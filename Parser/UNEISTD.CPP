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
// File uneistd.cpp
// Copyright © 1996 Asset Information Management
// Programmer: Dmitry Protopopov
///////////////////////////////////////////////////////////
// U M T 0 3 2

BEGIN_IMPLEMENT_SEQUENCE(UMT032_C, "UNEXIM MT032 C")
  M(UFIELD20, srvrUneiField20_SendersReference)
  O(UFIELD21, srvrUneiField21_RelatedReference)
  M(UFIELD25D, srvrUneiField25a_InstructingParty)
  M(UFIELD25C, srvrUneiField25a_Beneficiary)
  M(UFIELD32A, srvrUneiField32A_ValueDateCurrencyAmount)
  M(UFIELD70, srvrUneiField70_PaymentDetails)
  //O(UFIELD71, srvrUneiField71_ExpenseDetails)
  //O(UFIELD72, srvrUneiField72_SenderToReceiverInformation)
  STATIC(OS_MANTADORY, UEOT)
END_IMPLEMENT_SEQUENCE(UMT032_C)

BEGIN_IMPLEMENT_SEQUENCE(UMT032_D, "UNEXIM MT032 D")
  M(UFIELD20, srvrUneiField20_SendersReference)
  O(UFIELD21, srvrUneiField21_RelatedReference)
  M(UFIELD25D, srvrUneiField25a_Beneficiary)
  M(UFIELD25C, srvrUneiField25a_InstructingParty)
  M(UFIELD32A, srvrUneiField32A_ValueDateCurrencyAmount)
  M(UFIELD70, srvrUneiField70_PaymentDetails)
  //O(UFIELD71, srvrUneiField71_ExpenseDetails)
  //O(UFIELD72, srvrUneiField72_SenderToReceiverInformation)
  STATIC(OS_MANTADORY, UEOT)
END_IMPLEMENT_SEQUENCE(UMT032_D)

////////////////////////////////////////////////////
// U M T 0 4 1

BEGIN_IMPLEMENT_SEQUENCE(UMT041_C, "UNEXIM MT041 C")
  M(UFIELD20, srvrUneiField20_SendersReference)
  O(UFIELD21, srvrUneiField21_RelatedReference)
  M(UFIELD25D, srvrUneiField25a_InstructingParty)
  M(UFIELD25C, srvrUneiField25a_Beneficiary)
  M(UFIELD32A, srvrUneiField32A_ValueDateCurrencyAmount)
  //O(UFIELD32T, srvrUneiField32T_TheAmountOfTheTransmissionExpenses)
  //O(UFIELD32C, srvrUneiField32C_TheBankingCommisionAmount)
  O(UFIELD50, srvrUneiField5X_InstructingParty)
  O(UFIELD52AD, srvrUneiField52a_InstructingPartysBank)
  O(UFIELD54AD, srvrUneiField54a_ReceiversCorrespondentBank)
  O(UFIELD56AD, srvrUneiField56a_Intermediary)
  O(UFIELD57AD, srvrUneiField57a_BeneficiarysBank)
  M(UFIELD59, srvrUneiField5X_Beneficiary)
  M(UFIELD70, srvrUneiField70_PaymentDetails)
  //O(UFIELD71, srvrUneiField71_ExpenseDetails)
  //O(UFIELD72, srvrUneiField72_SenderToReceiverInformation)
  STATIC(OS_MANTADORY, UEOT)
END_IMPLEMENT_SEQUENCE(UMT041_C)

