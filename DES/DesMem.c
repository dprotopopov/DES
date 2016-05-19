/*
 *
 *      DESMEM.C
 *
 *      Copyright (C) 1994-2001 , Dmitry Protopopov 70952828511@mail.ru
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "des.h"
#include "desx.h"
#include "desmem.h"

#define BUFFERSIZE	4096



void des_memencrypt(unsigned char *key, unsigned char *data , int datalen)
{
	DESKEYTABLE	keytable ;
	unsigned char	lastblock[ DESBLOCKSIZE ] ;
	unsigned char	startvariable[ DESBLOCKSIZE ] ;
	int		q , r , pc ;

	des_init( &keytable , key ) ;

	des_encrypt( &keytable , XE1D2C3B45A697887 , startvariable ) ;

	q = datalen >> 3 ;
	r = datalen & 7 ;
	pc = 0 ;

	if( q )
	{
		des_xor( data , startvariable ) ;
		des_encrypt( &keytable , data , data ) ;

		while( --q  )
		{
			des_xor( &data[ pc+DESBLOCKSIZE ] , &data[ pc ] ) ;
			pc += DESBLOCKSIZE ;
			des_encrypt( &keytable , &data[ pc ] , &data[ pc ] ) ;
		}
		des_move( lastblock , &data[ pc ] ) ;
		pc += DESBLOCKSIZE ;

	}
	else des_move( lastblock , startvariable ) ;

	if( r )
	{
		des_encrypt(  &keytable , lastblock , lastblock ) ;
		while( r-- ) data[ pc+r ] ^= lastblock[ r ] ;
	}
}


void des_memdecrypt(unsigned char *key, unsigned char *data , int datalen)
{
	DESKEYTABLE	keytable ;
	unsigned char	lastblock[ DESBLOCKSIZE ] ;
	unsigned char	startvariable[ DESBLOCKSIZE ] ;
	int		q , r , pc ;

	des_init( &keytable , key ) ;

	des_encrypt( &keytable , XE1D2C3B45A697887 , startvariable ) ;

	q = datalen >> 3 ;
	r = datalen & 7 ;
	pc = datalen - r ;

	if( r )
	{
		if( q )
			des_encrypt( &keytable , &data[ pc - DESBLOCKSIZE ] , lastblock  ) ;
		else
			des_encrypt( &keytable , startvariable , lastblock ) ;
		while( r-- ) data[ pc+r ] ^= lastblock[ r ] ;
	}

	if( q )
	{
		while( --q  )
		{
			pc -= DESBLOCKSIZE ;
			des_decrypt(  &keytable , &data[ pc ] , &data[ pc ] ) ;
			des_xor( &data[ pc ] , &data[ pc-DESBLOCKSIZE ] ) ;
		}

		des_decrypt( &keytable , data , data ) ;
		des_xor( data , startvariable ) ;
	}
}

void des_memcheck(
	unsigned char *key ,
	unsigned char *data , 
	long datalen,
	unsigned char *checkvalue
	)
{
	DESKEYTABLE	keytable ;

	des_init( &keytable , key ) ;

	memset( checkvalue , 0 , DESBLOCKSIZE ) ;

	while( datalen>=DESBLOCKSIZE )
	{
		des_xor( checkvalue , data ) ;
		des_encrypt( &keytable , checkvalue , checkvalue ) ;
		data = &data[ DESBLOCKSIZE ] ;
		datalen -= DESBLOCKSIZE ;
	}

	if( datalen>0 )
	{
		while( datalen-- ) checkvalue[ datalen ] ^= data[ datalen ] ;
		des_encrypt( &keytable , checkvalue , checkvalue ) ;
	}

	des_owf( &keytable , checkvalue , checkvalue ) ;
}

