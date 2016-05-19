#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "des.h"

#if defined( __Intel386__ )

#include <mem.h>

#endif

#if defined(__cplusplus)
extern "C" {
#endif

void SpeedTest( void ) ;

#if defined(__cplusplus)
}
#endif

void debugPrintBlock( unsigned char *block, int blockLen )
{
  int		i;
  for( i=0; i < blockLen; i++) printf("%02X", block[ i ]);
}


int main()
{
  long	i , j ;

  unsigned char	key[]="\x01\x23\x45\x67\x89\xAB\xCD\xEF" ;
  unsigned char	plaintext[]="Now is the time for all " ;
  unsigned char	ciphertext[]="------------------------" ;
  unsigned char	SV[]="\x12\x34\x56\x78\x90\xAB\xCD\xEF" ;

  unsigned char	inputblock[ DESBLOCKSIZE ] ;
  unsigned char	outputblock[ DESBLOCKSIZE ] ;
  unsigned char	lastblock[ DESBLOCKSIZE ] ;
  DESKEYTABLE	keytable ;


  printf("Cryptographic key = ") ; debugPrintBlock(key,8) ; printf("\n") ;
  printf("The plaintext is '%s'\n",plaintext) ;
  printf("The starting variable ( SV ) = ") ; debugPrintBlock(SV,8) ; printf("\n") ;


  InitDesKeyTable( &keytable , key ) ;

  printf("\n\n\t\tExamples of ECB MODE - ENCIPHERMENT\n\n") ;

  for( i = 0 ; i<24 ; i += DESBLOCKSIZE )
  { 
    memmove( inputblock, &plaintext[i], DESBLOCKSIZE ) ;

    EncryptBlock( outputblock , inputblock , &keytable ) ;

    memmove( &ciphertext[i], outputblock, DESBLOCKSIZE ) ;

    debugPrintBlock( &plaintext[i], DESBLOCKSIZE ) ;  printf("  ") ;
    debugPrintBlock( inputblock, DESBLOCKSIZE ) ;     printf("  ") ;
    debugPrintBlock( outputblock, DESBLOCKSIZE ) ;    printf("  ") ;
    debugPrintBlock( &ciphertext[i], DESBLOCKSIZE ) ; printf("\n") ;
  }


  printf("\n\n\t\tExamples of ECB MODE - DECIPHERMENT\n\n") ;
  for( i = 0 ; i<24 ; i+=DESBLOCKSIZE )
  { 
    memmove( inputblock, &ciphertext[i], DESBLOCKSIZE ) ;

    DecryptBlock( outputblock , inputblock , &keytable ) ;

    memmove( &plaintext[i], outputblock, DESBLOCKSIZE ) ;

    debugPrintBlock( &ciphertext[i], DESBLOCKSIZE ) ; printf("  ") ;
    debugPrintBlock( inputblock, DESBLOCKSIZE ) ;     printf("  ") ;
    debugPrintBlock( outputblock, DESBLOCKSIZE ) ;    printf("  ") ;
    debugPrintBlock( &plaintext[i], DESBLOCKSIZE ) ;  printf("\n") ;
  }



  printf("\n\n\t\tExamples of CBC MODE - ENCIPHERMENT\n\n") ;

  memmove( lastblock , SV , DESBLOCKSIZE ) ;

  for( i = 0 ; i<24 ; i+=DESBLOCKSIZE )
  { 
    for( j=0 ; j<DESBLOCKSIZE ; j++ )
      inputblock[ j ] = lastblock[ j ] ^ plaintext[ i + j ] ;

    EncryptBlock( outputblock , inputblock , &keytable ) ;

    memmove( lastblock , outputblock , DESBLOCKSIZE ) ;

    memmove( &ciphertext[i], outputblock, DESBLOCKSIZE ) ;

    debugPrintBlock( &plaintext[i], DESBLOCKSIZE ) ;  printf("  ") ;
    debugPrintBlock( inputblock, DESBLOCKSIZE ) ;     printf("  ") ;
    debugPrintBlock( outputblock, DESBLOCKSIZE ) ;    printf("  ") ;
    debugPrintBlock( &ciphertext[i], DESBLOCKSIZE ) ; printf("\n") ;
  }


  printf("\n\n\t\tExamples of CBC MODE - DECIPHERMENT\n\n") ;

  memmove( lastblock , SV , DESBLOCKSIZE ) ;

  for( i = 0 ; i < 24 ; i+=DESBLOCKSIZE )
  { 
    memmove( inputblock, &ciphertext[i], DESBLOCKSIZE ) ;

    DecryptBlock( outputblock , inputblock , &keytable ) ;

    for( j = 0 ; j < DESBLOCKSIZE ; j++ ) 
      plaintext[ i + j ] = lastblock[j] ^ outputblock[ j ] ;

    memmove( lastblock , inputblock, DESBLOCKSIZE ) ;

    debugPrintBlock(&ciphertext[i], DESBLOCKSIZE ) ; printf("  ") ;
    debugPrintBlock(inputblock, DESBLOCKSIZE ) ;     printf("  ") ;
    debugPrintBlock(outputblock, DESBLOCKSIZE ) ;    printf("  ") ;
    debugPrintBlock(&plaintext[i], DESBLOCKSIZE ) ;  printf("\n") ;
  }

  printf("\n") ;
  i = EncryptFile("cipher.txt" , "plain.txt" , key ) ;
  printf("%ld bytes encrypted\n", i ) ;

  i = DecryptFile("plain2.txt" , "cipher.txt" , key ) ;
  printf("%ld bytes decrypted\n", i ) ;

/*
  SpeedTest() ;
*/
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
    InitDesKeyTable( &keytable , key ) ;
  }

  t2 = clock() ;


  t3 = clock() ;

  for( i=100000l ; i-- ; )
  {
    InitDesKeyTable( &keytable , key ) ;
    InitDesKeyTable( &keytable , key ) ;
    InitDesKeyTable( &keytable , key ) ;
    InitDesKeyTable( &keytable , key ) ;
    InitDesKeyTable( &keytable , key ) ;
  }

  t4 = clock() ;

  i = (long)( t4 - t3 - ( t2 - t1 ) ) ;
  printf("InitDesKeyTable :\n\n" ) ;
  printf("400000 iterations = %ld clocks ( %f sec ) \n",
    i, (float)(((double)i)/CLOCKS_PER_SEC) ) ;

  printf("Iteration/Second  = %f\n" , (float)(400000.0*CLOCKS_PER_SEC/i) ) ;
  printf("Second/Iteration  = %f\n" , (float)i/(400000.0*CLOCKS_PER_SEC) ) ;


  printf("\n\n") ;

  t1 = clock() ;

  for( i=100000l ; i-- ; )
  {
    EncryptBlock( outputblock , inputblock , &keytable ) ;
  }

  t2 = clock() ;


  t3 = clock() ;

  for( i=100000l ; i-- ; )
  {
    EncryptBlock( outputblock , inputblock , &keytable ) ;
    EncryptBlock( outputblock , inputblock , &keytable ) ;
    EncryptBlock( outputblock , inputblock , &keytable ) ;
    EncryptBlock( outputblock , inputblock , &keytable ) ;
    EncryptBlock( outputblock , inputblock , &keytable ) ;
  }

  t4 = clock() ;

  i = (long)( t4 - t3 - ( t2 - t1 ) ) ;

  printf("EncryptBlock/DecryptBlock\n\n") ;

  printf("400000 blocks ( 3200000 bytes ) = %ld clocks ( %f sec ) \n",
    i, (float)(((double)i)/CLOCKS_PER_SEC) ) ;


  printf("Byte/Second  = %f\n" , (float)(3200000.0*CLOCKS_PER_SEC/i) ) ;
  printf("Second/Byte  = %f\n" , (float)i/(3200000.0*CLOCKS_PER_SEC) ) ;

}

