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
#include "swiftsrv.h"

//////////////////////////////////////////////////////////////////
// GENERAL FIELD DEFINITION IMPLEMENTATION
// File swiftgfd.cpp
// Copyright © 1996 Asset Information Management
// Copyright © 1997 Asset Information Management
// Programmer: Dmitry Protopopov
//////////////////////////////////////////////////////////////////
// FIELD11R - MT and Date of Original Message
// 534
// 573
// 574

BEGIN_IMPLEMENT_SEQUENCE(FIELD11R, "SWIFT FIELD 11R")
  STATIC(OS_MANTADORY,":11R:")
  TEXT(OS_MANTADORY, hField11a_MessageType, MESSAGE_TYPE)
  STATIC(OS_MANTADORY,EOL)
  DATETIME(OS_MANTADORY, hField11a_Date, YYMMDD)
  STATIC(OS_MANTADORY,EOL)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    INTEGER(OS_MANTADORY, hField11a_SessionNumber, SESSION_NUMBER, "%04lu")
    INTEGER(OS_MANTADORY, hField11a_SequenceNumber, SEQUENCE_NUMBER, "%06lu")
    STATIC(OS_MANTADORY,EOL)
  END_SEQUENCE
END_IMPLEMENT_SEQUENCE(FIELD11R)

//////////////////////////////////////////////////////////////////
// FIELD11S - MT and Date of Original Message
// n92

BEGIN_IMPLEMENT_SEQUENCE(FIELD11S, "SWIFT FIELD 11S")
  STATIC(OS_MANTADORY,":11S:") 
  TEXT(OS_MANTADORY, hField11a_MessageType,  DIGIT3)
  STATIC(OS_MANTADORY,EOL)
  DATETIME(OS_MANTADORY, hField11a_Date, YYMMDD)
  STATIC(OS_MANTADORY,EOL)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    INTEGER(OS_MANTADORY, hField11a_SessionNumber, DIGIT4, "%04lu")
    INTEGER(OS_MANTADORY, hField11a_SequenceNumber, DIGIT6, "%06lu")
    STATIC(OS_MANTADORY,EOL)
  END_SEQUENCE
END_IMPLEMENT_SEQUENCE(FIELD11S)

