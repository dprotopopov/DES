//////////////////////////////////
// System level dependencies

#include <windows.h>

//////////////////////////////////
// ANSI level dependencies

#include <stdio.h>

//////////////////////////////////
// Application level dependencies

#include "prc.h"
#include "swiftext.h"
#include "uneiext.h"

///////////////////////////////////////////////////////////
// UNEXIM EXTENSION IMPLEMENTATION
// File uneiext.cpp
// Copyright © 1996 Asset Information Management
// Programmer: Dmitry Protopopov
///////////////////////////////////////////////////////////

const char UEOT[] = "-}\r\n";

const char DDMMYYYY[] = 
"%d%m%Y";

const char CHAR3[] = 
FIX3 ( CHAR ) "%n\0";

const char VARCHAR16[] =
"%*16" CHAR "%n\0";

const char VARCHAR25[] =
"%*25" CHAR "%n\0";

const char VARCHAR34[] =
"%*34" CHAR "%n\0";

const char VARCHAR35[] =
"%*35" CHAR "%n\0";

const char VARCHARLINE35[] =
"%*35" CHAR "%n\0"
"%n\0";

//////////////////////////////////////////////////////////
