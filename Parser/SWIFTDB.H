#ifndef __SWIFTDB_H
#define __SWIFTDB_H

////////////////////////////////////////////////////////////
// SWIFT DATABASE HEADER
// File swiftdb.h
// Copyright © 1996 Asset Information Management
// Programmer: Dmitry Protopopov
////////////////////////////////////////////////////////////
class TSwiftDatabase : public TOdbcDatabase
{
public:
TSwiftDatabase(char *pszDSN, char *pszUID, char *pszAuthStr, TMemory *pMemory);
~TSwiftDatabase();
protected:
static char szExportSelectFormat[];
};

/////////////////////////////////////////////////////////////

#endif // __SWIFTDB_H