//////////////////////////////////////////////////////////////////
// FIELD12 - Message Type
/*
Definition:

The identification of a message type.

Message Types:

570
n98
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD12, "SWIFT FIELD 12")
  STATIC(OS_MANTADORY,":12:")
  TEXT(OS_MANTADORY,hField12_MessageType, DIGIT3)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD12)

//////////////////////////////////////////////////////////////////
// FIELD18A
// Reference:
// 560
// 561
// 571
// 572
// 573
// 574
// 576
//////////////////////////////////////////////////////////////////
// FIELD14S - Business Day Convention/Time Stamp/Miscellaneous
/*
Message Types:

502, 513, 514, 515, 517, 518, 576
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD14S, "SWIFT FIELD 14S")
  STATIC(OS_MANTADORY,":14S:") 
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    DATETIME(OS_MANTADORY, hField14S_Time, HHMMSS)
    DATETIME(OS_MANTADORY, hField14S_Time, HHMM)
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD14S)

//////////////////////////////////////////////////////////////////
// FIELD19 - Sum of Amounts
/*
Definition:

The sum of all amounts appearing in destignated fields within the message.

Message Types:

102
554, 559
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD19, "SWIFT FIELD 19")
  STATIC(OS_MANTADORY,":19:")
  NUMBER(OS_MANTADORY, hField19_SumOfAmount, NUMBER17)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD19)

//////////////////////////////////////////////////////////////////
// FIELD20 - Transaction Reference Number
/*
Definition:

The Sender's unambiguous identification of the transaction. Its detaled form and content are at the discretion of the Sender.
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD20, "SWIFT FIELD 20")
  STATIC(OS_MANTADORY,":20:")
  TEXT(OS_MANTADORY,hField20_TransactionReferenceNumber,  REFERENCE)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD20)

//////////////////////////////////////////////////////////////////
// FIELD20B - Sender's Transaction Reference Number
/*
Definition:

Identifies the Instructing Party's transaction reference number.

Message Types:

514
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD20B, "SWIFT FIELD 20F")
  STATIC(OS_MANTADORY,":20B:")
  TEXT(OS_MANTADORY, hField20B_TransactionReferenceNumber,  REFERENCE)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD20B)

//////////////////////////////////////////////////////////////////
// FIELD20F - Sender's Transaction Reference Number
/*
Definition:

A code identifying the message function.
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD20F, "SWIFT FIELD 20F")
  STATIC(OS_MANTADORY,":20F:")
  TEXT(OS_MANTADORY,hField20F_Code,  LETTER3)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD20F)

//////////////////////////////////////////////////////////////////
// FIELD20S - Sender's Transaction Reference Number
/*
Definition:

A code indicating if standing instructions are to be or not to be overridden.
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD20S, "SWIFT FIELD 20S")
  STATIC(OS_MANTADORY,":20S:")
  TEXT(OS_MANTADORY,hField20S_Code,  LETTER1)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD20S)

//////////////////////////////////////////////////////////////////
// FIELD21 - Related Reference

BEGIN_IMPLEMENT_SEQUENCE(FIELD21, "SWIFT FIELD 21")
  STATIC(OS_MANTADORY,":21:")
  TEXT(OS_MANTADORY,hField21_RelatedReference, REFERENCE)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD21)

//////////////////////////////////////////////////////////////////
// FIELD21B - Allocation Reference Number

BEGIN_IMPLEMENT_SEQUENCE(FIELD21B, "SWIFT FIELD 21B")
  STATIC(OS_MANTADORY,":21B:")
  TEXT(OS_MANTADORY,hField21a_AllocationReferenceNumber, REFERENCE)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD21B)

//////////////////////////////////////////////////////////////////
// FIELD21N - Allocation Reference Number

BEGIN_IMPLEMENT_SEQUENCE(FIELD21N, "SWIFT FIELD 21N")
  STATIC(OS_MANTADORY,":21N:")
  TEXT(OS_MANTADORY,hField21a_AllocationReferenceNumber, REFERENCE)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD21N)

//////////////////////////////////////////////////////////////////
// FIELD21R - Allocation Reference Number

BEGIN_IMPLEMENT_SEQUENCE(FIELD21R, "SWIFT FIELD 21R")
  STATIC(OS_MANTADORY,":21R:")
  TEXT(OS_MANTADORY,hField21a_AllocationReferenceNumber, REFERENCE)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD21R)

//////////////////////////////////////////////////////////////////
// FIELD23 - Further Identification
/*
Definition:

The specification of additional information about transaction.
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD23, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  TEXT(OS_MANTADORY, hField23_FurtherIdentification, VARTEXT16) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23)

BEGIN_IMPLEMENT_SEQUENCE(FIELD23_526, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  TEXT(OS_MANTADORY, hField23_FurtherIdentification, VARLETTER16) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23_526)

BEGIN_IMPLEMENT_SEQUENCE(FIELD23_534, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  TEXT(OS_MANTADORY, hField23_Subfield1, LETTER3) 
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    TEXT(OS_MANTADORY, hField23_Subfield2, VARLETTER8)
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23_534)

BEGIN_IMPLEMENT_SEQUENCE(FIELD23_552, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  TEXT(OS_MANTADORY, hField23_FurtherIdentification, VARLETTER16) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23_552)

BEGIN_IMPLEMENT_SEQUENCE(FIELD23_553, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  TEXT(OS_MANTADORY, hField23_FurtherIdentification, VARLETTER16) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23_553)

BEGIN_IMPLEMENT_SEQUENCE(FIELD23_554, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  RULE(OS_MANTADORY, hField23_FurtherIdentification, "CREDIT\0DEBIT\0", "C\0D\0")
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23_554)

BEGIN_IMPLEMENT_SEQUENCE(FIELD23_555, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  RULE(OS_MANTADORY, hField23_Subfield1, "CREDIT\0DEBIT\0", "C\0D\0")
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    RULE(OS_MANTADORY, hField23_Subfield2, "BONUSIS\0DIVREIN\0", "B\0D\0")
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23_555)

BEGIN_IMPLEMENT_SEQUENCE(FIELD23_556, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  TEXT(OS_MANTADORY, hField23_FurtherIdentification, "ADVICE%n\0NOTICE%n\0") 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23_556)

BEGIN_IMPLEMENT_SEQUENCE(FIELD23_557, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  TEXT(OS_MANTADORY, hField23_FurtherIdentification, "INCOME%n\0" "INCPRINC%n\0" "PRINCIPL%n\0") 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23_557)

BEGIN_IMPLEMENT_SEQUENCE(FIELD23_559, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  TEXT(OS_MANTADORY, hField23_FurtherIdentification, "INCOME%n\0" "INCPRINC%n\0" "PRINCIPL%n\0") 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23_559)

BEGIN_IMPLEMENT_SEQUENCE(FIELD23_562, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  TEXT(OS_MANTADORY, hField23_Subfield1, VARLETTER8) 
  STATIC(OS_MANTADORY,"/")
  TEXT(OS_MANTADORY, hField23_Subfield2, LETTERDIGIT5)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23_562)

BEGIN_IMPLEMENT_SEQUENCE(FIELD23_563, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  TEXT(OS_MANTADORY, hField23_FurtherIdentification, VARLETTER16) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23_563)

BEGIN_IMPLEMENT_SEQUENCE(FIELD23_571, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  TEXT(OS_MANTADORY, hField23_Subfield1, VARLETTER2) 
  STATIC(OS_MANTADORY,"/")
  TEXT(OS_MANTADORY, hField23_Subfield2, VARLETTER5)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23_571)

BEGIN_IMPLEMENT_SEQUENCE(FIELD23_573, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  TEXT(OS_MANTADORY, hField23_FurtherIdentification, VARLETTER16) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23_573)

BEGIN_IMPLEMENT_SEQUENCE(FIELD23_574, "SWIFT FIELD 23")
  STATIC(OS_MANTADORY,":23:")
  TEXT(OS_MANTADORY, hField23_FurtherIdentification, VARLETTER16) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23_574)

//////////////////////////////////////////////////////////////////
// FIELD23D - Identification of the Swap
/*
Definition:

The specification of the type of transaction being confirmed, as well as method used.
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD23D, "SWIFT FIELD 23D")
  STATIC(OS_MANTADORY,":23D:")
  TEXT(OS_MANTADORY, hField23D_TypeOfChargeOrTax, LETTER3)
  RULE(OS_OPTIONAL,hField23D_NetIndicator, "/N\0","N\0")
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"//")
    TEXT(OS_MANTADORY,hField23D_OtherInformation,VARTEXT30)
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23D)

///////////////////////////////////////////////////////////////////////////////////////
// FIELD23I - Identification of the Swap
/*
Definition:

The specification of the type of transaction being confirmed, as well as method used.
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD23I, "SWIFT FIELD 23I")
  STATIC(OS_MANTADORY,":23I:")
  TEXT(OS_MANTADORY, hField23I_Code, LETTER3)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    TEXT(OS_MANTADORY,hField23I_ShortDescription,VARTEXT12)
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23I)
///////////////////////////////////////////////////////////////////////////////////////
// FIELD23O - Identification of the Swap
/*
Definition:

The specification of the type of transaction being confirmed, as well as method used.

Message Types:

502, 513, 514, 515, 518, 576
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD23O, "SWIFT FIELD 23O")
  STATIC(OS_MANTADORY,":23O:")
  TEXT(OS_MANTADORY, hField23O_BuyOrSellIndicator, LETTER1) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23O)

///////////////////////////////////////////////////////////////////////////////////////
// FIELD23R - Identification of the Swap
/*
Definition:

The specification of the type of transaction being confirmed, as well as method used.

Message Types:

502
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD23R, "SWIFT FIELD 23R")
  STATIC(OS_MANTADORY,":23R:")
  TEXT(OS_MANTADORY, hField23R_AutomaticOrderRoutingIndicator, LETTER3) 
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    TEXT(OS_MANTADORY,hField23R_AttentionPartyIdentification, VARTEXT12)
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23R)

///////////////////////////////////////////////////////////////////////////////////////
// FIELD23T - Identification of the Swap
/*
Definition:

The specification of the type of transaction being confirmed, as well as method used.

Message Types:

502, 514, 515, 518, 576
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD23T, "SWIFT FIELD 23T")
  STATIC(OS_MANTADORY,":23T:")
  TEXT(OS_MANTADORY, hField23T_TypeOfSafekeeping, LETTER3) 
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    TEXT(OS_MANTADORY,hField23T_ShortDescription, VARTEXT30)
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD23T)

///////////////////////////////////////////////////////////////////////////////////////
// FIELD24A - Transaction Version Number
/*
Definition:

Identifies the version number of the trade being confirmed.

Message Types:

*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD24A, "SWIFT FIELD 24A")
  STATIC(OS_MANTADORY,":24A:")
  TEXT(OS_MANTADORY, hField24A_VersionNumber, VARTEXT16) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD24A)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FIELD24C - Transaction Version Number
/*
Definition:

Identifies the version number of the trade being confirmed.

Message Types:

*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD24C, "SWIFT FIELD 24C")
  STATIC(OS_MANTADORY,":24C:")
  TEXT(OS_MANTADORY, hField24C_ReasonOrStatus, VARTEXT16) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD24C)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FIELD24I - Transaction Version Number
/*
Definition:

Identifies the version number of the trade being confirmed.

Message Types:

*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD24I, "SWIFT FIELD 24I")
  STATIC(OS_MANTADORY,":24I:")
  TEXT(OS_MANTADORY, hField24I_TypeOfInterestedParty, LETTER3) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD24I)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FIELD24T - Transaction Version Number
/*
Definition:

Identifies the version number of the trade being confirmed.

Message Types:

*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD24T, "SWIFT FIELD 24T")
  STATIC(OS_MANTADORY,":24T:")
  TEXT(OS_MANTADORY, hField24T_TypeOfAffirmingParty, LETTER3) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD24T)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FIELD25 - Account Identification
/*
Definition:

The identification assigned by the Account Servicing Institution to identify the account of the Account Owner.

Message Types:

n90
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD25, "SWIFT FIELD 25")
  STATIC(OS_MANTADORY,":25:")
  TEXT(OS_MANTADORY, hField25_AccountIdentification, NARRATIVE_LINE35)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD25)

//////////////////////////////////////////////////////////////////
// FIELD25B - Interested Party Internal Account Number
/*
Definition:

Code specifiying the basis for the commission.

Message Types:

502
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD25B, "SWIFT FIELD 25B")
  STATIC(OS_MANTADORY,":25B:")
  TEXT(OS_MANTADORY, hField25B_BasisForTheCommission, LETTER1)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD25B)

//////////////////////////////////////////////////////////////////
// FIELD25C - Interested Party Internal Account Number
/*
Definition:

Specifies an additional transaction or trade condition.

Message Types:

502, 513, 514, 515, 518, 576
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD25C, "SWIFT FIELD 25C")
  STATIC(OS_MANTADORY,":25C:")
  TEXT(OS_MANTADORY, hField25C_ConditionCode, LETTER3)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    TEXT(OS_MANTADORY,hField25C_ShortDescription,VARTEXT30)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD25C)

//////////////////////////////////////////////////////////////////
// FIELD25I - Interested Party Internal Account Number
/*
Definition:

Identifies the Financial Instrument Attribute.

Message Types:

502, 513, 514, 515, 518, 576
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD25I, "SWIFT FIELD 25I")
  STATIC(OS_MANTADORY,":25I:")
  TEXT(OS_MANTADORY, hField25I_AttributeCode, LETTER3)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    TEXT(OS_MANTADORY,hField25I_ShortDescription,VARTEXT30)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD25I)

//////////////////////////////////////////////////////////////////
// FIELD26F - Item Identification
/*
Definition:

Unambiguous identification of a single item or sequence of items.

Message Types:

571
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD26F, "SWIFT FIELD 26F")
  STATIC(OS_MANTADORY,":26F:")
  TEXT(OS_MANTADORY, hField26F_ItemIdentification, VARLETTER9)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD26F)

//////////////////////////////////////////////////////////////////
// FIELD26G - Item Identification
/*
Definition:

Unambiguous identification of a single item or sequence of items.

Message Types:

550
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD26G, "SWIFT FIELD 26G")
  STATIC(OS_MANTADORY,":26G:")
  TEXT(OS_MANTADORY, hField26G_ItemIdentification, LETTER7)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD26G)

//////////////////////////////////////////////////////////////////
// FIELD26H - Item Identification
/*
Definition:

Unambiguous identification of a single item or sequence of items.

Message Types:

550, 552
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD26H, "SWIFT FIELD 26H")
  STATIC(OS_MANTADORY,":26H:")
  TEXT(OS_MANTADORY, hField26H_ItemIdentification, VARTEXT16)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD26H)

//////////////////////////////////////////////////////////////////
// FIELD26J - Item Identification
/*
Definition:

Unambiguous identification of a single item or sequence of items.

Message Types:

580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD26J, "SWIFT FIELD 26J")
  STATIC(OS_MANTADORY,":26J:")
  INTEGER(OS_MANTADORY, hField26J_ItemIdentification, DIGIT1,"%lu")
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD26J)

//////////////////////////////////////////////////////////////////
// FIELD26K - Item Identification
/*
Definition:

Unambiguous identification of a single item or sequence of items.

Message Types:

580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD26K, "SWIFT FIELD 26K")
  STATIC(OS_MANTADORY,":26K:")
  MULTITEXT(OS_MANTADORY, hField26K_ItemIdentification,1,6, NARRATIVE_TEXT35,EOL,SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD26K)

//////////////////////////////////////////////////////////////////
// FIELD26L - Item Identification
/*
Definition:

Unambiguous identification of a single item or sequence of items.

Message Types:

580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD26L, "SWIFT FIELD 26L")
  STATIC(OS_MANTADORY,":26L:")
  TEXT(OS_MANTADORY, hField26L_ItemIdentification, DIGIT1)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD26L)

//////////////////////////////////////////////////////////////////
// FIELD26T - Item Identification
/*
Definition:

Unambiguous identification of a single item or sequence of items.

Message Types:

102
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD26T, "SWIFT FIELD 26T")
  STATIC(OS_MANTADORY,":26T:")
  TEXT(OS_MANTADORY, hField26T_ItemIdentification, LETTER3)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD26T)

//////////////////////////////////////////////////////////////////
// FIELD26U - Item Identification
/*
Definition:

Unambiguous identification of a single item or sequence of items.

Message Types:

513, 514, 515, 518
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD26U, "SWIFT FIELD 26U")
  STATIC(OS_MANTADORY,":26U:")
  TEXT(OS_MANTADORY, hField26U_TypeOfPrice, LETTER3)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD26U)

//////////////////////////////////////////////////////////////////
// FIELD28 - Statement Number, Page Number
/*
Definition:

The identification of the number (within the year) of particular statement. It may also identify the page number (message number) within a series of messages for the same statement.

Message Types:

571, 572, 573, 574
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD28, "SWIFT FIELD 28")
  STATIC(OS_MANTADORY,":28:")
  INTEGER(OS_MANTADORY, hField28_StatementNumber, VARDIGIT5, "%lu")
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    INTEGER(OS_MANTADORY, hField28_PageNumber, VARDIGIT2, "%lu")
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD28)

//////////////////////////////////////////////////////////////////
// FIELD28B - Page Number/Continuation Indicator
/*
Definition:

Indicates page number, whether or not the statement is to continue, and optionally the statement identification.

Message Types:

576
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD28B, "SWIFT FIELD 28B")
  STATIC(OS_MANTADORY,":28B:")
  INTEGER(OS_MANTADORY,hField28B_PageNumber,VARDIGIT3,"%lu")
  TEXT(OS_MANTADORY, hField28B_ContinueOrLastIndicator, LETTER1)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    TEXT(OS_MANTADORY,hField28B_StatementIdentification,VARTEXT5)
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD28B)

//////////////////////////////////////////////////////////////////
// FIELD28L - Page Number/Continuation Indicator
/*
Definition:

Indicates page number, whether or not the statement is to continue, and optionally the statement identification.

Price Limit Qualifier.

Message Types:

502, 576
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD28L, "SWIFT FIELD 28L")
  STATIC(OS_MANTADORY,":28L:")
  TEXT(OS_MANTADORY, hField28L_PriceLimitQualifier, LETTER3)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD28L)

//////////////////////////////////////////////////////////////////
// FIELD28P - Page Number/Continuation Indicator
/*
Definition:

Indicates page number, whether or not the statement is to continue, and optionally the statement identification.

Code word indicating Place of Trade or Exchange.
Description of other Place of Trade.

Message Types:

502, 513, 515, 518
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD28P, "SWIFT FIELD 28P")
  STATIC(OS_MANTADORY,":28P:")
  TEXT(OS_MANTADORY, hField28P_CodeWord, LETTER3)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    TEXT(OS_MANTADORY,hField28P_Description,VARTEXT30)
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD28P)

//////////////////////////////////////////////////////////////////
// FIELD29A - Identification of Location Within Sender/Receiver
/*
Definition:

The identification of the specific location for which the message is intended or from which the message has been sent within the receiving or sending finansial institution, respectively.

Identifies the specific location from which the message has been sent within the sending financial institution.

Message Types:

526
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD29A, "SWIFT FIELD 29A")
  STATIC(OS_MANTADORY,":29A:")
  MULTITEXT(OS_MANTADORY,hField29A_Location, 1, 4, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD29A)

//////////////////////////////////////////////////////////////////
// FIELD29B - Identification of Location Within Sender/Receiver
/*
Definition:

The identification of the specific location for which the message is intended or from which the message has been sent within the receiving or sending finansial institution, respectively.

Message Types:

526
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD29B, "SWIFT FIELD 29B")
  STATIC(OS_MANTADORY,":29B:")
  MULTITEXT(OS_MANTADORY,hField29B_Location, 1, 4, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD29B)

//////////////////////////////////////////////////////////////////
// FIELD29D - Identification of Location Within Sender/Receiver
/*
Definition:

The identification of the specific location for which the message is intended or from which the message has been sent within the receiving or sending finansial institution, respectively.

Message Types:

502, 513, 514, 515, 518
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD29D, "SWIFT FIELD 29D")
  STATIC(OS_MANTADORY,":29D:")
  TEXT(OS_MANTADORY,hField29D_CodeWord,LETTER3)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    TEXT(OS_MANTADORY,hField29D_AdditionalInformation,VARTEXT30)
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD29D)

//////////////////////////////////////////////////////////////////
// FIELD29E - Identification of Location Within Sender/Receiver
/*
Definition:

The identification of the specific location for which the message is intended or from which the message has been sent within the receiving or sending finansial institution, respectively.

Code word identifying the type of security or currency.
Quantity.

Note:

When used in MT 513, may consist of a currency code instead of security code (Error Code T37).

Message Types:

513
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD29E, "SWIFT FIELD 29E")
  STATIC(OS_MANTADORY,":29E:")
  TEXT(OS_MANTADORY,hField29E_SecurityOrCurrencyCode,LETTER3)
  NUMBER(OS_MANTADORY,hField29E_Quantity,NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD29E)

//////////////////////////////////////////////////////////////////
// FIELD29L - Identification of Location Within Sender/Receiver
/*
Definition:

The identification of the specific location for which the message is intended or from which the message has been sent within the receiving or sending finansial institution, respectively.

Code word identifying the type of security or currency.
Quantity.

Note:

When used in MT 513, may consist of a currency code instead of security code (Error Code T37).

Message Types:

513
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD29L, "SWIFT FIELD 29L")
  STATIC(OS_MANTADORY,":29L:")
  TEXT(OS_MANTADORY,hField29L_SecurityOrCurrencyCode,LETTER3)
  NUMBER(OS_MANTADORY,hField29L_Quantity,NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD29L)

//////////////////////////////////////////////////////////////////
// FIELD29O - Identification of Location Within Sender/Receiver
/*
Definition:

The identification of the specific location for which the message is intended or from which the message has been sent within the receiving or sending finansial institution, respectively.

Code word identifying the type of security or currency.
Quantity.

Note:

When used in MT 513, may consist of a currency code instead of security code (Error Code T37).

Message Types:

513
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD29O, "SWIFT FIELD 29O")
  STATIC(OS_MANTADORY,":29O:")
  TEXT(OS_MANTADORY,hField29O_SecurityOrCurrencyCode,LETTER3)
  NUMBER(OS_MANTADORY,hField29O_Quantity,NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD29O)

//////////////////////////////////////////////////////////////////
// FIELD29P - Identification of Location Within Sender/Receiver
/*
Definition:

The identification of the specific location for which the message is intended or from which the message has been sent within the receiving or sending finansial institution, respectively.

Code word identifying where the Partial Fill was executed.
Additional Information.

Message Types:

513, 515
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD29P, "SWIFT FIELD 29P")
  STATIC(OS_MANTADORY,":29P:")
  TEXT(OS_MANTADORY,hField29P_CodeWord,LETTER3)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    TEXT(OS_MANTADORY,hField29P_AdditionalInformation,VARTEXT30)
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD29P)

//////////////////////////////////////////////////////////////////
// FIELD29T - Identification of Location Within Sender/Receiver
/*
Definition:

The identification of the specific location for which the message is intended or from which the message has been sent within the receiving or sending finansial institution, respectively.

Time.

Message Types:

513, 515, 518
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD29T, "SWIFT FIELD 29T")
  STATIC(OS_MANTADORY,":29T:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    DATETIME(OS_MANTADORY,hField29T_Time,HHMMSS)
    DATETIME(OS_MANTADORY,hField29T_Time,HHMM)
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD29T)

//////////////////////////////////////////////////////////////////
// FIELD30 - Date
/*
Definition:

The identification of a date in the transaction.

Message Types:

500, 501, 510, 512, 516, 520, 521, 522, 523, 526, 530, 531, 532, 533, 534, 552, 553, 560, 563, 571, 572, 572B, 573, 573B, 573C, 574
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD30, "SWIFT FIELD 30")
  STATIC(OS_MANTADORY,":30:")
  DATETIME(OS_MANTADORY, hField30_Date, YYMMDD) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD30)

//////////////////////////////////////////////////////////////////
// FIELD30B - Time Limit/Expiry Date of Order and Trade Date
/*
Definition:

The identification of various codes indicating time limits and/or expiration dates.

Message Types:

502, 576
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD30B, "SWIFT FIELD 30B")
  STATIC(OS_MANTADORY,":30B:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      TEXT(OS_MANTADORY,hField30B_Code,LETTER3)
      DATETIME(OS_OPTIONAL, hField30B_Date, YYYYMMDD) 
    END_SEQUENCE
    DATETIME(OS_MANTADORY, hField30B_Date, YYYYMMDD) 
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD30B)

/////////////////////////////////////////////////////////////////////////
// FIELD30E - Time Limit/Expiry Date of Order and Trade Date
/*
Definition:

The identification of various codes indicating time limits and/or expiration dates.

Message Types:

513, 514, 515
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD30E, "SWIFT FIELD 30E")
  STATIC(OS_MANTADORY,":30E:")

  DATETIME(OS_OPTIONAL,hField30E_Date,YYYYMMDD)
  TEXT(OS_OPTIONAL,hField30E_Code,LETTER3)

  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD30E)

/////////////////////////////////////////////////////////////////////////
// FIELD30F - Time Limit/Expiry Date of Order and Trade Date
/*
Definition:

The identification of various codes indicating time limits and/or expiration dates.

Message Types:

518
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD30F, "SWIFT FIELD 30F")
  STATIC(OS_MANTADORY,":30F:")
  DATETIME(OS_MANTADORY, hField30F_Date, YYYYMMDD)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD30F)

/////////////////////////////////////////////////////////////////////////
// FIELD30P - Time Limit/Expiry Date of Order and Trade Date
/*
Definition:

The identification of various codes indicating time limits and/or expiration dates.

Message Types:

576
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD30P, "SWIFT FIELD 30P")
  STATIC(OS_MANTADORY,":30P:")
  DATETIME(OS_MANTADORY, hField30P_Date, YYYYMMDD)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD30P)

/////////////////////////////////////////////////////////////////////////
// FIELD30Q - Time Limit/Expiry Date of Order and Trade Date
/*
Definition:

The identification of various codes indicating time limits and/or expiration dates.

Message Types:

513, 515
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD30Q, "SWIFT FIELD 30Q")
  STATIC(OS_MANTADORY,":30Q:")
  DATETIME(OS_MANTADORY, hField30Q_Date, YYYYMMDD)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD30Q)

/////////////////////////////////////////////////////////////////////////
// FIELD31B - Date
/*
Definition:

The identification of a date in the transaction, which may also contain additional information about the date, such as a time and meeting place, an amount due on the date specified, or a range of dates.

Message Types:

560, 561
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD31B, "SWIFT FIELD 31B")
  STATIC(OS_MANTADORY,":31B:")
  DATETIME(OS_MANTADORY, hField31B_Date, YYMMDD)
  STATIC(OS_MANTADORY,EOL)
  MULTITEXT(OS_MANTADORY, hField31B_TimeAndPlace, 1, 4, NARRATIVE_TEXT65, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD31B)

//////////////////////////////////////////////////////////////////
// FIELD31C - Date
/*
Definition:

The identification of a date in the transaction, which may also contain additional information about the date, such as a time and meeting place, an amount due on the date specified, or a range of dates.

Message Types:

550, 552, 554, 555, 559, 574
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD31C, "SWIFT FIELD 31C")
  STATIC(OS_MANTADORY,":31C:")
  DATETIME(OS_MANTADORY, hField31C_Date, YYMMDD) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD31C)

//////////////////////////////////////////////////////////////////
// FIELD31E - Date
/*
Definition:

The identification of a date in the transaction, which may also contain additional information about the date, such as a time and meeting place, an amount due on the date specified, or a range of dates.

Message Types:

550, 552, 554, 555, 559
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD31E, "SWIFT FIELD 31E")
  STATIC(OS_MANTADORY,":31E:")
  DATETIME(OS_MANTADORY, hField31E_Date, YYMMDD)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD31E)

//////////////////////////////////////////////////////////////////
// FIELD31F - Date
/*
Definition:

The identification of a date in the transaction, which may also contain additional information about the date, such as a time and meeting place, an amount due on the date specified, or a range of dates.

Message Types:

516, 526, 583
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD31F, "SWIFT FIELD 31F")
  STATIC(OS_MANTADORY,":31F:")
  DATETIME(OS_MANTADORY,hField31F_Date1,  YYMMDD)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    DATETIME(OS_MANTADORY,hField31F_Date2,  YYMMDD)
  END_SEQUENCE
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"//")
    TEXT(OS_MANTADORY,hField31F_Narrative, VARTEXT35)
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD31F)

//////////////////////////////////////////////////////////////////
// FIELD31H - Date
/*
Definition:

The identification of a date in the transaction, which may also contain additional information about the date, such as a time and meeting place, an amount due on the date specified, or a range of dates.

Message Types:

550
552
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD31H, "SWIFT FIELD 31H")
  STATIC(OS_MANTADORY,":31H:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    DATETIME(OS_MANTADORY, hField31H_DateAndTime, YYMMDDHHMM)
    DATETIME(OS_MANTADORY, hField31H_DateAndTime, YYMMDD)
    TEXT(OS_MANTADORY, hField31H_CodeWord, VARLETTER7)
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD31H)

//////////////////////////////////////////////////////////////////
// FIELD31J - Date
/*
Definition:

The identification of a date in the transaction, which may also contain additional information about the date, such as a time and meeting place, an amount due on the date specified, or a range of dates.

Message Types:

550
552
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD31J, "SWIFT FIELD 31J")
  STATIC(OS_MANTADORY,":31J:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    DATETIME(OS_MANTADORY, hField31J_DateAndTime, YYMMDDHHMM)
    DATETIME(OS_MANTADORY, hField31J_DateAndTime, YYMMDD)
    TEXT(OS_MANTADORY, hField31J_CodeWord, VARLETTER7)
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD31J)

//////////////////////////////////////////////////////////////////
// FIELD31L - Date
/*
Definition:

The identification of a date in the transaction, which may also contain additional information about the date, such as a time and meeting place, an amount due on the date specified, or a range of dates.

Message Types:

516
552
554
559
563
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD31L, "SWIFT FIELD 31L")
  STATIC(OS_MANTADORY,":31L:")
  DATETIME(OS_MANTADORY, hField31L_Date, YYMMDD) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD31L)

//////////////////////////////////////////////////////////////////
// FIELD31P - Date
/*
Definition:

The identification of a date in the transaction, which may also contain additional information about the date, such as a time and meeting place, an amount due on the date specified, or a range of dates.

Message Types:

510
512
516
519
520
521
522
523
531
533
580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD31P, "SWIFT FIELD 31P")
  STATIC(OS_MANTADORY,":31P:")
  DATETIME(OS_MANTADORY, hField31P_Date, YYMMDD) 
  TEXT(OS_OPTIONAL, hField31P_Place, NARRATIVE_LINE29)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD31P)

//////////////////////////////////////////////////////////////////
// FIELD31S - Date
/*
Definition:

The identification of a date in the transaction, which may also contain additional information about the date, such as a time and meeting place, an amount due on the date specified, or a range of dates.

Message Types:

534  PROB
550  PARRI
552  PARRI
556  CALL
559  CALL
563  PARRY
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD31S, "SWIFT FIELD 31S")
  STATIC(OS_MANTADORY,":31S:")
  DATETIME(OS_MANTADORY, hField31S_Date, YYMMDD)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD31S)

//////////////////////////////////////////////////////////////////
// FIELD31T - Date
/*
Definition:

The identification of a date in the transaction, which may also contain additional information about the date, such as a time and meeting place, an amount due on the date specified, or a range of dates.

Message Types:

534  PROB
550  PARRI
552  PARRI
556  CALL
559  CALL
563  PARRY
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD31T, "SWIFT FIELD 31T")
  STATIC(OS_MANTADORY,":31T:")
  DATETIME(OS_MANTADORY, hField31T_Time, HHMM)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD31T)

//////////////////////////////////////////////////////////////////
// FIELD31U - Date
/*
Definition:

The identification of a date in the transaction, which may also contain additional information about the date, such as a time and meeting place, an amount due on the date specified, or a range of dates.

Message Types:

534  PROB
550  PARRI
552  PARRI
556  CALL
559  CALL
563  PARRY
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD31U, "SWIFT FIELD 31U")
  STATIC(OS_MANTADORY,":31U:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    DATETIME(OS_MANTADORY, hField31U_Time, HHMMSS)
    DATETIME(OS_MANTADORY, hField31U_Time, HHMM)
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD31U)

//////////////////////////////////////////////////////////////////
// FIELD31X - Date
/*
Definition:

The identification of a date in the transaction, which may also contain additional information about the date, such as a time and meeting place, an amount due on the date specified, or a range of dates.

Message Types:

550, 552, 554, 555
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD31X, "SWIFT FIELD 31X")
  STATIC(OS_MANTADORY,":31X:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    DATETIME(OS_MANTADORY, hField31X_DateAndTime, YYMMDDHHMM)
    DATETIME(OS_MANTADORY, hField31X_DateAndTime, YYMMDD)
    TEXT(OS_MANTADORY, hField31X_CodeWord, LETTER7)
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD31X)

//////////////////////////////////////////////////////////////////
// FIELD32A - Amount
/*
Definition:

The currency code and/or amount in the transaction, which may also contain other information conserning the amount, such as dete(s) or qualifying statements about the  amount.

Message Types:

516
900, 910
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD32A, "SWIFT FIELD 32A")
  STATIC(OS_MANTADORY,":32A:")
  DATETIME(OS_MANTADORY, hField32A_Date, YYMMDD)
  TEXT(OS_MANTADORY, hField32A_PriceOrCurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField32A_Amount, NUMBER15) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD32A)

//////////////////////////////////////////////////////////////////
// FIELD32B - Amount
/*
Definition:

The currency code and/or amount in the transaction, which may also contain other information conserning the amount, such as dete(s) or qualifying statements about the  amount.

Message Types:

510, 512, 514, 515, 516, 518, 521, 523, 531, 533, 539, 553, 562, 563, 573, 580
n91  AMNT
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD32B, "SWIFT FIELD 32B")
  STATIC(OS_MANTADORY,":32B:")
  TEXT(OS_MANTADORY, hField32B_CurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField32B_Amount, NUMBER15) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD32B)

//////////////////////////////////////////////////////////////////
// FIELD32AB
/*
Definition:

The currency code and/or amount in the transaction, which may also contain other information conserning the amount, such as dete(s) or qualifying statements about the  amount.

Message Types:

*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD32AB, "SWIFT FIELD 32(A or B)")
  STATIC(OS_MANTADORY,":32")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"A:")
      DATETIME(OS_MANTADORY, hField32a_Date, YYMMDD)
    END_SEQUENCE
    STATIC(OS_MANTADORY,"B:")
  END_PARALLEL
  TEXT(OS_MANTADORY, hField32a_PriceOrCurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField32a_Amount, NUMBER15) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD32AB)

//////////////////////////////////////////////////////////////////
// FIELD32CD
/*
Definition:

The currency code and/or amount in the transaction, which may also contain other information conserning the amount, such as dete(s) or qualifying statements about the  amount.

Message Types:

516
900, 910
n90
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD32CD, "SWIFT FIELD 32(C or D)")
  STATIC(OS_MANTADORY,":32")
  TEXT(OS_MANTADORY, hField32a_CreditOrDebit, "%*1[CD]%n\0")
  STATIC(OS_MANTADORY,":")
  DATETIME(OS_MANTADORY, hField32a_Date, YYMMDD)
  TEXT(OS_MANTADORY, hField32a_PriceOrCurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField32a_Amount, NUMBER15) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD32CD)

//////////////////////////////////////////////////////////////////
// FIELD32G - Amount
/*
Definition:

The currency code and/or amount in the transaction, which may also contain other information conserning the amount, such as dete(s) or qualifying statements about the  amount.

Message Types:

513, 514, 515, 518, 554, 557, 582
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD32G, "SWIFT FIELD 32G")
  STATIC(OS_MANTADORY,":32G:")
  TEXT(OS_MANTADORY, hField32G_CurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField32G_Amount, NUMBER15) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD32G)

//////////////////////////////////////////////////////////////////
// FIELD32H - Amount
/*
Definition:

The currency code and/or amount in the transaction, which may also contain other information conserning the amount, such as dete(s) or qualifying statements about the  amount.

Message Types:

571
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD32H, "SWIFT FIELD 32H")
  STATIC(OS_MANTADORY,":32H:")

  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"N")
      TEXT(OS_MANTADORY, hField32H_CurrencyCode, CURRENCY_ISO)
      NEGATIVE(OS_MANTADORY, hField32H_Amount, NUMBER15) 
    END_SEQUENCE
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      TEXT(OS_MANTADORY, hField32H_CurrencyCode, CURRENCY_ISO)
      NUMBER(OS_MANTADORY, hField32H_Amount, NUMBER15) 
    END_SEQUENCE
  END_PARALLEL

  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD32H)

//////////////////////////////////////////////////////////////////
// FIELD32L - Amount
/*
Definition:

The currency code and/or amount in the transaction, which may also contain other information conserning the amount, such as dete(s) or qualifying statements about the  amount.

Message Types:

500, 501, 574
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD32L, "SWIFT FIELD 32L")
  STATIC(OS_MANTADORY,":32L:")
  BEGIN_PARALLEL(OS_MANTADORY, NULL)
    BEGIN_SEQUENCE(OS_MANTADORY, NULL)
      TEXT(OS_MANTADORY, hField32L_PriceOrCurrencyCode, LETTER3)
      NUMBER(OS_MANTADORY, hField32L_Amount, NUMBER15)
      STATIC(OS_MANTADORY,EOL)
      BEGIN_SEQUENCE(OS_OPTIONAL, NULL)
        STATIC(OS_MANTADORY, "/")
        TEXT(OS_MANTADORY, hField32L_FurtherQualification, NARRATIVE_LINE35)
        STATIC(OS_MANTADORY, EOL)
      END_SEQUENCE
    END_SEQUENCE
    BEGIN_SEQUENCE(OS_MANTADORY, NULL)
      STATIC(OS_MANTADORY, "/")
      TEXT(OS_MANTADORY, hField32L_FurtherQualification, NARRATIVE_LINE35)
      STATIC(OS_MANTADORY, EOL)
    END_SEQUENCE
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD32L)

//////////////////////////////////////////////////////////////////
// FIELD32M - Amount
/*
Definition:

The currency code and/or amount in the transaction, which may also contain other information conserning the amount, such as dete(s) or qualifying statements about the  amount.

Message Types:

510
512
513
515
518
521  DEAL
523  DEAL
531  DEAL
533  DEAL
556  REDA
557  RED
559 REDA
580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD32M, "SWIFT FIELD 32M")
  STATIC(OS_MANTADORY,":32M:")
  TEXT(OS_MANTADORY, hField32M_CurrencyCode, CURRENCY_ISO)
  NUMBER(OS_MANTADORY, hField32M_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD32M)

//////////////////////////////////////////////////////////////////
// FIELD32O - Amount
/*
Definition:

The currency code and/or amount in the transaction, which may also contain other information conserning the amount, such as dete(s) or qualifying statements about the  amount.

Message Types:

502
576
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD32O, "SWIFT FIELD 32O")
  STATIC(OS_MANTADORY,":32M:")
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    TEXT(OS_MANTADORY, hField32O_PriceOrCurrencyCode, CURRENCY_ISO)
    NUMBER(OS_MANTADORY, hField32O_Amount, NUMBER15)
    STATIC(OS_MANTADORY,EOL)
  END_SEQUENCE
  BEGIN_LOOP(OS_OPTIONAL, "\0\0",1,4)
    STATIC(OS_MANTADORY,"/")
    TEXT(OS_MANTADORY,hField32O_TypeOfOrder,LETTER3)
    BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
      STATIC(OS_MANTADORY,"/")
      TEXT(OS_MANTADORY,hField32O_Description,VARTEXT30)
    END_SEQUENCE
    STATIC(OS_MANTADORY,EOL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD32O)

///////////////////////////////////////////////////////////////////////////////
// FIELD32S - Amount
/*
Definition:

The currency code and/or amount in the transaction, which may also contain other information conserning the amount, such as dete(s) or qualifying statements about the  amount.

Message Types:

500, 501, 510, 519
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD32S, "SWIFT FIELD 32S")
  STATIC(OS_MANTADORY,":32S:")
  DATETIME(OS_MANTADORY, hField32S_Date, YYMMDD)
  TEXT(OS_MANTADORY, hField32S_PriceOrCurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField32S_Amount, NUMBER15) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD32S)

///////////////////////////////////////////////////////////////////////////////
// FIELD32X - Amount
/*
Definition:

The currency code and/or amount in the transaction, which may also contain other information conserning the amount, such as dete(s) or qualifying statements about the  amount.

Message Types:

502, 576
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD32X, "SWIFT FIELD 32X")
  STATIC(OS_MANTADORY,":32X:")
  TEXT(OS_MANTADORY, hField32X_PriceOrCurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField32X_Amount, NUMBER15) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD32X)

///////////////////////////////////////////////////////////////////////////////
// FIELD33B - Amount
/*
Definition:

The currency code and amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

550  SUBPR
552  SUBPR
563  SUBS
571  571
572 572
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD33B, "SWIFT FIELD 33B")
  STATIC(OS_MANTADORY,":33B:")
  TEXT(OS_MANTADORY, hField33B_PriceOrCurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField33B_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD33B)

//////////////////////////////////////////////////////////////////
// FIELD33CD
/*
Definition:

The currency code and amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

555
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD33CD, "SWIFT FIELD 33CD")
  STATIC(OS_MANTADORY,":33")
  TEXT(OS_MANTADORY, hField33a_CreditOrDebit, "%*1[CD]%n\0")
  STATIC(OS_MANTADORY,":")
  DATETIME(OS_MANTADORY, hField33a_Date, YYMMDD)
  TEXT(OS_MANTADORY, hField33a_CurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField33a_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD33CD)

//////////////////////////////////////////////////////////////////
// FIELD33O - Amount
/*
Definition:

The currency code and amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

513, 515
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD33O, "SWIFT FIELD 33O")
  STATIC(OS_MANTADORY,":33O:")
  TEXT(OS_MANTADORY, hField33O_PriceOrCurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField33O_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD33O)

////////////////////////////////////////////////////////////////////////////////////
// FIELD33S - Amount
/*
Definition:

The currency code and amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

510
512
516
531  CONS
533  CONS
550  INDPRIGHT_ISO
552  INDPRIGHT_CW
563  CONCES
580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD33S, "SWIFT FIELD 33S")
  STATIC(OS_MANTADORY,":33S:")
  TEXT(OS_MANTADORY, hField33S_PriceOrCurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField33S_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD33S)

//////////////////////////////////////////////////////////////////
// FIELD33T - Amount
/*
Definition:

The currency code and amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

510
512
513
514
515
516
518
519
521  DEALP
523  DEALP
531  DEALP
533  DEALP
550  INDPRNI
552  INDPR
556  RED
559 RED
580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD33T, "SWIFT FIELD 33T")
  STATIC(OS_MANTADORY,":33T:")
  TEXT(OS_MANTADORY, hField33T_PriceOrCurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField33T_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD33T)

//////////////////////////////////////////////////////////////////
// FIELD33V - Amount
/*
Definition:

The currency code and amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

502, 513, 520, 521, 522, 523, 530, 531, 532, 533, 539
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD33V, "SWIFT FIELD 33V")
  STATIC(OS_MANTADORY,":33V:")
  TEXT(OS_MANTADORY, hField33V_PriceOrCurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField33V_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD33V)

//////////////////////////////////////////////////////////////////
// FIELD33X - Amount
/*
Definition:

The currency code and amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

515, 518
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD33X, "SWIFT FIELD 33X")
  STATIC(OS_MANTADORY,":33X:")
  TEXT(OS_MANTADORY, hField33X_ToCurrencyCode, LETTER3)
  STATIC(OS_MANTADORY,"/")
  TEXT(OS_MANTADORY, hField33X_FromCurrencyCode, LETTER3)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD33X)

//////////////////////////////////////////////////////////////////
// FIELD34A - Amount
/*
Definition:

The currency code and an amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

510, 512, 531, 533, 554, 557, 559, 563, 582
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD34A, "SWIFT FIELD 34A")
  STATIC(OS_MANTADORY,":34A:")
  DATETIME(OS_MANTADORY, hField34A_Date, YYMMDD)
  TEXT(OS_MANTADORY, hField34A_CurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField34A_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD34A)

//////////////////////////////////////////////////////////////////
// FIELD34B - Amount
/*
Definition:

The currency code and an amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

510, 512, 515, 518, 581
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD34B, "SWIFT FIELD 34B")
  STATIC(OS_MANTADORY,":34B:")
  TEXT(OS_MANTADORY, hField34a_CurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField34a_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD34B)

//////////////////////////////////////////////////////////////////
// FIELD34CD
/*
Definition:

The currency code and an amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

555, 556, 572
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD34CD, "SWIFT FIELD 34a(C or D)")
  STATIC(OS_MANTADORY,":34")
  TEXT(OS_MANTADORY, hField34CD_CreditOrDebit, "%*1[CD]%n\0")
  STATIC(OS_MANTADORY,":")
  DATETIME(OS_MANTADORY, hField34CD_Date, YYMMDD)
  TEXT(OS_MANTADORY, hField34CD_CurrencyCode, CURRENCY_ISO)
  NUMBER(OS_MANTADORY, hField34CD_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD34CD)

//////////////////////////////////////////////////////////////////
// FIELD34E - Amount
/*
Definition:

The currency code and an amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

571
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD34E, "SWIFT FIELD 34E")
  STATIC(OS_MANTADORY,":34E:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"N")
      TEXT(OS_MANTADORY, hField34E_CurrencyCode, CURRENCY_ISO)
      NEGATIVE(OS_MANTADORY, hField34E_Amount, NUMBER15)
    END_SEQUENCE
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      TEXT(OS_MANTADORY, hField34E_CurrencyCode, CURRENCY_ISO)
      NUMBER(OS_MANTADORY, hField34E_Amount, NUMBER15)
    END_SEQUENCE
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD34E)

//////////////////////////////////////////////////////////////////
// FIELD34I - Amount
/*
Definition:

The currency code and an amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

515, 518
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD34I, "SWIFT FIELD 34I")
  STATIC(OS_MANTADORY,":34I:")
  DATETIME(OS_MANTADORY, hField34a_Date, YYYYMMDD)
  TEXT(OS_MANTADORY, hField34a_CurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField34a_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD34I)

////////////////////////////////////////////////////////////////////////////////////////////////
// FIELD34AB - Amount
/*
Definition:

The currency code and an amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

510, 512
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD34AB, "SWIFT FIELD 34a(A or B)")
  STATIC(OS_MANTADORY,":34")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"A:")
      DATETIME(OS_MANTADORY, hField34a_Date, YYMMDD)
    END_SEQUENCE
    STATIC(OS_MANTADORY,"B:")
  END_PARALLEL
  TEXT(OS_MANTADORY, hField34a_CurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField34a_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD34AB)

////////////////////////////////////////////////////////////////////////////////////////////////
// FIELD34BI - Amount
/*
Definition:

The currency code and an amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

515, 518
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD34BI, "SWIFT FIELD 34a(B or I)")
  STATIC(OS_MANTADORY,":34")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"I:")
      DATETIME(OS_MANTADORY, hField34a_Date, YYYYMMDD)
    END_SEQUENCE
    STATIC(OS_MANTADORY,"B:")
  END_PARALLEL
  TEXT(OS_MANTADORY, hField34a_CurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField34a_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD34BI)

////////////////////////////////////////////////////////////////////////////////////////////////
// FIELD35A - Specification of Securities
/*
Definition:

The identification of securities related transaction.

Messages Types:

500, 501, 510, 512, 513, 514, 515, 516, 518, 519, 520, 521, 522, 523, 526, 530, 531, 532, 533, 534, 539, 550, 551, 552, 553, 554, 555, 556, 559, 560, 561, 562, 563, 572, 573, 574, 576, 577, 580, 582, 589
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD35A, "SWIFT FIELD 35A")
  STATIC(OS_MANTADORY,":35A:")
  TEXT(OS_MANTADORY, hField35A_CodeWord, LETTER3)
  NUMBER(OS_MANTADORY, hField35A_Quantity, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD35A)

//////////////////////////////////////////////////////////////////
// FIELD35B - Specification of Securities
/*
Definition:

The identification of securities related transaction.

Messages Types:

500, 501, 502, 510, 512, 513, 514, 515, 516, 518, 519, 520, 521, 522, 523, 526, 530, 531, 532, 533, 534, 539, 550, 551, 552, 553, 554, 555, 556, 559, 560, 561, 562, 563, 570, 571, 572, 573, 574, 576, 577, 580, 581, 582, 583
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD35B, "SWIFT FIELD 35B")
  STATIC(OS_MANTADORY,":35B:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"ISIN ")
      TEXT(OS_MANTADORY, hField35B_ISIN, ISIN)
      STATIC(OS_MANTADORY,EOL)
      BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
        MULTITEXT(OS_MANTADORY, hField35B_DescriptionOfTheSecurity, 1, 4, NARRATIVE_TEXT35, EOL, SOForEOT)
        STATIC(OS_MANTADORY,EOL)
      END_SEQUENCE
    END_SEQUENCE
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      MULTITEXT(OS_MANTADORY, hField35B_DescriptionOfTheSecurity, 1, 4, NARRATIVE_TEXT35, EOL, SOForEOT)
      STATIC(OS_MANTADORY,EOL)
    END_SEQUENCE
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD35B)

//////////////////////////////////////////////////////////////////
// FIELD35C - Specification of Securities
/*
Definition:

The identification of securities related transaction.

Messages Types:

500, 501, 510, 512, 520, 521, 522, 523, 530, 531, 532, 533, 550, 552, 554, 555, 559, 563
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD35C, "SWIFT FIELD 35C")
  STATIC(OS_MANTADORY,":35C:")
  TEXT(OS_MANTADORY|TS_COUPONPATCH, hField35C_SpecificationOfSecurities, LETTERDIGIT3) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD35C)

//////////////////////////////////////////////////////////////////
// FIELD35D - Specification of Securities
/*
Definition:

The identification of securities related transaction.

Messages Types:

500, 501, 510, 512, 520, 521, 522, 523, 530, 531, 532, 533, 550, 552, 554, 555, 556, 559, 563
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD35D, "SWIFT FIELD 35D")
  STATIC(OS_MANTADORY,":35D:")
  DATETIME(OS_MANTADORY, hField35D_SpecificationOfSecurities, YYMMDD) 
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD35D)

//////////////////////////////////////////////////////////////////
// FIELD35E - Specification of Securities
/*
Definition:

The identification of securities related transaction.

Messages Types:

501, 510, 520, 521, 522, 523, 530, 531, 532, 533, 556, 559, 580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD35E, "SWIFT FIELD 35E")
  STATIC(OS_MANTADORY,":35E:")
  MULTITEXT(OS_MANTADORY, hField35E_SpecificationOfSecurities, 1, 6, NARRATIVE_TEXT50, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD35E)

//////////////////////////////////////////////////////////////////
// FIELD35F - Specification of Securities
/*
Definition:

The identification of securities related transaction.

Messages Types:

577, 579
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD35F, "SWIFT FIELD 35F")
  STATIC(OS_MANTADORY,":35F:")
  MULTITEXT(OS_MANTADORY, hField35F_SpecificationOfSecurities, 1, 35, NARRATIVE_TEXT50, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD35F)

//////////////////////////////////////////////////////////////////
// FIELD35H - Specification of Securities
/*
Definition:

The identification of securities related transaction.

Messages Types:

571, 581
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD35H, "SWIFT FIELD 35H")
  STATIC(OS_MANTADORY,":35H:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"N")
      TEXT(OS_MANTADORY, hField35H_CodeWord, LETTER3)
      NEGATIVE(OS_MANTADORY, hField35H_Quantity, NUMBER15)
    END_SEQUENCE
    BEGIN_SEQUENCE(OS_MANTADORY, NULL)
      TEXT(OS_MANTADORY, hField35H_CodeWord, LETTER3)
      NUMBER(OS_MANTADORY, hField35H_Quantity, NUMBER15)
    END_SEQUENCE
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD35H)

//////////////////////////////////////////////////////////////////
// FIELD35L - Specification of Securities
/*
Definition:

The identification of securities related transaction.

Messages Types:

555, 556, 559
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD35L, "SWIFT FIELD 35L")
  STATIC(OS_MANTADORY,":35L:")
  MULTITEXT(OS_MANTADORY, hField35L_SpecificationOfSecurities, 1, 4, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD35L)

//////////////////////////////////////////////////////////////////
// FIELD35N - Specification of Securities
/*
Definition:

The identification of securities related transaction.

Messages Types:

516, 555
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD35N, "SWIFT FIELD 35N")
  STATIC(OS_MANTADORY,":35N:")
  TEXT(OS_MANTADORY, hField35N_CodeWord, LETTER3)
  NUMBER(OS_MANTADORY, hField35N_Quantity, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD35N)

//////////////////////////////////////////////////////////////////
// FIELD35P - Specification of Securities
/*
Definition:

The identification of securities related transaction.

Messages Types:

514, 555
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD35P, "SWIFT FIELD 35P")
  STATIC(OS_MANTADORY,":35P:")
  TEXT(OS_MANTADORY, hField35P_CodeWord, LETTER3)
  NUMBER(OS_MANTADORY, hField35P_Quantity, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD35P)

//////////////////////////////////////////////////////////////////
// FIELD35S - Specification of Securities
/*
Definition:

The identification of securities related transaction.

Messages Types:

513, 514, 515, 516, 552, 553, 562, 563, 582
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD35S, "SWIFT FIELD 35S")
  STATIC(OS_MANTADORY,":35S:")
  TEXT(OS_MANTADORY, hField35S_CodeWord, LETTER3)
  NUMBER(OS_MANTADORY, hField35S_Quantity, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD35S)

//////////////////////////////////////////////////////////////////
// FIELD35T - Specification of Securities
/*
Definition:

The identification of securities related transaction.

Messages Types:

550, 552
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD35T, "SWIFT FIELD 35T")
  STATIC(OS_MANTADORY,":35T:")
  NUMBER(OS_MANTADORY, hField35T_NumberOfRights, NUMBER7)
  STATIC(OS_MANTADORY,"/")
  TEXT(OS_MANTADORY, hField35T_CodeWord, LETTER3)
  NUMBER(OS_MANTADORY, hField35T_NumberOfSecurities, NUMBER7)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD35T)

//////////////////////////////////////////////////////////////////
// FIELD35U - Specification of Securities
/*
Definition:

The identification of securities related transaction.

Messages Types:

554, 559
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD35U, "SWIFT FIELD 35U")
  STATIC(OS_MANTADORY,":35U:")
  TEXT(OS_MANTADORY, hField35U_PriceOrCurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField35U_Amount, NUMBER15)
  TEXT(OS_OPTIONAL, hField35U_Code, LETTER1)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD35U)

//////////////////////////////////////////////////////////////////
// FIELD36 - Exchange Rate
/*
Definition:

The rate of exchange between the currencies appearing in the transaction.

Message Types:

510, 512, 515, 518, 531, 533, 554, 555, 556, 557, 559, 563, 571, 582
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD36, "SWIFT FIELD 36")
  STATIC(OS_MANTADORY,":36:")
  NUMBER(OS_MANTADORY, hField36_ExchangeRate, NUMBER12)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD36)

//////////////////////////////////////////////////////////////////
// FIELD37J - Interest Field
/*
Definition:

The specification of the interest rate, which may also identify the method of interest computation and additional information about the interest rate.

Message Types:

516, 580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD37J, "SWIFT FIELD 37J")
  STATIC(OS_MANTADORY,":37J:")
  NUMBER(OS_MANTADORY, hField37J_InterestField, NUMBER12)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD37J)

//////////////////////////////////////////////////////////////////
// FIELD37L - Interest Field
/*
Definition:

The specification of the interest rate, which may also identify the method of interest computation and additional information about the interest rate.

Message Types:

580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD37L, "SWIFT FIELD 37L")
  STATIC(OS_MANTADORY,":37L:")
  NUMBER(OS_MANTADORY, hField37L_InterestField, NUMBER12)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD37L)

//////////////////////////////////////////////////////////////////
// FIELD37P - Interest Field
/*
Definition:

The specification of the interest rate, which may also identify the method of interest computation and additional information about the interest rate.

Message Types:

580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD37P, "SWIFT FIELD 37P")
  STATIC(OS_MANTADORY,":37P:")
  NUMBER(OS_MANTADORY, hField37P_InterestField, NUMBER12)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD37P)

//////////////////////////////////////////////////////////////////
// FIELD37S - Interest Field
/*
Definition:

The specification of the interest rate, which may also identify the method of interest computation and additional information about the interest rate.

Message Types:

580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD37S, "SWIFT FIELD 37S")
  STATIC(OS_MANTADORY,":37S:")
  NUMBER(OS_MANTADORY, hField37S_InterestField1, NUMBER12)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    TEXT(OS_MANTADORY, hField37S_InterestField2,VARDIGIT4)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD37S)

//////////////////////////////////////////////////////////////////
// FIELD37ABCDEF - Interest Field
/*
Definition:

The specification of the interest rate, which may also identify the method of interest computation and additional information about the interest rate.

Message Types:

516
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD37ABCDEF, "SWIFT FIELD 37ABCDEF")
  STATIC(OS_MANTADORY,":37")
  TEXT(OS_MANTADORY,hField37a_Tag,"[A-F]%n\0")
  STATIC(OS_MANTADORY,":")
  NUMBER(OS_MANTADORY, hField37a_InterestRate,NUMBER12)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    DATETIME(OS_MANTADORY,hField37a_Date,YYMMDD)
    TEXT(OS_MANTADORY,hField37a_PeriodCode,LETTER1)
    INTEGER(OS_MANTADORY,hField37a_NumberOfDaysOrMonths, VARDIGIT3,"%3ld")
  END_SEQUENCE
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    TEXT(OS_MANTADORY,hField37a_CodeWord,VARTEXT16)
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD37ABCDEF)

//////////////////////////////////////////////////////////////////
// FIELD38F - Period Specification
/*
Definition:

The number of days in a period.

Message Types:

513, 515
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD38F, "SWIFT FIELD 38F")
  STATIC(OS_MANTADORY,":38F:")
  TEXT(OS_MANTADORY,hField38F_Code,LETTER1)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD38F)

//////////////////////////////////////////////////////////////////
// FIELD39D - Amount Specification
/*
Definition:

The specification of further information about the amount of the transaction.

Message Types:

514
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD39D, "SWIFT FIELD 39D")
  STATIC(OS_MANTADORY,":39D:")
  INTEGER(OS_MANTADORY,hField39D_AllocationNumber, VARDIGIT3,"%3ld")
  STATIC(OS_MANTADORY,"/")
  INTEGER(OS_MANTADORY,hField39D_TotalNumberOfAllocations, VARDIGIT3,"%3ld")
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD39D)

//////////////////////////////////////////////////////////////////
// FIELD44S - Shipment Details
/*
Definition:

The specification of the place of dispatch or taking in charge of the goods, or loading on board, and the place of final destignation, as well as the latest date for shipment, if applicable, or the period of time during which this is  to take place.

Message Types:

513, 514, 515, 518
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD44S, "SWIFT FIELD 44S")
  STATIC(OS_MANTADORY,":44S:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    DATETIME(OS_MANTADORY,hField44S_Date,YYYYMMDD)
    TEXT(OS_MANTADORY,hField44S_Code,LETTER3)
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD44S)

//////////////////////////////////////////////////////////////////
// FIELD50 - Ordering Customer
/*
Definition:

The customer ordering the transaction.

Message Types:

100, 102
210
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD50, "SWIFT FIELD 50")
  STATIC(OS_MANTADORY,":50:")
  MULTITEXT(OS_MANTADORY, hField50_NameAndAddress, 1, 4, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD50)

//////////////////////////////////////////////////////////////////
// FIELD60A - Opening Balance
/*
Definition:

The balance of an account at beginning of a statement period or, in the case of multiply messages for the same statement period, the intermediate opening balance.

Message Types:

572
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD60A, "SWIFT FIELD 60A")
  STATIC(OS_MANTADORY,":60A:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"N")
      NEGATIVE(OS_MANTADORY, hField60A_Amount, NUMBER15)
    END_SEQUENCE
    NUMBER(OS_MANTADORY, hField60A_Amount, NUMBER15)
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD60A)

//////////////////////////////////////////////////////////////////
// FIELD60B - Opening Balance
/*
Definition:

The balance of an account at beginning of a statement period or, in the case of multiply messages for the same statement period, the intermediate opening balance.

Message Types:

571, 572
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD60B, "SWIFT FIELD 60B")
  STATIC(OS_MANTADORY,":60B:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"N")
      NEGATIVE(OS_MANTADORY, hField60B_Amount, NUMBER15)
    END_SEQUENCE
    NUMBER(OS_MANTADORY, hField60B_Amount, NUMBER15)
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD60B)

//////////////////////////////////////////////////////////////////
// FIELD62A - Closing Balance (Booked Funds)
/*
Definition:

The balance of an account at the close of statement period or, in the case of multiplye messages for the same statement period, the intermediate closing balance.

Message Types:

572
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD62A, "SWIFT FIELD 62A")
  STATIC(OS_MANTADORY,":62A:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"N")
      NEGATIVE(OS_MANTADORY, hField62A_Amount, NUMBER15)
    END_SEQUENCE
    NUMBER(OS_MANTADORY, hField62A_Amount, NUMBER15)
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD62A)

//////////////////////////////////////////////////////////////////
// FIELD62B - Closing Balance (Booked Funds)
/*
Definition:

The balance of an account at the close of statement period or, in the case of multiplye messages for the same statement period, the intermediate closing balance.

Message Types:

572
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD62B, "SWIFT FIELD 62B")
  STATIC(OS_MANTADORY,":62B:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"N")
      NEGATIVE(OS_MANTADORY, hField62B_Amount, NUMBER15)
    END_SEQUENCE
    NUMBER(OS_MANTADORY, hField62B_Amount, NUMBER15)
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD62B)

//////////////////////////////////////////////////////////////////
// FIELD66A - Transaction Details
/*
Definition:

The specification of  the transaction details.

Message Types:

572
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD66A, "SWIFT FIELD 66A")
  STATIC(OS_MANTADORY,":66A:")
  DATETIME(OS_MANTADORY, hField66A_PostingDate, YYMMDD)
  TEXT(OS_MANTADORY, hField66A_DirectionOfTheTransaction, "%*1[NT]%n\0")
  INTEGER(OS_MANTADORY|IS_NULLPATCH, hField66A_TransactionType, "%*1[0-9]%*1[0-9]%n\0", "%02lu")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    TEXT(OS_MANTADORY, hField66A_ReceiversReference, "%*16" "[-a-zA-Z0-9?().,'+{} ]" "%n\0")
    STATIC(OS_MANTADORY,"NONREF")
  END_PARALLEL
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"//")
    TEXT(OS_MANTADORY, hField66A_SendersReference, "%*16" "[-a-zA-Z0-9?().,'+{} ]" "%n\0")
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD66A)

//////////////////////////////////////////////////////////////////
// FIELD67A - Statement Period
/*
Definition:

The specification of the date(s) covered by a statement or for which a statement is requested.

Message Types:

570, 571, 572, 573, 574, 577
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD67A, "SWIFT FIELD 67A")
  STATIC(OS_MANTADORY,":67A:")
  DATETIME(OS_MANTADORY, hField67A_FirstDateOfPeriod, YYMMDD)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    DATETIME(OS_MANTADORY, hField67A_LastDateOfPeriod, YYMMDD)
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD67A)

BEGIN_IMPLEMENT_SEQUENCE(FIELD67A_571, "SWIFT FIELD 67A")
  STATIC(OS_MANTADORY,":67A:")
  DATETIME(OS_MANTADORY, hField67A_DateOfPeriod, YYMMDD)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD67A_571)

//////////////////////////////////////////////////////////////////
// FIELD67S - Statement Period
/*
Definition:

The specification of the date(s) covered by a statement or for which a statement is requested.

Message Types:

576
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD67S, "SWIFT FIELD 67S")
  STATIC(OS_MANTADORY,":67S:")
  DATETIME(OS_MANTADORY, hField67S_Date, YYYYMMDD)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD67S)

//////////////////////////////////////////////////////////////////
// CHARGES71BCD

BEGIN_IMPLEMENT_SEQUENCE(CHARGES71BCD, "SWIFT CHARGES OF  FIELDS 71B 71C 71D")
  STATIC(OS_MANTADORY,"/")
  TEXT(OS_MANTADORY, hField71a_CodeWord, VARLETTER8)
  STATIC(OS_MANTADORY,"/")
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    TEXT(OS_MANTADORY, hField71a_CurrencyCode, CURRENCY_ISO)
    NUMBER(OS_MANTADORY, hField71a_Amount, NUMBER13)
  END_SEQUENCE
  MULTITEXT(OS_OPTIONAL, hField71a_AdditionalInformation, 1, 6, ADDITIONAL_TEXT33, "\r\n//",  EOAI)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(CHARGES71BCD)

//////////////////////////////////////////////////////////////////
// FIELD71B - Details of Charges

BEGIN_IMPLEMENT_SEQUENCE(FIELD71B, "SWIFT FIELD 71B")
  STATIC(OS_MANTADORY,":71B:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      LOOP(OS_MANTADORY, "charges_71\0chrg_typ_c='B'\0NOT chrg_cdw71_c='<nocode>'", 1, 6) CUSTOM1(CHARGES71BCD,OS_MANTADORY,NULL)
      BEGIN_LOOP(OS_OPTIONAL, "charges_71\0chrg_typ_c='B', chrg_cdw71_c='<nocode>'\0", 1, 1)
        MULTITEXT(OS_MANTADORY, hField71a_AdditionalInformation, 1, 5, NARRATIVE_TEXT35, EOL, SOForEOT)
        STATIC(OS_MANTADORY,EOL)
      END_LOOP
    END_SEQUENCE
    BEGIN_LOOP(OS_MANTADORY, "charges_71\0chrg_typ_c='B', chrg_cdw71_c='<nocode>'\0", 1, 1)
      MULTITEXT(OS_MANTADORY, hField71a_AdditionalInformation, 1, 6, NARRATIVE_TEXT35, EOL, SOForEOT)
      STATIC(OS_MANTADORY,EOL)
    END_LOOP
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD71B)

BEGIN_IMPLEMENT_SEQUENCE(FIELD71B_MULT, "SWIFT FIELD 71B")
  STATIC(OS_MANTADORY,":71B:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      LOOP(OS_MANTADORY, "charges_71mult\0chrg_typ_c='B'\0NOT chrg_cdw71_c='<nocode>'", 1, 6) CUSTOM1(CHARGES71BCD,OS_MANTADORY,NULL)
      BEGIN_LOOP(OS_OPTIONAL, "charges_71mult\0chrg_typ_c='B', chrg_cdw71_c='<nocode>'\0", 1, 1)
        MULTITEXT(OS_MANTADORY, hField71a_AdditionalInformation, 1, 5, NARRATIVE_TEXT35, EOL, SOForEOT)
        STATIC(OS_MANTADORY,EOL)
      END_LOOP
    END_SEQUENCE
    BEGIN_LOOP(OS_MANTADORY,"charges_71mult\0chrg_typ_c='B', chrg_cdw71_c='<nocode>'\0", 1, 1)
      MULTITEXT(OS_MANTADORY, hField71a_AdditionalInformation, 1, 6, NARRATIVE_TEXT35, EOL, SOForEOT)
      STATIC(OS_MANTADORY,EOL)
    END_LOOP
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD71B_MULT)

BEGIN_IMPLEMENT_SEQUENCE(FIELD71B_MMLT, "SWIFT FIELD 71B")
  STATIC(OS_MANTADORY,":71B:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      LOOP(OS_MANTADORY, "charges_71mmlt\0chrg_typ_c='B'\0NOT chrg_cdw71_c='<nocode>'", 1, 6) CUSTOM1(CHARGES71BCD,OS_MANTADORY,NULL)
      BEGIN_LOOP(OS_OPTIONAL,"charges_71mmlt\0chrg_typ_c='B', chrg_cdw71_c='<nocode>'\0", 1, 1)
        MULTITEXT(OS_MANTADORY, hField71a_AdditionalInformation, 1, 5, NARRATIVE_TEXT35, EOL, SOForEOT)
        STATIC(OS_MANTADORY,EOL)
      END_LOOP
    END_SEQUENCE
    BEGIN_LOOP(OS_MANTADORY,"charges_71mmlt\0chrg_typ_c='B', chrg_cdw71_c='<nocode>'\0", 1, 1)
      MULTITEXT(OS_MANTADORY, hField71a_AdditionalInformation, 1, 6, NARRATIVE_TEXT35, EOL, SOForEOT)
      STATIC(OS_MANTADORY,EOL)
    END_LOOP
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD71B_MMLT)

//////////////////////////////////////////////////////////////////
// FIELD71C - Details of Charges

BEGIN_IMPLEMENT_SEQUENCE(FIELD71C, "SWIFT FIELD 71C")
  STATIC(OS_MANTADORY,":71C:")

  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      LOOP(OS_MANTADORY,"charges_71\0chrg_typ_c='C'\0NOT chrg_cdw71_c='<nocode>'", 1, 6)  CUSTOM1(CHARGES71BCD,OS_MANTADORY,NULL)
      BEGIN_LOOP(OS_OPTIONAL,"charges_71\0chrg_typ_c='C', chrg_cdw71_c='<nocode>'\0", 1, 1)
        MULTITEXT(OS_MANTADORY, hField71a_AdditionalInformation, 1, 5, NARRATIVE_TEXT35, EOL, SOForEOT)
        STATIC(OS_MANTADORY,EOL)
      END_LOOP
    END_SEQUENCE

    BEGIN_LOOP(OS_MANTADORY,"charges_71\0chrg_typ_c='C', chrg_cdw71_c='<nocode>'\0", 1, 1)
      MULTITEXT(OS_MANTADORY, hField71a_AdditionalInformation, 1, 6, NARRATIVE_TEXT35, EOL, SOForEOT)
      STATIC(OS_MANTADORY,EOL)
    END_LOOP
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD71C)

BEGIN_IMPLEMENT_SEQUENCE(FIELD71C_MULT, "SWIFT FIELD 71C")
  STATIC(OS_MANTADORY,":71C:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      LOOP(OS_MANTADORY,"charges_71mult\0chrg_typ_c='C'\0NOT chrg_cdw71_c='<nocode>'", 1, 6) CUSTOM1(CHARGES71BCD,OS_MANTADORY,NULL)
      BEGIN_LOOP(OS_OPTIONAL,"charges_71mult\0chrg_typ_c='C', chrg_cdw71_c='<nocode>'\0", 1, 1)
        MULTITEXT(OS_MANTADORY, hField71a_AdditionalInformation, 1, 5, NARRATIVE_TEXT35, EOL, SOForEOT)
        STATIC(OS_MANTADORY,EOL)
      END_LOOP
    END_SEQUENCE
    BEGIN_LOOP(OS_MANTADORY,"charges_71mult\0chrg_typ_c='C', chrg_cdw71_c='<nocode>'\0", 1, 1)
      MULTITEXT(OS_MANTADORY, hField71a_AdditionalInformation, 1, 6, NARRATIVE_TEXT35, EOL, SOForEOT)
      STATIC(OS_MANTADORY,EOL)
    END_LOOP
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD71C_MULT)

BEGIN_IMPLEMENT_SEQUENCE(FIELD71C_MMLT, "SWIFT FIELD 71C")
  STATIC(OS_MANTADORY,":71C:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      LOOP(OS_MANTADORY,"charges_71mmlt\0chrg_typ_c='C'\0NOT chrg_cdw71_c='<nocode>'", 1, 6) CUSTOM1(CHARGES71BCD,OS_MANTADORY,NULL)
      BEGIN_LOOP(OS_OPTIONAL,"charges_71mmlt\0chrg_typ_c='C', chrg_cdw71_c='<nocode>'\0", 1, 1)
        MULTITEXT(OS_MANTADORY, hField71a_AdditionalInformation, 1, 5, NARRATIVE_TEXT35, EOL, SOForEOT)
        STATIC(OS_MANTADORY,EOL)
      END_LOOP
    END_SEQUENCE
    BEGIN_LOOP(OS_MANTADORY,"charges_71mmlt\0chrg_typ_c='C', chrg_cdw71_c='<nocode>'\0", 1, 1)
      MULTITEXT(OS_MANTADORY, hField71a_AdditionalInformation, 1, 6, NARRATIVE_TEXT35, EOL, SOForEOT)
      STATIC(OS_MANTADORY,EOL)
    END_LOOP
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD71C_MMLT)

//////////////////////////////////////////////////////////////////
// FIELD71D - Details of Charges

BEGIN_IMPLEMENT_SEQUENCE(FIELD71D, "SWIFT FIELD 71D")
  STATIC(OS_MANTADORY,":71D:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      LOOP(OS_MANTADORY,"charges_71\0chrg_typ_c='D'\0NOT chrg_cdw71_c='<nocode>'", 1, 6)  CUSTOM1(CHARGES71BCD,OS_MANTADORY,NULL)
      BEGIN_LOOP(OS_OPTIONAL,"charges_71\0chrg_typ_c='D', chrg_cdw71_c='<nocode>'\0", 1, 1)
        MULTITEXT(OS_MANTADORY, hField71a_AdditionalInformation, 1, 5, NARRATIVE_TEXT35, EOL, SOForEOT)
        STATIC(OS_MANTADORY,EOL)
      END_LOOP
    END_SEQUENCE
    BEGIN_LOOP(OS_MANTADORY,"charges_71\0chrg_typ_c='D', chrg_cdw71_c='<nocode>'\0", 1, 1)
      MULTITEXT(OS_MANTADORY, hField71a_AdditionalInformation, 1, 6, NARRATIVE_TEXT35, EOL, SOForEOT)
      STATIC(OS_MANTADORY,EOL)
    END_LOOP
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD71D)

//////////////////////////////////////////////////////////////////
// FIELD71E - Details of Charges

BEGIN_IMPLEMENT_SEQUENCE(FIELD71E, "SWIFT FIELD 71E")
  STATIC(OS_MANTADORY,":71E:")
  TEXT(OS_MANTADORY, hField71E_CurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField71E_Amount, NUMBER15)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    STATIC(OS_MANTADORY,"/")
    NUMBER(OS_MANTADORY, hField71E_Rate, NUMBER15)
  END_SEQUENCE
  STATIC(OS_MANTADORY,EOL)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    MULTITEXT(OS_MANTADORY, hField71E_AdditionalInformation, 1, 4, NARRATIVE_TEXT35 , EOL, SOForEOT)
    STATIC(OS_MANTADORY,EOL)
  END_SEQUENCE
END_IMPLEMENT_SEQUENCE(FIELD71E)

//////////////////////////////////////////////////////////////////
// FIELD71F - Details of Charges

BEGIN_IMPLEMENT_SEQUENCE(FIELD71F, "SWIFT FIELD 71F")
  STATIC(OS_MANTADORY,":71F:")
  TEXT(OS_MANTADORY, hField71F_CurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField71F_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD71F)

//////////////////////////////////////////////////////////////////
// FIELD71G - Details of Charges

BEGIN_IMPLEMENT_SEQUENCE(FIELD71G, "SWIFT FIELD 71G")
  STATIC(OS_MANTADORY,":71G:")
  TEXT(OS_MANTADORY, hField71G_CurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField71G_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD71G)

//////////////////////////////////////////////////////////////////
// FIELD72 - Sender to Receiver Information
/*
Definition:

Instructions or additional information for the Receiver, Intermediary, Account With Institution or Beneficiary Institution.

Message Types:

520, 521, 522, 523, 526, 530, 531, 532, 533, 534, 550, 551, 552, 553, 554A, 554B, 555, 556, 559A, 559B, 560, 561, 562, 563, 570, 571, 571B, 571C, 572, 572, 573, 574
n90  nXX
n91  nXX
This field need right solution
*/
BEGIN_IMPLEMENT_SEQUENCE(FIELD72, "SWIFT FIELD 72")
  STATIC(OS_MANTADORY,":72:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"/")
      TEXT(OS_MANTADORY, hField72_CodeWord, VARLETTERDIGIT8)
      BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
        STATIC(OS_MANTADORY,"/")
        MULTITEXT(OS_OPTIONAL, hField72_AdditionalInformation, 1, 6, NARRATIVE_TEXT35 , "\r\n", SOForEOT)
      END_SEQUENCE
    END_SEQUENCE
    MULTITEXT(OS_MANTADORY, hField72_AdditionalInformation, 1, 6, NARRATIVE_TEXT35 , EOL, SOForEOT)
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD72)

