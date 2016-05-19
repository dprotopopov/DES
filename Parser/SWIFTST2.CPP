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
#include "swiftgfd.h"
#include "swiftstd.h"
#include "swiftsrv.h"

///////////////////////////////////////////////////////////////////////////////////
// STANDARDS IMPLEMENTATION
// File swiftst2.cpp
// Copyright © 1996, Asset Information Management
// Copyright © 1997, Asset Information Management
// Programmer: Dmitry Protopopov
////////////////////////////////////////////////////////////////////////////////////

/*
RETVALUE MT574::Validate(TMemory *pMemory, TLog * pLog)
{
	RETVALUE retvalue;
	return PSequence::Validate(pMemory, pLog);
}
*/

const char C00[]   = "C00 - Internal error";
const char C03[]   = "C03 - The number of decimal digits in the amount component is checked against the maximum allowed for the corresponding currency.";
const char C04[]   = "C04 - If field 88() is used, field 87() must also be present.";
const char C08[]   = "C08 - When used, field 57() and 58() must both be present.";
const char C28[]   = "C28 - Field 20 in sequence A must be present if there no repetitive sequences.";
const char C32[]   = "C32 - An optional sequence of fields was used. However, a field which is required or a field which mantadory with this sequence is missing.";
const char C37[]   = "C37 - The second subfield of field 67A must not be present.";
const char C56v0[] = "C56 - Field 60A and field 62A must either both be present or both be absent in each occurrence of the outermost repetitive sequence.";
const char C56v1[] = "C56 - Field 60B and field 62B must either both be present or both be absent in each occurrence of the inner repetitive sequence.";
const char C63[]   = "C63 - If field 34E is present, the amount must equal the net sum of amounts of all occurrences of field 32H.";
const char C64[]   = "C64 - If field 34E is present, then currency code in all occurrences of field 32H must be the same as the currency code in field 34E.";
const char C65[]   = "C65 - Fields 60B and 62B may only be present if field 83() is also present in the same repetitive sequence of fields 83() through 62B.";
const char C67[]   = "C67 - In MT 500 and in sequence A of MT 516, either field 83() or 87(), but not both, may be present.";
const char C68[]   = "C68 - Either field 53() or fields 57() and 58(), but not both, may be present.";
const char C69[]   = "C69 - If field 23 consists of the code word 'SOLD' or contain 'SOLD/...', either field 53() or field 57() and 58(), but not both, may be present.";
const char C70[]   = "C70 - If field 23 consists of the code word 'BOUGHT' or contains 'BOUGHT/...', either field 83() or 87(), but not both, may be present.";
const char C71[]   = "C71 - If field 57() is present, field 58() must be present.";
const char C72[]   = "C72 - If field 23 consists of the code word 'DELIVERD' and field 88() is present, field 87() must be present.";
const char C73[]   = "C73 - If sequence B is present two or more times, field 83() must be present in each occurrence of the repetitive sequence.";
const char D11[]   = "D11 - Field 23 may only be present when field 12 consist of '573'.";
const char D12v0[] = "D12 - Field 83() must be present in sequence A or in each occurrence of sequence B or C.";
const char D12v1[] = "D12 - If used in any sequence B or C, field 83() must be present in every occurence of the inner repetitive sequence of every sequence B or C.";
const char D12v2[] = "D12 - Sequence B and C must not both be present in the same message.";
const char D12v3[] = "D12 - Field 83() must be present in sequence A or in each occurrence of sequence B.";
const char D12v4[] = "D12 - If used in any sequence B, field 83() must be present in every occurence of the inner repetitive sequence of every sequence B.";
const char D14[]   = "D14 - If field 23 is present within any sequence B, it must be present in every occurrence of the innermost repetitive sequence in every sequence B.";
const char D15[]   = "D15 - If field 35B is present within any sequence C, it must be present in every occurrence of the innermost repetitive sequence of every sequence C.";
const char D16[]   = "D16 - For each occurrence of sequence B, if field 32H is present, the first subfield must be present if and only if the first subfield of field of field 35H is present.";

#define RETURN_ERROR(code)									\
		{													\
			pLog->Write(GetObjectName(), 0, TLog::Error, 0, \
			(char *)code, sizeof(code)-1);					\
			return PARSER_ERROR;							\
		}													\
		// RETURN_ERROR


