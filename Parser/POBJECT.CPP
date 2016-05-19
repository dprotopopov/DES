//////////////////////////////////
// System level dependencies

#include <windows.h>

//////////////////////////////////
// ANSI level dependencies

#include <stdio.h>
#include <string.h>
#include <time.h>

//////////////////////////////////
// Application level dependencies

#include "tio.h"
#include "tdb.h"
#include "tlog.h"
#include "tmemory.h"
#include "pobject.h"

const char cszError[] = "***Error***";
const char cszSuccess[] = "***Success***";
const char cszSuccessWithInfo[] = "***Success with info***";
const char cszNoDataFound[] = "***No data found***";

/////////////////////////////////////////////////////////////
// Container's constructors/destructors

PContainer::PContainer() : PObject()
{
}

PContainer::~PContainer()
{
}

PSequence::PSequence() : PContainer()
{
}

PSequence::~PSequence()
{
}

PParallel::PParallel() : PContainer()
{
}

PParallel::~PParallel()
{
}

PSwitch::PSwitch() : PContainer()
{
}

PSwitch::~PSwitch()
{
}

PPointer::PPointer() : PContainer()
{
}

PPointer::~PPointer()
{
}


PRepeat::PRepeat() : PPointer()
{
}

PRepeat::~PRepeat()
{
}

PLoop::PLoop() : PContainer()
{
}

PLoop::~PLoop()
{
}

////////////////////////////////////////////////////////////////////
// Store method
// PContainer::Store is default for PSequence, PParallel and PRepead

RETVALUE PContainer::Store(TOutput * pOutput, TMemory *pMemory, TLog * pLog) 
{
	PObject * pChild = GetFirstChild();
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bCommit = TRUE;

	while (bStatus && (pChild != NULL))
	{
		pLog->BeginWrite(this->GetObjectName(), m_nLevel);
		RETVALUE i = pChild->Store(pOutput, pMemory, pLog);
		pLog->EndWrite(this->GetObjectName(), m_nLevel, i);

		switch(i)
		{
		case PARSER_SUCCESS:

			pChild = pChild->GetNext();
			break;

		case PARSER_SUCCESS_WITH_INFO:

			retvalue = PARSER_SUCCESS_WITH_INFO;
			pChild = pChild->GetNext();
			break;

		case PARSER_ERROR:

			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}

	return retvalue; 
}

////////////////////////////////////////////////////////////
// Insert Method
// PContainer::Insert is default for PSequence and PParallel
// PRepead has own one

RETVALUE PContainer::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bCommit = TRUE;
	BOOL bOpen = FALSE;
	BOOL bInsert = FALSE;

	if (m_pszDomain != NULL)
	{
		pszDomain = m_pszDomain;

		if (bStatus) switch (bOpen = (pMonitor->OpenDomain(pLog, m_pszDomain)))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bStatus) switch (bInsert = (pMonitor->AddNew(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary)))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}
	

	PObject * pChild = GetFirstChild();

	while (bStatus && (pChild != NULL) )
	{
		pLog->BeginWrite(this->GetObjectName(), m_nLevel);
		RETVALUE i = pChild->Insert(pMonitor, pMemory, pLog, pszDomain, pPrimary, ppSecondary, nSecondary);
		pLog->EndWrite(this->GetObjectName(), m_nLevel, i);

		switch(i)
		{
		case PARSER_SUCCESS:
			pChild = pChild->GetNext();
			break;
		case PARSER_SUCCESS_WITH_INFO:
			retvalue = PARSER_SUCCESS_WITH_INFO;
			pChild = pChild->GetNext();
			break;
		case PARSER_ERROR:
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}


	if (m_pszDomain != NULL)
	{
		if (bInsert) switch (pMonitor->Update(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary, bCommit))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bOpen) switch (pMonitor->CloseDomain(pLog, m_pszDomain))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

	}

	return retvalue; 
}

////////////////////////////////////////////////////////////////
// Load method

