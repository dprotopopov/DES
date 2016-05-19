//////////////////////////////////
// System level dependencies

#include <windows.h>
#include <sql.h>
#include <sqlext.h>

//////////////////////////////////
// ANSI level dependencies

#include <stdio.h>
#include <time.h>

//////////////////////////////////
// Application level dependencies

#include "tio.h"
#include "tdb.h"
#include "tlog.h"
#include "tmemory.h"
#include "thash.h"
#include "pobject.h"
#include "odbcbind.h"
#include "odbcdb.h"

/////////////////////////////////
#define STACK_LEN	16*1024

UINT TOdbcEnviroment::m_ccObject = 0;
HENV TOdbcEnviroment::m_henv;
const char TOdbcEnviroment::szParameter[] = "?";

TOdbcEnviroment::TOdbcEnviroment(char *pszDSN, char *pszUID, char *pszAuthStr)
{
	if (!m_ccObject++) ::SQLAllocEnv(&m_henv);
	m_pszDSN = (UCHAR FAR *)pszDSN;
	m_pszUID = (UCHAR FAR *)pszUID;
	m_pszAuthStr = (UCHAR FAR *)pszAuthStr;
	::SQLAllocConnect(m_henv, &m_hdbc);
}

TOdbcEnviroment::~TOdbcEnviroment()
{
	::SQLFreeConnect(m_hdbc);
	if (!--m_ccObject) ::SQLFreeEnv(m_henv);
}


UINT TOdbcEnviroment::PreinsertInteger(SLONG *dest, LONG *source)
{
	*dest = *(SLONG *)source;
	return sizeof(SLONG);
}

UINT TOdbcEnviroment::PostselectInteger(LONG *dest, SLONG *source)
{
	*dest = *(LONG *)source;
	return sizeof(LONG);
}

UINT TOdbcEnviroment::PreinsertText(char *dest, char *source, UINT len)
{
	memmove(dest, source, len);
	return len;
}

UINT TOdbcEnviroment::PostselectText(char *dest, char *source, UINT len)
{
	char ch;

	while (len-- && (((ch = source[len]) == ' ') || (ch == '\0')));
	len++;

	memmove(dest, source, len);
	return len;
}

UINT TOdbcEnviroment::PreinsertMultitext(char *dest, char *source, UINT len)
{
	UINT len2 = 0;
	while (len--)
	{
		if((*source) == '\0')
		{
			dest[len2++] = '\r';
			dest[len2++] = '\n';
			source++;
		}
		else
			dest[len2++] = *source++;
	}

	return len2;
}


UINT TOdbcEnviroment::PostselectMultitext(char *dest, char *source, UINT len)
{
	UINT len2 = 0;

	while (len--)
	{
		switch(*source)
		{
		case '\r':
			if (len && (source[1] == '\n'))
			{
				len--;
				source++;
			}

		case '\n':
			source++;
			while (len2-- && (dest[len2] == ' '));
			len2++;
			dest[len2++] = '\0';
			break;

		default:
			dest[len2++] = *source++;
			break;
		}
	}

	while(len2-- && ((dest[len2] == '\0') || (dest[len2] == ' ')));
	len2++;

	return len2;
}

UINT TOdbcEnviroment::PreinsertDecimal(char *dest, char *source, UINT len)
{
	memmove(dest, source, len);
	return len;
}

UINT TOdbcEnviroment::PostselectDecimal(char *dest, char *source, UINT len)
{
	memmove(dest, source, len);
	return len;
}

UINT TOdbcEnviroment::PreinsertDatetime(TIMESTAMP_STRUCT *dest, struct tm *source)
{
	dest->year = source->tm_year + 1900;
	dest->month = source->tm_mon + 1;
	dest->day = source->tm_mday;
	dest->hour = source->tm_hour;
	dest->minute = source->tm_min;
	dest->second = source->tm_sec;
	dest->fraction = 0;

	return sizeof(TIMESTAMP_STRUCT);
}

UINT TOdbcEnviroment::PostselectDatetime(struct tm *dest, TIMESTAMP_STRUCT *source)
{
	dest->tm_year = source->year - 1900;
	dest->tm_mon = source->month - 1;
	dest->tm_mday = source->day;
	dest->tm_hour = source->hour;
	dest->tm_min = source->minute;
	dest->tm_sec = source->second;

	return sizeof(struct tm);
}

///////////////////////////////////////////////////////////////////////////

TOdbcLog::TOdbcLog(char *pszDSN, char *pszUID, char *pszAuthStr, TMemory *pMemory)
 : TOdbcEnviroment(pszDSN, pszUID, pszAuthStr)
{
}

TOdbcLog::~TOdbcLog()
{
}

