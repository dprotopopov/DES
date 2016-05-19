#ifndef __UNEISRV_H
#define __UNEISRV_H

DECLARE_SERVER(srvrUMT592M)
DECLARE_SERVER(srvrUMT598M)

DECLARE_SERVER(srvrUneiField20_MT572TransactionReferenceNumber)                   
DECLARE_SERVER(srvrUneiField67A_MT572StatementPeriod)                   

/////////////////////////////////////////////

DECLARE_SERVER(srvrUneiField20_SendersReference)                   
DECLARE_SERVER(srvrUneiField20_CashSystemReference)                
DECLARE_SERVER(srvrUneiField20F_TheFilesReference)                 
DECLARE_SERVER(srvrUneiField21_CustodySystemReference)             
DECLARE_SERVER(srvrUneiField21_RelatedReference)                   
DECLARE_SERVER(srvrUneiField32A_ValueDateCurrencyAmount)           
DECLARE_SERVER(srvrUneiField32A_TransactionAmount)                 
DECLARE_SERVER(srvrUneiField32C_TheBankingCommisionAmount)         
DECLARE_SERVER(srvrUneiField32F_ControlAmount)                     
DECLARE_SERVER(srvrUneiField32T_TheAmountOfTheTransmissionExpenses)
DECLARE_SERVER(srvrUneiField32K_NumberOfMessagesInTheFile)  
DECLARE_SERVER(srvrUneiField52a_InstructingPartysBank)      
DECLARE_SERVER(srvrUneiField54a_ReceiversCorrespondentBank) 
DECLARE_SERVER(srvrUneiField56a_Intermediary)               
DECLARE_SERVER(srvrUneiField57a_BeneficiarysBank)           
DECLARE_SERVER(srvrUneiField70_PaymentDetails)              
DECLARE_SERVER(srvrUneiField71_ExpenseDetails)              
DECLARE_SERVER(srvrUneiField72_SenderToReceiverInformation) 

DECLARE_SERVER(srvrUneiField25a_InstructingParty)                            
DECLARE_SERVER(srvrUneiField25a_Beneficiary)                             
DECLARE_SERVER(srvrUneiField5X_InstructingParty)           
DECLARE_SERVER(srvrUneiField5X_Beneficiary)                 

DECLARE_SERVICE(hUneiField20_Reference)
DECLARE_SERVICE(hUneiField20F_Reference)
DECLARE_SERVICE(hUneiField21_Reference)
DECLARE_SERVICE(hUneiField32a_PayerOrBeneficiary)
DECLARE_SERVICE(hUneiField32a_Date)     
DECLARE_SERVICE(hUneiField32a_CurrencyCode)     
DECLARE_SERVICE(hUneiField32a_Amount)           
DECLARE_SERVICE(hUneiField70_Narrative)           
DECLARE_SERVICE(hUneiField71_Narrative)           
DECLARE_SERVICE(hUneiField72_Narrative)           

DECLARE_SERVICE(hUneiField25a_AccountNumber) 
DECLARE_SERVICE(hUneiField5X_AccountNumber)
DECLARE_SERVICE(hUneiField5X_NameAndAddress)

DECLARE_SERVICE(hUneiFieldXXa_CreditedOrDebitedAccount)
DECLARE_SERVICE(hUneiFieldXXa_AccountNumber)
DECLARE_SERVICE(hUneiFieldXXa_BankIdentifierCode)
DECLARE_SERVICE(hUneiFieldXXa_BranchIdentificationOrNameAndAddress)

/////////////////////////////////////////////

DECLARE_SERVICE(hUneiField_MessageType)
DECLARE_SERVICE(hUneiField_TradeDate)
DECLARE_SERVICE(hUneiField_MT570TradeDate)
DECLARE_SERVICE(hUneiField_MT570TransactionReferenceNumber)
DECLARE_SERVICE(hUneiField_MT572TransactionReferenceNumber)
DECLARE_SERVICE(hUneiField_MT572TradeDate)
DECLARE_SERVICE(hUneiField_MT574TransactionReferenceNumber)

#endif __UNEISRV_H