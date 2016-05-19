#ifndef __POBJECT_H
#define __POBJECT_H

#include <time.h>

enum {
	GW_MOVE   = 0,
	GW_ALLOC  = 1,
	GW_PROG   = 2,
	GW_STYLE  = 3
};

class PObject;
class TInput;
class TOutput;
class TMonitor;
class TArchive;
class TMemory;
class TLog;

typedef int RETVALUE;
enum {
	PARSER_SUCCESS = 0,
	PARSER_SUCCESS_WITH_INFO = 1,
	PARSER_NO_DATA_FOUND = 2,
	PARSER_ERROR = 3
};

typedef LPARAM *(*MOVEFUNC)(LPARAM *);
typedef PObject *(*ALLOCFUNC)(TMemory *);
typedef LPARAM *(*PROGFUNC)(LPARAM *);

#define PARAM(plParam, n) plParam[4+(n)]

#define DECLARE_OBJECT()						\
	virtual char * GetObjectName();				\
	// DECLARE_OBJECT

#define IMPLEMENT_OBJECT(Class, ObjectName)		\
	char * Class::GetObjectName()				\
	{											\
		static char name[] = ObjectName;		\
		return name;							\
	}											\
	// IMPLEMENT_OBJECT

#define DECLARE_CREATE()						\
	virtual RETVALUE Create(TMemory *, LPARAM, LPARAM *, PObject *, UINT, PObject *);\
	// DECLARE_CREATE

#define DECLARE_ALLOCATE()						\
	static PObject * Allocate(TMemory *);		\
	// DECLARE_ALLOCATE

#define IMPLEMENT_ALLOCATE(Class)				\
	PObject * Class::Allocate(TMemory *pMemory)	\
	{											\
		return new Class();						\
	}											\
	// IMPLEMENT_ALLOCATE

#define DECLARE_MOVE()							\
	static LPARAM * MoveShort(LPARAM *);		\
	static LPARAM * MoveLong(LPARAM *);			\
	// DECLARE_MOVE

#define IMPLEMENT_MOVESHORT(Class, Base, n)		\
	LPARAM * Class::MoveShort(LPARAM * plParam)	\
	{											\
		return Base::MoveShort(&plParam[n]);	\
	}											\
	// IMPLEMENT_MOVESHORT

#define IMPLEMENT_MOVE(Class, Base, n)			\
	IMPLEMENT_MOVESHORT(Class, Base, n)			\
	LPARAM * Class::MoveLong(LPARAM * plParam)	\
	{											\
		return Base::MoveLong(&plParam[n]);		\
	}											\
	// IMPLEMENT_MOVE

#define DECLARE_PROGRAM()						\
	static LPARAM * Program(LPARAM *);			\
	// DECLARE_PROGRAM

#define IMPLEMENT_PROGRAM(Class, Base, n)		\
	LPARAM * Class::Program(LPARAM * plParam)	\
	{											\
		return Base::Program(&plParam[n]);		\
	}											\
	// IMPLEMENT_PROGRAM

#define DECLARE_LOAD()																				\
	virtual RETVALUE Load(TInput *, TMemory *, TLog *) ;											\
	// DECLARE_LOAD

#define DECLARE_STORE()																				\
	virtual RETVALUE Store(TOutput *, TMemory *, TLog *) ;											\
	// DECLARE_STORE

#define DECLARE_INSERT()																			\
	virtual RETVALUE Insert(TMonitor *, TMemory *, TLog *, char *, PRIMARY *, SECONDARY **, UINT) ;	\
	// DECLARE_INSERT 

#define DECLARE_SELECT()																			\
	virtual RETVALUE Select(TArchive *, TMemory *, TLog *, char *, PRIMARY *, SECONDARY **, UINT) ;	\
	// DECLARE_SELECT 

#define DECLARE_METHODS()							\
	DECLARE_LOAD()									\
	DECLARE_STORE()									\
	DECLARE_INSERT()								\
	DECLARE_SELECT()								\
	// DECLARE_METHODS 

#define DECLARE_DESTROY()							\
	virtual void Destroy(TMemory *);				\
	// DECLARE_DESTROY

#define DECLARE_REFRESH()							\
	virtual RETVALUE Refresh(TMemory *);			\
	// DECLARE_REFRESH

#define DECLARE_STARTUP()							\
	static LPARAM	StartUp[];						\
	// DECLARE_STARTUP

#define IMPLEMENT_STARTUP(Class, Domain)			\
	LPARAM Class::StartUp[] =						\
	{												\
		(LPARAM)(Class::MoveShort),					\
		(LPARAM)(Class::Allocate),					\
		(LPARAM)(Class::Program),					\
		(LPARAM)(OS_MANTADORY),						\
		(LPARAM)Domain								\
	};												\
	// IMPLEMENT_STARTUP

