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
// File swiftstd.cpp
// Copyright © 1996, Asset Information Management
// Copyright © 1997, Asset Information Management
// Programmer: Dmitry Protopopov
////////////////////////////////////////////////////////////////////////////////////
//    M T 5 0 0

BEGIN_IMPLEMENT_SEQUENCE(MT500, "MT500 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD23, srvrField23_FurtherIdentification)
  O(FIELD30, srvrField30_ExpiryDateOfOrder)
  O(FIELD32S, srvrField32S_DateAndStrikingPrice)
  M(FIELD35A, srvrField35A_QuantityOfSecurities)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD35CD, srvrField35a_NextCoupon)
  M(FIELD35L, srvrField35L_PriceLimit)
  O(FIELD82AD, srvrField82a_InstructingParty)
  O(FIELD83ACD, srvrField83a_SafekeepingAccount)
  O(FIELD87EF, srvrField87a_ReceiverOfSecurities)
  O(FIELD88ACD, srvrField88a_BeneficiaryOfSecurities)
  O(FIELD53ACD, srvrField53a_AccountForPayment)
  O(FIELD71D, srvrField71D_AccountsForCharges)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT500)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 0 1

BEGIN_IMPLEMENT_SEQUENCE(MT501, "MT501 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD23, srvrField23_FurtherIdentification)
  O(FIELD30, srvrField30_ExpiryDateOfOrder)
  O(FIELD32S, srvrField32S_DateAndStrikingPrice)
  M(FIELD35A, srvrField35A_QuantityOfSecurities)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD35CD, srvrField35a_NextCoupon)
  M(FIELD35L, srvrField35L_PriceLimit)
  O(FIELD82AD, srvrField82a_InstructingParty)
  O(FIELD83ACD, srvrField83a_SafekeepingAccount)
  O(FIELD87EF, srvrField87a_DelivererOfSecurities)
  O(FIELD53ACD, srvrField53a_AccountForPayment)
  O(FIELD57ABD, srvrField57a_AccountWithInstitution)
  O(FIELD58AD, srvrField58a_BeneficiaryOfMoney)
  O(FIELD71D, srvrField71D_AccountsForCharges)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT501)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 0 2

BEGIN_IMPLEMENT_SEQUENCE(MT502, "MT502 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD20F, srvrField20F_FunctionOfTheMessage)
  M(FIELD23O, srvrField23O_BuyOrSellIndicator)
  M(FIELD21, srvrField21_RelatedReference)
  O(FIELD24C, srvrField24C_ReasonOrStatusCode)
  O(FIELD72B, srvrField72B_ReasonOrStatusNarrative)
  O(FIELD14S, srvrField14S_TimeStamp)
  O(FIELD23R, srvrField23R_AutomaticOrderRoutingIndicator)
  O(FIELD23I, srvrField23I_FurtherRoutingIndicator)
  LOOP(OS_MANTADORY, "???",0,1000)
    M(FIELD29D, srvrField29D_ReportingOrProcessingInstruction)
  M(FIELD30B, srvrField30B_TimeLimitOrderOrExpiryDateOfOrder)
  M(FIELD32O, srvrField32O_PriceLimitOrTypeOfOrder)
  O(FIELD32X, srvrField32X_StopPrice)
  O(FIELD28L, srvrField28L_PriceLimitQualifier)
  O(FIELD28P, srvrField28P_PlaceOfTradeOrExchange)
  LOOP(OS_MANTADORY, "???",0,1000)
    M(FIELD25C, srvrField25C_TransactionCondition)
  M(FIELD35A, srvrField35A_QuantityOfFinancialInstrument)
  O(FIELD23T, srvrField23T_TypeOfSafekeeping)
  O(FIELD83ACD, srvrField83a_SafekeepingAccount)
  O(FIELD87EF, srvrField87a_DelivererOrReceiverOfFinancialInstruments)
  O(FIELD88ACD, srvrField88a_BeneficiaryOfFinancialInstruments)
  O(FIELD53ACD, srvrField53a_AccountForPayment)
  O(FIELD57ACD, srvrField57a_AccountWithInstitution)
  O(FIELD58ACD, srvrField58a_BeneficiaryOfMoney)
  M(FIELD35B, srvrField35B_IdentificationOfFinancialInstrument)
  LOOP(OS_MANTADORY,"???",0,1000)
    M(FIELD25I, srvrField25I_FinancialInstrumentAttribute)
  O(FIELD20S, srvrField20S_StandingInstructionsOverrideIndicator)
  O(FIELD82ACD, srvrField82a_InstructingParty)
  O(FIELD84ACD, srvrField84a_ExecutingBroker)
  O(FIELD33V, srvrField33V_CommissionAmount)
  O(FIELD25B, srvrField25B_CommissionBasis)
  O(FIELD71D, srvrField71D_AccountsForCharges)
  O(FIELD83R, srvrField83a_DealingCapacity)
  O(FIELD77D, srvrField77D_RegistrationDetails)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT502)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 1 0

BEGIN_IMPLEMENT_SEQUENCE(MT510, "MT510 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(FIELD23, srvrField23_FurtherIdentification)
  M(FIELD31P, srvrField31P_DateAndPlaceOfTrade)
  O(FIELD30, srvrField30_SettlementDate)
  M(FIELD35A, srvrField35A_QuantityOfSecurities)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD35CD, srvrField35a_NextCoupon)
  O(FIELD35E, srvrField35E_CertificateNumbers)
  O(FIELD33V, srvrField33V_BookValue)
  O(FIELD82AD, srvrField82a_InstructingParty)
  O(FIELD83ACD, srvrField83a_SafekeepingAccount)
  O(FIELD87EF, srvrField87a_ReceiverOrDelivererOfSecurities)
  O(FIELD88ACD, srvrField88a_BeneficiaryOfSecurities)
  O(FIELD53ACD, srvrField53a_AccountForPayment)
  O(FIELD57ACD, srvrField57a_AccountWithInstitution)
  O(FIELD58AD, srvrField58a_BeneficiaryOfMoney)
  O(FIELD32S, srvrField32S_DateAndStrikingPrice)
  O(FIELD33S, srvrField33S_SpecialConcessions)
  M(FIELD33T, srvrField33T_DealPrice)
  O(FIELD32M, srvrField32M_DealAmount)
  O(FIELD34GH, srvrField34a_AccruedInterest)
  O(FIELD32B, srvrField32B_SettlementAmount)
  O(FIELD71C, srvrField71C_OtherCharges)
  O(FIELD71B, srvrField71B_OwnCharges)
  O(FIELD36, srvrField36_ExchangeRate)
  M(FIELD34AB, srvrField34a_NetProceeds)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT510)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 1 2

BEGIN_IMPLEMENT_SEQUENCE(MT512, "MT512 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(FIELD23, srvrField23_FurtherIdentification)
  M(FIELD31P, srvrField31P_DateAndPlaceOfTrade)
  O(FIELD31T, srvrField31T_TimeOfTrade)
  M(FIELD30, srvrField30_DateOfIntendedSettlement)
  M(FIELD35A, srvrField35A_QuantityOfSecurities)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD35CD, srvrField35a_NextCoupon)
  O(FIELD82AD, srvrField82a_Counterparty)
  M(FIELD87EF, srvrField87a_ReceiverOfSecurities)
  O(FIELD87EF, srvrField87a_DelivererOfSecurities)
  M(FIELD33T, srvrField33T_DealPrice)
  O(FIELD32M, srvrField32M_DealAmount)
  O(FIELD33S, srvrField33S_SpecialConcessions)
  O(FIELD34GH, srvrField34a_AccruedInterest)
  O(FIELD32B, srvrField32B_SettlementAmount)
  O(FIELD71C, srvrField71C_OtherCharges)
  O(FIELD71B, srvrField71B_OwnCharges)
  O(FIELD36, srvrField36_ExchangeRate)
  M(FIELD34AB, srvrField34a_NetProceeds)
  O(FIELD57ABD, srvrField57a_AccountWithInstitution)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT512)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 1 3 - Client Advice of Execution
/*
Scope:
This message type is sent by the Executing Party (e.g. the Broker-Dealer) to an Instructing Party (e.g. the Clien), or uts authorised representative. It may also be sent by a point of execution to the party which had previously submitted an order to buy 
*/

BEGIN_IMPLEMENT_SEQUENCE(MT513, "MT513 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD20F, srvrField20F_FunctionOfTheMessage)
  M(FIELD21, srvrField21_RelatedReference)
  O(FIELD24C, srvrField24C_ReasonOrStatusCode)
  O(FIELD72B, srvrField72B_ReasonOrStatusNarrative)
  O(FIELD14S, srvrField14S_TimeStamp)

  M(FIELD23O, srvrField23O_BoughtOrSoldIndicator)
  LOOP(OS_MANTADORY,"???",0,1000)
    M(FIELD29D, srvrField29D_ReportingOrProcessingInstruction)
  O(FIELD24A, srvrField24A_TransactionVersionNumber)
  O(FIELD38F, srvrField38F_PartialFillOrRecapIndicator)

  BEGIN_LOOP(OS_MANTADORY,"???",0,1000)
    O(FIELD30Q, srvrField30Q_PartialFillTradeDate)
    O(FIELD31U, srvrField31U_PartialFillTime)
    O(FIELD29P, srvrField29P_PartialFillPlaceOfTradeOrExchange)
    M(FIELD35S, srvrField35S_PartialFillQuantity)
    M(FIELD33O, srvrField33O_PartialFillPrice)
    O(FIELD86ACD, srvrField86a_Counterparty)
    O(FIELD33V, srvrField33V_CommissionAmount)
  END_LOOP

  O(FIELD29O, srvrField29O_QuantityOrdered)
  O(FIELD29E, srvrField29E_QuantityPreviouslyExecuted)
  O(FIELD29L, srvrField29L_QuantityRemainingOnOrder)

  O(FIELD81ACD, srvrField81a_FundOrClient)
  M(FIELD30E, srvrField30E_DateOfTrade)
  O(FIELD29T, srvrField29T_TimeOfTrade)
  O(FIELD28P, srvrField28P_PlaceOfTradeOrExchange)
  M(FIELD35A, srvrField35A_QuantityOfFinancialInstrument)
  M(FIELD35B, srvrField35B_IdentificationOfFinancialInstrument)
  LOOP(OS_MANTADORY,"???",0,1000)
    M(FIELD25I, srvrField25I_FinancialInstrumentAttribute)
  M(FIELD33T, srvrField33T_DealPrice)
  O(FIELD26U, srvrField26U_TypeOfPrice)
  O(FIELD32M, srvrField32M_DealAmount)
  LOOP(OS_MANTADORY,"???",0,1000)
    M(FIELD25C, srvrField25C_TransactionCondition)
  O(FIELD34GH, srvrField34a_AccruedInterest)
  O(FIELD83R, srvrField83a_DealingCapacity)

  O(FIELD82ACD, srvrField82a_Institution)
  O(FIELD84ACD, srvrField84a_ExecutingBroker)
  O(FIELD20S, srvrField20S_StandingInstructionsOverrideIndicator)
  O(FIELD44S, srvrField44S_DateOfSettlement)

  BEGIN_LOOP(OS_MANTADORY,"???",0,1000)
    M(FIELD23D, srvrField23D_TypeOfChargeOrTax)
    M(FIELD32G, srvrField32G_ChargeOrTaxAmount)
    O(FIELD77N, srvrField77N_ChargeOrTaxNarrative)
  END_LOOP

  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT513)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 1 4

