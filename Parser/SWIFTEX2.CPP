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
// File swiftex2.cpp
// Copyright © 1996
// Programmer: Dmitry Protopopov
//////////////////////////////////////////////////////////////////////////

const char cszNoDataFound[] = "***No Data Found***";
const char cszError[] = "***Error***";

IMPLEMENT_ALLOCATE(PLtAddress)
IMPLEMENT_OBJECT(PLtAddress, "PLtAddress")
IMPLEMENT_MOVE(PLtAddress, PObject, 1)
IMPLEMENT_PROGRAM(PLtAddress, PObject, 1)

IMPLEMENT_ALLOCATE(PBicAddress)
IMPLEMENT_OBJECT(PBicAddress, "PBicAddress")
IMPLEMENT_MOVE(PBicAddress, PObject, 1)
IMPLEMENT_PROGRAM(PBicAddress, PObject, 1)

IMPLEMENT_ALLOCATE(PNumber)
IMPLEMENT_OBJECT(PNumber, "PNumber")
IMPLEMENT_MOVE(PNumber, PObject, 2)
IMPLEMENT_PROGRAM(PNumber, PObject, 2)

IMPLEMENT_ALLOCATE(PNegative)
IMPLEMENT_OBJECT(PNegative, "PNegative")
IMPLEMENT_MOVE(PNegative, PObject, 2)
IMPLEMENT_PROGRAM(PNegative, PObject, 2)

IMPLEMENT_ALLOCATE(FIELD18A)
IMPLEMENT_OBJECT(FIELD18A, "SWIFT FIELD 18A")
IMPLEMENT_MOVE(FIELD18A, PObject, 0)
IMPLEMENT_PROGRAM(FIELD18A, PObject, 0)

PLtAddress::PLtAddress() : PObject()
{
}

PLtAddress::~PLtAddress()
{
}

RETVALUE PLtAddress::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pszAttribute = (char *)PARAM(plParam, 0);
	return PObject::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}


RETVALUE PLtAddress::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{ 
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bStatus = TRUE;
	UINT nLength;

	Preload(this, m_nLevel, pLog);
	pInput->BeginRead();
	bStatus = bStatus && (pInput->Scanf((char *)LT_ADDRESS, m_strText, &nLength, 12)) ;
	pInput->EndRead(bStatus);
	if (!bStatus)
	{
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
	}
	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PLtAddress::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{ 
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bStatus = TRUE;
	bStatus = bStatus && ((pOutput->Write(m_strText, 12)) == 12);
	if (!bStatus) retvalue = PARSER_ERROR;
	return retvalue; 
}

RETVALUE PLtAddress::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	RETVALUE retvalue = PARSER_SUCCESS;
	if (m_lpStyle & OS_DATA_ERROR) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, (char *)cszError, sizeof(cszError)-1);
	if (m_lpStyle & OS_NULL_VALUE) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Null, NULL, 0);
	else switch (pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, m_strText, 12))
	{
	case FALSE:
		retvalue = PARSER_ERROR;
		break;
	default:
		break;
	}

	return retvalue;
}

RETVALUE PLtAddress::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bStatus = TRUE;
	UINT nLength;

	Preselect(this, m_nLevel, pLog);
	memset(m_strText, ' ', 12);
	bStatus = bStatus && (pArchive->GetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, m_strText, &nLength, sizeof(m_strText))); 
	if (bStatus) switch(nLength)
	{
	case 12:
		break;
	case 11:
		m_strText[11] = m_strText[10];
		m_strText[10] = m_strText[9];
		m_strText[9] = m_strText[8];
		m_strText[8] = 'A';
		break;
	case 8:
		memmove(&m_strText[8], "AXXX", 4);
		break;
	default:
		m_lpStyle |= OS_DATA_ERROR;
		retvalue = PARSER_ERROR;
		bStatus = FALSE;
	}
	else
	{
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
	}

	if (bStatus && !IsValid())
	{
		m_lpStyle |= OS_DATA_ERROR;
		retvalue = PARSER_ERROR;
	}

	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

UINT PLtAddress::GetLength()
{
	return 12;
}

