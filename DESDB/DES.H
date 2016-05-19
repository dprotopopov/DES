/*
 *
 *	DES.H
 *
 *	Defined functions profile
 *
 *	See AS 2805.5 for more detail
 *
 *	Copyright (C) 1994 , DialogBank
 *
 */

#if !defined( __DES_H )

#define __DES_H

#include <string.h>

#define DESBLOCKSIZE	8

#define X1234567890ABCDEF "\x12\x34\x56\x78\x90\xAB\xCD\xEF"
#define X2222222222222222 "\x22\x22\x22\x22\x22\x22\x22\x22"
#define X2424242424242424 "\x24\x24\x24\x24\x24\x24\x24\x24"
#define X2828282828282828 "\x28\x28\x28\x28\x28\x28\x28\x28"
#define XE1D2C3B45A697887 "\xE1\xD2\xC3\xB4\x5A\x69\x78\x87"

typedef unsigned char	DESKEY[ DESBLOCKSIZE ] ;
typedef unsigned char	DESBLOCK[ DESBLOCKSIZE ] ;

#if !defined(__Intel386__) && !defined(__Sun__) && !defined(__AnsiDes__)

#define	__AnsiDes__

#endif

typedef struct
	{
		struct
		{
			unsigned long	KEY0246 ;
			unsigned long	KEY1357 ;
		}
		KEY[ 16 ] ;
	}
	DESKEYTABLE ;


#define MoveBlock( dest , source ) memmove( (dest) , (source) , DESBLOCKSIZE )


#if defined( __cplusplus )
extern "C" {
#endif  

#if defined( __Intel386__ )

void far InitDesKeyTable(
				DESKEYTABLE far * keytable ,
				unsigned char far * key
			) ;

void far EncryptBlock	(
				unsigned char far * ciphertext ,
				unsigned char far * plaintext  ,
				DESKEYTABLE far * keytable
			) ;

void far DecryptBlock	(
				unsigned char far * plaintext ,
				unsigned char far * ciphertext ,
				DESKEYTABLE far * keytable
			) ;

#endif /* __Intel386__ */


#if defined( __Sun__ ) || defined( __AnsiDes__ )

void InitDesKeyTable( DESKEYTABLE * keytable , unsigned char * key ) ;

void EncryptBlock	(
				unsigned char * ciphertext ,
				unsigned char * plaintext  ,
				DESKEYTABLE * keytable
			) ;

void DecryptBlock	(
				unsigned char * plaintext ,
				unsigned char * ciphertext ,
				DESKEYTABLE * keytable
			) ;

#endif /* __Sun__ */


void XorBlock( unsigned char * dest , unsigned char * oper ) ;

void MoveXorBlock( unsigned char * dest ,
				unsigned char * source1 ,
				unsigned char * source2
		) ;

short CmpBlock( unsigned char * value1 , unsigned char * value2 ) ;

void OneWayFunction 	(
				unsigned char *dest ,
				unsigned char *source ,
				DESKEYTABLE *keytable
		);


void StringToKey( unsigned char * key , char * str ) ;
void SetParity( unsigned char * key ) ;

void CbcEncrypt( unsigned char * data , int datalen , unsigned char * key ) ;
void CbcDecrypt( unsigned char * data , int datalen , unsigned char * key ) ;

void _CbcEncrypt( unsigned char * dest ,
				unsigned char * source , int datalen ,
				DESKEYTABLE * keytable
		) ;

void _CbcDecrypt( unsigned char * dest ,
				unsigned char * source , int datalen ,
				DESKEYTABLE * keytable
		) ;

void CheckValue (
			unsigned char * checkvalue ,
			unsigned char * data , long datalen ,
			unsigned char * key
		) ;

long EncryptFile( char * destName , char * sourceName , unsigned char * key ) ;
long DecryptFile( char * destName , char * sourceName , unsigned char * key ) ;

long CheckValueFile	(
				unsigned char * checkvalue ,
				char * fileName ,
				unsigned char * key
			) ;


#if defined( __cplusplus )
}
#endif

#endif /* __DES_H */