BEGIN_IMPLEMENT_SEQUENCE(MT514, "MT514 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD20F, srvrField20F_FunctionOfTheMessage)
  M(FIELD21, srvrField21_RelatedReference)

  LOOP(OS_MANTADORY,"???",0,1000)
    M(FIELD29D, srvrField29D_ReportingOrProcessingInstruction)
  O(FIELD35P, srvrField35P_QuantityToBeAllocated)
  O(FIELD35S, srvrField35S_QuantityPreviouslyAllocated)
  M(FIELD35B, srvrField35B_IdentificationOfFinancialInstrument)
  LOOP(OS_MANTADORY,"\0\0",0,1000)
    M(FIELD25I, srvrField25I_FinancialInstrumentAttribute)
  O(FIELD23O, srvrField23O_BoughtOrSoldIndicator)
  O(FIELD44S, srvrField44S_DateOfSettlement)
  O(FIELD30E, srvrField30E_DateOfTrade)
  O(FIELD21B, srvrField21B_TransactionVersionNumberOfBlockTrade)
  O(FIELD82ACD, srvrField82a_Institution)
  O(FIELD84ACD, srvrField84a_ExecutingBroker)
  O(FIELD85ACD, srvrField85a_ClearingBroker)
  O(FIELD14S, srvrField14S_TimeStamp)
  O(FIELD72C, srvrField72C_SenderToReceiverInformation)

  BEGIN_LOOP(OS_MANTADORY,"\0\0",1,1000)
    M(FIELD20B, srvrField20B_SendersTransactionReferenceNumber)
    LOOP(OS_MANTADORY,"\0\0",0,1000)
      M(FIELD29D, srvrField29D_ReportingOrProcessingInstruction)
    O(FIELD89ACD, srvrField89a_StepInBroker)
    O(FIELD24C, srvrField24C_ReasonOrStatusCode)
    O(FIELD72B, srvrField72B_ReasonOrStatusNarrative)
    M(FIELD21R, srvrField21R_AllocationReferenceNumber)
    O(FIELD21N, srvrField21N_VersionNumberOfAllocatedTrade)
    O(FIELD39D, srvrField39D_AllocationNumberOrTotalInTheMessage)
    M(FIELD81ACD, srvrField81a_FundOrClient)
    M(FIELD35A, srvrField35A_QuantityOfFinancialInstrument)
    O(FIELD33T, srvrField33T_DealPrice)
    O(FIELD26U, srvrField26U_TypeOfPrice)
    O(FIELD34GH, srvrField34a_AccruedInterest)
    LOOP(OS_MANTADORY,"\0\0",1,1000)
      M(FIELD25C, srvrField25C_TransactionCondition)
    BEGIN_LOOP(OS_MANTADORY,"\0\0",1,1000)
      M(FIELD23D, srvrField23D_TypeOfChargeOrTax)
      M(FIELD32G, srvrField32G_ChargeOrTaxAmount)
      O(FIELD77N, srvrField77N_ChargeOrTaxNarrative)
    END_LOOP
    O(FIELD32B, srvrField32B_SettlementAmount)
    O(FIELD20S, srvrField20S_StandingInstructionsOverrideIndicator)
    O(FIELD82IR, srvrField82a_PlaceOfSettlement)
    O(FIELD23T, srvrField23T_TypeOfSafekeeping)
    O(FIELD83ACD, srvrField83a_SafekeepingAccount)
    O(FIELD87EF, srvrField87a_DelivererOrReceiverOfFinancialInstruments)
    O(FIELD88ACD, srvrField88a_BeneficiaryOfFinancialInstruments)
    O(FIELD53ACD, srvrField53a_AccountForPayment)
    O(FIELD57ACD, srvrField57a_AccountWithInstitution)
    O(FIELD58ACD, srvrField58a_BeneficiaryOfMoney)
    BEGIN_LOOP(OS_MANTADORY,"\0\0",1,1000)
      O(FIELD24I, srvrField24I_TypeOfInterestedParty)
      M(FIELD86ACD, srvrField86a_InterestedParty)
      O(FIELD25, srvrField25_InterestedPartyInternalAccountNumber)
    END_LOOP
    O(FIELD72, srvrField72_SenderToReceiverInformation)
  END_LOOP

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT514)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 1 5

BEGIN_IMPLEMENT_SEQUENCE(MT515, "MT515 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD20F, srvrField20F_FunctionOfTheMessage)
  M(FIELD21, srvrField21_RelatedReference)
  O(FIELD24C, srvrField24C_ReasonOrStatusCode)
  O(FIELD72B, srvrField72B_ReasonOrStatusNarrative)
  O(FIELD14S, srvrField14S_TimeStamp)

  M(FIELD23O, srvrField23O_BoughtOrSoldIndicator)
  LOOP(OS_MANTADORY,"\0\0",0,1000)
    M(FIELD29D, srvrField29D_ReportingOrProcessingInstruction)
  O(FIELD38F, srvrField38F_PartialFillIndicator)

  BEGIN_LOOP(OS_MANTADORY,"\0\0",0,1000)
    O(FIELD30Q, srvrField30Q_PartialFillTradeDate)
    O(FIELD31U, srvrField31U_PartialFillTime)
    O(FIELD29P, srvrField29P_PartialFillPlaceOfTradeOrExchange)
    M(FIELD35S, srvrField35S_QuantityPreviouslyAllocated)
    M(FIELD33O, srvrField33O_PartialFillPrice)
  END_LOOP

  M(FIELD81ACD, srvrField81a_FundOrClient)
  O(FIELD24A, srvrField24A_TransactionVersionNumber)
  O(FIELD21R, srvrField21R_AllocationReferenceNumber)
  M(FIELD30E, srvrField30E_DateOfTrade)
  O(FIELD29T, srvrField29T_TimeOfTrade)
  O(FIELD28P, srvrField28P_PartialFillPlaceOfTradeOrExchange)
  M(FIELD35A, srvrField35A_QuantityOfFinancialInstrument)
  M(FIELD35B, srvrField35B_IdentificationOfFinancialInstrument)
  LOOP(OS_MANTADORY,"\0\0",0,1000)
    M(FIELD25I, srvrField25I_FinancialInstrumentAttribute)
  M(FIELD33T, srvrField33T_DealPrice)
  O(FIELD26U, srvrField26U_TypeOfPrice)
  O(FIELD32M, srvrField32M_DealAmount)
  LOOP(OS_MANTADORY,"\0\0",0,1000)
    M(FIELD25C, srvrField25C_TransactionCondition)
  O(FIELD34GH, srvrField34a_AccruedInterest)
  O(FIELD32B, srvrField32B_SettlementAmount)
  O(FIELD20S, srvrField20S_StandingInstructionsOverrideIndicator)
  O(FIELD83R, srvrField83a_DealingCapacity)

  O(FIELD23T, srvrField23T_TypeOfSafekeeping)
  O(FIELD83ACD, srvrField83a_SafekeepingAccount)
  O(FIELD82ACD, srvrField82a_InstructingParty)
  O(FIELD84ACD, srvrField84a_ExecutingBroker)
  O(FIELD24T, srvrField24T_TypeOfAffirmingParty)
  O(FIELD85ACD, srvrField85a_ClearingBroker)
  O(FIELD82IR, srvrField82a_PlaceOfSettlement)
  M(FIELD44S, srvrField44S_DateOfSettlement)
  O(FIELD87EF, srvrField87a_ReceiverOrDelivererOfSecurities)
  O(FIELD88ACD, srvrField88a_BeneficiaryOfFinancialInstruments)
  O(FIELD53ACD, srvrField53a_AccountForPayment)
  O(FIELD57ACD, srvrField57a_AccountWithInstitution)
  O(FIELD58ACD, srvrField58a_BeneficiaryOfMoney)
  BEGIN_LOOP(OS_MANTADORY,"\0\0",0,1000)
    M(FIELD23D, srvrField23D_TypeOfChargeOrTax)
    M(FIELD32G, srvrField32G_ChargeOrTaxAmount)
    O(FIELD77N, srvrField77N_ChargeOrTaxNarrative)
  END_LOOP

  BEGIN_LOOP(OS_MANTADORY,"\0\0",0,1000)
    M(FIELD33X, srvrField33X_ToAndFromCurrencies)
    M(FIELD36, srvrField36_ExchangeRate)
  END_LOOP
  M(FIELD34BI, srvrField34a_NetProceeds)
  BEGIN_LOOP(OS_MANTADORY,"\0\0",0,1000)
    O(FIELD24I, srvrField24I_TypeOfInterestedParty)
    M(FIELD86ACDEF, srvrField86a_InterestedParty)
    O(FIELD25, srvrField25_InterestedPartyInternalAccountNumber)
    O(FIELD72S, srvrField72S_InterestedPartyNarrative)
  END_LOOP
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT515)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 1 6

BEGIN_IMPLEMENT_SEQUENCE(MT516, "MT516 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  M(FIELD23, srvrField23_FurtherIdentification)
  M(FIELD31P, srvrField31P_DateLoanOrRecallOrReturnAgreed)
  O(FIELD83C, srvrField83a_SafekeepingAccount)
  M(FIELD35B, srvrField35B_IdentificationOfFinancialInstrument)
  O(FIELD35A, srvrField35A_QuantityOfFinancialInstrument)
  O(FIELD31L, srvrField31L_PayableDate)
  O(FIELD31X, srvrField31X_ExDate)
  M(FIELD30, srvrField30_EffectiveDate)
  O(FIELD31F, srvrField31F_ExpiryAndOptionDateOfLoan)
  O(FIELD87AD, srvrField87a_ReceiverOrDelivererOfSecurities)
  O(FIELD35N, srvrField35N_QuantityOfSecuritiesRecalledOrReturned)
  O(FIELD33T, srvrField33T_DealPrice)

  O(FIELD37J, srvrField37J_InterestRateOnSecurities)
  O(FIELD26H, srvrField26H_CollateralType)
  O(FIELD33S, srvrField33S_SpecialConcessions)
  O(FIELD32AB, srvrField32a_CashCollateralAmount)
  O(FIELD37ABCDEF, srvrField37a_RebateAgreed)
  O(FIELD57ABD, srvrField57a_AccountWithInstitution)
  O(FIELD35S, srvrField35S_QuantityPreviouslyAllocated)
  O(FIELD35B, srvrField35B_IdentificationOfFinancialInstrument)
  O(FIELD87AD, srvrField87a_ReceiverOrDelivererOfSecurities)

  O(FIELD77D, srvrField77D_RegistrationDetails)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT516)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 1 7

BEGIN_IMPLEMENT_SEQUENCE(MT517, "MT517 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  O(FIELD21R, srvrField21R_AllocationReferenceNumber)
  O(FIELD24A, srvrField24A_TransactionVersionNumber)
  O(FIELD14S, srvrField14S_TimeStamp)
  O(FIELD84ACD, srvrField84a_ExecutingBroker)
  O(FIELD82ACD, srvrField82a_InstructingParty)
  O(FIELD24T, srvrField24T_TypeOfAffirmingParty)
  O(FIELD85ACD, srvrField85a_ClearingBroker)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT517)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 1 8

