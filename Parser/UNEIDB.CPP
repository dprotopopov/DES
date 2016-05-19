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
#include "uneidb.h"

////////////////////////////////////////////////////////////
// UNEXIM DATABASE IMPLEMENTATION
// File uneidb.cpp
// Copyright © 1996, Asset Information Management
// Copyright © 1997, Asset Information Management
// Programmer: Dmitry Protopopov
////////////////////////////////////////////////////////////

char TUneiSwiftDatabase::szExportSelectFormat[] = "SELECT DISTINCT MIN(id) FROM message_desc WHERE msg_dir='I' AND msg_busy_f=0 AND msg_nonsw_f=0 AND msg_sign_f=1 AND id>%lu AND NOT msg_type='202' AND receiver NOT LIKE '<%%>'";

TUneiSwiftDatabase::TUneiSwiftDatabase(char *pszDSN, char *pszUID, char *pszAuthStr, TMemory *pMemory)
  : TOdbcDatabase(pszDSN, pszUID, pszAuthStr, pMemory, SWIFT_DB, TUneiSwiftDatabase::szExportSelectFormat)
{
}

TUneiSwiftDatabase::~TUneiSwiftDatabase() 
{
}

char TUneiMessageDatabase::szExport041SelectFormat[] = "SELECT DISTINCT MIN(h.id) FROM MT202 mt, message_desc h WHERE mt.id=h.id AND h.msg_dir='I' AND h.msg_busy_f=0 AND h.msg_nonsw_f=0 AND h.msg_sign_f=1 AND h.id>%lu AND NOT mt.val_curr_iso='RUR' AND mt.ben_crdr_f IS NOT NULL AND h.msg_type='202' AND mt.ben_crdr_f IN ('C','D') AND h.receiver NOT LIKE '<%%>'";

char TUneiMessageDatabase::szExport044SelectFormat[] = "SELECT DISTINCT MIN(h.id) FROM MT202 mt, message_desc h WHERE mt.id=h.id AND h.msg_dir='I' AND h.msg_busy_f=0 AND h.msg_nonsw_f=0 AND h.msg_sign_f=1 AND h.id>%lu AND mt.val_curr_iso='RUR' AND mt.ben_crdr_f IS NOT NULL AND h.msg_type='202' AND mt.ben_crdr_f IN ('C','D') AND h.receiver NOT LIKE '<%%>'";

TUneiMessageDatabase::TUneiMessageDatabase(char *pszDSN, char *pszUID, char *pszAuthStr, TMemory *pMemory, char * pszExportSelectFormat)
  : TOdbcDatabase(pszDSN, pszUID, pszAuthStr, pMemory, UNEI_DB, pszExportSelectFormat)
{
}

TUneiMessageDatabase::~TUneiMessageDatabase() 
{
}

char TMicexDatabase::szExportSelectFormat[] = "SELECT DISTINCT MIN(id) FROM message_desc WHERE msg_dir='I' AND msg_busy_f=0 AND msg_nonsw_f=0 AND msg_sign_f=1 AND id>%lu AND receiver LIKE '<%%>'";

TMicexDatabase::TMicexDatabase(char *pszDSN, char *pszUID, char *pszAuthStr, TMemory *pMemory)
  : TOdbcDatabase(pszDSN, pszUID, pszAuthStr, pMemory, MICEX_DB, TMicexDatabase::szExportSelectFormat)
{
}

TMicexDatabase::~TMicexDatabase() 
{
}

