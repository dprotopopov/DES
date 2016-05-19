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

FILE * UneiOpenDestStream(char *pszFileName, char *pszExtension)
{
	char path_buffer[_MAX_PATH];
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];

	strftime(path_buffer, sizeof(path_buffer), pszFileName, &g_tmBasic);
	_splitpath( path_buffer, drive, dir, fname, ext );
	_makepath( path_buffer, drive, dir, fname, pszExtension );

	return fopen(path_buffer, "ab"); 
}

void UneiExport(char *pszDSN, char *pszUID, char *pszAuthStr, char *pszExport, char *pszUnei, IDLEFUNC fnIdle)
{
///////////////////////////////////////////////////////
	TLog			*pLog = new TFileLog(__logfile);
	TMemory			*pMemory = new THeapMemory ();
	TReport			*pReport;
	TReport			*pShortReport;
	TOdbcDatabase	*pArchive;
	TFile			*pOutput;
//////////////////////////////////////////////////////
	FILE			*flDest;
	time_t			ltime;
	IDLEINFO		ii;
	memset(&ii, 0, sizeof(IDLEINFO));

	pLog->Create();
	pMemory->Create();

	time (&ltime);
	memmove (&ii.tmStart, localtime(&ltime), sizeof(struct tm));

//////////////////////////////////////////////
// Export SWIFT messages exept 202

	flDest = OpenDestStream(pszExport);
	pReport = new TFileReport(__logfile);
	pShortReport = new IShortReport(__logfile);
	pArchive = new TUneiSwiftDatabase (pszDSN, pszUID, pszAuthStr, pMemory);
	pOutput = new TFile (flDest);

	IFILESWIFTMESSAGE *pObjectSwift = new IFILESWIFTMESSAGE ();
	pObjectSwift->Create(pMemory);

	DefaultExport
	(
		pObjectSwift, 
		pLog, 
		pReport, 
		pShortReport, 
		pMemory, 
		pArchive, 
		pOutput, 
		fnIdle,
		&ii
	);

	pObjectSwift->Destroy(pMemory);
	delete pObjectSwift;

	delete pOutput;
	delete pShortReport;
	delete pReport;
	if (flDest) fclose(flDest);
	delete pArchive;

////////////////////////////////////////////////
// Export 041 messages

	flDest = UneiOpenDestStream(pszUnei, "041");
	pReport = new TFileReport(__logfile);
	pShortReport = new IShortReport(__logfile);
	pArchive = new TUneiMessageDatabase (pszDSN, pszUID, pszAuthStr, pMemory, TUneiMessageDatabase::szExport041SelectFormat);
	pOutput = new TFile (flDest);

	UMT041 * pObject041 = new UMT041 ();
	pObject041->Create(pMemory);

	DefaultExport
	(
		pObject041, 
		pLog, 
		pReport, 
		pShortReport, 
		pMemory, 
		pArchive, 
		pOutput, 
		fnIdle,
		&ii
	);

	pObject041->Destroy(pMemory);
	delete pObject041;

	delete pOutput;
	delete pShortReport;
	delete pReport;
	if (flDest) fclose(flDest);
	delete pArchive;

////////////////////////////////////////////////
// Export 044 messages

	flDest = UneiOpenDestStream(pszUnei, "044");
	pReport = new TFileReport(__logfile);
	pShortReport = new IShortReport(__logfile);
	pArchive = new TUneiMessageDatabase (pszDSN, pszUID, pszAuthStr, pMemory, TUneiMessageDatabase::szExport044SelectFormat);
	pOutput = new TFile (flDest);

	UMT044 * pObject044 = new UMT044 ();
	pObject044->Create(pMemory);

	DefaultExport
	(
		pObject044, 
		pLog, 
		pReport, 
		pShortReport, 
		pMemory, 
		pArchive, 
		pOutput, 
		fnIdle,
		&ii
	);

	pObject044->Destroy(pMemory);
	delete pObject044;

	delete pOutput;
	delete pShortReport;
	delete pReport;
	if (flDest) fclose(flDest);


	time (&ltime);
	memmove (&ii.tmFinish, localtime(&ltime), sizeof(struct tm));

	((TOdbcDatabase *)pArchive)->AddHistory(pLog, &ii.tmStart, &ii.tmFinish, pszExport, ii.lSuccess, ii.lError);
	delete pArchive;

	pMemory->Destroy();
	pLog->Destroy();

/////////////////////////////////////////////

	delete pMemory;
	delete pLog;
}
