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

RETVALUE PObject::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_lpStyle = lpStyle;
	m_pParent = pParent;
	m_pInstance = pInstance;
	m_pNext = NULL;
	m_nLevel = nLevel;
	return PARSER_SUCCESS;
}

RETVALUE PUserObject::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pObject = (PObject *)(pInstance + PARAM(plParam, 0));
	PObject::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
	return m_pObject->Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PStatic::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pszText = (char *)PARAM(plParam, 0);
	return PObject::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PInteger::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pszAttribute = (char *)PARAM(plParam, 0);
	m_pszPrimaryFormat = (char *)PARAM(plParam, 1);
	m_pszSecondaryFormat = (char *)PARAM(plParam, 2);
	return PObject::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PText::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pszAttribute = (char *)PARAM(plParam, 0);
	m_pszFormat = (char *)PARAM(plParam, 1);
	return PObject::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PDecimal::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pszAttribute = (char *)PARAM(plParam, 0);
	m_pszFormat = (char *)PARAM(plParam, 1);
	return PObject::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PDatetime::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pszAttribute = (char *)PARAM(plParam, 0);
	m_pszFormat = (char *)PARAM(plParam, 1);
	return PObject::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PMultitext::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pszAttribute = (char *)PARAM(plParam, 0);
	m_minsize = (UINT)PARAM(plParam, 1);
	m_maxsize = (UINT)PARAM(plParam, 2);
	m_pszLineFormat = (char *)PARAM(plParam, 3);
	m_pszLineSeparator = (char *)PARAM(plParam, 4);
	m_pszEndOfTextFormat = (char *)PARAM(plParam, 5);
	return PObject::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PRule::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pszAttribute = (char *)PARAM(plParam, 0);
	m_pszStreamConstants = (char *)PARAM(plParam, 1);
	m_pszSqlConstants = (char *)PARAM(plParam, 2);
	return PObject::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PContainer::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pszDomain = (char *)PARAM(plParam, 0);
	m_pCommand = ((PROGFUNC)(plParam[GW_PROG]))(plParam);
	m_pFirstChild = NULL;
	return PObject::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PSequence::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pProgram = ((PROGFUNC)(plParam[GW_PROG]))(plParam);
	return PContainer::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PParallel::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pProgram = ((PROGFUNC)(plParam[GW_PROG]))(plParam);
	return PContainer::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PSwitch::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pProgram = ((PROGFUNC)(plParam[GW_PROG]))(plParam);
	return PContainer::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PPointer::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pszAttribute = (char *)PARAM(plParam, 1);
	return PContainer::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PRepeat::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_minsize = (UINT)PARAM(plParam, 2);
	m_maxsize = (UINT)PARAM(plParam, 3);
	m_size = 0;
	return PPointer::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PLoop::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_minsize = (UINT)PARAM(plParam, 1);
	m_maxsize = (UINT)PARAM(plParam, 2);
	m_size = 0;
	return PContainer::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

///////////////////////////////////////////////////
// Refresh methods

RETVALUE PObject::Refresh(TMemory *pMemory) 
{
	m_lpStyle &= ~(OS_NULL_VALUE|OS_DATA_ERROR);
	return PARSER_SUCCESS;
}

RETVALUE PUserObject::Refresh(TMemory *pMemory) 
{
	m_pObject->Refresh(pMemory);
	return PObject::Refresh(pMemory);
}

RETVALUE PContainer::Refresh(TMemory *pMemory)
{

	PObject * pCurrent = GetFirstChild();
	while (pCurrent != NULL)
	{
		PObject * pNext = pCurrent->GetNext();
		pCurrent->Destroy(pMemory);
		delete pCurrent;
		pCurrent = pNext;
	}
	SetFirstChild(NULL);
	return PObject::Refresh(pMemory);
}

RETVALUE PSequence::Refresh(TMemory *pMemory)
{
	m_pCommand = m_pProgram;
	return PContainer::Refresh(pMemory);
}

RETVALUE PParallel::Refresh(TMemory *pMemory)
{
	m_pCommand = m_pProgram;
	return PContainer::Refresh(pMemory);
}

RETVALUE PSwitch::Refresh(TMemory *pMemory)
{
	m_pCommand = m_pProgram;
	return PContainer::Refresh(pMemory);
}

RETVALUE PRepeat::Refresh(TMemory *pMemory)
{
	m_size = 0;
	return PPointer::Refresh(pMemory);
}

RETVALUE PLoop::Refresh(TMemory *pMemory)
{
	m_size = 0;
	return PContainer::Refresh(pMemory);
}

///////////////////////////////////////////////////
// Destroy methods

void PObject::Destroy(TMemory *pMemory) 
{
}

void PUserObject::Destroy(TMemory *pMemory) 
{
	PObject::Destroy(pMemory);
	m_pObject->Destroy(pMemory);
}

void PContainer::Destroy(TMemory *pMemory)
{
	PObject::Destroy(pMemory);

	PObject * pCurrent = GetFirstChild();
	while (pCurrent != NULL)
	{
		PObject * pNext = pCurrent->GetNext();
		pCurrent->Destroy(pMemory);
		delete pCurrent;
		pCurrent = pNext;
	}
	SetFirstChild(NULL);
}
