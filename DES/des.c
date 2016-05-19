/*
 *
 *	DES.C
 *
 *	Data Encryption Standard
 *	Copyright (C) 2001, Dmitry Protopopov 70952828511@mail.ru
 *
 */

#include <io.h>
#include <stdio.h>
#include <string.h>

#include "des.h"
#include "desx.h"
#include "desmem.h"
#include "desfile.h"

char *screen[] =
{
"",
"                       **********      ************      ********",
"                      ****    ****    ****    ****    ****    ****",
"                     ****    ****    ****            ****",
"                    ****    ****    ****            ****",
"                   ****    ****    ********          ********",
"                  ****    ****    ****                    ****",
"                 ****    ****    ****                    ****",
"                ****    ****    ****    ****    ****    ****",
"               **********      ************      ********",
"",
"                             Data Encryption Standard",
"                               Software version 1.0",
"                     Copyright (c) 1994,2001, Dmitry Protopopov",
"                            E-mail:70952828511@mail.ru",
""
};
char *help[] =
{
"",
"Usage: DES command password plainfile cipherfile",
"Examples: DES e GOODTIME plain.txt cipher.dat",
"Commands:",
"	e         Encrypt file",
"	d         Decrypt file",
""
};

int main(int argn, char **argv)
{
	int i;
	long count;
	DESKEY key;

	for (i = 0; i < sizeof(screen)/sizeof(char*); i++) puts(screen[i]);

	if (argn!=5) goto help;
	if (strlen(argv[1])!=1) goto help;
	if (!strchr("eEdD",argv[1][0])) goto help;

	des_atok(key,argv[2]);

	if (strchr("eE",argv[1][0]))
	{
		count = des_fileencrypt(key,argv[3],argv[4]);
		printf("Total %ld bytes encrypted\n",count);
	}
	if (strchr("dD",argv[1][0]))
	{
		count = des_filedecrypt(key,argv[3],argv[4]);
		printf("Total %ld bytes decrypted\n",count);
	}
	return 0;

help:

	for (i = 0; i < sizeof(help)/sizeof(char*); i++) puts(help[i]);
	
	return 0;
}