;
;	DES386.ASM
;
;	Copyright (C) 1994 , DialogBank
;


;------------------------------------------------------------------------
;
;	void far InitDesKeyTable( 
;					DESKEYTABLE far * keytable ,
;					unsigned char far * key 
;				)
;
;------------------------------------------------------------------------
;
;	void far EncryptBlock	( 
;					unsigned char far * outputblock ,
;					unsigned char far * inputblock ,
;					DESKEYTABLE far * keytable
;				)
;
;------------------------------------------------------------------------
;
;	void far DecryptBlock	( 
;					unsigned char far * outputblock ,
;					unsigned char far * inputblock ,
;					DESKEYTABLE far * keytable
;				)
;
;------------------------------------------------------------------------

;
;	tasm -ml des386.asm
;

	.386

	.MODEL LARGE , C


STACKBASE = 6


DES_STEP	MACRO 	LEFT , RIGHT , IterNo

		mov	ecx , RIGHT
		ror	ecx , 1
		xor	ecx , dword ptr es:[ si + (8*IterNo) ]
		and	ecx , dword ptr [ KEYMASK ]
		mov	bl , cl
		xor	LEFT , dword ptr PFTAB6[ bx ]
		mov	bl , ch
		xor	LEFT , dword ptr PFTAB4[ bx ]
		push	ecx
		pop	cx
		pop	cx
		mov	bl , cl
		xor	LEFT , dword ptr PFTAB2[ bx ]
		mov	bl , ch
		xor	LEFT , dword ptr PFTAB0[ bx ]

		mov	ecx , RIGHT
		rol	ecx , 3
		xor	ecx , dword ptr es:[ si + (8*IterNo) + 4 ]
		and	ecx , dword ptr [ KEYMASK ]
		mov	bl , cl
		xor	LEFT , dword ptr PFTAB7[ bx ]
		mov	bl , ch
		xor	LEFT , dword ptr PFTAB5[ bx ]
		push	ecx
		pop	cx
		pop	cx
		mov	bl , cl
		xor	LEFT , dword ptr PFTAB3[ bx ]
		mov	bl , ch
		xor	LEFT , dword ptr PFTAB1[ bx ]

		ENDM


;
;	es:[si] -> sourceBlock
;

IPTRANSFER	MACRO	LEFT , RIGHT

		movzx	bx , byte ptr es:[ si + 7 ]
		shl	bx , 2
		mov	LEFT , IPTABLEFT[ bx ]
		mov	RIGHT , IPTABRIGHT[ bx ]
		shl	LEFT , 1
		shl	RIGHT , 1
		movzx	bx , byte ptr es:[ si + 6 ]
		shl	bx , 2
		xor	LEFT , dword ptr IPTABLEFT[ bx ]
		xor	RIGHT , dword ptr IPTABRIGHT[ bx ]
		shl	LEFT , 1
		shl	RIGHT , 1
		movzx	bx , byte ptr es:[ si + 5 ]
		shl	bx , 2
		xor	LEFT , dword ptr IPTABLEFT[ bx ]
		xor	RIGHT , dword ptr IPTABRIGHT[ bx ]
		shl	LEFT , 1
		shl	RIGHT , 1
		movzx	bx , byte ptr es:[ si + 4 ]
		shl	bx , 2
		xor	LEFT , dword ptr IPTABLEFT[ bx ]
		xor	RIGHT , dword ptr IPTABRIGHT[ bx ]
		shl	LEFT , 1
		shl	RIGHT , 1
		movzx	bx , byte ptr es:[ si + 3 ]
		shl	bx , 2
		xor	LEFT , dword ptr IPTABLEFT[ bx ]
		xor	RIGHT , dword ptr IPTABRIGHT[ bx ]
		shl	LEFT , 1
		shl	RIGHT , 1
		movzx	bx , byte ptr es:[ si + 2 ]
		shl	bx , 2
		xor	LEFT , dword ptr IPTABLEFT[ bx ]
		xor	RIGHT , dword ptr IPTABRIGHT[ bx ]
		shl	LEFT , 1
		shl	RIGHT , 1
		movzx	bx , byte ptr es:[ si + 1 ]
		shl	bx , 2
		xor	LEFT , dword ptr IPTABLEFT[ bx ]
		xor	RIGHT , dword ptr IPTABRIGHT[ bx ]
		shl	LEFT , 1
		shl	RIGHT , 1
		movzx	bx , byte ptr es:[ si + 0 ]
		shl	bx , 2
		xor	LEFT , dword ptr IPTABLEFT[ bx ]
		xor	RIGHT , dword ptr IPTABRIGHT[ bx ]

		ENDM


;	edx - left , eax - right