BOOL PLtAddress::IsValid()
{
	BOOL bStatus = TRUE;

	bStatus = bStatus &&  ('A'<=m_strText[0]) && (m_strText[0]<='Z');
	bStatus = bStatus &&  ('A'<=m_strText[1]) && (m_strText[1]<='Z');
	bStatus = bStatus &&  ('A'<=m_strText[2]) && (m_strText[2]<='Z');
	bStatus = bStatus &&  ('A'<=m_strText[3]) && (m_strText[3]<='Z');
	bStatus = bStatus &&  ('A'<=m_strText[4]) && (m_strText[4]<='Z');
	bStatus = bStatus &&  ('A'<=m_strText[5]) && (m_strText[5]<='Z');
	bStatus = bStatus &&  ((('A'<=m_strText[6]) && (m_strText[6]<='Z')) || (('0'<=m_strText[6]) && (m_strText[6]<='9')));
	bStatus = bStatus &&  ((('A'<=m_strText[7]) && (m_strText[7]<='Z')) || (('0'<=m_strText[7]) && (m_strText[7]<='9')));
	bStatus = bStatus &&  ((('A'<=m_strText[8]) && (m_strText[8]<='Z')) || (('0'<=m_strText[8]) && (m_strText[8]<='9')));
	bStatus = bStatus &&  ((('A'<=m_strText[9]) && (m_strText[9]<='Z')) || (('0'<=m_strText[9]) && (m_strText[9]<='9')));
	bStatus = bStatus &&  ((('A'<=m_strText[10]) && (m_strText[10]<='Z')) || (('0'<=m_strText[10]) && (m_strText[10]<='9')));
	bStatus = bStatus &&  ((('A'<=m_strText[11]) && (m_strText[11]<='Z')) || (('0'<=m_strText[11]) && (m_strText[11]<='9')));
	return bStatus;
}

///////////////////////////////////////////////////////
PBicAddress::PBicAddress() : PObject()
{
}

PBicAddress::~PBicAddress()
{
}

RETVALUE PBicAddress::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pszAttribute = (char *)PARAM(plParam, 0);
	return PObject::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PBicAddress::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{ 
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bStatus = TRUE;

	Preload(this, m_nLevel, pLog);
	pInput->BeginRead();
	bStatus = bStatus && (pInput->Scanf((char *)BIC, m_strText, &m_nLength, 12)) ;
	pInput->EndRead(bStatus);
	if (!bStatus)
	{
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
	}
	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PBicAddress::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{ 
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bStatus = TRUE;
	bStatus = bStatus && ((pOutput->Write(m_strText, 8)) == 8);
	switch(m_nLength)
	{
	case 12:
	case 11:
		bStatus = bStatus && ((pOutput->Write(&m_strText[m_nLength-3], 3)) == 3);
	case 8:
	default:
		break;
	}

	if (!bStatus) retvalue = PARSER_ERROR;
	return retvalue; 
}

RETVALUE PBicAddress::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	RETVALUE retvalue = PARSER_SUCCESS;
	if (m_lpStyle & OS_DATA_ERROR) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, (char *)cszError, sizeof(cszError)-1);
	if (m_lpStyle & OS_NULL_VALUE) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Null, NULL, 0);
	else switch (pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, m_strText, m_nLength))
	{
	case FALSE:
		retvalue = PARSER_ERROR;
		break;
	default:
		break;
	}

	return retvalue;
}

RETVALUE PBicAddress::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bStatus = TRUE;

	Preselect(this, m_nLevel, pLog);
	bStatus = bStatus && (pArchive->GetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, m_strText, &m_nLength, sizeof(m_strText))); 

	if (bStatus)
	{
		if (!IsValid())
		{
			m_lpStyle |= OS_DATA_ERROR;
			retvalue = PARSER_ERROR;
		}
	}
	else
	{
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
	}

	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

UINT PBicAddress::GetLength()
{
	if (m_lpStyle & OS_NULL_VALUE) return 0;
	switch(m_nLength)
	{
	case 12:
	case 11:
		return 11;
	case 8:
	default:
		return 8;
	}
}

BOOL PBicAddress::IsValid()
{
	BOOL bStatus = TRUE;
	switch(m_nLength)
	{
	case 12:
	case 11:
		bStatus = bStatus &&  ((('A'<=m_strText[m_nLength-1]) && (m_strText[m_nLength-1]<='Z')) || (('0'<=m_strText[m_nLength-1]) && (m_strText[m_nLength-1]<='9')));
		bStatus = bStatus &&  ((('A'<=m_strText[m_nLength-2]) && (m_strText[m_nLength-2]<='Z')) || (('0'<=m_strText[m_nLength-2]) && (m_strText[m_nLength-2]<='9')));
		bStatus = bStatus &&  ((('A'<=m_strText[m_nLength-3]) && (m_strText[m_nLength-3]<='Z')) || (('0'<=m_strText[m_nLength-3]) && (m_strText[m_nLength-3]<='9')));

	case 8:
		bStatus = bStatus &&  ('A'<=m_strText[0]) && (m_strText[0]<='Z');
		bStatus = bStatus &&  ('A'<=m_strText[1]) && (m_strText[1]<='Z');
		bStatus = bStatus &&  ('A'<=m_strText[2]) && (m_strText[2]<='Z');
		bStatus = bStatus &&  ('A'<=m_strText[3]) && (m_strText[3]<='Z');
		bStatus = bStatus &&  ('A'<=m_strText[4]) && (m_strText[4]<='Z');
		bStatus = bStatus &&  ('A'<=m_strText[5]) && (m_strText[5]<='Z');
		bStatus = bStatus &&  ((('A'<=m_strText[6]) && (m_strText[6]<='Z')) || (('0'<=m_strText[6]) && (m_strText[6]<='9')));
		bStatus = bStatus &&  ((('A'<=m_strText[7]) && (m_strText[7]<='Z')) || (('0'<=m_strText[7]) && (m_strText[7]<='9')));
		return bStatus;
	default:
		return FALSE;
	}
}
///////////////////////////////////////////////////////

