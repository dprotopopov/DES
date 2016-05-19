/*
 *
 *		DESTEST.C
 *
 *		Copyright (C) 1994-2001 , Dmitry Protopopov 70952828511@mail.ru
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "des.h"
#include "desx.h"
#include "desmem.h"
#include "desfile.h"

#if defined(__cplusplus)
extern "C" {
#endif

void SpeedTest( void ) ;

#if defined(__cplusplus)
}
#endif

void debug_print( unsigned char *block, int blockLen )
{
  int		i;
  for( i=0; i < blockLen; i++) printf("%02X", block[ i ]);
}


int main(int argn, char *argv[])
{
  long	i ;

  unsigned char	key[]="\x01\x23\x45\x67\x89\xAB\xCD\xEF" ;
  unsigned char	plaintext[]="Now is the time for all " ;
  unsigned char	ciphertext[]="------------------------" ;
  unsigned char	SV[]="\x12\x34\x56\x78\x90\xAB\xCD\xEF" ;

  unsigned char	inputblock[ DESBLOCKSIZE ] ;
  unsigned char	outputblock[ DESBLOCKSIZE ] ;
  unsigned char	lastblock[ DESBLOCKSIZE ] ;
  DESKEYTABLE	keytable ;


  printf("Cryptographic key = ") ; debug_print(key,8) ; printf("\n") ;
  printf("The plaintext is '%s'\n",plaintext) ;
  printf("The starting variable ( SV ) = ") ; debug_print(SV,8) ; printf("\n") ;


  des_init( &keytable , key ) ;

  printf("\n\n\t\tExamples of ECB MODE - ENCIPHERMENT\n\n") ;

  for( i = 0 ; i<24 ; i += DESBLOCKSIZE )
  { 
    des_move( inputblock, &plaintext[i] ) ;
    des_encrypt( &keytable , inputblock , outputblock ) ;
    des_move( &ciphertext[i], outputblock ) ;

    debug_print( &plaintext[i], DESBLOCKSIZE ) ;  printf("  ") ;
    debug_print( inputblock, DESBLOCKSIZE ) ;     printf("  ") ;
    debug_print( outputblock, DESBLOCKSIZE ) ;    printf("  ") ;
    debug_print( &ciphertext[i], DESBLOCKSIZE ) ; printf("\n") ;
  }


  printf("\n\n\t\tExamples of ECB MODE - DECIPHERMENT\n\n") ;
  for( i = 0 ; i<24 ; i+=DESBLOCKSIZE )
  { 
    des_move( inputblock, &ciphertext[i] ) ;
    des_decrypt( &keytable , outputblock , inputblock ) ;
    des_move( &plaintext[i], outputblock ) ;

    debug_print( &ciphertext[i], DESBLOCKSIZE ) ; printf("  ") ;
    debug_print( inputblock, DESBLOCKSIZE ) ;     printf("  ") ;
    debug_print( outputblock, DESBLOCKSIZE ) ;    printf("  ") ;
    debug_print( &plaintext[i], DESBLOCKSIZE ) ;  printf("\n") ;
  }



  printf("\n\n\t\tExamples of CBC MODE - ENCIPHERMENT\n\n") ;

  memmove( lastblock , SV , DESBLOCKSIZE ) ;

  for( i = 0 ; i<24 ; i+=DESBLOCKSIZE )
  { 
    
	des_movexor( inputblock, lastblock, &plaintext[i]);
    des_encrypt( &keytable , inputblock , outputblock ) ;
    des_move( lastblock , outputblock ) ;
    des_move( &ciphertext[i], outputblock ) ;

    debug_print( &plaintext[i], DESBLOCKSIZE ) ;  printf("  ") ;
    debug_print( inputblock, DESBLOCKSIZE ) ;     printf("  ") ;
    debug_print( outputblock, DESBLOCKSIZE ) ;    printf("  ") ;
    debug_print( &ciphertext[i], DESBLOCKSIZE ) ; printf("\n") ;
  }


  printf("\n\n\t\tExamples of CBC MODE - DECIPHERMENT\n\n") ;

  memmove( lastblock , SV , DESBLOCKSIZE ) ;

  for( i = 0 ; i < 24 ; i+=DESBLOCKSIZE )
  { 
    des_move( inputblock, &ciphertext[i] ) ;
    des_decrypt( &keytable , outputblock , inputblock ) ;
    des_movexor( &plaintext[i], lastblock, outputblock );
    des_move( lastblock , inputblock ) ;

    debug_print(&ciphertext[i], DESBLOCKSIZE ) ; printf("  ") ;
    debug_print(inputblock, DESBLOCKSIZE ) ;     printf("  ") ;
    debug_print(outputblock, DESBLOCKSIZE ) ;    printf("  ") ;
    debug_print(&plaintext[i], DESBLOCKSIZE ) ;  printf("\n") ;
  }

  printf("\n") ;
  i = des_fileencrypt( key, "plain.txt" , "cipher.txt" ) ;
  printf("%ld bytes encrypted\n", i ) ;

  i = des_filedecrypt( key, "plain2.txt" , "cipher.txt" ) ;
  printf("%ld bytes decrypted\n", i ) ;

  if (argn==2 && argv[1][0]=='s')
	SpeedTest() ;

  return 0 ;
}

void SpeedTest( void )
{

  clock_t 	t1 , t2 , t3 , t4 ;
  long    	i ;
  unsigned char	inputblock[ DESBLOCKSIZE ] , outputblock[ DESBLOCKSIZE ] ;
  DESKEYTABLE 	keytable ;
  static unsigned char key[]="EXAMPLE " ;


  printf("\n\nSpeed test :\n\n") ;

  t1 = clock() ;

  for( i=100000l ; i-- ; )
  {
    des_init( &keytable , key ) ;
  }

  t2 = clock() ;


  t3 = clock() ;

  for( i=100000l ; i-- ; )
  {
    des_init( &keytable , key ) ;
    des_init( &keytable , key ) ;
    des_init( &keytable , key ) ;
    des_init( &keytable , key ) ;
    des_init( &keytable , key ) ;
  }

  t4 = clock() ;

  i = (long)( t4 - t3 - ( t2 - t1 ) ) ;
  printf("des_init :\n\n" ) ;
  printf("400000 iterations = %ld clocks ( %f sec ) \n",
    i, (float)(((double)i)/CLOCKS_PER_SEC) ) ;

  printf("Iteration/Second  = %f\n" , (float)(400000.0*CLOCKS_PER_SEC/i) ) ;
  printf("Second/Iteration  = %f\n" , (float)i/(400000.0*CLOCKS_PER_SEC) ) ;


  printf("\n\n") ;

  t1 = clock() ;

  for( i=100000l ; i-- ; )
  {
    des_encrypt( &keytable , inputblock , outputblock ) ;
  }

  t2 = clock() ;


  t3 = clock() ;

  for( i=100000l ; i-- ; )
  {
    des_encrypt( &keytable , inputblock , outputblock ) ;
    des_encrypt( &keytable , inputblock , outputblock ) ;
    des_encrypt( &keytable , inputblock , outputblock ) ;
    des_encrypt( &keytable , inputblock , outputblock ) ;
    des_encrypt( &keytable , inputblock , outputblock ) ;
  }

  t4 = clock() ;

  i = (long)( t4 - t3 - ( t2 - t1 ) ) ;

  printf("des encrypt/decrypt\n\n") ;

  printf("400000 blocks ( 3200000 bytes ) = %ld clocks ( %f sec ) \n",
    i, (float)(((double)i)/CLOCKS_PER_SEC) ) ;


  printf("Byte/Second  = %f\n" , (float)(3200000.0*CLOCKS_PER_SEC/i) ) ;
  printf("Second/Byte  = %f\n" , (float)i/(3200000.0*CLOCKS_PER_SEC) ) ;

}