RIPTRANSFER	MACRO

		mov	bl , dl
		shl	bx , 2
		mov	ecx , dword ptr RIPTABLEFT[ bx ]
		mov	edi , dword ptr RIPTABRIGHT[ bx ]
		movzx	bx , al
		shl	bx , 2
		shr	ecx , 1
		shr	edi , 1
		xor	ecx , dword ptr RIPTABLEFT[ bx ]
		xor	edi , dword ptr RIPTABRIGHT[ bx ]
		movzx	bx , dh
		shl	bx , 2
		shr	ecx , 1
		shr	edi , 1
		xor	ecx , dword ptr RIPTABLEFT[ bx ]
		xor	edi , dword ptr RIPTABRIGHT[ bx ]
		movzx	bx , ah
		shl	bx , 2
		shr	ecx , 1
		shr	edi , 1
		xor	ecx , dword ptr RIPTABLEFT[ bx ]
		xor	edi , dword ptr RIPTABRIGHT[ bx ]

		push	edx
		pop	dx
		pop	dx

		push	eax
		pop	ax
		pop	ax

		movzx	bx , dl
		shl	bx , 2
		shr	ecx , 1
		shr	edi , 1
		xor	ecx , dword ptr RIPTABLEFT[ bx ]
		xor	edi , dword ptr RIPTABRIGHT[ bx ]
		movzx	bx , al
		shl	bx , 2
		shr	ecx , 1
		shr	edi , 1
		xor	ecx , dword ptr RIPTABLEFT[ bx ]
		xor	edi , dword ptr RIPTABRIGHT[ bx ]
		movzx	bx , dh
		shl	bx , 2
		shr	ecx , 1
		shr	edi , 1
		xor	ecx , dword ptr RIPTABLEFT[ bx ]
		xor	edi , dword ptr RIPTABRIGHT[ bx ]
		movzx	bx , ah
		shl	bx , 2
		shr	ecx , 1
		shr	edi , 1
		xor	ecx , dword ptr RIPTABLEFT[ bx ]
		xor	edi , dword ptr RIPTABRIGHT[ bx ]

		ENDM







DESDATA		SEGMENT PARA USE16 PUBLIC 'DATA'

KEYMASK	label dword
	DB	0FCh , 0FCh , 0FCh , 0FCh

KEYSHIFTFLAG label dword
	DW	1 , 0011111101111110B

DESDATA		ENDS



DESDATA		SEGMENT PARA USE16 PUBLIC 'DATA'

IPTABLEFT	label dword
I = 0
	REPT 256
	DB		( ( I       ) and 1 ) 
	DB		( ( I shr 2 ) and 1 ) 
	DB		( ( I shr 4 ) and 1 )
	DB		( ( I shr 6 ) and 1 )
I = I + 1
	ENDM

IPTABRIGHT label dword
I = 0
	REPT 256
	DB		( ( I shr 1 ) and 1 ) 
	DB		( ( I shr 3 ) and 1 ) 
	DB		( ( I shr 5 ) and 1 )
	DB		( ( I shr 7 ) and 1 )
I = I + 1
	ENDM


RIPTABLEFT label dword
I = 0
	REPT 256
	DB		( ( I shl 7 ) and 080h ) 
	DB		( ( I shl 6 ) and 080h ) 
	DB		( ( I shl 5 ) and 080h )
	DB		( ( I shl 4 ) and 080h )
I = I + 1
	ENDM


PC1TABLEFT  label dword
RIPTABRIGHT label dword
I = 0
	REPT 256
	DB		( ( I shl 3 ) and 080h ) 
	DB		( ( I shl 2 ) and 080h ) 
	DB		( ( I shl 1 ) and 080h )
	DB		( ( I       ) and 080h )
I = I + 1
	ENDM

DESDATA		ENDS



DESDATA		SEGMENT PARA USE16 PUBLIC 'DATA'

PC1TABRIGHT label dword
I = 0
	REPT 256
	DB		( ( I shl 3 ) and 080h )
	DB		( ( I shl 4 ) and 080h )
	DB		( ( I shl 5 ) and 080h )
	DB		( ( I shl 6 ) and 080h )
I = I + 1
	ENDM

DESDATA		ENDS



DESDATA		SEGMENT PARA USE16 PUBLIC 'DATA'

PFTAB0	label dword
	DB	000h , 082h , 080h , 000h
	DB	000h , 000h , 000h , 000h
	DB	000h , 080h , 000h , 000h
	DB	002h , 082h , 080h , 000h
	DB	002h , 080h , 080h , 000h
	DB	002h , 082h , 000h , 000h
	DB	002h , 000h , 000h , 000h
	DB	000h , 080h , 000h , 000h
	DB	000h , 002h , 000h , 000h
	DB	000h , 082h , 080h , 000h
	DB	002h , 082h , 080h , 000h
	DB	000h , 002h , 000h , 000h
	DB	002h , 002h , 080h , 000h
	DB	002h , 080h , 080h , 000h
	DB	000h , 000h , 080h , 000h
	DB	002h , 000h , 000h , 000h
	DB	002h , 002h , 000h , 000h
	DB	000h , 002h , 080h , 000h
	DB	000h , 002h , 080h , 000h
	DB	000h , 082h , 000h , 000h
	DB	000h , 082h , 000h , 000h
	DB	000h , 080h , 080h , 000h
	DB	000h , 080h , 080h , 000h
	DB	002h , 002h , 080h , 000h
	DB	002h , 080h , 000h , 000h
	DB	002h , 000h , 080h , 000h
	DB	002h , 000h , 080h , 000h
	DB	002h , 080h , 000h , 000h
	DB	000h , 000h , 000h , 000h
	DB	002h , 002h , 000h , 000h
	DB	002h , 082h , 000h , 000h
	DB	000h , 000h , 080h , 000h
	DB	000h , 080h , 000h , 000h
	DB	002h , 082h , 080h , 000h
	DB	002h , 000h , 000h , 000h
	DB	000h , 080h , 080h , 000h
	DB	000h , 082h , 080h , 000h
	DB	000h , 000h , 080h , 000h
	DB	000h , 000h , 080h , 000h
	DB	000h , 002h , 000h , 000h
	DB	002h , 080h , 080h , 000h
	DB	000h , 080h , 000h , 000h
	DB	000h , 082h , 000h , 000h
	DB	002h , 000h , 080h , 000h
	DB	000h , 002h , 000h , 000h
	DB	002h , 000h , 000h , 000h
	DB	002h , 002h , 080h , 000h
	DB	002h , 082h , 000h , 000h
	DB	002h , 082h , 080h , 000h
	DB	002h , 080h , 000h , 000h
	DB	000h , 080h , 080h , 000h
	DB	002h , 002h , 080h , 000h
	DB	002h , 000h , 080h , 000h
	DB	002h , 002h , 000h , 000h
	DB	002h , 082h , 000h , 000h
	DB	000h , 082h , 080h , 000h
	DB	002h , 002h , 000h , 000h
	DB	000h , 002h , 080h , 000h
	DB	000h , 002h , 080h , 000h
	DB	000h , 000h , 000h , 000h
	DB	002h , 080h , 000h , 000h
	DB	000h , 082h , 000h , 000h
	DB	000h , 000h , 000h , 000h
	DB	002h , 080h , 080h , 000h