BEGIN_IMPLEMENT_SEQUENCE(MT518, "MT518 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD20F, srvrField20F_FunctionOfTheMessage)
  M(FIELD21, srvrField21_RelatedReference)
  O(FIELD24C, srvrField24C_ReasonOrStatusCode)
  O(FIELD72B, srvrField72B_ReasonOrStatusNarrative)
  O(FIELD14S, srvrField14S_TimeStamp)

  M(FIELD23O, srvrField23O_BoughtOrSoldIndicator)
  LOOP(OS_MANTADORY,"\0\0",0,1000)
    M(FIELD29D, srvrField29D_ReportingOrProcessingInstruction)
  O(FIELD24A, srvrField24A_TransactionVersionNumber)
  M(FIELD30F, srvrField30F_DateOfTrade)
  O(FIELD29T, srvrField29T_TimeOfTrade)
  O(FIELD28P, srvrField28P_PlaceOfTradeOrExchange)
  M(FIELD35A, srvrField35A_QuantityOfFinancialInstrument)
  M(FIELD35B, srvrField35B_IdentificationOfFinancialInstrument)
  LOOP(OS_MANTADORY,"\0\0",0,1000)
    M(FIELD25I, srvrField25I_FinancialInstrumentAttribute)
  M(FIELD33T, srvrField33T_DealPrice)
  O(FIELD26U, srvrField26U_TypeOfPrice)
  O(FIELD32M, srvrField32M_DealAmount)
  O(FIELD34GH, srvrField34a_AccruedInterest)
  O(FIELD83R, srvrField83a_DealingCapacity)
  LOOP(OS_MANTADORY,"\0\0",0,1000)
    M(FIELD25C, srvrField25C_TransactionCondition)

  M(FIELD32B, srvrField32B_SettlementAmount)
  BEGIN_LOOP(OS_MANTADORY, "\0\0",0,1000)
    M(FIELD23D, srvrField23D_TypeOfChargeOrTax)
    M(FIELD32G, srvrField32G_ChargeOrTaxAmount)
    O(FIELD77N, srvrField77N_ChargeOrTaxNarrative)
  END_LOOP
  M(FIELD44S, srvrField44S_DateOfSettlement)
  O(FIELD23T, srvrField23T_TypeOfSafekeeping)
  M(FIELD87EF, srvrField87a_ReceiverOrDelivererOfSecurities)
  O(FIELD86EF, srvrField86a_InterestedParty)
  BEGIN_LOOP(OS_MANTADORY,"\0\0",0,1000)
    M(FIELD33X, srvrField33X_ToAndFromCurrencies)
    M(FIELD36, srvrField36_ExchangeRate)
  END_LOOP
  O(FIELD34BI, srvrField34a_NetProceeds)
  O(FIELD57ACD, srvrField57a_AccountWithInstitution)
  O(FIELD82ACD, srvrField82a_InstructingParty)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT518)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 1 9

BEGIN_IMPLEMENT_SEQUENCE(MT519, "MT519 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(FIELD23, srvrField23_FurtherIdentification)
  M(FIELD31P, srvrField31P_DateAndPlaceOfTrade)
  O(FIELD32S, srvrField32S_DateAndStrikingPrice)
  M(FIELD35A, srvrField35A_QuantityOfFinancialInstrument)
  M(FIELD35B, srvrField35B_IdentificationOfFinancialInstrument)
  M(FIELD33T, srvrField33T_DealPrice)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT519)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 2 0 - Receive Free
/*
Scope:

This message type is sent from one financial institution to another, both of which are involved in the transfer of securities.
It is used to instruct the Receiver to receive specified securities, physically or by book-entry, from a specified party, without paying an amount of money.
*/

BEGIN_IMPLEMENT_SEQUENCE(MT520, "MT520 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

//////////////////////////////////////////////////////////
// Sequence A

  O(FIELD30, srvrField30_DeliveryDate)
  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  O(FIELD31P, srvrField31P_DateAndPlaceOfTrade)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD35CD, srvrField35a_NextCoupon)
  O(FIELD33V, srvrField33V_BookValue)
  O(FIELD82AD, srvrField82a_InstructingParty)

////////////////////////////////////////////////////////////////////////
// Sequence B

  LOOP(OS_MANTADORY,srvrMT5XXB, 1, 1000)
    BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceB)
      M(FIELD35A, srvrField35A_QuantityOfSecurities)
      O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
      O(FIELD35E, srvrField35E_CertificateNumbers)
    END_SEQUENCE

/////////////////////////////////////////////////////////////////////////////
// Sequence C

  M(FIELD87AD, srvrField87a_DelivererOfSecurities)
  O(FIELD88ACD, srvrField88a_BeneficiaryOfSecurities)
  O(FIELD85ACD, srvrField85a_DeliverersInstructingParty)
  O(FIELD77D, srvrField77D_RegistrationDetails)
  O(FIELD77R, srvrField77R_DeclarationDetails)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT520)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 2 1 - Receive Against Payment
/*
Scope:

This message type sent by one financial institution to another, both of which are involved in the transfer of securities.
It is used to instruct the Receiver to receive specified securities, physically or by book-entry, from a specified party, and to remit the specified amount of money in payment.
*/

BEGIN_IMPLEMENT_SEQUENCE(MT521, "MT521 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

//////////////////////////////////////////////////////////
// Sequence A

  O(FIELD30, srvrField30_SettlementDate)
  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  O(FIELD31P, srvrField31P_DateAndPlaceOfTrade)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD35CD, srvrField35a_NextCoupon)
  O(FIELD33V, srvrField33V_BookValue)
  O(FIELD82AD, srvrField82a_InstructingParty)

////////////////////////////////////////////////////////////////////////
// Sequence B

  LOOP(OS_MANTADORY,srvrMT5XXB, 1, 1000)
    BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceB)
      M(FIELD35A, srvrField35A_QuantityOfSecurities)
      O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
      O(FIELD35E, srvrField35E_CertificateNumbers)
    END_SEQUENCE

/////////////////////////////////////////////////////////////////////////////
// Sequence C

  M(FIELD87AD, srvrField87a_DelivererOfSecurities)
  O(FIELD88ACD, srvrField88a_BeneficiaryOfSecurities)
  O(FIELD85ACD, srvrField85a_DeliverersInstructingParty)
  O(FIELD77D, srvrField77D_RegistrationDetails)
  O(FIELD77R, srvrField77R_DeclarationDetails)
  O(FIELD53ACD, srvrField53a_AccountForPayment)
  O(FIELD57ABD, srvrField57a_AccountWithInstitution)
  O(FIELD58AD, srvrField58a_BeneficiaryOfMoney)
  O(FIELD33T, srvrField33T_DealPrice)
  O(FIELD32M, srvrField32M_DealAmount)
  O(FIELD34GH, srvrField34a_AccruedInterest)
  O(FIELD71E, srvrField71E_TaxesAdded)
  O(FIELD71F, srvrField71F_BrokersCommission)
  O(FIELD71G, srvrField71G_OtherChargesOrFees)
  M(FIELD32B, srvrField32B_SettlementAmount)
  O(FIELD71D, srvrField71D_AccountsForCharges)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT521)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 2 2

BEGIN_IMPLEMENT_SEQUENCE(MT522, "MT522 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

//////////////////////////////////////////////////////////
// Sequence A

  O(FIELD30, srvrField30_DeliveryDate)
  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  O(FIELD31P, srvrField31P_DateAndPlaceOfTrade)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD35CD, srvrField35a_NextCoupon)
  O(FIELD33V, srvrField33V_BookValue)
  O(FIELD82AD, srvrField82a_InstructingParty)

////////////////////////////////////////////////////////////////////////
// Sequence B

  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_LOOP(OS_MANTADORY,"instr_acct\0\0", 1, 1000)
      M(FIELD35A, srvrField35A_QuantityOfSecurities)
      M(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
      O(FIELD35E, srvrField35E_CertificateNumbers)
    END_LOOP

    BEGIN_LOOP(OS_MANTADORY,"instr_acct\0\0", 1, 1)
      M(FIELD35A, srvrField35A_QuantityOfSecurities)
      O(FIELD35E, srvrField35E_CertificateNumbers)
    END_LOOP
  END_PARALLEL

/////////////////////////////////////////////////////////////////////////////
// Sequence C

  M(FIELD87AD, srvrField87a_ReceiverOfSecurities)
  O(FIELD88ACD, srvrField88a_BeneficiaryOfSecurities)
  O(FIELD77D, srvrField77D_RegistrationDetails)
  O(FIELD77R, srvrField77R_DeclarationDetails)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT522)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 2 3

BEGIN_IMPLEMENT_SEQUENCE(MT523, "MT523 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

//////////////////////////////////////////////////////////
// Sequence A

  O(FIELD30, srvrField30_SettlementDate)
  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  O(FIELD31P, srvrField31P_DateAndPlaceOfTrade)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD35CD, srvrField35a_NextCoupon)
  O(FIELD33V, srvrField33V_BookValue)
  O(FIELD82AD, srvrField82a_InstructingParty)

////////////////////////////////////////////////////////////////////////
// Sequence B

  LOOP(OS_MANTADORY,srvrMT5XXB, 1, 1000)
    BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceB)
      M(FIELD35A, srvrField35A_QuantityOfSecurities)
      O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
      O(FIELD35E, srvrField35E_CertificateNumbers)
    END_SEQUENCE

/////////////////////////////////////////////////////////////////////////////
// Sequence C

  M(FIELD87AD, srvrField87a_ReceiverOfSecurities)
  O(FIELD88ACD, srvrField88a_BeneficiaryOfSecurities)
  O(FIELD77D, srvrField77D_RegistrationDetails)
  O(FIELD77R, srvrField77R_DeclarationDetails)
  O(FIELD53ACD, srvrField53a_AccountForPayment)
  O(FIELD57ABD, srvrField57a_AccountWithInstitution)
  O(FIELD58AD, srvrField58a_BeneficiaryOfMoney)

  O(FIELD33T, srvrField33T_DealPrice)
  O(FIELD32M, srvrField32M_DealAmount)
  O(FIELD34GH, srvrField34a_AccruedInterest)
  O(FIELD71E, srvrField71E_TaxesDeducted)
  O(FIELD71F, srvrField71F_BrokersCommission)
  O(FIELD71G, srvrField71G_OtherChargesOrFees)
  M(FIELD32B, srvrField32B_SettlementAmount)
  O(FIELD71D, srvrField71D_AccountsForCharges)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT523)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 2 6 - General Securities Lending/Borrowing Message
/*
Note:

This message may only be send and receive after prior arragements between the Sender and Receiver.

Scope:

This message type is sent from one financial institution to another, both of which are involved in the lending of securities.
*/