RETVALUE MT500::Validate(TMemory *pMemory, TLog * pLog)
{

////////////////////////////////////////
// Semantic validation rule 4

	PContainer * pField88a;
	RETVALUE retvalue88a = this->Event(EV_FIND,(LPARAM)srvrField88a_BeneficiaryOfSecurities,(LPARAM)&pField88a);
	if (retvalue88a != PARSER_NO_DATA_FOUND)
	{
		PContainer * pField87a;
		RETVALUE retvalue87a = this->Event(EV_FIND,(LPARAM)srvrField87a_ReceiverOfSecurities,(LPARAM)&pField87a);
		if (retvalue87a == PARSER_NO_DATA_FOUND) RETURN_ERROR(C04);
	}

////////////////////////////////////////
// Semantic validation rule 67

	PContainer * pField83a;
	RETVALUE retvalue83a = this->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
	PContainer * pField87a;
	RETVALUE retvalue87a = this->Event(EV_FIND,(LPARAM)srvrField87a_ReceiverOfSecurities,(LPARAM)&pField87a);
	if ((retvalue83a != PARSER_NO_DATA_FOUND) && (retvalue87a != PARSER_NO_DATA_FOUND)) RETURN_ERROR(C67);

	return PSequence::Validate(pMemory, pLog);
}

RETVALUE MT501::Validate(TMemory *pMemory, TLog * pLog)
{

////////////////////////////////////////
// Semantic validation rule 8

	PContainer * pField57a;
	RETVALUE retvalue57a = this->Event(EV_FIND,(LPARAM)srvrField57a_AccountWithInstitution,(LPARAM)&pField57a);
	BOOL bStatus = (retvalue57a != PARSER_NO_DATA_FOUND);
	PContainer * pField58a;
	RETVALUE retvalue58a = this->Event(EV_FIND,(LPARAM)srvrField58a_BeneficiaryOfMoney,(LPARAM)&pField58a);
	bStatus = (retvalue58a != PARSER_NO_DATA_FOUND)?(!bStatus):bStatus;
	if (bStatus) RETURN_ERROR(C08);

////////////////////////////////////////
// Semantic validation rule 68

	PContainer * pField53a;
	RETVALUE retvalue53a = this->Event(EV_FIND,(LPARAM)srvrField53a_AccountForPayment,(LPARAM)&pField53a);
	if ((retvalue53a != PARSER_NO_DATA_FOUND) && ((retvalue57a != PARSER_NO_DATA_FOUND) || (retvalue58a != PARSER_NO_DATA_FOUND))) RETURN_ERROR(C68);

	return PSequence::Validate(pMemory, pLog);
}