DESDATA		ENDS


DESDATA		SEGMENT PARA USE16 PUBLIC 'DATA'


PFTAB1	label dword
	DB	010h , 040h , 008h , 040h
	DB	000h , 040h , 000h , 040h
	DB	000h , 040h , 000h , 000h
	DB	010h , 040h , 008h , 000h
	DB	000h , 000h , 008h , 000h
	DB	010h , 000h , 000h , 000h
	DB	010h , 000h , 008h , 040h
	DB	010h , 040h , 000h , 040h
	DB	010h , 000h , 000h , 040h
	DB	010h , 040h , 008h , 040h
	DB	000h , 040h , 008h , 040h
	DB	000h , 000h , 000h , 040h
	DB	000h , 040h , 000h , 040h
	DB	000h , 000h , 008h , 000h
	DB	010h , 000h , 000h , 000h
	DB	010h , 000h , 008h , 040h
	DB	000h , 040h , 008h , 000h
	DB	010h , 000h , 008h , 000h
	DB	010h , 040h , 000h , 040h
	DB	000h , 000h , 000h , 000h
	DB	000h , 000h , 000h , 040h
	DB	000h , 040h , 000h , 000h
	DB	010h , 040h , 008h , 000h
	DB	000h , 000h , 008h , 040h
	DB	010h , 000h , 008h , 000h
	DB	010h , 000h , 000h , 040h
	DB	000h , 000h , 000h , 000h
	DB	000h , 040h , 008h , 000h
	DB	010h , 040h , 000h , 000h
	DB	000h , 040h , 008h , 040h
	DB	000h , 000h , 008h , 040h
	DB	010h , 040h , 000h , 000h
	DB	000h , 000h , 000h , 000h
	DB	010h , 040h , 008h , 000h
	DB	010h , 000h , 008h , 040h
	DB	000h , 000h , 008h , 000h
	DB	010h , 040h , 000h , 040h
	DB	000h , 000h , 008h , 040h
	DB	000h , 040h , 008h , 040h
	DB	000h , 040h , 000h , 000h
	DB	000h , 000h , 008h , 040h
	DB	000h , 040h , 000h , 040h
	DB	010h , 000h , 000h , 000h
	DB	010h , 040h , 008h , 040h
	DB	010h , 040h , 008h , 000h
	DB	010h , 000h , 000h , 000h
	DB	000h , 040h , 000h , 000h
	DB	000h , 000h , 000h , 040h
	DB	010h , 040h , 000h , 000h
	DB	000h , 040h , 008h , 040h
	DB	000h , 000h , 008h , 000h
	DB	010h , 000h , 000h , 040h
	DB	010h , 000h , 008h , 000h
	DB	010h , 040h , 000h , 040h
	DB	010h , 000h , 000h , 040h
	DB	010h , 000h , 008h , 000h
	DB	000h , 040h , 008h , 000h
	DB	000h , 000h , 000h , 000h
	DB	000h , 040h , 000h , 040h
	DB	010h , 040h , 000h , 000h
	DB	010h , 000h , 008h , 000h
	DB	010h , 000h , 008h , 040h
	DB	010h , 040h , 008h , 040h
	DB	000h , 040h , 008h , 000h

DESDATA		ENDS


DESDATA		SEGMENT PARA USE16 PUBLIC 'DATA'

PFTAB2	label dword
	DB	004h , 001h , 000h , 000h
	DB	000h , 001h , 001h , 004h
	DB	000h , 000h , 000h , 000h
	DB	004h , 000h , 001h , 004h
	DB	000h , 001h , 000h , 004h
	DB	000h , 000h , 000h , 000h
	DB	004h , 001h , 001h , 000h
	DB	000h , 001h , 000h , 004h
	DB	004h , 000h , 001h , 000h
	DB	004h , 000h , 000h , 004h
	DB	004h , 000h , 000h , 004h
	DB	000h , 000h , 001h , 000h
	DB	004h , 001h , 001h , 004h
	DB	004h , 000h , 001h , 000h
	DB	000h , 000h , 001h , 004h
	DB	004h , 001h , 000h , 000h
	DB	000h , 000h , 000h , 004h
	DB	004h , 000h , 000h , 000h
	DB	000h , 001h , 001h , 004h
	DB	000h , 001h , 000h , 000h
	DB	000h , 001h , 001h , 000h
	DB	000h , 000h , 001h , 004h
	DB	004h , 000h , 001h , 004h
	DB	004h , 001h , 001h , 000h
	DB	004h , 001h , 000h , 004h
	DB	000h , 001h , 001h , 000h
	DB	000h , 000h , 001h , 000h
	DB	004h , 001h , 000h , 004h
	DB	004h , 000h , 000h , 000h
	DB	004h , 001h , 001h , 004h
	DB	000h , 001h , 000h , 000h
	DB	000h , 000h , 000h , 004h
	DB	000h , 001h , 001h , 004h
	DB	000h , 000h , 000h , 004h
	DB	004h , 000h , 001h , 000h
	DB	004h , 001h , 000h , 000h
	DB	000h , 000h , 001h , 000h
	DB	000h , 001h , 001h , 004h
	DB	000h , 001h , 000h , 004h
	DB	000h , 000h , 000h , 000h
	DB	000h , 001h , 000h , 000h
	DB	004h , 000h , 001h , 000h
	DB	004h , 001h , 001h , 004h
	DB	000h , 001h , 000h , 004h
	DB	004h , 000h , 000h , 004h
	DB	000h , 001h , 000h , 000h
	DB	000h , 000h , 000h , 000h
	DB	004h , 000h , 001h , 004h
	DB	004h , 001h , 000h , 004h
	DB	000h , 000h , 001h , 000h
	DB	000h , 000h , 000h , 004h
	DB	004h , 001h , 001h , 004h
	DB	004h , 000h , 000h , 000h
	DB	004h , 001h , 001h , 000h
	DB	000h , 001h , 001h , 000h
	DB	004h , 000h , 000h , 004h
	DB	000h , 000h , 001h , 004h
	DB	004h , 001h , 000h , 004h
	DB	004h , 001h , 000h , 000h
	DB	000h , 000h , 001h , 004h
	DB	004h , 001h , 001h , 000h
	DB	004h , 000h , 000h , 000h
	DB	004h , 000h , 001h , 004h
	DB	000h , 001h , 001h , 000h