//////////////////////////////////////////////////////////////////
// FIELD72B - Reason/Status Narrative
/*
Definition:

Additional Information regarding the reason for request for cancellation, request for amendment, request for status or advice of status.

Message Types:

502, 513, 514, 515, 518
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD72B, "SWIFT FIELD 72B")
  STATIC(OS_MANTADORY,":72B:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"/")
      TEXT(OS_MANTADORY, hField72a_CodeWord, VARLETTERDIGIT8)
      STATIC(OS_MANTADORY,"/")
      MULTITEXT(OS_OPTIONAL, hField72a_AdditionalInformation, 1, 6, NARRATIVE_TEXT35 , "\r\n", SOForEOT)
    END_SEQUENCE
    MULTITEXT(OS_MANTADORY, hField72a_AdditionalInformation, 1, 6, NARRATIVE_TEXT35 , EOL, SOForEOT)
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD72B)

//////////////////////////////////////////////////////////////////
// FIELD72C - Reason/Status Narrative
/*
Definition:

Additional Information regarding the reason for request for cancellation, request for amendment, request for status or advice of status.

Message Types:

514, 576
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD72C, "SWIFT FIELD 72C")
  STATIC(OS_MANTADORY,":72C:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"/")
      TEXT(OS_MANTADORY, hField72a_CodeWord, VARLETTERDIGIT8)
      STATIC(OS_MANTADORY,"/")
      MULTITEXT(OS_OPTIONAL, hField72a_AdditionalInformation, 1, 6, NARRATIVE_TEXT35 , "\r\n", SOForEOT)
    END_SEQUENCE
    MULTITEXT(OS_MANTADORY, hField72a_AdditionalInformation, 1, 6, NARRATIVE_TEXT35 , EOL, SOForEOT)
  END_PARALLEL
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD72C)

//////////////////////////////////////////////////////////////////
// FIELD72S - Reason/Status Narrative
/*
Definition:

Additional Information regarding the reason for request for cancellation, request for amendment, request for status or advice of status.

Message Types:

515
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD72S, "SWIFT FIELD 72S")
  STATIC(OS_MANTADORY,":72S:")
  MULTITEXT(OS_MANTADORY, hField72a_AdditionalInformation, 1, 6, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD72S)

//////////////////////////////////////////////////////////////////
// FIELD73 - Details of Amounts Added 
/*
Definition:

The explanation of amounts added to the amount of principal.

Message Types:

557
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD73, "SWIFT FIELD 73")
  STATIC(OS_MANTADORY,":73:")
  
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)    
      BEGIN_LOOP(OS_MANTADORY,"amount_added\0\0cdw73_c IS NOT NULL", 1, 6)
        STATIC(OS_MANTADORY,"/")
        TEXT(OS_MANTADORY, hField73_CodeWord, VARLETTER8)
        STATIC(OS_MANTADORY,"/")
        BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
          TEXT(OS_MANTADORY, hField73_CurrencyCode, CURRENCY_ISO)
          NUMBER(OS_MANTADORY, hField73_Amount, NUMBER13)
        END_SEQUENCE
        MULTITEXT(OS_OPTIONAL, hField73_AdditionalInformation, 1, 6, ADDITIONAL_TEXT33, "\r\n//", EOAI)
        STATIC(OS_MANTADORY,EOL)
      END_LOOP
      BEGIN_LOOP(OS_OPTIONAL,"amount_added\0\0cdw73_c IS NULL", 1, 1)
        MULTITEXT(OS_MANTADORY, hField73_AdditionalInformation, 1, 5, NARRATIVE_TEXT35, EOL, SOForEOT)
        STATIC(OS_MANTADORY,EOL)
      END_LOOP
    END_SEQUENCE
    BEGIN_LOOP(OS_MANTADORY,"amount_added\0\0cdw73_c IS NULL", 1, 1)
      MULTITEXT(OS_MANTADORY, hField73_AdditionalInformation, 1, 6, NARRATIVE_TEXT35, EOL, SOForEOT)
      STATIC(OS_MANTADORY,EOL)
    END_LOOP
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD73)

//////////////////////////////////////////////////////////////////
// FIELD75 - Queries
/*
Definition:

The specification of questions about a transaction.

Message Types:

539, 556, 559,
n95
*/

