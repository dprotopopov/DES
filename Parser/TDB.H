#ifndef __TDB_H
#define __TDB_H

typedef ULONG PRIMARY;
typedef ULONG SECONDARY;

class TLog;

/////////////////////////////////////////////////////////////
// Database classes
// File tdb.h
// Copyright © 1996
// Programmer: Dmitry Protopopov
/////////////////////////////////////////////////////////////
class TProDatabase
{
public:

virtual BOOL OpenDomain(TLog *pLog, char *pszDomain) = 0;
virtual BOOL CloseDomain(TLog *pLog, char *pszDomain) = 0;

};

/////////////////////////////////////////////////
class TMonitor : public TProDatabase
{
public:

virtual BOOL GetPrimary(TLog *pLog, char *pszDomain , PRIMARY *pPrimary) = 0;
virtual BOOL GetSecondary(TLog *pLog, char *pszDomain , PRIMARY * pPrimary, SECONDARY **ppSecondary, UINT nSecondary, SECONDARY *pSecondary) = 0;
virtual BOOL SetAttribute(TLog *pLog, char *pszDomain, char *pszAttribute, PRIMARY *pPrimary, SECONDARY **ppSecondary , UINT nSecondary, int type, void * pBuffer, UINT  cbBuffer = 0) = 0;
virtual BOOL AddNew(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary , UINT nSecondary) = 0;
virtual BOOL Update(TLog *pLog, char *pszDomain , PRIMARY *pPrimary, SECONDARY **ppSecondary , UINT nSecondary,  BOOL bCommit) = 0;

virtual BOOL BeginImport(TLog *pLog, PRIMARY *pPrimary) = 0;
virtual BOOL EndImport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit = FALSE) = 0;

};

/////////////////////////////////////////////////////////////////////////////////
class TFileDatabase : public TMonitor
{
struct stkccAttribute
{
int ccAttribute;
};

struct stkAttribute
{
char * pszAttribute;
int type;
void *pBuffer;
UINT cbBuffer;
};

protected:
FILE * m_pFile;
struct stkccAttribute m_stkccAttribute[1000];
struct stkAttribute m_stkAttribute[1000];
int m_sizeccAttribute;

int m_offsAttribute;
int m_ccAttribute;

public:
TFileDatabase(FILE *pFile);
~TFileDatabase();

public:
virtual BOOL OpenDomain(TLog *pLog, char *pszDomain);
virtual BOOL CloseDomain(TLog *pLog, char *pszDomain);

public:
virtual BOOL GetPrimary(TLog *pLog, char *pszDomain , PRIMARY * pPrimary);
virtual BOOL GetSecondary(TLog *pLog, char *pszDomain , PRIMARY * pPrimary, SECONDARY **ppSecondary, UINT nSecondary, SECONDARY *pSecondary) ;
virtual BOOL SetAttribute(TLog *pLog, char *pszDomain, char *pszAttribute, PRIMARY * pPrimary, SECONDARY **ppSecondary, UINT nSecondary,  int type, void * pBuffer, UINT  cbBuffer = 0) ;
virtual BOOL AddNew(TLog *pLog, char *pszDomain , PRIMARY *pPrimary, SECONDARY **ppSecondary , UINT nSecondary) ;
virtual BOOL Update(TLog *pLog, char *pszDomain , PRIMARY *pPrimary, SECONDARY **ppSecondary , UINT nSecondary, BOOL bCommit);

virtual BOOL BeginImport(TLog *pLog, PRIMARY *pPrimary);
virtual BOOL EndImport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit = FALSE);

};

////////////////////////////////////////////////////////////////////////////////////////////////////
class TArchive : public TProDatabase
{
public:

virtual BOOL Fetch(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary, BOOL bSort) = 0;
virtual BOOL GetAttribute(TLog *pLog, char *pszDomain, char *pszAttribute, PRIMARY * pPrimary, SECONDARY **ppSecondary, UINT nSecondary,  int type, void *pBuffer, UINT *pcbBuffer = NULL, UINT cbMaxBuffer = 256) = 0;
virtual BOOL BeginSelect(TLog *pLog, char *pszDomain , PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary , BOOL bSort = FALSE) = 0; 
virtual BOOL EndSelect(TLog *pLog, char *pszDomain , PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) = 0;

virtual BOOL BeginExport(TLog *pLog, PRIMARY *pPrimary) = 0;
virtual BOOL EndExport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit = FALSE) = 0;

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
class TDatabase : public TArchive, public TMonitor
{
public:
enum {Null,Primary,Secondary,Text,Integer,Datetime,Decimal,Multitext};

protected:
static const char szComma[];
static const char szEqual[];
static const char szInsertInto[];
static const char szValues[];
static const char szUpdate[];
static const char szSet[];
static const char szSelect[];
static const char szFrom[];
static const char szWhere[];
static const char szAnd[];
static const char szOrderBy[];
static const char szBeginTrans[];
static const char szCommitTrans[];
static const char szRollbackTrans[];

};

class TReport : public TMonitor
{
};

class TFileReport : public TReport
{
protected:
FILE * m_pFile;

public:
TFileReport(FILE *pFile);
~TFileReport();

public:
virtual BOOL OpenDomain(TLog *pLog, char *pszDomain);
virtual BOOL CloseDomain(TLog *pLog, char *pszDomain);

public:
virtual BOOL GetPrimary(TLog *pLog, char *pszDomain , PRIMARY *pPrimary) ;
virtual BOOL GetSecondary(TLog *pLog, char *pszDomain , PRIMARY * pPrimary, SECONDARY **ppSecondary, UINT nSecondary, SECONDARY *pSecondary) ;
virtual BOOL SetAttribute(TLog *pLog, char *pszDomain, char *pszAttribute, PRIMARY *pPrimary, SECONDARY **ppSecondary , UINT nSecondary, int type, void * pBuffer, UINT  cbBuffer = 0) ;
virtual BOOL AddNew(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary , UINT nSecondary);
virtual BOOL Update(TLog *pLog, char *pszDomain , PRIMARY *pPrimary, SECONDARY **ppSecondary , UINT nSecondary,  BOOL bCommit) ;

virtual BOOL BeginImport(TLog *pLog, PRIMARY *pPrimary);
virtual BOOL EndImport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit = FALSE);

};

//////////////////////////////////////////////////////////////////////////////

#endif // __TDB_H