BEGIN_IMPLEMENT_SEQUENCE(MT526, "MT526 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

//////////////////////////////////////////////////////////
// Sequence A

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  M(FIELD23_526, srvrField23_FurtherIdentification)
  O(FIELD83C, srvrField83a_SafekeepingAccount)
  O(FIELD29A, srvrField29A_From)
  O(FIELD29B, srvrField29B_ToTheAttentionOf)

////////////////////////////////////////////////////////////////////////
// Sequence B

  BEGIN_LOOP(OS_MANTADORY,"instr_acct\0\0", 1, 1000)
    M(FIELD35B, srvrField35B_IdentificationOfSecurities)
    O(FIELD35A, srvrField35A_QuantityOfSecurities)
    O(FIELD30, srvrField30_EffectiveDate)
    O(FIELD31F, srvrField31F_ExpiryAndOptionDate)
    M(FIELD87AD, srvrField87a_ReceiverOrDelivererOfSecurities)
    O(FIELD72, srvrField72_SenderToReceiverInformation)
  END_LOOP

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT526)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 3 0

BEGIN_IMPLEMENT_SEQUENCE(MT530, "MT530 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

//////////////////////////////////////////////////////////
// Sequence A

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(FIELD30, srvrField30_DeliveryDate)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD35CD, srvrField35a_NextCoupon)
  O(FIELD33V, srvrField33V_BookValue)
  O(FIELD82AD, srvrField82a_InstructingParty)

////////////////////////////////////////////////////////////////////////
// Sequence B

  LOOP(OS_MANTADORY,srvrMT5XXB, 1, 1000)
    BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceB)
      M(FIELD35A, srvrField35A_QuantityOfSecurities)
      O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
      O(FIELD35E, srvrField35E_CertificateNumbers)
    END_SEQUENCE

/////////////////////////////////////////////////////////////////////////////
// Sequence C

  M(FIELD87AD, srvrField87a_DelivererOfSecurities)
  O(FIELD88ACD, srvrField88a_BeneficiaryOfSecurities)
  O(FIELD85ACD, srvrField85a_DeliverersInstructingParty)
  O(FIELD77D, srvrField77D_RegistrationDetails)
  O(FIELD77R, srvrField77R_DeclarationDetails)
  O(FIELD71C, srvrField71C_OtherCharges)
  O(FIELD71B, srvrField71B_OwnCharges)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT530)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 3 1

BEGIN_IMPLEMENT_SEQUENCE(MT531, "MT531 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

//////////////////////////////////////////////////////////
// Sequence A

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(FIELD30, srvrField30_SettlementDate)
  O(FIELD31P, srvrField31P_DateAndPlaceOfTrade)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD35CD, srvrField35a_NextCoupon)
  O(FIELD33V, srvrField33V_BookValue)
  O(FIELD82AD, srvrField82a_InstructingParty)

////////////////////////////////////////////////////////////////////////
// Sequence B

  LOOP(OS_MANTADORY,srvrMT5XXB, 1, 1000)
    BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceB)
      M(FIELD35A, srvrField35A_QuantityOfSecurities)
      O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
      O(FIELD35E, srvrField35E_CertificateNumbers)
    END_SEQUENCE

/////////////////////////////////////////////////////////////////////////////
// Sequence C

  M(FIELD87AD, srvrField87a_DelivererOfSecurities)
  O(FIELD88ACD, srvrField88a_BeneficiaryOfSecurities)
  O(FIELD85ACD, srvrField85a_DeliverersInstructingParty)
  O(FIELD77D, srvrField77D_RegistrationDetails)
  O(FIELD77R, srvrField77R_DeclarationDetails)
  O(FIELD53ACD, srvrField53a_AccountForPayment)
  O(FIELD57ABD, srvrField57a_AccountWithInstitution)
  O(FIELD58AD, srvrField58a_BeneficiaryOfMoney)
  O(FIELD33S, srvrField33S_SpecialConcessions)
  O(FIELD33T, srvrField33T_DealPrice)
  O(FIELD32M, srvrField32M_DealAmount)
  O(FIELD34GH, srvrField34a_AccruedInterest)
  M(FIELD32B, srvrField32B_SettlementAmount)
  O(FIELD71C, srvrField71C_OtherCharges)
  O(FIELD71B, srvrField71B_OwnCharges)
  O(FIELD36, srvrField36_ExchangeRate)
  O(FIELD34A, srvrField34A_NetProceeds)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT531)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 3 2

BEGIN_IMPLEMENT_SEQUENCE(MT532, "MT532 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

//////////////////////////////////////////////////////////
// Sequence A

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(FIELD30, srvrField30_DeliveryDate)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD35CD, srvrField35a_NextCoupon)
  O(FIELD33V, srvrField33V_BookValue)
  O(FIELD82AD, srvrField82a_InstructingParty)

////////////////////////////////////////////////////////////////////////
// Sequence B

  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_LOOP(OS_MANTADORY,"instr_acct\0\0", 1, 1000)
      M(FIELD35A, srvrField35A_QuantityOfSecurities)
      M(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
      O(FIELD35E, srvrField35E_CertificateNumbers)
    END_LOOP

    BEGIN_LOOP(OS_MANTADORY,"instr_acct\0\0", 1, 1)
      M(FIELD35A, srvrField35A_QuantityOfSecurities)
      O(FIELD35E, srvrField35E_CertificateNumbers)
    END_LOOP
  END_PARALLEL

/////////////////////////////////////////////////////////////////////////////
// Sequence C

  M(FIELD87AD, srvrField87a_ReceiverOfSecurities)
  O(FIELD88ACD, srvrField88a_BeneficiaryOfSecurities)
  O(FIELD77D, srvrField77D_RegistrationDetails)
  O(FIELD77R, srvrField77R_DeclarationDetails)
  O(FIELD71C, srvrField71C_OtherCharges)
  O(FIELD71B, srvrField71B_OwnCharges)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT532)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 3 3

BEGIN_IMPLEMENT_SEQUENCE(MT533, "MT533 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

//////////////////////////////////////////////////////////
// Sequence A

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(FIELD30, srvrField30_SettlementDate)
  O(FIELD31P, srvrField31P_DateAndPlaceOfTrade)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD35CD, srvrField35a_NextCoupon)
  O(FIELD33V, srvrField33V_BookValue)
  O(FIELD82AD, srvrField82a_InstructingParty)

////////////////////////////////////////////////////////////////////////
// Sequence B

  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_LOOP(OS_MANTADORY,"instr_acct\0\0", 1, 1000)
      M(FIELD35A, srvrField35A_QuantityOfSecurities)
      M(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
      O(FIELD35E, srvrField35E_CertificateNumbers)
    END_LOOP

    BEGIN_LOOP(OS_MANTADORY,"instr_acct\0\0", 1, 1)
      M(FIELD35A, srvrField35A_QuantityOfSecurities)
      O(FIELD35E, srvrField35E_CertificateNumbers)
    END_LOOP
  END_PARALLEL

/////////////////////////////////////////////////////////////////////////////
// Sequence C

  M(FIELD87AD, srvrField87a_ReceiverOfSecurities)
  O(FIELD88ACD, srvrField88a_BeneficiaryOfSecurities)
  O(FIELD77D, srvrField77D_RegistrationDetails)
  O(FIELD77R, srvrField77R_DeclarationDetails)

  BEGIN_PARALLEL(OS_OPTIONAL,NULL)  
    M(FIELD53ACD, srvrField53a_AccountForPayment)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      M(FIELD57ABD, srvrField57a_AccountWithInstitution)
      M(FIELD58AD, srvrField58a_BeneficiaryOfMoney)
    END_SEQUENCE
  END_PARALLEL

  O(FIELD33S, srvrField33S_SpecialConcessions)
  O(FIELD33T, srvrField33T_DealPrice)
  O(FIELD32M, srvrField32M_DealAmount)
  O(FIELD34GH, srvrField34a_AccruedInterest)
  M(FIELD32B, srvrField32B_SettlementAmount)
  O(FIELD71C, srvrField71C_OtherCharges)
  O(FIELD71B, srvrField71B_OwnCharges)
  O(FIELD36, srvrField36_ExchangeRate)
  O(FIELD34A, srvrField34A_NetProceeds)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT533)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 3 4

BEGIN_IMPLEMENT_SEQUENCE(MT534, "MT534 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

//////////////////////////////////////////////////////////
// Sequence A

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  O(FIELD11R, srvrField11a_MTAndDateOfTheOriginalInstruction)
  O(FIELD30, srvrField30_SettlementDate)
  O(FIELD31S, srvrField31S_DateProblemOccured)
  M(FIELD23_534, srvrField23_FurtherIdentification)
  O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
  M(FIELD35A, srvrField35A_QuantityOfSecurities)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD87ACD, srvrField87a_ReceiverOrDelivererOfSecurities)
  O(FIELD82ACD, srvrField82a_ReceiversOrDeliverersInstructingParty)
  O(FIELD79, srvrField79_Narrative)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT534)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 5 0

BEGIN_IMPLEMENT_SEQUENCE(MT550, "MT550 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  M(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
  M(FIELD35A, srvrField35A_QuantityOfSecurities)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  M(FIELD31H, srvrField31H_ExpiryDate)
  M(FIELD31X, srvrField31X_ExDate)
  M(FIELD31J, srvrField31J_ResponseDeadline)
  O(FIELD31C, srvrField31C_PayableDate)
  O(FIELD31E, srvrField31E_RecordDate)
  M(FIELD35A, srvrField35A_QuantityOfRights)
  O(FIELD35B, srvrField35B_IdentificationOfRights)
  O(FIELD35T, srvrField35T_SubscriptionRatio)
  O(FIELD33B, srvrField33B_SubscriptionPrice)
  O(FIELD26G, srvrField26G_TypeOfRights)
  O(FIELD33S, srvrField33S_IndicativeMarketPriceOfRights)
  O(FIELD33T, srvrField33T_IndicativeMarketPriceOfNewIssue)
  O(FIELD31S, srvrField31S_ParriPassuDate)
  O(FIELD26H, srvrField26H_DispositionOfFractions)
  O(FIELD35C, srvrField35C_CouponNumber)
  O(FIELD35D, srvrField35D_CouponDate)
  O(FIELD77R, srvrField77R_DeclarationDetails)
  O(FIELD79, srvrField79_Narrative)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT550)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 5 1

BEGIN_IMPLEMENT_SEQUENCE(MT551, "MT551 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
  O(FIELD35A, srvrField35A_QuantityOfSecurities)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  M(FIELD79, srvrField79_Narrative)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT551)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 5 2

BEGIN_IMPLEMENT_SEQUENCE(MT552, "MT552 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  M(FIELD23_552, srvrField23_FurtherIdentification)
  O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
  O(FIELD35A, srvrField35A_QuantityOfSecurities)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD35CD, srvrField35a_CouponIdentification)
  O(FIELD33B, srvrField33B_SubscriptionPrice)
  O(FIELD31C, srvrField31C_PayableDate)
  O(FIELD33S, srvrField33S_IndicativeMarketPriceOfSecurities)
  M(FIELD31H, srvrField31H_ExpiryDate)
  O(FIELD30, srvrField30_StartOfPeriod)
  O(FIELD31X, srvrField31X_ExDate)
  M(FIELD31J, srvrField31J_ResponseDeadline)
  O(FIELD31E, srvrField31E_RecordDate)
  O(FIELD35T, srvrField35T_ConversionRatio)
  O(FIELD35B, srvrField35B_IdentificationOfSecuritiesDerived)
  O(FIELD77B, srvrField77B_OtherProceedsDerived)
  O(FIELD35S, srvrField35S_QuantityOfSecuritiesDerived)
  O(FIELD31L, srvrField31L_EffectiveDate)
  O(FIELD33T, srvrField33T_DealPrice)
  O(FIELD31S, srvrField31S_ParriPassuDate)
  O(FIELD26H, srvrField26H_DispositionOfFractions)
  O(FIELD77R, srvrField77R_DeclarationDetails)
  M(FIELD79, srvrField79_Narrative)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT552)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 5 3

