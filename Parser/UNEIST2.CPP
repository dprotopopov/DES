//////////////////////////////////
// System level dependencies

#include <windows.h>

//////////////////////////////////
// ANSI level dependencies

//////////////////////////////////
// Application level dependencies

#include "prc.h"
#include "srv.h"
#include "swiftext.h"
#include "swiftstd.h"
#include "swiftgfd.h"
#include "swiftsrv.h"
#include "uneiext.h"
#include "uneigfd.h"
#include "uneistd.h"
#include "uneisrv.h"

////////////////////////////////////////////////////////////
// UNEXIM STANDARDS IMPLEMENTATION
// File uneist2.cpp
// Copyright © 1996, Asset Information Management
// Copyright © 1997, Asset Information Management
// Programmer: Dmitry Protopopov
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
//

BEGIN_IMPLEMENT_DERIVATE(UMT570, MT570, "UNEXIM MT570")

RETVALUE UMT570::Validate(TMemory *pMemory, TLog * pLog)
{
	return MT570::Validate(pMemory, pLog);
}

END_IMPLEMENT_DERIVATE(UMT570, MT570)

/////////////////////////////////////////////////////////////////////
//

BEGIN_IMPLEMENT_DERIVATE(UMT572, MT572, "UNEXIM MT574")

RETVALUE UMT572::Validate(TMemory *pMemory, TLog * pLog)
{
	return MT572::Validate(pMemory, pLog);
}

END_IMPLEMENT_DERIVATE(UMT572, MT572)

////////////////////////////////////////////////////////////////
//

RETVALUE UMT574::Validate(TMemory *pMemory, TLog * pLog)
{
	return MT574::Validate(pMemory, pLog);
}

////////////////////////////////////////////////////////////////////
// UMT592

BEGIN_IMPLEMENT_DERIVATE(UMT592, MTn92, "UNEXIM MT592")

RETVALUE UMT592::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	pInplaceMessage = new UMT592UM();
	pInplaceMessage->Create(pMemory);
	return MTn92::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE UMT592::Load(TInput *pInput, TMemory *pMemory, TLog *pLog)
{
	RETVALUE retvalue = MTn92::Load(pInput, pMemory, pLog);

/////////////////////////////////////////////////////////////////
//After load standart implementation we are store field 79 and
//copy of original message into pipeline stream and reload MICEX
//specific message from it.

	char buffer[1024];
	TMemPipeline * pMemPipeline = new TMemPipeline(buffer, sizeof(buffer));
	//pMemPipeline->Create();

	FIELD79 * pField79;
	RETVALUE retvalue79 = this->Event(EV_FIND,(LPARAM)srvrField79_NarrativeDescriptionOfTheOriginalMessage,(LPARAM)&pField79);
	if (retvalue79 != PARSER_NO_DATA_FOUND)
	{
		pField79->Store(pMemPipeline,pMemory,pLog);	

	}

	PMultitext * pCopyOfTheOriginalMessage;
	RETVALUE retvalueCopyOfTheOriginalMessage = this->Event(EV_FIND,(LPARAM)hCopyOfTheOriginalMessage,(LPARAM)&pCopyOfTheOriginalMessage);
	if (retvalueCopyOfTheOriginalMessage != PARSER_NO_DATA_FOUND)
	{
		pCopyOfTheOriginalMessage->Store(pMemPipeline,pMemory,pLog);
		pMemPipeline->Write("\r\n",2);
	}

	pInplaceMessage->Load(pMemPipeline, pMemory, pLog);

	//pMemPipeline->Destroy();
	delete pMemPipeline;

/*
#ifdef _DEBUG
	fprintf(stdout, "Debug: Additional Information of MT 592\n");

	PRIMARY Primary;
	SECONDARY *Secondary[10];

	TFileReport * pDebugReport = new TFileReport(stdout);
	pDebugReport->BeginImport(pLog, &Primary);
	pInplaceMessage->Insert(pDebugReport, pMemory, pLog, NULL, &Primary, Secondary, 0);
	pDebugReport->EndImport(pLog, &Primary, TRUE);
	fflush(stdout);
	delete pDebugReport;
#endif
*/

	return retvalue;
}

RETVALUE UMT592::Validate(TMemory *pMemory, TLog * pLog)
{
	const char ERROR79[] = "Field 79 must be present and contain message type and trade date of MT 570.";
	const char ERRORCOPY[] = "Copy of original message must be present and contain fields 20 and 67A of MT 572.";

	FIELD79 * pField79;
	RETVALUE retvalue79 = this->Event(EV_FIND,(LPARAM)srvrField79_NarrativeDescriptionOfTheOriginalMessage,(LPARAM)&pField79);
	if (retvalue79 == PARSER_NO_DATA_FOUND) 
	{
		pLog->Write(GetObjectName(), 0, TLog::Warning, 0, (char *)ERROR79, sizeof(ERROR79)-1);
	}
	else
	{
		PMultitext * pNarrative;
		RETVALUE retvalueNarrative = pField79->Event(EV_FIND,(LPARAM)hField79_Narrative,(LPARAM)&pNarrative);
		if (retvalueNarrative == PARSER_NO_DATA_FOUND) 
		{
			pLog->Write(GetObjectName(), 0, TLog::Warning, 0, (char *)ERROR79, sizeof(ERROR79)-1);
		}
	}

	PMultitext * pCopyOfTheOriginalMessage;
	RETVALUE retvalueCopyOfTheOriginalMessage = this->Event(EV_FIND,(LPARAM)hCopyOfTheOriginalMessage,(LPARAM)&pCopyOfTheOriginalMessage);
	if (retvalueCopyOfTheOriginalMessage == PARSER_NO_DATA_FOUND) 
	{
		pLog->Write(GetObjectName(), 0, TLog::Warning, 0, (char *)ERRORCOPY, sizeof(ERRORCOPY)-1);
	}

	return MTn92::Validate(pMemory, pLog);
}