DESDATA		ENDS


DESDATA		SEGMENT PARA USE16 PUBLIC 'DATA'

PFTAB3	label dword
	DB	000h , 010h , 040h , 080h
	DB	040h , 010h , 000h , 080h
	DB	040h , 010h , 000h , 080h
	DB	040h , 000h , 000h , 000h
	DB	040h , 010h , 040h , 000h
	DB	040h , 000h , 040h , 080h
	DB	000h , 000h , 040h , 080h
	DB	000h , 010h , 000h , 080h
	DB	000h , 000h , 000h , 000h
	DB	000h , 010h , 040h , 000h
	DB	000h , 010h , 040h , 000h
	DB	040h , 010h , 040h , 080h
	DB	040h , 000h , 000h , 080h
	DB	000h , 000h , 000h , 000h
	DB	040h , 000h , 040h , 000h
	DB	000h , 000h , 040h , 080h
	DB	000h , 000h , 000h , 080h
	DB	000h , 010h , 000h , 000h
	DB	000h , 000h , 040h , 000h
	DB	000h , 010h , 040h , 080h
	DB	040h , 000h , 000h , 000h
	DB	000h , 000h , 040h , 000h
	DB	000h , 010h , 000h , 080h
	DB	040h , 010h , 000h , 000h
	DB	040h , 000h , 040h , 080h
	DB	000h , 000h , 000h , 080h
	DB	040h , 010h , 000h , 000h
	DB	040h , 000h , 040h , 000h
	DB	000h , 010h , 000h , 000h
	DB	040h , 010h , 040h , 000h
	DB	040h , 010h , 040h , 080h
	DB	040h , 000h , 000h , 080h
	DB	040h , 000h , 040h , 000h
	DB	000h , 000h , 040h , 080h
	DB	000h , 010h , 040h , 000h
	DB	040h , 010h , 040h , 080h
	DB	040h , 000h , 000h , 080h
	DB	000h , 000h , 000h , 000h
	DB	000h , 000h , 000h , 000h
	DB	000h , 010h , 040h , 000h
	DB	040h , 010h , 000h , 000h
	DB	040h , 000h , 040h , 000h
	DB	040h , 000h , 040h , 080h
	DB	000h , 000h , 000h , 080h
	DB	000h , 010h , 040h , 080h
	DB	040h , 010h , 000h , 080h
	DB	040h , 010h , 000h , 080h
	DB	040h , 000h , 000h , 000h
	DB	040h , 010h , 040h , 080h
	DB	040h , 000h , 000h , 080h
	DB	000h , 000h , 000h , 080h
	DB	000h , 010h , 000h , 000h
	DB	000h , 000h , 040h , 080h
	DB	000h , 010h , 000h , 080h
	DB	040h , 010h , 040h , 000h
	DB	040h , 000h , 040h , 080h
	DB	000h , 010h , 000h , 080h
	DB	040h , 010h , 000h , 000h
	DB	000h , 000h , 040h , 000h
	DB	000h , 010h , 040h , 080h
	DB	040h , 000h , 000h , 000h
	DB	000h , 000h , 040h , 000h
	DB	000h , 010h , 000h , 000h
	DB	040h , 010h , 040h , 000h

DESDATA		ENDS


DESDATA		SEGMENT PARA USE16 PUBLIC 'DATA'

