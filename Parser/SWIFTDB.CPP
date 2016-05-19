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
#include "swiftdb.h"

////////////////////////////////////////////////////////////
// SWIFT DATABASE IMPLEMENTATION
// File swiftdb.cpp
// Copyright © 1996, Asset Information Management
// Copyright © 1997, Asset Information Management
// Programmer: Dmitry Protopopov
////////////////////////////////////////////////////////////
char TSwiftDatabase::szExportSelectFormat[] = "SELECT DISTINCT MIN(id) FROM message_desc WHERE msg_dir='I' AND msg_busy_f=0 AND msg_nonsw_f=0 AND msg_sign_f=1 AND id>%lu AND receiver NOT LIKE '<%%>'";

TSwiftDatabase::TSwiftDatabase(char *pszDSN, char *pszUID, char *pszAuthStr, TMemory *pMemory)
  : TOdbcDatabase(pszDSN, pszUID, pszAuthStr, pMemory, SWIFT_DB, TSwiftDatabase::szExportSelectFormat)
{
}

TSwiftDatabase::~TSwiftDatabase() 
{
}

