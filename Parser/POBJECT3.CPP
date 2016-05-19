//////////////////////////////////
// System level dependencies

#include <windows.h>

//////////////////////////////////
// ANSI level dependencies

#include <stdio.h>
#include <string.h>
#include <time.h>

//////////////////////////////////
// Application level dependencies

#include "tio.h"
#include "tdb.h"
#include "tlog.h"
#include "tmemory.h"
#include "pobject.h"

IMPLEMENT_ALLOCATE(PUserObject)
IMPLEMENT_ALLOCATE(PDummy)
IMPLEMENT_ALLOCATE(PStatic)
IMPLEMENT_ALLOCATE(PInteger)
IMPLEMENT_ALLOCATE(PText)
IMPLEMENT_ALLOCATE(PDecimal)
IMPLEMENT_ALLOCATE(PDatetime)
IMPLEMENT_ALLOCATE(PMultitext)
IMPLEMENT_ALLOCATE(PRule)
IMPLEMENT_ALLOCATE(PSequence)
IMPLEMENT_ALLOCATE(PParallel)
IMPLEMENT_ALLOCATE(PSwitch)
IMPLEMENT_ALLOCATE(PLoop)
IMPLEMENT_ALLOCATE(PPointer)
IMPLEMENT_ALLOCATE(PRepeat)

IMPLEMENT_OBJECT(PObject, "PObject")
IMPLEMENT_OBJECT(PUserObject, "PUserObject")
IMPLEMENT_OBJECT(PDummy, "PDummy")
IMPLEMENT_OBJECT(PStatic, "PStatic")
IMPLEMENT_OBJECT(PInteger, "PInteger")
IMPLEMENT_OBJECT(PText, "PText")
IMPLEMENT_OBJECT(PDecimal, "PDecimal")
IMPLEMENT_OBJECT(PDatetime, "PDatetime")
IMPLEMENT_OBJECT(PMultitext, "PMultitext")
IMPLEMENT_OBJECT(PRule, "PRule")
IMPLEMENT_OBJECT(PContainer, "PContainer")
IMPLEMENT_OBJECT(PParallel, "PParallel")
IMPLEMENT_OBJECT(PSequence, "PSequence")
IMPLEMENT_OBJECT(PSwitch, "PSwitch")
IMPLEMENT_OBJECT(PLoop, "PLoop")
IMPLEMENT_OBJECT(PPointer, "PPointer")
IMPLEMENT_OBJECT(PRepeat, "PRepeat")

IMPLEMENT_MOVESHORT(PUserObject, PObject, 1)
IMPLEMENT_MOVE(PDummy, PObject, 0)
IMPLEMENT_MOVE(PStatic, PObject, 1)
IMPLEMENT_MOVE(PInteger, PObject, 3)
IMPLEMENT_MOVE(PText, PObject, 2)
IMPLEMENT_MOVE(PDecimal, PObject, 2)
IMPLEMENT_MOVE(PDatetime, PObject, 2)
IMPLEMENT_MOVE(PMultitext, PObject, 6)
IMPLEMENT_MOVE(PRule, PObject, 3)
IMPLEMENT_MOVESHORT(PContainer, PObject, 1)
IMPLEMENT_MOVESHORT(PParallel, PContainer, 0)
IMPLEMENT_MOVESHORT(PSequence, PContainer, 0)
IMPLEMENT_MOVESHORT(PSwitch, PContainer, 0)
IMPLEMENT_MOVE(PLoop, PContainer, 2)
IMPLEMENT_MOVE(PPointer, PContainer, 1)
IMPLEMENT_MOVE(PRepeat, PPointer, 2)

IMPLEMENT_PROGRAM(PUserObject, PObject, 1)
IMPLEMENT_PROGRAM(PDummy, PObject, 0)
IMPLEMENT_PROGRAM(PStatic, PObject, 1)
IMPLEMENT_PROGRAM(PInteger, PObject, 3)
IMPLEMENT_PROGRAM(PText, PObject, 2)
IMPLEMENT_PROGRAM(PDecimal, PObject, 2)
IMPLEMENT_PROGRAM(PDatetime, PObject, 2)
IMPLEMENT_PROGRAM(PMultitext, PObject, 6)
IMPLEMENT_PROGRAM(PRule, PObject, 3)
IMPLEMENT_PROGRAM(PContainer, PObject, 1)
IMPLEMENT_PROGRAM(PSequence, PContainer, 0)
IMPLEMENT_PROGRAM(PParallel, PContainer, 0)
IMPLEMENT_PROGRAM(PSwitch, PContainer, 0)
IMPLEMENT_PROGRAM(PLoop, PContainer, 2)
IMPLEMENT_PROGRAM(PPointer, PContainer, 1)
IMPLEMENT_PROGRAM(PRepeat, PPointer, 2)

LPARAM PObject::m_lpStack[16];
UINT PObject::m_nStack = 0;

///////////////////////////////////////////////////////////////
// Special operation implementation