PFTAB4	label dword
	DB	080h , 000h , 000h , 000h
	DB	080h , 000h , 004h , 001h
	DB	000h , 000h , 004h , 001h
	DB	080h , 000h , 000h , 021h
	DB	000h , 000h , 004h , 000h
	DB	080h , 000h , 000h , 000h
	DB	000h , 000h , 000h , 020h
	DB	000h , 000h , 004h , 001h
	DB	080h , 000h , 004h , 020h
	DB	000h , 000h , 004h , 000h
	DB	080h , 000h , 000h , 001h
	DB	080h , 000h , 004h , 020h
	DB	080h , 000h , 000h , 021h
	DB	000h , 000h , 004h , 021h
	DB	080h , 000h , 004h , 000h
	DB	000h , 000h , 000h , 020h
	DB	000h , 000h , 000h , 001h
	DB	000h , 000h , 004h , 020h
	DB	000h , 000h , 004h , 020h
	DB	000h , 000h , 000h , 000h
	DB	080h , 000h , 000h , 020h
	DB	080h , 000h , 004h , 021h
	DB	080h , 000h , 004h , 021h
	DB	080h , 000h , 000h , 001h
	DB	000h , 000h , 004h , 021h
	DB	080h , 000h , 000h , 020h
	DB	000h , 000h , 000h , 000h
	DB	000h , 000h , 000h , 021h
	DB	080h , 000h , 004h , 001h
	DB	000h , 000h , 000h , 001h
	DB	000h , 000h , 000h , 021h
	DB	080h , 000h , 004h , 000h
	DB	000h , 000h , 004h , 000h
	DB	080h , 000h , 000h , 021h
	DB	080h , 000h , 000h , 000h
	DB	000h , 000h , 000h , 001h
	DB	000h , 000h , 000h , 020h
	DB	000h , 000h , 004h , 001h
	DB	080h , 000h , 000h , 021h
	DB	080h , 000h , 004h , 020h
	DB	080h , 000h , 000h , 001h
	DB	000h , 000h , 000h , 020h
	DB	000h , 000h , 004h , 021h
	DB	080h , 000h , 004h , 001h
	DB	080h , 000h , 004h , 020h
	DB	080h , 000h , 000h , 000h
	DB	000h , 000h , 000h , 001h
	DB	000h , 000h , 004h , 021h
	DB	080h , 000h , 004h , 021h
	DB	080h , 000h , 004h , 000h
	DB	000h , 000h , 000h , 021h
	DB	080h , 000h , 004h , 021h
	DB	000h , 000h , 004h , 001h
	DB	000h , 000h , 000h , 000h
	DB	000h , 000h , 004h , 020h
	DB	000h , 000h , 000h , 021h
	DB	080h , 000h , 004h , 000h
	DB	080h , 000h , 000h , 001h
	DB	080h , 000h , 000h , 020h
	DB	000h , 000h , 004h , 000h
	DB	000h , 000h , 000h , 000h
	DB	000h , 000h , 004h , 020h
	DB	080h , 000h , 004h , 001h
	DB	080h , 000h , 000h , 020h

DESDATA		ENDS


DESDATA		SEGMENT PARA USE16 PUBLIC 'DATA'

PFTAB5	label dword
	DB	008h , 000h , 000h , 010h
	DB	000h , 000h , 020h , 010h
	DB	000h , 020h , 000h , 000h
	DB	008h , 020h , 020h , 010h
	DB	000h , 000h , 020h , 010h
	DB	008h , 000h , 000h , 000h
	DB	008h , 020h , 020h , 010h
	DB	000h , 000h , 020h , 000h
	DB	000h , 020h , 000h , 010h
	DB	008h , 020h , 020h , 000h
	DB	000h , 000h , 020h , 000h
	DB	008h , 000h , 000h , 010h
	DB	008h , 000h , 020h , 000h
	DB	000h , 020h , 000h , 010h
	DB	000h , 000h , 000h , 010h
	DB	008h , 020h , 000h , 000h
	DB	000h , 000h , 000h , 000h
	DB	008h , 000h , 020h , 000h
	DB	008h , 020h , 000h , 010h
	DB	000h , 020h , 000h , 000h
	DB	000h , 020h , 020h , 000h
	DB	008h , 020h , 000h , 010h
	DB	008h , 000h , 000h , 000h
	DB	008h , 000h , 020h , 010h
	DB	008h , 000h , 020h , 010h
	DB	000h , 000h , 000h , 000h
	DB	008h , 020h , 020h , 000h
	DB	000h , 020h , 020h , 010h
	DB	008h , 020h , 000h , 000h
	DB	000h , 020h , 020h , 000h
	DB	000h , 020h , 020h , 010h
	DB	000h , 000h , 000h , 010h
	DB	000h , 020h , 000h , 010h
	DB	008h , 000h , 000h , 000h
	DB	008h , 000h , 020h , 010h
	DB	000h , 020h , 020h , 000h
	DB	008h , 020h , 020h , 010h
	DB	000h , 000h , 020h , 000h
	DB	008h , 020h , 000h , 000h
	DB	008h , 000h , 000h , 010h
	DB	000h , 000h , 020h , 000h
	DB	000h , 020h , 000h , 010h
	DB	000h , 000h , 000h , 010h
	DB	008h , 020h , 000h , 000h
	DB	008h , 000h , 000h , 010h
	DB	008h , 020h , 020h , 010h
	DB	000h , 020h , 020h , 000h
	DB	000h , 000h , 020h , 010h
	DB	008h , 020h , 020h , 000h
	DB	000h , 020h , 020h , 010h
	DB	000h , 000h , 000h , 000h
	DB	008h , 000h , 020h , 010h
	DB	008h , 000h , 000h , 000h
	DB	000h , 020h , 000h , 000h
	DB	000h , 000h , 020h , 010h
	DB	008h , 020h , 020h , 000h
	DB	000h , 020h , 000h , 000h
	DB	008h , 000h , 020h , 000h
	DB	008h , 020h , 000h , 010h
	DB	000h , 000h , 000h , 000h
	DB	000h , 020h , 020h , 010h
	DB	000h , 000h , 000h , 010h
	DB	008h , 000h , 020h , 000h
	DB	008h , 020h , 000h , 010h

DESDATA		ENDS


DESDATA		SEGMENT PARA USE16 PUBLIC 'DATA'