#define DECLARE_LENGTH()							\
	virtual UINT GetLength();						\
	// DECLARE_LENGTH()

#define DECLARE_VALIDATE()							\
	virtual RETVALUE Validate(TMemory *, TLog *);	\
	// DECLARE_VALIDATE

#define DECLARE_EVENT()								\
	virtual RETVALUE Event(UINT, LPARAM, LPARAM);	\
	// DECLARE_EVENT

#define DECLARE_OPTIONS()							\
	// DECLARE_OPTIONS 

#define IMPLEMENT_OPTIONS(Class, Base)				\
	// IMPLEMENT_OPTIONS


#define OS_NULL_VALUE		0x10000000ul
#define OS_DATA_ERROR		0x20000000ul
#define OS_MANTADORY		0x00000000ul
#define OS_OPTIONAL			0x80000000ul

#define OS_PUSH				0x00000001ul
#define OS_POP				0x00000002ul

#define TS_PUSHFORMATNUMBER 0x00000010ul
#define TS_COUPONPATCH		0x00000100ul

#define IS_SIGNED			0x00000000ul
#define IS_UNSIGNED			0x00000010ul
#define IS_NULLPATCH		0x00000020ul

#define DS_DOTSEPARETED		0x00000000ul
#define DS_COMMASEPARETED   0x00000010ul
#define DS_MINUS			0x00000020ul

#define LS_PUSHCOUNT		0x00000010ul



#define EV_FIND				1001


class PObject
{
protected:
LPARAM m_lpStyle;
PObject * m_pParent;
PObject * m_pInstance;
PObject * m_pNext;
UINT m_nLevel;

public:
PObject();
~PObject();

public:
int IsKindOf(char * pszObjectName);
PObject * GetParent();
PObject * GetNext();
PObject * GetLast();
void SetNext(PObject *);

public:
virtual RETVALUE Load(TInput *pInput, TMemory *pMemory, TLog *pLog) = 0;
virtual RETVALUE Store(TOutput *pOutput, TMemory *pMemory, TLog *pLog) = 0;
virtual RETVALUE Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) = 0;
virtual RETVALUE Select(TArchive *pArchive, TMemory *pMemory,  TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) = 0;
// DECLARE_LOAD()
// DECLARE_STORE()
// DESCARE_INSERT()
// DECLARE_SELECT()
// DECLARE_METHODS()
// Use this macro to change all methods

DECLARE_CREATE()
DECLARE_REFRESH()
DECLARE_DESTROY()
DECLARE_LENGTH()
DECLARE_VALIDATE()
DECLARE_EVENT()

public:
DECLARE_OBJECT()
// Use this macro in any derived class to change object name
// virtual char * GetObjectName()

DECLARE_MOVE()
// Any derived class has "virtual" static functions
// static LPARAM * MoveShort(LPARAM *)
// static LPARAM * MoveLong(LPARAM *)

// DECLARE_ALLOCATE()
// Any derived class has "virtual" static function
// static PObject * Allocate(TMemory *pMemory);
//

DECLARE_PROGRAM()
// Any derived class has "virtual" static function
// static LPARAM * Program (LPARAM *)

DECLARE_OPTIONS()

protected:
static LPARAM  m_lpStack[16];
static UINT m_nStack;
static void Push(LPARAM lParam);
static LPARAM Pop();

protected:
static void Preload(PObject *pObject, UINT nLevel, TLog *pLog);
static void Prestore(PObject *pObject, UINT nLevel, TLog *pLog);
static void Preselect(PObject *pObject, UINT nLevel, TLog *pLog);
static void Preinsert(PObject *pObject, UINT nLevel, TLog *pLog);
static void Postload(PObject *pObject, UINT nLevel, TLog *pLog, RETVALUE retvalue);
static void Poststore(PObject *pObject, UINT nLevel, TLog *pLog, RETVALUE retvalue);
static void Postselect(PObject *pObject, UINT nLevel, TLog *pLog, RETVALUE retvalue);
static void Postinsert(PObject *pObject, UINT nLevel, TLog *pLog, RETVALUE retvalue);

};

class PUserObject : public PObject
{
protected:
PObject * m_pObject;

public:
PUserObject();
~ PUserObject();

public:
DECLARE_CREATE()
DECLARE_REFRESH()
DECLARE_DESTROY()
DECLARE_METHODS()
DECLARE_LENGTH()
DECLARE_VALIDATE()
DECLARE_EVENT()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};

class PDummy : public PObject
{
public:
PDummy();
~PDummy() ;

public:
DECLARE_METHODS()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};

class PStatic : public PObject
{
protected:
char * m_pszText;

public:
PStatic();
~PStatic();

public:
DECLARE_CREATE()
DECLARE_METHODS()
DECLARE_LENGTH()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};

