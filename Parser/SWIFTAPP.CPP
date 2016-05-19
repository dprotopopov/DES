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

/////////////////////////////////

BOOL SkipSwiftMessage(TInput *pInput, TOutput * pOutput)
{
	char ch;
	BOOL bStatus = TRUE;
	BOOL eom = FALSE;
	
	while ( bStatus && (!eom) && (!(pInput->Eof())) )
	{
		pInput->Read(&ch, 1);
		pOutput->Write(&ch, 1);
		eom = (ch == '\x03');
	}

	return bStatus;
}

FILE * OpenSourceStream(char * pszFileName) 
{ 
	char path_buffer[_MAX_PATH];
	strftime(path_buffer, sizeof(path_buffer), pszFileName, &g_tmBasic);
	return fopen(path_buffer, "rb"); 
}

int RenameSourceStream(char * pszFileName) 
{ 
	char path_buffer1[_MAX_PATH];
	char path_buffer2[_MAX_PATH];
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	strftime(path_buffer1, sizeof(path_buffer1), pszFileName, &g_tmBasic);
	_splitpath( path_buffer1, drive, dir, fname, ext );
	_makepath( path_buffer2, drive, dir, fname, "ou2" );
	return rename(path_buffer1, path_buffer2); 
}

FILE * OpenDestStream(char * pszFileName)    
{ 
	char path_buffer[_MAX_PATH];
	strftime(path_buffer, sizeof(path_buffer), pszFileName, &g_tmBasic);
	return fopen(path_buffer, "ab"); 
}

/////////////////////////////////////////////////

const char szExport[] = "Export";
const char szImport[] = "Import";

const char cszSysfilesError[] = 
	"Can not create system files. "
	"Process terminated.";

/////////////////////////////////////////////////

void SwiftExport(char *pszDSN, char *pszUID, char *pszAuthStr, char *pszExport, IDLEFUNC fnIdle)
{
	FILE			*flDest = OpenDestStream(pszExport);
///////////////////////////////////////////////////////
	TLog			*pLog = new TFileLog(__logfile);
	TReport			*pReport = new TFileReport(__logfile);
	TReport			*pShortReport = new IShortReport(__logfile);
	TMemory			*pMemory = new THeapMemory ();
	IFILESWIFTMESSAGE	*pObject = new IFILESWIFTMESSAGE ();
	TOdbcDatabase	*pArchive = new TSwiftDatabase (pszDSN, pszUID, pszAuthStr, pMemory);
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

void SwiftImport(char *pszDSN, char *pszUID, char *pszAuthStr, char *pszImport, char *pszClear, char *pcszError, IDLEFUNC fnIdle)
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
	OFILESWIFTMESSAGE	*pObject = new OFILESWIFTMESSAGE();
	TFile			*pInput = new TFile (flSrc);
	TFile			*pClear = new TFile (flClr);
	TFile			*pError = new TFile (flErr);
	TOdbcDatabase	*pMonitor = new TSwiftDatabase (pszDSN, pszUID, pszAuthStr, pMemory);
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