PNegative::PNegative() : PObject()
{
}

PNegative::~PNegative()
{
}

RETVALUE PNegative::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pszAttribute = (char *)PARAM(plParam, 0);
	m_nMaxLength = (UINT)PARAM(plParam, 1);
	m_strText[0] = '-';
	return PObject::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PNegative::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{ 
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;

	Preload(this, m_nLevel, pLog);
	pInput->BeginRead();
	bStatus = bStatus && (pInput->Scanf("%*[0-9],%*[0-9]%n\0%*[0-9],%n\0", &m_strText[1], &m_nLength, sizeof(m_strText) - 1)) ;
	bStatus = bStatus &&	(m_nLength <= m_nMaxLength) ;

	switch (bStatus)
	{
	case FALSE:
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
		break;
	default:
		break;
	}

	m_nLength++;
	UINT i = m_nLength;
	while ( bStatus && --i ) if (m_strText[i] == ',') m_strText[i] = '.';

	pInput->EndRead(bStatus);
	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PNegative::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{ 
	RETVALUE retvalue = PARSER_SUCCESS;
	char *ptr = &m_strText[1];
	BOOL bStatus = TRUE;
	UINT i = m_nLength;
	BOOL comma = FALSE;

	while ( bStatus && --i )
		if (*ptr == '.') 
		{			
			bStatus = ((pOutput->Write(",", 1)) == 1);
			comma = TRUE;
			ptr++;
		}
		else
		{
			bStatus = ((pOutput->Write(ptr++, 1)) == 1);
		}

	if (bStatus && !comma) bStatus = ((pOutput->Write(",", 1)) == 1);
	if (!bStatus) retvalue = PARSER_ERROR;
	return retvalue; 
}

RETVALUE PNegative::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	RETVALUE retvalue = PARSER_SUCCESS;
	if (m_lpStyle & OS_DATA_ERROR) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, (char *)cszError, sizeof(cszError)-1);
	if (m_lpStyle & OS_NULL_VALUE) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Null, NULL, 0);
	else switch (pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Decimal, m_strText, m_nLength))
	{
	case TRUE:
		break;
	case FALSE:
		retvalue = PARSER_ERROR;
		break;
	}

	return retvalue;
}

RETVALUE PNegative::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bStatus = TRUE;

	Preselect(this, m_nLevel, pLog);
	bStatus = bStatus && (pArchive->GetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Decimal, m_strText, &m_nLength, sizeof(m_strText))); 
	if (bStatus)
	{
		bStatus = bStatus && (1 < m_nLength) && (m_nLength <= (m_nMaxLength+1) ) && (m_strText[0] == '-');
		if (bStatus)
		{
			UINT i = m_nLength;
			BOOL bComma = FALSE;
			while ( !bComma && i-- ) bComma = (m_strText[i] == '.');
			if (bComma)
			{
				while ( m_strText[m_nLength-1] == '0' ) m_nLength--;
				if (i == 1)
				{
					for ( i = m_nLength++ ; --i ; ) m_strText[i+1] = m_strText[i];
					m_strText[1] = '0';				
				}
			}
		}
		else
		{
			m_lpStyle |= OS_DATA_ERROR;
			retvalue = PARSER_NO_DATA_FOUND;
		}
	}
	else
	{
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
	}
	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

UINT PNegative::GetLength()
{
	if (m_lpStyle & OS_NULL_VALUE) return 0;
	return m_nLength-1;
}

PNumber::PNumber() : PObject()
{
}

PNumber::~PNumber()
{
}

