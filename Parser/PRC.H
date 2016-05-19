#ifndef __PRC_H
#define __PRC_H

#include <stdio.h>
#include <time.h>

#include "tio.h"
#include "tdb.h"
#include "tlog.h"
#include "tmemory.h"
#include "pobject.h"

#define BEGIN_DECLARE_CONTAINER(Class, Base)						\
	class Class : public Base										\
	{																\
	public:															\
	Class();														\
	~Class();														\
	virtual RETVALUE Create(TMemory *, LPARAM lpStyle=0x00000000ul,	\
	LPARAM *plParam=Class::StartUp, PObject *pParent=NULL,			\
	UINT nLevel=0, PObject * pInstance=NULL);						\
	public:															\
	DECLARE_ALLOCATE()												\
	DECLARE_OBJECT()												\
	DECLARE_MOVE()													\
	DECLARE_PROGRAM()												\
	DECLARE_STARTUP()												\
	// BEGIN_DECLARE_CONTAINER

#define END_DECLARE_CONTAINER(Class, Base)							\
	};																\
	// END_DECLARE_CONTAINER

#define DECLARE_CONTAINER(Class, Base)								\
	BEGIN_DECLARE_CONTAINER(Class, Base)							\
	END_DECLARE_CONTAINER(Class, Base)								\
	// DECLARE_CONTAINER

#define BEGIN_IMPLEMENT_CONTAINER(Class, Base, Name)				\
	IMPLEMENT_ALLOCATE(Class)										\
	IMPLEMENT_OBJECT(Class, Name)									\
	IMPLEMENT_MOVE(Class, Base, 0)									\
	IMPLEMENT_STARTUP(Class, NULL)									\
	Class::Class() : Base() {}										\
	Class::~Class() {}												\
	RETVALUE Class::Create(TMemory *pMemory, LPARAM lpStyle,		\
	LPARAM *plParam, PObject *pParent, UINT nLevel,					\
	PObject * pInstance)											\
	{ return Base::Create(pMemory, lpStyle, plParam, pParent,		\
	nLevel, this); }												\
	LPARAM * Class::Program(LPARAM * plParam)						\
	{ static LPARAM prog[] = {										\
	// BEGIN_IMPLEMENT_CONTAINER
	
#define END_IMPLEMENT_CONTAINER(Class, Base)						\
	NULL}; return prog; }											\
	// END_IMPLEMENT_CONTAINER

#define BEGIN_DECLARE_DERIVATE(Class, Base)							\
	class Class : public Base										\
	{																\
	public:															\
	Class();														\
	~Class();														\
	public:															\
	DECLARE_ALLOCATE()												\
	DECLARE_OBJECT()												\
	DECLARE_MOVE()													\
	DECLARE_STARTUP()												\
	// BEGIN_DECLARE_DERIVATE

#define END_DECLARE_DERIVATE(Class, Base)							\
	};																\
	// END_DECLARE_DERIVATE

#define BEGIN_IMPLEMENT_DERIVATE(Class, Base, Name)					\
	IMPLEMENT_ALLOCATE(Class)										\
	IMPLEMENT_OBJECT(Class, Name)									\
	IMPLEMENT_MOVE(Class, Base, 0)									\
	IMPLEMENT_STARTUP(Class, NULL)									\
	Class::Class() : Base() {}										\
	Class::~Class() {}												\
	// BEGIN_IMPLEMENT_DERIVATE
	
#define END_IMPLEMENT_DERIVATE(Class, Base)							\
	// END_IMPLEMENT_DERIVATE

#define BEGIN_DECLARE_SEQUENCE(Class) BEGIN_DECLARE_CONTAINER(Class, PSequence)
#define END_DECLARE_SEQUENCE(Class) END_DECLARE_CONTAINER(Class, PSequence)
#define DECLARE_SEQUENCE(Class) DECLARE_CONTAINER(Class, PSequence)
#define BEGIN_IMPLEMENT_SEQUENCE(Class, Name) BEGIN_IMPLEMENT_CONTAINER(Class, PSequence, Name)
#define END_IMPLEMENT_SEQUENCE(Class) END_IMPLEMENT_CONTAINER(Class, PSequence)

#define DECLARE_PARALLEL(Class) DECLARE_CONTAINER(Class, PParallel)
#define BEGIN_IMPLEMENT_PARALLEL(Class, Name) BEGIN_IMPLEMENT_CONTAINER(Class, PParallel, Name)
#define END_IMPLEMENT_PARALLEL(Class) END_IMPLEMENT_CONTAINER(Class, PParallel)