RETVALUE UMT592::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	pInplaceMessage->Insert(pMonitor, pMemory, pLog, pszDomain, pPrimary, ppSecondary, nSecondary);
	return MTn92::Insert(pMonitor, pMemory, pLog, pszDomain, pPrimary, ppSecondary, nSecondary);
}

void UMT592::Destroy(TMemory * pMemory)
{
	MTn92::Destroy(pMemory);
	pInplaceMessage->Destroy(pMemory);
	delete pInplaceMessage;
}

END_IMPLEMENT_DERIVATE(UMT592, MTn92)

//////////////////////////////////////////////////////////////////
// UMT598

BEGIN_IMPLEMENT_DERIVATE(UMT598, MTn98, "UNEXIM MT598")

RETVALUE UMT598::Create(TMemory *pMemory, LPARAM lpStyle, LPARAM *plParam, PObject *pParent, UINT nLevel, PObject * pInstance)
{
	pInplaceMessage = new UMT598UM();
	pInplaceMessage->Create(pMemory);
	return MTn98::Create(pMemory, lpStyle, plParam, pParent, nLevel, pInstance);
}

RETVALUE UMT598::Load(TInput *pInput, TMemory *pMemory, TLog *pLog)
{
	RETVALUE retvalue = MTn98::Load(pInput, pMemory, pLog);

////////////////////////////////////////////////////////////////
//After load standart implementation we are store field 77E into 
//pipeline stream and reload MICEX specific message from it.

	char buffer[1024];
	TMemPipeline * pMemPipeline = new TMemPipeline(buffer, sizeof(buffer));
	//pMemPipeline->Create();

	FIELD77E * pField77E;
	RETVALUE retvalue77E = this->Event(EV_FIND,(LPARAM)srvrField77E_ProprietaryMessage,(LPARAM)&pField77E);
	if (retvalue77E != PARSER_NO_DATA_FOUND)
	{
		pField77E->Store(pMemPipeline, pMemory, pLog);
	}

	pInplaceMessage->Load(pMemPipeline, pMemory, pLog);

	//pMemPipeline->Destroy();
	delete pMemPipeline;

/*
#ifdef _DEBUG
	fprintf(stdout, "Debug: Additional Information of MT 598\n");

	PRIMARY Primary;
	SECONDARY *Secondary[10];

	TFileReport * pDebugReport = new TFileReport(stdout);
	pDebugReport->BeginImport(pLog, &Primary);
	pInplaceMessage->Insert(pDebugReport, pMemory, pLog, NULL, &Primary, Secondary, 0);
	pDebugReport->EndImport(pLog, &Primary, TRUE);
	fflush(stdout);
	delete pDebugReport;
#endif
*/

	return retvalue;
}

RETVALUE UMT598::Validate(TMemory *pMemory, TLog * pLog)
{
	const char ERROR77E[] = "Field 77E must be present and contain trade date and transaction reference numbers from MT 570, 574 and optionaly from 572.";

	FIELD77E * pField77E;
	RETVALUE retvalue77E = this->Event(EV_FIND,(LPARAM)srvrField77E_ProprietaryMessage,(LPARAM)&pField77E);
	if (retvalue77E == PARSER_NO_DATA_FOUND)
	{
		pLog->Write(GetObjectName(), 0, TLog::Warning, 0, (char *)ERROR77E, sizeof(ERROR77E)-1);
	}

	return MTn98::Validate(pMemory, pLog);
}

RETVALUE UMT598::Insert(TMonitor *pMonitor, TMemory *pMemory, TLog *pLog, char *pszDomain, PRIMARY *pPrimary, SECONDARY **ppSecondary, UINT nSecondary) 
{
	pInplaceMessage->Insert(pMonitor, pMemory, pLog, pszDomain, pPrimary, ppSecondary, nSecondary);
	return MTn98::Insert(pMonitor, pMemory, pLog, pszDomain, pPrimary, ppSecondary, nSecondary);
}

void UMT598::Destroy(TMemory * pMemory)
{
	MTn98::Destroy(pMemory);
	pInplaceMessage->Destroy(pMemory);
	delete pInplaceMessage;
}

END_IMPLEMENT_DERIVATE(UMT598, MTn98)