PFTAB6	label dword
	DB	000h , 000h , 010h , 000h
	DB	001h , 000h , 010h , 002h
	DB	001h , 004h , 000h , 002h
	DB	000h , 000h , 000h , 000h
	DB	000h , 004h , 000h , 000h
	DB	001h , 004h , 000h , 002h
	DB	001h , 004h , 010h , 000h
	DB	000h , 004h , 010h , 002h
	DB	001h , 004h , 010h , 002h
	DB	000h , 000h , 010h , 000h
	DB	000h , 000h , 000h , 000h
	DB	001h , 000h , 000h , 002h
	DB	001h , 000h , 000h , 000h
	DB	000h , 000h , 000h , 002h
	DB	001h , 000h , 010h , 002h
	DB	001h , 004h , 000h , 000h
	DB	000h , 004h , 000h , 002h
	DB	001h , 004h , 010h , 000h
	DB	001h , 000h , 010h , 000h
	DB	000h , 004h , 000h , 002h
	DB	001h , 000h , 000h , 002h
	DB	000h , 000h , 010h , 002h
	DB	000h , 004h , 010h , 002h
	DB	001h , 000h , 010h , 000h
	DB	000h , 000h , 010h , 002h
	DB	000h , 004h , 000h , 000h
	DB	001h , 004h , 000h , 000h
	DB	001h , 004h , 010h , 002h
	DB	000h , 004h , 010h , 000h
	DB	001h , 000h , 000h , 000h
	DB	000h , 000h , 000h , 002h
	DB	000h , 004h , 010h , 000h
	DB	000h , 000h , 000h , 002h
	DB	000h , 004h , 010h , 000h
	DB	000h , 000h , 010h , 000h
	DB	001h , 004h , 000h , 002h
	DB	001h , 004h , 000h , 002h
	DB	001h , 000h , 010h , 002h
	DB	001h , 000h , 010h , 002h
	DB	001h , 000h , 000h , 000h
	DB	001h , 000h , 010h , 000h
	DB	000h , 000h , 000h , 002h
	DB	000h , 004h , 000h , 002h
	DB	000h , 000h , 010h , 000h
	DB	000h , 004h , 010h , 002h
	DB	001h , 004h , 000h , 000h
	DB	001h , 004h , 010h , 000h
	DB	000h , 004h , 010h , 002h
	DB	001h , 004h , 000h , 000h
	DB	001h , 000h , 000h , 002h
	DB	001h , 004h , 010h , 002h
	DB	000h , 000h , 010h , 002h
	DB	000h , 004h , 010h , 000h
	DB	000h , 000h , 000h , 000h
	DB	001h , 000h , 000h , 000h
	DB	001h , 004h , 010h , 002h
	DB	000h , 000h , 000h , 000h
	DB	001h , 004h , 010h , 000h
	DB	000h , 000h , 010h , 002h
	DB	000h , 004h , 000h , 000h
	DB	001h , 000h , 000h , 002h
	DB	000h , 004h , 000h , 002h
	DB	000h , 004h , 000h , 000h
	DB	001h , 000h , 010h , 000h

DESDATA		ENDS


DESDATA		SEGMENT PARA USE16 PUBLIC 'DATA'

PFTAB7	label dword
	DB	020h , 008h , 000h , 008h
	DB	000h , 008h , 000h , 000h
	DB	000h , 000h , 002h , 000h
	DB	020h , 008h , 002h , 008h
	DB	000h , 000h , 000h , 008h
	DB	020h , 008h , 000h , 008h
	DB	020h , 000h , 000h , 000h
	DB	000h , 000h , 000h , 008h
	DB	020h , 000h , 002h , 000h
	DB	000h , 000h , 002h , 008h
	DB	020h , 008h , 002h , 008h
	DB	000h , 008h , 002h , 000h
	DB	000h , 008h , 002h , 008h
	DB	020h , 008h , 002h , 000h
	DB	000h , 008h , 000h , 000h
	DB	020h , 000h , 000h , 000h
	DB	000h , 000h , 002h , 008h
	DB	020h , 000h , 000h , 008h
	DB	000h , 008h , 000h , 008h
	DB	020h , 008h , 000h , 000h
	DB	000h , 008h , 002h , 000h
	DB	020h , 000h , 002h , 000h
	DB	020h , 000h , 002h , 008h
	DB	000h , 008h , 002h , 008h
	DB	020h , 008h , 000h , 000h
	DB	000h , 000h , 000h , 000h
	DB	000h , 000h , 000h , 000h
	DB	020h , 000h , 002h , 008h
	DB	020h , 000h , 000h , 008h
	DB	000h , 008h , 000h , 008h
	DB	020h , 008h , 002h , 000h
	DB	000h , 000h , 002h , 000h
	DB	020h , 008h , 002h , 000h
	DB	000h , 000h , 002h , 000h
	DB	000h , 008h , 002h , 008h
	DB	000h , 008h , 000h , 000h
	DB	020h , 000h , 000h , 000h
	DB	020h , 000h , 002h , 008h
	DB	000h , 008h , 000h , 000h
	DB	020h , 008h , 002h , 000h
	DB	000h , 008h , 000h , 008h
	DB	020h , 000h , 000h , 000h
	DB	020h , 000h , 000h , 008h
	DB	000h , 000h , 002h , 008h
	DB	020h , 000h , 002h , 008h
	DB	000h , 000h , 000h , 008h
	DB	000h , 000h , 002h , 000h
	DB	020h , 008h , 000h , 008h
	DB	000h , 000h , 000h , 000h
	DB	020h , 008h , 002h , 008h
	DB	020h , 000h , 002h , 000h
	DB	020h , 000h , 000h , 008h
	DB	000h , 000h , 002h , 008h
	DB	000h , 008h , 000h , 008h
	DB	020h , 008h , 000h , 008h
	DB	000h , 000h , 000h , 000h
	DB	020h , 008h , 002h , 008h
	DB	000h , 008h , 002h , 000h
	DB	000h , 008h , 002h , 000h
	DB	020h , 008h , 000h , 000h
	DB	020h , 008h , 000h , 000h
	DB	020h , 000h , 002h , 000h
	DB	000h , 000h , 000h , 008h
	DB	000h , 008h , 002h , 008h


