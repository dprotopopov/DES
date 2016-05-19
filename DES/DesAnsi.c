/*
 *
 *	DESANSI.C
 *
 *	Defined functions profile
 *
 *	See AS 2805.5 for more detail
 *
 *	Copyright (C) 1994-2001, Dmitry Protopopov 70952828511@mail.ru
 *
 */

#include "des.h"

unsigned int SHIFT[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

unsigned long PFTAB0[64] =
{
	0x00808200ul,0x00000000ul,0x00008000ul,0x00808202ul,0x00808002ul,0x00008202ul,0x00000002ul,0x00008000ul,
	0x00000200ul,0x00808200ul,0x00808202ul,0x00000200ul,0x00800202ul,0x00808002ul,0x00800000ul,0x00000002ul,
	0x00000202ul,0x00800200ul,0x00800200ul,0x00008200ul,0x00008200ul,0x00808000ul,0x00808000ul,0x00800202ul,
	0x00008002ul,0x00800002ul,0x00800002ul,0x00008002ul,0x00000000ul,0x00000202ul,0x00008202ul,0x00800000ul,
	0x00008000ul,0x00808202ul,0x00000002ul,0x00808000ul,0x00808200ul,0x00800000ul,0x00800000ul,0x00000200ul,
	0x00808002ul,0x00008000ul,0x00008200ul,0x00800002ul,0x00000200ul,0x00000002ul,0x00800202ul,0x00008202ul,
	0x00808202ul,0x00008002ul,0x00808000ul,0x00800202ul,0x00800002ul,0x00000202ul,0x00008202ul,0x00808200ul,
	0x00000202ul,0x00800200ul,0x00800200ul,0x00000000ul,0x00008002ul,0x00008200ul,0x00000000ul,0x00808002ul
};
unsigned long PFTAB1[64] =
{
	0x40084010ul,0x40004000ul,0x00004000ul,0x00084010ul,0x00080000ul,0x00000010ul,0x40080010ul,0x40004010ul,
	0x40000010ul,0x40084010ul,0x40084000ul,0x40000000ul,0x40004000ul,0x00080000ul,0x00000010ul,0x40080010ul,
	0x00084000ul,0x00080010ul,0x40004010ul,0x00000000ul,0x40000000ul,0x00004000ul,0x00084010ul,0x40080000ul,
	0x00080010ul,0x40000010ul,0x00000000ul,0x00084000ul,0x00004010ul,0x40084000ul,0x40080000ul,0x00004010ul,
	0x00000000ul,0x00084010ul,0x40080010ul,0x00080000ul,0x40004010ul,0x40080000ul,0x40084000ul,0x00004000ul,
	0x40080000ul,0x40004000ul,0x00000010ul,0x40084010ul,0x00084010ul,0x00000010ul,0x00004000ul,0x40000000ul,
	0x00004010ul,0x40084000ul,0x00080000ul,0x40000010ul,0x00080010ul,0x40004010ul,0x40000010ul,0x00080010ul,
	0x00084000ul,0x00000000ul,0x40004000ul,0x00004010ul,0x00080010ul,0x40080010ul,0x40084010ul,0x00084000ul
};
unsigned long PFTAB2[64] =
{
	0x00000104ul,0x04010100ul,0x00000000ul,0x04010004ul,0x04000100ul,0x00000000ul,0x00010104ul,0x04000100ul,
	0x00010004ul,0x04000004ul,0x04000004ul,0x00010000ul,0x04010104ul,0x00010004ul,0x04010000ul,0x00000104ul,
	0x04000000ul,0x00000004ul,0x04010100ul,0x00000100ul,0x00010100ul,0x04010000ul,0x04010004ul,0x00010104ul,
	0x04000104ul,0x00010100ul,0x00010000ul,0x04000104ul,0x00000004ul,0x04010104ul,0x00000100ul,0x04000000ul,
	0x04010100ul,0x04000000ul,0x00010004ul,0x00000104ul,0x00010000ul,0x04010100ul,0x04000100ul,0x00000000ul,
	0x00000100ul,0x00010004ul,0x04010104ul,0x04000100ul,0x04000004ul,0x00000100ul,0x00000000ul,0x04010004ul,
	0x04000104ul,0x00010000ul,0x04000000ul,0x04010104ul,0x00000004ul,0x00010104ul,0x00010100ul,0x04000004ul,
	0x04010000ul,0x04000104ul,0x00000104ul,0x04010000ul,0x00010104ul,0x00000004ul,0x04010004ul,0x00010100ul
};
unsigned long PFTAB3[64] =
{
	0x80401000ul,0x80001040ul,0x80001040ul,0x00000040ul,0x00401040ul,0x80400040ul,0x80400000ul,0x80001000ul,
	0x00000000ul,0x00401000ul,0x00401000ul,0x80401040ul,0x80000040ul,0x00000000ul,0x00400040ul,0x80400000ul,
	0x80000000ul,0x00001000ul,0x00400000ul,0x80401000ul,0x00000040ul,0x00400000ul,0x80001000ul,0x00001040ul,
	0x80400040ul,0x80000000ul,0x00001040ul,0x00400040ul,0x00001000ul,0x00401040ul,0x80401040ul,0x80000040ul,
	0x00400040ul,0x80400000ul,0x00401000ul,0x80401040ul,0x80000040ul,0x00000000ul,0x00000000ul,0x00401000ul,
	0x00001040ul,0x00400040ul,0x80400040ul,0x80000000ul,0x80401000ul,0x80001040ul,0x80001040ul,0x00000040ul,
	0x80401040ul,0x80000040ul,0x80000000ul,0x00001000ul,0x80400000ul,0x80001000ul,0x00401040ul,0x80400040ul,
	0x80001000ul,0x00001040ul,0x00400000ul,0x80401000ul,0x00000040ul,0x00400000ul,0x00001000ul,0x00401040ul
};
unsigned long PFTAB4[64] =
{
	0x00000080ul,0x01040080ul,0x01040000ul,0x21000080ul,0x00040000ul,0x00000080ul,0x20000000ul,0x01040000ul,
	0x20040080ul,0x00040000ul,0x01000080ul,0x20040080ul,0x21000080ul,0x21040000ul,0x00040080ul,0x20000000ul,
	0x01000000ul,0x20040000ul,0x20040000ul,0x00000000ul,0x20000080ul,0x21040080ul,0x21040080ul,0x01000080ul,
	0x21040000ul,0x20000080ul,0x00000000ul,0x21000000ul,0x01040080ul,0x01000000ul,0x21000000ul,0x00040080ul,
	0x00040000ul,0x21000080ul,0x00000080ul,0x01000000ul,0x20000000ul,0x01040000ul,0x21000080ul,0x20040080ul,
	0x01000080ul,0x20000000ul,0x21040000ul,0x01040080ul,0x20040080ul,0x00000080ul,0x01000000ul,0x21040000ul,
	0x21040080ul,0x00040080ul,0x21000000ul,0x21040080ul,0x01040000ul,0x00000000ul,0x20040000ul,0x21000000ul,
	0x00040080ul,0x01000080ul,0x20000080ul,0x00040000ul,0x00000000ul,0x20040000ul,0x01040080ul,0x20000080ul
};
unsigned long PFTAB5[64] =
{
	0x10000008ul,0x10200000ul,0x00002000ul,0x10202008ul,0x10200000ul,0x00000008ul,0x10202008ul,0x00200000ul,
	0x10002000ul,0x00202008ul,0x00200000ul,0x10000008ul,0x00200008ul,0x10002000ul,0x10000000ul,0x00002008ul,
	0x00000000ul,0x00200008ul,0x10002008ul,0x00002000ul,0x00202000ul,0x10002008ul,0x00000008ul,0x10200008ul,
	0x10200008ul,0x00000000ul,0x00202008ul,0x10202000ul,0x00002008ul,0x00202000ul,0x10202000ul,0x10000000ul,
	0x10002000ul,0x00000008ul,0x10200008ul,0x00202000ul,0x10202008ul,0x00200000ul,0x00002008ul,0x10000008ul,
	0x00200000ul,0x10002000ul,0x10000000ul,0x00002008ul,0x10000008ul,0x10202008ul,0x00202000ul,0x10200000ul,
	0x00202008ul,0x10202000ul,0x00000000ul,0x10200008ul,0x00000008ul,0x00002000ul,0x10200000ul,0x00202008ul,
	0x00002000ul,0x00200008ul,0x10002008ul,0x00000000ul,0x10202000ul,0x10000000ul,0x00200008ul,0x10002008ul
};
unsigned long PFTAB6[64] =
{
	0x00100000ul,0x02100001ul,0x02000401ul,0x00000000ul,0x00000400ul,0x02000401ul,0x00100401ul,0x02100400ul,
	0x02100401ul,0x00100000ul,0x00000000ul,0x02000001ul,0x00000001ul,0x02000000ul,0x02100001ul,0x00000401ul,
	0x02000400ul,0x00100401ul,0x00100001ul,0x02000400ul,0x02000001ul,0x02100000ul,0x02100400ul,0x00100001ul,
	0x02100000ul,0x00000400ul,0x00000401ul,0x02100401ul,0x00100400ul,0x00000001ul,0x02000000ul,0x00100400ul,
	0x02000000ul,0x00100400ul,0x00100000ul,0x02000401ul,0x02000401ul,0x02100001ul,0x02100001ul,0x00000001ul,
	0x00100001ul,0x02000000ul,0x02000400ul,0x00100000ul,0x02100400ul,0x00000401ul,0x00100401ul,0x02100400ul,
	0x00000401ul,0x02000001ul,0x02100401ul,0x02100000ul,0x00100400ul,0x00000000ul,0x00000001ul,0x02100401ul,
	0x00000000ul,0x00100401ul,0x02100000ul,0x00000400ul,0x02000001ul,0x02000400ul,0x00000400ul,0x00100001ul
};
unsigned long PFTAB7[64] =
{
	0x08000820ul,0x00000800ul,0x00020000ul,0x08020820ul,0x08000000ul,0x08000820ul,0x00000020ul,0x08000000ul,
	0x00020020ul,0x08020000ul,0x08020820ul,0x00020800ul,0x08020800ul,0x00020820ul,0x00000800ul,0x00000020ul,
	0x08020000ul,0x08000020ul,0x08000800ul,0x00000820ul,0x00020800ul,0x00020020ul,0x08020020ul,0x08020800ul,
	0x00000820ul,0x00000000ul,0x00000000ul,0x08020020ul,0x08000020ul,0x08000800ul,0x00020820ul,0x00020000ul,
	0x00020820ul,0x00020000ul,0x08020800ul,0x00000800ul,0x00000020ul,0x08020020ul,0x00000800ul,0x00020820ul,
	0x08000800ul,0x00000020ul,0x08000020ul,0x08020000ul,0x08020020ul,0x08000000ul,0x00020000ul,0x08000820ul,
	0x00000000ul,0x08020820ul,0x00020020ul,0x08000020ul,0x08020000ul,0x08000800ul,0x08000820ul,0x00000000ul,
	0x08020820ul,0x00020800ul,0x00020800ul,0x00000820ul,0x00000820ul,0x00020020ul,0x08000000ul,0x08020800ul
};
unsigned long IPTABLEFT[256] =
{
	0x00000000ul,0x00000001ul,0x00000000ul,0x00000001ul,0x00000100ul,0x00000101ul,0x00000100ul,0x00000101ul,0x00000000ul,0x00000001ul,0x00000000ul,0x00000001ul,0x00000100ul,0x00000101ul,0x00000100ul,0x00000101ul,
	0x00010000ul,0x00010001ul,0x00010000ul,0x00010001ul,0x00010100ul,0x00010101ul,0x00010100ul,0x00010101ul,0x00010000ul,0x00010001ul,0x00010000ul,0x00010001ul,0x00010100ul,0x00010101ul,0x00010100ul,0x00010101ul,
	0x00000000ul,0x00000001ul,0x00000000ul,0x00000001ul,0x00000100ul,0x00000101ul,0x00000100ul,0x00000101ul,0x00000000ul,0x00000001ul,0x00000000ul,0x00000001ul,0x00000100ul,0x00000101ul,0x00000100ul,0x00000101ul,
	0x00010000ul,0x00010001ul,0x00010000ul,0x00010001ul,0x00010100ul,0x00010101ul,0x00010100ul,0x00010101ul,0x00010000ul,0x00010001ul,0x00010000ul,0x00010001ul,0x00010100ul,0x00010101ul,0x00010100ul,0x00010101ul,
	0x01000000ul,0x01000001ul,0x01000000ul,0x01000001ul,0x01000100ul,0x01000101ul,0x01000100ul,0x01000101ul,0x01000000ul,0x01000001ul,0x01000000ul,0x01000001ul,0x01000100ul,0x01000101ul,0x01000100ul,0x01000101ul,
	0x01010000ul,0x01010001ul,0x01010000ul,0x01010001ul,0x01010100ul,0x01010101ul,0x01010100ul,0x01010101ul,0x01010000ul,0x01010001ul,0x01010000ul,0x01010001ul,0x01010100ul,0x01010101ul,0x01010100ul,0x01010101ul,
	0x01000000ul,0x01000001ul,0x01000000ul,0x01000001ul,0x01000100ul,0x01000101ul,0x01000100ul,0x01000101ul,0x01000000ul,0x01000001ul,0x01000000ul,0x01000001ul,0x01000100ul,0x01000101ul,0x01000100ul,0x01000101ul,
	0x01010000ul,0x01010001ul,0x01010000ul,0x01010001ul,0x01010100ul,0x01010101ul,0x01010100ul,0x01010101ul,0x01010000ul,0x01010001ul,0x01010000ul,0x01010001ul,0x01010100ul,0x01010101ul,0x01010100ul,0x01010101ul,
	0x00000000ul,0x00000001ul,0x00000000ul,0x00000001ul,0x00000100ul,0x00000101ul,0x00000100ul,0x00000101ul,0x00000000ul,0x00000001ul,0x00000000ul,0x00000001ul,0x00000100ul,0x00000101ul,0x00000100ul,0x00000101ul,
	0x00010000ul,0x00010001ul,0x00010000ul,0x00010001ul,0x00010100ul,0x00010101ul,0x00010100ul,0x00010101ul,0x00010000ul,0x00010001ul,0x00010000ul,0x00010001ul,0x00010100ul,0x00010101ul,0x00010100ul,0x00010101ul,
	0x00000000ul,0x00000001ul,0x00000000ul,0x00000001ul,0x00000100ul,0x00000101ul,0x00000100ul,0x00000101ul,0x00000000ul,0x00000001ul,0x00000000ul,0x00000001ul,0x00000100ul,0x00000101ul,0x00000100ul,0x00000101ul,
	0x00010000ul,0x00010001ul,0x00010000ul,0x00010001ul,0x00010100ul,0x00010101ul,0x00010100ul,0x00010101ul,0x00010000ul,0x00010001ul,0x00010000ul,0x00010001ul,0x00010100ul,0x00010101ul,0x00010100ul,0x00010101ul,
	0x01000000ul,0x01000001ul,0x01000000ul,0x01000001ul,0x01000100ul,0x01000101ul,0x01000100ul,0x01000101ul,0x01000000ul,0x01000001ul,0x01000000ul,0x01000001ul,0x01000100ul,0x01000101ul,0x01000100ul,0x01000101ul,
	0x01010000ul,0x01010001ul,0x01010000ul,0x01010001ul,0x01010100ul,0x01010101ul,0x01010100ul,0x01010101ul,0x01010000ul,0x01010001ul,0x01010000ul,0x01010001ul,0x01010100ul,0x01010101ul,0x01010100ul,0x01010101ul,
	0x01000000ul,0x01000001ul,0x01000000ul,0x01000001ul,0x01000100ul,0x01000101ul,0x01000100ul,0x01000101ul,0x01000000ul,0x01000001ul,0x01000000ul,0x01000001ul,0x01000100ul,0x01000101ul,0x01000100ul,0x01000101ul,
	0x01010000ul,0x01010001ul,0x01010000ul,0x01010001ul,0x01010100ul,0x01010101ul,0x01010100ul,0x01010101ul,0x01010000ul,0x01010001ul,0x01010000ul,0x01010001ul,0x01010100ul,0x01010101ul,0x01010100ul,0x01010101ul
};
unsigned long IPTABRIGHT[256] =
{
	0x00000000ul,0x00000000ul,0x00000001ul,0x00000001ul,0x00000000ul,0x00000000ul,0x00000001ul,0x00000001ul,0x00000100ul,0x00000100ul,0x00000101ul,0x00000101ul,0x00000100ul,0x00000100ul,0x00000101ul,0x00000101ul,
	0x00000000ul,0x00000000ul,0x00000001ul,0x00000001ul,0x00000000ul,0x00000000ul,0x00000001ul,0x00000001ul,0x00000100ul,0x00000100ul,0x00000101ul,0x00000101ul,0x00000100ul,0x00000100ul,0x00000101ul,0x00000101ul,
	0x00010000ul,0x00010000ul,0x00010001ul,0x00010001ul,0x00010000ul,0x00010000ul,0x00010001ul,0x00010001ul,0x00010100ul,0x00010100ul,0x00010101ul,0x00010101ul,0x00010100ul,0x00010100ul,0x00010101ul,0x00010101ul,
	0x00010000ul,0x00010000ul,0x00010001ul,0x00010001ul,0x00010000ul,0x00010000ul,0x00010001ul,0x00010001ul,0x00010100ul,0x00010100ul,0x00010101ul,0x00010101ul,0x00010100ul,0x00010100ul,0x00010101ul,0x00010101ul,
	0x00000000ul,0x00000000ul,0x00000001ul,0x00000001ul,0x00000000ul,0x00000000ul,0x00000001ul,0x00000001ul,0x00000100ul,0x00000100ul,0x00000101ul,0x00000101ul,0x00000100ul,0x00000100ul,0x00000101ul,0x00000101ul,
	0x00000000ul,0x00000000ul,0x00000001ul,0x00000001ul,0x00000000ul,0x00000000ul,0x00000001ul,0x00000001ul,0x00000100ul,0x00000100ul,0x00000101ul,0x00000101ul,0x00000100ul,0x00000100ul,0x00000101ul,0x00000101ul,
	0x00010000ul,0x00010000ul,0x00010001ul,0x00010001ul,0x00010000ul,0x00010000ul,0x00010001ul,0x00010001ul,0x00010100ul,0x00010100ul,0x00010101ul,0x00010101ul,0x00010100ul,0x00010100ul,0x00010101ul,0x00010101ul,
	0x00010000ul,0x00010000ul,0x00010001ul,0x00010001ul,0x00010000ul,0x00010000ul,0x00010001ul,0x00010001ul,0x00010100ul,0x00010100ul,0x00010101ul,0x00010101ul,0x00010100ul,0x00010100ul,0x00010101ul,0x00010101ul,
	0x01000000ul,0x01000000ul,0x01000001ul,0x01000001ul,0x01000000ul,0x01000000ul,0x01000001ul,0x01000001ul,0x01000100ul,0x01000100ul,0x01000101ul,0x01000101ul,0x01000100ul,0x01000100ul,0x01000101ul,0x01000101ul,
	0x01000000ul,0x01000000ul,0x01000001ul,0x01000001ul,0x01000000ul,0x01000000ul,0x01000001ul,0x01000001ul,0x01000100ul,0x01000100ul,0x01000101ul,0x01000101ul,0x01000100ul,0x01000100ul,0x01000101ul,0x01000101ul,
	0x01010000ul,0x01010000ul,0x01010001ul,0x01010001ul,0x01010000ul,0x01010000ul,0x01010001ul,0x01010001ul,0x01010100ul,0x01010100ul,0x01010101ul,0x01010101ul,0x01010100ul,0x01010100ul,0x01010101ul,0x01010101ul,
	0x01010000ul,0x01010000ul,0x01010001ul,0x01010001ul,0x01010000ul,0x01010000ul,0x01010001ul,0x01010001ul,0x01010100ul,0x01010100ul,0x01010101ul,0x01010101ul,0x01010100ul,0x01010100ul,0x01010101ul,0x01010101ul,
	0x01000000ul,0x01000000ul,0x01000001ul,0x01000001ul,0x01000000ul,0x01000000ul,0x01000001ul,0x01000001ul,0x01000100ul,0x01000100ul,0x01000101ul,0x01000101ul,0x01000100ul,0x01000100ul,0x01000101ul,0x01000101ul,
	0x01000000ul,0x01000000ul,0x01000001ul,0x01000001ul,0x01000000ul,0x01000000ul,0x01000001ul,0x01000001ul,0x01000100ul,0x01000100ul,0x01000101ul,0x01000101ul,0x01000100ul,0x01000100ul,0x01000101ul,0x01000101ul,
	0x01010000ul,0x01010000ul,0x01010001ul,0x01010001ul,0x01010000ul,0x01010000ul,0x01010001ul,0x01010001ul,0x01010100ul,0x01010100ul,0x01010101ul,0x01010101ul,0x01010100ul,0x01010100ul,0x01010101ul,0x01010101ul,
	0x01010000ul,0x01010000ul,0x01010001ul,0x01010001ul,0x01010000ul,0x01010000ul,0x01010001ul,0x01010001ul,0x01010100ul,0x01010100ul,0x01010101ul,0x01010101ul,0x01010100ul,0x01010100ul,0x01010101ul,0x01010101ul
};
unsigned long RIPTABLEFT[256] =
{
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul,
	0x00000000ul,0x01000000ul,0x00010000ul,0x01010000ul,0x00000100ul,0x01000100ul,0x00010100ul,0x01010100ul,0x00000001ul,0x01000001ul,0x00010001ul,0x01010001ul,0x00000101ul,0x01000101ul,0x00010101ul,0x01010101ul
};
unsigned long RIPTABRIGHT[256] =
{
	0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,
	0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,
	0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,
	0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,
	0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,
	0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,
	0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,
	0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,
	0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,
	0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,
	0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,
	0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,
	0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,
	0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,
	0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,
	0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul
};
unsigned long PC1TABLEFT[256] =
{
	0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,0x00000000ul,
	0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,0x00000001ul,
	0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,0x00000100ul,
	0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,0x00000101ul,
	0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,0x00010000ul,
	0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,0x00010001ul,
	0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,0x00010100ul,
	0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,0x00010101ul,
	0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,0x01000000ul,
	0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,0x01000001ul,
	0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,0x01000100ul,
	0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,0x01000101ul,
	0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,0x01010000ul,
	0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,0x01010001ul,
	0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,0x01010100ul,
	0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul,0x01010101ul
};
unsigned long PC1TABRIGHT[256] =
{
	0x00000000ul,0x00000000ul,0x01000000ul,0x01000000ul,0x00010000ul,0x00010000ul,0x01010000ul,0x01010000ul,0x00000100ul,0x00000100ul,0x01000100ul,0x01000100ul,0x00010100ul,0x00010100ul,0x01010100ul,0x01010100ul,
	0x00000001ul,0x00000001ul,0x01000001ul,0x01000001ul,0x00010001ul,0x00010001ul,0x01010001ul,0x01010001ul,0x00000101ul,0x00000101ul,0x01000101ul,0x01000101ul,0x00010101ul,0x00010101ul,0x01010101ul,0x01010101ul,
	0x00000000ul,0x00000000ul,0x01000000ul,0x01000000ul,0x00010000ul,0x00010000ul,0x01010000ul,0x01010000ul,0x00000100ul,0x00000100ul,0x01000100ul,0x01000100ul,0x00010100ul,0x00010100ul,0x01010100ul,0x01010100ul,
	0x00000001ul,0x00000001ul,0x01000001ul,0x01000001ul,0x00010001ul,0x00010001ul,0x01010001ul,0x01010001ul,0x00000101ul,0x00000101ul,0x01000101ul,0x01000101ul,0x00010101ul,0x00010101ul,0x01010101ul,0x01010101ul,
	0x00000000ul,0x00000000ul,0x01000000ul,0x01000000ul,0x00010000ul,0x00010000ul,0x01010000ul,0x01010000ul,0x00000100ul,0x00000100ul,0x01000100ul,0x01000100ul,0x00010100ul,0x00010100ul,0x01010100ul,0x01010100ul,
	0x00000001ul,0x00000001ul,0x01000001ul,0x01000001ul,0x00010001ul,0x00010001ul,0x01010001ul,0x01010001ul,0x00000101ul,0x00000101ul,0x01000101ul,0x01000101ul,0x00010101ul,0x00010101ul,0x01010101ul,0x01010101ul,
	0x00000000ul,0x00000000ul,0x01000000ul,0x01000000ul,0x00010000ul,0x00010000ul,0x01010000ul,0x01010000ul,0x00000100ul,0x00000100ul,0x01000100ul,0x01000100ul,0x00010100ul,0x00010100ul,0x01010100ul,0x01010100ul,
	0x00000001ul,0x00000001ul,0x01000001ul,0x01000001ul,0x00010001ul,0x00010001ul,0x01010001ul,0x01010001ul,0x00000101ul,0x00000101ul,0x01000101ul,0x01000101ul,0x00010101ul,0x00010101ul,0x01010101ul,0x01010101ul,
	0x00000000ul,0x00000000ul,0x01000000ul,0x01000000ul,0x00010000ul,0x00010000ul,0x01010000ul,0x01010000ul,0x00000100ul,0x00000100ul,0x01000100ul,0x01000100ul,0x00010100ul,0x00010100ul,0x01010100ul,0x01010100ul,
	0x00000001ul,0x00000001ul,0x01000001ul,0x01000001ul,0x00010001ul,0x00010001ul,0x01010001ul,0x01010001ul,0x00000101ul,0x00000101ul,0x01000101ul,0x01000101ul,0x00010101ul,0x00010101ul,0x01010101ul,0x01010101ul,
	0x00000000ul,0x00000000ul,0x01000000ul,0x01000000ul,0x00010000ul,0x00010000ul,0x01010000ul,0x01010000ul,0x00000100ul,0x00000100ul,0x01000100ul,0x01000100ul,0x00010100ul,0x00010100ul,0x01010100ul,0x01010100ul,
	0x00000001ul,0x00000001ul,0x01000001ul,0x01000001ul,0x00010001ul,0x00010001ul,0x01010001ul,0x01010001ul,0x00000101ul,0x00000101ul,0x01000101ul,0x01000101ul,0x00010101ul,0x00010101ul,0x01010101ul,0x01010101ul,
	0x00000000ul,0x00000000ul,0x01000000ul,0x01000000ul,0x00010000ul,0x00010000ul,0x01010000ul,0x01010000ul,0x00000100ul,0x00000100ul,0x01000100ul,0x01000100ul,0x00010100ul,0x00010100ul,0x01010100ul,0x01010100ul,
	0x00000001ul,0x00000001ul,0x01000001ul,0x01000001ul,0x00010001ul,0x00010001ul,0x01010001ul,0x01010001ul,0x00000101ul,0x00000101ul,0x01000101ul,0x01000101ul,0x00010101ul,0x00010101ul,0x01010101ul,0x01010101ul,
	0x00000000ul,0x00000000ul,0x01000000ul,0x01000000ul,0x00010000ul,0x00010000ul,0x01010000ul,0x01010000ul,0x00000100ul,0x00000100ul,0x01000100ul,0x01000100ul,0x00010100ul,0x00010100ul,0x01010100ul,0x01010100ul,
	0x00000001ul,0x00000001ul,0x01000001ul,0x01000001ul,0x00010001ul,0x00010001ul,0x01010001ul,0x01010001ul,0x00000101ul,0x00000101ul,0x01000101ul,0x01000101ul,0x00010101ul,0x00010101ul,0x01010101ul,0x01010101ul
};
      	 
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


unsigned char KEYTAB[8][6] =
     {{	18,15,21, 8,31,27 },      { 29, 4,17,26,11,22 },
      {	 9,13,20,28, 6,24 },      { 16,25, 5,12,19,30 },
      {	19, 8,29,23,13, 5 },      { 30,20, 9,15,27,12 },
      { 16,11,21, 4,26, 7 },      { 14,18,10,24,31,28 }};
      
#define IPTRANSFER(LEFT, RIGHT, ptr) \
	LEFT.l = IPTABLEFT[ ptr[7] ]; \
	RIGHT.l = IPTABRIGHT[ ptr[7] ]; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l += IPTABLEFT[ ptr[6] ]; \
	RIGHT.l += IPTABRIGHT[ ptr[6] ]; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l += IPTABLEFT[ ptr[5] ]; \
	RIGHT.l += IPTABRIGHT[ ptr[5] ]; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l += IPTABLEFT[ ptr[4] ]; \
	RIGHT.l += IPTABRIGHT[ ptr[4] ]; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l += IPTABLEFT[ ptr[3] ]; \
	RIGHT.l += IPTABRIGHT[ ptr[3] ]; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l += IPTABLEFT[ ptr[2] ]; \
	RIGHT.l += IPTABRIGHT[ ptr[2] ]; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l += IPTABLEFT[ ptr[1] ]; \
	RIGHT.l += IPTABRIGHT[ ptr[1] ]; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l += IPTABLEFT[ ptr[0] ]; \
	RIGHT.l += IPTABRIGHT[ ptr[0] ]; 

#define RIPTRANSFER(LEFT, RIGHT, OLDLEFT, OLDRIGHT) \
	LEFT.l = RIPTABLEFT[ OLDRIGHT.b.b0 ]; \
	RIGHT.l = RIPTABRIGHT[ OLDRIGHT.b.b0 ]; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l += RIPTABLEFT[ OLDLEFT.b.b0 ]; \
	RIGHT.l += RIPTABRIGHT[ OLDLEFT.b.b0 ]; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l += RIPTABLEFT[ OLDRIGHT.b.b1 ]; \
	RIGHT.l += RIPTABRIGHT[ OLDRIGHT.b.b1 ]; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l += RIPTABLEFT[ OLDLEFT.b.b1 ]; \
	RIGHT.l += RIPTABRIGHT[ OLDLEFT.b.b1 ]; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l += RIPTABLEFT[ OLDRIGHT.b.b2 ]; \
	RIGHT.l += RIPTABRIGHT[ OLDRIGHT.b.b2 ]; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l += RIPTABLEFT[ OLDLEFT.b.b2 ]; \
	RIGHT.l += RIPTABRIGHT[ OLDLEFT.b.b2 ]; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l += RIPTABLEFT[ OLDRIGHT.b.b3 ]; \
	RIGHT.l += RIPTABRIGHT[ OLDRIGHT.b.b3 ]; \
	LEFT.l <<= 1; \
	RIGHT.l <<= 1; \
	LEFT.l += RIPTABLEFT[ OLDLEFT.b.b3 ]; \
	RIGHT.l += RIPTABRIGHT[ OLDLEFT.b.b3 ]; 

#define ROLLONG(x) (((x)<<1)+((x&0x80000000ul)?1:0))

#define DES_STEP(LEFT, RIGHT, KeyTable, IterNo) \
	lb.l = (ROLLONG(RIGHT.l)^(KeyTable->KEY[IterNo].KEY1357))&KEYMASK; \
	LEFT.l ^= PFTAB1[lb.b.b0]^PFTAB3[lb.b.b1]^PFTAB5[lb.b.b2]^PFTAB7[lb.b.b3]; \
	lb.l = ((RIGHT.l>>3)^((RIGHT.l&7)<<29)^(KeyTable->KEY[IterNo].KEY0246))&KEYMASK; \
	LEFT.l ^= PFTAB0[lb.b.b0]^PFTAB2[lb.b.b1]^PFTAB4[lb.b.b2]^PFTAB6[lb.b.b3]; 

	
void des_init( DESKEYTABLE * keytable , unsigned char * key )
{
	int	i, c;
	LB	a, d, k;
	
	a.l = PC1TABLEFT[ key[7] ];
	d.l = PC1TABRIGHT[ key[7] ];
	a.l <<= 1;
	d.l <<= 1;
	a.l += PC1TABLEFT[ key[6] ];
	d.l += PC1TABRIGHT[ key[6] ];
	a.l <<= 1;
	d.l <<= 1;
	a.l += PC1TABLEFT[ key[5] ];
	d.l += PC1TABRIGHT[ key[5] ];
	a.l <<= 1;
	d.l <<= 1;
	a.l += PC1TABLEFT[ key[4] ];
	d.l += PC1TABRIGHT[ key[4] ];
	a.l <<= 1;
	d.l <<= 1;
	a.l += PC1TABLEFT[ key[3] ];
	d.l += PC1TABRIGHT[ key[3] ];
	a.l <<= 1;
	d.l <<= 1;
	a.l += PC1TABLEFT[ key[2] ];
	d.l += PC1TABRIGHT[ key[2] ];
	a.l <<= 1;
	d.l <<= 1;
	a.l += PC1TABLEFT[ key[1] ];
	d.l += PC1TABRIGHT[ key[1] ];
	a.l <<= 1;
	d.l <<= 1;
	a.l += PC1TABLEFT[ key[0] ];
	d.l += PC1TABRIGHT[ key[0] ];
	a.b.b3 &= 0xF0;
	d.b.b3 <<= 4;
	
	for( i = 0 ; i<16 ; i++ ) {
		for( c = SHIFT[i] ; c-- ; ) {           
			a.l = (a.l<<1) + ((a.b.b0&0x80u)?0x10:0);
			d.l = (d.l<<1) + ((d.b.b0&0x80u)?0x10:0);
		} 

#define KEYVALUE(x,s) (unsigned char)((((((((((((x>>s[0]))<<1)+((x>>s[1])&1))<<1)+((x>>s[2])&1))<<1)+((x>>s[3])&1))<<1)+((x>>s[4])&1))<<1)+((x>>s[5])&1))

		k.b.b0 = KEYVALUE( a.l, KEYTAB[0]);
		k.b.b1 = KEYVALUE( a.l, KEYTAB[2]);
		k.b.b2 = KEYVALUE( d.l, KEYTAB[4]);
		k.b.b3 = KEYVALUE( d.l, KEYTAB[6]);
		keytable->KEY[i].KEY0246 = k.l;
		
		k.b.b0 = KEYVALUE( a.l, KEYTAB[1]);
		k.b.b1 = KEYVALUE( a.l, KEYTAB[3]);
		k.b.b2 = KEYVALUE( d.l, KEYTAB[5]);
		k.b.b3 = KEYVALUE( d.l, KEYTAB[7]);
		keytable->KEY[i].KEY1357 = k.l;
	}
}

void des_encrypt	(
				DESKEYTABLE * keytable ,
				unsigned char * plaintext  ,
				unsigned char * ciphertext
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

void des_decrypt	(
				DESKEYTABLE * keytable ,
				unsigned char * plaintext  ,
				unsigned char * ciphertext
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