RETVALUE PSequence::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bCommit = TRUE;

	Preload(this, m_nLevel, pLog);
	pInput->BeginRead();

	while (bStatus && ((*m_pCommand) != NULL))
	{
		PObject * pChild = ((ALLOCFUNC)(m_pCommand[GW_ALLOC]))(pMemory);
		LPARAM lpStyle = (LPARAM)(m_pCommand[GW_STYLE]);
		pChild->Create(pMemory, lpStyle, m_pCommand, this, m_nLevel+1, m_pInstance);
		
		pLog->BeginWrite(this->GetObjectName(), m_nLevel);
		RETVALUE i = pChild->Load(pInput, pMemory, pLog);
		if ( (i == PARSER_NO_DATA_FOUND) && (lpStyle & OS_OPTIONAL) )
			pLog->EndWrite(this->GetObjectName(), m_nLevel, PARSER_SUCCESS);
		else
			pLog->EndWrite(this->GetObjectName(), m_nLevel, i);


		switch(i)
		{
		case PARSER_SUCCESS:

			Attach(pChild); 
			m_pCommand = ((MOVEFUNC)(m_pCommand[GW_MOVE]))(m_pCommand);
			break;

		case PARSER_SUCCESS_WITH_INFO:

			retvalue = PARSER_SUCCESS_WITH_INFO;
			Attach(pChild); 
			m_pCommand = ((MOVEFUNC)(m_pCommand[GW_MOVE]))(m_pCommand);
			break;

		case PARSER_NO_DATA_FOUND:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
#endif

			if (lpStyle & OS_OPTIONAL)
			{
				pChild->Destroy(pMemory);
				delete pChild;
				m_pCommand = ((MOVEFUNC)(m_pCommand[GW_MOVE]))(m_pCommand);
				break;
			}
			else
			{
				retvalue = PARSER_NO_DATA_FOUND;
				Attach(pChild);
				bCommit = FALSE;
				bStatus = FALSE;
				break;
			}

		case PARSER_ERROR:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
#endif

			retvalue = PARSER_ERROR;
			Attach(pChild);
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}

	pInput->EndRead(bCommit);
	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

//////////////////////////////////////////////////////////////
// Select method

RETVALUE PSequence::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bCommit = TRUE;
	BOOL bOpen = FALSE;
	BOOL bSelect = FALSE;
	BOOL bFetch = FALSE;

	Preselect(this, m_nLevel, pLog);
	if (m_pszDomain != NULL)
	{
		pszDomain = m_pszDomain;

		if (bStatus) switch (bOpen = (pArchive->OpenDomain(pLog, m_pszDomain)))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bStatus) switch (bSelect = (pArchive->BeginSelect(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary, FALSE)))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bStatus) switch (bFetch = (pArchive->Fetch(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary, FALSE)))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
			retvalue = PARSER_NO_DATA_FOUND;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}


	while (bStatus && ((*m_pCommand) != NULL)) 
	{
		PObject * pChild = ((ALLOCFUNC)(m_pCommand[GW_ALLOC]))(pMemory);
		LPARAM lpStyle = (LPARAM)(m_pCommand[GW_STYLE]);
		pChild->Create(pMemory, lpStyle, m_pCommand, this, m_nLevel+1, m_pInstance);

		pLog->BeginWrite(this->GetObjectName(), m_nLevel);
		RETVALUE i = pChild->Select(pArchive, pMemory, pLog, pszDomain, pPrimary, ppSecondary, nSecondary);
		if ( (i == PARSER_NO_DATA_FOUND) && (lpStyle & OS_OPTIONAL) )
			pLog->EndWrite(this->GetObjectName(), m_nLevel, PARSER_SUCCESS);
		else
			pLog->EndWrite(this->GetObjectName(), m_nLevel, i);


		switch(i)
		{
		case PARSER_SUCCESS:

#if defined(_DEBUG)
			{
				char szMessage[256];
				sprintf(szMessage, "Sequence container select %s", pChild->GetObjectName());
				pLog->Write(this->GetObjectName(), m_nLevel, TLog::Information, 0, szMessage, strlen(szMessage));
			}
#endif

			Attach(pChild); 
			m_pCommand = ((MOVEFUNC)(m_pCommand[GW_MOVE]))(m_pCommand);
			break;

		case PARSER_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
			{
				char szMessage[256];
				sprintf(szMessage, "Sequence container select with info %s", pChild->GetObjectName());
				pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, szMessage, strlen(szMessage));
			}
#endif

			retvalue = PARSER_SUCCESS_WITH_INFO;
			Attach(pChild); 
			m_pCommand = ((MOVEFUNC)(m_pCommand[GW_MOVE]))(m_pCommand);
			break;

		case PARSER_NO_DATA_FOUND:

#if defined(_DEBUG)
			{
				char szMessage[256];
				sprintf(szMessage, "Sequence container can not select %s", pChild->GetObjectName());
				pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, szMessage, strlen(szMessage));
			}
#endif

			if (lpStyle & OS_OPTIONAL)
			{
				pChild->Destroy(pMemory);
				delete pChild;
				m_pCommand = ((MOVEFUNC)(m_pCommand[GW_MOVE]))(m_pCommand);
				break;
			}
			else
			{
				retvalue = PARSER_NO_DATA_FOUND;
				Attach(pChild);
				bCommit = FALSE;
				bStatus = FALSE;
				break;
			}

		case PARSER_ERROR:

#if defined(_DEBUG)
			{
				char szMessage[256];
				sprintf(szMessage, "Sequence container detect error in %s", pChild->GetObjectName());
				pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, szMessage, strlen(szMessage));
			}
