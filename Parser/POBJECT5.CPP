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

const char cszError[] = "***Error***";
const char cszSuccess[] = "***Success***";
const char cszSuccessWithInfo[] = "***Success with info***";
const char cszNoDataFound[] = "***No data found***";


///////////////////////////////////////////////
// PObject constructor/destructor

PObject::PObject()
{
}

PObject::~PObject() {}

//////////////////////////////////////////////////////
// Primary object's constructor/destrucructor

PUserObject::PUserObject() : PObject()
{
}

PUserObject::~PUserObject()
{
}


PDummy::PDummy() : PObject()
{
}

PDummy::~PDummy()
{
}

PStatic::PStatic() : PObject()
{
}

PStatic::~PStatic()
{
}

PInteger::PInteger() : PObject()
{
}

PInteger::~PInteger()
{
}

PText::PText() : PObject()
{
}

PText::~PText()
{
}

PDecimal::PDecimal() : PObject()
{
}

PDecimal::~PDecimal()
{
}

PDatetime::PDatetime() : PObject()
{
}

PDatetime::~PDatetime()
{
}

PMultitext::PMultitext() : PObject()
{
}

PMultitext::~PMultitext()
{
}

PRule::PRule() : PObject()
{
}

PRule::~PRule()
{
}
//////////////////////////////////////////////////////
// PUserObject virtual methods

RETVALUE PUserObject::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{ 
	return m_pObject->Load(pInput, pMemory, pLog);
}

RETVALUE PUserObject::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{ 
	return m_pObject->Store(pOutput, pMemory, pLog);
}

RETVALUE PUserObject::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{ 
	return m_pObject->Insert(pMonitor, pMemory, pLog, pszDomain, pPrimary, ppSecondary, nSecondary);
}

RETVALUE PUserObject::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{ 
	return m_pObject->Select(pArchive, pMemory, pLog, pszDomain, pPrimary, ppSecondary, nSecondary);
}

//////////////////////////////////////////////////////
// PDummy virtual methods

RETVALUE PDummy::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{ 
	RETVALUE retvalue = PARSER_SUCCESS;
	Preload(this, m_nLevel, pLog);
	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PDummy::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{ 
	return PARSER_SUCCESS; 
}

RETVALUE PDummy::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{ 
	return PARSER_SUCCESS; 
}

RETVALUE PDummy::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{ 
	RETVALUE retvalue = PARSER_SUCCESS;
	Preselect(this, m_nLevel, pLog);
	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue;
}

/////////////////////////////////////////////////////
// PStatic virtual methods

RETVALUE PStatic::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{ 
	UINT len = strlen(m_pszText); 
	char buffer[256];
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;

	Preload(this, m_nLevel, pLog);
	pInput->BeginRead();
	bStatus = bStatus && (len == (pInput->Read(buffer, len))) ;
	bStatus = bStatus && (strncmp(buffer, m_pszText, len) == 0) ;
	pInput->EndRead(bStatus);
	switch (bStatus)
	{
	case FALSE:
		retvalue = PARSER_NO_DATA_FOUND;
		break;
	default:
		break;
	}
	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PStatic::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{ 
	UINT len = strlen(m_pszText); 
	BOOL bStatus = ((pOutput->Write(m_pszText, len)) == len);
	return bStatus?PARSER_SUCCESS:PARSER_ERROR; 
}

RETVALUE PStatic::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{ 
	return PARSER_SUCCESS; 
}

RETVALUE PStatic::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{ 
	RETVALUE retvalue = PARSER_SUCCESS;
	Preselect(this, m_nLevel, pLog);
	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue;
}

////////////////////////////////////////////////////////////////
// PInteger virtual methods

RETVALUE PInteger::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{ 
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	char buffer[256];
	UINT len;

	Preload(this, m_nLevel, pLog);

	pInput->BeginRead();
	bStatus = bStatus && (pInput->Scanf(m_pszPrimaryFormat, buffer, &len, sizeof(buffer))) ;
	pInput->EndRead(bStatus);

	switch (bStatus)
	{
	case FALSE:
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
		break;
	default:
		buffer[len] = '\0';
		sscanf(buffer, m_pszSecondaryFormat, &m_lValue);
		break;
	}

	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue;
}

RETVALUE PInteger::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{ 
	char buffer[256];
	UINT len;
	sprintf(buffer, m_pszSecondaryFormat, m_lValue);
	len = strlen(buffer);
	BOOL bStatus = ((pOutput->Write(buffer, len)) == len);
	return bStatus?PARSER_SUCCESS:PARSER_ERROR; 
}

RETVALUE PInteger::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	if (m_lpStyle & OS_DATA_ERROR) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, (char *)cszError, sizeof(cszError)-1);
	if (m_lpStyle & OS_NULL_VALUE) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Null, NULL, 0);
	else if (bStatus) switch (pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Integer, &m_lValue, sizeof(m_lValue)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bStatus = FALSE;
		break;
	}

	return retvalue; 
}

