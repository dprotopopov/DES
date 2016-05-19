/*
 *
 *	DESMEM.H
 *
 *	Defined functions profile
 *
 *	See AS 2805.5 for more detail
 *
 *	Copyright (C) 1994-2001, Dmitry Protopopov 70952828511@mail.ru
 *
 */

#if !defined( __DESMEM_H )

#define __DESMEM_H

#if defined( __cplusplus )
extern "C" {
#endif  

void des_memencrypt( unsigned char * key , unsigned char * data , int len ) ;
void des_memdecrypt( unsigned char * key , unsigned char * data , int len ) ;
void des_memcheck ( unsigned char * key , unsigned char * data , long len , unsigned char * checkvalue ) ;


#if defined( __cplusplus )
}
#endif

#endif /* __DESMEM_H */

