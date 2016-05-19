//////////////////////////////////
// System level dependencies

#include <windows.h>

//////////////////////////////////
// ANSI level dependencies

#include <stdio.h>
#include <time.h>

//////////////////////////////////
// Application level dependencies

#include "tlog.h"

FILE * __logfile = NULL;

const char TFileLog::szError[]       = "Error      ";
const char TFileLog::szWarning[]     = "Warning    ";
const char TFileLog::szInformation[] = "Information";
const char cszEol[] = "\r\n";

BOOL TLog::Create() 
{ 
	m_pStack1 = new char[16000];
	m_pStack2 = new char[64000];
	m_nRows = 0;
	return TRUE; 
}

BOOL TLog::Destroy() 
{
	delete m_pStack2;
	delete m_pStack1;
	return TRUE; 
}

BOOL TLog::BeginWrite(char *pszObjectName, UINT nLevel)
{
	BOOL bStatus = TRUE;
	Push(&m_pStack1, &m_nRows, sizeof(m_nRows));
	m_nRows = 0;
	return bStatus;
}

BOOL TLog::EndWrite(char *pszObjectName, UINT nLevel, int retvalue)
{
	BOOL bStatus = TRUE;
	int type;
	int category;
	char szMessage[1024];
	UINT nMessageLen;
	UINT nPrevRows;

	switch (retvalue)
	{
	case 0:
		while(m_nRows--)
		{
			Pop(&m_pStack2, &nMessageLen, sizeof(UINT));
			Pop(&m_pStack2, szMessage, nMessageLen);
			Pop(&m_pStack2, &category, sizeof(int));
			Pop(&m_pStack2, &type, sizeof(int));
			Pop(&m_pStack2, &nLevel, sizeof(UINT));
			Pop(&m_pStack2, &pszObjectName, sizeof(char *));
		}
		Pop(&m_pStack1, &m_nRows, sizeof(m_nRows));
		break;

	default:
		Pop(&m_pStack1, &nPrevRows, sizeof(m_nRows));
		m_nRows += nPrevRows;
		break;
	}

	return bStatus;
}

BOOL TLog::Write(char *pszObjectName, UINT nLevel, int type, int category, char *pszMessage, UINT nMessageLen)
{
	BOOL bStatus = TRUE;

	Push(&m_pStack2, &pszObjectName, sizeof(char *));
	Push(&m_pStack2, &nLevel, sizeof(UINT));
	Push(&m_pStack2, &type, sizeof(int));
	Push(&m_pStack2, &category, sizeof(int));
	Push(&m_pStack2, pszMessage, nMessageLen);
	Push(&m_pStack2, &nMessageLen, sizeof(UINT));
	m_nRows++;
	return bStatus;
}

BOOL TLog::Push(char **ppStack, void *pBuffer, UINT nSize)
{
	memmove(*ppStack, pBuffer, nSize);
	*ppStack = (*ppStack) + nSize;
	return TRUE;
}

BOOL TLog::Pop(char **ppStack, void *pBuffer, UINT nSize)
{
	*ppStack = (*ppStack) - nSize;
	memmove(pBuffer, *ppStack, nSize);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////
// class TFileLog

TFileLog::TFileLog(FILE *pFile) :
	m_pFile(pFile)
{
}

TFileLog::~TFileLog()
{
}


BOOL TFileLog::Flush()
{
	BOOL bStatus = TRUE;
	char buffer[2048];
	char *pszType;

	char *pszObjectName;
	UINT nLevel;
	int type;
	int category;
	char szMessage[1024];
	UINT nMessageLen;

	while(m_nRows--)
	{
		Pop(&m_pStack2, &nMessageLen, sizeof(UINT));
		Pop(&m_pStack2, szMessage, nMessageLen);
		Pop(&m_pStack2, &category, sizeof(int));
		Pop(&m_pStack2, &type, sizeof(int));
		Pop(&m_pStack2, &nLevel, sizeof(UINT));
		Pop(&m_pStack2, &pszObjectName, sizeof(char *));

		switch (type)
		{
		case Error:       pszType = (char *)szError;       break;
		case Warning:     pszType = (char *)szWarning;     break;
		case Information: pszType = (char *)szInformation; break;
		}

		sprintf(buffer, "%s (%s)  ", pszType, pszObjectName);
		fwrite(buffer, 1, strlen(buffer), m_pFile);
		for ( int i = nMessageLen ; i-- ; ) if (!szMessage[i]) szMessage[i] = '\n';
		fwrite(szMessage, 1, nMessageLen, m_pFile);
		fwrite((char *)cszEol, 1, sizeof(cszEol)-1, m_pFile);
		fflush(m_pFile);
	}

	m_nRows = 0;

	return bStatus;
}
