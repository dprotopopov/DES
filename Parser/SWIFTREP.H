#ifndef __SWIFTREP_H
#define __SWIFTREP_H

//////////////////////////////////////////////////////////////////////////////////
// SWIFT REPORT
// File swiftrep.h
// Copyright © 1996 Asset Information Menegment
// Programmer: Dmitry Protopopov
//////////////////////////////////////////////////////////////////////////
class TShortReport : public TFileReport
{
char m_strMessageType[3];
char m_strSender[12];
char m_strReceiver[12];
char m_strSession[5];
char m_strSequence[7];
struct tm m_tmDate;

public:
TShortReport(FILE *pFile);
~TShortReport();
virtual BOOL SetAttribute(TLog *pLog, char *pszDomain, char *pszAttribute, PRIMARY *pPrimary, SECONDARY **ppSecondary , UINT nSecondary, int type, void * pBuffer, UINT  cbBuffer = 0) ;
virtual BOOL BeginImport(TLog *pLog, PRIMARY *pPrimary);
virtual BOOL EndImport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit = FALSE);
virtual BOOL AddNew(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary , UINT nSecondary);
};

class IShortReport : public TShortReport
{
public:
IShortReport(FILE *pFile);
~IShortReport();
virtual BOOL EndImport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit = FALSE);
};

class OShortReport : public TShortReport
{
struct tm m_tmMessageDate;

public:
OShortReport(FILE *pFile);
~OShortReport();
virtual BOOL SetAttribute(TLog *pLog, char *pszDomain, char *pszAttribute, PRIMARY *pPrimary, SECONDARY **ppSecondary , UINT nSecondary, int type, void * pBuffer, UINT  cbBuffer = 0) ;
virtual BOOL BeginImport(TLog *pLog, PRIMARY *pPrimary);
virtual BOOL EndImport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit = FALSE);
};


//////////////////////////////////////////////////////////////////////////////////

#endif // __SWIFTREP_H
