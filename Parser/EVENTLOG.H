#ifndef __EVENTLOG_H
#define __EVENTLOG_H

///////////////////////////////////////////////////////////////////////////////////
// Windows Event Log header
// File eventlog.h
// Copyright © 1996
// Programmer: Dmitry Protopopov
////////////////////////////////////////////////////////////////////////////////
class TEventLog : public TLog
{
protected:
char *m_pszUNCServerName;
char *m_pszSourceName;
HANDLE m_hEventLog;

public:
TEventLog(char *pszUNCServerName, char *pszSourceName);
~TEventLog();

public:
virtual BOOL Create();
virtual BOOL Destroy();
virtual BOOL Flush();
};

///////////////////////////////////////////////////////////////////////////////////

#endif // __EVENTLOG_H