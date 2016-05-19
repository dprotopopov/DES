#ifndef __PARSER_H
#define __PARSER_H

class PObject;
class TLog;
class TMemory;
class TReport;
class TArchive;
class TMonitor;
class TInput;
class TOutput;

extern struct tm g_tmBasic;

typedef struct tagIDLEINFO {
	char	*pszCmdLine;
	ULONG	lSuccess;
	ULONG	lError;
	ULONG	lPosition;
	ULONG	lFileSize;
	struct tm tmStart;
	struct tm tmFinish;
} IDLEINFO;

typedef BOOL (*IDLEFUNC)(IDLEINFO *);
typedef BOOL (*SKIPFUNC)(TInput *, TOutput *);

BOOL DefaultIdle(IDLEINFO *);
void DefaultExport(PObject * pObject, TLog * pLog, TReport * pReport, TReport * pShortReport, TMemory * pMemory, TArchive * pArchive, TOutput * pOutput, IDLEFUNC fnIdle, IDLEINFO * pIdleInfo);
void DefaultImport(PObject * pObject, TLog * pLog, TReport * pReport, TReport * pShortReport, TMemory * pMemory, TMonitor * pMonitor, TInput * pInput, TOutput * pClear, TOutput * pError, SKIPFUNC fnSkip, IDLEFUNC fnIdle, IDLEINFO * pIdleInfo);

#endif // __PARSER_H