RETVALUE PInteger::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bError = FALSE;

	Preselect(this, m_nLevel, pLog);

	if (bStatus) switch (pArchive->GetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Integer, &m_lValue, NULL, sizeof(m_lValue)))
	{
	case FALSE:
		pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
		bStatus = FALSE;
		break;
	default:
		if ((!m_lValue) && (m_lpStyle & IS_NULLPATCH))
		{
			pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
			m_lpStyle |= OS_NULL_VALUE;
			retvalue = PARSER_NO_DATA_FOUND;
			bStatus = FALSE;
		}
		break;
	}

	Postselect(this, m_nLevel, pLog, retvalue);

	return retvalue; 
}

////////////////////////////////////////////////////////////////
// PText virtual methods

RETVALUE PText::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{ 
	LPARAM lFormatNumber;
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;

	Preload(this, m_nLevel, pLog);
	pInput->BeginRead();
	m_nLength = 0;
	bStatus = bStatus && (pInput->Scanf(m_pszFormat, m_strText, &m_nLength, sizeof(m_strText), &lFormatNumber)) ;
	switch (bStatus) 
	{
	case FALSE:
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
		break;
	default:
		if (m_lpStyle & TS_PUSHFORMATNUMBER) Push(lFormatNumber);
		break;
	}

	pInput->EndRead(bStatus);
	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PText::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{ 
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;

	if (bStatus && !(m_lpStyle & OS_NULL_VALUE)) switch (((pOutput->Write(m_strText, m_nLength)) == m_nLength)?TRUE:FALSE)
	{
	case FALSE:
		pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		break;
	default:
		break;
	}

	return retvalue; 
}

RETVALUE PText::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	RETVALUE retvalue = PARSER_SUCCESS;
	if (m_lpStyle & OS_DATA_ERROR) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, (char *)cszError, sizeof(cszError)-1);
	if (m_lpStyle & OS_NULL_VALUE) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Null, NULL, 0);
	else switch(pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, m_strText, m_nLength))
	{
	case FALSE:
		pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		break;
	default:
		break;
	}
	return retvalue;
}

RETVALUE PText::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{ 
	LPARAM lFormatNumber = 0;
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_ERROR;
	BOOL bError = TRUE;

	Preselect(this, m_nLevel, pLog);
	m_nLength = 0;
	if (bStatus) switch (pArchive->GetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, m_strText, &m_nLength, sizeof(m_strText)))
	{
	case FALSE:
		pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
		bError = FALSE;
		bStatus = FALSE;
		break;
	default:
		if (m_lpStyle & TS_COUPONPATCH) switch (m_nLength) 
		{
		case 2:
			if (('0'>m_strText[1]) || (m_strText[1]>'9')) break;
		case 1:
			if (('0'>m_strText[0]) || (m_strText[0]>'9')) break;
			{
				int i = 3;
				while (m_nLength--) m_strText[--i] = m_strText[m_nLength];
				while (i--) m_strText[i] = '0';
				m_nLength = 3;
			}
			break;
		default:
			break;
		}
		break;
	}

	if (bStatus) 
	{
		m_strText[m_nLength] = '\0';

		char *subformat = m_pszFormat;
		int i = -1;
		
		bStatus = FALSE;

		while ( *subformat )
		{
			sscanf(m_strText, subformat, &i);
			bStatus = ( i == (int)m_nLength ) ;
			if ( bStatus )
			{
				retvalue = PARSER_SUCCESS;
				bError = FALSE;
				break;
			}
			lFormatNumber++;
			while ( *subformat++ );
		}

		switch (bStatus)
		{
		case FALSE:
			m_lpStyle |= OS_DATA_ERROR;
			pLog->Write(m_pszAttribute, m_nLevel, TLog::Information, 0, m_strText, m_nLength);
			break;
		default:
			break;
		}
	}

	if (bError)
	{
		const char cszMessage[] = "***Wrong text format***";
		pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszMessage, sizeof(cszMessage)-1);
	}

	if (bStatus && (m_lpStyle & TS_PUSHFORMATNUMBER)) Push(lFormatNumber);
	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

