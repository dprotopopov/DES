//////////////////////////////////
// System level dependencies

#include <windows.h>
#include <sql.h>
#include <sqlext.h>

//////////////////////////////////
// ANSI level dependencies

#include <stdio.h>
#include <time.h>
#include <direct.h>

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
#include "swiftapp.h"
#include "uneiapp.h"
#include "micexapp.h"
#include "eventlog.h"

/////////////////////////////////
struct tm g_tmBasic;


const char szTitle[]      = "Parser of S.W.I.F.T. messages";
const char cszCopyright[] = "Copyright (c) 1996,1997 Asset Information Management";
const char szVersion[]    = "1.1.3.5";

const char szLogFileName[]    = ".\\log\\%y%m%d.log";
const char szImportFileName[] = ".\\from_st\\%y%m%d.out";
const char szExportFileName[] = ".\\to_st\\%y%m%d.in";
const char szClearFileName[]  = ".\\log\\%y%m%d.clr";
const char cszErrorFileName[] = ".\\log\\%y%m%d.err";
const char cszUneiFileName[]  = ".\\unei\\%y%m%d";

const char szDSN[]     = "SWIFT";
const char szUID[]     = "swift";
const char szAuthStr[] = "1swift";

const char cmdHELP[]         = "0";
const char cmdIMPORTONLY[]   = "1";
const char cmdEXPORTONLY[]   = "2";
const char cmdIMPORTEXPORT[] = "3";

const char optLOG[]    = "-L";
const char optIMPORT[] = "-I";
const char optEXPORT[] = "-E";
const char optCLEAR[]  = "-C";
const char optERROR[]  = "-B";
const char optDSN[]    = "-D";
const char optUID[]    = "-U";
const char optPWD[]    = "-P";
const char optWD[]     = "-W";
const char optUNEI[]   = "-S";

const char flagSWIFT[] = "/swift";
const char flagUNEI[]  = "/unei";
const char flagMICEX[] = "/micex";

const char szHelp[] =
"Usage:\n"
"parser [0123] [-L...] [-I...] [-E...] [-C...] [-B...] [-D...] [-U...] [-P...]\n" 
"Commands:\n"
"0\tShow help (*)\n"
"1\tImport only\n"
"2\tExport only\n"
"3\tImport and export\n"
"\n"
"Options:\n"
"-W\tWorking directory (.)\n"
"-L\tLog file name     (.\\log\\%y%m%d.log)\n"
"-I\tImport file name  (.\\from_st\\%y%m%d.out)\n"
"-E\tExport file name  (.\\to_st\\%y%m%d.in)\n"
"-C\tClear file name   (.\\log\\%y%m%d.clr)\n"
"-B\tError file name   (.\\log\\%y%m%d.err)\n"
"-D\tData source name  (SWIFT)\n"
"-U\tUser identificator\n"
"-P\tPassword\n"
"-S\tUNEXIM messages file mask (.\\unei\\%y%m%d)\n"
"Flags:\n"
"/swift\tUse SWIFT TERMINAL specification\n"
"/unei\tUse UNEXIM specification\n"
"/micex\tUse MICEX specification\n"
;

/////////////////////////////////////////////////////////
// Internal structures which used to parse command line

struct cmddef { char * pszCommand; UINT nCommand; };

struct cmddef Command[] = 
{
	{(char *)cmdHELP, 0},
	{(char *)cmdIMPORTONLY, 1},
	{(char *)cmdEXPORTONLY, 2},
	{(char *)cmdIMPORTEXPORT, 3}
};

struct optdef { char * pOption; UINT nOption; char **ppBuffer; };
struct flagdef { char * pFlag; UINT nFlag; BOOL *pBuffer; };