#define PMS(Class)	((LPARAM)Class::MoveShort)
#define PML(Class)	((LPARAM)Class::MoveLong)
#define PA(Class)	((LPARAM)Class::Allocate)
#define PP(Class)	((LPARAM)Class::Program)
#define _L(x)		(LPARAM)x

#define CUSTOM0(Class, Style)								PMS(Class),PA(Class),PP(Class),_L(Style),
#define CUSTOM1(Class, Style, arg1)							PMS(Class),PA(Class),PP(Class),_L(Style),_L(arg1), 
#define CUSTOM2(Class, Style, arg1, arg2)					PMS(Class),PA(Class),PP(Class),_L(Style),_L(arg1),_L(arg2), 
#define CUSTOM3(Class, Style, arg1, arg2, arg3)				PMS(Class),PA(Class),PP(Class),_L(Style),_L(arg1),_L(arg2),_L(arg3), 
#define CUSTOM4(Class, Style, arg1, arg2, arg3, arg4)		PMS(Class),PA(Class),PP(Class),_L(Style),_L(arg1),_L(arg2),_L(arg3),_L(arg4),
#define CUSTOM6(Class, Style, arg1, arg2, arg3, arg4, arg5, arg6)	PMS(Class),PA(Class),PP(Class),_L(Style),_L(arg1),_L(arg2),_L(arg3),_L(arg4),_L(arg5),_L(arg6),

#define BEGIN_CUSTOM0(Class, Style)							PML(Class),PA(Class),PP(Class),_L(Style),
#define BEGIN_CUSTOM1(Class, Style, arg1)					PML(Class),PA(Class),PP(Class),_L(Style),_L(arg1), 
#define BEGIN_CUSTOM2(Class, Style, arg1, arg2)				PML(Class),PA(Class),PP(Class),_L(Style),_L(arg1),_L(arg2),
#define BEGIN_CUSTOM3(Class, Style, arg1, arg2, arg3)		PML(Class),PA(Class),PP(Class),_L(Style),_L(arg1),_L(arg2),_L(arg3), 
#define BEGIN_CUSTOM4(Class, Style, arg1, arg2, arg3, arg4)	PML(Class),PA(Class),PP(Class),_L(Style),_L(arg1),_L(arg2),_L(arg3),_L(arg4),

#define END_CUSTOM(Class)									_L(NULL),

#define DUMMY(style)							CUSTOM0(PDummy,style)
#define STATIC(style,text)						CUSTOM1(PStatic,style,text)
#define INTEGER(style,column,format1,format2)	CUSTOM3(PInteger,style,column,format1,format2)
#define TEXT(style,column,format)				CUSTOM2(PText,style,column,format)
#define RULE(style,column,str,sql)				CUSTOM3(PRule,style,column,str,sql)
#define DECIMAL(style,column,format)			CUSTOM2(PDecimal,style,column,format)
#define DATETIME(style,column,format)			CUSTOM2(PDatetime,style,column,format)
#define MULTITEXT(style,attribute,minsize,maxsize,lineformat,lineseparator,eotformat)	\
	CUSTOM6(PMultitext,style,attribute,minsize,maxsize,lineformat,lineseparator,eotformat)

#define LOOP(style, table, minsize, maxsize)		BEGIN_CUSTOM3(PLoop, style, table, minsize, maxsize)
#define POINTER(style,table, attribute)				BEGIN_CUSTOM2(PPointer, style, table, attribute)
#define REPEAT(style,table, attribute, minsize, maxsize)	BEGIN_CUSTOM4(PRepeat, style, table, attribute, minsize, maxsize)

#define BEGIN_PARALLEL(style,table)	BEGIN_CUSTOM1(PParallel, style, table)
#define END_PARALLEL				END_CUSTOM(PParallel)

#define BEGIN_SEQUENCE(style,table)	BEGIN_CUSTOM1(PSequence, style, table)
#define END_SEQUENCE				END_CUSTOM(PSequence)

#define BEGIN_SWITCH(style,table)	BEGIN_CUSTOM1(PSwitch, style, table)
#define END_SWITCH					END_CUSTOM(PSwitch)

#define BEGIN_LOOP(style,table,minsize,maxsize) LOOP(style, table, minsize, maxsize) BEGIN_SEQUENCE(OS_MANTADORY,NULL)
#define END_LOOP								END_SEQUENCE

#define BEGIN_POINTER(style,table,attribute)	POINTER(style,table,attribute) BEGIN_SEQUENCE(OS_MANTADORY,NULL)
#define END_POINTER								END_SEQUENCE

#define BEGIN_REPEAT(style,table,attribute,minsize,maxsize) REPEAT(style,table,attribute,minsize,maxsize) BEGIN_SEQUENCE(OS_MANTADORY,NULL)
#define END_REPEAT											END_SEQUENCE
			
#endif // __PRC_H