////////////////////////////////////////////////////////////////
// PDecimal virtual methods

RETVALUE PDecimal::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{ 
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;

	Preload(this, m_nLevel, pLog);
	pInput->BeginRead();
	m_nLength = 0;
	bStatus = bStatus && (pInput->Scanf(m_pszFormat, m_strText, &m_nLength, sizeof(m_strText))) ;
	pInput->EndRead(bStatus);
	switch (bStatus) 
	{
	case FALSE:
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
		break;
	default:
		break;
	}
	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue;
}

RETVALUE PDecimal::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{ 
	BOOL bStatus = ((pOutput->Write(m_strText, m_nLength)) == m_nLength);
	return bStatus?PARSER_SUCCESS:PARSER_ERROR; 
}

RETVALUE PDecimal::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	if (m_lpStyle & OS_DATA_ERROR) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, (char *)cszError, sizeof(cszError)-1);
	if (m_lpStyle & OS_NULL_VALUE) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Null, NULL, 0);
	else if (bStatus) switch (pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Decimal, m_strText, m_nLength))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bStatus = FALSE;
		break;
	}

	return retvalue; 
}

RETVALUE PDecimal::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_ERROR;
	BOOL bError = TRUE;
	Preselect(this, m_nLevel, pLog);
	m_nLength = 0;
	if (bStatus) switch (pArchive->GetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Decimal, m_strText, &m_nLength, sizeof(m_strText)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
		bError = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bStatus) 
	{
		m_strText[m_nLength] = '\0';

		char *subformat = m_pszFormat;
		int i = -1;
		
		bStatus = FALSE;

		while ( *subformat )
		{
			sscanf(m_strText, subformat, &i);
			bStatus = ( i == (int)m_nLength ) ;
			if ( bStatus ) 
			{
				retvalue = PARSER_SUCCESS;
				bError = FALSE;
				break;
			}
			while ( *subformat++ );
		}

		switch (bStatus)
		{
		case FALSE:
			pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, m_strText, m_nLength);
			m_lpStyle |= OS_DATA_ERROR;
			break;
		default:
			break;
		}
	}

	Postselect(this, m_nLevel, pLog, retvalue);

	return retvalue; 
}

////////////////////////////////////////////////////////////////
// PDatetime virtual methods

RETVALUE PDatetime::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{ 
	char *ptr = m_pszFormat;
	char buffer[256];
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;

	Preload(this, m_nLevel, pLog);
	pInput->BeginRead();
	memset(&m_tm, 0, sizeof(struct tm));

	while (bStatus && *ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
			switch(*ptr)
			{
			case 'Y':
				bStatus = bStatus && (pInput->Read(buffer, 4) == 4);
				bStatus = bStatus && ('0' <= buffer[0]) && (buffer[0] <='9');
				bStatus = bStatus && ('0' <= buffer[1]) && (buffer[1] <='9');
				bStatus = bStatus && ('0' <= buffer[2]) && (buffer[2] <='9');
				bStatus = bStatus && ('0' <= buffer[3]) && (buffer[3] <='9');
				buffer[4] = '\0';
				break;

			case 'y':
			case 'm':
			case 'd':
			case 'H':
			case 'M':
			case 'S':
				bStatus = bStatus && (pInput->Read(buffer, 2) == 2);
				bStatus = bStatus && ('0' <= buffer[0]) && (buffer[0] <='9');
				bStatus = bStatus && ('0' <= buffer[1]) && (buffer[1] <='9');
				buffer[2] = '\0';
				break;

			case '%':
				bStatus = bStatus && (pInput->Read(buffer, 1) == 1);
				break;
			default:
				bStatus = FALSE;
			}

			if (bStatus)
			{
				switch(*ptr)
				{
				case 'Y':
					m_tm.tm_year = atoi(buffer) - 1900;
					break;

				case 'y':
					m_tm.tm_year = atoi(buffer);
					break;
				case 'm':
					m_tm.tm_mon = atoi(buffer) - 1;
					bStatus = bStatus && (0 <= m_tm.tm_mon) && (m_tm.tm_mon < 12);
					break;
				case 'd':
					m_tm.tm_mday = atoi(buffer);
					bStatus = bStatus && (1 <= m_tm.tm_mday) && (m_tm.tm_mday <= 31);
					break;
				case 'H':
					m_tm.tm_hour = atoi(buffer);
					bStatus = bStatus && (0 <= m_tm.tm_hour) && (m_tm.tm_hour < 24);
					break;
				case 'M':
					m_tm.tm_min = atoi(buffer);
					bStatus = bStatus && (0 <= m_tm.tm_min) && (m_tm.tm_min < 60);
					break;
				case 'S':
					m_tm.tm_sec = atoi(buffer);
					bStatus = bStatus && (0 <= m_tm.tm_sec) && (m_tm.tm_sec < 60);
					break;

				case '%':
					bStatus = bStatus && (buffer[0] == '%');
					break;
				}
			}
			ptr++;
		}
		else
		{
			bStatus = bStatus && (pInput->Read(buffer, 1) == 1);
			bStatus = bStatus && (buffer[0] == *ptr);
			ptr++;
		}
	}


	pInput->EndRead(bStatus);
	switch (bStatus)
	{
	case FALSE:
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
		break;
	default:
		break;
	}

	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PDatetime::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{ 
	char buffer[256];
	UINT len = strftime(buffer, sizeof(buffer), m_pszFormat, &m_tm);
	BOOL bStatus = ((pOutput->Write(buffer, len)) == len);
	return bStatus?PARSER_SUCCESS:PARSER_ERROR; 
}