//////////////////////////////////////////////////////////////
//The main function is the name of the function that marks the beginning and 
//end of program execution. A C or C++ program must have one function named main.
//
//The main and wmain functions can take the following three optional arguments, 
//traditionally called argc, argv, and envp (in that order):
//argc	An integer specifying how many arguments are passed to the program from the command line. 
//		Since the program name is considered an argument, argc is at least 1.
//argv	An array of null-terminated strings. It can be declared as an array of pointers 
//		to char (char *argv[ ] or wchar_t *argv[ ] for wmain) or as a pointer to pointers to 
//		char (char **argv or wchar_t **argv for wmain). The first string (argv[0]) is the program 
//		name, and each following string is an argument passed to the program from the command line. 
//		The last pointer (argv[argc]) is NULL.
//envp	A pointer to an array of environment strings. It can be declared as an array of pointers 
//		to char (char *envp[ ]) or as a pointer to pointers to char (char **envp). If your 
//		program uses wmain instead of main, use the wchar_t data type instead of char. 
//		The end of the array is indicated by a NULL pointer. The environment block passed 
//		to main and wmain is a "frozen" copy of the current environment. If you subsequently 
//		change the environment via a call to putenv or _wputenv, the current environment (as 
//		returned by getenv/_wgetenv and the _environ/ _wenviron variable) will change, but the 
//		block pointed to by envp will not change.

int main(int argc, char *argv[])
{
	printf("%s\n", (char *)szTitle);
	printf("Version %s\n", (char *)szVersion);
	printf("%s\n", (char *)cszCopyright);
	fflush(stdout);

	time_t t;
	time(&t);
	memmove(&g_tmBasic, localtime(&t), sizeof(struct tm));

	char cwd[256];
	/////////////////////////////////
	// Get current working directory
	_getcwd(cwd, sizeof(cwd));

	char *pszLog     = (char *)szLogFileName;
	char *pszImport  = (char *)szImportFileName;
	char *pszExport  = (char *)szExportFileName;
	char *pszClear   = (char *)szClearFileName;
	char *pszError   = (char *)cszErrorFileName;
	char *pszDSN     = (char *)szDSN;
	char *pszUID     = (char *)szUID;
	char *pszAuthStr = (char *)szAuthStr;
	char *pszWorkDir = NULL;

	char *pszUnei   = (char *)cszUneiFileName;
	BOOL bSwift = TRUE;
	BOOL bUnei = FALSE;
	BOOL bMicex = FALSE;

	struct optdef Option[] =
	{
		{ (char *)optLOG,    sizeof(optLOG)-1,    &pszLog },
		{ (char *)optIMPORT, sizeof(optIMPORT)-1, &pszImport },
		{ (char *)optEXPORT, sizeof(optEXPORT)-1, &pszExport },
		{ (char *)optCLEAR,  sizeof(optCLEAR)-1,  &pszClear },
		{ (char *)optERROR,  sizeof(optERROR)-1,  &pszError },
		{ (char *)optDSN,    sizeof(optDSN)-1,    &pszDSN },
		{ (char *)optUID,    sizeof(optUID)-1,    &pszUID },
		{ (char *)optPWD,    sizeof(optPWD)-1,    &pszAuthStr },
		{ (char *)optWD,     sizeof(optWD)-1,     &pszWorkDir },
		{ (char *)optUNEI,   sizeof(optUNEI)-1,   &pszUnei }
	};

	struct flagdef Flag[] =
	{
		{ (char *)flagSWIFT,  sizeof(flagSWIFT)-1, &bSwift },
		{ (char *)flagUNEI,   sizeof(flagUNEI)-1,  &bUnei },
		{ (char *)flagMICEX,  sizeof(flagMICEX)-1, &bMicex }
	};


	UINT nCommand = 0;
	char **ppArg = argv;
	BOOL bStatus = TRUE;

	argc--; ppArg++;

	if ( argc )
	{
		char * pszCommand = *ppArg;
		int i = sizeof(Command)/sizeof(cmddef);
		while ( bStatus && i-- )
		{
			if ( strcmp(pszCommand, Command[i].pszCommand) == 0 )
			{
				nCommand = Command[i].nCommand;
				argc--; ppArg++;
				break;
			}
		}
	}

	while ( bStatus && argc )
	{
		char * pCurrentArg = *ppArg;
		int i = sizeof(Option)/sizeof(optdef);
		bStatus = FALSE;
		if (!bStatus) 
		{
			i = sizeof(Option)/sizeof(optdef);
			while ( i-- )
			{
				if ( strncmp(pCurrentArg, Option[i].pOption, Option[i].nOption) == 0 )
				{
					bStatus = TRUE;
					*(Option[i].ppBuffer) = &(pCurrentArg[Option[i].nOption]);
					argc--; ppArg++;
					break;
				}
			}
		}
		if (!bStatus) 
		{
			i = sizeof(Flag)/sizeof(flagdef);
			while ( i-- )
			{
				if ( strncmp(pCurrentArg, Flag[i].pFlag, Flag[i].nFlag) == 0 )
				{
					bStatus = TRUE;
					*(Flag[i].pBuffer) = TRUE;
					argc--; ppArg++;
					break;
				}
			}
		}
	}

	if (!bStatus)
	{
		for(int i = 10 ; i-- ; ) MessageBeep(-1);
		printf("Error in command string\n%s\n", (char *)szHelp);
		return -1;
	}

	if (pszWorkDir) _chdir(pszWorkDir);

	__logfile = OpenDestStream(pszLog);
	if (__logfile == NULL)
	{
		for(int i = 10 ; i-- ; ) MessageBeep(-1);
		return -1;
	}

	if (bUnei) printf("Plus UNEXIM BANK messages module\n");
	if (bMicex) printf("Plus MICEX messages module\n");

	bSwift = ! (bUnei || bMicex);

	switch (nCommand)
	{
	case 0:
		printf("%s", (char *)szHelp);
		break;

	case 1:
	case 2:
	case 3:

		if (nCommand & 1)
		{
			if (bSwift) SwiftImport(pszDSN, pszUID, pszAuthStr, pszImport, pszClear, pszError, DefaultIdle);
			if (bUnei)  SwiftImport(pszDSN, pszUID, pszAuthStr, pszImport, pszClear, pszError, DefaultIdle);
			if (bMicex) MicexImport(pszDSN, pszUID, pszAuthStr, pszImport, pszClear, pszError, DefaultIdle);
		}

		if (nCommand & 2) 
		{
			if (bSwift) SwiftExport(pszDSN, pszUID, pszAuthStr, pszExport, DefaultIdle);
			if (bUnei)  UneiExport(pszDSN, pszUID, pszAuthStr, pszExport, pszUnei, DefaultIdle);
			if (bMicex) MicexExport(pszDSN, pszUID, pszAuthStr, pszExport, DefaultIdle);
		}
	}


	if (__logfile) fclose(__logfile);

	//////////////////////////////////
	// Return to old working directory
	_chdir(cwd);

	MessageBeep(-1);
	return 0;
}