TOdbcLog::Flush()
{
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////

char * _top_level[] = {
	"message_desc",
	"history",
	NULL };

char * _parent_of_accounts[] = {
	"MT520","MT521","MT522","MT523","MT524","MT526",
	"MT530","MT531","MT532","MT533","MT534",
	"MT550","MT551","MT552","MT553","MT554","MT555","MT556","MT557","MT559",
	"MT560","MT560","MT561","MT562","MT563",
	"MT570","MT571","MT572","MT573",
	"MT590","MT591","MT592","MT595","MT596","MT599",
	NULL };

char * _parent_of_charges71[] = {
	"MT520","MT521","MT522","MT523","MT524","MT526",
	"MT530","MT531","MT532","MT533","MT534",
	"MT550","MT551","MT552","MT553","MT554","MT555","MT556","MT557","MT559",
	"MT560","MT560","MT561","MT562","MT563",
	"MT570","MT571","MT572","MT573",
	"MT590","MT591","MT592","MT595","MT596","MT599",
	NULL };

char * _parent_of_charges71mult[] = {
	"instr_acct",
	"instr_acct55",
	"derinstr_acct55",
	"MT554sub",
	"MT559sub",
	"derinstr_56",
	"MT56instr",
	"MT56instr_a",
	"MT563sb",
	"MT571sub",
	"MT572sub",
	"MT573subB",
	"MT573subC",
	NULL };

char * _parent_of_charges71mmlt[] = {
	"MT563sb1",
	NULL };

char * _parent_of_queries[] = {
	"MT595",
	NULL };

char * _parent_of_answers[] = {
	"MT596",
	NULL };

char * _parent_of_amountadded[] = {
	"MT557",
	NULL };

THashArray top_level(_top_level);
THashArray parent_of_accounts(_parent_of_accounts);
THashArray parent_of_queries(_parent_of_queries);
THashArray parent_of_answers(_parent_of_answers);
THashArray parent_of_amountadded(_parent_of_amountadded);
THashArray parent_of_charges71(_parent_of_charges71);
THashArray parent_of_charges71mult(_parent_of_charges71mult);
THashArray parent_of_charges71mmlt(_parent_of_charges71mmlt);

char szAccounts[] = "accounts";
char szCharges71[] = "charges_71";
char szCharges71mult[] = "charges_71mult";
char szCharges71mmlt[] = "charges_71mmlt";
char szQueries[] = "queries";
char szAnswers[] = "answers";
char szAmountAdded[] = "amount_added";

/////////////////////////////////////////////////////////

char * TOdbcDatabase::strappend(char *dest, char *src)
{
	while( *src ) *dest++ = *src++;
	return dest;
}

//////////////////////////////////////////////////////////

const char cszError[]           = "Error";
const char cszInvalidHandle[]   = "Invalid handle";
const char cszSuccess[]         = "Success";
const char cszSuccessWithInfo[] = "Success with info";
const char cszNoDataFound[]     = "No data found";
const char cszNeedData[]        = "Need data";

/////////////////////////////////////////////////////////

const char szSQLBindParameter[] = "SQLBindParameter";
const char szSQLError[]         = "SQLError";
const char szSQLExecute[]       = "SQLExecute";
const char szSQLPrepare[]       = "SQLPrepare";

/////////////////////////////////////////////////////////

void TOdbcDatabase::ReleaseSQLError(TLog *pLog)
{
	UCHAR szSqlState[256];
	SDWORD fNativeError;
	UCHAR cszErrorMsg[SQL_MAX_MESSAGE_LENGTH];
	SWORD cbErrorMsg;
	RETCODE retcode;
	char buffer[256];

	retcode = ::SQLError(m_henv, m_hdbc, m_hstmt, (UCHAR FAR *)szSqlState, &fNativeError, (UCHAR FAR *)cszErrorMsg, SQL_MAX_MESSAGE_LENGTH-1, &cbErrorMsg);

	switch(retcode)
	{
	case SQL_SUCCESS:
	case SQL_SUCCESS_WITH_INFO:
		sprintf(buffer, "State = %s;Native = %ld;Error = %s", szSqlState, fNativeError, cszErrorMsg);
		pLog->Write((char *)szSQLError, 0, TLog::Warning, 0, buffer, strlen(buffer));
		break;

	case SQL_NO_DATA_FOUND:
		pLog->Write((char *)szSQLError, 0, TLog::Information, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
		break;

	case SQL_ERROR:
		pLog->Write((char *)szSQLError, 0, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		break;

	case SQL_INVALID_HANDLE:
		pLog->Write((char *)szSQLError, 0, TLog::Error, 0, (char *)cszInvalidHandle, sizeof(cszInvalidHandle)-1);
		break;
	}
}

BOOL TOdbcDatabase::ReleaseSQL(TLog *pLog)
{
	UINT i;
	BOOL bStatus = TRUE;
	UWORD ipar;
	char * pSqlData;
	RETCODE retcode;

	for ( i = m_sizeSQL ; bStatus && (i--) ; )
	{
		pLog->Write((char *)szSQLPrepare, 0, TLog::Information, 0, (char *)m_stkSql[i].rgbSqlStr, (UINT)m_stkSql[i].cbSqlStr);
		retcode = ::SQLPrepare(m_hstmt, (UCHAR FAR *)(m_stkSql[i].rgbSqlStr), m_stkSql[i].cbSqlStr);

		switch(retcode)
		{
		case SQL_SUCCESS:

#if defined(_DEBUG)
			pLog->Write((char *)szSQLPrepare, 0, TLog::Information, 0, (char *)cszSuccess, sizeof(cszSuccess)-1);
#endif

			break;

		case SQL_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
			pLog->Write((char *)szSQLPrepare, 0, TLog::Warning, 0, (char *)cszSuccessWithInfo, sizeof(cszSuccessWithInfo)-1);
			ReleaseSQLError(pLog);
#endif
			
			break;

		case SQL_STILL_EXECUTING:
			break;

		case SQL_ERROR:

			pLog->Write((char *)szSQLPrepare, 0, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			ReleaseSQLError(pLog);
			bStatus = FALSE;
			break;

		case SQL_INVALID_HANDLE:

			pLog->Write((char *)szSQLPrepare, 0, TLog::Error, 0, (char *)cszInvalidHandle, sizeof(cszInvalidHandle)-1);
			ReleaseSQLError(pLog);
			bStatus = FALSE;
			break;
		};

		pSqlData = m_stkSql[i].rgbSqlData;

		for ( ipar = 1 ; bStatus && (ipar <= m_stkSql[i].npar) ; ipar++)
		{
			SWORD fCType = ((struct bch *)pSqlData)->fCType;
			SWORD fSqlType = ((struct bch *)pSqlData)->fSqlType;
			UDWORD cbColDef;
			SWORD ibScale = ((struct bch *)pSqlData)->ibScale;
			PTR rgbValue = (PTR)(pSqlData + sizeof(struct bch));
			SDWORD FAR * pcbValue = (SDWORD FAR *)&(((struct bch *)pSqlData)->cbValue);

			switch (fSqlType)
			{
			case SQL_LONGVARBINARY:
			case SQL_LONGVARCHAR:
				cbColDef = *pcbValue;
				break;
			default:
				cbColDef = ((struct bch *)pSqlData)->cbColDef;
				break;
			}

			retcode = ::SQLBindParameter(m_hstmt, ipar, SQL_PARAM_INPUT, fCType, fSqlType, cbColDef, ibScale, rgbValue, *pcbValue, pcbValue);

			switch(retcode)
			{
			case SQL_SUCCESS:

#if defined(_DEBUG)
				pLog->Write((char *)szSQLBindParameter, 0, TLog::Information, 0, (char *)cszSuccess, sizeof(cszSuccess)-1);
#endif
				break;

			case SQL_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
				pLog->Write((char *)szSQLBindParameter, 0, TLog::Warning, 0, (char *)cszSuccessWithInfo, sizeof(cszSuccessWithInfo)-1);
				ReleaseSQLError(pLog);
#endif

				break;

			case SQL_ERROR:

				pLog->Write((char *)szSQLBindParameter, 0, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
				ReleaseSQLError(pLog);
				bStatus = FALSE;
				break;

			case SQL_INVALID_HANDLE:

				pLog->Write((char *)szSQLBindParameter, 0, TLog::Error, 0, (char *)cszInvalidHandle, sizeof(cszInvalidHandle)-1);
				ReleaseSQLError(pLog);
				bStatus = FALSE;
				break;
			};

			pSqlData += sizeof(struct bch) + *pcbValue;
		}

		if (bStatus)
		{
			retcode = ::SQLExecute(m_hstmt);

			switch(retcode)
			{
			case SQL_SUCCESS:

#if defined(_DEBUG)
				pLog->Write((char *)szSQLExecute, 0, TLog::Information, 0, (char *)cszSuccess, sizeof(cszSuccess)-1);
#endif

				break;

			case SQL_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
				pLog->Write((char *)szSQLExecute, 0, TLog::Information, 0, (char *)cszSuccessWithInfo, sizeof(cszSuccessWithInfo)-1);
				ReleaseSQLError(pLog);
#endif

				break;

			case SQL_STILL_EXECUTING:

				m_bStillExecuting = TRUE;
				break;

			case SQL_NEED_DATA:

				pLog->Write((char *)szSQLExecute, 0, TLog::Error, 0, (char *)cszNeedData, sizeof(cszNeedData)-1);
				bStatus = FALSE;
				break;

			case SQL_ERROR:

				pLog->Write((char *)szSQLExecute, 0, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
				ReleaseSQLError(pLog);
				bStatus = FALSE;
				break;

			case SQL_INVALID_HANDLE:

				pLog->Write((char *)szSQLExecute, 0, TLog::Error, 0, (char *)cszInvalidHandle, sizeof(cszInvalidHandle)-1);
				ReleaseSQLError(pLog);
				bStatus = FALSE;
				break;
			}
		}

		retcode = ::SQLFreeStmt(m_hstmt, SQL_UNBIND);
		retcode = ::SQLFreeStmt(m_hstmt, SQL_RESET_PARAMS);
		retcode = ::SQLFreeStmt(m_hstmt, SQL_CLOSE);
	}

	for ( i = m_sizeSQL ; i-- ; ) 
	{
		m_pMemory->Free(m_stkSql[i].rgbSqlStr, (UINT)m_stkSql[i].cbSqlStr);
		m_pMemory->Free(m_stkSql[i].rgbSqlData, (UINT)m_stkSql[i].cbSqlData);
	}

	m_sizeSQL = 0;

	return bStatus;
}

TOdbcDatabase::TOdbcDatabase(char *pszDSN, char *pszUID, char *pszAuthStr, TMemory *pMemory, REG_STRUCT *pRegStruct, char * pszExportSelectFormat)
 : TOdbcEnviroment(pszDSN, pszUID, pszAuthStr) ,
	m_pMemory (pMemory),
	m_pRegStruct (pRegStruct),
	m_pszExportSelectFormat (pszExportSelectFormat),
	m_sizeSQL (0),
	m_offsAttribute (0),
	m_ccAttribute (0)
{
	m_sizeDomain = sizeof(m_stkDomain)/sizeof(struct stkDomain);
	m_pMemory->Malloc((void **)&m_pStack, STACK_LEN);
}

TOdbcDatabase::~TOdbcDatabase()
{
	m_pMemory->Free(m_pStack, STACK_LEN);
}

//////////////////////////////////////////////////
// Overwrite TDatabase methods

BOOL TOdbcDatabase::OpenDomain(TLog *pLog, char *pszDomain)
{
	if (pszDomain[0] == ':') return TRUE;

	REG_STRUCT * pRegStruct = m_pRegStruct;
	char * ptr;
	BOOL bStatus = FALSE;

	while ((ptr = (pRegStruct->pszDomain)) && !(bStatus = (strcmp(pszDomain, ptr) == 0)) )
	{
		pRegStruct++;
	}

	if (bStatus)
	{
		m_sizeDomain--;
		struct stkDomain * pstkDomain = &m_stkDomain[m_sizeDomain];

		pstkDomain->pBindStruct = pRegStruct->pBindStruct;
		pstkDomain->ppSecondaryNames = pRegStruct->ppSecondaryNames;
	}

	return bStatus;
}

BOOL TOdbcDatabase::CloseDomain(TLog *pLog, char *pszDomain)
{
	if (pszDomain[0] == ':') return TRUE;
	m_sizeDomain++;
	return TRUE;
}

ODBCBIND_STRUCT * TOdbcDatabase::GetBindStruct() { return m_stkDomain[m_sizeDomain].pBindStruct; }
char ** TOdbcDatabase::GetSecondaryNames() { return m_stkDomain[m_sizeDomain].ppSecondaryNames; }

///////////////////////////////////////////////////
// Overwrite TMonitor methods

BOOL TOdbcDatabase::GetPrimary(TLog *pLog, char *pszDomain, PRIMARY *pPrimary)
{
	RETCODE retcode;
	SLONG Primary;
	SDWORD cbDomain;
	SDWORD cbPrimary;
	BOOL bStatus = TRUE;

	UCHAR buffer[30];
	static UCHAR rgbSqlStr[] = "{call GetNextID(?)}";

	strcpy((char *)buffer, pszDomain);
	AnsiUpper((char *)buffer);

	cbDomain = SQL_NTS;
	cbPrimary = sizeof(SLONG);

	retcode = ::SQLPrepare(m_hstmt, rgbSqlStr, sizeof(rgbSqlStr)-1);
	retcode = ::SQLBindParameter(m_hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 30, 0, &buffer[0], 0, &cbDomain);
	retcode = ::SQLExecute(m_hstmt);
	retcode = ::SQLFetch(m_hstmt);
	retcode = ::SQLGetData(m_hstmt, 1, SQL_C_SLONG, &Primary, sizeof(Primary), &cbPrimary);
	retcode = ::SQLFreeStmt(m_hstmt, SQL_RESET_PARAMS);
	retcode = ::SQLFreeStmt(m_hstmt, SQL_CLOSE);

	*pPrimary = (PRIMARY)Primary;

	return bStatus;
}

BOOL TOdbcDatabase::GetSecondary(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary, SECONDARY *pSecondary)
{
	     if (strcmp(pszDomain, szAccounts) == 0) *pSecondary = ++m_secAccounts;
	else if (strcmp(pszDomain, szCharges71) == 0) *pSecondary = ++m_secCharges71;
	else if (strcmp(pszDomain, szCharges71mult) == 0) *pSecondary = ++m_secCharges71mult;
	else if (strcmp(pszDomain, szCharges71mmlt) == 0) *pSecondary = ++m_secCharges71mmlt;
	else if (strcmp(pszDomain, szQueries) == 0) *pSecondary = ++m_secQueries;
	else if (strcmp(pszDomain, szAnswers) == 0) *pSecondary = ++m_secAnswers;
	else if (strcmp(pszDomain, szAmountAdded) == 0) *pSecondary = ++m_secAmountAdded;
	else (*pSecondary)++;

	return TRUE;
}

BOOL TOdbcDatabase::SetAttribute(TLog *pLog, char *pszDomain, char *pszAttribute, PRIMARY * pPrimary, SECONDARY **ppSecondary, UINT nSecondary, int type, void * pBuffer, UINT  cbBuffer)
{
	if ((*(char *)pszAttribute == '_') || (type == TDatabase::Null))
		return TRUE;

	struct stkAttribute * pstkAttribute
		= &m_stkAttribute[m_offsAttribute + m_ccAttribute++];

	pstkAttribute->pszSubdomain = pszDomain;
	pstkAttribute->pszAttribute = pszAttribute;
	pstkAttribute->type = type;
	pstkAttribute->pBuffer = pBuffer;
	pstkAttribute->cbBuffer = cbBuffer;

	return TRUE;
}

BOOL TOdbcDatabase::AddNew(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	if (pszDomain[0] == ':') return TRUE;
	if (parent_of_accounts.InHashArray(pszDomain)) m_secAccounts = 0;
	if (parent_of_charges71.InHashArray(pszDomain)) m_secCharges71 = 0;
	if (parent_of_queries.InHashArray(pszDomain)) m_secQueries = 0;
	if (parent_of_answers.InHashArray(pszDomain)) m_secAnswers = 0;
	if (parent_of_amountadded.InHashArray(pszDomain)) m_secAmountAdded = 0;
	if (parent_of_charges71mult.InHashArray(pszDomain)) m_secCharges71mult = 0;
	if (parent_of_charges71mmlt.InHashArray(pszDomain)) m_secCharges71mmlt = 0;

	UINT i;
	UCHAR rgbSqlStr[16*1024];
	char * pSqlStr = (char *)rgbSqlStr;
	char ** ppSecondaryNames = GetSecondaryNames();
	char ulbuff[32];

	Push(&m_ccAttribute, sizeof(m_ccAttribute));
	m_offsAttribute += m_ccAttribute;
	m_ccAttribute = 0;

	if (strcmp(pszDomain, "message_desc") != 0) return TRUE;

	pSqlStr = strappend (pSqlStr, (char *)szUpdate);
	pSqlStr = strappend (pSqlStr, pszDomain);
	pSqlStr = strappend (pSqlStr, (char *)szSet);
	pSqlStr = strappend (pSqlStr, "msg_load_f=0");
	pSqlStr = strappend (pSqlStr, (char *)szWhere);
	pSqlStr = strappend (pSqlStr, "id");
	pSqlStr = strappend (pSqlStr, (char *)szEqual);
	pSqlStr = strappend (pSqlStr, _ultoa(*pPrimary, ulbuff, 10));

	for ( i = nSecondary; i-- ; )
	{
		pSqlStr = strappend (pSqlStr, (char *)szAnd);
		pSqlStr = strappend (pSqlStr, ppSecondaryNames[i]);
		pSqlStr = strappend (pSqlStr, (char *)szEqual);
		pSqlStr = strappend (pSqlStr, _ultoa(*(ppSecondary[i]), ulbuff, 10));
	}

	m_stkSql[m_sizeSQL].npar = 0;

	size_t nSqlStr = (size_t)(((ULONG)pSqlStr) - ((ULONG)rgbSqlStr));
	m_pMemory->Malloc((void **)&(m_stkSql[m_sizeSQL].rgbSqlStr), nSqlStr);
	memmove(m_stkSql[m_sizeSQL].rgbSqlStr, rgbSqlStr, nSqlStr);

	m_stkSql[m_sizeSQL].cbSqlStr = (SDWORD)nSqlStr;
	m_pMemory->Malloc((void **)&(m_stkSql[m_sizeSQL].rgbSqlData), 0);
	m_stkSql[m_sizeSQL].cbSqlData = 0;

	m_sizeSQL++;

	return TRUE;
}

BOOL TOdbcDatabase::Update(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary, BOOL bCommit)
{
	if (pszDomain[0] == ':') return TRUE;

	if (!bCommit)
	{
		Pop(&m_ccAttribute, sizeof(m_ccAttribute));
		m_offsAttribute -= m_ccAttribute;
		return TRUE;
	}

	UCHAR rgbSqlStr[16*1024];
	char rgbSqlData[16*1024];
	UCHAR rgbSqlParams[8*1024];
	UINT npar = 0;
	char * pSqlStr = (char *) rgbSqlStr;
	char * pSqlData = (char *) rgbSqlData;
	char * pSqlParams = (char *) rgbSqlParams;
	struct stkAttribute * pstkAttribute;
	char ulbuff[32];

	BOOL bStatus = TRUE;
	UINT i;

	BOOL bRelease = top_level.InHashArray(pszDomain);
	BOOL bLoad = (strcmp(pszDomain, "message_desc") == 0);
	char **ppszSecondaryNames = GetSecondaryNames();

	pSqlStr = strappend (pSqlStr, (char *)szInsertInto);
	while ( *pszDomain ) *pSqlStr++ = *pszDomain++;
	pSqlStr = strappend (pSqlStr, "(id");

	for ( i = 0; i < nSecondary ; i++ )
	{
		pSqlStr = strappend (pSqlStr, (char *)szComma);
		pSqlStr = strappend (pSqlStr, ppszSecondaryNames[i]);
	}

	if ( *++pszDomain )
	{
		char ch;
		do
		{
			pSqlStr = strappend (pSqlStr, (char *)szComma);
			while ( (ch = *pszDomain++) != '=' ) *pSqlStr++ = ch;
			pSqlParams = strappend (pSqlParams, (char *)szComma);
			while ( (ch = *pszDomain++) && (ch != ',') ) *pSqlParams++ = ch;
		} while (ch == ',');
	}

	if (bLoad)
	{
		pSqlStr = strappend (pSqlStr, (char *)szComma);
		pSqlStr = strappend (pSqlStr, "msg_load_f");
		pSqlParams = strappend (pSqlParams, (char *)szComma);
		pSqlParams = strappend (pSqlParams, "1");
	}


	while (m_ccAttribute--)
	{
		pstkAttribute = &m_stkAttribute[m_offsAttribute + m_ccAttribute];
		char * pszSubdomain = pstkAttribute->pszSubdomain;
		char * pszAttribute = pstkAttribute->pszAttribute;
		char * ptrA;
		char * ptrD;
		ODBCBIND_STRUCT * pBindStruct = GetBindStruct();

		bStatus = FALSE;

		while ( ((ptrA = pBindStruct->pszAttribute) != NULL) && !(bStatus = ((((ptrD = pBindStruct->pszSubdomain) == NULL) || (ptrD == pszSubdomain)) && (ptrA == pszAttribute))) )
		{
			pBindStruct++;
		}
	
		if (!bStatus) 
		{
			char buffer[256];
			sprintf(buffer, "Can not find attribute %s in resigtration database", pszAttribute);
			pLog->Write("DEVELOPMENT", 0, TLog::Error, 0, buffer, strlen(buffer));
			for ( i = m_sizeSQL ; i-- ; ) 
			{
				m_pMemory->Free(m_stkSql[i].rgbSqlStr, (UINT)m_stkSql[i].cbSqlStr);
				m_pMemory->Free(m_stkSql[i].rgbSqlData, (UINT)m_stkSql[i].cbSqlData);
			}

			m_sizeSQL = 0;
			Pop(&m_ccAttribute, sizeof(m_ccAttribute));
			m_offsAttribute -= m_ccAttribute;
			return FALSE;
		}

		pSqlStr = strappend (pSqlStr, (char *)szComma);
		pSqlStr = strappend (pSqlStr, pBindStruct->pszColumn);
		pSqlParams = strappend (pSqlParams, (char *)szComma);
		pSqlParams = strappend (pSqlParams, pBindStruct->pszParameter);
		((struct bch *)pSqlData)->fCType     = pBindStruct->fCType;
		((struct bch *)pSqlData)->fSqlType   = pBindStruct->fSqlType;
		((struct bch *)pSqlData)->cbColDef   = pBindStruct->cbColDef;
		((struct bch *)pSqlData)->ibScale    = pBindStruct->ibScale;
		((struct bch *)pSqlData)->cbValueMax = pBindStruct->cbValueMax;
		switch (pstkAttribute->type)
		{
		case TDatabase::Integer:
			((struct bch *)pSqlData)->cbValue = PreinsertInteger((SLONG *)(pSqlData + sizeof(struct bch)), (LONG *)(pstkAttribute->pBuffer));
			pSqlData += sizeof(struct bch) + (((struct bch *)pSqlData)->cbValue);
			npar++;
			break;

		case TDatabase::Datetime:
			((struct bch *)pSqlData)->cbValue = PreinsertDatetime((TIMESTAMP_STRUCT *)(pSqlData + sizeof(struct bch)), (struct tm *)(pstkAttribute->pBuffer));
			pSqlData += sizeof(struct bch) + (((struct bch *)pSqlData)->cbValue);
			npar++;
			break;

		case TDatabase::Text:
			((struct bch *)pSqlData)->cbValue = PreinsertText((char *)(pSqlData + sizeof(struct bch)), (char *)(pstkAttribute->pBuffer), (pstkAttribute->cbBuffer));
			pSqlData += sizeof(struct bch) + (((struct bch *)pSqlData)->cbValue);
			npar++;
			break;

		case TDatabase::Multitext:
			((struct bch *)pSqlData)->cbValue = PreinsertMultitext((char *)(pSqlData + sizeof(struct bch)), (char *)(pstkAttribute->pBuffer), (pstkAttribute->cbBuffer));
			pSqlData += sizeof(struct bch) + (((struct bch *)pSqlData)->cbValue);
			npar++;
			break;

		case TDatabase::Decimal:
			((struct bch *)pSqlData)->cbValue = PreinsertDecimal((char *)(pSqlData + sizeof(struct bch)), (char *)(pstkAttribute->pBuffer), (pstkAttribute->cbBuffer));
			pSqlData += sizeof(struct bch) + (((struct bch *)pSqlData)->cbValue);
			npar++;
			break;
		}
	}

	pSqlStr = strappend (pSqlStr, ")");
	pSqlStr = strappend (pSqlStr, (char *)szValues);
	pSqlStr = strappend (pSqlStr, "(");
	pSqlStr = strappend (pSqlStr, _ultoa(*pPrimary, ulbuff, 10));

	for ( i = 0; i < nSecondary ; i++ )
	{
		pSqlStr = strappend (pSqlStr, (char *)szComma);
		pSqlStr = strappend (pSqlStr, _ultoa(*(ppSecondary[i]), ulbuff, 10));
	}

	size_t nSqlParams = (size_t)(((ULONG)pSqlParams) - ((ULONG)rgbSqlParams));
	memmove(pSqlStr, rgbSqlParams, nSqlParams);
	pSqlStr += nSqlParams;
	pSqlStr = strappend (pSqlStr, ")");

	m_stkSql[m_sizeSQL].npar = npar;

	size_t nSqlStr = (size_t)(((ULONG)pSqlStr) - ((ULONG)rgbSqlStr));
	m_pMemory->Malloc((void **)&(m_stkSql[m_sizeSQL].rgbSqlStr), nSqlStr);
	memmove(m_stkSql[m_sizeSQL].rgbSqlStr, rgbSqlStr, nSqlStr);
	m_stkSql[m_sizeSQL].cbSqlStr = (SDWORD)nSqlStr;

	UINT nSqlData = ((UINT)pSqlData) - ((UINT)rgbSqlData);
	m_pMemory->Malloc((void **)&(m_stkSql[m_sizeSQL].rgbSqlData), nSqlData);
	memmove(m_stkSql[m_sizeSQL].rgbSqlData, rgbSqlData, nSqlData);
	m_stkSql[m_sizeSQL].cbSqlData = (SDWORD)nSqlData;
	m_sizeSQL++;


	Pop(&m_ccAttribute, sizeof(m_ccAttribute));
	m_offsAttribute -= m_ccAttribute;

	if (!bRelease) return TRUE;
	bStatus = ReleaseSQL(pLog);

	return bStatus;
}


BOOL TOdbcDatabase::AddHistory(TLog *pLog, struct tm *start, struct tm *finish, char *pszCmdLine, ULONG success, ULONG error)
{
	BOOL bStatus = TRUE;
	BOOL bConnect = FALSE;
	static char szHistory[] = "history\0";
	static char szSqlStr[] = "INSERT INTO history(id,start_date,end_date,command_s,success_cnt,error_cnt) VALUES (?,?,?,?,?,?)";

	PRIMARY Primary;
	TIMESTAMP_STRUCT dsStart;
	TIMESTAMP_STRUCT dsFinish;
	RETCODE retcode;

	SDWORD cbPrimary = sizeof(PRIMARY);
	SDWORD cbCmdLine = SQL_NTS;
	SDWORD cbStart = PreinsertDatetime(&dsStart, start);
	SDWORD cbFinish = PreinsertDatetime(&dsFinish, finish);
	SDWORD cbSuccess = sizeof(ULONG);
	SDWORD cbError = sizeof(ULONG);

	bStatus = bStatus && (bConnect = Connect(pLog));
	bStatus = bStatus && GetPrimary(pLog, szHistory, &Primary);
	retcode = ::SQLPrepare(m_hstmt, (UCHAR FAR *)szSqlStr, SQL_NTS);
	retcode = ::SQLBindParameter(m_hstmt, 1, SQL_PARAM_INPUT, SQL_C_ULONG,     SQL_INTEGER,   0,   0, (PTR)&Primary,   0, &cbPrimary);
	retcode = ::SQLBindParameter(m_hstmt, 2, SQL_PARAM_INPUT, SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, (PTR)&dsStart,   0, &cbStart);
	retcode = ::SQLBindParameter(m_hstmt, 3, SQL_PARAM_INPUT, SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, (PTR)&dsFinish,  0, &cbFinish);
	retcode = ::SQLBindParameter(m_hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR,      SQL_CHAR,      254, 0, (PTR)pszCmdLine, 0, &cbCmdLine);
	retcode = ::SQLBindParameter(m_hstmt, 5, SQL_PARAM_INPUT, SQL_C_ULONG,     SQL_INTEGER,   0,   0, (PTR)&success,   0, &cbSuccess);
	retcode = ::SQLBindParameter(m_hstmt, 6, SQL_PARAM_INPUT, SQL_C_ULONG,     SQL_INTEGER,   0,   0, (PTR)&error,     0, &cbError);
	retcode = ::SQLExecute(m_hstmt);
	retcode = ::SQLFreeStmt(m_hstmt, SQL_RESET_PARAMS);
	retcode = ::SQLFreeStmt(m_hstmt, SQL_CLOSE);
	if (bConnect) bStatus = Disconnect(pLog) && bStatus;
	return bStatus;
}

BOOL TOdbcDatabase::BeginExport(TLog *pLog, PRIMARY *pPrimary)
{
	static char szUpdateFmt[] = "UPDATE message_desc SET msg_busy_f=1 WHERE id=%lu";


	BOOL bStatus = TRUE;
	BOOL bConnect = FALSE;
	UCHAR szSqlStr[512];
	SDWORD cbPrimary;
	RETCODE retcode;

	bStatus = bStatus && (bConnect = Connect(pLog));
	if (!bConnect) return FALSE;

	retcode = ::SQLPrepare(m_hstmt, (UCHAR FAR *)szBeginTrans, SQL_NTS);
	retcode = ::SQLExecute(m_hstmt);
	retcode = ::SQLFreeStmt(m_hstmt,SQL_CLOSE);

	sprintf((char *)szSqlStr, m_pszExportSelectFormat, *pPrimary);
	retcode = ::SQLPrepare(m_hstmt, szSqlStr, SQL_NTS);
	switch (retcode)
	{
	case SQL_SUCCESS:

		break;

	case SQL_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
		pLog->Write((char *)szSQLPrepare, 0, TLog::Information, 0, (char *)szSqlStr, strlen((char *)szSqlStr));
		ReleaseSQLError(pLog);
#endif

		break;

	case SQL_STILL_EXECUTING:

		m_bStillExecuting = TRUE;
		break;

	case SQL_ERROR:

		pLog->Write((char *)szSQLPrepare, 0, TLog::Information, 0, (char *)szSqlStr, strlen((char *)szSqlStr));
		pLog->Write((char *)szSQLPrepare, 0, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		ReleaseSQLError(pLog);
		bStatus = FALSE;
		break;

	case SQL_INVALID_HANDLE:

		pLog->Write((char *)szSQLPrepare, 0, TLog::Information, 0, (char *)szSqlStr, strlen((char *)szSqlStr));
		pLog->Write((char *)szSQLPrepare, 0, TLog::Error, 0, (char *)cszInvalidHandle, sizeof(cszInvalidHandle)-1);
		ReleaseSQLError(pLog);
		bStatus = FALSE;
		break;
	}
		
	retcode = ::SQLExecute(m_hstmt);
	switch (retcode)
	{
	case SQL_SUCCESS:

		break;

	case SQL_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
		pLog->Write((char *)szSQLExecute, 0, TLog::Information, 0, (char *)szSqlStr, strlen((char *)szSqlStr));
		ReleaseSQLError(pLog);
#endif
		
		break;

	case SQL_STILL_EXECUTING:

		m_bStillExecuting = TRUE;
		break;

	case SQL_NEED_DATA:

		pLog->Write((char *)szSQLExecute, 0, TLog::Information, 0, (char *)szSqlStr, strlen((char *)szSqlStr));
		pLog->Write((char *)szSQLExecute, 0, TLog::Error, 0, (char *)cszNeedData, sizeof(cszNeedData)-1);
		bStatus = FALSE;
		break;

	case SQL_ERROR:

		pLog->Write((char *)szSQLExecute, 0, TLog::Information, 0, (char *)szSqlStr, strlen((char *)szSqlStr));
		pLog->Write((char *)szSQLExecute, 0, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		ReleaseSQLError(pLog);
		bStatus = FALSE;
		break;

	case SQL_INVALID_HANDLE:

		pLog->Write((char *)szSQLExecute, 0, TLog::Information, 0, (char *)szSqlStr, strlen((char *)szSqlStr));
		pLog->Write((char *)szSQLExecute, 0, TLog::Error, 0, (char *)cszInvalidHandle, sizeof(cszInvalidHandle)-1);
		ReleaseSQLError(pLog);
		bStatus = FALSE;
		break;
	}
		

	retcode = ::SQLBindCol(m_hstmt, 1, SQL_C_ULONG, pPrimary, sizeof(PRIMARY), &cbPrimary);
	retcode = ::SQLFetch(m_hstmt);

	switch (retcode)
	{
	case SQL_SUCCESS:
		break;

	case SQL_SUCCESS_WITH_INFO:

		ReleaseSQLError(pLog);
		break;

	case SQL_STILL_EXECUTING:

		m_bStillExecuting = TRUE;
		break;

	case SQL_ERROR:
	case SQL_INVALID_HANDLE:

		ReleaseSQLError(pLog);

	case SQL_NO_DATA_FOUND:

		bStatus = FALSE;
		break;
	}
		
	WaitForData();
	retcode = ::SQLFreeStmt(m_hstmt, SQL_UNBIND);
	retcode = ::SQLFreeStmt(m_hstmt, SQL_CLOSE);
	bStatus = bStatus && (cbPrimary != SQL_NULL_DATA);

	if (bStatus)
	{
		sprintf((char *)szSqlStr, szUpdateFmt, *pPrimary);
		retcode = ::SQLPrepare(m_hstmt, szSqlStr, SQL_NTS);
		retcode = ::SQLExecute(m_hstmt);
		retcode = ::SQLFreeStmt(m_hstmt, SQL_CLOSE);
	}

	retcode = ::SQLPrepare(m_hstmt, (bStatus?((UCHAR FAR *)szCommitTrans):((UCHAR FAR *)szRollbackTrans)), SQL_NTS);
	retcode = ::SQLExecute(m_hstmt);
	retcode = ::SQLFreeStmt(m_hstmt, SQL_CLOSE);

	if ((!bStatus) && bConnect) Disconnect(pLog);

	return bStatus;
}

BOOL TOdbcDatabase::EndExport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit)
{
	static char szRollbackFmt[] = "UPDATE message_desc SET msg_busy_f=0,msg_sign_f=0,msg_valid_f=0 WHERE id=%lu";
	static char szCommitFmt[] = "UPDATE message_desc SET msg_busy_f=0,msg_sign_f=2 WHERE id=%lu";

	BOOL bStatus = TRUE;
	UCHAR szSqlStr[256];
	RETCODE retcode;

	sprintf((char *)szSqlStr, ((bCommit)? szCommitFmt:szRollbackFmt), *pPrimary);
	WaitForData();
	retcode = ::SQLPrepare(m_hstmt, szSqlStr, SQL_NTS);
	switch (retcode)
	{
	case SQL_SUCCESS:

		break;

	case SQL_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
		pLog->Write((char *)szSQLPrepare, 0, TLog::Information, 0, (char *)szSqlStr, strlen((char *)szSqlStr));
		ReleaseSQLError(pLog);
#endif
		
		break;

	case SQL_STILL_EXECUTING:

		m_bStillExecuting = TRUE;
		break;

	case SQL_ERROR:
	case SQL_INVALID_HANDLE:

		pLog->Write((char *)szSQLPrepare, 0, TLog::Information, 0, (char *)szSqlStr, strlen((char *)szSqlStr));
		ReleaseSQLError(pLog);
		bStatus = FALSE;
		break;
	}
		
	WaitForData();
	retcode = ::SQLExecute(m_hstmt);
	switch (retcode)
	{
	case SQL_SUCCESS:

		break;

	case SQL_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
		ReleaseSQLError(pLog);
#endif
		
		break;

	case SQL_STILL_EXECUTING:

		m_bStillExecuting = TRUE;
		break;

	case SQL_NEED_DATA:
	case SQL_ERROR:
	case SQL_INVALID_HANDLE:

		pLog->Write((char *)szSQLExecute, 0, TLog::Information, 0, (char *)szSqlStr, strlen((char *)szSqlStr));
		ReleaseSQLError(pLog);
		bStatus = FALSE;
		break;
	}
		
	WaitForData();
	retcode = ::SQLFreeStmt(m_hstmt, SQL_RESET_PARAMS);
	retcode = ::SQLFreeStmt(m_hstmt, SQL_UNBIND);
	retcode = ::SQLFreeStmt(m_hstmt, SQL_CLOSE);

	bStatus = Disconnect(pLog) && bStatus;
	return bStatus;
}

BOOL TOdbcDatabase::BeginImport(TLog *pLog, PRIMARY *pPrimary)
{
	static char szMessageDesc[] = "message_desc";

	BOOL bStatus = TRUE;
	BOOL bConnect = FALSE;
	RETCODE retcode;

	bStatus = bStatus && (bConnect = Connect(pLog));
	if (bStatus)
	{
		retcode = ::SQLPrepare(m_hstmt, (UCHAR FAR *)szBeginTrans, SQL_NTS);
		retcode = ::SQLExecute(m_hstmt);
		retcode = ::SQLFreeStmt(m_hstmt, SQL_CLOSE);
		bStatus = bStatus && GetPrimary(pLog, (char *)szMessageDesc, pPrimary);
	}

	if ((!bStatus) && bConnect) Disconnect(pLog);
	return bStatus;
}

BOOL TOdbcDatabase::EndImport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit)
{
	BOOL bStatus = TRUE;
	RETCODE retcode;

	retcode = ::SQLPrepare(m_hstmt, (bCommit?((UCHAR FAR *)szCommitTrans):((UCHAR FAR *)szRollbackTrans)), SQL_NTS);
	retcode = ::SQLExecute(m_hstmt);
	retcode = ::SQLFreeStmt(m_hstmt, SQL_CLOSE);

	bStatus = Disconnect(pLog) && bStatus;
	return bStatus;
}
///////////////////////////////////////////////

BOOL TOdbcDatabase::Connect(TLog *pLog)
{
	BOOL bStatus = TRUE;
	RETCODE retcode;

	retcode = ::SQLConnect(m_hdbc, m_pszDSN, SQL_NTS, m_pszUID, SQL_NTS, m_pszAuthStr, SQL_NTS);
	switch (retcode)
	{
	case SQL_SUCCESS:
	case SQL_SUCCESS_WITH_INFO:

		break;

	case SQL_ERROR:
	case SQL_INVALID_HANDLE:

		bStatus = FALSE;
		break;
	}

	if (bStatus)
	{
		retcode = ::SQLAllocStmt(m_hdbc, &m_hstmt);
		switch (retcode)
		{
		case SQL_SUCCESS:
			
			break;

		case SQL_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
			ReleaseSQLError(pLog);
#endif

			break;

		case SQL_ERROR:
		case SQL_INVALID_HANDLE:

			ReleaseSQLError(pLog);
			bStatus = FALSE;
			break;
		}

		if (!bStatus) ::SQLDisconnect(m_hdbc);
	}

	return bStatus;
}

BOOL TOdbcDatabase::Disconnect(TLog *pLog)
{
	BOOL bStatus = TRUE;
	RETCODE retcode;
	retcode = ::SQLFreeStmt(m_hstmt, SQL_DROP);
	retcode = ::SQLDisconnect(m_hdbc);
	return bStatus;
}

///////////////////////////////////////////////

void TOdbcDatabase::WaitForData()
{
	while (m_bStillExecuting)
	{
		for ( int i = 10000 ; i-- ; );
		m_bStillExecuting = FALSE;
	}
}


BOOL TOdbcDatabase::BeginSelect(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary , BOOL bSort)
{
	if (pszDomain[0] == ':') return TRUE;

	BOOL bStatus = TRUE;
	ODBCBIND_STRUCT * pBindStruct = GetBindStruct();

	if (pBindStruct == NULL) return FALSE;

	Push(&m_pBuffer, sizeof(m_pBuffer));
	Push(&m_cbBuffer, sizeof(m_cbBuffer));
	m_cbBuffer = 0;

	for ( ;  bStatus && (pBindStruct->pszAttribute) ; pBindStruct++)
	{
		m_cbBuffer += sizeof(SDWORD) + 1 + (pBindStruct->cbValueMax);
	}

	m_pMemory->Malloc(&m_pBuffer, (UINT)m_cbBuffer);

	return bStatus;
}

BOOL TOdbcDatabase::Fetch(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary , BOOL bSort)
{
	if (pszDomain[0] == ':') return TRUE;

	UCHAR szSqlStr[4096];
	char * pSqlStr = (char *)szSqlStr;
	ODBCBIND_STRUCT * pBindStruct = GetBindStruct();
	char ** ppSecondaryNames = GetSecondaryNames();
	UWORD icol = 0;
	char ulbuff[32];
	BOOL first = TRUE;
	char *pSqlData = (char *)m_pBuffer;
	RETCODE retcode;
	BOOL bStatus = TRUE;

	if (pBindStruct == NULL) return FALSE;

	pSqlStr = strappend (pSqlStr, (char *)szSelect);

	for ( icol = 1 ;  bStatus && (pBindStruct->pszAttribute) ; icol++ , pBindStruct++)
	{
		if( first ) first = FALSE; else pSqlStr = strappend (pSqlStr, (char *)szComma);
		pSqlStr = strappend (pSqlStr, pBindStruct->pszFunction);
		WaitForData();
		retcode = ::SQLBindCol(m_hstmt, icol, pBindStruct->fCType, &pSqlData[sizeof(SDWORD)], pBindStruct->cbValueMax+1, (SDWORD *)pSqlData);
		switch ( retcode )
		{
		case SQL_SUCCESS:

			break;

		case SQL_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
			ReleaseSQLError(pLog);
#endif

			break;

		case SQL_ERROR:
		case SQL_INVALID_HANDLE:

			ReleaseSQLError(pLog);
			::SQLFreeStmt(m_hstmt, SQL_RESET_PARAMS);
			::SQLFreeStmt(m_hstmt, SQL_UNBIND);
			::SQLFreeStmt(m_hstmt, SQL_CLOSE);
			bStatus = FALSE;
			break;
		}
		pSqlData = &pSqlData[sizeof(SDWORD) + 1 + (pBindStruct->cbValueMax)];
	}

	if ( bStatus && bSort ) 
	{ 
		if ( first ) first = FALSE; pSqlStr = strappend (pSqlStr, (char *)szComma);
		pSqlStr = strappend (pSqlStr, ppSecondaryNames[nSecondary]);
		static SDWORD cbSecondary;

		WaitForData();
		retcode = ::SQLBindCol(m_hstmt, icol, SQL_C_ULONG, ppSecondary[nSecondary], sizeof(SECONDARY), &cbSecondary);
		switch ( retcode )
		{
		case SQL_SUCCESS:

			break;

		case SQL_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
			ReleaseSQLError(pLog);
#endif

			break;

		case SQL_ERROR:
		case SQL_INVALID_HANDLE:

			ReleaseSQLError(pLog);
			::SQLFreeStmt(m_hstmt, SQL_RESET_PARAMS);
			::SQLFreeStmt(m_hstmt, SQL_UNBIND);
			::SQLFreeStmt(m_hstmt, SQL_CLOSE);
			bStatus = FALSE;
			break;
		}
	}

	pSqlStr = strappend (pSqlStr, (char *)szFrom);

	while ( *pszDomain ) *pSqlStr++ = *pszDomain++;
	
	pSqlStr = strappend (pSqlStr, (char *)szWhere);
	pSqlStr = strappend (pSqlStr, "id");
	pSqlStr = strappend (pSqlStr, (char *)szEqual);
	pSqlStr = strappend (pSqlStr, _ultoa (*pPrimary, ulbuff, 10));
	
	UINT i = nSecondary;

	while( bStatus && i-- )
	{
		pSqlStr = strappend (pSqlStr, (char *)szAnd);
		pSqlStr = strappend (pSqlStr, ppSecondaryNames[i]);
		pSqlStr = strappend (pSqlStr, (char *)szEqual);
		pSqlStr = strappend (pSqlStr, _ultoa (*(ppSecondary[i]), ulbuff, 10));
	}

	if ( bStatus )
	{
		if (*(++pszDomain))
		{
			char ch;
			do
			{
			pSqlStr = strappend (pSqlStr, (char *)szAnd);
			while ( (ch = *pszDomain++) && (ch != ',') ) *pSqlStr++ = ch;
			} while (ch == ',');
		}

		if (*pszDomain)
		{
			pSqlStr = strappend (pSqlStr, (char *)szAnd);
			pSqlStr = strappend (pSqlStr, (char *)pszDomain);
		}
	}

	if ( bStatus && bSort)
	{
		pSqlStr = strappend (pSqlStr, (char *)szAnd);
		pSqlStr = strappend (pSqlStr, ppSecondaryNames[nSecondary]);
		*pSqlStr++ = '>';
		pSqlStr = strappend (pSqlStr, _ultoa(*(ppSecondary[nSecondary]), ulbuff, 10));

		pSqlStr = strappend (pSqlStr, (char *)szOrderBy);
		pSqlStr = strappend (pSqlStr, ppSecondaryNames[nSecondary]);
	}

	if (!bStatus) return FALSE;

	UINT nSqlStr = ((UINT)pSqlStr) - ((UINT)szSqlStr);

	WaitForData();

#if defined(_DEBUG)
	pLog->Write((char *)szSQLPrepare, 0, TLog::Information, 0, (char *)szSqlStr, nSqlStr);
#endif
	
	retcode = ::SQLPrepare(m_hstmt, szSqlStr, (SDWORD)nSqlStr);

	switch (retcode)
	{
	case SQL_SUCCESS:
		
		break;

	case SQL_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
		ReleaseSQLError(pLog);
#endif
		
		break;

	case SQL_STILL_EXECUTING:
		
		m_bStillExecuting = TRUE;
		break;

	case SQL_ERROR:
	case SQL_INVALID_HANDLE:
		
		ReleaseSQLError(pLog);
		::SQLFreeStmt(m_hstmt, SQL_RESET_PARAMS);
		::SQLFreeStmt(m_hstmt, SQL_UNBIND);
		::SQLFreeStmt(m_hstmt, SQL_CLOSE);
		bStatus = FALSE;
		break;
	}

	if (!bStatus) return FALSE;

	WaitForData();

	retcode = ::SQLSetStmtOption(m_hstmt, SQL_MAX_ROWS, 1);

	switch (retcode)
	{
	case SQL_SUCCESS:
		
		break;

	case SQL_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
		ReleaseSQLError(pLog);
#endif

		break;

	case SQL_ERROR:
	case SQL_INVALID_HANDLE:
		
		ReleaseSQLError(pLog);
		::SQLFreeStmt(m_hstmt, SQL_RESET_PARAMS);
		::SQLFreeStmt(m_hstmt, SQL_UNBIND);
		::SQLFreeStmt(m_hstmt, SQL_CLOSE);
		bStatus = FALSE;
		break;
	}

	if (!bStatus) return FALSE;

	retcode = ::SQLExecute(m_hstmt);

	switch (retcode)
	{
	case SQL_SUCCESS:
		
		break;

	case SQL_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
		ReleaseSQLError(pLog);
#endif
		
		break;

	case SQL_STILL_EXECUTING:
		
		m_bStillExecuting = TRUE;
		break;

	case SQL_NEED_DATA:
	case SQL_ERROR:
	case SQL_INVALID_HANDLE:
		
		ReleaseSQLError(pLog);
		::SQLFreeStmt(m_hstmt, SQL_RESET_PARAMS);
		::SQLFreeStmt(m_hstmt, SQL_UNBIND);
		::SQLFreeStmt(m_hstmt, SQL_CLOSE);
		bStatus = FALSE;
		break;
	}

	if (!bStatus) return FALSE;

	WaitForData();
	retcode = ::SQLFetch(m_hstmt);

	switch (retcode)
	{
	case SQL_SUCCESS:
		
		break;

	case SQL_SUCCESS_WITH_INFO:
		
#if defined(_DEBUG)
		ReleaseSQLError(pLog);
#endif
		break;

	case SQL_NO_DATA_FOUND:
		
		bStatus = FALSE;
		::SQLFreeStmt(m_hstmt, SQL_RESET_PARAMS);
		::SQLFreeStmt(m_hstmt, SQL_UNBIND);
		::SQLFreeStmt(m_hstmt, SQL_CLOSE);
		break;

	case SQL_STILL_EXECUTING:
		
		m_bStillExecuting = TRUE;
		break;

	case SQL_ERROR:
	case SQL_INVALID_HANDLE:
		
		ReleaseSQLError(pLog);
		::SQLFreeStmt(m_hstmt, SQL_RESET_PARAMS);
		::SQLFreeStmt(m_hstmt, SQL_UNBIND);
		::SQLFreeStmt(m_hstmt, SQL_CLOSE);
		bStatus = FALSE;
		break;
	}

	if (!bStatus) return FALSE;

	WaitForData();
	::SQLFreeStmt(m_hstmt, SQL_RESET_PARAMS);
	::SQLFreeStmt(m_hstmt, SQL_UNBIND);
	::SQLFreeStmt(m_hstmt, SQL_CLOSE);
	return bStatus;
}

BOOL TOdbcDatabase::EndSelect(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary)
{
	if (pszDomain[0] == ':') return TRUE;

	m_pMemory->Free(m_pBuffer, (UINT)m_cbBuffer);
	Pop(&m_cbBuffer, sizeof(m_cbBuffer));
	Pop(&m_pBuffer, sizeof(m_pBuffer));
	return TRUE;
}

UINT TOdbcDatabase::min3(UINT i, UINT j, UINT k)
{
	if ( i < k ) k = i;
	if ( j < k ) k = j;
	return k;
}

BOOL TOdbcDatabase::GetAttribute(TLog *pLog, char *pszDomain, char *pszAttribute, PRIMARY * pPrimary, SECONDARY **ppSecondary, UINT nSecondary, int type, void *pBuffer, UINT *pcbBuffer, UINT cbMaxBuffer)
{
	BOOL bStatus = FALSE;
	char * ptrA;
	char * ptrD;
	char * pSqlData = (char *)m_pBuffer;

	if (pSqlData == NULL) return FALSE;

	ODBCBIND_STRUCT * pBindStruct = GetBindStruct();

	while ( ((ptrA = pBindStruct->pszAttribute) != NULL) && !(bStatus = ((((ptrD = pBindStruct->pszSubdomain) == NULL) || (ptrD == pszDomain)) && (ptrA == pszAttribute))) )
	{
		pSqlData = &pSqlData[sizeof(SDWORD) + 1 + (pBindStruct->cbValueMax)];
		pBindStruct++;
	}
	
	if (!bStatus) return FALSE;

	SDWORD cbValueMax = pBindStruct->cbValueMax;
	UINT cbBuffer;

	WaitForData();

	if ( *(SDWORD *)pSqlData == SQL_NULL_DATA) return FALSE;

	switch (type)
	{
	case TDatabase::Integer:
		cbBuffer = PostselectInteger((LONG *)pBuffer, (SLONG *)&pSqlData[sizeof(SDWORD)]);
		break;

	case TDatabase::Text:
		cbBuffer = PostselectText((char *)pBuffer, &pSqlData[sizeof(SDWORD)], min3(*(SDWORD *)pSqlData,cbValueMax,cbMaxBuffer));
		break;

	case TDatabase::Multitext:
		cbBuffer = PostselectMultitext((char *)pBuffer, &pSqlData[sizeof(SDWORD)], min3(*(SDWORD *)pSqlData,cbValueMax,cbMaxBuffer));
		break;

	case TDatabase::Decimal:
		cbBuffer = PostselectDecimal((char *)pBuffer, &pSqlData[sizeof(SDWORD)], min3(*(SDWORD *)pSqlData,cbValueMax,cbMaxBuffer));
		break;

	case TDatabase::Datetime:
		cbBuffer = PostselectDatetime((struct tm *)pBuffer, (TIMESTAMP_STRUCT *)&pSqlData[sizeof(SDWORD)]);
		break;

	default:
		bStatus = FALSE;
	}

	if (pcbBuffer) *pcbBuffer = cbBuffer;
	bStatus = bStatus && (cbBuffer != 0);

	return bStatus;
}

void TOdbcDatabase::Push(void *pBuffer, UINT nLen)
{
	memmove(m_pStack, pBuffer, nLen);
	m_pStack += nLen;
}

void TOdbcDatabase::Pop(void *pBuffer, UINT nLen)
{
	m_pStack -= nLen;
	memmove(pBuffer, m_pStack, nLen);
}