BEGIN_IMPLEMENT_SEQUENCE(MTn9X_FIELD75, "SWIFT FIELD 75")
  STATIC(OS_MANTADORY,":75:")

  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      BEGIN_LOOP(OS_MANTADORY,"queries\0\0query_cdw75c IS NOT NULL", 1, 6)
        STATIC(OS_MANTADORY,"/")
        INTEGER(IS_NULLPATCH, hField75_QueryNumber, "%*2[0-9]%n\0", "%lu")
        STATIC(OS_MANTADORY,"/")
        MULTITEXT(OS_OPTIONAL, hField75_AdditionalInformation, 1, 6,  ADDITIONAL_TEXT33 , "\r\n//", EOAI)
        STATIC(OS_MANTADORY,EOL)
      END_LOOP
      BEGIN_LOOP(OS_OPTIONAL,"queries\0\0query_cdw75c IS NULL", 1, 1)
        MULTITEXT(OS_MANTADORY, hField75_AdditionalInformation, 1, 5, NARRATIVE_TEXT35, EOL, SOForEOT)
        STATIC(OS_MANTADORY,EOL)
      END_LOOP
    END_SEQUENCE

    BEGIN_LOOP(OS_MANTADORY,"queries\0\0query_cdw75c IS NULL", 1, 1)
      MULTITEXT(OS_MANTADORY, hField75_AdditionalInformation, 1, 6, NARRATIVE_TEXT35, EOL, SOForEOT)
      STATIC(OS_MANTADORY,EOL)
    END_LOOP
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(MTn9X_FIELD75)