BOOL DefaultIdle(IDLEINFO *) 
{ 
	return TRUE; 
}

///////////////////////////////////////////
//

const char szApplication[] = "Application";
const char szExport[] = "Export";
const char szImport[] = "Import";
const char szLoad[] = "Load";
const char szStore[] = "Store";
const char szInsert[] = "Insert";
const char szSelect[] = "Select";
const char szValidate[] = "Validate";

/////////////////////////////////////////////////
//

const char cszNoDataFound[] = "No Data Found";
const char cszError[] = "Error";

/////////////////////////////////////////////////
//

const char cszCopy[] = 
	"Copy message into error stream";

const char cszCopyError[] =
	"Error in error stream. "
	"Last processed message no present in database and no present in error stream. "
	"Process terminated";

const char cszTerminatedByUser[] =
	"Process terminated by user.";

//////////////////////////////////////////////////////
//

const char cszSuccessPrefix[] = "{1 ";
const char cszSuccessSuffix[] = "";
const char cszErrorPrefix[] = "{0 ";
const char cszErrorSuffix[] = "";
const char cszHeaderPrefix[] = "";
const char cszHeaderSuffix[] = "}\r\n";
const char cszWarningsPrefix[] = "";
const char cszWarningsSuffix[] = "";
const char cszDebugPrefix[] = "";
const char cszDebugSuffix[] = "";

///////////////////////////////////////////////////////
//

