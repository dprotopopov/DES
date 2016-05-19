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

////////////////////////////////////////////////////////////////////
// SWIFT  EXTENSION IMPLEMENTATION
// File swiftext.cpp
// Copyright © 1996, Asset Information Management
// Copyright © 1997, Asset Information Management
// Programmer: Dmitry Protopopov
//////////////////////////////////////////////////////////////////////////

const char SOF[] = ":";
const char EOL[] = "\r\n";
const char SOT[] = "{4:\r\n";
const char EOT[] = "-}";

////////////////////////////////////////////////////////////////////
//  Text formats

const char BIC[] = 
FIX6( LETTER )  FIX5( LETTERDIGIT )  "%n\0"  
FIX6( LETTER )  FIX2( LETTERDIGIT )  "%n\0";

const char LT_ADDRESS[] = 
FIX6( LETTER )  FIX6( LETTERDIGIT )  "%n\0";

const char MESSAGE_TYPE[] = 
FIX3( DIGIT ) "%n\0";

const char SESSION_NUMBER[] = 
FIX4( DIGIT ) "%n\0";

const char SEQUENCE_NUMBER[] = 
FIX6( DIGIT ) "%n\0";

const char REFERENCE[] = 
"%*16" EBCDIC_TEXTONLY  "%n\0";

const char CURRENCY_ISO[] = 
FIX3( LETTER ) "%n\0";

const char ISIN[] =
FIX12( LETTERDIGIT ) "%n\0";

const char ACCOUNT_NUMBER[] =
"%*34" EBCDIC_TEXTONLY "%n\0";

////////////////////////////////////////////////////////////////////////////////

const char DIGIT1[] =
"%*1" DIGIT "%n\0";

const char DIGIT2[] =
FIX2( DIGIT ) "%n\0";

const char DIGIT3[] =
FIX3( DIGIT ) "%n\0";

const char DIGIT4[] =
FIX4( DIGIT ) "%n\0";

const char DIGIT6[] =
FIX6( DIGIT ) "%n\0";

const char VARDIGIT2[] =
"%*2" DIGIT "%n\0";

const char VARDIGIT3[] =
"%*3" DIGIT "%n\0";

const char VARDIGIT4[] =
"%*4" DIGIT "%n\0";

const char VARDIGIT5[] =
"%*5" DIGIT "%n\0";

/////////////////////////////////////////////////////////////////////////////////

const char LETTER1[] =
"%*1" LETTER "%n\0";

const char LETTER2[] =
FIX2( LETTER ) "%n\0";

const char LETTER3[] =
FIX3( LETTER ) "%n\0";

const char LETTER4[] =
FIX4( LETTER ) "%n\0";

const char LETTER5[] =
FIX5( LETTER ) "%n\0";

const char LETTER7[] =
FIX7( LETTER ) "%n\0";

const char LETTER8[] =
FIX8( LETTER ) "%n\0";

const char LETTER9[] =
FIX9( LETTER ) "%n\0";

const char LETTER16[] =
FIX16( LETTER ) "%n\0";

///////////////////////////////////////////////////////////////////////////

const char LETTERDIGIT1[] =
"%*1" LETTERDIGIT "%n\0";

const char LETTERDIGIT2[] =
FIX2( LETTERDIGIT ) "%n\0";

const char LETTERDIGIT3[] =
FIX3( LETTERDIGIT ) "%n\0";

const char LETTERDIGIT5[] =
FIX5( LETTERDIGIT ) "%n\0";

const char LETTERDIGIT7[] =
FIX7( LETTERDIGIT ) "%n\0";

const char LETTERDIGIT8[] =
FIX8( LETTERDIGIT ) "%n\0";

const char LETTERDIGIT9[] =
FIX9( LETTERDIGIT ) "%n\0";

const char LETTERDIGIT16[] =
FIX16( LETTERDIGIT ) "%n\0";

//////////////////////////////////////////////////////////////

