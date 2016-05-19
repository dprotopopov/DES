/*
 *
 *	DESX.H
 *
 *	Defined functions profile
 *
 *	See AS 2805.5 for more detail
 *
 *	Copyright (C) 1994-2001, Dmitry Protopopov 70952828511@mail.ru
 *
 */

#if !defined( __DESX_H )

#define __DESX_H

#define X1234567890ABCDEF "\x12\x34\x56\x78\x90\xAB\xCD\xEF"
#define X2222222222222222 "\x22\x22\x22\x22\x22\x22\x22\x22"
#define X2424242424242424 "\x24\x24\x24\x24\x24\x24\x24\x24"
#define X2828282828282828 "\x28\x28\x28\x28\x28\x28\x28\x28"
#define XE1D2C3B45A697887 "\xE1\xD2\xC3\xB4\x5A\x69\x78\x87"


#define des_move( dest , source ) memmove( (dest) , (source) , DESBLOCKSIZE )


#if defined( __cplusplus )
extern "C" {
#endif  

void des_xor( unsigned char * dest , unsigned char * oper ) ;
void des_movexor( unsigned char * dest , unsigned char * source1 ,	unsigned char * source2 ) ;
short des_compare( unsigned char * value1 , unsigned char * value2 ) ;

void des_owf(DESKEYTABLE *keytable , unsigned char *source , unsigned char *dest );

void des_atok( unsigned char * key , char * str ) ;
void des_parity( unsigned char * key ) ;

void des_cbcencrypt(
				DESKEYTABLE * keytable ,
				unsigned char * plaintext ,
				unsigned char * ciphertext , 
				int len
		) ;

void des_cbcdecrypt(
				DESKEYTABLE * keytable,
				unsigned char * plaintext ,
				unsigned char * ciphertext , 
				int len
		) ;

#if defined( __cplusplus )
}
#endif

#endif /* __DESX_H */