RETVALUE PNumber::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	m_pszAttribute = (char *)PARAM(plParam, 0);
	m_nMaxLength = (UINT)PARAM(plParam, 1);
	return PObject::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE PNumber::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{ 
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;

	Preload(this, m_nLevel, pLog);
	pInput->BeginRead();
	bStatus = bStatus && (pInput->Scanf("%*[0-9],%*[0-9]%n\0%*[0-9],%n\0", m_strText, &m_nLength, sizeof(m_strText)));
	bStatus = bStatus &&	(m_nLength <= m_nMaxLength) ;

	UINT i = m_nLength;
	while ( bStatus && i-- ) if (m_strText[i] == ',') m_strText[i] = '.';

	pInput->EndRead(bStatus);
	if (!bStatus) 
	{
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
	}
	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PNumber::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{ 
	RETVALUE retvalue = PARSER_SUCCESS;
	char *ptr = m_strText;
	BOOL bStatus = TRUE;
	UINT i = m_nLength;
	BOOL comma = FALSE;

	while ( bStatus && i-- )
		if (*ptr == '.') 
		{
			bStatus = ((pOutput->Write(",", 1)) == 1);
			comma = TRUE;
			ptr++;
		}
		else
		{
			bStatus = ((pOutput->Write(ptr++, 1)) == 1);
		}

	if (bStatus && !comma) bStatus = ((pOutput->Write(",", 1)) == 1);

	if (!bStatus) retvalue = PARSER_ERROR;
	return retvalue; 
}

RETVALUE PNumber::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	RETVALUE retvalue = PARSER_SUCCESS;

	if (m_lpStyle & OS_DATA_ERROR) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, (char *)cszError, sizeof(cszError)-1);
	if (m_lpStyle & OS_NULL_VALUE) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Null, NULL, 0);
	else switch (pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Decimal, m_strText, m_nLength))
	{
	case TRUE:
		break;
	case FALSE:
		retvalue = PARSER_ERROR;
		break;
	}

	return retvalue;
}

RETVALUE PNumber::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;

	Preselect(this, m_nLevel, pLog);
	bStatus = bStatus && (pArchive->GetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Decimal, m_strText, &m_nLength, sizeof(m_strText))); 
	if (bStatus)
	{
		bStatus = bStatus && (0 < m_nLength) && (m_nLength <= m_nMaxLength) && (m_strText[0] != '-');
		if (bStatus)
		{
			UINT i = m_nLength;
			BOOL bComma = FALSE;
			while ( !bComma && i-- ) bComma = (m_strText[i] == '.');
			if (bComma)
			{
				while ( m_strText[m_nLength-1] == '0' ) m_nLength--;
				if (i == 0)
				{
					for ( i = m_nLength++ ; i-- ; ) m_strText[i+1] = m_strText[i];
					m_strText[0] = '0';
				}
			}
		}
		else
		{
			m_lpStyle |= OS_DATA_ERROR;
			retvalue = PARSER_NO_DATA_FOUND;
		}
	}
	else 
	{
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
	}
	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

UINT PNumber::GetLength()
{
	if (m_lpStyle & OS_NULL_VALUE) return 0;
	return m_nLength;
}

FIELD18A::FIELD18A() : PObject()
{
}

FIELD18A::~FIELD18A()
{
}

RETVALUE FIELD18A::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	return PObject::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE FIELD18A::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{
	RETVALUE retvalue = PARSER_SUCCESS;
	char buffer[8];
	char vBuffer[16];
	UINT len;
	BOOL bStatus = TRUE;
	UINT value = (UINT)Pop();

	Preload(this, m_nLevel, pLog);
	pInput->BeginRead();
	bStatus = bStatus && (pInput->Read(buffer, 5) == 5) && (strncmp(buffer, ":18A:", 5) == 0);
	bStatus = bStatus && (pInput->Scanf("%*5[0-9]%n\0", vBuffer, &len, sizeof(vBuffer)-1));
	bStatus = bStatus && (pInput->Read(buffer, 2) == 2) && (strncmp(buffer, EOL, 2) == 0);
	if (bStatus) vBuffer[len] = '\0';
	bStatus = bStatus && (value == (m_nCount = (UINT)atoi(vBuffer)));
	pInput->EndRead(bStatus);

	if (!bStatus)
	{

//#if defined(_DEBUG)
//		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
//#endif

//		retvalue = PARSER_ERROR;
		retvalue = PARSER_NO_DATA_FOUND;
	}

	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue;
}

RETVALUE FIELD18A::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{ 
	RETVALUE retvalue = PARSER_SUCCESS;
	char buffer[16];
	sprintf(buffer, ":18A:%u\r\n", m_nCount);
	pOutput->Write(buffer, strlen(buffer));
	return retvalue;
}

RETVALUE FIELD18A::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	return PARSER_SUCCESS;
}

RETVALUE FIELD18A::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bStatus = TRUE;
	Preselect(this, m_nLevel, pLog);
	m_nCount = (UINT)Pop();
	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue;
}

UINT FIELD18A::GetLength() 
{ 
	if (m_lpStyle & OS_NULL_VALUE) return 0;
	char buffer[16];
	sprintf(buffer, ":18A:%u\r\n", m_nCount);
	return strlen(buffer);
}


