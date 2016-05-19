/*
 *      DESFILE.C
 *
 *      Copyright (C) 1994,1995 , DialogBank
 */

#include <stdio.h>
#include <stdlib.h>


#include "des.h"

#if defined( __AnsiDes__ )

#include <string.h>

#endif

#if defined( __Intel386__ )

#include <mem.h>
#include <alloc.h>

#endif



#if defined( __Sun__ )

#include <string.h>

#endif

#define BUFFERSIZE	4096



/*
------------------------------------------------------------------------

	EncryptFile / DecryptFile :

	return number bytes encrypted/decrypted

------------------------------------------------------------------------
*/

long EncryptFile	(
				char * destname ,
				char * sourcename ,
				unsigned char *key
			)
{

  FILE		*fi , *fo ; /* input and output file's pointer */
  int		i , j , k , pc ;
  unsigned char	*buffer ;
  unsigned char	lastblock[ DESBLOCKSIZE ] ;
  int		end_of_job = 0 ;
  long		bytes_count = 0 ;
  DESKEYTABLE	keytable ;


  buffer = ( unsigned char * ) malloc( BUFFERSIZE ) ;
  if( buffer == NULL ) return -1 ;

  fi = fopen( sourcename , "rb" ) ;
  if( fi == NULL ) 
  {
    free( buffer ) ;
    return -2 ;
  }

  fo = fopen( destname , "wb" ) ;
  if( fo == NULL ) 
  { 
    free( buffer ) ;
    fclose( fi ) ; 
    return -3 ; 
  }


  InitDesKeyTable( &keytable , key ) ;

  EncryptBlock( lastblock , XE1D2C3B45A697887 , &keytable ) ;

  do
  {

    i = fread( buffer, 1, BUFFERSIZE, fi) ;

    if( i<BUFFERSIZE ) end_of_job = 1 ;


    j = ( i >> 3 ) ; /*        or      j = ( i / DESBLOCKSIZE )      */

    if( j != 0 )
    {

      XorBlock( buffer , lastblock ) ;
      EncryptBlock( buffer , buffer , &keytable ) ;

      for( pc = DESBLOCKSIZE ; --j ; pc += DESBLOCKSIZE ) /* (j-1) iterations */
      {
        XorBlock( &buffer[ pc ] , &buffer[ pc - DESBLOCKSIZE ] ) ;
        EncryptBlock( &buffer[ pc ] , &buffer[ pc ] , &keytable ) ;
      }		

      MoveBlock( lastblock , &buffer[ pc - DESBLOCKSIZE ] ) ;

    }

    else
      pc = 0 ;


    k = ( i & 7 ) ; /*     or        k = (  i % DESBLOCKSIZE )       */

    if( k != 0 )
    {
      EncryptBlock( lastblock , lastblock , &keytable ) ;

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

long DecryptFile	( 
				char * destname ,
				char * sourcename ,
				unsigned char *key 
			)
{

  FILE		*fi , *fo ; /* input and output file's pointer */
  int		i , j , k , pc ;
  unsigned char	*buffer ;
  unsigned char	lastblock[ DESBLOCKSIZE ] ;
  int		end_of_job = 0 ;
  long		bytes_count = 0 ;
  DESKEYTABLE	keytable ;


  buffer = ( unsigned char * ) malloc( BUFFERSIZE ) ;
  if( buffer == NULL ) return -1 ;

  fi = fopen( sourcename , "rb" ) ;
  if( fi == NULL ) 
  {
    free( buffer ) ;
    return -2 ;
  }

  fo = fopen( destname , "wb" ) ;
  if( fo == NULL ) 
  { 
    free( buffer ) ;
    fclose( fi ) ; 
    return -3 ; 
  }


  InitDesKeyTable( &keytable , key ) ; /* initalize DES table */

  EncryptBlock( lastblock , XE1D2C3B45A697887 , &keytable ) ;

  do
  {

    i = fread( buffer, 1, BUFFERSIZE, fi) ;

    if( i<BUFFERSIZE ) end_of_job = 1 ;


    j = ( i >> 3 ) ; /*        or      j = ( i / DESBLOCKSIZE )      */


    if( j != 0 )
    {

      unsigned char	lastblock1[ DESBLOCKSIZE ] ;

      MoveBlock( lastblock1 , lastblock ) ;

      pc = ( i & ~0x7 ) ; /* or         pc  =  ( DESBLOCKSIZE * j )  */

      MoveBlock( lastblock , &buffer[ pc-DESBLOCKSIZE ] ) ;

      while( --j )
      {
        pc -= DESBLOCKSIZE ;
        DecryptBlock( &buffer[ pc ] , &buffer[ pc ] , &keytable ) ;
	XorBlock( &buffer[ pc ] , &buffer[ pc-DESBLOCKSIZE ] ) ;
      }

      DecryptBlock( buffer , buffer , &keytable ) ;
      XorBlock( buffer , lastblock1 ) ;

    }

    k = ( i & 7 ) ; /*     or        k = (  i % DESBLOCKSIZE )       */

    if( k != 0 )
    {

      pc = i & ~0x7 ; /*  or   pc = DESBLOCKSIZE * (int)( i/DESBLOCKSIZE ) */

      EncryptBlock( lastblock , lastblock , &keytable ) ;

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

long CheckValueFile	( 
				unsigned char *checkvalue ,
				char * fileName ,
				unsigned char *key 
			)
{

  FILE		*fi ; /* input file's pointer */
  int		i , j , pc ;
  unsigned char	*buffer ;
  int		end_of_job = 0 ;
  long		bytes_count = 0 ;
  DESKEYTABLE	keytable ;


  buffer = ( unsigned char * ) malloc( BUFFERSIZE ) ;
  if( buffer == NULL ) return -1 ;

  fi = fopen( fileName , "rb" ) ;
  if( fi == NULL ) 
  {
    free( buffer ) ;
    return -2 ;
  }


  InitDesKeyTable( &keytable , key ) ;

  memset( checkvalue , 0 , DESBLOCKSIZE ) ;

  do
  {

    i = fread( buffer, 1, BUFFERSIZE, fi) ;

    if( i<BUFFERSIZE ) end_of_job = 1 ;


    j = ( i >> 3 ) ; /*        or      j = ( i / DESBLOCKSIZE )      */

    pc = 0 ;

    if( j != 0 )
    {

      XorBlock( checkvalue , &buffer[ pc ] ) ;
      EncryptBlock( checkvalue , checkvalue , &keytable ) ;
      pc += DESBLOCKSIZE ;
    }

   
    if( end_of_job  )
    {
      j = i&~0x7 ;
      if( j>0 ) 
      {
        while( j-- ) checkvalue[ j ] ^= buffer[ pc+j ] ;
        EncryptBlock( checkvalue , checkvalue , &keytable ) ;
      }
    }

    bytes_count += i ;

  }
  while( !end_of_job ) ;
 
  OneWayFunction( checkvalue , checkvalue , &keytable ) ;

  free( buffer ) ;
  fclose( fi ) ;

  return bytes_count ;

}