#endif

			retvalue = PARSER_ERROR;
			Attach(pChild);
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

	}

	if (m_pszDomain != NULL)
	{
		if (bSelect) switch (pArchive->EndSelect(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bOpen) switch (pArchive->CloseDomain(pLog, m_pszDomain))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

	}

	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

////////////////////////////////////////////
// Load method

RETVALUE PParallel::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_NO_DATA_FOUND;
	BOOL bCommit = FALSE;

	Preload(this, m_nLevel, pLog);
	pInput->BeginRead();

	while (bStatus && (!bCommit) && ((*m_pCommand) != NULL))
	{
		PObject * pChild = ((ALLOCFUNC)(m_pCommand[GW_ALLOC]))(pMemory);
		LPARAM lpStyle = (LPARAM)(m_pCommand[GW_STYLE]);
		pChild->Create(pMemory, lpStyle, m_pCommand, this, m_nLevel+1, m_pInstance);

		pLog->BeginWrite(this->GetObjectName(), m_nLevel);
		RETVALUE i = pChild->Load(pInput, pMemory, pLog);
		if ( (i == PARSER_NO_DATA_FOUND) && (lpStyle & OS_OPTIONAL) )
			pLog->EndWrite(this->GetObjectName(), m_nLevel, PARSER_SUCCESS);
		else
			pLog->EndWrite(this->GetObjectName(), m_nLevel, i);


		switch (i)
		{
		case PARSER_SUCCESS:

			retvalue = PARSER_SUCCESS;
			{
				PObject * pCurrent = GetFirstChild();
				while (pCurrent != NULL)
				{
					PObject * pNext = pCurrent->GetNext();
					pCurrent->Destroy(pMemory);
					delete pCurrent;
					pCurrent = pNext;
				}
				SetFirstChild(NULL);
			}
			Attach(pChild);
			bCommit = TRUE;
			break;

		case PARSER_SUCCESS_WITH_INFO:

			retvalue = PARSER_SUCCESS_WITH_INFO;
			{
				PObject * pCurrent = GetFirstChild();
				while (pCurrent != NULL)
				{
					PObject * pNext = pCurrent->GetNext();
					pCurrent->Destroy(pMemory);
					delete pCurrent;
					pCurrent = pNext;
				}
				SetFirstChild(NULL);
			}
			Attach(pChild);
			bCommit = TRUE;
			break;

		case PARSER_NO_DATA_FOUND:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
#endif
			
			if (m_lpStyle & OS_OPTIONAL)
			{
				pChild->Destroy(pMemory);
				delete pChild;
			}
			else
			{
				Attach(pChild);
			}
			m_pCommand = ((MOVEFUNC)(m_pCommand[GW_MOVE]))(m_pCommand);
			break;

		case PARSER_ERROR:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
#endif
			
			retvalue = PARSER_ERROR;
			Attach(pChild);
			bStatus = FALSE;
			break;
		}
	}


	pInput->EndRead(bCommit);
	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PParallel::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_NO_DATA_FOUND;
	BOOL bCommit = FALSE;
	BOOL bOpen = FALSE;
	BOOL bSelect = FALSE;
	BOOL bFetch = FALSE;

	Preselect(this, m_nLevel, pLog);

	if (m_pszDomain != NULL)
	{
		pszDomain = m_pszDomain;

		if (bStatus) switch (bOpen = (pArchive->OpenDomain(pLog, m_pszDomain)))
		{
		case TRUE:
			break;
		case FALSE:
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bStatus) switch (bSelect = (pArchive->BeginSelect(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary, FALSE)))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bStatus) switch (bFetch = (pArchive->Fetch(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary, FALSE)))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
			retvalue = PARSER_NO_DATA_FOUND;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}


	while (bStatus && (!bCommit) && ((*m_pCommand) != NULL)) 
	{
		PObject * pChild = ((ALLOCFUNC)(m_pCommand[GW_ALLOC]))(pMemory);
		LPARAM lpStyle = (LPARAM)(m_pCommand[GW_STYLE]);
		pChild->Create(pMemory, lpStyle, m_pCommand, this, m_nLevel+1, m_pInstance);

		pLog->BeginWrite(this->GetObjectName(), m_nLevel);
		RETVALUE i = pChild->Select(pArchive, pMemory, pLog, pszDomain, pPrimary, ppSecondary, nSecondary);
		if ( (i == PARSER_NO_DATA_FOUND) && (lpStyle & OS_OPTIONAL) )
			pLog->EndWrite(this->GetObjectName(), m_nLevel, PARSER_SUCCESS);
		else
			pLog->EndWrite(this->GetObjectName(), m_nLevel, i);


		switch (i)
		{
		case PARSER_SUCCESS:

#if defined(_DEBUG)
			{
				char szMessage[256];
				sprintf(szMessage, "Parallel container select %s", pChild->GetObjectName());
				pLog->Write(this->GetObjectName(), m_nLevel, TLog::Information, 0, szMessage, strlen(szMessage));
			}
#endif
			
			retvalue = PARSER_SUCCESS;
			{
				PObject * pCurrent = GetFirstChild();
				while (pCurrent != NULL)
				{
					PObject * pNext = pCurrent->GetNext();
					pCurrent->Destroy(pMemory);
					delete pCurrent;
					pCurrent = pNext;
				}
				SetFirstChild(NULL);
			}
			Attach(pChild);
			bCommit = TRUE;
			break;

		case PARSER_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
			{
				char szMessage[256];
				sprintf(szMessage, "Parallel container select with info %s", pChild->GetObjectName());
				pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, szMessage, strlen(szMessage));
			}
#endif
			
			retvalue = PARSER_SUCCESS_WITH_INFO;
			{
				PObject * pCurrent = GetFirstChild();
				while (pCurrent != NULL)
				{
					PObject * pNext = pCurrent->GetNext();
					pCurrent->Destroy(pMemory);
					delete pCurrent;
					pCurrent = pNext;
				}
				m_pFirstChild = NULL;
			}
			Attach(pChild);
			bCommit = TRUE;
			break;

		case PARSER_NO_DATA_FOUND:

#if defined(_DEBUG)
			{
				char szMessage[256];
				sprintf(szMessage, "Parallel container skip %s", pChild->GetObjectName());
				pLog->Write(this->GetObjectName(), m_nLevel, TLog::Information, 0, szMessage, strlen(szMessage));
			}
#endif

			if (m_lpStyle & OS_OPTIONAL)
			{
				pChild->Destroy(pMemory);
				delete pChild;
			}
			else
			{
				Attach(pChild);
			}
			m_pCommand = ((MOVEFUNC)(m_pCommand[GW_MOVE]))(m_pCommand);
			break;

		case PARSER_ERROR:

#if defined(_DEBUG)
			{
				char szMessage[256];
				sprintf(szMessage, "Parallel container detect error in %s", pChild->GetObjectName());
				pLog->Write(this->GetObjectName(), m_nLevel, TLog::Information, 0, szMessage, strlen(szMessage));
			}
#endif

			retvalue = PARSER_ERROR;
			Attach(pChild);
			bStatus = FALSE;
			break;
		}
	}

	if (m_pszDomain != NULL)
	{
		if (bSelect) switch (pArchive->EndSelect(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bOpen) switch (pArchive->CloseDomain(pLog, m_pszDomain))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}

	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

////////////////////////////////////////////
// Load method

RETVALUE PSwitch::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_ERROR;
	BOOL bCommit = FALSE;
	LPARAM lItemNumber;

	Preload(this, m_nLevel, pLog);
	lItemNumber = Pop();
	pInput->BeginRead();

	while (lItemNumber-- && ((*m_pCommand) != NULL) )
		m_pCommand = ((MOVEFUNC)(m_pCommand[GW_MOVE]))(m_pCommand);

	if ( bStatus && ((*m_pCommand) == NULL) )
	{
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
	}

	if (bStatus)
	{
		PObject * pChild = ((ALLOCFUNC)(m_pCommand[GW_ALLOC]))(pMemory);
		LPARAM lpStyle = (LPARAM)(m_pCommand[GW_STYLE]);
		pChild->Create(pMemory, lpStyle, m_pCommand, this, m_nLevel+1, m_pInstance);

		pLog->BeginWrite(this->GetObjectName(), m_nLevel);
		RETVALUE i = pChild->Load(pInput, pMemory, pLog);
		if ( (i == PARSER_NO_DATA_FOUND) && (lpStyle & OS_OPTIONAL) )
			pLog->EndWrite(this->GetObjectName(), m_nLevel, PARSER_SUCCESS);
		else
			pLog->EndWrite(this->GetObjectName(), m_nLevel, i);


		switch (i)
		{
		case PARSER_SUCCESS:

			retvalue = PARSER_SUCCESS;
			Attach(pChild);
			bCommit = TRUE;
			break;

		case PARSER_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszSuccessWithInfo, sizeof(cszSuccessWithInfo)-1);
#endif

			retvalue = PARSER_SUCCESS_WITH_INFO;
			Attach(pChild);
			bCommit = TRUE;
			break;

		case PARSER_NO_DATA_FOUND:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
#endif
			
			if (lpStyle & OS_OPTIONAL)
			{
				pChild->Destroy(pMemory);
				delete pChild;
			}
			else
			{
				Attach(pChild);
			}
			retvalue = PARSER_NO_DATA_FOUND;
			bCommit = FALSE;
			break;

		case PARSER_ERROR:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
#endif

			retvalue = PARSER_ERROR;
			Attach(pChild);
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}

	pInput->EndRead(bCommit);
	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PSwitch::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue;
	BOOL bCommit = TRUE;
	LPARAM lItemNumber;
	BOOL bOpen = FALSE;
	BOOL bSelect = FALSE;
	BOOL bFetch = FALSE;

	Preselect(this, m_nLevel, pLog);
	lItemNumber = Pop();

	while( lItemNumber-- && ((*m_pCommand) != NULL) )
		m_pCommand = ((MOVEFUNC)(m_pCommand[GW_MOVE]))(m_pCommand);

	if (bStatus && ((*m_pCommand) == NULL))
	{
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
	}

	if (m_pszDomain != NULL)
	{
		pszDomain = m_pszDomain;

		if (bStatus) switch (bOpen = (pArchive->OpenDomain(pLog, m_pszDomain)))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bStatus) switch (bSelect = (pArchive->BeginSelect(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary, FALSE)))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bStatus) switch (bFetch = (pArchive->Fetch(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary, FALSE)))
		{
		case TRUE:
			break;
		case FALSE:
			retvalue = PARSER_NO_DATA_FOUND;
			bCommit = FALSE;
			break;
		}
	}


	if (bStatus && bCommit)
	{
		PObject * pChild = ((ALLOCFUNC)(m_pCommand[GW_ALLOC]))(pMemory);
		LPARAM lpStyle = (LPARAM)(m_pCommand[GW_STYLE]);
		pChild->Create(pMemory, lpStyle, m_pCommand, this, m_nLevel+1, m_pInstance);

		pLog->BeginWrite(this->GetObjectName(), m_nLevel);
		RETVALUE i = pChild->Select(pArchive, pMemory, pLog, pszDomain, pPrimary, ppSecondary, nSecondary);
		if ( (i == PARSER_NO_DATA_FOUND) && (lpStyle & OS_OPTIONAL) )
			pLog->EndWrite(this->GetObjectName(), m_nLevel, PARSER_SUCCESS);
		else
			pLog->EndWrite(this->GetObjectName(), m_nLevel, i);


		switch (i)
		{
		case PARSER_SUCCESS:

			retvalue = PARSER_SUCCESS;
			Attach(pChild);
			break;

		case PARSER_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszSuccessWithInfo, sizeof(cszSuccessWithInfo)-1);
#endif
			
			retvalue = PARSER_SUCCESS_WITH_INFO;
			Attach(pChild);
			break;

		case PARSER_NO_DATA_FOUND:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
#endif

			if (lpStyle & OS_OPTIONAL)
			{
				pChild->Destroy(pMemory);
				delete pChild;
			}
			else
			{
				Attach(pChild);
			}
			retvalue = PARSER_NO_DATA_FOUND;
			bCommit = FALSE;
			break;

		case PARSER_ERROR:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
#endif
			
			retvalue = PARSER_ERROR;
			Attach(pChild);
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}

	if (m_pszDomain != NULL)
	{
		if (bSelect) switch (pArchive->EndSelect(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bOpen) switch (pArchive->CloseDomain(pLog, m_pszDomain))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}

	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PPointer::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_NO_DATA_FOUND;
	BOOL bCommit = TRUE;

	Preload(this, m_nLevel, pLog);
	pInput->BeginRead();

		PObject * pChild = ((ALLOCFUNC)(m_pCommand[GW_ALLOC]))(pMemory);
		LPARAM lpStyle = (LPARAM)(m_pCommand[GW_STYLE]);
		pChild->Create(pMemory, lpStyle, m_pCommand, this, m_nLevel+1, m_pInstance);

	if (bStatus) switch (pChild->Load(pInput, pMemory, pLog))
	{
	case PARSER_SUCCESS:

		retvalue = PARSER_SUCCESS;
		Attach(pChild); 
		break;

	case PARSER_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszSuccessWithInfo, sizeof(cszSuccessWithInfo)-1);
#endif
		
		retvalue = PARSER_SUCCESS_WITH_INFO;
		Attach(pChild); 
		break;

	case PARSER_NO_DATA_FOUND:

			if (lpStyle & OS_OPTIONAL)
			{
				pChild->Destroy(pMemory);
				delete pChild;
			}
			else
			{
				Attach(pChild);
			}
		retvalue = PARSER_NO_DATA_FOUND;
		bCommit = FALSE;
		break;

	case PARSER_ERROR:

#if defined(_DEBUG)
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
#endif
		
		retvalue = PARSER_ERROR;
		pChild->Destroy(pMemory);
		delete pChild;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	pInput->EndRead(bCommit);
	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PPointer::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bCommit = TRUE;
	BOOL bOpen = FALSE;
	BOOL bInsert = FALSE;
	PObject * ptr = GetFirstChild();

	if (!ptr)
	{
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
	}

	if (bStatus) switch (bOpen = (pMonitor->OpenDomain(pLog, m_pszDomain)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bStatus) switch (pMonitor->GetPrimary(pLog, m_pszDomain, &m_idCurrent))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bStatus) switch (bInsert = (pMonitor->AddNew(pLog, m_pszDomain, &m_idCurrent, ppSecondary, nSecondary)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bStatus) switch (ptr->Insert(pMonitor, pMemory, pLog, m_pszDomain, &m_idCurrent, ppSecondary, nSecondary))
	{
	case PARSER_SUCCESS:
		break;

	case PARSER_SUCCESS_WITH_INFO:

#if defined(_DEBUG)
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszSuccessWithInfo, sizeof(cszSuccessWithInfo)-1);
#endif
		
		retvalue = PARSER_SUCCESS_WITH_INFO;
		break;

	case PARSER_ERROR:

#if defined(_DEBUG)
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
#endif
		
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bInsert) switch (pMonitor->Update(pLog, m_pszDomain, &m_idCurrent, ppSecondary, nSecondary, bCommit))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bOpen) switch (pMonitor->CloseDomain(pLog, m_pszDomain))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bStatus) switch (pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Primary, &m_idCurrent))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	return retvalue; 
}

