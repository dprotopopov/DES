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

///////////////////////////////////////////////
// Event methods

RETVALUE PObject::Event(UINT event, LPARAM lParam1, LPARAM lParam2) 
{
	return PARSER_NO_DATA_FOUND;
}

RETVALUE PUserObject::Event(UINT event, LPARAM lParam1, LPARAM lParam2) 
{
	return m_pObject->Event(event, lParam1, lParam2);
}

RETVALUE PContainer::Event(UINT event, LPARAM lParam1, LPARAM lParam2)
{
	RETVALUE retvalue = PObject::Event(event, lParam1, lParam2);
	if ((event == EV_FIND) && (lParam1 == (LPARAM)m_pszDomain))
	{
		*((PObject **)lParam2) = this;
		return PARSER_SUCCESS;
	}

	PObject * pCurrent = GetFirstChild();
	while ((retvalue == PARSER_NO_DATA_FOUND) && (pCurrent != NULL))
	{
		retvalue = pCurrent->Event(event, lParam1, lParam2);
		pCurrent = pCurrent->GetNext();
	}
	return retvalue;
}

RETVALUE PText::Event(UINT event, LPARAM lParam1, LPARAM lParam2) 
{
	switch(event)
	{
	case EV_FIND:
		if (((char *)lParam1) != m_pszAttribute) break;
		*((PObject **)lParam2) = this;
		return PARSER_SUCCESS;

	default:
		break;
	}
	return PObject::Event(event, lParam1, lParam2);
}

RETVALUE PInteger::Event(UINT event, LPARAM lParam1, LPARAM lParam2) 
{
	switch(event)
	{
	case EV_FIND:
		if (((char *)lParam1) != m_pszAttribute) break;
		*((PObject **)lParam2) = this;
		return PARSER_SUCCESS;

	default:
		break;
	}
	return PObject::Event(event, lParam1, lParam2);
}

RETVALUE PDecimal::Event(UINT event, LPARAM lParam1, LPARAM lParam2) 
{
	switch(event)
	{
	case EV_FIND:
		if (((char *)lParam1) != m_pszAttribute) break;
		*((PObject **)lParam2) = this;
		return PARSER_SUCCESS;

	default:
		break;
	}
	return PObject::Event(event, lParam1, lParam2);
}

RETVALUE PDatetime::Event(UINT event, LPARAM lParam1, LPARAM lParam2) 
{
	switch(event)
	{
	case EV_FIND:
		if (((char *)lParam1) != m_pszAttribute) break;
		*((PObject **)lParam2) = this;
		return PARSER_SUCCESS;

	default:
		break;
	}
	return PObject::Event(event, lParam1, lParam2);
}

RETVALUE PMultitext::Event(UINT event, LPARAM lParam1, LPARAM lParam2) 
{
	switch(event)
	{
	case EV_FIND:
		if (((char *)lParam1) != m_pszAttribute) break;
		*((PObject **)lParam2) = this;
		return PARSER_SUCCESS;

	default:
		break;
	}
	return PObject::Event(event, lParam1, lParam2);
}

RETVALUE PRule::Event(UINT event, LPARAM lParam1, LPARAM lParam2) 
{
	switch(event)
	{
	case EV_FIND:
		if (((char *)lParam1) != m_pszAttribute) break;
		*((PObject **)lParam2) = this;
		return PARSER_SUCCESS;

	default:
		break;
	}
	return PObject::Event(event, lParam1, lParam2);
}

///////////////////////////////////////////////////
// GetLength methods

UINT PObject::GetLength()
{
	return 0;
}

UINT PUserObject::GetLength()
{
	return m_pObject->GetLength();
}

UINT PStatic::GetLength()
{
	if (m_lpStyle & OS_NULL_VALUE) return 0;
	return strlen(m_pszText);
}

UINT PInteger::GetLength()
{
	if (m_lpStyle & OS_NULL_VALUE) return 0;
	char buffer[256];
	sprintf(buffer, m_pszSecondaryFormat, m_lValue);
	return strlen(buffer);
}

UINT PText::GetLength()
{
	if (m_lpStyle & OS_NULL_VALUE) return 0;
	return m_nLength;
}

UINT PDecimal::GetLength()
{
	if (m_lpStyle & OS_NULL_VALUE) return 0;
	return m_nLength;
}

UINT PDatetime::GetLength()
{
	if (m_lpStyle & OS_NULL_VALUE) return 0;
	char buffer[256];
	return strftime(buffer, sizeof(buffer), m_pszFormat, &m_tm);
}

UINT PMultitext::GetLength()
{
	if (m_lpStyle & OS_NULL_VALUE) return 0;
	UINT i = m_nLength;
	UINT nTotal = m_nLength;
	UINT nSepLen = strlen(m_pszLineSeparator)-1;
	while(i--) if (!m_strText[i]) nTotal+= nSepLen;
	return nTotal;
}

UINT PRule::GetLength()
{
	if (m_lpStyle & OS_NULL_VALUE) return 0;
	UINT i = m_nSelection;
	char *ptr = m_pszStreamConstants;
	while (i--) while(*ptr++);
	return strlen(ptr);
}

UINT PContainer::GetLength()
{
	if (m_lpStyle & OS_NULL_VALUE) return 0;
	UINT nTotal = 0;
	PObject * pChild = GetFirstChild();
	while (pChild)
	{
		nTotal += pChild->GetLength();
		pChild = pChild->GetNext();
	}
	return nTotal;
}

///////////////////////////////////////////////////
// Validate

RETVALUE PObject::Validate(TMemory * pMemory, TLog * pLog)
{
	return PARSER_SUCCESS;
}

RETVALUE PUserObject::Validate(TMemory * pMemory, TLog * pLog)
{
	return m_pObject->Validate(pMemory, pLog);
}

RETVALUE PContainer::Validate(TMemory * pMemory, TLog * pLog)
{
	RETVALUE retvalue = PARSER_SUCCESS;
	PObject * pChild = GetFirstChild();
	while (pChild)
	{
		switch(pChild->Validate(pMemory, pLog))
		{
		case PARSER_SUCCESS:
			pChild = pChild->GetNext();
			break;
		case PARSER_SUCCESS_WITH_INFO:
			retvalue = PARSER_SUCCESS_WITH_INFO;
			pChild = pChild->GetNext();
			break;
		case PARSER_ERROR:
			return PARSER_ERROR;
		}
	}
	return retvalue;
}
