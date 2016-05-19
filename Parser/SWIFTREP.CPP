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

#include "tlog.h"
#include "tdb.h"
#include "thash.h"
#include "srv.h"
#include "swiftrep.h"
#include "swiftsrv.h"

const char cszSeparator[] = " ";

TShortReport::TShortReport(FILE *pFile) : TFileReport(pFile)
{
}

TShortReport::~TShortReport()
{
}

BOOL TShortReport::SetAttribute(TLog *pLog, char *pszDomain, char *pszAttribute, PRIMARY *pPrimary, SECONDARY **ppSecondary , UINT nSecondary, int type, void * pBuffer, UINT  cbBuffer)
{
	if (type == TDatabase::Null) return TRUE;
	else if (pszAttribute == hHeader_MessageType) memmove(m_strMessageType, pBuffer, 3);
	else if (pszAttribute == hHeader_Sender) memmove(m_strSender, pBuffer, 12);
	else if (pszAttribute == hHeader_Receiver) memmove(m_strReceiver, pBuffer, 12);
	else if (pszAttribute == hHeader_SessionNumber) sprintf(m_strSession, "%04lu", *(ULONG *)pBuffer);
	else if (pszAttribute == hHeader_SequenceNumber) sprintf(m_strSequence, "%06lu", *(ULONG *)pBuffer);
	else if (pszAttribute == hHeader_MessageDate) memmove(&m_tmDate, pBuffer, sizeof(struct tm));
	return TRUE;
}

BOOL TShortReport::BeginImport(TLog *pLog, PRIMARY *pPrimary)
{
	memset(m_strMessageType, '?', 3);
	memset(m_strSender, '?', 12);
	memset(m_strReceiver, '?', 12);
	memset(m_strSession, '?', 4);
	memset(m_strSequence, '?', 6);

	time_t t;
    time( &t );                /* Get time as long integer. */
    memmove(&m_tmDate, localtime( &t ), sizeof(struct tm)); /* Convert to local time. */

	return TRUE;
}

BOOL TShortReport::EndImport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit)
{
	fwrite(m_strMessageType, 1, 3, m_pFile);
	fwrite(cszSeparator, 1, sizeof(cszSeparator)-1, m_pFile);
	fwrite(m_strSender, 1, 12, m_pFile);
	fwrite(cszSeparator, 1, sizeof(cszSeparator)-1, m_pFile);
	fwrite(m_strReceiver, 1, 12, m_pFile); 
	fwrite(cszSeparator, 1, sizeof(cszSeparator)-1, m_pFile);
	fwrite(m_strSession, 1, 4, m_pFile); 
	fwrite(cszSeparator, 1, sizeof(cszSeparator)-1, m_pFile);
	fwrite(m_strSequence, 1, 6, m_pFile); 
	fwrite(cszSeparator, 1, sizeof(cszSeparator)-1, m_pFile);
	fwrite(asctime(&m_tmDate), 1, 24, m_pFile);
	return TRUE;
}

BOOL TShortReport::AddNew(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary , UINT nSecondary)
{
	return TRUE;
}

IShortReport::IShortReport(FILE *pFile) : TShortReport(pFile)
{
}

IShortReport::~IShortReport()
{
}

BOOL IShortReport::EndImport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit)
{
	const char cszInputPrefix[] = "I ";
	const char cszInputSuffix[] = "";
	fwrite(cszInputPrefix, 1, sizeof(cszInputPrefix)-1, m_pFile);
	TShortReport::EndImport(pLog, pPrimary, bCommit);
	fwrite(cszInputSuffix, 1, sizeof(cszInputSuffix)-1, m_pFile);
	return TRUE;
}

OShortReport::OShortReport(FILE *pFile) : TShortReport(pFile)
{
}

OShortReport::~OShortReport()
{
}

BOOL OShortReport::BeginImport(TLog *pLog, PRIMARY *pPrimary)
{
	memset(&m_tmMessageDate, 0, sizeof(struct tm));
	return TShortReport::BeginImport(pLog, pPrimary);
}

BOOL OShortReport::EndImport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit)
{
	const char cszOutputPrefix[] = "O ";
	const char cszOutputSuffix[] = "";
	fwrite(cszOutputPrefix, 1, sizeof(cszOutputPrefix)-1, m_pFile);
	TShortReport::EndImport(pLog, pPrimary, bCommit);
	fwrite(cszOutputSuffix, 1, sizeof(cszOutputSuffix)-1, m_pFile);
	return TRUE;
}

BOOL OShortReport::SetAttribute(TLog *pLog, char *pszDomain, char *pszAttribute, PRIMARY *pPrimary, SECONDARY **ppSecondary , UINT nSecondary, int type, void * pBuffer, UINT  cbBuffer)
{
	return TShortReport::SetAttribute(pLog, pszDomain, pszAttribute, pPrimary, ppSecondary , nSecondary, type, pBuffer, cbBuffer);
}