void DefaultExport
(
	PObject * pObject, 
	TLog * pLog, 
	TReport * pReport, 
	TReport * pShortReport, 
	TMemory * pMemory, 
	TArchive * pArchive, 
	TOutput * pOutput, 
	IDLEFUNC fnIdle,
	IDLEINFO * pIdleInfo
)
{
	BOOL			bIdle;
	PRIMARY			Primary = 0;
	SECONDARY		*Secondary[100];

	while ( (bIdle = fnIdle(pIdleInfo)) )
	{
		BOOL bStatus = TRUE;
		BOOL bool_step_begin = TRUE;
		BOOL bExport = FALSE;
		
		pLog->BeginWrite((char *)szExport, 0);
		bStatus = bStatus && (bExport = bool_step_begin = (pArchive->BeginExport(pLog, &Primary)));

		if (bStatus) 
		{
			char buffer[256];
			sprintf(buffer, "Message id=%lu", Primary);
			pLog->Write((char *)szExport, 0, TLog::Information, 1, buffer, strlen(buffer));
		}


		if (bStatus)
		{
			pLog->BeginWrite((char *)szSelect, 0);
			RETVALUE retvalue = pObject->Select(pArchive, pMemory, pLog, NULL, &Primary, Secondary, 0);
			switch (retvalue)
			{
			case PARSER_SUCCESS:
			case PARSER_SUCCESS_WITH_INFO:
				break;
			case PARSER_NO_DATA_FOUND:
				pLog->Write((char *)szSelect, 0, TLog::Error, 1, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
				bStatus = FALSE;
				break;
			case PARSER_ERROR:
				pLog->Write((char *)szSelect, 0, TLog::Error, 1, (char *)cszError, sizeof(cszError)-1);
				bStatus = FALSE;
				break;
			}
			
			pLog->EndWrite((char *)szSelect, 0, retvalue);
		}

		if (bStatus) 
		{
			pLog->BeginWrite((char *)szValidate, 0);
			RETVALUE retvalue = pObject->Validate(pMemory, pLog);
			switch(retvalue)
			{
			case PARSER_SUCCESS:
			case PARSER_SUCCESS_WITH_INFO:
				break;
			case PARSER_NO_DATA_FOUND:
			case PARSER_ERROR:
				pLog->Write((char *)szValidate, 0, TLog::Error, 1, (char *)cszError, sizeof(cszError)-1);
				bStatus = FALSE;
				break;
			}
			pLog->EndWrite((char *)szValidate, 0, retvalue);
		}

		if (bStatus) 
		{
			pLog->BeginWrite((char *)szStore, 0);
			RETVALUE retvalue = pObject->Store(pOutput, pMemory, pLog);
			switch(retvalue)
			{
			case PARSER_SUCCESS:
			case PARSER_SUCCESS_WITH_INFO:
				break;
			case PARSER_ERROR:
				pLog->Write((char *)szStore, 0, TLog::Error, 1, (char *)cszError, sizeof(cszError)-1);
				bStatus = FALSE;
				break;
			}
			
			pLog->EndWrite((char *)szStore, 0, retvalue);
		}

		if (bExport)
		{
			pArchive->EndExport(pLog, &Primary, bStatus);
		}

		if (bStatus)
		{
			pIdleInfo->lSuccess++;

			const char szMessage[] = "Message exported success";
			pLog->Write((char *)szExport, 0, TLog::Information, 1, (char *)szMessage, sizeof(szMessage)-1);
			pLog->EndWrite((char *)szExport, 0, PARSER_SUCCESS);

			fwrite((char *)cszSuccessPrefix, 1, sizeof(cszSuccessPrefix)-1, __logfile);

			fwrite((char *)cszHeaderPrefix, 1, sizeof(cszHeaderPrefix)-1, __logfile);
			pShortReport->BeginImport(pLog, &Primary);
			pObject->Insert(pShortReport, pMemory, pLog, NULL, &Primary, Secondary, 0);
			pShortReport->EndImport(pLog, &Primary, TRUE);
			fwrite((char *)cszHeaderSuffix, 1, sizeof(cszHeaderSuffix)-1, __logfile);

			fwrite((char *)cszWarningsPrefix, 1, sizeof(cszWarningsPrefix)-1, __logfile);
			pLog->Flush();
			fwrite((char *)cszWarningsSuffix, 1, sizeof(cszWarningsSuffix)-1, __logfile);

			fwrite((char *)cszDebugPrefix, 1, sizeof(cszDebugPrefix)-1, __logfile);
			fwrite((char *)cszDebugSuffix, 1, sizeof(cszDebugSuffix)-1, __logfile);

			fwrite((char *)cszSuccessSuffix, 1, sizeof(cszSuccessSuffix)-1, __logfile);
		}
		else if (bExport)
		{
			pIdleInfo->lError++;

			const char szMessage[] = "Error occured during message export";
			pLog->Write((char *)szExport, 0, TLog::Warning, 1, (char *)szMessage, sizeof(szMessage)-1);
			pLog->EndWrite((char *)szExport, 0, PARSER_ERROR);

			fwrite((char *)cszErrorPrefix, 1, sizeof(cszErrorPrefix)-1, __logfile);

			fwrite((char *)cszHeaderPrefix, 1, sizeof(cszHeaderPrefix)-1, __logfile);
			pShortReport->BeginImport(pLog, &Primary);
			pObject->Insert(pShortReport, pMemory, pLog, NULL, &Primary, Secondary, 0);
			pShortReport->EndImport(pLog, &Primary, TRUE);
			fwrite((char *)cszHeaderSuffix, 1, sizeof(cszHeaderSuffix)-1, __logfile);

			fwrite((char *)cszWarningsPrefix, 1, sizeof(cszWarningsPrefix)-1, __logfile);
			pLog->Flush();
			fwrite((char *)cszWarningsSuffix, 1, sizeof(cszWarningsSuffix)-1, __logfile);

			fwrite((char *)cszDebugPrefix, 1, sizeof(cszDebugPrefix)-1, __logfile);
			pReport->BeginImport(pLog, &Primary);
			pObject->Insert(pReport, pMemory, pLog, NULL, &Primary, Secondary, 0);
			pReport->EndImport(pLog, &Primary, TRUE);
			fwrite((char *)cszDebugSuffix, 1, sizeof(cszDebugSuffix)-1, __logfile);

			fwrite((char *)cszErrorSuffix, 1, sizeof(cszErrorSuffix)-1, __logfile);
		}

		pObject->Refresh(pMemory);

		if (!bool_step_begin) break;
	}
}

void DefaultImport
(
	PObject * pObject, 
	TLog * pLog, 
	TReport * pReport, 
	TReport * pShortReport, 
	TMemory * pMemory, 
	TMonitor * pMonitor, 
	TInput * pInput, 
	TOutput * pClear, 
	TOutput * pError, 
	SKIPFUNC fnSkip,
	IDLEFUNC fnIdle,
	IDLEINFO * pIdleInfo
)
{
	BOOL			bIdle;
	PRIMARY			Primary = 0;
	SECONDARY		*Secondary[100];

	while ( (bIdle = fnIdle(pIdleInfo)) && (!(pInput->Eof())) )
	{
		BOOL bStatus = TRUE;
		BOOL bool_step_begin = TRUE;
		BOOL bool_step_store = TRUE;
		BOOL bImport = FALSE;
	
		pLog->BeginWrite((char *)szImport, 0);
		pInput->BeginRead();

		if (bStatus)
		{
			pLog->BeginWrite((char *)szLoad, 0);
			RETVALUE retvalue = pObject->Load(pInput, pMemory, pLog);
			switch(retvalue)
			{
			case PARSER_SUCCESS:
			case PARSER_SUCCESS_WITH_INFO:
				break;
			case PARSER_NO_DATA_FOUND:
				pLog->Write((char *)szLoad, 0, TLog::Error, 1, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
				bStatus = FALSE;
				break;
			case PARSER_ERROR:
				pLog->Write((char *)szLoad, 0, TLog::Error, 1, (char *)cszError, sizeof(cszError)-1);
				bStatus = FALSE;
				break;
			}
			pLog->EndWrite((char *)szLoad, 0, retvalue);
		}

		if (bStatus) 
		{
			pLog->BeginWrite((char *)szValidate, 0);
			RETVALUE retvalue = pObject->Validate(pMemory, pLog);
			switch(retvalue)
			{
			case PARSER_SUCCESS:
			case PARSER_SUCCESS_WITH_INFO:
				break;
			case PARSER_NO_DATA_FOUND:
			case PARSER_ERROR:
				pLog->Write((char *)szValidate, 0, TLog::Error, 1, (char *)cszError, sizeof(cszError)-1);
				bStatus = FALSE;
				break;
			}
			pLog->EndWrite((char *)szValidate, 0, retvalue);
		}

		bStatus = bStatus && (bImport = bool_step_begin = (pMonitor->BeginImport(pLog, &Primary)));
		if ( !bool_step_begin )
		{
			const char cszErrorMsg[] = "Error execute method BeginImport";
			pLog->Write((char *)szImport, 0, TLog::Error, 1, (char *)cszErrorMsg, sizeof(cszErrorMsg)-1);
		}

		if (bStatus)
		{
			char buffer[256];
			sprintf(buffer, "Message id=%lu", Primary);
			pLog->Write((char *)szImport, 0, TLog::Information, 1, buffer, strlen(buffer));
		}

		if (bStatus) 
		{
			pLog->BeginWrite((char *)szInsert, 0);
			RETVALUE retvalue = pObject->Insert(pMonitor, pMemory, pLog, NULL, &Primary, Secondary, 0);
			switch(retvalue)
			{
			case PARSER_SUCCESS:
			case PARSER_SUCCESS_WITH_INFO:
				break;
			case PARSER_ERROR:
				pLog->Write((char *)szInsert, 0, TLog::Error, 1, (char *)cszError, sizeof(cszError)-1);
				bStatus = FALSE;
				break;
			}
			pLog->EndWrite((char *)szInsert, 0, retvalue);
		}

		if (bStatus) 
		{
			pLog->BeginWrite((char *)szStore, 0);
			RETVALUE retvalue = pObject->Store(pClear, pMemory, pLog);
			switch(retvalue)
			{
			case PARSER_SUCCESS:
			case PARSER_SUCCESS_WITH_INFO:
				break;
			case PARSER_ERROR:
				pLog->Write((char *)szStore, 0, TLog::Error, 1, (char *)cszError, sizeof(cszError)-1);
				bStatus = FALSE;
				break;
			}
			pLog->EndWrite((char *)szStore, 0, retvalue);
		}

		if (bImport) ((TMonitor *)pMonitor)->EndImport(pLog, &Primary, bStatus) ;

		pInput->EndRead(bStatus);
	
		if (bStatus)
		{
			pIdleInfo->lSuccess++;

			const char szMessage[] = "Message imported success";
			pLog->Write((char *)szImport, 0, TLog::Information, 1, (char *)szMessage, sizeof(szMessage)-1);
			pLog->EndWrite((char *)szImport, 0, PARSER_SUCCESS);

			fwrite((char *)cszSuccessPrefix, 1, sizeof(cszSuccessPrefix)-1, __logfile);

			fwrite((char *)cszHeaderPrefix, 1, sizeof(cszHeaderPrefix)-1, __logfile);
			pShortReport->BeginImport(pLog, &Primary);
			pObject->Insert(pShortReport, pMemory, pLog, NULL, &Primary, Secondary, 0);
			pShortReport->EndImport(pLog, &Primary, TRUE);
			fwrite((char *)cszHeaderSuffix, 1, sizeof(cszHeaderSuffix)-1, __logfile);

			fwrite((char *)cszWarningsPrefix, 1, sizeof(cszWarningsPrefix)-1, __logfile);
			pLog->Flush();
			fwrite((char *)cszWarningsSuffix, 1, sizeof(cszWarningsSuffix)-1, __logfile);

			fwrite((char *)cszDebugPrefix, 1, sizeof(cszDebugPrefix)-1, __logfile);
			fwrite((char *)cszDebugSuffix, 1, sizeof(cszDebugSuffix)-1, __logfile);

			fwrite((char *)cszSuccessSuffix, 1, sizeof(cszSuccessSuffix)-1, __logfile);
		}
		else
		{
			pIdleInfo->lError++;

			pLog->Write((char *)szImport, 0, TLog::Warning, 1, (char *)cszCopy, sizeof(cszCopy)-1);

			if (!fnSkip(pInput, pError))
			{
				pLog->Write((char *)szImport, 0, TLog::Error, 1, (char *)cszCopyError, sizeof(cszCopyError)-1);
			}

			pLog->EndWrite((char *)szImport, 0, PARSER_ERROR);

			fwrite((char *)cszErrorPrefix, 1, sizeof(cszErrorPrefix)-1, __logfile);

			fwrite((char *)cszHeaderPrefix, 1, sizeof(cszHeaderPrefix)-1, __logfile);
			pShortReport->BeginImport(pLog, &Primary);
			pObject->Insert(pShortReport, pMemory, pLog, NULL, &Primary, Secondary, 0);
			pShortReport->EndImport(pLog, &Primary, TRUE);
			fwrite((char *)cszHeaderSuffix, 1, sizeof(cszHeaderSuffix)-1, __logfile);

			fwrite((char *)cszWarningsPrefix, 1, sizeof(cszWarningsPrefix)-1, __logfile);
			pLog->Flush();
			fwrite((char *)cszWarningsSuffix, 1, sizeof(cszWarningsSuffix)-1, __logfile);

			fwrite((char *)cszDebugPrefix, 1, sizeof(cszDebugPrefix)-1, __logfile);
			pReport->BeginImport(pLog, &Primary);
			pObject->Insert(pReport, pMemory, pLog, NULL, &Primary, Secondary, 0);
			pReport->EndImport(pLog, &Primary, TRUE);
			fwrite((char *)cszDebugSuffix, 1, sizeof(cszDebugSuffix)-1, __logfile);

			fwrite((char *)cszErrorSuffix, 1, sizeof(cszErrorSuffix)-1, __logfile);
		}


		pObject->Refresh(pMemory);
	}

	if (!bIdle)
	{
		while ( !(pInput->Eof()))
		{
			fnIdle(pIdleInfo);
			pIdleInfo->lError++;

			pLog->Write((char *)szImport, 0, TLog::Information, 1, (char *)cszCopy, sizeof(cszCopy)-1);

			if (!fnSkip(pInput, pError))
			{
				pLog->Write((char *)szImport, 0, TLog::Error, 1, (char *)cszCopyError, sizeof(cszCopyError)-1);
			}
			else pIdleInfo->lError++;

			pLog->Write((char *)szImport, 0, TLog::Warning, 1, (char *)cszTerminatedByUser, sizeof(cszTerminatedByUser)-1);
		}

		fwrite((char *)cszErrorPrefix, 1, sizeof(cszErrorPrefix)-1, __logfile);

		fwrite((char *)cszHeaderPrefix, 1, sizeof(cszHeaderPrefix)-1, __logfile);
		const char cszText[] = "O ??? ???????????? ???????????? ???? ?????? ????????????????????????";
		fwrite((char *)cszText, 1, sizeof(cszText)-1, __logfile);
		fwrite((char *)cszHeaderSuffix, 1, sizeof(cszHeaderSuffix)-1, __logfile);

		fwrite((char *)cszWarningsPrefix, 1, sizeof(cszWarningsPrefix)-1, __logfile);
		pLog->Flush();
		fwrite((char *)cszWarningsSuffix, 1, sizeof(cszWarningsSuffix)-1, __logfile);

		fwrite((char *)cszDebugPrefix, 1, sizeof(cszDebugPrefix)-1, __logfile);
		fwrite((char *)cszDebugSuffix, 1, sizeof(cszDebugSuffix)-1, __logfile);

		fwrite((char *)cszErrorSuffix, 1, sizeof(cszErrorSuffix)-1, __logfile);
	}
}