DESDATA		ENDS





DESCODE		SEGMENT PARA USE16 PUBLIC 'CODE'

	ASSUME	CS:DESCODE , DS:DESDATA


InitDesKeyTable	PROC FAR 	

		PUBLIC	InitDesKeyTable

;		ARG	keytableptr:DWORD , keyptr:DWORD

		push	bp
		mov	bp , sp

		push	si 
		push	di
		push	ds

		mov	ax , DESDATA
		mov	ds , ax

		les	si , dword ptr ss:[ bp + STACKBASE + 4 ]  ; keyptr

		xor	bh , bh
		mov	bl , byte ptr es:[ si ]
		shl	bx , 2
		mov	eax , dword ptr PC1TABLEFT[ bx ]
		mov	edx , dword ptr PC1TABRIGHT[ bx ]
I = 1
	REPT 7
		xor	bh , bh
		mov	bl , byte ptr es:[ si + I ]
		shr	edx , 1
		shr	eax , 1
		shl	bx , 2
		xor	eax , dword ptr PC1TABLEFT[ bx ]
		xor	edx , dword ptr PC1TABRIGHT[ bx ]
I = I + 1
	ENDM	

		and	al , 0F0h
		shl	dl , 4



		mov	ecx , dword ptr [ KEYSHIFTFLAG ]


		ASSUME	DS:NOTHING

		lds	bx , dword ptr ss:[ bp + STACKBASE ]  ; keytableptr

STARTINITKEYTABLE :		

;		ROLKEY

		rol	eax , 1
		add	al , 00Fh
		and	al , 0F0h
		rol	edx , 1
		add	dl , 00Fh
		and	dl , 0F0h

		shl	ecx , 1
		jnc	short loc1

		rol	eax , 1
		add	al , 00Fh
		and	al , 0F0h
		rol	edx , 1
		add	dl , 00Fh
		and	dl , 0F0h


loc1 :

; KEY 0	
		bt	eax , (	32 -	14	)
		rcl	si , 1
		bt	ax , (	32 -	17	)
		rcl	si , 1
		bt	eax , (	32 -	11	)
		rcl	si , 1
		bt	ax , (	32 -	24	)
		rcl	si , 1
		bt	eax , (	32 -	 1	)
		rcl	si , 1
		bt	eax , (	32 -	 5 	)
		rcl	si , 1
		shl	si , 2

; KEY1
		bt	eax , (	32 -	 3	)
		rcl	di , 1
		bt	ax , (	32 -	28	)
		rcl	di , 1
		bt	eax , (	32 -	15	)
		rcl	di , 1
		bt	eax , (	32 -	 6	)
		rcl	di , 1
		bt	ax , (	32 -	21	)
		rcl	di , 1
		bt	eax , (	32 -	10	)
		rcl	di , 1
		shl	di , 2
; KEY2
		bt	ax , (	32 -	23	)
		rcl	si , 1
		bt	ax , (	32 -	19	)
		rcl	si , 1
		bt	eax , (	32 -	12	)
		rcl	si , 1
		bt	eax , (	32 -	 4	)
		rcl	si , 1
		bt	ax , (	32 -	26	)
		rcl	si , 1
		bt	eax , (	32 -	 8 	)
		rcl	si , 1
		shl	si , 2

; KEY3
		bt	eax , (	32 -	16	)
		rcl	di , 1
		bt	eax , (	32 -	 7	)
		rcl	di , 1
		bt	ax , (	32 -	27	)
		rcl	di , 1
		bt	ax , (	32 -	20	)
		rcl	di , 1
		bt	eax , (	32 -	13	)
		rcl	di , 1
		bt	eax , (	32 -	 2	)
		rcl	di , 1
		shl	di , 2

; KEY4
		bt	edx , (	60 -	41	)
		rcl	esi , 1
		bt	dx , (	60 -	52	)
		rcl	esi , 1
		bt	edx , (	60 -	31	)
		rcl	esi , 1
		bt	edx , (	60 -	37	)
		rcl	esi , 1
		bt	dx , (	60 -	47	)
		rcl	esi , 1
		bt	dx , (	60 -	55 	)
		rcl	esi , 1
		shl	esi , 2
; KEY5
		bt	edx , (	60 -	30	)
		rcl	edi , 1
		bt	edx , (	60 -	40	)
		rcl	edi , 1
		bt	dx , (	60 -	51	)
		rcl	edi , 1
		bt	dx , (	60 -	45	)
		rcl	edi , 1
		bt	edx , (	60 -	33	)
		rcl	edi , 1
		bt	dx , (	60 -	48 	)
		rcl	edi , 1
		shl	edi , 2
; KEY6
		bt	edx , (	60 -	44	)
		rcl	esi , 1
		bt	dx , (	60 -	49	)
		rcl	esi , 1
		bt	edx , (	60 -	39	)
		rcl	esi , 1
		bt	dx , (	60 -	56	)
		rcl	esi , 1
		bt	edx , (	60 -	34	)
		rcl	esi , 1
		bt	dx , (	60 -	53 	)
		rcl	esi , 1
		shl	esi , 2
