/*
 *
 *	DESFILE.H
 *
 *	Defined functions profile
 *
 *	See AS 2805.5 for more detail
 *
 *	Copyright (C) 1994-2001, Dmitry Protopopov 70952828511@mail.ru
 *
 */

#if !defined( __DESFILE_H )

#define __DESFILE_H

#if defined( __cplusplus )
extern "C" {
#endif  

long des_fileencrypt( unsigned char * key , char * plainfile , char * cipherfile ) ;
long des_filedecrypt( unsigned char * key , char * plainfile , char * cipherfile ) ;
long des_filecheck( unsigned char * key , char * file , unsigned char * checkvalue ) ;


#if defined( __cplusplus )
}
#endif

#endif /* __DESFILE_H */