RETVALUE MT520::Validate(TMemory *pMemory, TLog * pLog)
{

////////////////////////////////////////
// Semantic validation rule 3

////////////////////////////////////////
// Semantic validation rule 73

	PLoop * pLoopOfSequenceB;
	RETVALUE retvalueB = this->Event(EV_FIND,(LPARAM)srvrMT5XXB,(LPARAM)&pLoopOfSequenceB);
	if (retvalueB == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
	if ((pLoopOfSequenceB->m_size) > 1)
	{
		PContainer * pSequenceB = (PContainer *)(pLoopOfSequenceB->GetFirstChild());
		while(pSequenceB != NULL)
		{
			PContainer * pField83a;
		    RETVALUE retvalue83a = pSequenceB->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
			if (retvalue83a == PARSER_NO_DATA_FOUND) RETURN_ERROR(C73);
			pSequenceB = (PContainer *)(pSequenceB->GetNext());
		}
	}
	return PSequence::Validate(pMemory, pLog);
}

RETVALUE MT521::Validate(TMemory *pMemory, TLog * pLog)
{

////////////////////////////////////////
// Semantic validation rule 3

////////////////////////////////////////
// Semantic validation rule 71

	PContainer * pField57a;
	RETVALUE retvalue57a = this->Event(EV_FIND,(LPARAM)srvrField57a_AccountWithInstitution,(LPARAM)&pField57a);
	if (retvalue57a != PARSER_NO_DATA_FOUND)
	{
		PContainer * pField58a;
		RETVALUE retvalue58a = this->Event(EV_FIND,(LPARAM)srvrField58a_BeneficiaryOfMoney,(LPARAM)&pField58a);
		if (retvalue58a == PARSER_NO_DATA_FOUND) RETURN_ERROR(C71);
	}

////////////////////////////////////////
// Semantic validation rule 73

	PLoop * pLoopOfSequenceB;
	RETVALUE retvalueB = this->Event(EV_FIND,(LPARAM)srvrMT5XXB,(LPARAM)&pLoopOfSequenceB);
	if (retvalueB == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
	if ((pLoopOfSequenceB->m_size) > 1)
	{
		PContainer * pSequenceB = (PContainer *)(pLoopOfSequenceB->GetFirstChild());
		while(pSequenceB != NULL)
		{
			PContainer * pField83a;
		    RETVALUE retvalue83a = pSequenceB->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
			if (retvalue83a == PARSER_NO_DATA_FOUND) RETURN_ERROR(C73);
			pSequenceB = (PContainer *)(pSequenceB->GetNext());
		}
	}
	return PSequence::Validate(pMemory, pLog);
}

RETVALUE MT523::Validate(TMemory *pMemory, TLog * pLog)
{

////////////////////////////////////////
// Semantic validation rule 8

	PContainer * pField57a;
	RETVALUE retvalue57a = this->Event(EV_FIND,(LPARAM)srvrField57a_AccountWithInstitution,(LPARAM)&pField57a);
	BOOL bStatus = (retvalue57a != PARSER_NO_DATA_FOUND);
	PContainer * pField58a;
	RETVALUE retvalue58a = this->Event(EV_FIND,(LPARAM)srvrField58a_BeneficiaryOfMoney,(LPARAM)&pField58a);
	bStatus = (retvalue58a != PARSER_NO_DATA_FOUND)?(!bStatus):bStatus;
	if (bStatus) RETURN_ERROR(C08);

////////////////////////////////////////
// Semantic validation rule 68

	PContainer * pField53a;
	RETVALUE retvalue53a = this->Event(EV_FIND,(LPARAM)srvrField53a_AccountForPayment,(LPARAM)&pField53a);
	if ((retvalue53a != PARSER_NO_DATA_FOUND) && ((retvalue57a != PARSER_NO_DATA_FOUND) || (retvalue58a != PARSER_NO_DATA_FOUND))) RETURN_ERROR(C68);

////////////////////////////////////////
// Semantic validation rule 73

	PLoop * pLoopOfSequenceB;
	RETVALUE retvalueB = this->Event(EV_FIND,(LPARAM)srvrMT5XXB,(LPARAM)&pLoopOfSequenceB);
	if (retvalueB == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
	if ((pLoopOfSequenceB->m_size) > 1)
	{
		PContainer * pSequenceB = (PContainer *)(pLoopOfSequenceB->GetFirstChild());
		while(pSequenceB != NULL)
		{
			PContainer * pField83a;
		    RETVALUE retvalue83a = pSequenceB->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
			if (retvalue83a == PARSER_NO_DATA_FOUND) RETURN_ERROR(C73);
			pSequenceB = (PContainer *)(pSequenceB->GetNext());
		}
	}
	return PSequence::Validate(pMemory, pLog);
}

RETVALUE MT530::Validate(TMemory *pMemory, TLog * pLog)
{

////////////////////////////////////////
// Semantic validation rule 3

////////////////////////////////////////
// Semantic validation rule 73

	PLoop * pLoopOfSequenceB;
	RETVALUE retvalueB = this->Event(EV_FIND,(LPARAM)srvrMT5XXB,(LPARAM)&pLoopOfSequenceB);
	if (retvalueB == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
	if ((pLoopOfSequenceB->m_size) > 1)
	{
		PContainer * pSequenceB = (PContainer *)(pLoopOfSequenceB->GetFirstChild());
		while(pSequenceB != NULL)
		{
			PContainer * pField83a;
		    RETVALUE retvalue83a = pSequenceB->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
			if (retvalue83a == PARSER_NO_DATA_FOUND) RETURN_ERROR(C73);
			pSequenceB = (PContainer *)(pSequenceB->GetNext());
		}
	}
	return PSequence::Validate(pMemory, pLog);
}

RETVALUE MT531::Validate(TMemory *pMemory, TLog * pLog)
{

////////////////////////////////////////
// Semantic validation rule 3

////////////////////////////////////////
// Semantic validation rule 71

	PContainer * pField57a;
	RETVALUE retvalue57a = this->Event(EV_FIND,(LPARAM)srvrField57a_AccountWithInstitution,(LPARAM)&pField57a);
	if (retvalue57a != PARSER_NO_DATA_FOUND)
	{
		PContainer * pField58a;
		RETVALUE retvalue58a = this->Event(EV_FIND,(LPARAM)srvrField58a_BeneficiaryOfMoney,(LPARAM)&pField58a);
		if (retvalue58a == PARSER_NO_DATA_FOUND) RETURN_ERROR(C71);
	}

////////////////////////////////////////
// Semantic validation rule 73

	PLoop * pLoopOfSequenceB;
	RETVALUE retvalueB = this->Event(EV_FIND,(LPARAM)srvrMT5XXB,(LPARAM)&pLoopOfSequenceB);
	if (retvalueB == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
	if ((pLoopOfSequenceB->m_size) > 1)
	{
		PContainer * pSequenceB = (PContainer *)(pLoopOfSequenceB->GetFirstChild());
		while(pSequenceB != NULL)
		{
			PContainer * pField83a;
		    RETVALUE retvalue83a = pSequenceB->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
			if (retvalue83a == PARSER_NO_DATA_FOUND) RETURN_ERROR(C73);
			pSequenceB = (PContainer *)(pSequenceB->GetNext());
		}
	}
	return PSequence::Validate(pMemory, pLog);
}

RETVALUE MT570::Validate(TMemory *pMemory, TLog * pLog)
{

////////////////////////////////////////
// Semantic validation rule 32
// Implemented throw mantadory fields in optional sequences

////////////////////////////////////////
// Semantic validation rule 111

	PContainer * pField23;
	RETVALUE retvalue23 = this->Event(EV_FIND,(LPARAM)srvrField23_FurtherIdentification,(LPARAM)&pField23);
	if (retvalue23 != PARSER_NO_DATA_FOUND)
	{
		FIELD12 * pField12;
		RETVALUE retvalue12 = this->Event(EV_FIND,(LPARAM)srvrField12_MessageType,(LPARAM)&pField12);
		if (retvalue12 == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
		PText * pText;
		RETVALUE retvalue = pField12->Event(EV_FIND,(LPARAM)hField12_MessageType,(LPARAM)&pText);
		if ((retvalue == PARSER_NO_DATA_FOUND) || strncmp(pText->m_strText,"573",3)) RETURN_ERROR(D11);
	}

////////////////////////////////////////
// Semantic validation rule 112
	
	PContainer * pSequenceA;
	RETVALUE retvalueA = this->Event(EV_FIND,(LPARAM)srvrSequenceA,(LPARAM)&pSequenceA);
	if (retvalueA == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
	PContainer * pField83a;
	RETVALUE retvalue83a = pSequenceA->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
    if (retvalue83a == PARSER_NO_DATA_FOUND)
	{
		retvalue83a = this->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
		if (retvalue83a == PARSER_NO_DATA_FOUND) RETURN_ERROR(D12v0);
	}
	PLoop * pLoopOfSequenceB;
	RETVALUE retvalueB = this->Event(EV_FIND,(LPARAM)srvrMT570B,(LPARAM)&pLoopOfSequenceB);
	if (retvalueB == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
	retvalue83a = pLoopOfSequenceB->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
	if (retvalue83a != PARSER_NO_DATA_FOUND)
	{
		PContainer * pSequenceB = (PContainer *)(pLoopOfSequenceB->GetFirstChild());
		while (pSequenceB != NULL)
		{
			PLoop * pLoopOfSequenceB1;
			retvalueB = pSequenceB->Event(EV_FIND,(LPARAM)srvrMT570B1,(LPARAM)&pLoopOfSequenceB1);
			if (retvalueB == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);

			PContainer * pSequenceB1 = (PContainer *)(pLoopOfSequenceB1->GetFirstChild());
			while(pSequenceB1 != NULL)
			{
				retvalue83a = pSequenceB1->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
				if (retvalue83a == PARSER_NO_DATA_FOUND) RETURN_ERROR(D12v1);
				pSequenceB1 = (PContainer *)(pSequenceB1->GetNext());
			}
			pSequenceB = (PContainer *)(pSequenceB->GetNext());
		}
	}
	PLoop * pLoopOfSequenceC;
	RETVALUE retvalueC = this->Event(EV_FIND,(LPARAM)srvrMT570C,(LPARAM)&pLoopOfSequenceC);
	if (retvalueC == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
	retvalue83a = pLoopOfSequenceB->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
	if (retvalue83a != PARSER_NO_DATA_FOUND)
	{
		PContainer * pSequenceC = (PContainer *)(pLoopOfSequenceC->GetFirstChild());
		while (pSequenceC != NULL)
		{
			PLoop * pLoopOfSequenceC1;
			retvalueC = pSequenceC->Event(EV_FIND,(LPARAM)srvrMT570C1,(LPARAM)&pLoopOfSequenceC1);
			if (retvalueC == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);

			PContainer * pSequenceC1 = (PContainer *)(pLoopOfSequenceC1->GetFirstChild());
			while(pSequenceC1 != NULL)
			{
				retvalueC = pSequenceC1->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
				if (retvalueC == PARSER_NO_DATA_FOUND) RETURN_ERROR(D12v1);
				pSequenceC1 = (PContainer *)(pSequenceC1->GetNext());
			}
			pSequenceC = (PContainer *)(pSequenceC->GetNext());
		}
	}
	if ((pLoopOfSequenceB->m_size) && (pLoopOfSequenceC->m_size)) RETURN_ERROR(D12v2);

////////////////////////////////////////
// Semantic validation rule 114

	retvalue23 = pLoopOfSequenceB->Event(EV_FIND,(LPARAM)srvrField23_FurtherIdentification,(LPARAM)&pField23);
	if (retvalue23 != PARSER_NO_DATA_FOUND)
	{
		PContainer * pSequenceB = (PContainer *)(pLoopOfSequenceB->GetFirstChild());
		while (pSequenceB != NULL)
		{
			PLoop * pLoopOfSequenceB1;
			RETVALUE retvalueB = pSequenceB->Event(EV_FIND,(LPARAM)srvrMT570B1,(LPARAM)&pLoopOfSequenceB1);
			if (retvalueB == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
			PContainer * pSequenceB1 = (PContainer *)(pLoopOfSequenceB1->GetFirstChild());
			while(pSequenceB1 != NULL)
			{
				retvalue23 = pSequenceB1->Event(EV_FIND,(LPARAM)srvrField23_FurtherIdentification,(LPARAM)&pField23);
				if (retvalue23 == PARSER_NO_DATA_FOUND) RETURN_ERROR(D14);
				pSequenceB1 = (PContainer *)(pSequenceB1->GetNext());
			}
			pSequenceB = (PContainer *)(pSequenceB->GetNext());
		}
	}

////////////////////////////////////////
// Semantic validation rule 115

	FIELD35B * pField35B;
	RETVALUE retvalue35B = pLoopOfSequenceC->Event(EV_FIND,(LPARAM)srvrField35B_IdentificationOfSecurities,(LPARAM)&pField35B);
	if (retvalue35B != PARSER_NO_DATA_FOUND)
	{
		PContainer * pSequenceC = (PContainer *)(pLoopOfSequenceC->GetFirstChild());
		while (pSequenceC != NULL)
		{
			PLoop * pLoopOfSequenceC1;
			retvalueC = pSequenceC->Event(EV_FIND,(LPARAM)srvrMT570C1,(LPARAM)&pLoopOfSequenceC1);
			if (retvalueC == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
			PContainer * pSequenceC1 = (PContainer *)(pLoopOfSequenceC1->GetFirstChild());
			while(pSequenceC1 != NULL)
			{
				retvalue35B = pSequenceC1->Event(EV_FIND,(LPARAM)srvrField35B_IdentificationOfSecurities,(LPARAM)&pField35B);
				if (retvalue35B == PARSER_NO_DATA_FOUND) RETURN_ERROR(D15);
				pSequenceC1 = (PContainer *)(pSequenceC1->GetNext());
			}
			pSequenceC = (PContainer *)(pSequenceC->GetNext());
		}
	}

	return PSequence::Validate(pMemory, pLog);
}

RETVALUE MT571::Validate(TMemory *pMemory, TLog * pLog)
{

//////////////////////////////////////////
// Semantic validation 3

//////////////////////////////////////////
// Semantic validation 32

//////////////////////////////////////////
// Semantic validation 37

	FIELD67A * pField67A;
	RETVALUE retvalue67A = this->Event(EV_FIND, (LPARAM)srvrField67A_StatementPeriod, (LPARAM)&pField67A);
	if (retvalue67A == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
	PDatetime * pDatetime;
	RETVALUE retvalueDatetime = pField67A->Event(EV_FIND, (LPARAM)hField67A_LastDateOfPeriod, (LPARAM)&pDatetime);
	if (retvalueDatetime != PARSER_NO_DATA_FOUND) RETURN_ERROR(C37);

//////////////////////////////////////////
// Semantic validation 63

//////////////////////////////////////////
// Semantic validation 64

	FIELD34E * pField34E;
	RETVALUE retvalue34E = this->Event(EV_FIND, (LPARAM)srvrField34E_FinalValue, (LPARAM)&pField34E);
	if (retvalue34E != PARSER_NO_DATA_FOUND)
	{
		PText * pText34E;
		retvalue34E = pField34E->Event(EV_FIND, (LPARAM)hField34E_CurrencyCode, (LPARAM)&pText34E);
		if (retvalue34E == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);

		PLoop * pLoopOfSequenceB;
		RETVALUE retvalueB = this->Event(EV_FIND, (LPARAM)srvrMT571B, (LPARAM)&pLoopOfSequenceB);
		if (retvalueB == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
		PContainer * pSequenceB = (PContainer *)(pLoopOfSequenceB->GetFirstChild());
		while(pSequenceB != NULL)
		{
			FIELD32H * pField32H;
			RETVALUE retvalue32H = pSequenceB->Event(EV_FIND, (LPARAM)srvrField32H_Value, (LPARAM)&pField32H);
			if (retvalue32H != PARSER_NO_DATA_FOUND)
			{
				PText * pText32H;
				retvalue32H = pField32H->Event(EV_FIND, (LPARAM)hField32H_CurrencyCode, (LPARAM)&pText32H);
				if (retvalue32H == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
				if (strncmp(pText32H->m_strText, pText34E->m_strText, 3)) RETURN_ERROR(C64);
			}
			pSequenceB = (PContainer *)(pSequenceB->GetNext());
		}
	}
	
//////////////////////////////////////////
// Semantic validation 116

	return PSequence::Validate(pMemory, pLog);
}


RETVALUE MT572::Validate(TMemory *pMemory, TLog * pLog)
{
//////////////////////////////////////////
// Semantic validation 3
//////////////////////////////////////////
// Semantic validation 32
//////////////////////////////////////////
// Semantic validation 56

	PLoop * pLoopOfSequenceB;
	RETVALUE retvalueB = this->Event(EV_FIND, (LPARAM)srvrMT572B, (LPARAM)&pLoopOfSequenceB);
	if (retvalueB == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);

	PContainer * pSequenceB = (PContainer *)(pLoopOfSequenceB->GetFirstChild());
	while (pSequenceB != NULL)
	{
		FIELD60A * pField60A;
		FIELD62A * pField62A;
		RETVALUE retvalue60A = pSequenceB->Event(EV_FIND,(LPARAM)srvrField60A_OpeningBalance,(LPARAM)&pField60A);
		RETVALUE retvalue62A = pSequenceB->Event(EV_FIND,(LPARAM)srvrField62A_ClosingBalance,(LPARAM)&pField62A);
		if (((retvalue60A != PARSER_NO_DATA_FOUND) && (retvalue62A == PARSER_NO_DATA_FOUND)) ||
			((retvalue60A == PARSER_NO_DATA_FOUND) && (retvalue62A != PARSER_NO_DATA_FOUND))) RETURN_ERROR(C56v0);

		PLoop * pLoopOfSequenceB1;
		RETVALUE retvalueB1 = pSequenceB->Event(EV_FIND,(LPARAM)srvrMT572B1,(LPARAM)&pLoopOfSequenceB1);
		if (retvalueB1 == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);

		PContainer * pSequenceB1 = (PContainer *)(pLoopOfSequenceB1->GetFirstChild());
		while(pSequenceB1 != NULL)
		{
			FIELD60B * pField60B;
			FIELD62B * pField62B;
			RETVALUE retvalue60B = pSequenceB1->Event(EV_FIND,(LPARAM)srvrField60B_OpeningBalance,(LPARAM)&pField60B);
			RETVALUE retvalue62B = pSequenceB1->Event(EV_FIND,(LPARAM)srvrField62B_ClosingBalance,(LPARAM)&pField62B);
			if (((retvalue60B != PARSER_NO_DATA_FOUND) && (retvalue62B == PARSER_NO_DATA_FOUND)) ||
				((retvalue60B == PARSER_NO_DATA_FOUND) && (retvalue62B != PARSER_NO_DATA_FOUND))) RETURN_ERROR(C56v1);
			pSequenceB1 = (PContainer *)(pSequenceB1->GetNext());
		}
		pSequenceB = (PContainer *)(pSequenceB->GetNext());
	}

//////////////////////////////////////////
// Semantic validation 65

	pSequenceB = (PContainer *)(pLoopOfSequenceB->GetFirstChild());
	while (pSequenceB != NULL)
	{
		PLoop * pLoopOfSequenceB1;
		RETVALUE retvalueB1 = pSequenceB->Event(EV_FIND,(LPARAM)srvrMT572B1,(LPARAM)&pLoopOfSequenceB1);
		if (retvalueB1 == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);

		PContainer * pSequenceB1 = (PContainer *)(pLoopOfSequenceB1->GetFirstChild());
		while(pSequenceB1 != NULL)
		{
			PContainer * pField83a;
			RETVALUE retvalue83a = pSequenceB1->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
			if (retvalue83a == PARSER_NO_DATA_FOUND) 
			{
				FIELD60B * pField60B;
				FIELD62B * pField62B;
				RETVALUE retvalue60B = pSequenceB1->Event(EV_FIND,(LPARAM)srvrField60B_OpeningBalance,(LPARAM)&pField60B);
				RETVALUE retvalue62B = pSequenceB1->Event(EV_FIND,(LPARAM)srvrField62B_ClosingBalance,(LPARAM)&pField62B);
				if ((retvalue60B != PARSER_NO_DATA_FOUND) || (retvalue62B != PARSER_NO_DATA_FOUND)) RETURN_ERROR(C65);
			}
			pSequenceB1 = (PContainer *)(pSequenceB1->GetNext());
		}
		pSequenceB = (PContainer *)(pSequenceB->GetNext());
	}

//////////////////////////////////////////
// Semantic validation 112

	
	PContainer * pSequenceA;
	RETVALUE retvalueA = this->Event(EV_FIND,(LPARAM)srvrSequenceA,(LPARAM)&pSequenceA);
	if (retvalueA == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);

	PContainer * pField83a;
	RETVALUE retvalue83a = pSequenceA->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
    if (retvalue83a == PARSER_NO_DATA_FOUND)
	{
		retvalue83a = pLoopOfSequenceB->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
		if (retvalue83a == PARSER_NO_DATA_FOUND) RETURN_ERROR(D12v3);
	}
	retvalue83a = pLoopOfSequenceB->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
	if (retvalue83a != PARSER_NO_DATA_FOUND)
	{
		pSequenceB = (PContainer *)(pLoopOfSequenceB->GetFirstChild());
		while (pSequenceB != NULL)
		{
			PLoop * pLoopOfSequenceB1;
			RETVALUE retvalueB1 = pSequenceB->Event(EV_FIND,(LPARAM)srvrMT572B1,(LPARAM)&pLoopOfSequenceB1);
			if (retvalueB1 == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);

			PContainer * pSequenceB1 = (PContainer *)(pLoopOfSequenceB1->GetFirstChild());
			while(pSequenceB1 != NULL)
			{
				retvalue83a = pSequenceB1->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
				if (retvalue83a == PARSER_NO_DATA_FOUND) RETURN_ERROR(D12v4);
				pSequenceB1 = (PContainer *)(pSequenceB1->GetNext());
			}
			pSequenceB = (PContainer *)(pSequenceB->GetNext());
		}
	}

  
	return PSequence::Validate(pMemory, pLog);
}

RETVALUE MT573::Validate(TMemory *pMemory, TLog * pLog)
{
//////////////////////////////////////////
// Semantic validation rule 3
//////////////////////////////////////////
// Semantic validation rule 28

	PContainer * pSequenceA;
	RETVALUE retvalueA = this->Event(EV_FIND,(LPARAM)srvrSequenceA,(LPARAM)&pSequenceA);
	if (retvalueA == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);

	PLoop * pLoopOfSequenceB;
	RETVALUE retvalueB = this->Event(EV_FIND, (LPARAM)srvrMT573B, (LPARAM)&pLoopOfSequenceB);
	PLoop * pLoopOfSequenceC;
	RETVALUE retvalueC = this->Event(EV_FIND, (LPARAM)srvrMT573C, (LPARAM)&pLoopOfSequenceC);

	if (((retvalueB == PARSER_NO_DATA_FOUND) || !(pLoopOfSequenceB->m_size)) &&
		((retvalueC == PARSER_NO_DATA_FOUND) || !(pLoopOfSequenceC->m_size)))
	{
		FIELD20 * pField20;
		RETVALUE retvalue20 = pSequenceA->Event(EV_FIND, (LPARAM)srvrField20_TransactionReferenceNumber, (LPARAM)&pField20);
		if (retvalue20 == PARSER_NO_DATA_FOUND) RETURN_ERROR(C28);
	}

//////////////////////////////////////////
// Semantic validation rule 32
////////////////////////////////////////
// Semantic validation rule 37

	FIELD67A * pField67A;
	RETVALUE retvalue67A = pSequenceA->Event(EV_FIND, (LPARAM)srvrField67A_StatementPeriod, (LPARAM)&pField67A);
	if (retvalue67A == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
	PDatetime * pDatetime;
	RETVALUE retvalueDatetime = pField67A->Event(EV_FIND, (LPARAM)hField67A_LastDateOfPeriod, (LPARAM)&pDatetime);
	if (retvalueDatetime != PARSER_NO_DATA_FOUND) RETURN_ERROR(C37);

//////////////////////////////////////////
// Semantic validation rule 112

	PContainer * pField83a;
	RETVALUE retvalue83a = pSequenceA->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
    if (retvalue83a == PARSER_NO_DATA_FOUND)
	{
		RETVALUE retvalueB83a;
		if (retvalueB != PARSER_NO_DATA_FOUND)
			retvalueB83a = pLoopOfSequenceB->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
		RETVALUE retvalueC83a;
		if (retvalueC != PARSER_NO_DATA_FOUND)
			retvalueC83a = pLoopOfSequenceC->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);

		if ((retvalueB != PARSER_NO_DATA_FOUND && retvalueB83a == PARSER_NO_DATA_FOUND) &&
			(retvalueC != PARSER_NO_DATA_FOUND && retvalueC83a == PARSER_NO_DATA_FOUND)) RETURN_ERROR(D12v0);
	}
	
	if (retvalueB != PARSER_NO_DATA_FOUND)
	{
		retvalue83a = pLoopOfSequenceB->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
		if (retvalue83a != PARSER_NO_DATA_FOUND)
		{
			PContainer * pSequenceB = (PContainer *)(pLoopOfSequenceB->GetFirstChild());
			while (pSequenceB != NULL)
			{
				PLoop * pLoopOfSequenceB1;
				RETVALUE retvalueB1 = pSequenceB->Event(EV_FIND,(LPARAM)srvrMT573B1,(LPARAM)&pLoopOfSequenceB1);
				if (retvalueB1 == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);

				PContainer * pSequenceB1 = (PContainer *)(pLoopOfSequenceB1->GetFirstChild());
				while(pSequenceB1 != NULL)
				{
					retvalue83a = pSequenceB1->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
					if (retvalue83a == PARSER_NO_DATA_FOUND) RETURN_ERROR(D12v1);
					pSequenceB1 = (PContainer *)(pSequenceB1->GetNext());
				}
				pSequenceB = (PContainer *)(pSequenceB->GetNext());
			}
		}
	}

	if (retvalueC != PARSER_NO_DATA_FOUND)
	{
		retvalue83a = pLoopOfSequenceC->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
		if (retvalue83a != PARSER_NO_DATA_FOUND)
		{
			PContainer * pSequenceC = (PContainer *)(pLoopOfSequenceC->GetFirstChild());
			while (pSequenceC != NULL)
			{
				PLoop * pLoopOfSequenceC1;
				RETVALUE retvalueB1 = pSequenceC->Event(EV_FIND,(LPARAM)srvrMT573C1,(LPARAM)&pLoopOfSequenceC1);
				if (retvalueB1 == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);

				PContainer * pSequenceC1 = (PContainer *)(pLoopOfSequenceC1->GetFirstChild());
				while(pSequenceC1 != NULL)
				{
					retvalue83a = pSequenceC1->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
					if (retvalue83a == PARSER_NO_DATA_FOUND) RETURN_ERROR(D12v1);
					pSequenceC1 = (PContainer *)(pSequenceC1->GetNext());
				}
				pSequenceC = (PContainer *)(pSequenceC->GetNext());
			}
		}
	}

	if ((retvalueB != PARSER_NO_DATA_FOUND && pLoopOfSequenceB->m_size) &&
		(retvalueC != PARSER_NO_DATA_FOUND && pLoopOfSequenceC->m_size)) RETURN_ERROR(D12v2);

	return PSequence::Validate(pMemory, pLog);
}

RETVALUE MT574::Validate(TMemory *pMemory, TLog * pLog)
{
	RETVALUE retvalue;

//////////////////////////////////////////
// Semantic validation

	PContainer * pSequenceA;
	retvalue = this->Event(EV_FIND,(LPARAM)srvrSequenceA,(LPARAM)&pSequenceA);
	if (retvalue == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);


////////////////////////////////////////
// Semantic validation rule 28

	PLoop * pLoopOfSequenceB;
	retvalue = this->Event(EV_FIND, (LPARAM)srvrMT574B, (LPARAM)&pLoopOfSequenceB);
	if ((retvalue == PARSER_NO_DATA_FOUND) || !(pLoopOfSequenceB->m_size))
	{
		FIELD20 * pField20;
		retvalue = pSequenceA->Event(EV_FIND, (LPARAM)srvrField20_TransactionReferenceNumber, (LPARAM)&pField20);
		if (retvalue == PARSER_NO_DATA_FOUND) RETURN_ERROR(C28);
	}

////////////////////////////////////////
// Semantic validation rule 37

	FIELD67A * pField67A;
	retvalue = pSequenceA->Event(EV_FIND, (LPARAM)srvrField67A_StatementPeriod, (LPARAM)&pField67A);
	if (retvalue == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);
	PDatetime * pDatetime;
	retvalue = pField67A->Event(EV_FIND, (LPARAM)hField67A_LastDateOfPeriod, (LPARAM)&pDatetime);
	if (retvalue != PARSER_NO_DATA_FOUND) RETURN_ERROR(C37);

////////////////////////////////////////
// Semantic validation rule 112
	
	PContainer * pField83a;
	retvalue = pSequenceA->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
    if (retvalue == PARSER_NO_DATA_FOUND)
	{
		retvalue = pLoopOfSequenceB->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
		if (retvalue == PARSER_NO_DATA_FOUND) RETURN_ERROR(D12v3);
	}
	retvalue = pLoopOfSequenceB->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
	if (retvalue != PARSER_NO_DATA_FOUND)
	{
		PContainer * pSequenceB = (PContainer *)(pLoopOfSequenceB->GetFirstChild());
		while (pSequenceB != NULL)
		{
			PLoop * pLoopOfSequenceB1;
			retvalue = pSequenceB->Event(EV_FIND,(LPARAM)srvrMT574B1,(LPARAM)&pLoopOfSequenceB1);
			if (retvalue == PARSER_NO_DATA_FOUND) RETURN_ERROR(C00);

			PContainer * pSequenceB1 = (PContainer *)(pLoopOfSequenceB1->GetFirstChild());
			while(pSequenceB1 != NULL)
			{
				retvalue = pSequenceB1->Event(EV_FIND,(LPARAM)srvrField83a_SafekeepingAccount,(LPARAM)&pField83a);
				if (retvalue == PARSER_NO_DATA_FOUND) RETURN_ERROR(D12v4);
				pSequenceB1 = (PContainer *)(pSequenceB1->GetNext());
			}
			pSequenceB = (PContainer *)(pSequenceB->GetNext());
		}
	}

	return PSequence::Validate(pMemory, pLog);
}