BEGIN_IMPLEMENT_SEQUENCE(MT55X_FIELD75, "SWIFT FIELD 75")
  STATIC(OS_MANTADORY,":75:")
  MULTITEXT(OS_MANTADORY, hField75_AdditionalInformation, 1, 6, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(MT55X_FIELD75)

//////////////////////////////////////////////////////////////////
// FIELD76 - Answers
/*
Definition:

The specification of responses to questions about a previous transaction.

Message Types:

n96
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD76_n96, "SWIFT FIELD 76")
  STATIC(OS_MANTADORY,":76:")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      BEGIN_LOOP(OS_MANTADORY,"answers\0\0answ_cdw76c IS NOT NULL", 1, 6)
        STATIC(OS_MANTADORY,"/")
        INTEGER(IS_NULLPATCH, hField76_AnswerNumber, "%*2[0-9]%n\0", "%lu")
        STATIC(OS_MANTADORY,"/")
        MULTITEXT(OS_OPTIONAL, hField76_AdditionalInformation, 1, 6, ADDITIONAL_TEXT33 , "\r\n//",  EOAI)
        STATIC(OS_MANTADORY,EOL)
      END_LOOP
      BEGIN_LOOP(OS_OPTIONAL,"answers\0\0answ_cdw76c IS NULL", 1, 1)
        MULTITEXT(OS_MANTADORY, hField76_AdditionalInformation, 1, 5, NARRATIVE_TEXT35, EOL, SOForEOT)
        STATIC(OS_MANTADORY,EOL)
      END_LOOP
    END_SEQUENCE
    BEGIN_LOOP(OS_MANTADORY,"answers\0\0answ_cdw76c IS NULL", 1, 1)
      MULTITEXT(OS_MANTADORY, hField76_AdditionalInformation, 1, 6, NARRATIVE_TEXT35, EOL, SOForEOT)
      STATIC(OS_MANTADORY,EOL)
    END_LOOP
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD76_n96)

//////////////////////////////////////////////////////////////////
// FIELD77A - Narrative
/*
Definition:

This field may contain any kind of instraction or information.

Message Types:

n95, n96
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD77A, "SWIFT FIELD 77A")
  STATIC(OS_MANTADORY,":77A:")
  MULTITEXT(OS_MANTADORY, hField77A_Narrative, 1, 20, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD77A)

//////////////////////////////////////////////////////////////////
// FIELD77B - Narrative
/*
Definition:

This field may contain any kind of instraction or information.

Message Types:

552, 563, 580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD77B, "SWIFT FIELD 77B")
  STATIC(OS_MANTADORY,":77B:")
  MULTITEXT(OS_MANTADORY, hField77B_Narrative, 1, 3, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD77B)

//////////////////////////////////////////////////////////////////
// FIELD77D - Narrative
/*
Definition:

This field may contain any kind of instraction or information.

Message Types:

502, 516, 520, 521, 522, 523, 530, 531, 532, 533, 553, 563, 580, 583
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD77D, "SWIFT FIELD 77D")
  STATIC(OS_MANTADORY,":77D:")
  MULTITEXT(OS_MANTADORY, hField77D_Narrative, 1, 6, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD77D)

//////////////////////////////////////////////////////////////////
// FIELD77E - Narrative
/*
Definition:

This field may contain any kind of instraction or information.

Message Types:

n98
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD77E, "SWIFT FIELD 77E")
  STATIC(OS_MANTADORY,":77E:")
  MULTITEXT(OS_MANTADORY, hField77E_Narrative, 1, 1000, NARRATIVE_TEXT78, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD77E)

//////////////////////////////////////////////////////////////////
// FIELD77N - Narrative
/*
Definition:

This field may contain any kind of instraction or information.

Message Types:

513, 514, 515, 518
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD77N, "SWIFT FIELD 77N")
  STATIC(OS_MANTADORY,":77N:")
  MULTITEXT(OS_MANTADORY, hField77N_Narrative, 1, 3, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD77N)

//////////////////////////////////////////////////////////////////
// FIELD77R - Narrative
/*
Definition:

This field may contain any kind of instraction or information.

Message Types:

520, 521, 522, 523, 530, 531, 532, 533, 550, 552, 553, 563
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD77R, "SWIFT FIELD 77R")
  STATIC(OS_MANTADORY,":77R:")
  MULTITEXT(OS_MANTADORY, hField77R_Narrative, 1, 10, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD77R)

//////////////////////////////////////////////////////////////////
// FIELD79 - Narrative
/*
Definition:

This field may contain any kind of instuction or information.

Message Types:

n92, n95, n96, n99
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD79, "SWIFT FIELD 79")
  STATIC(OS_MANTADORY,":79:")
  MULTITEXT(OS_MANTADORY, hField79_Narrative, 1, 35, NARRATIVE_TEXT50, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD79)

//////////////////////////////////////////////////////////////////
// FIELD80A - Narrative
/*
Definition:

This field may contain any kind of instruction or information.

Message Types:

560, 561
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD80A, "SWIFT FIELD 80A")
  STATIC(OS_MANTADORY,":80A:")
  MULTITEXT(OS_MANTADORY, hField80A_Narrative, 1, 4, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD80A)

//////////////////////////////////////////////////////////////////
// FIELD80B - Narrative
/*
Definition:

This field may contain any kind of instruction or information.

Message Types:

561
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD80B, "SWIFT FIELD 80B")
  STATIC(OS_MANTADORY,":80B:")
  MULTITEXT(OS_MANTADORY, hField80B_Narrative, 1, 4, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD80B)

//////////////////////////////////////////////////////////////////
// FIELD80C - Narrative
/*
Definition:

This field may contain any kind of instruction or information.

Message Types:

554, 555, 556, 557, 559, 581
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD80C, "SWIFT FIELD 80C")
  STATIC(OS_MANTADORY,":80C:")
  MULTITEXT(OS_MANTADORY, hField80C_Narrative, 1, 6, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD80C)

//////////////////////////////////////////////////////////////
// FIELD83R - Safekeeping Account
/*
Definition:

The specification of the safekeeping account from which the trade related commodity has been withdrawn or to which the commodity has been delivered.

Message Types:

502, 513, 515, 518, 580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD83R, "SWIFT FIELD 83R")
  STATIC(OS_MANTADORY,":83R:")
  TEXT(OS_MANTADORY, hField83R_CodeWord, LETTER4)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD83R)

//////////////////////////////////////////////////////////////
// FIELDXXA

BEGIN_IMPLEMENT_SEQUENCE(FIELDXXA, "SWIFT  FIELD OPTION A") 
  STATIC(OS_MANTADORY, "A:") 
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL) 
    STATIC(OS_MANTADORY,"/")
    BEGIN_PARALLEL(OS_MANTADORY, NULL)
      BEGIN_SEQUENCE(OS_MANTADORY,NULL) 
        TEXT(OS_MANTADORY, hFieldXXa_CreditedOrDebitedAccount, "%*1[CD]%n\0") 
        BEGIN_SEQUENCE(OS_OPTIONAL, NULL)
          STATIC(OS_MANTADORY,"/") 
          TEXT(OS_MANTADORY, hFieldXXa_AccountNumber, ACCOUNT_NUMBER)
        END_SEQUENCE
      END_SEQUENCE
      TEXT(OS_MANTADORY, hFieldXXa_AccountNumber, ACCOUNT_NUMBER) 
    END_PARALLEL
    STATIC(OS_MANTADORY,EOL) 
  END_SEQUENCE
  //TEXT(OS_MANTADORY, hFieldXXa_BankIdentifierCode, BIC) 
  BICADDRESS(OS_MANTADORY, hFieldXXa_BankIdentifierCode) // ß
  STATIC(OS_MANTADORY,EOL) 
END_IMPLEMENT_SEQUENCE(FIELDXXA) 

//////////////////////////////////////////////////////////////
// FIELDXXB

BEGIN_IMPLEMENT_SEQUENCE(FIELDXXB, "SWIFT FIELD OPTION B") 
  STATIC(OS_MANTADORY,"B:") 
  BEGIN_PARALLEL(OS_MANTADORY,NULL) 
    BEGIN_SEQUENCE(OS_MANTADORY,NULL) 
      STATIC(OS_MANTADORY,"/")
      BEGIN_PARALLEL(OS_MANTADORY, NULL) 
        BEGIN_SEQUENCE(OS_MANTADORY,NULL) 
          TEXT(OS_MANTADORY, hFieldXXa_CreditedOrDebitedAccount, "%*1[CD]%n\0") 
          BEGIN_SEQUENCE(OS_OPTIONAL, NULL)
            STATIC(OS_MANTADORY,"/") 
            TEXT(OS_MANTADORY, hFieldXXa_AccountNumber, ACCOUNT_NUMBER) 
          END_SEQUENCE
        END_SEQUENCE 
        TEXT(OS_MANTADORY, hFieldXXa_AccountNumber, ACCOUNT_NUMBER) 
      END_PARALLEL
      STATIC(OS_MANTADORY,EOL) 
      BEGIN_SEQUENCE(OS_OPTIONAL,NULL) 
        TEXT(OS_MANTADORY, hFieldXXa_BranchIdentificationOrNameAndAddress, NARRATIVE_LINE35) 
        STATIC(OS_MANTADORY,EOL) 
      END_SEQUENCE 
    END_SEQUENCE 
    BEGIN_SEQUENCE(OS_MANTADORY,NULL) 
      TEXT(OS_MANTADORY, hFieldXXa_BranchIdentificationOrNameAndAddress, NARRATIVE_LINE35) 
      STATIC(OS_MANTADORY,EOL) 
    END_SEQUENCE 
  END_PARALLEL 
END_IMPLEMENT_SEQUENCE(FIELDXXB) 

//////////////////////////////////////////////////////////////
// FIELDXXC

BEGIN_IMPLEMENT_SEQUENCE(FIELDXXC, "SWIFT FIELD OPTION C") 
  STATIC(OS_MANTADORY,"C:/") 
  TEXT(OS_MANTADORY, hFieldXXa_AccountNumber, ACCOUNT_NUMBER) 
  STATIC(OS_MANTADORY,EOL) 
END_IMPLEMENT_SEQUENCE(FIELDXXC) 

//////////////////////////////////////////////////////////////
// FIELDXXD

BEGIN_IMPLEMENT_SEQUENCE(FIELDXXD, "SWIFT FIELD OPTION D") 
  STATIC(OS_MANTADORY,"D:") 
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL) 
    STATIC(OS_MANTADORY,"/")
    BEGIN_PARALLEL(OS_MANTADORY, NULL)
      BEGIN_SEQUENCE(OS_MANTADORY,NULL) 
        TEXT(OS_MANTADORY, hFieldXXa_CreditedOrDebitedAccount, "%*1[CD]%n\0") 
        BEGIN_SEQUENCE(OS_OPTIONAL, NULL)
          STATIC(OS_MANTADORY,"/") 
          TEXT(OS_MANTADORY, hFieldXXa_AccountNumber, ACCOUNT_NUMBER)
        END_SEQUENCE
      END_SEQUENCE
      TEXT(OS_MANTADORY, hFieldXXa_AccountNumber, ACCOUNT_NUMBER) 
    END_PARALLEL
    STATIC(OS_MANTADORY,EOL) 
  END_SEQUENCE
  MULTITEXT(OS_MANTADORY, hFieldXXa_BranchIdentificationOrNameAndAddress, 1, 4, NARRATIVE_LINE35, EOL, SOForEOT) 
  STATIC(OS_MANTADORY,EOL) 
END_IMPLEMENT_SEQUENCE(FIELDXXD) 

//////////////////////////////////////////////////////////////
// FIELDXXE

BEGIN_IMPLEMENT_SEQUENCE(FIELDXXE, "SWIFT FIELD OPTION E") 
  STATIC(OS_MANTADORY,"E:") 
  TEXT(OS_MANTADORY, hFieldXXa_CodeWord, "FREE%n\0APMT%n\0") 
  STATIC(OS_MANTADORY,EOL) 
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL) 
    STATIC(OS_MANTADORY,"/")
    BEGIN_PARALLEL(OS_MANTADORY, NULL)
      BEGIN_SEQUENCE(OS_MANTADORY,NULL) 
        TEXT(OS_MANTADORY, hFieldXXa_CreditedOrDebitedAccount, "%*1[CD]%n\0") 
        BEGIN_SEQUENCE(OS_OPTIONAL, NULL)
          STATIC(OS_MANTADORY,"/") 
          TEXT(OS_MANTADORY, hFieldXXa_AccountNumber, ACCOUNT_NUMBER)
        END_SEQUENCE
      END_SEQUENCE
      TEXT(OS_MANTADORY, hFieldXXa_AccountNumber, ACCOUNT_NUMBER) 
    END_PARALLEL
    STATIC(OS_MANTADORY,EOL) 
  END_SEQUENCE
  //TEXT(OS_MANTADORY, hFieldXXa_BankIdentifierCode, BIC) 
  BICADDRESS(OS_MANTADORY, hFieldXXa_BankIdentifierCode) //ß
  STATIC(OS_MANTADORY,EOL) 
END_IMPLEMENT_SEQUENCE(FIELDXXE) 

//////////////////////////////////////////////////////////////
// FIELDXXF

BEGIN_IMPLEMENT_SEQUENCE(FIELDXXF, "SWIFT FIELD OPTION F") 
  STATIC(OS_MANTADORY,"F:") 
  TEXT(OS_MANTADORY, hFieldXXa_CodeWord, "FREE%n\0APMT%n\0") 
  STATIC(OS_MANTADORY,EOL) 
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL) 
    STATIC(OS_MANTADORY,"/")
    BEGIN_PARALLEL(OS_MANTADORY, NULL)
      BEGIN_SEQUENCE(OS_MANTADORY,NULL) 
        TEXT(OS_MANTADORY, hFieldXXa_CreditedOrDebitedAccount, "%*1[CD]%n\0") 
        BEGIN_SEQUENCE(OS_OPTIONAL, NULL)
          STATIC(OS_MANTADORY,"/") 
          TEXT(OS_MANTADORY, hFieldXXa_AccountNumber, ACCOUNT_NUMBER)
        END_SEQUENCE
      END_SEQUENCE
      TEXT(OS_MANTADORY, hFieldXXa_AccountNumber, ACCOUNT_NUMBER) 
    END_PARALLEL
    STATIC(OS_MANTADORY,EOL) 
  END_SEQUENCE
  MULTITEXT(OS_OPTIONAL , hFieldXXa_BranchIdentificationOrNameAndAddress, 1, 4, NARRATIVE_TEXT35, EOL, SOForEOT)
  STATIC(OS_MANTADORY,EOL) 
END_IMPLEMENT_SEQUENCE(FIELDXXF) 

//////////////////////////////////////////////////////////////
// FIELDXXI

BEGIN_IMPLEMENT_SEQUENCE(FIELDXXI, "SWIFT FIELD OPTION I") 
  STATIC(OS_MANTADORY,"I:") 
  //TEXT(OS_MANTADORY, hFieldXXa_BankIdentifierCode, BIC) 
  BICADDRESS(OS_MANTADORY, hFieldXXa_BankIdentifierCode) // ß
  STATIC(OS_MANTADORY,EOL) 
END_IMPLEMENT_SEQUENCE(FIELDXXI) 

//////////////////////////////////////////////////////////////////
// FIELD53A

BEGIN_IMPLEMENT_SEQUENCE(FIELD53A, "SWIFT FIELD 53A") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='53A'\0", 1, 1)
    STATIC(OS_MANTADORY,":53")
    CUSTOM1(FIELDXXA,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD53A)
 
//////////////////////////////////////////////////////////////////
// FIELD57A

BEGIN_IMPLEMENT_SEQUENCE(FIELD57A, "SWIFT FIELD 57A") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='57A'\0", 1, 1)
    STATIC(OS_MANTADORY,":57")
    CUSTOM1(FIELDXXA,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD57A)
 
//////////////////////////////////////////////////////////////////
// FIELD58A

BEGIN_IMPLEMENT_SEQUENCE(FIELD58A, "SWIFT FIELD 58A") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='58A'\0", 1, 1)
    STATIC(OS_MANTADORY,":58")
    CUSTOM1(FIELDXXA,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD58A)
 
//////////////////////////////////////////////////////////////////
// FIELD82A

BEGIN_IMPLEMENT_SEQUENCE(FIELD82A, "SWIFT FIELD 82A") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='82A'\0", 1, 1)
    STATIC(OS_MANTADORY,":82")
    CUSTOM1(FIELDXXA,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD82A)
 
//////////////////////////////////////////////////////////////////
// FIELD83A

BEGIN_IMPLEMENT_SEQUENCE(FIELD83A, "SWIFT FIELD 83A") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='83A'\0", 1, 1)
    STATIC(OS_MANTADORY,":83")
    CUSTOM1(FIELDXXA,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD83A)
 
//////////////////////////////////////////////////////////////////
// FIELD84A
/*
Message Types:

580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD84A, "SWIFT FIELD 84A") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='84A'\0", 1, 1)
    STATIC(OS_MANTADORY,":84")
    CUSTOM1(FIELDXXA,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD84A)
 
//////////////////////////////////////////////////////////////////
// FIELD85A

BEGIN_IMPLEMENT_SEQUENCE(FIELD85A, "SWIFT FIELD 85A") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='85A'\0", 1, 1)
    STATIC(OS_MANTADORY,":85")
    CUSTOM1(FIELDXXA,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD85A)
 
//////////////////////////////////////////////////////////////////
// FIELD87A

BEGIN_IMPLEMENT_SEQUENCE(FIELD87A, "SWIFT FIELD 87A") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='87A'\0", 1, 1)
    STATIC(OS_MANTADORY,":87")
    CUSTOM1(FIELDXXA,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD87A)

//////////////////////////////////////////////////////////////////
// FIELD88A

BEGIN_IMPLEMENT_SEQUENCE(FIELD88A, "SWIFT FIELD 88A") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='88A'\0", 1, 1)
    STATIC(OS_MANTADORY,":88")
    CUSTOM1(FIELDXXA,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD88A)
 
//////////////////////////////////////////////////////////////////
// FIELD57B

BEGIN_IMPLEMENT_SEQUENCE(FIELD57B, "SWIFT FIELD 57B") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='57B'\0", 1, 1)
    STATIC(OS_MANTADORY,":57")
    CUSTOM1(FIELDXXB,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD57B)

//////////////////////////////////////////////////////////////////
// FIELD53C

BEGIN_IMPLEMENT_SEQUENCE(FIELD53C, "SWIFT FIELD 53C") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='53C'\0", 1, 1)
    STATIC(OS_MANTADORY,":53")
    CUSTOM1(FIELDXXC,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD53C)

//////////////////////////////////////////////////////////////////
// FIELD82C

BEGIN_IMPLEMENT_SEQUENCE(FIELD82C, "SWIFT FIELD 82C") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='82C'\0", 1, 1)
    STATIC(OS_MANTADORY,":82")
    CUSTOM1(FIELDXXC,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD82C)

//////////////////////////////////////////////////////////////////
// FIELD83C

BEGIN_IMPLEMENT_SEQUENCE(FIELD83C, "SWIFT FIELD 83C") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='83C'\0",1,1)
    STATIC(OS_MANTADORY,":83")
    CUSTOM1(FIELDXXC,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD83C)

//////////////////////////////////////////////////////////////////
// FIELD85C

BEGIN_IMPLEMENT_SEQUENCE(FIELD85C, "SWIFT FIELD 85C") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='85C'\0", 1, 1)
    STATIC(OS_MANTADORY,":85")
    CUSTOM1(FIELDXXC,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD85C)

//////////////////////////////////////////////////////////////////
// FIELD87C

BEGIN_IMPLEMENT_SEQUENCE(FIELD87C, "SWIFT FIELD 87C") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='87C'\0", 1, 1)
    STATIC(OS_MANTADORY,":87")
    CUSTOM1(FIELDXXC,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD87C)

//////////////////////////////////////////////////////////////////
// FIELD88C

BEGIN_IMPLEMENT_SEQUENCE(FIELD88C, "SWIFT FIELD 88C") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='88C'\0", 1, 1)
    STATIC(OS_MANTADORY,":88")
    CUSTOM1(FIELDXXC,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD88C)

//////////////////////////////////////////////////////////////////
// FIELD53D

BEGIN_IMPLEMENT_SEQUENCE(FIELD53D, "SWIFT FIELD 53D") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='53D'\0", 1, 1)
    STATIC(OS_MANTADORY,":53")
    CUSTOM1(FIELDXXD,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD53D)

//////////////////////////////////////////////////////////////////
// FIELD57D

BEGIN_IMPLEMENT_SEQUENCE(FIELD57D, "SWIFT FIELD 57D") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='57D'\0", 1, 1)
    STATIC(OS_MANTADORY,":57")
    CUSTOM1(FIELDXXD,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD57D)

//////////////////////////////////////////////////////////////////
// FIELD58D

BEGIN_IMPLEMENT_SEQUENCE(FIELD58D, "SWIFT FIELD 58D") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='58D'\0", 1, 1)
    STATIC(OS_MANTADORY,":58")
    CUSTOM1(FIELDXXD,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD58D)

//////////////////////////////////////////////////////////////////
// FIELD82D

BEGIN_IMPLEMENT_SEQUENCE(FIELD82D, "SWIFT FIELD 82D") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='82D'\0", 1, 1)
    STATIC(OS_MANTADORY,":82")
    CUSTOM1(FIELDXXD,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD82D)

//////////////////////////////////////////////////////////////////
// FIELD83D

BEGIN_IMPLEMENT_SEQUENCE(FIELD83D, "SWIFT FIELD 82D") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='83D'\0", 1, 1)
    STATIC(OS_MANTADORY,":83")
    CUSTOM1(FIELDXXD,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD83D)

//////////////////////////////////////////////////////////////////
// FIELD85D

BEGIN_IMPLEMENT_SEQUENCE(FIELD85D, "SWIFT FIELD 85D") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='85D'\0", 1, 1)
    STATIC(OS_MANTADORY,":85")
    CUSTOM1(FIELDXXD,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD85D)

//////////////////////////////////////////////////////////////////
// FIELD87D

BEGIN_IMPLEMENT_SEQUENCE(FIELD87D, "SWIFT FIELD 87D") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='87D'\0", 1, 1)
    STATIC(OS_MANTADORY,":87")
    CUSTOM1(FIELDXXD,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD87D)

//////////////////////////////////////////////////////////////////
// FIELD88D

BEGIN_IMPLEMENT_SEQUENCE(FIELD88D, "SWIFT FIELD 88D") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='88D'\0", 1, 1)
    STATIC(OS_MANTADORY,":88")
    CUSTOM1(FIELDXXD,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD88D)

//////////////////////////////////////////////////////////////////
// FIELD87E

BEGIN_IMPLEMENT_SEQUENCE(FIELD87E, "SWIFT FIELD 87E") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='87E'\0", 1, 1)
    STATIC(OS_MANTADORY,":87")
    CUSTOM1(FIELDXXE,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD87E)

//////////////////////////////////////////////////////////////////
// FIELD87F

BEGIN_IMPLEMENT_SEQUENCE(FIELD87F, "SWIFT FIELD 87F") 
  BEGIN_LOOP(OS_MANTADORY,"accounts\0fld_tag_c='87F'\0", 1, 1)
    STATIC(OS_MANTADORY,":87")
    CUSTOM1(FIELDXXF,OS_MANTADORY,NULL)
  END_LOOP
END_IMPLEMENT_SEQUENCE(FIELD87F)

/////////////////////////////////////////////////////////////////
// Useful fields combinations
 
BEGIN_IMPLEMENT_PARALLEL(FIELDXXAD, "SWIFT FIELD OPTION A or D")
  CUSTOM1(FIELDXXA, OS_MANTADORY, NULL)
  CUSTOM1(FIELDXXD, OS_MANTADORY, NULL)
END_IMPLEMENT_PARALLEL(FIELDXXAD)

BEGIN_IMPLEMENT_PARALLEL(FIELDXXABD, "SWIFT FIELD OPTION A,B or D")
  CUSTOM1(FIELDXXA, OS_MANTADORY, NULL)
  CUSTOM1(FIELDXXB, OS_MANTADORY, NULL)
  CUSTOM1(FIELDXXD, OS_MANTADORY, NULL)
END_IMPLEMENT_PARALLEL(FIELDXXABD)

BEGIN_IMPLEMENT_PARALLEL(FIELDXXACD, "SWIFT FIELD OPTION A,C or D")
  CUSTOM1(FIELDXXA, OS_MANTADORY, NULL)
  CUSTOM1(FIELDXXD, OS_MANTADORY, NULL)
  CUSTOM1(FIELDXXC, OS_MANTADORY, NULL)
END_IMPLEMENT_PARALLEL(FIELDXXACD)

BEGIN_IMPLEMENT_PARALLEL(FIELDXXACDEF, "SWIFT FIELD OPTION A,C,D,E or F")
  CUSTOM1(FIELDXXE, OS_MANTADORY, NULL)
  CUSTOM1(FIELDXXF, OS_MANTADORY, NULL)
  CUSTOM1(FIELDXXA, OS_MANTADORY, NULL)
  CUSTOM1(FIELDXXD, OS_MANTADORY, NULL)
  CUSTOM1(FIELDXXC, OS_MANTADORY, NULL)
END_IMPLEMENT_PARALLEL(FIELDXXACDEF)

BEGIN_IMPLEMENT_PARALLEL(FIELDXXEF, "SWIFT FIELD OPTION E or F")
  CUSTOM1(FIELDXXE, OS_MANTADORY, NULL)
  CUSTOM1(FIELDXXF, OS_MANTADORY, NULL)
END_IMPLEMENT_PARALLEL(FIELDXXEF)

//////////////////////////////////////////////////////////////////
// FIELD11RS
// Reference:
// 562  
// 563 
// n95
// n96

BEGIN_IMPLEMENT_SEQUENCE(FIELD11RS, "SWIFT FIELD 11a(R or S)")
  STATIC(OS_MANTADORY,":11")
  TEXT(OS_MANTADORY, hField11a_ReceivedOrSent, "%*1[RS]%n\0")
  STATIC(OS_MANTADORY,":")
  TEXT(OS_MANTADORY, hField11a_MessageType,  MESSAGE_TYPE)
  STATIC(OS_MANTADORY,EOL)
  DATETIME(OS_MANTADORY, hField11a_Date, YYMMDD)
  STATIC(OS_MANTADORY,EOL)
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    INTEGER(OS_MANTADORY, hField11a_SessionNumber, SESSION_NUMBER, "%04lu")
    INTEGER(OS_MANTADORY, hField11a_SequenceNumber, SEQUENCE_NUMBER, "%06lu")
    STATIC(OS_MANTADORY,EOL)
  END_SEQUENCE
END_IMPLEMENT_SEQUENCE(FIELD11RS)

//////////////////////////////////////////////////////////////////
// FIELD34GH
/*
Definition:

The currency code and an amount in the transaction, which may also contain other information concerning the amount, such as date(s) and/or amount qualifiers.

Message Types:

510, 512, 513, 514, 515, 518, 521, 523, 531, 533, 563, 571, 572, 580
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD34GH, "SWIFT FIELD 34a(G or H)")
  STATIC(OS_MANTADORY,":34")
  RULE(OS_MANTADORY, hField34GH_AddedOrDeducted, "G\0H\0", "C\0D\0")
  STATIC(OS_MANTADORY, ":")
  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    INTEGER(OS_MANTADORY|IS_NULLPATCH, hField34GH_NumberOfDays, DIGIT3, "%03lu")
    STATIC(OS_MANTADORY,EOL)
  END_SEQUENCE
  TEXT(OS_MANTADORY, hField34GH_CurrencyCode, LETTER3)
  NUMBER(OS_MANTADORY, hField34GH_Amount, NUMBER15)
  STATIC(OS_MANTADORY,EOL)
END_IMPLEMENT_SEQUENCE(FIELD34GH)

//////////////////////////////////////////////////////////////////
// FIELD35CD
// Reference:
// n90  ORD
// n91  ORD

BEGIN_IMPLEMENT_PARALLEL(FIELD35CD, "SWIFT FIELD 35a(C or D)")
    CUSTOM1(FIELD35C,OS_MANTADORY,NULL)
    CUSTOM1(FIELD35D,OS_MANTADORY,NULL)
END_IMPLEMENT_PARALLEL(FIELD35CD)

//////////////////////////////////////////////////////////////////
// FIELD52AD
// Reference:
// n90  ORD
// n91  ORD

BEGIN_IMPLEMENT_SEQUENCE(FIELD52AD_ORD, "SWIFT FIELD 52a(A or D)")
  STATIC(OS_MANTADORY,":52")
  CUSTOM1(FIELDXXAD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD52AD_ORD)

//////////////////////////////////////////////////////////////////
// FIELD53ABD
// Reference:
// 202  SCOR

BEGIN_IMPLEMENT_SEQUENCE(FIELD53ABD_SCOR, "SWIFT FIELD 53a(A,B or D)") 
  STATIC(OS_MANTADORY,":53")
  CUSTOM1(FIELDXXABD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD53ABD_SCOR)

//////////////////////////////////////////////////////////////////
// FIELD53ACD
// Reference:
// 521
// 523
// 531
// 553
// 554
// 555
// 556
// 557 PAY
// 559
// 563

BEGIN_IMPLEMENT_SEQUENCE(FIELD53ACD, "SWIFT FIELD 53a(A,C or D)") 
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    CUSTOM1(FIELD53A,OS_MANTADORY,NULL)
    CUSTOM1(FIELD53C,OS_MANTADORY,NULL)
    CUSTOM1(FIELD53D,OS_MANTADORY,NULL)
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD53ACD)

BEGIN_IMPLEMENT_SEQUENCE(FIELD53ACD_PAY, "SWIFT FIELD 53a(A,C or D)") 
  STATIC(OS_MANTADORY,":53")
  CUSTOM1(FIELDXXACD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD53ACD_PAY)

//////////////////////////////////////////////////////////////////
// FIELD54ABD
// Reference:
// 202  RCOR

BEGIN_IMPLEMENT_SEQUENCE(FIELD54ABD_RCOR, "SWIFT FIELD 54a(A,C or D)") 
  STATIC(OS_MANTADORY,":54")
  CUSTOM1(FIELDXXABD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD54ABD_RCOR)

//////////////////////////////////////////////////////////////////
// FIELD56AD
/*
Definition:

The financial intitution, between the Receiver and the Account With Institution, through which the transaction must pass.

Message Types:

100,
202, 
582,
910
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD56AD, "SWIFT FIELD 56a(A or D)") 
  STATIC(OS_MANTADORY,":56")
  CUSTOM1(FIELDXXAD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD56AD)

//////////////////////////////////////////////////////////////////
// FIELD57AD - Account With Instituion
/*
Definition:

The financial institution at which the Ordering Party requests the Beneficiary to be paid. The Account With Institution may be a branch or affiliate of the Receiver, or the Receiver, or of the Intermediary, or of the Beneficiary Institution, or an entirely different financial institution.

Message Types:

100,
200, 201, 202. 203, 204, 205,
501, 510, 512, 514, …, 521, 523, 531, 533, 559,
n91 
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD57AD, "SWIFT FIELD 57a(A or D)") 
  STATIC(OS_MANTADORY,":57")
  CUSTOM1(FIELDXXAD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD57AD)

//////////////////////////////////////////////////////////////////
// FIELD57ABD - Account With Instituion
/*
Definition:

The financial institution at which the Ordering Party requests the Beneficiary to be paid. The Account With Institution may be a branch or affiliate of the Receiver, or the Receiver, or of the Intermediary, or of the Beneficiary Institution, or an entirely different financial institution.

Message Types:

100,
200, 201, 202. 203, 204, 205,
501, 510, 512, 514, …, 521, 523, 531, 533, 559,
n91 
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD57ABD, "SWIFT FIELD 57a(A,B or D)") 
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    CUSTOM1(FIELD57A,OS_MANTADORY,NULL)
    CUSTOM1(FIELD57B,OS_MANTADORY,NULL)
    CUSTOM1(FIELD57D,OS_MANTADORY,NULL)
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD57ABD)

BEGIN_IMPLEMENT_SEQUENCE(FIELD57ABD_IN, "SWIFT FIELD 57a(A,B or D)") 
  STATIC(OS_MANTADORY,":57")
  CUSTOM1(FIELDXXABD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD57ABD_IN)

//////////////////////////////////////////////////////////////////
// FIELD57ACD - Account With Instituion
/*
Definition:

The financial institution at which the Ordering Party requests the Beneficiary to be paid. The Account With Institution may be a branch or affiliate of the Receiver, or the Receiver, or of the Intermediary, or of the Beneficiary Institution, or an entirely different financial institution.

Message Types:

*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD57ACD, "SWIFT FIELD 57a(A,C or D)") 
  STATIC(OS_MANTADORY,":57")
  CUSTOM1(FIELDXXACD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD57ACD)

//////////////////////////////////////////////////////////////////
// FIELD58AD - Beneficiary Institution
/*
Definition:

The financial institution designated by the Ordering Institution as the  ultimate  reccipient  of the funds. The Beneficiary Institution may be a branch or affiliate of the Receiver  or of the Account With Institution, or an entirely different financial institution.

Message Types:

*/
// Reference:
// 202  BEN
// 521
// 523
// 531
// 533

BEGIN_IMPLEMENT_SEQUENCE(FIELD58AD, "SWIFT FIELD 58a(A or D)") 
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    CUSTOM1(FIELD58A,OS_MANTADORY,NULL)
    CUSTOM1(FIELD58D,OS_MANTADORY,NULL)
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD58AD)