RETVALUE PPointer::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	PRIMARY idCurrent;
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bCommit = TRUE;
	BOOL bOpen = FALSE;
	BOOL bSelect = FALSE;
	BOOL bFetch = FALSE;

	Preselect(this, m_nLevel, pLog);
	if (bStatus) switch (pArchive->GetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Primary, &idCurrent, NULL, sizeof(PRIMARY)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bStatus) switch (bOpen = (pArchive->OpenDomain(pLog, m_pszDomain)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bStatus) switch (bSelect = (pArchive->BeginSelect(pLog, m_pszDomain, &idCurrent, ppSecondary, nSecondary, FALSE)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bStatus) switch (bFetch = (pArchive->Fetch(pLog, m_pszDomain, &idCurrent, ppSecondary, nSecondary, FALSE)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
		retvalue = PARSER_NO_DATA_FOUND;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bStatus) 
	{
		PObject * pChild = ((ALLOCFUNC)(m_pCommand[GW_ALLOC]))(pMemory);
		LPARAM lpStyle = (LPARAM)(m_pCommand[GW_STYLE]);
		pChild->Create(pMemory, lpStyle, m_pCommand, this, m_nLevel+1, m_pInstance);

		switch (pChild->Select(pArchive, pMemory, pLog, m_pszDomain, &idCurrent, ppSecondary, nSecondary))
		{
		case PARSER_SUCCESS:

			Attach(pChild);
			bCommit = TRUE;
			break;

		case PARSER_SUCCESS_WITH_INFO:

			retvalue = PARSER_SUCCESS_WITH_INFO;
			Attach(pChild);
			bCommit = TRUE;
			break;

		case PARSER_NO_DATA_FOUND:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
#endif
			
			if (lpStyle & OS_OPTIONAL)
			{
				pChild->Destroy(pMemory);
				delete pChild;
			}
			else
			{
				Attach(pChild);
			}
			retvalue = PARSER_NO_DATA_FOUND;
			bCommit = FALSE;
			break;

		case PARSER_ERROR:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
#endif
			
			retvalue = PARSER_ERROR;
			Attach(pChild);
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}

	if (bSelect) switch (pArchive->EndSelect(pLog, m_pszDomain, &idCurrent, ppSecondary, nSecondary))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bOpen) switch (pArchive->CloseDomain(pLog, m_pszDomain))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PRepeat::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bCommit = TRUE;

	Preload(this, m_nLevel, pLog);
	pInput->BeginRead();

	BOOL bEof = FALSE;

	while (bStatus && (m_size < m_maxsize) && !bEof)
	{
		PObject * pChild = ((ALLOCFUNC)(m_pCommand[GW_ALLOC]))(pMemory);
		LPARAM lpStyle = (LPARAM)(m_pCommand[GW_STYLE]);
		pChild->Create(pMemory, lpStyle, m_pCommand, this, m_nLevel+1, m_pInstance);

		switch (pChild->Load(pInput, pMemory, pLog))
		{
		case PARSER_SUCCESS:

			Attach(pChild);
			m_size++;
			break;

		case PARSER_SUCCESS_WITH_INFO:

			retvalue = PARSER_SUCCESS_WITH_INFO;
			Attach(pChild);
			m_size++;
			break;

		case PARSER_NO_DATA_FOUND:

			bEof = TRUE;
			pChild->Destroy(pMemory);
			delete pChild;
			break;

		case PARSER_ERROR:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
#endif

			retvalue = PARSER_ERROR;
			Attach(pChild);
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}

	if (bStatus && (m_size < m_minsize))
	{

#if defined(_DEBUG)
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
#endif

		retvalue = PARSER_NO_DATA_FOUND;
		bCommit = FALSE;
	}

	pInput->EndRead(bCommit);
	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PRepeat::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bCommit = TRUE;
	BOOL bOpen = FALSE;

	if (bStatus) switch (bOpen = (pMonitor->OpenDomain(pLog, m_pszDomain)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bStatus) switch (pMonitor->GetPrimary(pLog, m_pszDomain, &m_idCurrent))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	PObject * ptr = GetFirstChild();

	ppSecondary[nSecondary++] = &m_Secondary;
	m_Secondary = 0;

	while (bStatus && (ptr != NULL))
	{
		BOOL bInsert = FALSE;
		BOOL bInsertCommit = TRUE;
		if (bStatus) switch (pMonitor->GetSecondary(pLog, m_pszDomain, &m_idCurrent, ppSecondary, nSecondary-1, &m_Secondary))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bInsertCommit = FALSE;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bStatus) switch (bInsert = (pMonitor->AddNew(pLog, m_pszDomain, &m_idCurrent, ppSecondary, nSecondary)))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bInsertCommit = FALSE;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bStatus) switch (ptr->Insert(pMonitor, pMemory, pLog, m_pszDomain, &m_idCurrent, ppSecondary, nSecondary))
		{
		case PARSER_SUCCESS:
			ptr = ptr->GetNext();
			break;
		case PARSER_SUCCESS_WITH_INFO:
			retvalue = PARSER_SUCCESS_WITH_INFO;
			ptr = ptr->GetNext();
			break;
		case PARSER_ERROR:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bInsertCommit = FALSE;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bInsert) switch (pMonitor->Update(pLog, m_pszDomain, &m_idCurrent, ppSecondary, nSecondary, bInsertCommit))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}

	nSecondary--;

	if (bOpen) switch (pMonitor->CloseDomain(pLog, m_pszDomain))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bStatus) switch (pMonitor->SetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Primary, &m_idCurrent))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	return retvalue; 
}

