//////////////////////////////////
// System level dependencies

#include <windows.h>

//////////////////////////////////
// ANSI level dependencies

#include <stdio.h>
#include <time.h>

//////////////////////////////////
// Application level dependencies

#include "tlog.h"
#include "tdb.h"

/////////////////////////////////

const char TDatabase::szComma[] = ",";
const char TDatabase::szEqual[] = "=";
const char TDatabase::szInsertInto[] = "INSERT INTO ";
const char TDatabase::szValues[] = " VALUES ";
const char TDatabase::szUpdate[] = "UPDATE ";
const char TDatabase::szSet[] = " SET ";
const char TDatabase::szSelect[] = "SELECT ";
const char TDatabase::szFrom[] = " FROM ";
const char TDatabase::szOrderBy[] = " ORDER BY ";
const char TDatabase::szWhere[] = " WHERE ";
const char TDatabase::szAnd[] = " AND ";
const char TDatabase::szBeginTrans[] = "BEGIN TRANSACTION";
const char TDatabase::szCommitTrans[] = "COMMIT TRANSACTION";
const char TDatabase::szRollbackTrans[] = "ROLLBACK TRANSACTION";

TFileDatabase::TFileDatabase(FILE *pFile)
{
	m_pFile = pFile;
	m_sizeccAttribute = 0;
	m_offsAttribute = 0;
	m_ccAttribute = 0;
}

TFileDatabase::~TFileDatabase()
{
}


BOOL TFileDatabase::OpenDomain(TLog *pLog, char *pszDomain)
{
	return TRUE;
}

BOOL TFileDatabase::CloseDomain(TLog *pLog, char *pszDomain)
{
	return TRUE;
}

BOOL TFileDatabase::GetPrimary(TLog *pLog, char *pszDomain, PRIMARY *pPrimary)
{
	return TRUE;
}

BOOL TFileDatabase::GetSecondary(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary, SECONDARY *pSecondary)
{
	(*pSecondary)++;
	return TRUE;
}

BOOL TFileDatabase::SetAttribute(TLog *pLog, char *pszDomain, char *pszAttribute, PRIMARY * pPrimary, SECONDARY **ppSecondary, UINT nSecondary, int type, void * pBuffer, UINT  cbBuffer)
{
	if (type == TDatabase::Null) return TRUE;

	struct stkAttribute * pstkAttribute
		= &m_stkAttribute[m_offsAttribute + m_ccAttribute++];

	pstkAttribute->pszAttribute = pszAttribute;
	pstkAttribute->type = type;
	pstkAttribute->pBuffer = pBuffer;
	pstkAttribute->cbBuffer = cbBuffer;

	return TRUE;
}

BOOL TFileDatabase::AddNew(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary)
{
	UINT i;
	struct stkccAttribute * pstkccAttribute
		= &m_stkccAttribute[m_sizeccAttribute++];

	pstkccAttribute->ccAttribute = m_ccAttribute;
	m_offsAttribute += m_ccAttribute;
	m_ccAttribute = 0;

	fprintf(m_pFile, "INSERT INTO [%s](id", pszDomain);
	for ( i = 0 ; i < nSecondary ; i++ )
		fprintf(m_pFile, ",seq_num%d", i);

	fprintf(m_pFile, ") VALUES (%ld", (*pPrimary));
	
	for ( i = 0 ; i < nSecondary; i++)
		fprintf(m_pFile, ",%ld", (*ppSecondary[i]));

	fprintf(m_pFile, ");\n");
	return TRUE;
}

BOOL TFileDatabase::Update(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary, BOOL bCommit)
{
	if (m_ccAttribute != 0)
	{

		fprintf(m_pFile, "UPDATE [%s] SET ", pszDomain);

		while (m_ccAttribute)
		{
			struct stkAttribute * pstkAttribute 
				= &m_stkAttribute[m_offsAttribute + (--m_ccAttribute)];

			fprintf(m_pFile, "[%s]=", (pstkAttribute->pszAttribute));
		
			switch (pstkAttribute->type)
			{
			case TDatabase::Primary:
			case TDatabase::Secondary:
			case TDatabase::Integer:

				fprintf(m_pFile, "%ld", *(ULONG *)(pstkAttribute->pBuffer));
				break;

			case TDatabase::Decimal:
				fwrite((pstkAttribute->pBuffer), 1, (pstkAttribute->cbBuffer), m_pFile);
				break;

			case TDatabase::Text:
			case TDatabase::Multitext:
				fprintf(m_pFile, "'"); 
				fwrite((pstkAttribute->pBuffer), 1, (pstkAttribute->cbBuffer), m_pFile);
				fprintf(m_pFile, "'"); 
				break;

			case TDatabase::Datetime:
				{
					char buffer[256];
					strftime (buffer, sizeof(buffer), "'%d/%m/%Y %H:%M:%S'", (struct tm *)(pstkAttribute->pBuffer));
					fprintf(m_pFile, "%s", buffer); 
				}
				break;
			}
			if (m_ccAttribute) fprintf(m_pFile, ",");

		}

		fprintf(m_pFile, " WHERE id=%ld", (*pPrimary));
		while (nSecondary--) fprintf(m_pFile, " AND seq_num%d=%ld", nSecondary, (*ppSecondary[nSecondary]));
		fprintf(m_pFile, ";\n");
	}

	struct stkccAttribute * pstkccAttribute
		= &m_stkccAttribute[--m_sizeccAttribute];

	m_ccAttribute = pstkccAttribute->ccAttribute;
	m_offsAttribute -= m_ccAttribute;

	return TRUE;
}

