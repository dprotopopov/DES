/*
 *
 *		DESX.C
 *
 *		Copyright (C) 1994-2001 , Dmitry Protopopov 70952828511@mail.ru
 *
 */


#include <string.h>

#include "des.h"
#include "desx.h"

#if defined( __Intel386__ )

void des_xor( unsigned char *dest , unsigned char *oper )
{
	*((unsigned long *)dest) ^= *((unsigned long *)oper) ;
	*((unsigned long *)&dest[4]) ^= *((unsigned long *)&oper[4]) ;
}

#endif

#if defined( __Sun__ ) || defined( __AnsiDes__ )

void des_xor( unsigned char *dest , unsigned char *oper )
{
	dest[ 0 ] ^= oper[ 0 ] ;
	dest[ 1 ] ^= oper[ 1 ] ;
	dest[ 2 ] ^= oper[ 2 ] ;
	dest[ 3 ] ^= oper[ 3 ] ;
	dest[ 4 ] ^= oper[ 4 ] ;
	dest[ 5 ] ^= oper[ 5 ] ;
	dest[ 6 ] ^= oper[ 6 ] ;
	dest[ 7 ] ^= oper[ 7 ] ;
}

#endif


void des_movexor( unsigned char *dest , unsigned char *source1 , unsigned char *source2 )
{
  dest[ 0 ] = source1[ 0 ] ^ source2[ 0 ] ;
  dest[ 1 ] = source1[ 1 ] ^ source2[ 1 ] ;
  dest[ 2 ] = source1[ 2 ] ^ source2[ 2 ] ;
  dest[ 3 ] = source1[ 3 ] ^ source2[ 3 ] ;
  dest[ 4 ] = source1[ 4 ] ^ source2[ 4 ] ;
  dest[ 5 ] = source1[ 5 ] ^ source2[ 5 ] ;
  dest[ 6 ] = source1[ 6 ] ^ source2[ 6 ] ;
  dest[ 7 ] = source1[ 7 ] ^ source2[ 7 ] ;
}

short des_compare( unsigned char * value1 , unsigned char * value2 )
{
  short i , j ;
  for( j = 0 ; j<8 ; j++ )
  {
    i = (value2[j]-value1[j]) ;
    if( i ) return i ;
  }
  return 0 ;
}

void des_owf(
		DESKEYTABLE *keytable,
		unsigned char *source ,
		unsigned char *dest
		)
{
	unsigned char	temp[ DESBLOCKSIZE ] ;
	des_decrypt( keytable , temp , source ) ;
	des_movexor( dest , temp , source ) ;
}


void des_atok( unsigned char *key , char * str )
{
  int i ;

  for( i=0 ; i<DESBLOCKSIZE && str[i]!='\0' ; i++ ) key[ i ] = str[ i ] << 1 ;

  for( ; i<DESBLOCKSIZE ; i++ ) key[ i ] = 0 ;

  des_parity( key ) ;
}

void des_parity( unsigned char *key )
{
	int				i ;
	unsigned char	a ;

	for( i = 8 ; i-- ; )
	{
		a = key[ i ] ;
		a ^= a>>4 ;
		a ^= a>>2 ;
		a ^= a>>1 ;
		if( (a & 1) == 0 ) key[ i ] ^= 1 ;
	}
}

void des_cbcencrypt( DESKEYTABLE *keytable , unsigned char *source , unsigned char *dest , int datalen)
{
	unsigned char	lastblock[ DESBLOCKSIZE ] ;
	unsigned char	startvariable[ DESBLOCKSIZE ] ;
	int		q , r , pc ;

	des_encrypt( keytable , XE1D2C3B45A697887 ,  startvariable ) ;

	q = datalen >> 3 ;
	r = datalen & 7 ;
	pc = 0 ;

	if( q )
	{
		des_movexor( dest , startvariable , source ) ;
		des_encrypt( keytable , dest , dest ) ;

		while( --q  )
		{
			des_movexor( &dest[ pc+DESBLOCKSIZE ] , &dest[ pc ] , &source[ pc+DESBLOCKSIZE ] ) ;
			pc += DESBLOCKSIZE ;
			des_encrypt( keytable , &dest[ pc ] , &dest[ pc ]  ) ;
		}

		des_move( lastblock , &dest[ pc ] ) ;
		pc += DESBLOCKSIZE ;

	}
	else des_move( lastblock , startvariable ) ;

	if( r )
	{
		des_encrypt( keytable , lastblock , lastblock ) ;
		while( r-- ) dest[ pc + r ] = source[ pc + r ] ^ lastblock[ r ] ;
	}
}


void des_cbcdecrypt( DESKEYTABLE *keytable , unsigned char *dest , unsigned char *source , int datalen)
{
	unsigned char	lastblock[ DESBLOCKSIZE ] ;
	unsigned char	startvariable[ DESBLOCKSIZE ] ;
	int		q , r , pc ;

	des_encrypt( keytable, XE1D2C3B45A697887 , startvariable ) ;

	q = datalen >> 3 ;
	r = datalen & 7 ;
	pc = datalen - r ;

	if( r )
	{
		if( q )
			des_encrypt( keytable, &source[ pc - DESBLOCKSIZE ] , lastblock ) ;
		else
			des_encrypt( keytable , startvariable , lastblock ) ;

		while( r-- ) dest[ pc + r ] = source[ pc + r ] ^ lastblock[ r ] ;
	}

	if( q )
	{
		while( --q  )
		{
			pc -= DESBLOCKSIZE ;
			des_decrypt( keytable , &dest[ pc ] , &source[ pc ] ) ;
			des_xor( &dest[ pc ] , &source[ pc-DESBLOCKSIZE ] ) ;
		}

		des_decrypt( keytable , dest , source ) ;
		des_xor( dest , startvariable ) ;
	}
}
