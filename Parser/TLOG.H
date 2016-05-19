#ifndef __TLOG_H
#define __TLOG_H

extern FILE * __logfile;

////////////////////////////////////////////////////////////////////////////
// Log classes
// File tlog.h
// Copyriht © 1996
////////////////////////////////////////////////////////////////////////////////
class TLog
{
public:
enum { Error, Warning,  Information };
enum { Load, Store, Select, Insert };

protected:
char *m_pStack1;
char *m_pStack2;
UINT m_nRows;

public:
virtual BOOL Create() ;
virtual BOOL Destroy() ;
virtual BOOL BeginWrite(char *pszObjectName, UINT nLevel);
virtual BOOL EndWrite(char *pszObjectName, UINT nLevel, int retvalue) ;
virtual BOOL Write(char *pszObjectName, UINT nLevel, int type, int category, char *pszMessage, UINT nMessageLen);
virtual BOOL Flush() = 0;

protected:
static BOOL Push(char **ppStack, void *pBuffer, UINT nSize);
static BOOL Pop(char **ppStack, void *pBuffer, UINT nSize);
};

//////////////////////////////////////////////////////////////////////////////
class TFileLog : public TLog
{
protected:
FILE *m_pFile;

public:
TFileLog(FILE *pFile);
~TFileLog();

public:
virtual BOOL Flush();

protected:
static const char szError[];
static const char szWarning[];
static const char szInformation[];
};

//////////////////////////////////////////////////////////////////////////

#endif // __TLOG_H