BEGIN_IMPLEMENT_SEQUENCE(MT553, "MT553 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  M(FIELD23_553, srvrField23_FurtherIdentification)
  O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)

  BEGIN_LOOP (LS_PUSHCOUNT, "instr_acct55\0\0",  1, 1000)
    O(FIELD35A, srvrField35A_QuantityOfSecurities)
    M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  END_LOOP

  CUSTOM0(FIELD18A, OS_MANTADORY)
  O(FIELD53ACD, srvrField53a_AccountForPayment)
  O(FIELD71D, srvrField71D_AccountsForCharges)
  M(FIELD79, srvrField79_Narrative)
  O(FIELD30, srvrField30_DateOfExecution)

  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_LOOP(LS_PUSHCOUNT, "derinstr_acct55\0\0", 1, 1000)
      M(FIELD35S, srvrField35S_QuantityOfSecuritiesDerived)
      M(FIELD35B, srvrField35B_IdentificationOfSecurities)
    END_LOOP

    LOOP(LS_PUSHCOUNT, "derinstr_acct55\0\0", 0, 1)
      M(FIELD35S, srvrField35S_QuantityOfSecuritiesDerived)
  END_PARALLEL

  CUSTOM0(FIELD18A,OS_MANTADORY)
  O(FIELD87EF, srvrField87a_ReceiverOfSecurities)
  O(FIELD88ACD, srvrField88a_BeneficiaryOfSecurities)
  O(FIELD32B, srvrField32B_SettlementAmount)
  O(FIELD77D, srvrField77D_RegistrationDetails)
  O(FIELD77R, srvrField77R_DeclarationDetails)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT553)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 5 4

BEGIN_IMPLEMENT_SEQUENCE(MT554, "MT554 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD19, srvrField19_SumOfNetProceeds)
  M(FIELD23_554, srvrField23_FurtherIdentification)
  O(FIELD53ACD, srvrField53a_AccountForPayment)
  O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
   O(FIELD72, srvrField72_SenderToReceiverInformation)

  BEGIN_LOOP(OS_MANTADORY,"MT554sub\0\0", 1, 10)
    M(FIELD20, srvrField20_TransactionReferenceNumber)
    O(FIELD21, srvrField21_RelatedReference)
    O(FIELD87AD_CNTRP, srvrField87a_ReceiverOrDelivererOfSecurities)
    M(FIELD35A, srvrField35A_QuantityOfSecurities)
    M(FIELD35B, srvrField35B_IdentificationOfSecurities)
    O(FIELD35CD, srvrField35a_CouponCollected)
    M(FIELD35U, srvrField35U_DividendOrInterestRate)
    O(FIELD31X, srvrField31X_ExDate)
    O(FIELD31E, srvrField31E_RecordDate)
    O(FIELD31L, srvrField31L_CouponClippingDate)
    O(FIELD31C, srvrField31C_PayableDate)
    O(FIELD80C, srvrField80C_ComponentsOfIncome)
    O(FIELD32G, srvrField32G_GrossAmount)
    O(FIELD71C_MULT, srvrField71C_OtherCharges)
    O(FIELD71B_MULT, srvrField71B_OwnCharges)
    O(FIELD71E, srvrField71E_TaxesDeducted)
    O(FIELD36, srvrField36_ExchangeRate)
    M(FIELD34A, srvrField34A_NetProceeds)
    O(FIELD72, srvrField72_SenderToReceiverInformation)
  END_LOOP

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT554)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 5 5

BEGIN_IMPLEMENT_SEQUENCE(MT555, "MT555 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  M(FIELD23_555, srvrField23_FurtherIdentification)
  O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
  O(FIELD87AD, srvrField87a_SenderOrDelivererOfSecurities)
  M(FIELD35A, srvrField35A_QuantityOfSecurities)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  O(FIELD35CD, srvrField35a_NextCoupon)
  M(FIELD35L, srvrField35L_Terms)
  O(FIELD31X, srvrField31X_ExDate)
  O(FIELD31E, srvrField31E_RecordDate)
  O(FIELD31C, srvrField31C_PayableDate)
  O(FIELD80C, srvrField80C_ComponentsOfIncome)
  O(FIELD35N, srvrField35N_QuantityOfSecuritiesDistributed)
  M(FIELD35P, srvrField35P_QuantityOfSecuritiesBooked)
  O(FIELD35B, srvrField35B_IdentificationOfSecuritiesBooked)
  O(FIELD33CD, srvrField33a_CashInLieuOfFraction)
  O(FIELD71C, srvrField71C_OtherCharges)
  O(FIELD71B, srvrField71B_OwnCharges)
  O(FIELD71E, srvrField71E_TaxesDeducted)
  O(FIELD36, srvrField36_ExchangeRate)
  O(FIELD34CD, srvrField34a_NetAmount)
  O(FIELD53ACD, srvrField53a_AccountForPayment)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT555)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 5 6

BEGIN_IMPLEMENT_SEQUENCE(MT556, "MT556 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  M(FIELD23_556, srvrField23_FurtherIdentification)
  O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
  M(FIELD35A, srvrField35A_QuantityOfSecurities)
  M(FIELD35B, srvrField35B_IdentificationOfSecurities)
  M(FIELD35D, srvrField35D_DueDate)
  O(FIELD31S, srvrField31S_CallDate)
  O(FIELD35E, srvrField35E_CertificateNumbers)
  O(FIELD33T, srvrField33T_RedemptionPrice)
  O(FIELD35L, srvrField35L_Terms)
  O(MT55X_FIELD75, srvrField75_Queries)
  O(FIELD32M, srvrField32M_RedemptionAmount)
  O(FIELD71C, srvrField71C_OtherCharges)
  O(FIELD71B, srvrField71B_OwnCharges)
  O(FIELD80C, srvrField80C_ComponentsOfRedemption)
  O(FIELD36, srvrField36_ExchangeRate)
  O(FIELD34CD, srvrField34a_NetAmount)
  O(FIELD53ACD, srvrField53a_AccountForPayment)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT556)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 5 7

BEGIN_IMPLEMENT_SEQUENCE(MT557, "MT557 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  M(FIELD23_557, srvrField23_FurtherIdentification)
  O(FIELD53ACD_PAY, srvrField53a_AccountForPayment)
  O(FIELD32M, srvrField32M_DealAmount)
  O(FIELD32G, srvrField32G_GrossAmount)
  O(FIELD80C, srvrField80C_ComponentsOfIncome)
  O(FIELD71B, srvrField71B_OwnCharges)
  O(FIELD73, srvrField73_AmountsAdded)
  O(FIELD36, srvrField36_ExchangeRate)
  O(FIELD34A, srvrField34A_NetProceeds)
  O(FIELD79, srvrField79_Narrative)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT557)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 5 9

BEGIN_IMPLEMENT_SEQUENCE(MT559, "MT559 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD19, srvrField19_SumOfNetProceeds)
  M(FIELD23_559, srvrField23_FurtherIdentification)

  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    M(FIELD53ACD, srvrField53a_AccountForPayment)
    M(FIELD57ABD, srvrField57a_AccountWithInstitution)
  END_PARALLEL

  O(FIELD72, srvrField72_SenderToReceiverInformation)

  BEGIN_LOOP(OS_MANTADORY,"MT559sub\0\0",  1, 10)
    M(FIELD20, srvrField20_TransactionReferenceNumber)
    M(FIELD35A, srvrField35A_QuantityOfSecurities)
    M(FIELD35B, srvrField35B_IdentificationOfSecurities)
    O(FIELD35CD, srvrField35a_CouponCollected)
    O(FIELD35E, srvrField35E_CertificateNumbers)
    O(FIELD35U, srvrField35U_DividendOrInterestRate)
    O(FIELD31E, srvrField31E_RecordDate)
    O(FIELD31L, srvrField31L_CouponClippingDate)
    O(FIELD31C, srvrField31C_PayableDate)
    O(FIELD31S, srvrField31S_CallDate)
    O(FIELD80C, srvrField80C_ComponentsOfIncome)
    O(FIELD33T, srvrField33T_RedemptionPrice)
    O(FIELD35L, srvrField35L_Terms)
    O(FIELD32M, srvrField32M_RedemptionAmount)
    O(FIELD32G, srvrField32G_GrossAmount)
    O(FIELD71C_MULT, srvrField71C_OtherCharges)
    O(FIELD71B_MULT, srvrField71B_OwnCharges)
    O(FIELD36, srvrField36_ExchangeRate)
    M(FIELD34A, srvrField34A_NetProceeds)
    O(MT55X_FIELD75, srvrField75_Queries)
    O(FIELD72, srvrField72_SenderToReceiverInformation)
  END_LOOP

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT559)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 6 0

