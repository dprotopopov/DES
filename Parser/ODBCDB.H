//
//
//

#ifndef __ODBCDB_H
#define __ODBCDB_H

#include <sql.h>
#include <sqlext.h>

class TLog;
class TMemory;

// Customization for ODBC
// ODBC Enveroment

class TOdbcEnviroment
{
protected:
static UINT m_ccObject;
static HENV m_henv;
HDBC  m_hdbc;
HSTMT m_hstmt;
UCHAR FAR *m_pszDSN;
UCHAR FAR *m_pszUID;
UCHAR FAR *m_pszAuthStr;

public:

TOdbcEnviroment(char *pszDSN, char *pszUID, char *pszAuthStr);
~ TOdbcEnviroment();

protected:
static UINT PreinsertInteger(SLONG *dest, LONG *source) ;
static UINT PostselectInteger(LONG *dest, SLONG *source) ;
static UINT PreinsertMultitext(char *dest, char *source, UINT len) ;
static UINT PostselectMultitext(char *dest, char *source, UINT len) ;
static UINT PreinsertText(char *dest, char *source, UINT len) ;
static UINT PostselectText(char *dest, char *source, UINT len) ;
static UINT PreinsertDecimal(char *dest, char *source, UINT len) ;
static UINT PostselectDecimal(char *dest, char *source, UINT len) ;
static UINT PreinsertDatetime(TIMESTAMP_STRUCT *dest, struct tm *source) ;
static UINT PostselectDatetime(struct tm *dest, TIMESTAMP_STRUCT *source) ;

protected:
static const char szParameter[];
};

////////////////////////////////////////////////////////////////////
// ODBC Log class

class TOdbcLog : public TLog, public TOdbcEnviroment
{
public:
TOdbcLog(char *pszDSN, char *pszUID, char *pszAuthStr, TMemory *pMemory);
~TOdbcLog();

virtual BOOL Flush();
};

//////////////////////////////////////////////////
// ODBC Database class

class TOdbcDatabase : public TDatabase, public TOdbcEnviroment
{
struct stkDomain
{
ODBCBIND_STRUCT * pBindStruct;
char **ppSecondaryNames;
};

struct stkAttribute
{
char * pszSubdomain;
char * pszAttribute;
int type;
void *pBuffer;
UINT cbBuffer;
};

protected:

struct stkDomain m_stkDomain[1000];
struct stkAttribute m_stkAttribute[1000];

// Bind column header
struct bch
{
SWORD fCType;
SWORD fSqlType;
UDWORD cbColDef;
SWORD ibScale;
SDWORD cbValueMax;
SDWORD cbValue;
// char rgbValue[cbValue];
}; 

struct sql
{
UWORD npar;
UCHAR FAR * rgbSqlStr;
SDWORD cbSqlStr;
char * rgbSqlData;
SDWORD cbSqlData;
};

struct sql m_stkSql[1000];
UINT m_sizeDomain;
UINT m_sizeSQL;
UINT m_offsAttribute;
UINT m_ccAttribute;
TMemory * m_pMemory;
REG_STRUCT * m_pRegStruct;
char * m_pszExportSelectFormat;

protected:
char *m_pStack;
void Push(void *pBuffer, UINT nLen);
void Pop(void *pBuffer, UINT nLen);

public:
TOdbcDatabase(char *pszDSN, char *pszUID, char *pszAuthStr, TMemory *pMemory, REG_STRUCT * pRegStruct, char *pszExportSelectFormat);
~TOdbcDatabase();

protected:
BOOL Connect(TLog *pLog);
BOOL Disconnect(TLog *pLog);

//////////////////////////////////////////////////
// Overwrite TProDatabase methods

public:
virtual BOOL OpenDomain(TLog *pLog, char *pszDomain);
virtual BOOL CloseDomain(TLog *pLog, char *pszDomain);

///////////////////////////////////////////////////
// Overwrite TMonitor methods

public:
virtual BOOL GetPrimary(TLog *pLog, char *pszDomain , PRIMARY * pPrimary);
virtual BOOL GetSecondary(TLog *pLog, char *pszDomain, PRIMARY * pPrimary, SECONDARY **ppSecondary, UINT nSecondary, SECONDARY *pSecondary) ;
virtual BOOL SetAttribute(TLog *pLog, char *pszDomain, char *pszAttribute, PRIMARY * pPrimary, SECONDARY **ppSecondary, UINT nSecondary,  int type, void * pBuffer, UINT  cbBuffer = 0);
virtual BOOL AddNew(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) ;
virtual BOOL Update(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary, BOOL bCommit);

virtual BOOL BeginImport(TLog *pLog, PRIMARY * pPrimary);
virtual BOOL EndImport(TLog *pLog, PRIMARY * pPrimary, BOOL bCommit = FALSE);

///////////////////////////////////////////////////
// Overwrite TArchive methods
public:

virtual BOOL Fetch(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary, BOOL bSort) ;
virtual BOOL GetAttribute(TLog *pLog, char *pszDomain, char *pszAttribute, PRIMARY * pPrimary, SECONDARY **ppSecondary, UINT nSecondary, int type, void *pBuffer, UINT *pcbBuffer = NULL, UINT cbMaxBuffer = 256) ;
virtual BOOL BeginSelect(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary , BOOL bSort = FALSE) ; 
virtual BOOL EndSelect(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) ;

virtual BOOL BeginExport(TLog *pLog, PRIMARY *pPrimary);
virtual BOOL EndExport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit = FALSE);

protected:
BOOL ReleaseSQL(TLog * pLog);
void ReleaseSQLError(TLog * pLog);
SECONDARY m_secAccounts;
SECONDARY m_secCharges71;
SECONDARY m_secCharges71mult;
SECONDARY m_secCharges71mmlt;
SECONDARY m_secAmountAdded;
SECONDARY m_secQueries;
SECONDARY m_secAnswers;

static UINT min3(UINT i, UINT j, UINT k);
static char * strappend(char *, char *);

protected:
BOOL m_bStillExecuting;
void WaitForData();
void *m_pBuffer;
SDWORD m_cbBuffer;
ODBCBIND_STRUCT * GetBindStruct() ;
char ** GetSecondaryNames() ;

public:
BOOL AddHistory(TLog * pLog, struct tm *start, struct tm *finish, char *pszCmdLine, ULONG success, ULONG error);
};

///////////////////////////////////////////////////////////////////////////////////////////////	

#endif // __ODBCDB_H