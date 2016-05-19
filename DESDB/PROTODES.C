#include "des.h"

char SHIFT[16] = {0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0};

unsigned char S[8][64] =
{
      { 14, 4,13, 1,	 2,15,11, 8,	 3,10, 6,12,	 5, 9, 0, 7,
	 0,15, 7, 4,	14, 2,13, 1,	10, 6,12,11,	 9, 5, 3, 8,
	 4, 1,14, 8,	13, 6, 2,11,	15,12, 9, 7,	 3,10, 5, 0,
	15,12, 8, 2,	 4, 9, 1, 7,	 5,11, 3,14,	10, 0, 6,13 },
	
      { 15, 1, 8,14,	 6,11, 3, 4,	 9, 7, 2,13,	12, 0, 5,10,
      	 3,13, 4, 7,	15, 2, 8,14,	12, 0, 1,10,	 6, 9,11, 5,
      	 0,14, 7,11,	10, 4,13, 1,	 5, 8,12, 6,	 9, 3, 2,15,
      	13, 8,10, 1,	 3,15, 4, 2,	11, 6, 7,12,	 0, 5,14, 9 },
      	
      {	
};

unsigned char P[32] =
      {	16, 7,20,21,	29,12,28,17,   	 1,15,23,26,	 5,18,31,10,
      	 2, 8,24,14,	32,27, 3, 9,	19,13,30, 6,	22,11, 4,25 };
      	 
typedef union {
	unsigned long	l;
	struct {
		unsigned char b3;
		unsigned char b2;
		unsigned char b1;
		unsigned char b0;
		} b;
	} LB;

#define KEYMASK		0x3F3F3F3Ful	

unsigned long  PFTAB[8][64];


LB IPTABLEFT[256];
LB IPTABRIGHT[256];
LB RIPTABLEFT[256];
LB RIPTABRIGHT[256];
LB PC1TABLEFT[256];
LB PC1TABRIGHT[256];

unsigned char KEY[8][6] =
     {{	18,15,21, 8,31,27 },
      {	29, 4,17,26,11,22 },
      {	 9,13,20,28, 6,24 },
      {	16,25, 5,12,19,30 },
      {	19, 8,29,23,13, 5 },
      {	30,20, 9,15,27,12 },
      { 16,11,21, 4,26, 7 }};
      
#define IPTRANSFER(LEFT, RIGHT, ptr) \
	LEFT.l = IPTABLEFT[ ptr[7] ].l; \
	RIGHT.l = IPTABRIGHT[ ptr[7] ].l; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l |= IPTABLEFT[ ptr[6] ].l; \
	RIGHT.l |= IPTABRIGHT[ ptr[6] ].l; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l |= IPTABLEFT[ ptr[5] ].l; \
	RIGHT.l |= IPTABRIGHT[ ptr[5] ].l; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l |= IPTABLEFT[ ptr[4] ].l; \
	RIGHT.l |= IPTABRIGHT[ ptr[4] ].l; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l |= IPTABLEFT[ ptr[3] ].l; \
	RIGHT.l |= IPTABRIGHT[ ptr[3] ].l; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l |= IPTABLEFT[ ptr[2] ].l; \
	RIGHT.l |= IPTABRIGHT[ ptr[2] ].l; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l |= IPTABLEFT[ ptr[1] ].l; \
	RIGHT.l |= IPTABRIGHT[ ptr[1] ].l; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l |= IPTABLEFT[ ptr[0] ].l; \
	RIGHT.l |= IPTABRIGHT[ ptr[0] ].l; 

#define RIPTRANSFER(LEFT, RIGHT, OLDLEFT, OLDRIGHT) \
	LEFT.l = RIPTABLEFT[ OLDRIGHT.b.b3 ].l; \
	RIGHT.l = RIPTABRIGHT[ OLDRIGHT.b.b3 ].l; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l |= RIPTABLEFT[ OLDLEFT.b.b0 ].l; \
	RIGHT.l |= RIPTABRIGHT[ OLDLEFT.b.b0 ].l; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l |= RIPTABLEFT[ OLDRIGHT.b.b2 ].l; \
	RIGHT.l |= RIPTABRIGHT[ OLDRIGHT.b.b2 ].l; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l |= RIPTABLEFT[ OLDLEFT.b.b1 ].l; \
	RIGHT.l |= RIPTABRIGHT[ OLDLEFT.b.b1 ].l; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l |= RIPTABLEFT[ OLDRIGHT.b.b1 ].l; \
	RIGHT.l |= RIPTABRIGHT[ OLDRIGHT.b.b1 ].l; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l |= RIPTABLEFT[ OLDLEFT.b.b2 ].l; \
	RIGHT.l |= RIPTABRIGHT[ OLDLEFT.b.b2 ].l; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l |= RIPTABLEFT[ OLDRIGHT.b.b0 ].l; \
	RIGHT.l |= RIPTABRIGHT[ OLDRIGHT.b.b0 ].l; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l |= RIPTABLEFT[ OLDLEFT.b.b3 ].l; \
	RIGHT.l |= RIPTABRIGHT[ OLDLEFT.b.b3 ].l; 

#define RORLONG(x) (((x)<<1)|((x&0x80000000ul)?1:0))

#define DES_STEP(LEFT, RIGHT, KeyTable, IterNo) \
	lb.l = (RORLONG(RIGHT.l)^(KeyTable->KEY[IterNo].KEY7531))&KEYMASK; \
	LEFT.l ^= PFTAB[1][lb.b.b0]^PFTAB[3][lb.b.b1]^PFTAB[5][lb.b.b2]^PFTAB[7][lb.b.b3]; \
	lb.l = ((RIGHT.l>>3)^((RIGHT.l&7)<<29)^(KeyTable->KEY[IterNo].KEY6420))&KEYMASK; \
	LEFT.l ^= PFTAB[0][lb.b.b0]^PFTAB[2][lb.b.b1]^PFTAB[4][lb.b.b2]^PFTAB[6][lb.b.b3]; 

	
#define bit0(x) (((x)>>7)&1);
#define bit1(x) (((x)>>6)&1);
#define bit2(x) (((x)>>5)&1);
#define bit3(x) (((x)>>4)&1);
#define bit4(x) (((x)>>3)&1);
#define bit5(x) (((x)>>2)&1);
#define bit6(x) (((x)>>1)&1);
#define bit7(x) (((x))&1);
	
	
unsigned long PTRANSFER(unsigned long x)
{           
	unsigned long r = 0;
	int	i;
	for ( i = 32 ; i-- ; ) r = (r<<1) + ((x>>(32-P[i]))&1);
	return r;
}

void DesInit()
{
	int	i;
	
	for( i = 256 ; i-- ; ) {
		IPTABLEFT[ i ].b.b0 = bit1(i);
		IPTABLEFT[ i ].b.b1 = bit3(i);
		IPTABLEFT[ i ].b.b2 = bit5(i);
		IPTABLEFT[ i ].b.b3 = bit7(i);
		
		IPTABRIGHT[ i ].b.b0 = bit0(i);
		IPTABRIGHT[ i ].b.b1 = bit2(i);
		IPTABRIGHT[ i ].b.b2 = bit4(i);
		IPTABRIGHT[ i ].b.b3 = bit6(i);
		
		RIPTABLEFT[ i ].b.b0 = bit7(i);
		RIPTABLEFT[ i ].b.b1 = bit6(i);
		RIPTABLEFT[ i ].b.b2 = bit5(i);
		RIPTABLEFT[ i ].b.b3 = bit4(i);
		
		RIPTABRIGHT[ i ].b.b0 = bit3(i);
		RIPTABRIGHT[ i ].b.b1 = bit2(i);
		RIPTABRIGHT[ i ].b.b2 = bit1(i);
		RIPTABRIGHT[ i ].b.b3 = bit0(i);
		
		PC1TABLEFT[ i ].b.b0 = bit0(i);
		PC1TABLEFT[ i ].b.b1 = bit1(i);
		PC1TABLEFT[ i ].b.b2 = bit2(i);
		PC1TABLEFT[ i ].b.b3 = bit3(i);
		
		PC1TABRIGHT[ i ].b.b0 = bit6(i);
		PC1TABRIGHT[ i ].b.b1 = bit5(i);
		PC1TABRIGHT[ i ].b.b2 = bit4(i);
		PC1TABRIGHT[ i ].b.b3 = bit3(i);
		
	}
	
	for( j = 8 ; j-- ; ) for( i = 64 ; i-- ; )
		PFTAB[j][i] = PTRANSFER( ((unsigned long)S[j][ (i&0x20)+((i&1)<<4)+((i&0x1E)>>1) ]) << (j<<2) );
}
				
void InitDesKeyTable( DESKEYTABLE * keytable , unsigned char * key )
{
	LB	a, d, k;
	
	a.l = PC1TABLEFT[ key[7] ].l;
	d.l = PC1TABRIGHT[ key[7] ].l
	a.l <<= 1;
	d.l <<= 1;
	a.l |= PC1TABLEFT[ key[6] ].l;
	d.l |= PC1TABRIGHT[ key[6] ].l
	a.l <<= 1;
	d.l <<= 1;
	a.l |= PC1TABLEFT[ key[5] ].l;
	d.l |= PC1TABRIGHT[ key[5] ].l
	a.l <<= 1;
	d.l <<= 1;
	a.l |= PC1TABLEFT[ key[4] ].l;
	d.l |= PC1TABRIGHT[ key[4] ].l
	a.l <<= 1;
	d.l <<= 1;
	a.l |= PC1TABLEFT[ key[3] ].l;
	d.l |= PC1TABRIGHT[ key[3] ].l
	a.l <<= 1;
	d.l <<= 1;
	a.l |= PC1TABLEFT[ key[2] ].l;
	d.l |= PC1TABRIGHT[ key[2] ].l
	a.l <<= 1;
	d.l <<= 1;
	a.l |= PC1TABLEFT[ key[1] ].l;
	d.l |= PC1TABRIGHT[ key[1] ].l
	a.l <<= 1;
	d.l <<= 1;
	a.l |= PC1TABLEFT[ key[0] ].l;
	d.l |= PC1TABRIGHT[ key[0] ].l 
	a.b.b3 &= 0xF0;
	d.b.b3 <<= 4;
	
	for( i = 0 ; i<16 ; i++ ) {
		c = SHIFT[ i ];
		do {           
			a.l = (a.l<<1) + ((a.b.b0&0x80)?0x10:0);
			d.l = (d.l<<1) + ((d.b.b0&0x80)?0x10:0);
		} while( c-- );

#define KEYVALUE(x,s) ((((((x>>s[0])&1<<1+(x>>s[1])&1)<<1+(x>>s[2])&1)<<1+(x>>s[3])&1)<<1+(x>>s[4])&1)<<1+(x>>s[5])&1

		k.b.b0 = KEYVALUE( a.l, KEY[0]);
		k.b.b1 = KEYVALUE( a.l, KEY[2]);
		k.b.b2 = KEYVALUE( a.l, KEY[4]);
		k.b.b3 = KEYVALUE( a.l, KEY[6]);
		keytable[i].KEY6420 = k.l;
		
		k.b.b0 = KEYVALUE( d.l, KEY[1]);
		k.b.b1 = KEYVALUE( d.l, KEY[3]);
		k.b.b2 = KEYVALUE( d.l, KEY[5]);
		k.b.b3 = KEYVALUE( d.l, KEY[7]);
		keytable[i].KEY7531 = k.l;
	}
}
void EncryptBlock	(
				unsigned char * ciphertext ,
				unsigned char * plaintext  ,
				DESKEYTABLE * keytable
			)
{
	LB	a, d, l, r, lb;
	
	IPTRANSFER( a , d , plaintext )
	
	DES_STEP( a , d , keytable, 0 )
	DES_STEP( d , a , keytable, 1 )
	DES_STEP( a , d , keytable, 2 )
	DES_STEP( d , a , keytable, 3 )
	DES_STEP( a , d , keytable, 4 )
	DES_STEP( d , a , keytable, 5 )
	DES_STEP( a , d , keytable, 6 )
	DES_STEP( d , a , keytable, 7 )
	DES_STEP( a , d , keytable, 8 )
	DES_STEP( d , a , keytable, 9 )
	DES_STEP( a , d , keytable, 10 )
	DES_STEP( d , a , keytable, 11 )
	DES_STEP( a , d , keytable, 12 )
	DES_STEP( d , a , keytable, 13 )
	DES_STEP( a , d , keytable, 14 )
	DES_STEP( d , a , keytable, 15 )

	RIPTRANSFER( l, r, d, a )
                           
	ciphertext[0] = l.b.b0;
	ciphertext[1] = l.b.b1;
	ciphertext[2] = l.b.b2;
	ciphertext[3] = l.b.b3;

	ciphertext[4] = r.b.b0;
	ciphertext[5] = r.b.b1;
	ciphertext[6] = r.b.b2;
	ciphertext[7] = r.b.b3;
}	

void DecryptBlock	(
				unsigned char * plaintext  ,
				unsigned char * ciphertext ,
				DESKEYTABLE * keytable
			)
{
	LB	a, d, l, r, lb;
	
	IPTRANSFER( a , d , ciphertext )
	
	DES_STEP( a , d , keytable, 15 )
	DES_STEP( d , a , keytable, 14 )
	DES_STEP( a , d , keytable, 13 )
	DES_STEP( d , a , keytable, 12 )
	DES_STEP( a , d , keytable, 11 )
	DES_STEP( d , a , keytable, 10 )
	DES_STEP( a , d , keytable, 9 )
	DES_STEP( d , a , keytable, 8 )
	DES_STEP( a , d , keytable, 7 )
	DES_STEP( d , a , keytable, 6 )
	DES_STEP( a , d , keytable, 5 )
	DES_STEP( d , a , keytable, 4 )
	DES_STEP( a , d , keytable, 3 )
	DES_STEP( d , a , keytable, 2 )
	DES_STEP( a , d , keytable, 1 )
	DES_STEP( d , a , keytable, 0 )

	RIPTRANSFER( l, r, d, a )
                           
	plaintext[0] = l.b.b0;
	plaintext[1] = l.b.b1;
	plaintext[2] = l.b.b2;
	plaintext[3] = l.b.b3;

	plaintext[4] = r.b.b0;
	plaintext[5] = r.b.b1;
	plaintext[6] = r.b.b2;
	plaintext[7] = r.b.b3;
}	