BEGIN_IMPLEMENT_SEQUENCE(MT560, "MT560 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD30, srvrField30_ProxyDeadline)

  LOOP(LS_PUSHCOUNT, "date_place\0\0", 1, 1000) 
    M(FIELD31B, srvrField31B_DateTimeAndPlaceOfMeeting)

  CUSTOM0(FIELD18A,OS_MANTADORY)
  M(FIELD80A, srvrField80A_RegisteredNameAndPlaceOfCompany)

  BEGIN_LOOP(LS_PUSHCOUNT, "MT56instr\0\0", 1, 1000)
    M(FIELD35B, srvrField35B_IdentificationOfSecurities)

    BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
      BEGIN_PARALLEL(OS_MANTADORY,NULL)
        BEGIN_LOOP(LS_PUSHCOUNT, "MT56instr_a\0\0", 1, 1000)
          M(FIELD35A, srvrField35A_QuantityOfSecurities)
          M(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
        END_LOOP

        LOOP(LS_PUSHCOUNT, "MT56instr_a\0\0", 1, 1)
           M(FIELD35A, srvrField35A_QuantityOfSecurities)
      END_PARALLEL

      CUSTOM0(FIELD18A,OS_MANTADORY)
    END_SEQUENCE
  END_LOOP

  CUSTOM0(FIELD18A,OS_MANTADORY)
  O(FIELD79, srvrField79_Narrative)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT560)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 6 1

BEGIN_IMPLEMENT_SEQUENCE(MT561, "MT561 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)

  LOOP(LS_PUSHCOUNT, "date_place\0\0", 1, 1000) 
    M(FIELD31B, srvrField31B_DateTimeAndPlaceOfMeeting)

  CUSTOM0(FIELD18A,OS_MANTADORY)
  M(FIELD80A, srvrField80A_RegisteredNameAndPlaceOfCompany)

  BEGIN_LOOP(LS_PUSHCOUNT, "MT56instr\0\0", 1, 1000)
    M(FIELD35B, srvrField35B_IdentificationOfSecurities)

    BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
      BEGIN_PARALLEL(OS_MANTADORY,NULL)
        BEGIN_LOOP(LS_PUSHCOUNT, "MT56instr_a\0\0", 1, 1000)
          M(FIELD35A, srvrField35A_QuantityOfSecurities)
          M(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
        END_LOOP

        LOOP(LS_PUSHCOUNT, "MT56instr_a\0\0", 1, 1) 
           M(FIELD35A, srvrField35A_QuantityOfSecurities)
      END_PARALLEL

      CUSTOM0(FIELD18A,OS_MANTADORY)
    END_SEQUENCE

  END_LOOP

  CUSTOM0(FIELD18A,OS_MANTADORY)
  O(FIELD80B, srvrField80B_Proxy)
  O(FIELD79, srvrField79_Narrative)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT561)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 6 2

BEGIN_IMPLEMENT_SEQUENCE(MT562, "MT562 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  O(FIELD11RS, srvrField11a_MTAndDateOfTheOriginalInstruction)
  M(FIELD23_562, srvrField23_FurtherIdentification)
  O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)

  BEGIN_LOOP(OS_MANTADORY,"instr_acct55\0\0", 1, 1000)
    O(FIELD35A, srvrField35A_QuantityOfSecurities)
    M(FIELD35B, srvrField35B_IdentificationOfSecurities)

    BEGIN_LOOP(OS_MANTADORY,"derinstr_56\0\0", 0, 1000)
      M(FIELD35S, srvrField35S_QuantityOfSecuritiesDerived)
      M(FIELD35B, srvrField35B_IdentificationOfSecurities)
      O(FIELD32B, srvrField32B_SettlementAmount)
    END_LOOP
  END_LOOP

  O(FIELD79, srvrField79_Narrative)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT562)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 6 3

BEGIN_IMPLEMENT_SEQUENCE(MT563, "MT563 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  O(FIELD11RS, srvrField11a_MTAndDateOfTheOriginalInstructionOrNotice)
  M(FIELD23_563, srvrField23_FurtherIdentification)
  O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)

  BEGIN_LOOP(OS_MANTADORY,"MT563sb\0\0", 1, 1000)
    O(FIELD35A, srvrField35A_QuantityOfSecurities)
    M(FIELD35B, srvrField35B_IdentificationOfSecurities)

    BEGIN_LOOP(OS_MANTADORY,"MT563sb1\0\0", 0, 1000)
      M(FIELD35S, srvrField35S_QuantityOfSecuritiesDerived)
      M(FIELD35B, srvrField35B_IdentificationOfSecurities)
      O(FIELD31L, srvrField31L_DateSecuritiesToBeCredited)
      O(FIELD33B, srvrField33B_SubscriptionPrice)
      O(FIELD31S, srvrField31S_ParriPassuDate)
      O(FIELD35C, srvrField35C_CouponNumber)
      O(FIELD35D, srvrField35D_CouponDate)
      O(FIELD32B, srvrField32B_SettlementAmount)
      O(FIELD77D, srvrField77D_RegistrationDetails)
      O(FIELD77R, srvrField77R_LegalRestrictions)
      O(FIELD34GH, srvrField34a_AccruedInterest)
      O(FIELD33S, srvrField33S_SpecialConcessions)
      O(FIELD71C_MMLT, srvrField71C_OtherCharges)
      O(FIELD71B_MMLT, srvrField71B_OwnCharges)
      O(FIELD36, srvrField36_ExchangeRate)
      O(FIELD34A, srvrField34A_NetProceeds)
    END_LOOP
  END_LOOP

  O(FIELD53ACD, srvrField53a_AccountForPayment)
  O(FIELD71D, srvrField71D_AccountsForCharges)
  O(FIELD79, srvrField79_Narrative)
  O(FIELD30, srvrField30_DateOfExecution)
  O(FIELD77B, srvrField77B_OtherProceedsDerived)
  O(FIELD87EF, srvrField87a_ReceiverOfSecurities)
  O(FIELD88ACD, srvrField88a_BeneficiaryOfSecurities)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT563)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 7 0 - Request for Statement
/*
Scope:

This message type is normally sent by a financial institution to a Custodian. It may also be sent by a Financial Institution involved in a securities transaction to other interested parties. When it is used to request a statement of open orders (MT's 574 or 576), it may also be sent by a party which has issued order to buy/sell to the party which received the orders.
*/

BEGIN_IMPLEMENT_SEQUENCE(MT570, "MT570 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceA)
    M(FIELD20, srvrField20_TransactionReferenceNumber)
    M(FIELD12, srvrField12_MessageType)
    O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
    M(FIELD67A, srvrField67A_StatementPeriod)
  END_SEQUENCE

  LOOP(OS_MANTADORY,srvrMT570B, 0, 1000)
    BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceB)
      M(FIELD35B, srvrField35B_IdentificationOfSecurities)

      LOOP(OS_MANTADORY,srvrMT570B1, 0, 1000)
        BEGIN_PARALLEL(OS_MANTADORY,srvrSequenceB1)
          BEGIN_SEQUENCE(OS_MANTADORY,NULL)
            M(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
            O(FIELD23, srvrField23_FurtherIdentification)
          END_SEQUENCE
          M(FIELD23, srvrField23_FurtherIdentification)
        END_PARALLEL
    END_SEQUENCE

  LOOP(OS_MANTADORY,srvrMT570C, 0, 1000)
    BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceC)
      M(FIELD23, srvrField23_FurtherIdentification)
      LOOP(OS_MANTADORY,srvrMT570C1, 0, 1000)
        BEGIN_PARALLEL(OS_MANTADORY,srvrSequenceC1)
          BEGIN_SEQUENCE(OS_MANTADORY,NULL)
            M(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
            O(FIELD35B, srvrField35B_IdentificationOfSecurities)
          END_SEQUENCE
          M(FIELD35B, srvrField35B_IdentificationOfSecurities)
        END_PARALLEL
    END_SEQUENCE

  BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceD)
    O(FIELD72, srvrField72_SenderToReceiverInformation)
  END_SEQUENCE

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT570)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 7 1 - Statement of Holding
/*
Scope:

Thi message type is normally sent by a Custodian, to a financial institution for which it holds securities. It may also be sent by a Financial Institution involved in a sequrities transaction to other interested perties.
It lists, as at a specified date, the quantity and identification of the securities and , optionaly, other holdings, the Custodian holds for the Receiver or the Receiver's customer.
The statement may also include sequrities held by the Custodian with sub-Custodians.
*/

BEGIN_IMPLEMENT_SEQUENCE(MT571, "MT571 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceA)
    M(FIELD28, srvrField28_PageNumberAndContinuationIndicator)
    M(FIELD20, srvrField20_TransactionReferenceNumber)
    O(FIELD21, srvrField21_RelatedReference)
    M(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
    M(FIELD67A, srvrField67A_StatementPeriod)
    O(FIELD30, srvrField30_DatePrepared)
    O(FIELD26F, srvrField26F_StatementBasis)
  END_SEQUENCE

  LOOP(LS_PUSHCOUNT, srvrMT571B, 0, 1000)
    BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceB) 
      M(FIELD35H, srvrField35H_QuantityOfSecurities)

      BEGIN_LOOP(OS_MANTADORY,"MT571sub1\0\0", 0, 1000)
        M(FIELD60B, srvrField60B_QuantityOfSecurities)
        M(FIELD23_571, srvrField23_FurtherIdentification)
        O(FIELD72, srvrField72_SenderToReceiverInformation)
      END_LOOP

      M(FIELD35B, srvrField35B_IdentificationOfSecurities)
      O(FIELD33B, srvrField33B_PricePerUnit)
      O(FIELD34GH, srvrField34a_AccruedInterest)
      O(FIELD36, srvrField36_ExchangeRate)
      O(FIELD32H, srvrField32H_Value)
      O(FIELD72, srvrField72_SenderToReceiverInformation)
    END_SEQUENCE

  BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceC)
    CUSTOM0(FIELD18A,OS_MANTADORY)
    O(FIELD34E, srvrField34E_FinalValue)
    O(FIELD72, srvrField72_SenderToReceiverInformation)
  END_SEQUENCE

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT571)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 7 2 - Statement of Transactions
/*
Scope:

This message type is normally sent by a Custodian to a finansial institution for which it hold securities. It may also be sent by a Financial Instituiton involved in a securities transaction to other interested parties.
It provides the details of increases and decreases of holdings which occurred during a specified period, for all or selected securities in all or selected safekeeping accounts/sub-accounts which the Custodian holds for the Receiver or the Receiver's customer.
*/

BEGIN_IMPLEMENT_SEQUENCE(MT572, "MT572 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceA)
    M(FIELD28, srvrField28_PageNumberAndContinuationIndicator)
    M(FIELD20, srvrField20_TransactionReferenceNumber)
    O(FIELD21, srvrField21_RelatedReference)
    O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
    M(FIELD67A, srvrField67A_StatementPeriod)
    O(FIELD30, srvrField30_DatePrepared)
  END_SEQUENCE

  LOOP(LS_PUSHCOUNT, srvrMT572B, 0, 1000)
    BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceB)
      M(FIELD35B, srvrField35B_IdentificationOfSecurities)
      O(FIELD60A, srvrField60A_OpeningBalance)
      LOOP(OS_MANTADORY,srvrMT572B1, 0, 1000)
        BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceB1)
          O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
          O(FIELD60B, srvrField60B_OpeningBalance)
          LOOP(OS_MANTADORY,srvrMT572B2, 1, 1000)
            BEGIN_SEQUENCE(OS_MANTADORY, NULL)
              M(FIELD35A, srvrField35A_QuantityOfSecurities)
              M(FIELD66A, srvrField66A_TransactionDetails)
              O(FIELD87AD_CNTRP, srvrField87a_Counterparty)
              O(FIELD30, srvrField30_SettlementDate)
              O(FIELD33B, srvrField33B_PricePerUnit)
              O(FIELD34GH, srvrField34a_AccruedInterest)
              O(FIELD34CD, srvrField34a_Amount)
              O(FIELD72, srvrField72_SenderToReceiverInformation)
            END_SEQUENCE
          O(FIELD62B, srvrField62B_ClosingBalance)
         END_SEQUENCE
      O(FIELD62A, srvrField62A_ClosingBalance)
    END_SEQUENCE

  BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceC)
    CUSTOM0(FIELD18A,OS_MANTADORY)
    O(FIELD72, srvrField72_SenderToReceiverInformation)
  END_SEQUENCE

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT572)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 7 3 - Statement of Pending Transactions
/*
Scope:

This message type is normaly sent by a Custodian, to a financial institution for which it holds securities, i.e., a customer. It may also be sent by a Financial Institution involved in a securities transaction to other interested parties.
*/