RETVALUE PDatetime::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	RETVALUE retvalue = PARSER_SUCCESS;

	if (m_lpStyle & OS_DATA_ERROR) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, (char *)cszError, sizeof(cszError)-1);
	if (m_lpStyle & OS_NULL_VALUE) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Null, NULL, 0);
	else switch (pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Datetime, &m_tm, sizeof(struct tm)))
	{
	case FALSE:
		pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		break;
	default:
		break;
	}

	return retvalue; 
}

RETVALUE PDatetime::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{ 
	RETVALUE retvalue = PARSER_SUCCESS;

	Preselect(this, m_nLevel, pLog);
	switch (pArchive->GetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Datetime, &m_tm, NULL, sizeof(struct tm)))
	{
	case FALSE:
		pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
		break;
	default:
		break;
	}
	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

////////////////////////////////////////////////////////////////
// PMultitext virtual methods

RETVALUE PMultitext::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{ 
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL eot = FALSE;
	UINT i = 0;
	UINT nLine;
	UINT nLineSeparator = strlen(m_pszLineSeparator);
	UINT j;
	char buffer[256];

	Preload(this, m_nLevel, pLog);
	m_nLength = 0;
	pInput->BeginRead();

		pInput->BeginRead();
		eot = pInput->Scanf(m_pszEndOfTextFormat, buffer, &j, sizeof(buffer));
		pInput->EndRead(FALSE);
		
	if (!eot) while ( bStatus && (i < m_maxsize) )
	{

		bStatus = bStatus && (pInput->Scanf(m_pszLineFormat, &m_strText[m_nLength], &nLine, sizeof(m_strText)-m_nLength));
		if (!bStatus) break;
		m_nLength += nLine;
		i++;

		pInput->BeginRead();
		eot = pInput->Scanf(m_pszEndOfTextFormat, buffer, &j, sizeof(buffer));
		pInput->EndRead(FALSE);
		
		if ( eot ) break;

		m_strText[m_nLength++] = '\0';
		bStatus = bStatus && ((pInput->Read(buffer, nLineSeparator)) == nLineSeparator);
		bStatus = bStatus && (strncmp(buffer, m_pszLineSeparator, nLineSeparator) == 0);
	}

	bStatus = bStatus && (m_minsize <= i);

	pInput->EndRead(bStatus);
	switch (bStatus) 
	{
	case FALSE:
		pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
		break;
	default:
		break;
	}

	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PMultitext::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{ 
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;

	UINT nLineSeparator = strlen(m_pszLineSeparator);
	
	for (UINT i = 0 ; bStatus && (i < m_nLength) ; i++)
		if (m_strText[i] != '\0')
		{
			if (bStatus) switch ((pOutput->Write(&m_strText[i], 1)) == 1)
			{
			case FALSE:
				retvalue = PARSER_ERROR;
				bStatus = FALSE;
				break;
			default:
				break;
			}
		}
		else
		{
			if (bStatus) switch ((pOutput->Write(m_pszLineSeparator, nLineSeparator)) == nLineSeparator)
			{
			case FALSE:
				retvalue = PARSER_ERROR;
				bStatus = FALSE;
				break;
			default:
				break;
			}
		}

	return retvalue; 
}

RETVALUE PMultitext::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	RETVALUE retvalue = PARSER_SUCCESS;

	if (m_lpStyle & OS_DATA_ERROR) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, (char *)cszError, sizeof(cszError)-1);
	if (m_lpStyle & OS_NULL_VALUE) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Null, NULL, 0);
	else switch (pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Multitext, m_strText, m_nLength))
	{
	case TRUE:
		break;
	case FALSE:
		retvalue = PARSER_ERROR;
		break;
	}
	return retvalue; 
}