; KEY7
		bt	dx , (	60 -	46	)
		rcl	edi , 1
		bt	edx , (	60 -	42	)
		rcl	edi , 1
		bt	dx , (	60 -	50	)
		rcl	edi , 1
		bt	edx , (	60 -	36	)
		rcl	edi , 1
		bt	edx , (	60 -	29	)
		rcl	edi , 1
		bt	edx , (	60 -	32 	)
		rcl	edi , 1
		shl	edi , 2

		mov	dword ptr ds:[ bx ] , esi 	; KEY6420
		mov	dword ptr ds:[ bx + 4 ] , edi 	; KEY7531

		jcxz	short ENDINITKEYTABLE
		add	bx , 8
		jmp	near ptr STARTINITKEYTABLE

ENDINITKEYTABLE :

		pop	ds
		pop	di
		pop	si

		pop	bp

		ret
InitDesKeyTable	ENDP

DESCODE		ENDS





DESCODE		SEGMENT PARA USE16 PUBLIC 'CODE'

	ASSUME	CS:DESCODE , DS:DESDATA

EncryptBlock 	PROC FAR

	PUBLIC	EncryptBlock

;	ARG	outputblockptr:DWORD , inputblockptr:DWORD , keytableptr:DWORD

	push	bp
	mov	bp , sp

	push	si
	push	di
	push	ds

	mov	ax , DESDATA
	mov	ds , ax

	les	si , dword ptr ss:[ bp + STACKBASE + 4 ]   ; inputblockptr

;---------------------------------------------------------------------
;		IP tranfer bits
;---------------------------------------------------------------------

		IPTRANSFER eax , edx

;-------------------------------------------------------------------
;			MAIN LOOP
;-------------------------------------------------------------------

		les	si , dword ptr ss:[ bp + STACKBASE + 8 ] ; keytableptr
		xor	bh , bh


;
;	eax - left dword , edx - right dword 
;
		DES_STEP 	eax , edx , 0
		DES_STEP 	edx , eax , 1
		DES_STEP 	eax , edx , 2
		DES_STEP 	edx , eax , 3
		DES_STEP 	eax , edx , 4
		DES_STEP 	edx , eax , 5
		DES_STEP 	eax , edx , 6
		DES_STEP 	edx , eax , 7
		DES_STEP 	eax , edx , 8
		DES_STEP 	edx , eax , 9
		DES_STEP 	eax , edx , 10
		DES_STEP 	edx , eax , 11
		DES_STEP 	eax , edx , 12
		DES_STEP 	edx , eax , 13
		DES_STEP 	eax , edx , 14
		DES_STEP 	edx , eax , 15

;-------------------------------------------------------------------
;			END MAIN LOOP
;-------------------------------------------------------------------

;
;	befor main loop :
;
;		eax - left dword , edx - right dword 
;
;	befor exchange left and rigth dword :
;
;		edx - left dword , eax - right dword
;


;---------------------------------------------------------------------
;		RIP transfer bits
;---------------------------------------------------------------------

		RIPTRANSFER

	ASSUME	DS:NOTHING

	lds	si , dword ptr ss:[ bp + STACKBASE ]  ; outputblockptr

	mov	dword ptr ds:[si] , ecx
	mov	dword ptr ds:[si+4] , edi

	pop	ds
	pop	di
	pop	si

	pop	bp

	ret

EncryptBlock	ENDP

DESCODE		ENDS





DESCODE		SEGMENT PARA USE16 PUBLIC 'CODE'

	ASSUME	CS:DESCODE , DS:DESDATA

DecryptBlock 	PROC FAR	

	PUBLIC	DecryptBlock

;	ARG	outputblockptr:DWORD , inputblockptr:DWORD , keytableptr:DWORD

	push	bp
	mov	bp , sp

	push	si
	push	di
	push	ds

	mov	ax , DESDATA
	mov	ds , ax

	les	si , dword ptr ss:[ bp + STACKBASE + 4 ] ; inputblockptr


;---------------------------------------------------------------------
;		IP tranfer bits
;---------------------------------------------------------------------

		IPTRANSFER eax , edx

;-------------------------------------------------------------------
;			MAIN LOOP
;-------------------------------------------------------------------

		les	si , dword ptr ss:[ bp + STACKBASE + 8 ] ; keytableptr
		xor	bh , bh


;
;	eax - left dword , edx - right dword 
;
		DES_STEP 	eax , edx , 15
		DES_STEP 	edx , eax , 14
		DES_STEP 	eax , edx , 13
		DES_STEP 	edx , eax , 12
		DES_STEP 	eax , edx , 11
		DES_STEP 	edx , eax , 10
		DES_STEP 	eax , edx , 9
		DES_STEP 	edx , eax , 8
		DES_STEP 	eax , edx , 7
		DES_STEP 	edx , eax , 6
		DES_STEP 	eax , edx , 5
		DES_STEP 	edx , eax , 4
		DES_STEP 	eax , edx , 3
		DES_STEP 	edx , eax , 2
		DES_STEP 	eax , edx , 1
		DES_STEP 	edx , eax , 0

;-------------------------------------------------------------------
;			END MAIN LOOP
;-------------------------------------------------------------------

;
;	befor main loop :
;
;		eax - left dword , edx - right dword 
;
;	befor exchange left and rigth dword :
;
;		edx - left dword , eax - right dword
;


;---------------------------------------------------------------------
;		RIP transfer bits
;---------------------------------------------------------------------

		RIPTRANSFER

	ASSUME	DS:NOTHING

	lds	si , dword ptr ss:[ bp + STACKBASE ] ; outputblockptr

	mov	dword ptr ds:[si] , ecx
	mov	dword ptr ds:[si+4] , edi


	pop	ds
	pop	di
	pop	si

	pop	bp

	ret

DecryptBlock	ENDP


DESCODE		ENDS


	END 
