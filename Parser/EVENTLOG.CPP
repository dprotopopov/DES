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
#include "eventlog.h"

/////////////////////////////////

TEventLog::TEventLog(char *pszUNCServerName, char *pszSourceName) : 
	m_pszUNCServerName(pszUNCServerName), 
	m_pszSourceName(pszSourceName)
{
}

TEventLog::~TEventLog() 
{
}

BOOL TEventLog::Create()
{
	m_hEventLog = OpenEventLog(m_pszUNCServerName, m_pszSourceName);
	return (m_hEventLog != NULL) && TLog::Create();
}

BOOL TEventLog::Destroy()
{
	CloseEventLog(m_hEventLog);
	return TLog::Destroy();
}

BOOL TEventLog::Flush()
{
	BOOL bStatus = TRUE;

	char *pszObjectName;
	UINT nLevel;
	UINT nInstance;
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
		Pop(&m_pStack2, &nInstance, sizeof(UINT));
		Pop(&m_pStack2, &nLevel, sizeof(UINT));
		Pop(&m_pStack2, &pszObjectName, sizeof(char *));
	}

	m_nRows = 0;

	return bStatus;
}