RETVALUE PMultitext::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{ 
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_ERROR;

	Preselect(this, m_nLevel, pLog);
	m_nLength = 0;
	if (bStatus) switch (pArchive->GetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Multitext, m_strText, &m_nLength, sizeof(m_strText)))
	{
	case TRUE:
		break;
	case FALSE:
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
		bStatus = FALSE;
		break;
	}

	if (bStatus) m_strText[m_nLength] = '\0';
	
	UINT pos = 0;

	while ( bStatus && (pos < m_nLength) )
	{
		char *subformat = m_pszLineFormat;
		int i = -1;
	
		bStatus = FALSE;

		retvalue = PARSER_ERROR;

		while ( *subformat )
		{
			sscanf (&m_strText[pos], subformat, &i);
			bStatus = (i != -1) && (m_strText[ pos + i ] == '\0') ;
			if ( bStatus ) 
			{
				pos = pos + i + 1;
				retvalue = PARSER_SUCCESS;
				break;
			}
			while ( *subformat++ );
		}

		if (!bStatus)
		{
			const char cszMessage[] = "***Wrong text line format***";
			pLog->Write(m_pszAttribute, m_nLevel, TLog::Information, 0, m_strText, m_nLength);
			pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszMessage, sizeof(cszMessage)-1);
		}
	}

	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PRule::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{ 
	RETVALUE retvalue = PARSER_NO_DATA_FOUND;
	Preload(this, m_nLevel, pLog);
	char * pszConst = m_pszStreamConstants;
	for (m_nSelection = 0 ; (*pszConst) != '\0' ; m_nSelection++)
	{
		UINT len = strlen(pszConst);
		char buffer[256];
		pInput->BeginRead();
		if ((pInput->Read(buffer, len) == len) && (strncmp(buffer, pszConst, len) == 0))
		{
			pInput->EndRead(TRUE);
			retvalue = PARSER_SUCCESS;
			break;
		}
		pInput->EndRead(FALSE);
		while (*pszConst++ != '\0');
	}

	if (*pszConst == '\0')
	{
		const char cszMessage[] = "***Cannot find option***";
		pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszMessage, sizeof(cszMessage)-1);
	}

	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PRule::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{
	UINT i = m_nSelection;
	char * pszConst = m_pszStreamConstants;
	while (i--) while (*pszConst++);
	UINT len = strlen(pszConst);
	pOutput->Write(pszConst, len);
	return PARSER_SUCCESS; 
}

RETVALUE PRule::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{ 
	if (m_lpStyle & OS_DATA_ERROR) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, (char *)cszError, sizeof(cszError)-1);
	else if (m_lpStyle & OS_NULL_VALUE) pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Null, NULL, 0);
	else
	{
		UINT i = m_nSelection;
		char * pszConst = m_pszSqlConstants;
		while (i--) while (*pszConst++);
		UINT len = strlen(pszConst);
		pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, pszConst, len);
	}
	return PARSER_SUCCESS; 
}

RETVALUE PRule::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{ 
	RETVALUE retvalue = PARSER_SUCCESS;
	UINT len;
	char buffer[256];
	char * pszConst = m_pszSqlConstants;

	Preselect(this, m_nLevel, pLog);
	switch (pArchive->GetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Text, buffer, &len, sizeof(buffer)))
	{
	case FALSE:
		pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
		m_lpStyle |= OS_NULL_VALUE;
		retvalue = PARSER_NO_DATA_FOUND;
		break;
	default:
		for (m_nSelection = 0 ; (*pszConst) && strncmp(buffer, pszConst, len); m_nSelection++)
			while (*pszConst++);

		if (!*pszConst)
		{
			m_lpStyle |= OS_DATA_ERROR;
			retvalue = PARSER_ERROR;

			const char cszMessage[] = "***Wrong option specified***";
			pLog->Write(m_pszAttribute, m_nLevel, TLog::Information, 0, buffer, len);
			pLog->Write(m_pszAttribute, m_nLevel, TLog::Error, 0, (char *)cszMessage, sizeof(cszMessage)-1);
		}
		break;
	}

	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue;
}