class PInteger : public PObject
{
protected:
char * m_pszAttribute;
char * m_pszPrimaryFormat;
char * m_pszSecondaryFormat;

public:
LONG m_lValue;

public:
PInteger();
~ PInteger();

public:
DECLARE_CREATE()
DECLARE_METHODS()
DECLARE_LENGTH()
DECLARE_EVENT()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};


class PText : public PObject
{
protected:
char * m_pszAttribute;
char * m_pszFormat;

public:
char  m_strText[256];
UINT m_nLength;

public:
PText();
~PText();

public:
DECLARE_CREATE()
DECLARE_METHODS()
DECLARE_LENGTH()
//DECLARE_VALIDATE()
DECLARE_EVENT()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};

class PDecimal : public PObject
{
protected:
char * m_pszAttribute;
char * m_pszFormat;

public:
char  m_strText[256];
UINT m_nLength;

public:
PDecimal();
~ PDecimal();

public:
DECLARE_CREATE()
DECLARE_METHODS()
DECLARE_LENGTH()
//DECLARE_VALIDATE()
DECLARE_EVENT()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};


class PDatetime : public PObject
{
protected:
char * m_pszAttribute;
char * m_pszFormat;

public:
struct tm  m_tm;

public:
PDatetime();
~PDatetime();

public:
DECLARE_CREATE()
DECLARE_METHODS()
DECLARE_LENGTH()
DECLARE_EVENT()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};

class PMultitext : public PObject
{
protected:
char * m_pszAttribute;
UINT m_minsize;
UINT m_maxsize;
char * m_pszLineFormat;
char * m_pszLineSeparator;
char * m_pszEndOfTextFormat;

public:
char  m_strText[32*1024];
UINT m_nLength;

public:
PMultitext();
~PMultitext();

public:
DECLARE_CREATE()
DECLARE_METHODS()
DECLARE_LENGTH()
DECLARE_EVENT()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};

class PRule : public PObject
{
protected:
char * m_pszAttribute;
char * m_pszStreamConstants;
char * m_pszSqlConstants;

public:
UINT m_nSelection;

public:
PRule();
~PRule();

public:
DECLARE_CREATE()
DECLARE_METHODS()
DECLARE_LENGTH()
DECLARE_EVENT()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};

class PContainer : public PObject
{
protected:
char * m_pszDomain;
LPARAM * m_pCommand;
PObject * m_pFirstChild;

public:
PContainer();
~PContainer();

protected:
void Attach(PObject *);
void SetFirstChild(PObject *);

public:
PObject * GetFirstChild();

public:
DECLARE_CREATE()
DECLARE_REFRESH()
DECLARE_DESTROY()
DECLARE_EVENT()

DECLARE_STORE()
DECLARE_INSERT()
DECLARE_LENGTH()
DECLARE_VALIDATE()

public:
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};

class PParallel : public PContainer
{
protected:
LPARAM * m_pProgram;

public:
PParallel();
~PParallel();

public:
DECLARE_CREATE()
DECLARE_REFRESH()
DECLARE_LOAD()
DECLARE_SELECT()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};

class PSequence : public PContainer
{
protected:
LPARAM * m_pProgram;

public:
PSequence();
~PSequence() ;

public:
DECLARE_CREATE()
DECLARE_REFRESH()
DECLARE_LOAD()
DECLARE_SELECT()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};

class PSwitch : public PContainer
{
protected:
LPARAM * m_pProgram;

public:
PSwitch();
~PSwitch() ;

public:
DECLARE_CREATE()
DECLARE_REFRESH()
DECLARE_LOAD()
DECLARE_SELECT()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};

class PLoop : public PContainer
{
protected:
UINT m_minsize;
UINT m_maxsize;
SECONDARY m_Secondary;

public:
UINT m_size;

public:
PLoop ();
~PLoop() ;

public:
DECLARE_CREATE()
DECLARE_REFRESH()
DECLARE_LOAD()
DECLARE_SELECT()
DECLARE_INSERT()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};


class PPointer : public PContainer
{
protected:
char * m_pszAttribute;
PRIMARY m_idCurrent;

public:
PPointer();
~PPointer() ;

public:
DECLARE_CREATE()
DECLARE_LOAD()
DECLARE_SELECT()
DECLARE_INSERT()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};


class PRepeat : public PPointer
{
protected:
UINT m_minsize;
UINT m_maxsize;
UINT m_size;
SECONDARY m_Secondary;

public:
PRepeat ();
~PRepeat() ;

public:
DECLARE_CREATE()
DECLARE_REFRESH()
DECLARE_LOAD()
DECLARE_SELECT()
DECLARE_INSERT()

public:
DECLARE_ALLOCATE()
DECLARE_OBJECT()
DECLARE_MOVE()
DECLARE_PROGRAM()
DECLARE_OPTIONS()
};



#endif // __POBJECT_H