const char VARLETTER2[] =
"%*2" LETTER "%n\0";

const char VARLETTER3[] =
"%*3" LETTER "%n\0";

const char VARLETTER5[] =
"%*5" LETTER "%n\0";

const char VARLETTER7[] =
"%*7" LETTER "%n\0";

const char VARLETTER8[] =
"%*8" LETTER "%n\0";

const char VARLETTER9[] =
"%*9" LETTER "%n\0";

const char VARLETTER16[] =
"%*16" LETTER "%n\0";

////////////////////////////////////////////////////////////////////////////

const char VARLETTERDIGIT8[] =
"%*8" LETTERDIGIT "%n\0";

////////////////////////////////////////////////////////////////////////////

const char VARTEXT5[] = 
 "%*5"  EBCDIC_TEXTONLY "%n\0";

const char VARTEXT12[] = 
 "%*12"  EBCDIC_TEXTONLY "%n\0";

const char VARTEXT16[] = 
 "%*16"  EBCDIC_TEXTONLY "%n\0";

const char VARTEXT30[] = 
 "%*30"  EBCDIC_TEXTONLY "%n\0";

const char VARTEXT35[] = 
 "%*35"  EBCDIC_TEXTONLY "%n\0";

////////////////////////////////////////////////////////////////////
//  Multitext formats

const char SOForEOT[] = "%*1[\r]%*1[\n]%*1[-:]%n\0";
const char EOAI[] = "%*1[\r]%*1[\n]%*1[^/]%n\0%*1[\r]%*1[\n]%*1[/]%*1[^/]%n\0";

const char NARRATIVE_LINE35[] = 
"%*1" EBCDIC_FIRSTLETTER "%*34" EBCDIC_TEXTONLY  "%n\0"
"%*1" EBCDIC_FIRSTLETTER "%n\0";

const char NARRATIVE_LINE29[] = 
"%*1" EBCDIC_FIRSTLETTER "%*28" EBCDIC_TEXTONLY  "%n\0"
"%*1" EBCDIC_FIRSTLETTER "%n\0";

const char NARRATIVE_TEXT78[] = 
"%*1" EBCDIC_FIRSTLETTER "%*77"  EBCDIC_TEXTONLY "%n\0"
"%*1" EBCDIC_FIRSTLETTER "%n\0"
"%n\0";

const char NARRATIVE_TEXT65[] = 
"%*1" EBCDIC_FIRSTLETTER "%*64"  EBCDIC_TEXTONLY "%n\0"
"%*1" EBCDIC_FIRSTLETTER "%n\0"
"%n\0";

const char NARRATIVE_TEXT50[] = 
"%*1" EBCDIC_FIRSTLETTER "%*49"  EBCDIC_TEXTONLY "%n\0"
"%*1" EBCDIC_FIRSTLETTER "%n\0"
"%n\0";

const char NARRATIVE_TEXT35[] = 
"%*1" EBCDIC_FIRSTLETTER "%*34" EBCDIC_TEXTONLY  "%n\0"
"%*1" EBCDIC_FIRSTLETTER "%n\0"
"%n\0";

const char ADDITIONAL_TEXT33[] = 
"%*33"  EBCDIC_TEXTONLY "%n\0"
"%n\0";

const char COPY_TEXT[] =
"%*1"   "[:a-zA-Z0-9/?().,'+{} ]"   "%*"   "[-:a-zA-Z0-9/?().,'+{} ]"  "%n\0"
"%*1"   "[:a-zA-Z0-9/?().,'+{} ]"  "%n\0"
"%n\0";

////////////////////////////////////////////////////////////
//  Datetime formats

const char YYYYMMDD[] = "%Y%m%d";
const char YYMMDD[] = "%y%m%d";
const char YYMMDDHHMM[] = "%y%m%d%H%M";
const char HHMMYYMMDD[] = "%H%M%y%m%d";
const char HHMMSS[] = "%H%M%S";
const char HHMM[] = "%H%M";