BEGIN_IMPLEMENT_SEQUENCE(FIELD58AD_BEN, "SWIFT FIELD 58a(A or D)")
  STATIC(OS_MANTADORY,":58") 
  CUSTOM1(FIELDXXAD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD58AD_BEN)

//////////////////////////////////////////////////////////////////
// FIELD58ACD - Beneficiary Institution
/*
Definition:

The financial institution designated by the Ordering Institution as the  ultimate  reccipient  of the funds. The Beneficiary Institution may be a branch or affiliate of the Receiver  or of the Account With Institution, or an entirely different financial institution.

Message Types:

*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD58ACD, "SWIFT FIELD 58a(A,C or D)")
  STATIC(OS_MANTADORY,":58") 
  CUSTOM1(FIELDXXACD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD58ACD)

//////////////////////////////////////////////////////////////////
// FIELD81ACD - Fund or Client
/*
Definition:

Identifies the Fund or Client to which the allocation relates.

Message Types:

513, 514, 515
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD81ACD, "SWIFT FIELD 81a(A,C or D)") 
  STATIC(OS_MANTADORY,":81")
  CUSTOM1(FIELDXXACD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD81ACD)

//////////////////////////////////////////////////////////////////// 
// FIELD82AD
// Reference:
// 520
// 521
// 522
// 523
// 530
// 531
// 532
// 533

BEGIN_IMPLEMENT_SEQUENCE(FIELD82AD, "SWIFT FIELD 82a(A or D)") 
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    CUSTOM1(FIELD82A,OS_MANTADORY,NULL)
    CUSTOM1(FIELD82D,OS_MANTADORY,NULL)
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD82AD)

//////////////////////////////////////////////////////////////////// 
// FIELD82ACD
// Reference:
// 534

BEGIN_IMPLEMENT_SEQUENCE(FIELD82ACD, "SWIFT FIELD 82a(A,C or D)") 
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    CUSTOM1(FIELD82A,OS_MANTADORY,NULL)
    CUSTOM1(FIELD82C,OS_MANTADORY,NULL)
    CUSTOM1(FIELD82D,OS_MANTADORY,NULL)
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD82ACD)

//////////////////////////////////////////////////////////////////// 
// FIELD82IR - Instructing Party
/*
Definition:

The identification of the initiator of the  trade related transaction.

Message Types:

514, 515
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD82IR, "SWIFT FIELD 82a(I or R)") 
  STATIC(OS_MANTADORY,":82")
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    CUSTOM1(FIELDXXI,OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      STATIC(OS_MANTADORY,"R:")
      TEXT(OS_MANTADORY, hField82R_InstructingParty,VARTEXT35)
      STATIC(OS_MANTADORY,EOL)
    END_SEQUENCE
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD82IR)

//////////////////////////////////////////////////////////////////// 
// FIELD83ACD
// Reference:
// 520  SAFE
// 521  SAFE
// 522  SAFE
// 523  SAFE
// 530  SAFE
// 531  SAFE
// 532  SAFE
// 533  SAFE
// 534  SAFE
// 550  SAFE_R
// 551  SAFE_R
// 552  SAFE_R
// 553  SAFE_R
// 554  SAFE_R
// 555  SAFE_R
// 556  SAFE_R
// 560  SAFE
// 562  SAFE
// 563  SAFE
// 570
// 570B SAFE
// 571  SAFE_R
// 572  SAFE_R
// 572B SAFE_R
// 573  SAFE_R
// 573B SAFE_R
// 573C SAFE_R
// 574
// 574B SAFE_R

BEGIN_IMPLEMENT_SEQUENCE(FIELD83ACD, "SWIFT FIELD 83a(A,C or D)") 
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    CUSTOM1(FIELD83A,OS_MANTADORY,NULL)
    CUSTOM1(FIELD83D,OS_MANTADORY,NULL)
    CUSTOM1(FIELD83C,OS_MANTADORY,NULL)
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD83ACD)

BEGIN_IMPLEMENT_SEQUENCE(FIELD83ACD_SAFE, "SWIFT FIELD 83a(A,C or D)") 
  STATIC(OS_MANTADORY,":83")
  CUSTOM1(FIELDXXACD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD83ACD_SAFE)

//////////////////////////////////////////////////////////////////// 
// FIELD84ACD

BEGIN_IMPLEMENT_SEQUENCE(FIELD84ACD, "SWIFT FIELD 86a(A,C or D)") 
  STATIC(OS_MANTADORY,":84")
  CUSTOM1(FIELDXXACD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD84ACD)

//////////////////////////////////////////////////////////////////
// FIELD85ACD
// Reference:
// 520
// 521
// 523
// 530
// 531

BEGIN_IMPLEMENT_SEQUENCE(FIELD85ACD, "SWIFT FIELD 85a(A,C or D)") 
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    CUSTOM1(FIELD85A,OS_MANTADORY,NULL)
    CUSTOM1(FIELD85C,OS_MANTADORY,NULL)
    CUSTOM1(FIELD85D,OS_MANTADORY,NULL)
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD85ACD)

//////////////////////////////////////////////////////////////////
// FIELD86ACD

BEGIN_IMPLEMENT_SEQUENCE(FIELD86ACD, "SWIFT FIELD 86a(A,C or D)") 
  STATIC(OS_MANTADORY,":86")
  CUSTOM1(FIELDXXACD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD86ACD)

//////////////////////////////////////////////////////////////////
// FIELD86ACDEF

BEGIN_IMPLEMENT_SEQUENCE(FIELD86ACDEF, "SWIFT FIELD 86a(A,C,D,E or F)") 
  STATIC(OS_MANTADORY,":86")
  CUSTOM1(FIELDXXACDEF,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD86ACDEF)

//////////////////////////////////////////////////////////////////
// FIELD86EF

BEGIN_IMPLEMENT_SEQUENCE(FIELD86EF, "SWIFT FIELD 86a(E or F)") 
  STATIC(OS_MANTADORY,":86")
  CUSTOM1(FIELDXXEF,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD86EF)

//////////////////////////////////////////////////////////////////
// FIELD87AD
// Reference:
// 520
// 521
// 522
// 523
// 526
// 530
// 531
// 532
// 533
// 554  MULT
// 555
// 572  CNTRP
// 573  CNTRP

BEGIN_IMPLEMENT_SEQUENCE(FIELD87AD, "SWIFT FIELD 87a(A or D)") 
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    CUSTOM1(FIELD87A,OS_MANTADORY,NULL)
    CUSTOM1(FIELD87D,OS_MANTADORY,NULL)
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD87AD)

BEGIN_IMPLEMENT_SEQUENCE(FIELD87AD_CNTRP, "SWIFT FIELD 87a(A or D)") 
  STATIC(OS_MANTADORY,":87")
  CUSTOM1(FIELDXXAD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD87AD_CNTRP)

//////////////////////////////////////////////////////////////////
// FIELD87ABD
/*
Message Types:

582
*/