BEGIN_IMPLEMENT_SEQUENCE(MT573, "MT573 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceA)
    M(FIELD28, srvrField28_PageNumberAndContinuationIndicator)
    O(FIELD20, srvrField20_TransactionReferenceNumber)
    O(FIELD21, srvrField21_RelatedReference)
    O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
    M(FIELD67A, srvrField67A_StatementPeriod)
    O(FIELD30, srvrField30_DatePrepared)
  END_SEQUENCE

  BEGIN_PARALLEL(OS_MANTADORY,NULL)
    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      LOOP(LS_PUSHCOUNT, srvrMT573B,  1, 1000)
        BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceB)
          M(FIELD35B, srvrField35B_IdentificationOfSecurities)
          LOOP(OS_MANTADORY, srvrMT573B1, 0, 1000)
            BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceB1)
              O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
              M(FIELD20, srvrField20_TransactionReferenceNumber)
              M(FIELD23_573, srvrField23_FurtherIdentification)
              O(FIELD11R, srvrField11a_MTAndDateOfTheOriginalInstruction)
              O(FIELD21, srvrField21_RelatedReference)
              M(FIELD35A, srvrField35A_QuantityOfSecurities)
              O(FIELD30, srvrField30_SettlementDate)
              O(FIELD32B, srvrField32B_SettlementAmount)
              O(FIELD87AD_CNTRP, srvrField87a_Counterparty)
              O(FIELD72, srvrField72_SenderToReceiverInformation)
            END_SEQUENCE
        END_SEQUENCE
      BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceD)
        CUSTOM0(FIELD18A,OS_MANTADORY)
        O(FIELD72, srvrField72_SenderToReceiverInformation)
      END_SEQUENCE
    END_SEQUENCE

    BEGIN_SEQUENCE(OS_MANTADORY,NULL)
      LOOP(LS_PUSHCOUNT, srvrMT573C, 1, 1000)
        BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceC)
          M(FIELD23_573, srvrField23_FurtherIdentification)
          LOOP(OS_MANTADORY, srvrMT573C1, 0, 1000)
            BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceC1)
              M(FIELD35B, srvrField35B_IdentificationOfSecurities)
              O(FIELD83ACD_SAFE, srvrField83a_SafekeepingAccount)
              M(FIELD20, srvrField20_TransactionReferenceNumber)
              O(FIELD11R, srvrField11a_MTAndDateOfTheOriginalInstruction)
              O(FIELD21, srvrField21_RelatedReference)
              M(FIELD35A, srvrField35A_QuantityOfSecurities)
              O(FIELD30, srvrField30_SettlementDate)
              O(FIELD32B, srvrField32B_SettlementAmount)
              O(FIELD87AD_CNTRP, srvrField87a_Counterparty)
              O(FIELD72, srvrField72_SenderToReceiverInformation)
            END_SEQUENCE
        END_SEQUENCE
      BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceD)
        CUSTOM0(FIELD18A,OS_MANTADORY)
        O(FIELD72, srvrField72_SenderToReceiverInformation)
      END_SEQUENCE
    END_SEQUENCE

    BEGIN_SEQUENCE(OS_MANTADORY,srvrSequenceD)
      STATIC(OS_MANTADORY,":18A:0\r\n")
      O(FIELD72, srvrField72_SenderToReceiverInformation)
    END_SEQUENCE
  END_PARALLEL

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT573)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 7 4 - Statement of Open Orders
/*
Scope:

This message type is sent by a financial institution which has accepted one or several orders to buy and/or sell securities, to the financial institution which has issued those orders.
*/

BEGIN_IMPLEMENT_SEQUENCE(MT574, "MT574 TEXT BLOCK")
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
          M(FIELD35A, srvrField35A_QuantityOfSecurities)
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
END_IMPLEMENT_SEQUENCE(MT574)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 7 6 - Statement of Open Orders
/*
Scope:

This message type is sent by an Executing Party (e.g., a Broker-Dealer) which has accepted one or several orders to buy or sell financial instruments to an Instructing Party (e.g., a Client) or its authorised agent. Where permitted this may also be sent by a point of execution (e.g., a Exchange) to list open orders.
*/

BEGIN_IMPLEMENT_SEQUENCE(MT576, "MT576 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD28B,srvrField28B_PageNumberAndContinuationIndicator)
  O(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21,srvrField21_RelatedReference)
  O(FIELD83ACD,srvrField83a_SafekeepingAccount)
  O(FIELD23T,srvrField23T_TypeOfSafekeeping)
  M(FIELD67S,srvrField67S_StatementPeriod)
  O(FIELD30P,srvrField30P_DatePrepared)
  O(FIELD14S,srvrField14S_TimeStamp)

  BEGIN_LOOP(OS_MANTADORY|LS_PUSHCOUNT,"\0\0",1,1000)
    M(FIELD35B,srvrField35B_IdentificationOfFinancialInstrument)
    LOOP(OS_MANTADORY,"\0\0",0,1000)
      M(FIELD25I,srvrField25I_FinancialInstrumentAttribute)
    BEGIN_LOOP(OS_MANTADORY,"\0\0",1,1000)
      O(FIELD83ACD,srvrField83a_SafekeepingAccount)
      O(FIELD23T,srvrField23T_TypeOfSafekeeping)
      M(FIELD20, srvrField20_TransactionReferenceNumber)
      O(FIELD23O,srvrField23O_BuyOrSellIndicator)
      M(FIELD21,srvrField21_RelatedReference)
      O(FIELD30B,srvrField30B_TimeLimitOrderOrExpiryDateOfOrder)
      O(FIELD32O,srvrField32O_PriceLimitOrTypeOfOrder)
      O(FIELD32X,srvrField32X_StopPrice)
      O(FIELD28L,srvrField28L_PriceLimitQualifier)
      LOOP(OS_MANTADORY,"\0\0",0,1000)
        M(FIELD25C,srvrField25C_TransactionCondition)
      M(FIELD35A,srvrField35A_QuantityOfTheFinancialInstrument)
      O(FIELD82ACD,srvrField82a_InstructingParty)
      O(FIELD84ACD,srvrField84a_ExecutingBroker)
      O(FIELD72,srvrField72_SenderToReceiverInformation)
    END_LOOP
  END_LOOP
  CUSTOM1(FIELD18A,OS_MANTADORY,NULL)
  O(FIELD72C,srvrField72C_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT576)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 7 7 - Statement of Numbers
/*
Scope:

This message type is sent by a Custodial to a financial institution for which ot holds securities.
It is used to provide certificate numbers of securities.
This is stand alone message and does not supplement any other message.
*/

BEGIN_IMPLEMENT_SEQUENCE(MT577, "MT577 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD28,srvrField28_PageNumberAndContinuationIndicator)
  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21,srvrField21_RelatedReference)
  O(FIELD83ACD,srvrField83a_SafekeepingAccount)
  M(FIELD67A,srvrField67A_StatementPeriod)
  O(FIELD35A,srvrField35A_QuantityOfSecurities)
  M(FIELD35B,srvrField35B_IdentificationOfSecurities)
  M(FIELD35F,srvrField35F_CertificateNumbers)
  O(FIELD72,srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT577)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 7 9 - Certificate Numbers
/*
Scope:

This message type is sent by Custodian to a financial institution for which it holds securities.
It is used only to replace or supplement the Certificate Numbers field (field 35E or 35F) in primary message and therefore  can be sent on the same day as that primary message.
*/

BEGIN_IMPLEMENT_SEQUENCE(MT579, "MT579 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD28,srvrField28_PageNumberAndContinuationIndicator)
  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21,srvrField21_RelatedReference)
  M(FIELD35F,srvrField35F_CertificateNumbers)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT579)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 8 0 - Instruction to an International Clearing System

BEGIN_IMPLEMENT_SEQUENCE(MT580, "MT580 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  O(FIELD20,srvrField20_TransactionReferenceNumber)

  BEGIN_LOOP(OS_MANTADORY,"\0\0",1,1000)
    M(FIELD23,srvrField23_FurtherIdentification)
    O(FIELD30,srvrField30_SettlementDate)
    M(FIELD20,srvrField20_TransactionReferenceNumber)
    O(FIELD21,srvrField21_RelatedReference)
    O(FIELD31P,srvrField31P_DateAndPlaceOfTrade)
    O(FIELD31T,srvrField31T_TimeOfTrade)
    O(FIELD26J,srvrField26J_PriorityRequested)
    M(FIELD35A,srvrField35A_QuantityOfSecurities)
    M(FIELD35B,srvrField35B_IdentificationOfSecurities)
    O(FIELD35E,srvrField35E_CertificateNumbers)
    O(FIELD82ACD,srvrField82a_InstructingParty)
    O(FIELD83R,srvrField83R_SendersRole)
    M(FIELD83C,srvrField83a_SafekeepingAccount)
    O(FIELD84A,srvrField84a_ClearingCorrespondent)
    M(FIELD87ACD,srvrField87a_ReceiverOrDelivererOfSecurities)
    O(FIELD85ACD,srvrField85a_DeliverersInstructingParty)
    O(FIELD88ACD,srvrField88a_BeneficiaryOfSecurities)
    O(FIELD57AD,srvrField57a_AccountWithInstitution)
    O(FIELD58AD,srvrField58a_BeneficiaryOfMoney)
    O(FIELD33T,srvrField33T_DealPrice)
    O(FIELD32M,srvrField32M_DealAmount)
    O(FIELD37J,srvrField37J_DealAmountExchangeRate)
    O(FIELD34GH,srvrField34a_AccruedInterest)
    O(FIELD37L,srvrField37L_AccruedInterestExchangeRate)
    O(FIELD37S,srvrField37S_AccruedInterestRateAndCalculationBasis)
    O(FIELD33S,srvrField33S_SpecialConcessions)
    O(FIELD37P,srvrField37P_SpecialConcessionsExchangeRate)
    O(FIELD32B,srvrField32B_SettlementAmount)
    O(FIELD26L,srvrField26L_FungibilityCode)
    O(FIELD26K,srvrField26K_DenominationChoice)
    O(FIELD77B,srvrField77B_FurtherInformation)
    O(FIELD77D,srvrField77D_RegistrationDetails)
    O(FIELD72,srvrField72_SenderToReceiverInformation)
    O(FIELD79,srvrField79_Narrative)
  END_LOOP

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT580)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 8 1 - Collateral Adjustment Message
/*
Note:

This message may only be sent and receive after prior arragements between the Sender and Receiver.

Scope:

This message type is sent from one financial institution to another, both of which are involved  in a securitiestransaction for which collaterad has been provided (e.g., a securities loan).
It is used to claim or notify an increase or decrease to the collateral amount resulting from a change in the value of the existing collateral amount relative to the securities on loan.
*/

