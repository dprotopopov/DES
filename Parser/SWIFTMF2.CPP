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
#include "swiftmf.h"
#include "swiftsrv.h"

/////////////////////////////////////////////////////////////////
// SWIFT II MESSAGE FORMAT IMPLEMENTATION
// File swiftmf2.cpp
// Copyright © 1996 Asset Information Management
// Programmer: Dmitry Protopopov
/////////////////////////////////////////////////////////////////

typedef struct tagMESSAGELENGTH
{
	char * pszType;
	UINT nMaxInputLength;
	UINT nMaxOutputLength;
} MESSAGELENGTH;

const UINT nDefaultMaxInputLength = 2000;
const UINT nDefaultMaxOutputLength = 2600;
const MESSAGELENGTH MessageLength[] =
{
	{ "102", 10000, 10600 },
	{ "106", 10000, 10600 },

	{ "360", 10000, 10600 },
	{ "361", 10000, 10600 },

	{ "514", 10000, 10600 },
	{ "570", 10000, 10600 },
	{ "571", 10000, 10600 },
	{ "572", 10000, 10600 },
	{ "573", 10000, 10600 },
	{ "574", 10000, 10600 },
	{ "576", 10000, 10600 },
	{ "577", 10000, 10600 },

	{ "700", 10000, 10600 },
	{ "701", 10000, 10600 },
	{ "710", 10000, 10600 },
	{ "711", 10000, 10600 },
	{ "720", 10000, 10600 },
	{ "721", 10000, 10600 },
	{ "760", 10000, 10600 },
	{ "767", 10000, 10600 },

	{ "198", 10000, 10600 },
	{ "298", 10000, 10600 },
	{ "398", 10000, 10600 },
	{ "498", 10000, 10600 },
	{ "598", 10000, 10600 },
	{ "698", 10000, 10600 },
	{ "798", 10000, 10600 },
	{ "898", 10000, 10600 },
	{ "998", 10000, 10600 }
};

const int Count = sizeof(MessageLength)/sizeof(MESSAGELENGTH);

RETVALUE ISWIFTMESSAGE::Validate(TMemory *pMemory, TLog * pLog)
{

	PText * pType;
	RETVALUE retvalue = Event(EV_FIND, (LPARAM)hHeader_MessageType, (LPARAM)&pType);
	int i = Count;
	UINT maxlen = nDefaultMaxInputLength;
	UINT len;
	char * ptr;
	char buffer[256];


	switch (retvalue)
	{
	case PARSER_SUCCESS:
	case PARSER_SUCCESS_WITH_INFO:

		if (pType->m_nLength != 3)
		{
			return PARSER_ERROR;
		}

		ptr = pType->m_strText;

		while (i-- && (strncmp(ptr, MessageLength[i].pszType, 3)));
		if (i != -1) maxlen = MessageLength[i].nMaxInputLength;

		if ((len = GetLength()) <= maxlen) break;

		sprintf(buffer, "The number of characters (%u) greate then maximal number (%u) specified for this message type", len, maxlen);
		pLog->Write(GetObjectName(), 0, TLog::Error, 0, buffer, strlen(buffer));
		return PARSER_ERROR;

	case PARSER_NO_DATA_FOUND:

		break;

	case PARSER_ERROR:

		return PARSER_ERROR;
	}

	return PSequence::Validate(pMemory, pLog);
}
