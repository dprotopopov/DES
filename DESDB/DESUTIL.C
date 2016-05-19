/*
 *
 *		DESUTIL.C
 *
 *		Copyright (C) 1994 , DialogBank
 *
 */


#include <string.h>

#include "des.h"

#if defined( __Intel386__ )

void XorBlock( unsigned char *dest , unsigned char *oper )
{
	*((unsigned long *)dest) ^= *((unsigned long *)oper) ;
	*((unsigned long *)&dest[4]) ^= *((unsigned long *)&oper[4]) ;
}

#endif

#if defined( __Sun__ ) || defined( __AnsiDes__ )

void XorBlock( unsigned char *dest , unsigned char *oper )
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


void MoveXorBlock( unsigned char *dest , unsigned char *source1 , unsigned char *source2 )
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

short CmpBlock( unsigned char * value1 , unsigned char * value2 )
{
  short i , j ;
  for( j = 0 ; j<8 ; j++ )
  {
    i = (value2[j]-value1[j]) ;
    if( i ) return i ;
  }
  return 0 ;
}

void OneWayFunction(
		unsigned char *dest ,
		unsigned char *source ,
		DESKEYTABLE *keytable
		)
{
	unsigned char	template[ DESBLOCKSIZE ] ;
	DecryptBlock( template , source , keytable ) ;
	MoveBlock( dest , source ) ;
	XorBlock( dest , template ) ;
}


void StringToKey( unsigned char *key , char * str )
{
  int i ;

  for( i=0 ; i<DESBLOCKSIZE && str[i]!='\0' ; i++ ) key[ i ] = str[ i ] << 1 ;

  for( ; i<DESBLOCKSIZE ; i++ ) key[ i ] = 0 ;

  SetParity( key ) ;
}

void SetParity( unsigned char *key )
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

void CheckValue(
	unsigned char *checkvalue ,
	unsigned char *data , long datalen ,
	unsigned char *key )
{
	DESKEYTABLE	keytable ;

	InitDesKeyTable( &keytable , key ) ;

	memset( checkvalue , 0 , DESBLOCKSIZE ) ;

	while( datalen>=DESBLOCKSIZE )
	{
		XorBlock( checkvalue , data ) ;
		EncryptBlock( checkvalue , checkvalue , &keytable ) ;
		data = &data[ DESBLOCKSIZE ] ;
		datalen -= DESBLOCKSIZE ;
	}

	if( datalen>0 )
	{
		while( datalen-- ) checkvalue[ datalen ] ^= data[ datalen ] ;
		EncryptBlock( checkvalue , checkvalue , &keytable ) ;
	}

	OneWayFunction( checkvalue , checkvalue , &keytable ) ;
}

void CbcEncrypt( unsigned char *data , int datalen , unsigned char *key)
{
	DESKEYTABLE	keytable ;
	unsigned char	lastblock[ DESBLOCKSIZE ] ;
	unsigned char	startvariable[ DESBLOCKSIZE ] ;
	int		q , r , pc ;

	InitDesKeyTable( &keytable , key ) ;

	EncryptBlock( startvariable , XE1D2C3B45A697887 , &keytable ) ;

	q = datalen >> 3 ;
	r = datalen & 7 ;
	pc = 0 ;

	if( q )
	{
		XorBlock( data , startvariable ) ;
		EncryptBlock( data , data , &keytable ) ;

		while( --q  )
		{
			XorBlock( &data[ pc+DESBLOCKSIZE ] , &data[ pc ] ) ;
			pc += DESBLOCKSIZE ;
			EncryptBlock( &data[ pc ] , &data[ pc ] , &keytable ) ;
		}
		MoveBlock( lastblock , &data[ pc ] ) ;
		pc += DESBLOCKSIZE ;

	}
	else MoveBlock( lastblock , startvariable ) ;

	if( r )
	{
		EncryptBlock( lastblock , lastblock , &keytable ) ;
		while( r-- ) data[ pc+r ] ^= lastblock[ r ] ;
	}

}