BEGIN_IMPLEMENT_SEQUENCE(MT581, "MT581 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21,srvrField21_RelatedReference)
  M(FIELD23,srvrField23_FurtherIdentification)
  O(FIELD30,srvrField30_DateOfAdjustment)
  M(FIELD35H,srvrField35H_AdjustmentToTheCollateral)
  O(FIELD35B,srvrField35B_IdentificationOfSecuritiesUsedAsCollateral)
  M(FIELD80C,srvrField80C_ReasonForCollateralAdjustment)
  O(FIELD34B,srvrField34B_OutstandingCollateralValue)
  O(FIELD72,srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT581)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 8 2 - Reimbursement Claim or Advice
/*
Note:

This message may only be sent and receive after prior arragements between the Sender and Receiver.

Scope:

This message type  is sent by a financial institution to another financial institution both of which are involved in a securities transaction.
*/

BEGIN_IMPLEMENT_SEQUENCE(MT582, "MT582 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21,srvrField21_RelatedReference)
  M(FIELD23,srvrField23_FurtherIdentification)
  M(FIELD35A,srvrField35A_QuantityOfSecurities)
  M(FIELD35B,srvrField35B_IdentificationOfSecurities)
  O(FIELD79,srvrField79_Narrative)

  O(FIELD32G,srvrField32G_GrossAmountClaimedOrReceived)
  O(FIELD71B,srvrField71B_Charges)
  O(FIELD36,srvrField36_ExchangeRate)
  M(FIELD34A,srvrField34A_NetAmountClaimedOrPaid)
  O(FIELD53ACD,srvrField53a_AccountForPayment)
  O(FIELD56AD,srvrField56a_Intermediary)
  O(FIELD57ABD,srvrField57a_AccountWithInstitution)

  M(FIELD35S,srvrField35S_QuantityOfSecuritiesClaimedOrAdvised)
  M(FIELD35B,srvrField35B_IdentificationOfSecurities)
  O(FIELD83ACD,srvrField83a_SafekeepingAccount)
  O(FIELD87ABD,srvrField87a_ReceiverOrDelivererOfSecurities)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT582)

////////////////////////////////////////////////////////////////////////////////////
//    M T 5 8 3 - Depot Management Advice

BEGIN_IMPLEMENT_SEQUENCE(MT583, "MT583 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21,srvrField21_RelatedReference)
  O(FIELD11RS,srvrField11a_MTAndDateOfTheOriginalMessage)
  O(FIELD83ACD,srvrField83a_SafekeepingAccount)
  M(FIELD23,srvrField23_FurtherIdentification)

  BEGIN_LOOP(OS_MANTADORY,"\0\0",1,1000)
    O(FIELD83ACD,srvrField83a_SafekeepingAccount)
    O(FIELD35A,srvrField35A_QuantityOfSecurities)
    M(FIELD35B,srvrField35B_IdentificationOfSecurities)
    O(FIELD31F,srvrField31F_EffectiveDate)
    O(FIELD77D,srvrField77D_Narrative)
  END_LOOP

  O(FIELD72,srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT583)

////////////////////////////////////////////////////////////////////////////////////
//    M T n 9 0

BEGIN_IMPLEMENT_SEQUENCE(MTn90, "MTn90 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(FIELD25, srvrField25_AccountIdentification)
  M(FIELD32CD, srvrField32a_ValueDateCurrencyCodeAmount)
  O(FIELD52AD_ORD, srvrField52a_OrderingInstitution)
  M(FIELD71B, srvrField71B_DetailsOfCharges)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MTn90)

////////////////////////////////////////////////////////////////////////////////////
//    M T n 9 1

BEGIN_IMPLEMENT_SEQUENCE(MTn91, "MTn91 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(FIELD32B, srvrField32B_CurrencyCodeAmount)
  O(FIELD52AD_ORD, srvrField52a_OrderingInstitution)
  O(FIELD57ABD_IN, srvrField57a_AccountWithInstitution)
  M(FIELD71B, srvrField71B_DetailsOfCharges)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MTn91)

////////////////////////////////////////////////////////////////////////////////////
//    M T n 9 2

BEGIN_IMPLEMENT_SEQUENCE(MTn92, "MTn92 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(FIELD11S, srvrField11a_MTAndDateOfOriginalMessage)
  O(FIELD79, srvrField79_NarrativeDescriptionOfTheOriginalMessage)

  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    MULTITEXT(OS_MANTADORY, hCopyOfTheOriginalMessage, 1, 1000, COPY_TEXT, EOL,  "\r\n-%n\0")
    STATIC(OS_MANTADORY,EOL)
  END_SEQUENCE

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MTn92)


////////////////////////////////////////////////////////////////////////////////////
//    M T n 9 5

BEGIN_IMPLEMENT_SEQUENCE(MTn95, "MTn95 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(MTn9X_FIELD75, srvrField75_Queries)
  O(FIELD77A, srvrField77A_Narrative)
  M(FIELD11RS, srvrField11a_MTAndDateOfOriginalMessage)
  O(FIELD79, srvrField79_Narrative)

  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    MULTITEXT(OS_MANTADORY, hCopyOfTheOriginalMessage, 1, 1000, COPY_TEXT, EOL,  "\r\n-%n\0")
    STATIC(OS_MANTADORY,EOL)
  END_SEQUENCE

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MTn95)

////////////////////////////////////////////////////////////////////////////////////
//    M T n 9 6

BEGIN_IMPLEMENT_SEQUENCE(MTn96, "MTn96 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(FIELD76_n96, srvrField76_Answers)
  O(FIELD77A, srvrField77A_Narrative)
  M(FIELD11RS, srvrField11a_MTAndDateOfOriginalMessage)
  O(FIELD79, srvrField79_NarrativeDescriptionOfOriginalMessageToWhichTheAnswerRelates)

  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    MULTITEXT(OS_MANTADORY, hCopyOfTheOriginalMessage, 1, 1000, COPY_TEXT, EOL,  "\r\n-%n\0")
    STATIC(OS_MANTADORY,EOL)
  END_SEQUENCE

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MTn96)

////////////////////////////////////////////////////////////////////////////////////
//    M T n 9 8

BEGIN_IMPLEMENT_SEQUENCE(MTn98, "MTn98 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD12, srvrField12_SubMessageType)
  O(FIELD77E, srvrField77E_ProprietaryMessage)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MTn98)


////////////////////////////////////////////////////////////////////////////////////
//    M T n 9 9

BEGIN_IMPLEMENT_SEQUENCE(MTn99, "MTn99 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  O(FIELD21, srvrField21_RelatedReference)
  M(FIELD79, srvrField79_Narrative)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MTn99)

////////////////////////////////////////////////////////////////////////////////////
//    M T 9 0 0

BEGIN_IMPLEMENT_SEQUENCE(MT900, "MT900 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(FIELD25, srvrField25_AccountIdentification)
  M(FIELD32A, srvrField32A_ValueDateCurrencyCodeAmount)
  O(FIELD52AD_ORD, srvrField52a_OrderingInstitution)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT900)

////////////////////////////////////////////////////////////////////////////////////
//    M T 9 1 0

BEGIN_IMPLEMENT_SEQUENCE(MT910, "MT910 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(FIELD25, srvrField25_AccountIdentification)
  M(FIELD32A, srvrField32A_ValueDateCurrencyCodeAmount)
  M(FIELD52AD_ORD, srvrField52a_OrderingInstitution)
  O(FIELD56AD, srvrField56a_Intermediary)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT910)

////////////////////////////////////////////////////////////////////////////////////
//    M T 1 0 0

BEGIN_IMPLEMENT_SEQUENCE(MT100, "MT100 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD32A, srvrField32A_ValueDateCurrencyCodeAmount)
  M(FIELD50, srvrField50_OrderingCustomer)
  O(FIELD52AD_ORD, srvrField52a_OrderingInstitution)
  O(FIELD53ABD_SCOR, srvrField53a_SendersCorrespondent)
  O(FIELD54ABD_RCOR, srvrField54a_ReceiversCorrespondent)
  O(FIELD56AD, srvrField56a_Intermediary)
  O(FIELD57ABD_IN, srvrField57a_AccountWithInstitution)
  //M(FIELD59, srvrField59_BeneficiaryCustomer)
  //O(FIELD70, srvrField70_DetailsOfPayment)
  //O(FIELD71A, srvrField71A_DetailsOfCharges)
   O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT100)

////////////////////////////////////////////////////////////////////////////////////

//    M T 1 0 2

BEGIN_IMPLEMENT_SEQUENCE(MT102, "MT102 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  //M(FIELD23, srvrField23_BankOperationCode)
  //M(FIELD51A, srvrField51a_SendingInstitution)
  //M(FILED50, srvrField50_OrderingCustomer)
  //O(FIELD52ABC, srvrField52a_OrderingInstitution)
  //O(FIELD26T, srvrField26T_TransactionTypeCode)
  O(FIELD77B, srvrField77B_RegulatoryReporting)
  //O(FIELD71A, srvrField71A_DetailsOfCharges)
  O(FIELD36, srvrField36_ExchangeRate)

  //BEGIN_LOOP()
    M(FIELD21, srvrField21_RelatedReference)
    //M(FIELD32B, srvrField32B_SettlementAmount)
    //M(FIELD50, srvrField50_OrderingCustomer)
    //O(FIELD52ABC, srvrField52a_OrderingInstitution)
    //O(FIELD57AC, srvrField57a_AccountWithInstitution)
    //M(FIELD59, srvrField59_BeneficiaryCustomer)
    //O(FIELD70, srvrField70_RemittanceInformation)
    //O(FIELD26T, srvrField26T_TransactionTypeCode)
    //O(FIELD77B, srvrField77B_RegulatoryReporting)
    //O(FIELD33B, srvrField33B_OriginalOrderedAmount)
    //O(FIELD71A, srvrField71A_DetailsOfCharges)
    //O(FIELD71F, srvrField71F_SendersChargesOrAmount)
    //O(FIELD71G, srvrField71G_ReceiversChargesOrAmount)
    O(FIELD36, srvrField36_ExchangeRate)
  //END_LOOP

  //M(FIELD32A, srvrField32A_ValueDateCurrencyCodeAmount)
  //O(FIELD19, srvrField19_SumOfAmount)
  O(FIELD71F, srvrField71F_SumOfSendersChargesOrAmount)
  //O(FIELD71G, srvr71G_SumOfReceiversChargesOrAmount)
  //O(FIELD53AC, srvrField53a_SendersCorrespondent)
  //O(FIELD54A, srvrField54a_ReceiversCorrespondent)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT102)

////////////////////////////////////////////////////////////////////////////////////

//    M T 2 0 2

BEGIN_IMPLEMENT_SEQUENCE(MT202, "MT202 TEXT BLOCK")
  STATIC(OS_MANTADORY,SOT)

  M(FIELD20, srvrField20_TransactionReferenceNumber)
  M(FIELD21, srvrField21_RelatedReference)
  M(FIELD32A, srvrField32A_ValueDateCurrencyCodeAmount)
  O(FIELD52AD_ORD, srvrField52a_OrderingInstitution)
  O(FIELD53ABD_SCOR, srvrField53a_SendersCorrespondent)
  O(FIELD54ABD_RCOR, srvrField54a_ReceiversCorrespondent)

  BEGIN_SEQUENCE(OS_OPTIONAL,NULL)
    O(FIELD56AD, srvrField56a_Intermediary)
    M(FIELD57ABD_IN, srvrField57a_AccountWithInstitution)
  END_SEQUENCE

  M(FIELD58AD_BEN, srvrField58a_BeneficiaryInstitution)
  O(FIELD72, srvrField72_SenderToReceiverInformation)

  STATIC(OS_MANTADORY,EOT)
END_IMPLEMENT_SEQUENCE(MT202)

////////////////////////////////////////////////////////////////////////////////////


