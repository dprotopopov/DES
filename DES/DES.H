/*
 *
 *	DES.H
 *
 *	Defined functions profile
 *
 *	See AS 2805.5 for more detail
 *
 *	Copyright (C) 1994-2001, Dmitry Protopopov 70952828511@mail.ru
 *
 */

#if !defined( __DES_H )

#define __DES_H

#define DESBLOCKSIZE	8
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

#if defined( __cplusplus )
extern "C" {
#endif  

#if defined( __Intel386__ )

void far des_init(
				DESKEYTABLE far * keytable ,
				unsigned char far * key
			) ;

void far des_encrypt	(
				DESKEYTABLE far * keytable
				unsigned char far * plaintext  ,
				unsigned char far * ciphertext ,
			) ;

void far des_decrypt	(
				DESKEYTABLE far * keytable
				unsigned char far * plaintext ,
				unsigned char far * ciphertext ,
			) ;

#endif /* __Intel386__ */


#if defined( __Sun__ ) || defined( __AnsiDes__ )

void des_init( DESKEYTABLE * keytable , unsigned char * key ) ;

void des_encrypt	(
				DESKEYTABLE * keytable,
				unsigned char * plaintext  ,
				unsigned char * ciphertext
			) ;

void des_decrypt	(
				DESKEYTABLE * keytable,
				unsigned char * plaintext ,
				unsigned char * ciphertext
			) ;

#endif /* __Sun__ OR __Ansi__ */


#if defined( __cplusplus )
}
#endif

#endif /* __DES_H */