BEGIN_IMPLEMENT_SEQUENCE(UMT041_D, "UNEXIM MT041 D")
  M(UFIELD20, srvrUneiField20_SendersReference)
  O(UFIELD21, srvrUneiField21_RelatedReference)
  M(UFIELD25D, srvrUneiField25a_Beneficiary)
  M(UFIELD25C, srvrUneiField25a_InstructingParty)
  M(UFIELD32A, srvrUneiField32A_ValueDateCurrencyAmount)
  //O(UFIELD32T, srvrUneiField32T_TheAmountOfTheTransmissionExpenses)
  //O(UFIELD32C, srvrUneiField32C_TheBankingCommisionAmount)
  O(UFIELD50, srvrUneiField5X_Beneficiary)
  O(UFIELD52AD, srvrUneiField52a_InstructingPartysBank)
  O(UFIELD54AD, srvrUneiField54a_ReceiversCorrespondentBank)
  O(UFIELD56AD, srvrUneiField56a_Intermediary)
  O(UFIELD57AD, srvrUneiField57a_BeneficiarysBank)
  M(UFIELD59, srvrUneiField5X_InstructingParty)
  M(UFIELD70, srvrUneiField70_PaymentDetails)
  //O(UFIELD71, srvrUneiField71_ExpenseDetails)
  //O(UFIELD72, srvrUneiField72_SenderToReceiverInformation)
  STATIC(OS_MANTADORY, UEOT)
END_IMPLEMENT_SEQUENCE(UMT041_D)

////////////////////////////////////////////////////
// U M T 0 4 4

BEGIN_IMPLEMENT_SEQUENCE(UMT044_C, "UNEXIM MT044 C")
  M(UFIELD20, srvrUneiField20_SendersReference)
  O(UFIELD21, srvrUneiField21_RelatedReference)
  M(UFIELD25D, srvrUneiField25a_InstructingParty)
  M(UFIELD25C, srvrUneiField25a_Beneficiary)
  M(UFIELD32A, srvrUneiField32A_ValueDateCurrencyAmount)
  //O(UFIELD32T, srvrUneiField32T_TheAmountOfTheTransmissionExpenses)
  //O(UFIELD32C, srvrUneiField32C_TheBankingCommisionAmount)
  O(UFIELD50, srvrUneiField5X_InstructingParty)
  O(UFIELD52AD, srvrUneiField52a_InstructingPartysBank)
  O(UFIELD57AD, srvrUneiField57a_BeneficiarysBank)
  M(UFIELD59, srvrUneiField5X_Beneficiary)
  M(UFIELD70, srvrUneiField70_PaymentDetails)
  STATIC(OS_MANTADORY, UEOT)
END_IMPLEMENT_SEQUENCE(UMT044_C)

BEGIN_IMPLEMENT_SEQUENCE(UMT044_D, "UNEXIM MT044 D")
  M(UFIELD20, srvrUneiField20_SendersReference)
  O(UFIELD21, srvrUneiField21_RelatedReference)
  M(UFIELD25D, srvrUneiField25a_Beneficiary)
  M(UFIELD25C, srvrUneiField25a_InstructingParty)
  M(UFIELD32A, srvrUneiField32A_ValueDateCurrencyAmount)
  //O(UFIELD32T, srvrUneiField32T_TheAmountOfTheTransmissionExpenses)
  //O(UFIELD32C, srvrUneiField32C_TheBankingCommisionAmount)
  O(UFIELD50, srvrUneiField5X_Beneficiary)
  O(UFIELD52AD, srvrUneiField52a_InstructingPartysBank)
  O(UFIELD57AD, srvrUneiField57a_BeneficiarysBank)
  M(UFIELD59, srvrUneiField5X_InstructingParty)
  M(UFIELD70, srvrUneiField70_PaymentDetails)
  STATIC(OS_MANTADORY, UEOT)
END_IMPLEMENT_SEQUENCE(UMT044_D)

//////////////////////////////////////////////////////
// U M T 9 0 0

BEGIN_IMPLEMENT_SEQUENCE(UMT900, "UNEXIM MT900")
  M(UFIELD20, srvrUneiField20_CashSystemReference)
  M(UFIELD21, srvrUneiField21_CustodySystemReference)
  M(UFIELD32A, srvrUneiField32A_TransactionAmount)
  STATIC(OS_MANTADORY, UEOT)
END_IMPLEMENT_SEQUENCE(UMT900)

////////////////////////////////////////////////////
// U M T 5 9 2 U M
/*
Scope:

This is narrative text and copy of original message of received from MICEX message to cancel trade.
*/