void CbcDecrypt( unsigned char *data , int datalen , unsigned char *key)
{
	DESKEYTABLE	keytable ;
	unsigned char	lastblock[ DESBLOCKSIZE ] ;
	unsigned char	startvariable[ DESBLOCKSIZE ] ;
	int		q , r , pc ;

	InitDesKeyTable( &keytable , key ) ;

	EncryptBlock( startvariable , XE1D2C3B45A697887 , &keytable ) ;

	q = datalen >> 3 ;
	r = datalen & 7 ;
	pc = datalen - r ;

	if( r )
	{
		if( q )
			EncryptBlock( lastblock , &data[ pc - DESBLOCKSIZE ] , &keytable ) ;
		else
			EncryptBlock( lastblock , startvariable , &keytable ) ;
		while( r-- ) data[ pc+r ] ^= lastblock[ r ] ;
	}

	if( q )
	{
		while( --q  )
		{
			pc -= DESBLOCKSIZE ;
			DecryptBlock( &data[ pc ] , &data[ pc ] , &keytable ) ;
			XorBlock( &data[ pc ] , &data[ pc-DESBLOCKSIZE ] ) ;
		}

		DecryptBlock( data , data , &keytable ) ;
		XorBlock( data , startvariable ) ;
	}

}

void _CbcEncrypt( unsigned char *dest , unsigned char *source , int datalen , DESKEYTABLE *keytable)
{
	unsigned char	lastblock[ DESBLOCKSIZE ] ;
	unsigned char	startvariable[ DESBLOCKSIZE ] ;
	int		q , r , pc ;

	EncryptBlock( startvariable , XE1D2C3B45A697887 , keytable ) ;

	q = datalen >> 3 ;
	r = datalen & 7 ;
	pc = 0 ;

	if( q )
	{
		MoveXorBlock( dest , startvariable , source ) ;
		EncryptBlock( dest , dest , keytable ) ;

		while( --q  )
		{
			MoveXorBlock( &dest[ pc+DESBLOCKSIZE ] , &dest[ pc ] , &source[ pc+DESBLOCKSIZE ] ) ;
			pc += DESBLOCKSIZE ;
			EncryptBlock( &dest[ pc ] , &dest[ pc ] , keytable ) ;
		}

		MoveBlock( lastblock , &dest[ pc ] ) ;
		pc += DESBLOCKSIZE ;

	}
	else MoveBlock( lastblock , startvariable ) ;

	if( r )
	{
		EncryptBlock( lastblock , lastblock , keytable ) ;
		while( r-- ) dest[ pc + r ] = source[ pc + r ] ^ lastblock[ r ] ;
	}

}


void _CbcDecrypt( unsigned char *dest , unsigned char *source , int datalen , DESKEYTABLE *keytable )
{
	unsigned char	lastblock[ DESBLOCKSIZE ] ;
	unsigned char	startvariable[ DESBLOCKSIZE ] ;
	int		q , r , pc ;

	EncryptBlock( startvariable , XE1D2C3B45A697887 , keytable ) ;

	q = datalen >> 3 ;
	r = datalen & 7 ;
	pc = datalen - r ;

	if( r )
	{
		if( q )
			EncryptBlock( lastblock , &source[ pc - DESBLOCKSIZE ] , keytable ) ;
		else
			EncryptBlock( lastblock , startvariable , keytable ) ;

		while( r-- ) dest[ pc + r ] = source[ pc + r ] ^ lastblock[ r ] ;
	}

	if( q )
	{
		while( --q  )
		{
			pc -= DESBLOCKSIZE ;
			DecryptBlock( &dest[ pc ] , &source[ pc ] , keytable ) ;
			XorBlock( &dest[ pc ] , &source[ pc-DESBLOCKSIZE ] ) ;
		}

		DecryptBlock( dest , source , keytable ) ;
		XorBlock( dest , startvariable ) ;
	}

}