BOOL TFileDatabase::BeginImport(TLog *pLog, PRIMARY *pPrimary)
{
	fprintf(m_pFile, "BEGIN TRANSACTION;\n");
	(*pPrimary)++;
	return TRUE;
}

BOOL TFileDatabase::EndImport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit)
{
	fprintf(m_pFile, (bCommit?"COMMIT TRANSACTION;\n":"ROLLBACK TRANSACTION;\n"));
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////
// class TFileReport

const char cszEol[] = "\r\n";
const char cszNoDataFound[] = "***No Data Found***";

TFileReport::TFileReport(FILE *pFile)
{
	m_pFile = pFile;
}

TFileReport::~TFileReport()
{
}

BOOL TFileReport::OpenDomain(TLog *pLog, char *pszDomain)
{
	return TRUE;
}

BOOL TFileReport::CloseDomain(TLog *pLog, char *pszDomain)
{
	return TRUE;
}

BOOL TFileReport::GetPrimary(TLog *pLog, char *pszDomain, PRIMARY *pPrimary)
{
	static PRIMARY GlobalPrimaryId = 1;
	*pPrimary = GlobalPrimaryId++;
	return TRUE;
}

BOOL TFileReport::GetSecondary(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary, SECONDARY *pSecondary)
{
	(*pSecondary)++;
	return TRUE;
}

BOOL TFileReport::SetAttribute(TLog *pLog, char *pszDomain, char *pszAttribute, PRIMARY * pPrimary, SECONDARY **ppSecondary, UINT nSecondary, int type, void * pBuffer, UINT  cbBuffer)
{
	char buffer[256];
	sprintf(buffer, "    %-40s : ", pszAttribute);
	fwrite(buffer, 1, strlen(buffer), m_pFile);
	switch(type)
	{
	case TDatabase::Null:
		fwrite(cszNoDataFound, 1, sizeof(cszNoDataFound)-1, m_pFile);
		break;
	case TDatabase::Integer:
		sprintf(buffer, "%ld", *(LONG *)pBuffer);
		fwrite(buffer, 1, strlen(buffer), m_pFile);
		break;
	case TDatabase::Text:
	case TDatabase::Decimal:
		if (cbBuffer) fwrite(pBuffer, 1, cbBuffer, m_pFile);
		break;
	case TDatabase::Multitext:
		{
			char * ptr = (char *)pBuffer;
			while (cbBuffer--) 
			{
				if ((*ptr) == '\0')
				{
					fwrite((char *)cszEol, 1, sizeof(cszEol)-1, m_pFile);
					for( int i = 44 ; i-- ; ) fwrite(" ", 1, 1, m_pFile);
					fwrite(" : ", 1, 3, m_pFile);
				}
				else
					fwrite(ptr, 1, 1, m_pFile);

				ptr++;
			}
		}
		break;
	case TDatabase::Datetime:
		UINT len = strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", (struct tm *)pBuffer);
		fwrite(buffer, 1, len, m_pFile);
		break;

	}
	fwrite((char *)cszEol, 1, sizeof(cszEol)-1, m_pFile);
	fflush(m_pFile);
	return TRUE;
}

BOOL TFileReport::AddNew(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary)
{
	if (pszDomain[0] == ':')
	{
		fwrite(pszDomain, 1, strlen(pszDomain), m_pFile);
		fwrite((char *)cszEol, 1, sizeof(cszEol)-1, m_pFile);
	}
	return TRUE;
}

BOOL TFileReport::Update(TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary, BOOL bCommit)
{
	return TRUE;
}

BOOL TFileReport::BeginImport(TLog *pLog, PRIMARY *pPrimary)
{
	return TRUE;
}

BOOL TFileReport::EndImport(TLog *pLog, PRIMARY *pPrimary, BOOL bCommit)
{
	return TRUE;
}
