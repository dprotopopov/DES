#include "srv.h"
#include "uneisrv.h"

IMPLEMENT_SERVER(srvrUMT592M, "MT592_unx_micex\0\0")
IMPLEMENT_SERVER(srvrUMT598M, "mt598_unx_micex\0\0")

IMPLEMENT_SERVER(srvrUneiField20_MT572TransactionReferenceNumber,     ":20:/MT 572 TRANSACTION REFERENCE NUMBER/")
IMPLEMENT_SERVER(srvrUneiField67A_MT572StatementPeriod,               ":67A:/MT 572 STATEMENT PERIOD/")

//////////////////////////////////////////////////////////////////////////

IMPLEMENT_SERVER(srvrUneiField20_SendersReference,                    ":20:/SENDERS REFERENCE/")
IMPLEMENT_SERVER(srvrUneiField20_CashSystemReference,                 ":20:/CASH SYSTEM REFERENCE/")
IMPLEMENT_SERVER(srvrUneiField20F_TheFilesReference,                  ":20F:/THE FILE'S REFERENCE/")
IMPLEMENT_SERVER(srvrUneiField21_CustodySystemReference,              ":21:/CUSTODY SYSTEM REFERENCE/")
IMPLEMENT_SERVER(srvrUneiField21_RelatedReference,                    ":21:/RELATED REFERENCE/")
IMPLEMENT_SERVER(srvrUneiField32A_ValueDateCurrencyAmount,            ":32A:/VALUE DATE, CURRENCY, AMOUNT/")
IMPLEMENT_SERVER(srvrUneiField32A_TransactionAmount,                  ":32A:/TRANSACTION AMOUNT/")
IMPLEMENT_SERVER(srvrUneiField32C_TheBankingCommisionAmount,          ":32C:/THE BANKING COMMISION AMOUNT/")
IMPLEMENT_SERVER(srvrUneiField32F_ControlAmount,                      ":32F:/CONTROL AMOUNT/")
IMPLEMENT_SERVER(srvrUneiField32T_TheAmountOfTheTransmissionExpenses, ":32T:/THE AMOUNT OF THE TRANSMISSION EXPENSES/")
IMPLEMENT_SERVER(srvrUneiField32K_NumberOfMessagesInTheFile,          ":32K:/NUMBER OF MESSAGES IN THE FILE/")
IMPLEMENT_SERVER(srvrUneiField52a_InstructingPartysBank,              ":52a:/INSTRUCTING PARTY'S BANK/")
IMPLEMENT_SERVER(srvrUneiField54a_ReceiversCorrespondentBank,         ":54a:/RECEIVERS CORRESPONDENT BANK/")
IMPLEMENT_SERVER(srvrUneiField56a_Intermediary,                       ":56a:/INTERMEDIARY/")
IMPLEMENT_SERVER(srvrUneiField57a_BeneficiarysBank,                   ":57a:/BENEFICIARY'S BANK/")
IMPLEMENT_SERVER(srvrUneiField70_PaymentDetails,                      ":70:/PAYMENT DETAILS/")
IMPLEMENT_SERVER(srvrUneiField71_ExpenseDetails,                      ":71:/EXPENSE DETAILS/")
IMPLEMENT_SERVER(srvrUneiField72_SenderToReceiverInformation,         ":72:/SENDER TO RECEIVER INFORMATION/")

IMPLEMENT_SERVER(srvrUneiField25a_InstructingParty,                   ":25a:/INSTRUCTING PARTY/")
IMPLEMENT_SERVER(srvrUneiField25a_Beneficiary,                        ":25a:/BENEFICIARY/")
IMPLEMENT_SERVER(srvrUneiField5X_InstructingParty,                    ":5X:/INSTRUCTING PARTY/")
IMPLEMENT_SERVER(srvrUneiField5X_Beneficiary,                         ":5X:/BENEFICIARY/")

IMPLEMENT_SERVICE(hUneiField20_Reference,             ":20:/REFERENCE/") 
IMPLEMENT_SERVICE(hUneiField20F_Reference,            ":20F:/REFERENCE/") 
IMPLEMENT_SERVICE(hUneiField21_Reference,             ":21:/REFERENCE/") 
IMPLEMENT_SERVICE(hUneiField32a_PayerOrBeneficiary,   ":32a:/PAYER OR BENEFICIARY/") 
IMPLEMENT_SERVICE(hUneiField32a_Date,                 ":32a:/DATE/") 
IMPLEMENT_SERVICE(hUneiField32a_CurrencyCode,         ":32a:/CURRENCY CODE/") 
IMPLEMENT_SERVICE(hUneiField32a_Amount,               ":32a:/AMOUNT/") 
IMPLEMENT_SERVICE(hUneiField70_Narrative,             ":70:/NARRATIVE/") 
IMPLEMENT_SERVICE(hUneiField71_Narrative,             ":71:/NARRATIVE/") 
IMPLEMENT_SERVICE(hUneiField72_Narrative,             ":72:/NARRATIVE/") 

IMPLEMENT_SERVICE(hUneiField25a_AccountNumber,        ":25a:/ACCOUNT NUMBER/") 
IMPLEMENT_SERVICE(hUneiField5X_AccountNumber,         ":5X:/ACCOUNT NUMBER/")
IMPLEMENT_SERVICE(hUneiField5X_NameAndAddress,        ":5X:/NAME AND ADDRESS/")

IMPLEMENT_SERVICE(hUneiFieldXXa_CreditedOrDebitedAccount,  ":XXa:/CREDITED OR DEBITED ACCOUNT/")
IMPLEMENT_SERVICE(hUneiFieldXXa_AccountNumber,             ":XXa:/ACCOUNT NUMBER/")
IMPLEMENT_SERVICE(hUneiFieldXXa_BankIdentifierCode,        ":XXa:/BANK IDENTIFIER CODE/")
IMPLEMENT_SERVICE(hUneiFieldXXa_BranchIdentificationOrNameAndAddress,":XXa:/BRANCH IDENTIFICATION OR NAME AND ADDRESS/")

IMPLEMENT_SERVICE(hUneiField_MessageType,                     ":/MESSAGE TYPE/")
IMPLEMENT_SERVICE(hUneiField_TradeDate,                       ":/TRADE DATE/")
IMPLEMENT_SERVICE(hUneiField_MT570TradeDate,                  ":/MT 570 TRADE DATE/")
IMPLEMENT_SERVICE(hUneiField_MT570TransactionReferenceNumber, ":/MT 570 TRANSACTION REFERENCE NUMBER/")
IMPLEMENT_SERVICE(hUneiField_MT572TradeDate,                  ":/MT 572 TRADE DATE/")
IMPLEMENT_SERVICE(hUneiField_MT572TransactionReferenceNumber, ":/MT 572 TRANSACTION REFERENCE NUMBER/")
IMPLEMENT_SERVICE(hUneiField_MT574TransactionReferenceNumber, ":/MT 574 TRANSACTION REFERENCE NUMBER/")