BEGIN_IMPLEMENT_SEQUENCE(FIELD87ABD, "SWIFT FIELD 87a(A,B or D)") 
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    CUSTOM1(FIELD87A,OS_MANTADORY,NULL)
    CUSTOM1(FIELD87C,OS_MANTADORY,NULL)
    CUSTOM1(FIELD87D,OS_MANTADORY,NULL)
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD87ABD)

//////////////////////////////////////////////////////////////////
// FIELD87ACD
// Reference:
// 534

BEGIN_IMPLEMENT_SEQUENCE(FIELD87ACD, "SWIFT FIELD 87a(A,C or D)") 
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    CUSTOM1(FIELD87A,OS_MANTADORY,NULL)
    CUSTOM1(FIELD87C,OS_MANTADORY,NULL)
    CUSTOM1(FIELD87D,OS_MANTADORY,NULL)
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD87ACD)

//////////////////////////////////////////////////////////////////
// FIELD87EF
// Reference:
// 553
// 563

BEGIN_IMPLEMENT_SEQUENCE(FIELD87EF, "SWIFT FIELD 87a(E or F)") 
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    CUSTOM1(FIELD87E,OS_MANTADORY,NULL)
    CUSTOM1(FIELD87F,OS_MANTADORY,NULL)
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD87EF)

//////////////////////////////////////////////////////////////////// 
// FIELD88ACD
// Reference:
// 520
// 521
// 522
// 523
// 530
// 531
// 532
// 533
// 553
// 563

BEGIN_IMPLEMENT_SEQUENCE(FIELD88ACD, "SWIFT FIELD 88a(A,C or D)") 
  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    CUSTOM1(FIELD88A,OS_MANTADORY,NULL)
    CUSTOM1(FIELD88C,OS_MANTADORY,NULL)
    CUSTOM1(FIELD88D,OS_MANTADORY,NULL)
  END_PARALLEL
END_IMPLEMENT_SEQUENCE(FIELD88ACD)

/////////////////////////////////////////////////////////////////////////////////////
// FIELD89ACD

BEGIN_IMPLEMENT_SEQUENCE(FIELD89ACD, "SWIFT FIELD 89a(A,C or D)") 
  STATIC(OS_MANTADORY,":89")
  CUSTOM1(FIELDXXACD,OS_MANTADORY,NULL)
END_IMPLEMENT_SEQUENCE(FIELD89ACD)

//////////////////////////////////////////////////////////////////

