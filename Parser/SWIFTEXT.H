#ifndef __SWIFTEXT_H
#define __SWIFTEXT_H

//////////////////////////////////////////////////////////
// SWIFT EXTENSION HEADER
// File swiftext.h
// Copyright © 1996, Asset Information Management
// Copyright © 1997, Asset Information Management
// Programmer: Dmitry Protopopov
//////////////////////////////////////////////////////////////////////////

#define O(class,srvr) CUSTOM1(class,OS_OPTIONAL,srvr)
#define M(class,srvr) CUSTOM1(class,OS_MANTADORY,srvr) 

////////////////////////////////////////////////////////////
//  Datetime formats

extern const char YYYYMMDD[];
extern const char YYMMDD[];
extern const char YYMMDDHHMM[];
extern const char HHMMYYMMDD[];
extern const char HHMMSS[];
extern const char HHMM[];

////////////////////////////////////////////////////////////
// Text formats

#define EBCDIC   "[-a-zA-Z0-9/?:().,'+{}\r\n ]"
#define EBCDIC_TEXTONLY   "[-a-zA-Z0-9/?:().,'+{} ]"
#define EBCDIC_FIRSTLETTER   "[a-zA-Z0-9/?().,'+{} ]"
#define EDIFACT_A  "[-A-Z0-9.,()/='+:?!\"%&*<>; ]"

#define LETTER  "[A-Z]"
#define DIGIT  "[0-9]"
#define LETTERDIGIT "[A-Z0-9]"
#define HEXDECIMAL "[0-9A-F]"

#define FIX1(format) "%*1"  format 
#define FIX2(format) FIX1(format) FIX1(format)
#define FIX3(format) FIX1(format) FIX2(format)
#define FIX4(format) FIX2(format) FIX2(format)
#define FIX5(format) FIX2(format) FIX3(format)
#define FIX6(format) FIX3(format) FIX3(format)
#define FIX7(format) FIX3(format) FIX4(format)
#define FIX8(format) FIX4(format) FIX3(format)
#define FIX9(format) FIX4(format) FIX5(format)
#define FIX12(format) FIX6(format) FIX6(format)
#define FIX16(format) FIX8(format) FIX8(format)

extern const char SOF[];
extern const char EOL[];
extern const char SOT[];
extern const char EOT[];

////////////////////////////////////////////////////////////////////
//  Text formats

extern const char BIC[];
extern const char LT_ADDRESS[];
extern const char MESSAGE_TYPE[];
extern const char SESSION_NUMBER[];
extern const char SEQUENCE_NUMBER[];
extern const char REFERENCE[];
extern const char CURRENCY_ISO[];
extern const char ACCOUNT_NUMBER[];
extern const char ISIN[];
extern const char DIGIT1[];
extern const char DIGIT2[];
extern const char DIGIT3[];
extern const char DIGIT4[];
extern const char DIGIT6[];
extern const char VARDIGIT2[];
extern const char VARDIGIT3[];
extern const char VARDIGIT4[];
extern const char VARDIGIT5[];
extern const char LETTER1[];
extern const char LETTER2[];
extern const char LETTER3[];
extern const char LETTER4[];
extern const char LETTER5[];
extern const char LETTER7[];
extern const char LETTER8[];
extern const char LETTER9[];
extern const char LETTER16[];
extern const char LETTERDIGIT1[];
extern const char LETTERDIGIT2[];
extern const char LETTERDIGIT3[];
extern const char LETTERDIGIT5[];
extern const char LETTERDIGIT7[];
extern const char LETTERDIGIT8[];
extern const char LETTERDIGIT9[];
extern const char LETTERDIGIT16[];
extern const char VARLETTER2[];
extern const char VARLETTER3[];
extern const char VARLETTER5[];
extern const char VARLETTER7[];
extern const char VARLETTER8[];
extern const char VARLETTER9[];
extern const char VARLETTER16[];
extern const char VARLETTERDIGIT8[];

extern const char VARTEXT5[];
extern const char VARTEXT12[];
extern const char VARTEXT16[];
extern const char VARTEXT30[];
extern const char VARTEXT35[];

////////////////////////////////////////////////////////////////////
//  Multitext formats

extern const char SOForEOT[];
extern const char EOAI[];
extern const char NARRATIVE_LINE35[];
extern const char NARRATIVE_LINE29[];
extern const char NARRATIVE_TEXT78[];
extern const char NARRATIVE_TEXT65[];
extern const char NARRATIVE_TEXT50[];
extern const char NARRATIVE_TEXT35[];
extern const char ADDITIONAL_TEXT33[];
extern const char COPY_TEXT[];

/////////////////////////////////////////////////////////////////////
// Number formats

#define NUMBER7  7
#define NUMBER12 12
#define NUMBER13 13
#define NUMBER15 15
#define NUMBER16 16
#define NUMBER17 17

///////////////////////////////////////////////////////////////////////
class PLtAddress : public PObject
{
protected:
char * m_pszAttribute;
char m_strText[12];

public:
PLtAddress();
~ PLtAddress();

public:
DECLARE_METHODS()
DECLARE_LENGTH()
//DECLARE_VALIDATE()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_CREATE()
DECLARE_PROGRAM()

protected:
BOOL IsValid();
};

#define LTADDRESS(style, column)  CUSTOM1(PLtAddress, style, column)

//////////////////////////////////////////////////////////////////////////////////////
class PBicAddress : public PObject
{
protected:
char * m_pszAttribute;
char m_strText[12];
UINT m_nLength;

public:
PBicAddress();
~ PBicAddress();

public:
DECLARE_CREATE()
DECLARE_METHODS()
DECLARE_LENGTH()
//DECLARE_VALIDATE()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()

protected:
BOOL IsValid();
};

#define BICADDRESS(style, column)  CUSTOM1(PBicAddress, style, column)

//////////////////////////////////////////////////////////////////////////////////////
class PNumber : public PObject
{
protected:
char * m_pszAttribute;
char m_strText[32];
UINT m_nLength;
UINT m_nMaxLength;

public:
PNumber();
~PNumber();

public:
DECLARE_CREATE()
DECLARE_METHODS()
DECLARE_LENGTH()
//DECLARE_VALIDATE()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
};

#define NUMBER(style, column, maxsize)  CUSTOM2(PNumber, style,  column,  maxsize)

//////////////////////////////////////////////////////////////////////////////////////
class PNegative : public PObject
{
protected:
char * m_pszAttribute;
char m_strText[32];
UINT m_nLength;
UINT m_nMaxLength;

public:
PNegative();
~PNegative();

public:
DECLARE_CREATE()
DECLARE_METHODS()
DECLARE_LENGTH()
//DECLARE_VALIDATE()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
};

#define NEGATIVE(style, column, maxsize)  CUSTOM2(PNegative,  style, column,  maxsize)

/////////////////////////////////////////////////////////////////////////////////////////
class FIELD18A : public PObject
{
protected:
UINT m_nCount;

public:
FIELD18A();
~ FIELD18A();

public:
DECLARE_CREATE()
DECLARE_METHODS()
DECLARE_LENGTH()
//DECLARE_VALIDATE()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
};

/////////////////////////////////////////////////////////////////////////////////

#endif // __SWIFTEXT_H
