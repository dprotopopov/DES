#include <stdio.h>

typedef union {
	unsigned long	l;
	struct {
		unsigned char b3;
		unsigned char b2;
		unsigned char b1;
		unsigned char b0;
		} b;
	} LB;


extern pascal unsigned long PFTAB0[];
extern pascal unsigned long PFTAB1[];
extern pascal unsigned long PFTAB2[];
extern pascal unsigned long PFTAB3[];
extern pascal unsigned long PFTAB4[];
extern pascal unsigned long PFTAB5[];
extern pascal unsigned long PFTAB6[];
extern pascal unsigned long PFTAB7[];

LB IPTABLEFT[256];
LB IPTABRIGHT[256];
LB RIPTABLEFT[256];
LB RIPTABRIGHT[256];
LB PC1TABLEFT[256];
LB PC1TABRIGHT[256];

#define bit0(x) (((x)>>7)&1);
#define bit1(x) (((x)>>6)&1);
#define bit2(x) (((x)>>5)&1);
#define bit3(x) (((x)>>4)&1);
#define bit4(x) (((x)>>3)&1);
#define bit5(x) (((x)>>2)&1);
#define bit6(x) (((x)>>1)&1);
#define bit7(x) (((x))&1);
	

void print_tab(unsigned long *ptr, int i)
{
	int  j;

	printf("unsigned long PFTAB%1d[64] =\n{\n", i);
	for( i = 0 ; i < 64 ; i += 8 ) {
		printf("\t");
		for( j = 0 ; j < 8 ; j++ ) {
			printf("0x%08lXul", ptr[i+j]);
			if( (i+j) != 63 ) printf(",");
		}
		printf("\n");
	}
	printf("};\n");
}

		
	
void main()
{
	int  i, j;

	print_tab(PFTAB0, 0);
	print_tab(PFTAB1, 1);
	print_tab(PFTAB2, 2);
	print_tab(PFTAB3, 3);
	print_tab(PFTAB4, 4);
	print_tab(PFTAB5, 5);
	print_tab(PFTAB6, 6);
	print_tab(PFTAB7, 7);
	
	
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

	printf("unsigned long IPTABLEFT[256] =\n{\n");
	for( i = 0 ; i<256 ; i+=16 ) {
		printf("\t");
		for( j=0; j<16 ; j++ ) {
			printf("0x%08lXul",IPTABLEFT[i+j].l);
			if ( (i+j)!=255) printf(",");
		}
		printf("\n");
	}
	printf("};\n");

	printf("unsigned long IPTABRIGHT[256] =\n{\n");
	for( i = 0 ; i<256 ; i+=16 ) {
		printf("\t");
		for( j=0; j<16 ; j++ ) {
			printf("0x%08lXul",IPTABRIGHT[i+j].l);
			if ( (i+j)!=255) printf(",");
		}
		printf("\n");
	}
	printf("};\n");

	printf("unsigned long RIPTABLEFT[256] =\n{\n");
	for( i = 0 ; i<256 ; i+=16 ) {
		printf("\t");
		for( j=0; j<16 ; j++ ) {
			printf("0x%08lXul",RIPTABLEFT[i+j].l);
			if ( (i+j)!=255) printf(",");
		}
		printf("\n");
	}
	printf("};\n");

	printf("unsigned long RIPTABRIGHT[256] =\n{\n");
	for( i = 0 ; i<256 ; i+=16 ) {
		printf("\t");
		for( j=0; j<16 ; j++ ) {
			printf("0x%08lXul",RIPTABRIGHT[i+j].l);
			if ( (i+j)!=255) printf(",");
		}
		printf("\n");
	}
	printf("};\n");

	printf("unsigned long PC1TABLEFT[256] =\n{\n");
	for( i = 0 ; i<256 ; i+=16 ) {
		printf("\t");
		for( j=0; j<16 ; j++ ) {
			printf("0x%08lXul",PC1TABLEFT[i+j].l);
			if ( (i+j)!=255) printf(",");
		}
		printf("\n");
	}
	printf("};\n");

	printf("unsigned long PC1TABRIGHT[256] =\n{\n");
	for( i = 0 ; i<256 ; i+=16 ) {
		printf("\t");
		for( j=0; j<16 ; j++ ) {
			printf("0x%08lXul",PC1TABRIGHT[i+j].l);
			if ( (i+j)!=255) printf(",");
		}
		printf("\n");
	}
	printf("};\n");

	
}