LPARAM * PObject::MoveShort(LPARAM *plParam) { return &plParam[4]; }
LPARAM * PObject::MoveLong(LPARAM *plParam) { return &plParam[4]; }
LPARAM * PObject::Program(LPARAM *plParam) { return &plParam[4]; }

LPARAM * PUserObject::MoveLong(LPARAM *plParam)
{
	plParam = PUserObject::MoveShort(plParam); 
	// This action provide standart object offset
	// and plParam point to first child

	plParam = ((MOVEFUNC)(plParam[GW_MOVE]))(plParam);
	return plParam;
}

LPARAM * PContainer::MoveLong(LPARAM *plParam)
{
	plParam = PContainer::MoveShort(plParam); 
	// This action provide standart object offset
	// and plParam point to first child

	plParam = ((MOVEFUNC)(plParam[GW_MOVE]))(plParam);
	return plParam;
}

LPARAM * PSequence::MoveLong(LPARAM *plParam)
{
	plParam = PSequence::MoveShort(plParam); 
	// This action provide standart object offset
	// and plParam point to first child

	while ((*plParam) != NULL) 
		plParam = ((MOVEFUNC)(plParam[GW_MOVE]))(plParam);
		
	return &plParam[1]; // Skip NULL
}

LPARAM * PParallel::MoveLong(LPARAM *plParam)
{
	plParam = PParallel::MoveShort(plParam); 
	// This action provide standart object offset
	// and plParam point to first child

	while ((*plParam) != NULL) 
		plParam = ((MOVEFUNC)(plParam[GW_MOVE]))(plParam);
		
	return &plParam[1]; // Skip NULL
}


LPARAM * PSwitch::MoveLong(LPARAM *plParam)
{
	plParam = PSwitch::MoveShort(plParam); 
	// This action provide standart object offset
	// and plParam point to first child

	while ((*plParam) != NULL) 
		plParam = ((MOVEFUNC)(plParam[GW_MOVE]))(plParam);
		
	return &plParam[1]; // Skip NULL
}


void PObject::Preload(PObject *pObject, UINT nLevel, TLog *pLog)
{
	pLog->BeginWrite(pObject->GetObjectName(), nLevel); 
}

void PObject::Prestore(PObject *pObject, UINT nLevel, TLog *pLog)
{
	pLog->BeginWrite(pObject->GetObjectName(), nLevel); 
}

void PObject::Preselect(PObject *pObject, UINT nLevel, TLog *pLog)
{
	pLog->BeginWrite(pObject->GetObjectName(), nLevel); 
}

void PObject::Preinsert(PObject *pObject, UINT nLevel, TLog *pLog)
{
	pLog->BeginWrite(pObject->GetObjectName(), nLevel); 
}

void PObject::Postload(PObject *pObject, UINT nLevel, TLog *pLog, RETVALUE retvalue)
{
	pLog->EndWrite(pObject->GetObjectName(), nLevel, retvalue);
}

void PObject::Poststore(PObject *pObject, UINT nLevel, TLog *pLog, RETVALUE retvalue)
{
	pLog->EndWrite(pObject->GetObjectName(), nLevel, retvalue);
}

void PObject::Postselect(PObject *pObject, UINT nLevel, TLog *pLog, RETVALUE retvalue)
{
	pLog->EndWrite(pObject->GetObjectName(), nLevel, retvalue);
}

void PObject::Postinsert(PObject *pObject, UINT nLevel, TLog *pLog, RETVALUE retvalue)
{
	pLog->EndWrite(pObject->GetObjectName(), nLevel, retvalue);
}

///////////////////////////////////////////////////
// PObject common methods

int PObject::IsKindOf(char * pszObjectName)
{
	if (strcmp(pszObjectName, GetObjectName()) == 0)
		return 1;

	PObject * pParent = GetParent();
	return (pParent != NULL && pParent->IsKindOf(pszObjectName))?2:0;
}

PObject * PObject::GetParent() 
{ 
	return m_pParent; 
}

PObject * PObject::GetNext() 
{ 
	return m_pNext; 
}

void PObject::SetNext(PObject *pObject) 
{ 
	m_pNext = pObject; 
}

PObject * PObject::GetLast()
{
	PObject * ptr = this;
	while ((ptr->m_pNext) != NULL) ptr = ptr->m_pNext;
	return ptr;
}

void PObject::Push(LPARAM lParam)
{
	m_lpStack[m_nStack++] = lParam;
	m_nStack &= 0x0F;
}

LPARAM PObject::Pop()
{
	m_nStack--;
	m_nStack &= 0x0F;
	return m_lpStack[m_nStack];
}

/////////////////////////////////////
// Containers' common methods

void PContainer::Attach(PObject * pChild)
{
	if (GetFirstChild() == NULL)
		SetFirstChild(pChild);
	else
		(GetFirstChild()->GetLast())->SetNext(pChild);
}

PObject * PContainer::GetFirstChild() 
{ 
	return m_pFirstChild; 
}

void PContainer::SetFirstChild(PObject * pChild)
{
	m_pFirstChild = pChild;
}