BEGIN_IMPLEMENT_SEQUENCE(UMT592UM, "UNEXIM MT592UM")
  BEGIN_SEQUENCE(OS_MANTADORY,srvrUMT592M)
    STATIC(OS_MANTADORY, ":79:")
    TEXT(OS_MANTADORY, hUneiField_MessageType, DIGIT3)
    STATIC(OS_MANTADORY,EOL)
    DATETIME(OS_MANTADORY, hUneiField_MT570TradeDate,YYMMDD)
    STATIC(OS_MANTADORY,EOL)
    M(FIELD20,srvrUneiField20_MT572TransactionReferenceNumber)
    M(FIELD67A,srvrUneiField67A_MT572StatementPeriod)
  END_SEQUENCE
END_IMPLEMENT_SEQUENCE(UMT592UM)

////////////////////////////////////////////////////
// U M T 5 9 8 U M
/*
Scope:

This is narrative text of field 77E of received from MICEX message to unblock trade accounts.
*/

BEGIN_IMPLEMENT_SEQUENCE(UMT598UM, "UNEXIM MT598UM")
  BEGIN_SEQUENCE(OS_MANTADORY, srvrUMT598M)
    STATIC(OS_MANTADORY,":77E:")
    DATETIME(OS_MANTADORY,hUneiField_TradeDate, YYMMDD)
    STATIC(OS_MANTADORY,EOL)
    TEXT(OS_MANTADORY, hUneiField_MT570TransactionReferenceNumber, VARTEXT16)
    STATIC(OS_MANTADORY,EOL)
    TEXT(OS_MANTADORY, hUneiField_MT574TransactionReferenceNumber, VARTEXT16)
    STATIC(OS_MANTADORY,EOL)
    BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
      TEXT(OS_MANTADORY, hUneiField_MT572TransactionReferenceNumber, VARTEXT16)
      STATIC(OS_MANTADORY,EOL)
    END_SEQUENCE
  END_SEQUENCE
END_IMPLEMENT_SEQUENCE(UMT598UM)

////////////////////////////////////////////////////
//   U M T 5 7 4 - Statement of Open Orders
/*
Scope:

This message type is sent by a financial institution which has accepted one or several orders to buy and/or sell securities, to the financial institution which has issued those orders.
*/

BEGIN_IMPLEMENT_CONTAINER(UMT574, MT574, "UNEXIM MT574 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceA)
    M(FIELD28, srvrField28_PageNumberAndContinuationIndicator)
    O(FIELD20, srvrField20_TransactionReferenceNumber)
    O(FIELD21, srvrField21_RelatedReference)
    O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
    M(FIELD67A, srvrField67A_StatementPeriod)
    O(FIELD30, srvrField30_DatePrepared)
  END_SEQUENCE

  LOOP(OS_MANTADORY|LS_PUSHCOUNT, srvrMT574B,  0, 1000)
    BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceB)
      M(FIELD35B, srvrField35B_IdentificationOfSecurities)

      LOOP(OS_MANTADORY, srvrMT574B1, 1, 1000)
        BEGIN_SEQUENCE(OS_MANTADORY, srvrSequenceB1)
          O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
          M(FIELD20, srvrField20_TransactionReferenceNumber)
          O(FIELD11R, srvrField11a_MTAndDateOfOriginalOrder)
          M(FIELD21, srvrField21_RelatedReference)
          O(FIELD23_574, srvrField23_FurtherIdentification)
          M(UFIELD35A, srvrField35A_QuantityOfSecurities)
          O(FIELD31C, srvrField31C_ExpiryDate)
          O(FIELD32L, srvrField32L_PriceLimit)
          O(FIELD72, srvrField72_SenderToReceiverInformation)
        END_SEQUENCE
   END_SEQUENCE

  BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceC)
    CUSTOM0(FIELD18A,OS_MANTADORY)
    O(FIELD72, srvrField72_SenderToReceiverInformation)
  END_SEQUENCE

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_CONTAINER(UMT574, MT574)

////////////////////////////////////////////////////////////////////////////////////
