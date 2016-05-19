#ifndef __UNEIDB_H
#define __UNEIDB_H

////////////////////////////////////////////////////////////////////
// UNEXIM DATABASE HEADER
// File uneidb.h
// Copyright © 1996, Asset Information Management
// Copyright © 1997, Asset Information Management
// Programmer: Dmitry Protopopov
////////////////////////////////////////////////////////////
class TUneiSwiftDatabase : public TOdbcDatabase
{
public:
TUneiSwiftDatabase(char *pszDSN, char *pszUID, char *pszAuthStr, TMemory *pMemory);
~TUneiSwiftDatabase();
protected:
static char szExportSelectFormat[];
};

//////////////////////////////////////////////////////////////////////
class TUneiMessageDatabase : public TOdbcDatabase
{
public:
TUneiMessageDatabase(char *pszDSN, char *pszUID, char *pszAuthStr, TMemory *pMemory, char * pszExportSelectFormat);
~TUneiMessageDatabase();

public:
static char szExport041SelectFormat[];
static char szExport044SelectFormat[];
};

////////////////////////////////////////////////////////////////////
class TMicexDatabase : public TOdbcDatabase
{
public:
TMicexDatabase(char *pszDSN, char *pszUID, char *pszAuthStr, TMemory *pMemory);
~TMicexDatabase();
protected:
static char szExportSelectFormat[];
};

//////////////////////////////////////////////////////////////////////

#endif // __UNEIDB_H