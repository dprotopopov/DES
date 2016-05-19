/*
 *
 *      DESFILE.C
 *
 *      Copyright (C) 1994-2001 , Dmitry Protopopov 70952828511@mail.ru
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "des.h"
#include "desx.h"
#include "desfile.h"

#define BUFFERSIZE	4096



long des_fileencrypt	( unsigned char *key, char * plain , char * cipher )
{

  FILE		*fi , *fo ; /* input and output file's pointer */
  int		i , j , k , pc ;
  unsigned char	*buffer ;
  unsigned char	lastblock[ DESBLOCKSIZE ] ;
  int		end_of_job = 0 ;
  long		bytes_count = 0 ;
  DESKEYTABLE	keytable ;


  buffer = ( unsigned char * ) malloc( BUFFERSIZE ) ;
  if( buffer == NULL ) 
	return 0 ;

  fi = fopen( plain , "rb" ) ;
  if( fi == NULL ) 
  {
	free( buffer ) ;
	return 0 ;
  }

  fo = fopen( cipher , "wb" ) ;
  if( fo == NULL ) 
  { 
	free( buffer ) ;
	fclose( fi ) ; 
	return 0 ; 
  }


  des_init( &keytable , key ) ;

  des_encrypt( &keytable , XE1D2C3B45A697887 , lastblock ) ;

  do
  {

    i = fread( buffer, 1, BUFFERSIZE, fi) ;

    if( i<BUFFERSIZE ) end_of_job = 1 ;


    j = ( i >> 3 ) ; /*        or      j = ( i / DESBLOCKSIZE )      */

    if( j != 0 )
    {

      des_xor( buffer , lastblock ) ;
      des_encrypt( &keytable , buffer , buffer ) ;

      for( pc = DESBLOCKSIZE ; --j ; pc += DESBLOCKSIZE ) /* (j-1) iterations */
      {
        des_xor( &buffer[ pc ] , &buffer[ pc - DESBLOCKSIZE ] ) ;
        des_encrypt( &keytable , &buffer[ pc ] , &buffer[ pc ] ) ;
      }		

      des_move( lastblock , &buffer[ pc - DESBLOCKSIZE ] ) ;

    }

    else
      pc = 0 ;


    k = ( i & 7 ) ; /*     or        k = (  i % DESBLOCKSIZE )       */

    if( k != 0 )
    {
      des_encrypt( &keytable , lastblock , lastblock ) ;

      while( k-- )
        buffer[ pc + k ] ^= lastblock[ pc ] ;
    }

    fwrite( buffer , 1 , i , fo ) ;

    bytes_count += i ;
	
  }
  while( !end_of_job )  ;

  free( buffer ) ;
  fclose( fi ) ;
  fclose( fo ) ;

  return bytes_count ;

}

long des_filedecrypt	( unsigned char *key , char * plain , char * cipher )
{

  FILE		*fi , *fo ; /* input and output file's pointer */
  int		i , j , k , pc ;
  unsigned char	*buffer ;
  unsigned char	lastblock[ DESBLOCKSIZE ] ;
  int		end_of_job = 0 ;
  long		bytes_count = 0 ;
  DESKEYTABLE	keytable ;


  buffer = ( unsigned char * ) malloc( BUFFERSIZE ) ;
  if( buffer == NULL )
	return 0 ;

  fi = fopen( cipher , "rb" ) ;
  if( fi == NULL ) 
  {
    free( buffer ) ;
    return 0 ;
  }

  fo = fopen( plain , "wb" ) ;
  if( fo == NULL ) 
  { 
    free( buffer ) ;
    fclose( fi ) ; 
    return 0 ; 
  }


  des_init( &keytable , key ) ; /* initalize DES table */

  des_encrypt( &keytable , XE1D2C3B45A697887 , lastblock ) ;

  do
  {

    i = fread( buffer, 1, BUFFERSIZE, fi) ;

    if( i<BUFFERSIZE ) end_of_job = 1 ;


    j = ( i >> 3 ) ; /*        or      j = ( i / DESBLOCKSIZE )      */


    if( j != 0 )
    {

      unsigned char	lastblock1[ DESBLOCKSIZE ] ;

      des_move( lastblock1 , lastblock ) ;

      pc = ( i & ~0x7 ) ; /* or         pc  =  ( DESBLOCKSIZE * j )  */

      des_move( lastblock , &buffer[ pc-DESBLOCKSIZE ] ) ;

      while( --j )
      {
        pc -= DESBLOCKSIZE ;
        des_decrypt( &keytable , &buffer[ pc ] , &buffer[ pc ] ) ;
		des_xor( &buffer[ pc ] , &buffer[ pc-DESBLOCKSIZE ] ) ;
      }

      des_decrypt( &keytable , buffer , buffer ) ;
      des_xor( buffer , lastblock1 ) ;

    }

    k = ( i & 7 ) ; /*     or        k = (  i % DESBLOCKSIZE )       */

    if( k != 0 )
    {

      pc = i & ~0x7 ; /*  or   pc = DESBLOCKSIZE * (int)( i/DESBLOCKSIZE ) */

      des_encrypt( &keytable , lastblock , lastblock ) ;

      while( k-- )
        buffer[ pc + k ] ^= lastblock[ pc ] ;
    }

    fwrite( buffer , 1 , i , fo ) ;

    bytes_count += i ;
	
  }
  while( !end_of_job )  ;

  free( buffer ) ;
  fclose( fi ) ;
  fclose( fo ) ;

  return bytes_count ;

}

long des_filecheck	( unsigned char *key , char * file , unsigned char *checkvalue )
{

  FILE		*fi ; /* input file's pointer */
  int		i , j , pc ;
  unsigned char	*buffer ;
  int		end_of_job = 0 ;
  long		bytes_count = 0 ;
  DESKEYTABLE	keytable ;


  buffer = ( unsigned char * ) malloc( BUFFERSIZE ) ;
  if( buffer == NULL ) return 0 ;

  fi = fopen( file , "rb" ) ;
  if( fi == NULL ) 
  {
    free( buffer ) ;
    return 0 ;
  }


  des_init( &keytable , key ) ;

  memset( checkvalue , 0 , DESBLOCKSIZE ) ;

  do
  {

    i = fread( buffer, 1, BUFFERSIZE, fi) ;

    if( i<BUFFERSIZE ) end_of_job = 1 ;


    j = ( i >> 3 ) ; /*        or      j = ( i / DESBLOCKSIZE )      */

    pc = 0 ;

    if( j != 0 )
    {

      des_xor( checkvalue , &buffer[ pc ] ) ;
      des_encrypt( &keytable , checkvalue , checkvalue ) ;
      pc += DESBLOCKSIZE ;
    }

   
    if( end_of_job  )
    {
      j = i&~0x7 ;
      if( j>0 ) 
      {
        while( j-- ) checkvalue[ j ] ^= buffer[ pc+j ] ;
        des_encrypt( &keytable , checkvalue , checkvalue ) ;
      }
    }

    bytes_count += i ;

  }
  while( !end_of_job ) ;
 
  des_owf( &keytable , checkvalue , checkvalue ) ;

  free( buffer ) ;
  fclose( fi ) ;

  return bytes_count ;

}