RETVALUE PRepeat::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	PRIMARY idCurrent;
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bCommit = TRUE;
	BOOL bOpen = FALSE;
	BOOL bSelect = FALSE;

	Preselect(this, m_nLevel, pLog);

	if (bStatus) switch (pArchive->GetAttribute(pLog, pszDomain, m_pszAttribute, pPrimary, ppSecondary, nSecondary, TDatabase::Primary, &idCurrent, NULL, sizeof(PRIMARY)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bStatus) switch (bOpen = (pArchive->OpenDomain(pLog, m_pszDomain)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	ppSecondary[nSecondary] = &m_Secondary;
	m_Secondary = 0;

	if (bStatus) switch (bSelect = (pArchive->BeginSelect(pLog, m_pszDomain, &idCurrent, ppSecondary, nSecondary, TRUE)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	while (bStatus && bCommit) 
	{
		BOOL bFetch = FALSE;
		switch (pArchive->Fetch(pLog, m_pszDomain, &idCurrent, ppSecondary, nSecondary, TRUE))
		{
		case TRUE:
			bFetch = TRUE;
			break;
		case FALSE:
			bFetch = FALSE;
			break;
		}

		if (!bFetch) break;

		PObject * pChild = ((ALLOCFUNC)(m_pCommand[GW_ALLOC]))(pMemory);
		LPARAM lpStyle = (LPARAM)(m_pCommand[GW_STYLE]);
		pChild->Create(pMemory, lpStyle, m_pCommand, this, m_nLevel+1, m_pInstance);

		if (bStatus) switch (pChild->Select(pArchive, pMemory, pLog, m_pszDomain, &idCurrent, ppSecondary, nSecondary+1))
		{
		case PARSER_SUCCESS:

			Attach(pChild);
			m_size++;
			break;

		case PARSER_SUCCESS_WITH_INFO:

			retvalue = PARSER_SUCCESS_WITH_INFO;
			Attach(pChild);
			m_size++;
			break;

		case PARSER_NO_DATA_FOUND:

			retvalue = PARSER_NO_DATA_FOUND;
			if (lpStyle & OS_OPTIONAL)
			{
				pChild->Destroy(pMemory);
				delete pChild;
			}
			else
			{
				Attach(pChild);
			}
			bCommit = FALSE;
			break;

		case PARSER_ERROR:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
#endif
			
			retvalue = PARSER_ERROR;
			Attach(pChild);
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}

	if (bSelect) switch (pArchive->EndSelect(pLog, m_pszDomain, &idCurrent, ppSecondary, nSecondary))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_NO_DATA_FOUND;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bOpen) switch (pArchive->CloseDomain(pLog, m_pszDomain))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_NO_DATA_FOUND;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bStatus && (m_size < m_minsize))
	{

#if defined(_DEBUG)
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
#endif
		
		retvalue = PARSER_NO_DATA_FOUND;
		bCommit = FALSE;
	}
	
	if (bStatus && (m_maxsize < m_size))
	{

#if defined(_DEBUG)
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
#endif
		
		retvalue = PARSER_NO_DATA_FOUND;
		bCommit = FALSE;
	}

	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PLoop::Load(TInput *pInput, TMemory *pMemory, TLog *pLog) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bCommit = TRUE;

	Preload(this, m_nLevel, pLog);
	pInput->BeginRead();

	BOOL bEof = FALSE;

	while (bStatus && (m_size < m_maxsize) && !bEof)
	{
		PObject * pChild = ((ALLOCFUNC)(m_pCommand[GW_ALLOC]))(pMemory);
		LPARAM lpStyle = (LPARAM)(m_pCommand[GW_STYLE]);
		pChild->Create(pMemory, lpStyle, m_pCommand, this, m_nLevel+1, m_pInstance);
		
		pLog->BeginWrite(this->GetObjectName(), m_nLevel);
		RETVALUE i = pChild->Load(pInput, pMemory, pLog);
		if ( (i == PARSER_NO_DATA_FOUND) && (lpStyle & OS_OPTIONAL) )
			pLog->EndWrite(this->GetObjectName(), m_nLevel, PARSER_SUCCESS);
		else
			pLog->EndWrite(this->GetObjectName(), m_nLevel, i);


		switch (i)
		{
		case PARSER_SUCCESS_WITH_INFO:

			retvalue = PARSER_SUCCESS_WITH_INFO;

		case PARSER_SUCCESS:

			Attach(pChild);
			m_size++;
			break;

		case PARSER_NO_DATA_FOUND:

			bEof = TRUE;
			pChild->Destroy(pMemory);
			delete pChild;		
			break;

		case PARSER_ERROR:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
#endif
			
			retvalue = PARSER_ERROR;
			Attach(pChild);
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}

	if (bStatus && (m_size < m_minsize))
	{

#if defined(_DEBUG)
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
#endif
		
		retvalue = PARSER_NO_DATA_FOUND;
		bCommit = FALSE;
	}

	if (bCommit && (m_lpStyle & LS_PUSHCOUNT)) Push(m_size);
	pInput->EndRead(bCommit);
	Postload(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

RETVALUE PLoop::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bCommit = TRUE;
	BOOL bOpen = FALSE;

	if (bStatus) switch (bOpen = (pMonitor->OpenDomain(pLog, m_pszDomain)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	PObject * ptr = GetFirstChild();
	ppSecondary[nSecondary++] = &m_Secondary;
	m_Secondary = 0;

	while (bStatus && (ptr != NULL))
	{
		BOOL bInsert = FALSE;
		BOOL bInsertCommit = TRUE;

		if (bStatus) switch (pMonitor->GetSecondary(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary-1, &m_Secondary))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bInsertCommit = FALSE;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bStatus) switch (bInsert = (pMonitor->AddNew(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary)))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bInsertCommit = FALSE;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bStatus) switch (ptr->Insert(pMonitor, pMemory, pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary))
		{
		case PARSER_SUCCESS_WITH_INFO:

			retvalue = PARSER_SUCCESS_WITH_INFO;

		case PARSER_SUCCESS:

			ptr = ptr->GetNext();
			break;

		case PARSER_ERROR:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
#endif
			
			retvalue = PARSER_ERROR;
			bInsertCommit = FALSE;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

		if (bInsert) switch (pMonitor->Update(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary, bInsertCommit))
		{
		case TRUE:
			break;
		case FALSE:
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
			retvalue = PARSER_ERROR;
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}
	}

	nSecondary--;

	if (bOpen) switch (pMonitor->CloseDomain(pLog, m_pszDomain))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	return retvalue; 
}

RETVALUE PLoop::Select(TArchive *pArchive, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	BOOL bStatus = TRUE;
	RETVALUE retvalue = PARSER_SUCCESS;
	BOOL bCommit = TRUE;
	BOOL bOpen = FALSE;
	BOOL bSelect = FALSE;

	Preselect(this, m_nLevel, pLog);
	if (bStatus) switch (bOpen = (pArchive->OpenDomain(pLog, m_pszDomain)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	ppSecondary[nSecondary] = &m_Secondary;
	m_Secondary = 0;

	if (bStatus) switch (bSelect = (pArchive->BeginSelect(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary, TRUE)))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	while (bStatus && bCommit)
	{
		BOOL bFetch = FALSE;
		switch (bFetch = (pArchive->Fetch(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary, TRUE)))
		{
		case TRUE:
			break;
		case FALSE:
			break;
		}

		if (!bFetch) break;

		PObject * pChild = ((ALLOCFUNC)(m_pCommand[GW_ALLOC]))(pMemory);
		LPARAM lpStyle = (LPARAM)(m_pCommand[GW_STYLE]);
		pChild->Create(pMemory, lpStyle, m_pCommand, this, m_nLevel+1, m_pInstance);

		pLog->BeginWrite(this->GetObjectName(), m_nLevel);
		RETVALUE i = pChild->Select(pArchive, pMemory, pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary+1);

		if ( (i == PARSER_NO_DATA_FOUND) && (lpStyle & OS_OPTIONAL) )
			pLog->EndWrite(this->GetObjectName(), m_nLevel, PARSER_SUCCESS);
		else
			pLog->EndWrite(this->GetObjectName(), m_nLevel, i);

		switch (i)
		{
		case PARSER_SUCCESS:

			Attach(pChild);
			m_size++;
			break;

		case PARSER_SUCCESS_WITH_INFO:

			retvalue = PARSER_SUCCESS_WITH_INFO;
			Attach(pChild);
			m_size++;
			break;

		case PARSER_NO_DATA_FOUND:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Warning, 0, (char *)cszNoDataFound, sizeof(cszNoDataFound)-1);
#endif

			retvalue = PARSER_NO_DATA_FOUND;
			if (lpStyle & OS_OPTIONAL)
			{
				pChild->Destroy(pMemory);
				delete pChild;
			}
			else
			{
				Attach(pChild);
			}
			bCommit = FALSE;
			break;

		case PARSER_ERROR:

#if defined(_DEBUG)
			pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
#endif
			
			retvalue = PARSER_ERROR;
			Attach(pChild);
			bCommit = FALSE;
			bStatus = FALSE;
			break;
		}

	}

	if (bSelect) switch (pArchive->EndSelect(pLog, m_pszDomain, pPrimary, ppSecondary, nSecondary))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bOpen) switch (pArchive->CloseDomain(pLog, m_pszDomain))
	{
	case TRUE:
		break;
	case FALSE:
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Error, 0, (char *)cszError, sizeof(cszError)-1);
		retvalue = PARSER_ERROR;
		bCommit = FALSE;
		bStatus = FALSE;
		break;
	}

	if (bStatus && (m_size < m_minsize))
	{

#if defined(_DEBUG)
		static char szMessage[] = "A few results. Results discard";
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Information, 0, (char *)szMessage, strlen(szMessage));
#endif
		
		retvalue = PARSER_NO_DATA_FOUND;
		bCommit = FALSE;
		bStatus = FALSE;
	}

	if (bStatus && (m_maxsize < m_size))
	{

#if defined(_DEBUG)
		static char szMessage[] = "A many results. Results discard";
		pLog->Write(this->GetObjectName(), m_nLevel, TLog::Information, 0, (char *)szMessage, strlen(szMessage));
#endif
		
		retvalue = PARSER_NO_DATA_FOUND;
		bCommit = FALSE;
		bStatus = FALSE;
	}

	if (bCommit && (m_lpStyle & LS_PUSHCOUNT)) Push(m_size);
	Postselect(this, m_nLevel, pLog, retvalue);
	return retvalue; 
}

