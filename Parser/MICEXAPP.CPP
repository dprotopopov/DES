//////////////////////////////////
// System level dependencies

#include <windows.h>
#include <sql.h>
#include <sqlext.h>

//////////////////////////////////
// ANSI level dependencies

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//////////////////////////////////
// Application level dependencies

#include "tdb.h"
#include "tio.h"
#include "tlog.h"
#include "tmemory.h"
#include "pobject.h"
#include "parser.h"
#include "odbcbind.h"
#include "odbcdb.h"
#include "eventlog.h"

#include "prc.h"
#include "swiftext.h"
#include "swiftmf.h"
#include "swiftrep.h"
#include "swiftapp.h"
#include "swiftdb.h"
#include "uneiext.h"
#include "uneimf.h"
#include "uneiapp.h"
#include "uneidb.h"
#include "micexapp.h"

/////////////////////////////////////////////////

const char szExport[] = "Export";
const char szImport[] = "Import";

const char cszSysfilesError[] = 
	"Can not create system files. "
	"Process terminated.";

/////////////////////////////////////////////////

void MicexExport(char *pszDSN, char *pszUID, char *pszAuthStr, char *pszExport, IDLEFUNC fnIdle)
{
	FILE			*flDest = OpenDestStream(pszExport);
///////////////////////////////////////////////////////
	TLog			*pLog = new TFileLog(__logfile);
	TReport			*pReport = new TFileReport(__logfile);
	TReport			*pShortReport = new IShortReport(__logfile);
	TMemory			*pMemory = new THeapMemory ();
	IFILEMICEXMESSAGE	*pObject = new IFILEMICEXMESSAGE ();
	TOdbcDatabase	*pArchive = new TMicexDatabase (pszDSN, pszUID, pszAuthStr, pMemory);
	TFile			*pOutput = new TFile (flDest);
//////////////////////////////////////////////////////
	time_t			ltime;
	IDLEINFO		ii;
	memset(&ii, 0, sizeof(IDLEINFO));

	pLog->Create();
	pMemory->Create();
	pObject->Create(pMemory);

	time (&ltime);
	memmove (&ii.tmStart, localtime(&ltime), sizeof(struct tm));

	DefaultExport
	(
		pObject, 
		pLog, 
		pReport, 
		pShortReport, 
		pMemory, 
		pArchive, 
		pOutput, 
		fnIdle,
		&ii
	);

	time (&ltime);
	memmove (&ii.tmFinish, localtime(&ltime), sizeof(struct tm));

	((TOdbcDatabase *)pArchive)->AddHistory(pLog, &ii.tmStart, &ii.tmFinish, pszExport, ii.lSuccess, ii.lError);
	pObject->Destroy(pMemory);
	pMemory->Destroy();
	pLog->Destroy();

//////////////////////////////////////////////////////
	delete pOutput;
	delete pArchive;
	delete pObject;
	delete pMemory;
	delete pShortReport;
	delete pReport;
	delete pLog;
	if (flDest) fclose(flDest);
}

void MicexImport(char *pszDSN, char *pszUID, char *pszAuthStr, char *pszImport, char *pszClear, char *pcszError, IDLEFUNC fnIdle)
{
	TLog			*pLog = new TFileLog(__logfile);
	TReport			*pReport = new TFileReport(__logfile);
	TReport			*pShortReport = new OShortReport(__logfile);

	pLog->Create();

	FILE			*flSrc = OpenSourceStream(pszImport);
	FILE			*flErr = OpenDestStream(pcszError);
	FILE			*flClr = OpenDestStream(pszClear);

	if (flErr == NULL || flClr == NULL )
	{
		pLog->Write((char *)szImport, 0, TLog::Error, 1, (char *)cszSysfilesError, sizeof(cszSysfilesError)-1);
		pLog->Flush();
		pLog->Destroy();
		delete pShortReport;
		delete pReport;
		delete pLog;
		return;
	}
////////////////////////////////////////////////////////
	TMemory			*pMemory = new THeapMemory();
	OFILEMICEXMESSAGE	*pObject = new OFILEMICEXMESSAGE();
	TFile			*pInput = new TFile (flSrc);
	TFile			*pClear = new TFile (flClr);
	TFile			*pError = new TFile (flErr);
	TOdbcDatabase	*pMonitor = new TMicexDatabase (pszDSN, pszUID, pszAuthStr, pMemory);
////////////////////////////////////////////////////////
	time_t			ltime;
	IDLEINFO		ii;
	memset(&ii, 0, sizeof(IDLEINFO));

	pMemory->Create();
	pObject->Create(pMemory);

	time (&ltime);
	memmove (&ii.tmStart, localtime(&ltime), sizeof(struct tm));

	DefaultImport
	(
		pObject, 
		pLog, 
		pReport, 
		pShortReport, 
		pMemory, 
		pMonitor, 
		pInput, 
		pClear, 
		pError, 
		SkipSwiftMessage,
		fnIdle, 
		&ii
	);


	time (&ltime);
	memmove (&ii.tmFinish, localtime(&ltime), sizeof(struct tm));

	((TOdbcDatabase *)pMonitor)->AddHistory(pLog, &ii.tmStart, &ii.tmFinish, pszImport, ii.lSuccess, ii.lError);
	pObject->Destroy(pMemory);
	pMemory->Destroy();
	pLog->Destroy();

////////////////////////////////////////////////////////
	delete pMonitor;
	delete pInput;
	delete pError;
	delete pClear;
	delete pObject;
	delete pMemory;
	delete pShortReport;
	delete pReport;
	delete pLog;
	if (flSrc) fclose(flSrc);
	if (flErr) fclose(flErr);
	if (flClr) fclose(flClr);
	RenameSourceStream(pszImport);
}
