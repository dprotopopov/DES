//////////////////////////////////
// System level dependencies

#include <windows.h>
#include <sql.h>
#include <sqlext.h>

//////////////////////////////////
// ANSI level dependencies

//////////////////////////////////
// Application level dependencies

#include "odbcbind.h"
#include "srv.h"
#include "swiftsrv.h"
#include "uneisrv.h"

/////////////////////////////////

char *SecondaryNames[] = {
	"seq_num",
	"subseq_num",
	"ssubseq_num"
};

char *SecondaryNames572[] = {
	"seq_num",
	"sub_seq_num",
	"ssub_seq_num"
};


////////////////////////////////////////////////////////////////////////////////////////////////
// ODBC BIND IMPLEMENTATION

////////////////////////////////////////////////////////////////////////////////////////////////
// SWIFT_DB

BEGIN_REGISTER(SWIFT_DB)
  REGISTER_SERVER("accounts",       ACCOUNTS_SERVER,      SecondaryNames)

  REGISTER_SERVER("charges_71",     CHARGES_71BCD_SERVER, SecondaryNames)
  REGISTER_SERVER("charges_71mult", CHARGES_71BCD_SERVER, SecondaryNames)
  REGISTER_SERVER("charges_71mmlt", CHARGES_71BCD_SERVER, SecondaryNames)

  REGISTER_SERVER("instr_acct",      INSTR_ACCT_SERVER,      SecondaryNames)
  REGISTER_SERVER("instr_acct55",    INSTR_ACCT55_SERVER,    SecondaryNames)
  REGISTER_SERVER("derinstr_acct55", DERINSTR_ACCT55_SERVER, SecondaryNames)
  REGISTER_SERVER("derinstr_56",     DERINSTR_56_SERVER,     SecondaryNames)
  REGISTER_SERVER("date_place",      DATE_PLACE_SERVER,      SecondaryNames)
  REGISTER_SERVER("amount_added", AMOUNT_ADDED_SERVER, SecondaryNames)
  REGISTER_SERVER("queries",      QUERIES_SERVER,      SecondaryNames)
  REGISTER_SERVER("answers",      ANSWERS_SERVER,      SecondaryNames)

  REGISTER_SERVER("message_desc", MESSAGE_DESC_SERVER, SecondaryNames)

  REGISTER_SERVER("MT520",       MT520_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT521",       MT521_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT522",       MT522_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT523",       MT523_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT530",       MT530_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT531",       MT531_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT532",       MT532_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT533",       MT533_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT534",       MT534_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT550",       MT550_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT551",       MT551_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT552",       MT552_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT553",       MT553_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT554",       MT554_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT554sub",    MT554SUB_SERVER,  SecondaryNames)
  REGISTER_SERVER("MT555",       MT555_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT556",       MT556_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT557",       MT557_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT559",       MT559_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT559sub",    MT559SUB_SERVER,  SecondaryNames)
  REGISTER_SERVER("MT560",       MT560_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT561",       MT561_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT562",       MT562_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT563",       MT563_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT563sb",     MT563SB_SERVER,   SecondaryNames)
  REGISTER_SERVER("MT563sb1",    MT563SB1_SERVER,  SecondaryNames)
  REGISTER_SERVER("MT56instr",   MT56INSTR_SERVER, SecondaryNames)
  REGISTER_SERVER("MT56instr_a", MT56INSTR_A_SERVER, SecondaryNames)
  REGISTER_SERVER("MT570",       MT570_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT570subB",   MT570SUBB_SERVER, SecondaryNames)
  REGISTER_SERVER("MT570subC",   MT570SUBC_SERVER, SecondaryNames)
  REGISTER_SERVER("MT570subB1",  MT570SUBB1_SERVER, SecondaryNames)
  REGISTER_SERVER("MT570subC1",  MT570SUBC1_SERVER, SecondaryNames)
  REGISTER_SERVER("MT571",       MT571_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT571sub",    MT571SUB_SERVER,  SecondaryNames)
  REGISTER_SERVER("MT571sub1",   MT571SUB1_SERVER, SecondaryNames)
  REGISTER_SERVER("MT572",       MT572_SERVER,     SecondaryNames572)
  REGISTER_SERVER("MT572sub",    MT572SUB_SERVER,  SecondaryNames572)
  REGISTER_SERVER("MT572sub1",   MT572SUB1_SERVER, SecondaryNames572)
  REGISTER_SERVER("MT572sub2",   MT572SUB2_SERVER, SecondaryNames572)
  REGISTER_SERVER("MT573",       MT573_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT573subB",   MT573SUBB_SERVER, SecondaryNames)
  REGISTER_SERVER("MT573subC",   MT573SUBC_SERVER, SecondaryNames)
  REGISTER_SERVER("MT573subB1",  MT573SUBB1_SERVER, SecondaryNames)
  REGISTER_SERVER("MT573subC1",  MT573SUBC1_SERVER, SecondaryNames)
  REGISTER_SERVER("MT574",       MT574_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT574sub",    MT574SUB_SERVER,  SecondaryNames)
  REGISTER_SERVER("MT574sub1",   MT574SUB1_SERVER, SecondaryNames)
  REGISTER_SERVER("MT590",       MTn90_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT591",       MTn91_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT592",       MTn92_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT595",       MTn95_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT596",       MTn96_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT598",       MTn98_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT599",       MTn99_SERVER,     SecondaryNames)

  REGISTER_SERVER("MT202",       MT202_SERVER,     SecondaryNames)

  REGISTER_SERVER("MT900",       MT900_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT910",       MT910_SERVER,     SecondaryNames)
END_REGISTER(SWIFT_DB)

////////////////////////////////////////////////////////////////////////////////////////////////
// UNEI_DB

BEGIN_REGISTER(UNEI_DB)
  REGISTER_SERVER("accounts",       ACCOUNTS_SERVER,      SecondaryNames)
  REGISTER_SERVER("charges_71",     CHARGES_71BCD_SERVER, SecondaryNames)
  REGISTER_SERVER("charges_71mult", CHARGES_71BCD_SERVER, SecondaryNames)
  REGISTER_SERVER("charges_71mmlt", CHARGES_71BCD_SERVER, SecondaryNames)
  REGISTER_SERVER("date_place",      DATE_PLACE_SERVER,      SecondaryNames)
  REGISTER_SERVER("amount_added", AMOUNT_ADDED_SERVER, SecondaryNames)

  REGISTER_SERVER("message_desc", MESSAGE_DESC_SERVER, SecondaryNames)

  REGISTER_SERVER("MT202",           UMT202_SERVER,      SecondaryNames)
END_REGISTER(UNEI_DB)

BEGIN_REGISTER(MICEX_DB)
  REGISTER_SERVER("accounts",       ACCOUNTS_SERVER,      SecondaryNames)
  REGISTER_SERVER("charges_71",     CHARGES_71BCD_SERVER, SecondaryNames)
  REGISTER_SERVER("charges_71mult", CHARGES_71BCD_SERVER, SecondaryNames)
  REGISTER_SERVER("charges_71mmlt", CHARGES_71BCD_SERVER, SecondaryNames)
  REGISTER_SERVER("instr_acct",      INSTR_ACCT_SERVER,      SecondaryNames)
  REGISTER_SERVER("instr_acct55",    INSTR_ACCT55_SERVER,    SecondaryNames)
  REGISTER_SERVER("derinstr_acct55", DERINSTR_ACCT55_SERVER, SecondaryNames)
  REGISTER_SERVER("derinstr_56",     DERINSTR_56_SERVER,     SecondaryNames)
  REGISTER_SERVER("date_place",      DATE_PLACE_SERVER,      SecondaryNames)
  REGISTER_SERVER("amount_added", AMOUNT_ADDED_SERVER, SecondaryNames)
  REGISTER_SERVER("queries",      QUERIES_SERVER,      SecondaryNames)
  REGISTER_SERVER("answers",      ANSWERS_SERVER,      SecondaryNames)

  REGISTER_SERVER("message_desc", MESSAGE_DESC_SERVER, SecondaryNames)

  REGISTER_SERVER("MT570",           MT570_SERVER,       SecondaryNames)
  REGISTER_SERVER("MT570subB",       MT570SUBB_SERVER, SecondaryNames)
  REGISTER_SERVER("MT570subC",       MT570SUBC_SERVER, SecondaryNames)
  REGISTER_SERVER("MT570subB1",      MT570SUBB1_SERVER, SecondaryNames)
  REGISTER_SERVER("MT570subC1",      MT570SUBC1_SERVER, SecondaryNames)
  REGISTER_SERVER("MT572",           MT572_SERVER,       SecondaryNames)
  REGISTER_SERVER("MT572sub",        MT572SUB_SERVER,  SecondaryNames572)
  REGISTER_SERVER("MT572sub1",       MT572SUB1_SERVER, SecondaryNames572)
  REGISTER_SERVER("MT572sub2",       MT572SUB2_SERVER, SecondaryNames572)
  REGISTER_SERVER("MT574",           MT574_SERVER,       SecondaryNames)
  REGISTER_SERVER("MT574sub",        MT574SUB_SERVER,  SecondaryNames)
  REGISTER_SERVER("MT574sub1",       MT574SUB1_SERVER, SecondaryNames)
  REGISTER_SERVER("MT592",           MTn92_SERVER,       SecondaryNames)
  REGISTER_SERVER("MT592_unx_micex", MT592UM_SERVER,     SecondaryNames)
  REGISTER_SERVER("MT598",           MTn98_SERVER,       SecondaryNames)
  REGISTER_SERVER("mt598_unx_micex", MT598UM_SERVER,     SecondaryNames)
END_REGISTER(MICEX_DB)

////////////////////////////////////////////////////////////////////////////////////////////////
// MESSAGE_DESC_SERVER

BEGIN_ODBCBIND(MESSAGE_DESC_SERVER)
  ODBCBIND(NULL, hHeader_Sender,         0, "sender",      "?", "sender",     SQL_C_CHAR,       SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hHeader_Receiver,       0, "receiver",    "?", "receiver",   SQL_C_CHAR,       SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hHeader_SessionNumber,  0, "msg_session", "?", "0",          SQL_C_SLONG,      SQL_CHAR,      4,   0, sizeof(SLONG))
  ODBCBIND(NULL, hHeader_SequenceNumber, 0, "msg_seq_num", "?", "0",          SQL_C_SLONG,      SQL_CHAR,      6,   0, sizeof(SLONG))
  ODBCBIND(NULL, hHeader_MessageType,    0, "msg_type",    "?", "msg_type",   SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hHeader_MessageDate,    0, "msg_d",       "?", "msg_d",      SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
END_ODBCBIND(MESSAGE_DESC_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// ACCOUNTS_SERVER

BEGIN_ODBCBIND(ACCOUNTS_SERVER)
  ODBCBIND(NULL, hFieldXXa_CodeWord,                 0, "party",     "?", "party",                 SQL_C_CHAR, SQL_CHAR,    4,   0, 4)
  ODBCBIND(NULL, hFieldXXa_CreditedOrDebitedAccount, 0, "crdr_f",    "?", "crdr_f",                SQL_C_CHAR, SQL_CHAR,    1,   0, 1)
  ODBCBIND(NULL, hFieldXXa_BankIdentifierCode,       0, "bic",       "?", "bic",                   SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(NULL, hFieldXXa_AccountNumber,            0, "acc_name",  "?", "{fn RTRIM(acc_name)}",  SQL_C_CHAR, SQL_VARCHAR, 34,  0, 34)
  ODBCBIND(NULL, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "name_addr", "?", "{fn RTRIM(name_addr)}", SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(ACCOUNTS_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// INSTR_ACCT_SERVER

BEGIN_ODBCBIND(INSTR_ACCT_SERVER)
  ODBCBIND(NULL, hField35A_CodeWord,                  0, "instr_cdw35a_c", "?", "instr_cdw35a_c",             SQL_C_CHAR, SQL_CHAR,    3,   0, 3)
  ODBCBIND(NULL, hField35A_Quantity,                  0, "instr_units_q",  "?", "instr_units_q",              SQL_C_CHAR, SQL_DECIMAL, 18,  3, 15)
  ODBCBIND(NULL, hField35E_SpecificationOfSecurities, 0, "sert_num_txt",   "?", "{fn RTRIM(sert_num_txt)}",   SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
  ODBCBIND(NULL, hFieldXXa_CreditedOrDebitedAccount,  0, "safe_crdr_f",    "?", "safe_crdr_f",                SQL_C_CHAR, SQL_CHAR,    1,   0, 1)
  ODBCBIND(NULL, hFieldXXa_BankIdentifierCode,        0, "safe_bic",       "?", "safe_bic",                   SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(NULL, hFieldXXa_AccountNumber,             0, "safe_acct_name", "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR, SQL_VARCHAR, 34,  0, 34)
  ODBCBIND(NULL, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namadd",    "?", "{fn RTRIM(safe_namadd)}",    SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(INSTR_ACC_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// INSTR_ACCT55_SERVER

BEGIN_ODBCBIND(INSTR_ACCT55_SERVER)
  ODBCBIND(NULL, hField35A_CodeWord,                 0, "instr_cdw35a_c", "?", "instr_cdw35a_c",         SQL_C_CHAR, SQL_CHAR,    3,   0, 3)
  ODBCBIND(NULL, hField35A_Quantity,                 0, "instr_units_q",  "?", "instr_units_q",          SQL_C_CHAR, SQL_DECIMAL, 18,  3, 15)
  ODBCBIND(NULL, hField35B_ISIN,                     0, "instr_isin",     "?", "instr_isin",             SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity, 0, "instr_desc",     "?", "{fn RTRIM(instr_desc)}", SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(INSTR_ACCT55_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// DERINSTR_ACCT55_SERVER

BEGIN_ODBCBIND(DERINSTR_ACCT55_SERVER)
  ODBCBIND(NULL, hField35B_ISIN,                     0, "instr_isin",     "?", "instr_isin",             SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity, 0, "instr_desc",     "?", "{fn RTRIM(instr_desc)}", SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
  ODBCBIND(NULL, hField35S_CodeWord,                 0, "instr_cdw35a_c", "?", "instr_cdw35a_c",         SQL_C_CHAR, SQL_CHAR,    3,   0, 3)
  ODBCBIND(NULL, hField35S_Quantity,                 0, "instr_units_q",  "?", "instr_units_q",          SQL_C_CHAR, SQL_DECIMAL, 18,  3, 15)
END_ODBCBIND(DERINSTR_ACCT55_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// DERINSTR_56_SERVER

BEGIN_ODBCBIND(DERINSTR_56_SERVER)
  ODBCBIND(NULL, hField32B_CurrencyCode,             0, "settle_curr_iso",  "?", "settle_curr_iso",        SQL_C_CHAR, SQL_CHAR,    3,   0, 3)
  ODBCBIND(NULL, hField32B_Amount,                   0, "settle_amount_a",  "?", "settle_amount_a",        SQL_C_CHAR, SQL_DECIMAL, 18,  3, 15)
  ODBCBIND(NULL, hField35B_ISIN,                     0, "instr_isin",       "?", "instr_isin",             SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity, 0, "instr_desc",       "?", "{fn RTRIM(instr_desc)}", SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
  ODBCBIND(NULL, hField35S_CodeWord,                 0, "instr_cdw_35a_c",  "?", "instr_cdw_35a_c",        SQL_C_CHAR, SQL_CHAR,    3,   0, 3)
  ODBCBIND(NULL, hField35S_Quantity,                 0, "instr_units_q",    "?", "instr_units_q",          SQL_C_CHAR, SQL_DECIMAL, 18,  3, 15)
END_ODBCBIND(DERINSTR_56_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// DATE_PLACE_SERVER

BEGIN_ODBCBIND(DATE_PLACE_SERVER)
  ODBCBIND(NULL, hField31B_Date,         0, "meet_dt",  "?", "meet_dt",              SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31B_TimeAndPlace, 0, "meet_plc", "?", "{fn RTRIM(meet_plc)}", SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(DATE_PLACE_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// CHARGES_71BCD_SERVER

BEGIN_ODBCBIND(CHARGES_71BCD_SERVER)
  ODBCBIND(NULL, hField71a_CodeWord,              0, "chrg_cdw71_c",  "?", "chrg_cdw71_c",              SQL_C_CHAR, SQL_VARCHAR, 8,   0, 8)
  ODBCBIND(NULL, hField71a_CurrencyCode,          0, "chrg_curr_iso", "?", "chrg_curr_iso",             SQL_C_CHAR, SQL_CHAR,    3,   0, 3)
  ODBCBIND(NULL, hField71a_Amount,                0, "chrg_amount_a", "?", "chrg_amount_a",             SQL_C_CHAR, SQL_DECIMAL, 18,  3, 13)
  ODBCBIND(NULL, hField71a_AdditionalInformation, 0, "chrg_info_txt", "?", "{fn RTRIM(chrg_info_txt)}", SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(CHARGES_71BCD_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// QUERIES_SERVER

BEGIN_ODBCBIND(QUERIES_SERVER)
  ODBCBIND(NULL, hField75_QueryNumber,           0, "query_cdw75c", "?", "query_cdw75c",          SQL_C_SLONG, SQL_INTEGER,  2,   0, sizeof(SLONG))
  ODBCBIND(NULL, hField75_AdditionalInformation, 0, "query_txt",    "?", "{fn RTRIM(query_txt)}", SQL_C_CHAR,  SQL_VARCHAR,  254, 0, 254)
END_ODBCBIND(QUERIES_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// ANSWERS_SERVER

BEGIN_ODBCBIND(ANSWERS_SERVER)
  ODBCBIND(NULL, hField76_AnswerNumber,          0, "answ_cdw76c", "?", "answ_cdw76c",          SQL_C_SLONG, SQL_INTEGER, 2,   0, sizeof(SLONG))
  ODBCBIND(NULL, hField76_AdditionalInformation, 0, "answ_txt",    "?", "{fn RTRIM(answ_txt)}", SQL_C_CHAR,  SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(ANSWERS_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT520_SERVER

BEGIN_ODBCBIND(MT520_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",        "?", "{fn RTRIM(tran_id)}",     SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",    "?", "{fn RTRIM(rel_tran_id)}", SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField30_Date,                       0, "delivery_d",     "?", "delivery_d",              SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31P_Date,                      0, "trade_d",        "?", "trade_d",                 SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31P_Place,                     0, "trade_place",    "?", "{fn RTRIM(trade_place)}", SQL_C_CHAR,      SQL_VARCHAR,   29,  0, 29)
  ODBCBIND(NULL, hField33V_PriceOrCurrencyCode,       0, "bv_curr_iso",    "?", "bv_curr_iso",             SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33V_Amount,                    0, "bv_amount",      "?", "bv_amount",               SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 18)
  ODBCBIND(NULL, hField35B_ISIN,                      0, "instr_isin",     "?", "instr_isin",              SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",     "?", "{fn RTRIM(instr_desc)}",  SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField35C_SpecificationOfSecurities, 0, "coupon_num",     "?", "coupon_num",              SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35D_SpecificationOfSecurities, 0, "coupon_d",       "?", "coupon_d",                SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",          SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",  SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField77D_Narrative,                 0, "reg_det_txt",    "?", "{fn RTRIM(reg_det_txt)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField77R_Narrative,                 0, "dcl_det_txt",    "?", "{fn RTRIM(dcl_det_txt)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT520_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT521_SERVER

BEGIN_ODBCBIND(MT521_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",         "?", "{fn RTRIM(tran_id)}",        SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",     "?", "{fn RTRIM(rel_tran_id)}",    SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField30_Date,                       0, "settle_d",        "?", "settle_d",                   SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31P_Date,                      0, "trade_d",         "?", "trade_d",                    SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31P_Place,                     0, "trade_place",     "?", "{fn RTRIM(trade_place)}",    SQL_C_CHAR,      SQL_VARCHAR,   29,  0, 29)
  ODBCBIND(NULL, hField32B_CurrencyCode,              0, "settle_curr_iso", "?", "settle_curr_iso",            SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32B_Amount,                    0, "settle_amount_a", "?", "settle_amount_a",            SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 18)
  ODBCBIND(NULL, hField32M_CurrencyCode,              0, "deala_curr_iso",  "?", "deala_curr_iso",             SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32M_Amount,                    0, "deal_amount_a",   "?", "deal_amount_a",              SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField33T_PriceOrCurrencyCode,       0, "dealp_curr_cw",   "?", "dealp_curr_cw",              SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33T_Amount,                    0, "deal_price_a",    "?", "deal_price_a",               SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField33V_PriceOrCurrencyCode,       0, "bv_curr_iso",     "?", "bv_curr_iso",                SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33V_Amount,                    0, "bv_amount",       "?", "bv_amount",                  SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField34GH_AddedOrDeducted,          0, "accr_crdr_f",     "?", "accr_crdr_f",                SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(NULL, hField34GH_NumberOfDays,             0, "accr_days",       "?", "accr_days",                  SQL_C_SLONG,     SQL_INTEGER,   3,   0, sizeof(SLONG))
  ODBCBIND(NULL, hField34GH_CurrencyCode,             0, "accr_curr_iso",   "?", "accr_curr_iso",              SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField34GH_Amount,                   0, "accr_amount_a",   "?", "accr_amount_a",              SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField35B_ISIN,                      0, "instr_isin",      "?", "instr_isin",                 SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",      "?", "{fn RTRIM(instr_desc)}",     SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField35C_SpecificationOfSecurities, 0, "coupon_num",      "?", "coupon_num",                 SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35D_SpecificationOfSecurities, 0, "coupon_d",        "?", "coupon_d",                   SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField71E_CurrencyCode,              0, "tax_curr_iso",    "?", "tax_curr_iso",               SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField71E_Amount,                    0, "tax_amount_a",    "?", "tax_amount_a",               SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField71E_Rate,                      0, "tax_rate",        "?", "tax_rate",                   SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 18)
  ODBCBIND(NULL, hField71E_AdditionalInformation,     0, "tax_info_txt",    "?", "tax_info_txt",               SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField71F_CurrencyCode,              0, "brok_curr_iso",   "?", "brok_curr_iso",              SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField71F_Amount,                    0, "brok_amount_a",   "?", "brok_amount_a",              SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField71G_CurrencyCode,              0, "fee_curr_iso",    "?", "fee_curr_iso",               SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField71G_Amount,                    0, "fee_amount_a",    "?", "fee_amount_a",               SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c",  "?", "srinfo_cdw72_c",             SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",      "?", "{fn RTRIM(srinfo_txt)}",     SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField77D_Narrative,                 0, "reg_det_txt",     "?", "{fn RTRIM(reg_det_txt)}",    SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField77R_Narrative,                 0, "dcl_det_txt",     "?", "{fn RTRIM(dcl_det_txt)}",    SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT521_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT522_SERVER

BEGIN_ODBCBIND(MT522_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",        "?", "{fn RTRIM(tran_id)}",     SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",    "?", "{fn RTRIM(rel_tran_id)}", SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField30_Date,                       0, "delivery_d",     "?", "delivery_d",              SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31P_Date,                      0, "trade_d",        "?", "trade_d",                 SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31P_Place,                     0, "trade_place",    "?", "{fn RTRIM(trade_place)}", SQL_C_CHAR,      SQL_VARCHAR,   29,  0, 29)
  ODBCBIND(NULL, hField33V_PriceOrCurrencyCode,       0, "bv_curr_iso",    "?", "bv_curr_iso",             SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33V_Amount,                    0, "bv_amount",      "?", "bv_amount",               SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField35B_ISIN,                      0, "instr_isin",     "?", "instr_isin",              SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",     "?", "{fn RTRIM(instr_desc)}",  SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField35C_SpecificationOfSecurities, 0, "coupon_num",     "?", "coupon_num",              SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35D_SpecificationOfSecurities, 0, "coupon_d",       "?", "coupon_d",                SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",          SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",  SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField77D_Narrative,                 0, "reg_det_txt",    "?", "{fn RTRIM(reg_det_txt)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField77R_Narrative,                 0, "dcl_det_txt",    "?", "{fn RTRIM(dcl_det_txt)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT522_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT523_SERVER

BEGIN_ODBCBIND(MT523_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",         "?", "{fn RTRIM(tran_id)}",      SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",     "?", "{fn RTRIM(rel_tran_id)}",  SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField30_Date,                       0, "settle_d",        "?", "settle_d",                 SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31P_Date,                      0, "trade_d",         "?", "trade_d",                  SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31P_Place,                     0, "trade_place",     "?", "{fn RTRIM(trade_place)}",  SQL_C_CHAR,      SQL_VARCHAR,   29,  0, 29)
  ODBCBIND(NULL, hField32B_CurrencyCode,              0, "settle_curr_iso", "?", "settle_curr_iso",          SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32B_Amount,                    0, "settle_amount_a", "?", "settle_amount_a",          SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField32M_CurrencyCode,              0, "deala_curr_iso",  "?", "deala_curr_iso",           SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32M_Amount,                    0, "deal_amount_a",   "?", "deal_amount_a",            SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField33T_PriceOrCurrencyCode,       0, "dealp_curr_cw",   "?", "dealp_curr_cw",            SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33T_Amount,                    0, "deal_price_a",    "?", "deal_price_a",             SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField33V_PriceOrCurrencyCode,       0, "bv_curr_iso",     "?", "bv_curr_iso",              SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33V_Amount,                    0, "bv_amount",       "?", "bv_amount",                SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField34GH_AddedOrDeducted,          0, "accr_crdr_f",     "?", "accr_crdr_f",              SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(NULL, hField34GH_NumberOfDays,             0, "accr_days",       "?", "accr_days",                SQL_C_SLONG,     SQL_INTEGER,   3,   0, sizeof(SLONG))
  ODBCBIND(NULL, hField34GH_CurrencyCode,             0, "accr_curr_iso",   "?", "accr_curr_iso",            SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField34GH_Amount,                   0, "accr_amount_a",   "?", "accr_amount_a",            SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField35B_ISIN,                      0, "instr_isin",      "?", "instr_isin",               SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",      "?", "{fn RTRIM(instr_desc)}",   SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField35C_SpecificationOfSecurities, 0, "coupon_num",      "?", "coupon_num",               SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35D_SpecificationOfSecurities, 0, "coupon_d",        "?", "coupon_d",                 SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField71E_CurrencyCode,              0, "tax_curr_iso",    "?", "tax_curr_iso",             SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField71E_Amount,                    0, "tax_amount_a",    "?", "tax_amount_a",             SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField71E_Rate,                      0, "tax_rate",        "?", "tax_rate",                 SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 12)
  ODBCBIND(NULL, hField71E_AdditionalInformation,     0, "tax_info_txt",    "?", "{fn RTRIM(tax_info_txt)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField71F_CurrencyCode,              0, "brok_curr_iso",   "?", "brok_curr_iso",            SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField71F_Amount,                    0, "brok_amount_a",   "?", "brok_amount_a",            SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField71G_CurrencyCode,              0, "fee_curr_iso",    "?", "fee_curr_iso",             SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField71G_Amount,                    0, "fee_amount_a",    "?", "fee_amount_a",             SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c",  "?", "srinfo_cdw72_c",           SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",      "?", "{fn RTRIM(srinfo_txt)}",   SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField77D_Narrative,                 0, "reg_det_txt",     "?", "{fn RTRIM(reg_det_txt)}",  SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField77R_Narrative,                 0, "dcl_det_txt",     "?", "{fn RTRIM(dcl_det_txt)}",  SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT523_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT530_SERVER

BEGIN_ODBCBIND(MT530_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",        "?", "{fn RTRIM(tran_id)}",        SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",    "?", "{fn RTRIM(rel_tran_id)}",    SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField30_Date,                       0, "delivery_d",     "?", "delivery_d",                 SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField33V_PriceOrCurrencyCode,       0, "bv_curr_iso",    "?", "bv_curr_iso",                SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33V_Amount,                    0, "bv_amount",      "?", "bv_amount",                  SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField35B_ISIN,                      0, "instr_isin",     "?", "instr_isin",                 SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",     "?", "{fn RTRIM(instr_desc)}",     SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField35C_SpecificationOfSecurities, 0, "coupon_num",     "?", "coupon_num",                 SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35D_SpecificationOfSecurities, 0, "coupon_d",       "?", "coupon_d",                   SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",             SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",     SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField77D_Narrative,                 0, "reg_det_txt",    "?", "{fn RTRIM(reg_det_txt)}",    SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField77R_Narrative,                 0, "dcl_det_txt",    "?", "{fn RTRIM(dcl_det_txt)}",    SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT530_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT531_SERVER

BEGIN_ODBCBIND(MT531_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",         "?", "{fn RTRIM(tran_id)}",        SQL_C_CHAR,       SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",     "?", "{fn RTRIM(rel_tran_id)}",    SQL_C_CHAR,       SQL_VARCHAR,   16,  0, 16)
  
  ODBCBIND(NULL, hField30_Date,                       0, "settle_d",        "?", "settle_d",                   SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  
  ODBCBIND(NULL, hField31P_Date,                      0, "trade_d",         "?", "trade_d",                    SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31P_Place,                     0, "trade_place",     "?", "{fn RTRIM(trade_place)}",    SQL_C_CHAR,       SQL_VARCHAR,   29,  0, 29)
  
  ODBCBIND(NULL, hField32B_CurrencyCode,              0, "settle_curr_iso", "?", "settle_curr_iso",            SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32B_Amount,                    0, "settle_amount_a", "?", "settle_amount_a",            SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField32M_CurrencyCode,              0, "deala_curr_iso",  "?", "deala_curr_iso",             SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32M_Amount,                    0, "deal_amount_a",   "?", "deal_amount_a",              SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField33S_PriceOrCurrencyCode,       0, "cons_curr_cw",    "?", "cons_curr_cw",               SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33S_Amount,                    0, "cons_amount_a",   "?", "cons_amount_a",              SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField33T_PriceOrCurrencyCode,       0, "dealp_curr_cw",   "?", "dealp_curr_cw",              SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33T_Amount,                    0, "deal_price_a",    "?", "deal_price_a",               SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField33V_PriceOrCurrencyCode,       0, "bv_curr_iso",     "?", "bv_curr_iso",                SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33V_Amount,                    0, "bv_amount",       "?", "bv_amount",                  SQL_C_CHAR,       SQL_DECIMAL,   18,  0, 15)
  
  ODBCBIND(NULL, hField34A_Date,                      0, "proc_d",          "?", "proc_d",                     SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField34A_CurrencyCode,              0, "proc_curr_iso",   "?", "proc_curr_iso",              SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField34A_Amount,                    0, "proc_amount_a",   "?", "proc_amount_a",              SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField34GH_AddedOrDeducted,          0, "accr_crdr_f",     "?", "accr_crdr_f",                SQL_C_CHAR,       SQL_CHAR,      1,   0, 1)
  ODBCBIND(NULL, hField34GH_NumberOfDays,             0, "accr_days",       "?", "accr_days",                  SQL_C_SLONG,      SQL_INTEGER,   3,   0, sizeof(SLONG))
  ODBCBIND(NULL, hField34GH_CurrencyCode,             0, "accr_curr_iso",   "?", "accr_curr_iso",              SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField34GH_Amount,                   0, "accr_amount_a",   "?", "accr_amount_a",              SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField35B_ISIN,                      0, "instr_isin",      "?", "instr_isin",                 SQL_C_CHAR,       SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",      "?", "{fn RTRIM(instr_desc)}",     SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
  
  ODBCBIND(NULL, hField35C_SpecificationOfSecurities, 0, "coupon_num",      "?", "coupon_num",                 SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35D_SpecificationOfSecurities, 0, "coupon_d",        "?", "coupon_d",                   SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  
  ODBCBIND(NULL, hField36_ExchangeRate,               0, "ex_rate",         "?", "ex_rate",                    SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 12)
  
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c",  "?", "srinfo_cdw72_c",             SQL_C_CHAR,       SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",      "?", "{fn RTRIM(srinfo_txt)}",     SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
  
  ODBCBIND(NULL, hField77D_Narrative,                 0, "reg_det_txt",     "?", "{fn RTRIM(reg_det_txt)}",    SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField77R_Narrative,                 0, "dcl_det_txt",     "?", "{fn RTRIM(dcl_det_txt)}",    SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT531_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT532_SERVER

BEGIN_ODBCBIND(MT532_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",        "?", "{fn RTRIM(tran_id)}",     SQL_C_CHAR,       SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",    "?", "{fn RTRIM(rel_tran_id)}", SQL_C_CHAR,       SQL_VARCHAR,   16,  0, 16)
  
  ODBCBIND(NULL, hField30_Date,                       0, "delivery_d",     "?", "delivery_d",              SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  
  ODBCBIND(NULL, hField33V_PriceOrCurrencyCode,       0, "bv_curr_iso",    "?", "bv_curr_iso",             SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33V_Amount,                    0, "bv_amount",      "?", "bv_amount",               SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 18)
  
  ODBCBIND(NULL, hField35B_ISIN,                      0, "instr_isin",     "?", "instr_isin",              SQL_C_CHAR,       SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",     "?", "{fn RTRIM(instr_desc)}",  SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
  
  ODBCBIND(NULL, hField35C_SpecificationOfSecurities, 0, "coupon_num",     "?", "coupon_num",              SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35D_SpecificationOfSecurities, 0, "coupon_d",       "?", "coupon_d",                SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",          SQL_C_CHAR,       SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",  SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
  
  ODBCBIND(NULL, hField77D_Narrative,                 0, "reg_det_txt",    "?", "{fn RTRIM(reg_det_txt)}", SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField77R_Narrative,                 0, "dcl_det_txt",    "?", "{fn RTRIM(dcl_det_txt)}", SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT532_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT533_SERVER

BEGIN_ODBCBIND(MT533_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",         "?", "{fn RTRIM(tran_id)}",      SQL_C_CHAR,       SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",     "?", "{fn RTRIM(rel_tran_id)}",  SQL_C_CHAR,       SQL_VARCHAR,   16,  0, 16)
  
  ODBCBIND(NULL, hField30_Date,                       0, "settle_d",        "?", "settle_d",                 SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  
  ODBCBIND(NULL, hField31P_Date,                      0, "trade_d",         "?", "trade_d",                  SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31P_Place,                     0, "trade_place",     "?", "{fn RTRIM(trade_place)}",  SQL_C_CHAR,       SQL_VARCHAR,   29,  0, 29)
  
  ODBCBIND(NULL, hField32B_CurrencyCode,              0, "settle_curr_iso", "?", "settle_curr_iso",          SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32B_Amount,                    0, "settle_amount_a", "?", "settle_amount_a",          SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField32M_CurrencyCode,              0, "deala_curr_iso",  "?", "deala_curr_iso",           SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32M_Amount,                    0, "deal_amount_a",   "?", "deal_amount_a",            SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField33S_PriceOrCurrencyCode,       0, "cons_curr_cw",    "?", "cons_curr_cw",             SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33S_Amount,                    0, "cons_amount_a",   "?", "cons_amount_a",            SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField33T_PriceOrCurrencyCode,       0, "dealp_curr_cw",   "?", "dealp_curr_cw",            SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33T_Amount,                    0, "deal_price_a",    "?", "deal_price_a",             SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField33V_PriceOrCurrencyCode,       0, "bv_curr_iso",     "?", "bv_curr_iso",              SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33V_Amount,                    0, "bv_amount",       "?", "bv_amount",                SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField34A_Date,                      0, "proc_d",          "?", "proc_d",                   SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField34A_CurrencyCode,              0, "proc_curr_iso",   "?", "proc_curr_iso",            SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField34A_Amount,                    0, "proc_amount_a",   "?", "proc_amount_a",            SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField34GH_AddedOrDeducted,          0, "accr_crdr_f",     "?", "accr_crdr_f",              SQL_C_CHAR,       SQL_CHAR,      1,   0, 1)
  ODBCBIND(NULL, hField34GH_NumberOfDays,             0, "accr_days",       "?", "accr_days",                SQL_C_SLONG,      SQL_INTEGER,   3,   0, sizeof(SLONG))
  ODBCBIND(NULL, hField34GH_CurrencyCode,             0, "accr_curr_iso",   "?", "accr_curr_iso",            SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField34GH_Amount,                   0, "accr_amount_a",   "?", "accr_amount_a",            SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField35B_ISIN,                      0, "instr_isin",      "?", "instr_isin",               SQL_C_CHAR,       SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",      "?", "{fn RTRIM(instr_desc)}",   SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
  
  ODBCBIND(NULL, hField35C_SpecificationOfSecurities, 0, "coupon_num",      "?", "coupon_num",               SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35D_SpecificationOfSecurities, 0, "coupon_d",        "?", "coupon_d",                 SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  
  ODBCBIND(NULL, hField36_ExchangeRate,               0, "ex_rate",         "?", "ex_rate",                  SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c",  "?", "srinfo_cdw72_c",           SQL_C_CHAR,       SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",      "?", "{fn RTRIM(srinfo_txt)}",   SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
  
  ODBCBIND(NULL, hField77D_Narrative,                 0, "reg_det_txt",     "?", "{fn RTRIM(reg_det_txt)}",  SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField77R_Narrative,                 0, "dcl_det_txt",     "?", "{fn RTRIM(dcl_det_txt)}",  SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT533_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT534_SERVER

BEGIN_ODBCBIND(MT534_SERVER)
  ODBCBIND(NULL, hField11a_MessageType,               0, "msg_type",       "?", "msg_type",                   SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField11a_Date,                      0, "msg_d",          "?", "msg_d",                      SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField11a_SessionNumber,             0, "msg_session",    "?", "msg_session",                SQL_C_SLONG,      SQL_CHAR,      4,   0, sizeof(SLONG))
  ODBCBIND(NULL, hField11a_SequenceNumber,            0, "msg_seq_num",    "?", "msg_seq_num",                SQL_C_SLONG,      SQL_CHAR,      6,   0, sizeof(SLONG))
  
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",        "?", "{fn RTRIM(tran_id)}",        SQL_C_CHAR,       SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",    "?", "{fn RTRIM(rel_tran_id)}",    SQL_C_CHAR,       SQL_VARCHAR,   16,  0, 16)
  
  ODBCBIND(srvrField23_FurtherIdentification, hField23_Subfield1,       0, "prob_dir",       "?", "prob_dir",                   SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(srvrField23_FurtherIdentification, hField23_Subfield2,       0, "prob_cdw23_c",   "?", "prob_cdw23_c",               SQL_C_CHAR,       SQL_CHAR,      8,   0, 8)
  
  ODBCBIND(NULL, hField30_Date,                       0, "settle_d",       "?", "settle_d",                   SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31S_Date,                      0, "prob_d",         "?", "prob_d",                     SQL_C_TIMESTAMP,  SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  
  ODBCBIND(NULL, hField35A_CodeWord,                  0, "instr_cdw35a_c", "?", "instr_cdw35a_c",             SQL_C_CHAR,       SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35A_Quantity,                  0, "instr_units_q",  "?", "instr_units_q",              SQL_C_CHAR,       SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(NULL, hField35B_ISIN,                      0, "instr_isin",     "?", "instr_isin",                 SQL_C_CHAR,       SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",     "?", "{fn RTRIM(instr_desc)}",     SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
  
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",             SQL_C_CHAR,       SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",     SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
  
  ODBCBIND(NULL, hField79_Narrative,                  0, "narrative_txt",  "?", "narrative_txt",              SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
  
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount, 0, "safe_crdr_f",    "?", "safe_crdr_f",                SQL_C_CHAR,       SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,            0, "safe_acct_name", "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR,       SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,       0, "safe_bic",       "?", "safe_bic",                   SQL_C_CHAR,       SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namadd",    "?", "{fn RTRIM(safe_namadd)}",    SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT534_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT550_SERVER

BEGIN_ODBCBIND(MT550_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",            "?", "{fn RTRIM(tran_id)}",        SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",        "?", "{fn RTRIM(rel_tran_id)}",    SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)
  
  ODBCBIND(NULL, hField26G_ItemIdentification,        0, "salable_cdw26_c",    "?", "salable_cdw26_c",            SQL_C_CHAR,      SQL_CHAR,        7,   0, 7)
  ODBCBIND(NULL, hField26H_ItemIdentification,        0, "fraction_cdw26_c",   "?", "fraction_cdw26_c",           SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(NULL, hField31C_Date,                      0, "payable_d",          "?", "payable_d",                  SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31E_Date,                      0, "record_d",           "?", "record_d",                   SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31H_DateAndTime,               0, "expiry_dt",          "?", "expiry_dt"  ,                SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31H_CodeWord,                  0, "expiry_w",           "?", "expiry_w",                   SQL_C_CHAR,      SQL_CHAR,        16,  0, 16)
  ODBCBIND(NULL, hField31J_DateAndTime,               0, "response_dt",        "?", "response_dt",                SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31J_CodeWord,                  0, "response_w",         "?", "response_w",                 SQL_C_CHAR,      SQL_CHAR,        16,  0, 16)
  ODBCBIND(NULL, hField31S_Date,                      0, "parri_d",            "?", "parri_d",                    SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  
  ODBCBIND(NULL, hField31X_DateAndTime,               0, "ex_dt",              "?", "ex_dt",                      SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31X_CodeWord,                  0, "ex_w",               "?", "ex_w",                       SQL_C_CHAR,      SQL_CHAR,        8,   0, 8)
  
  ODBCBIND(NULL, hField33B_PriceOrCurrencyCode,       0, "subpr_curr_iso",     "?", "subpr_curr_iso",             SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField33B_Amount,                    0, "subpr_a",            "?", "subpr_a",                    SQL_C_CHAR,      SQL_DECIMAL,     18,  0, 15)
  
  ODBCBIND(NULL, hField33S_PriceOrCurrencyCode,       0, "indpright_curr_iso", "?", "indpright_curr_iso",         SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField33S_Amount,                    0, "indpright_a",        "?", "indpright_a",                SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 15)
  
  ODBCBIND(NULL, hField33T_PriceOrCurrencyCode,       0, "indprni_curr_cw",    "?", "indprni_curr_cw",            SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField33T_Amount,                    0, "indprni_a",          "?", "indprni_a",                  SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 15)
  
  ODBCBIND(srvrField35A_QuantityOfSecurities,       hField35A_CodeWord,                 0, "instr_cdw35a_c",     "?", "instr_cdw35a_c",             SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(srvrField35A_QuantityOfSecurities,       hField35A_Quantity,                 0, "instr_units_q",      "?", "instr_units_q",              SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(srvrField35A_QuantityOfRights,           hField35A_CodeWord,                 1, "right_cdw35a_c",     "?", "right_cdw35a_c",             SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(srvrField35A_QuantityOfRights,           hField35A_Quantity,                 1, "right_units_q",      "?", "right_units_q",              SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  
  ODBCBIND(srvrField35B_IdentificationOfSecurities, hField35B_ISIN,                     0, "instr_isin",         "?", "instr_isin",                 SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField35B_IdentificationOfSecurities, hField35B_DescriptionOfTheSecurity, 0, "instr_desc",         "?", "{fn RTRIM(instr_desc)}",     SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  
  ODBCBIND(srvrField35B_IdentificationOfRights,     hField35B_ISIN,                     1, "right_isin",         "?", "right_isin",                 SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField35B_IdentificationOfRights,     hField35B_DescriptionOfTheSecurity, 1, "right_desc",         "?", "{fn RTRIM(right_desc)}",     SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  
  ODBCBIND(NULL, hField35C_SpecificationOfSecurities, 0, "coupon_num",         "?", "coupon_num",                 SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField35D_SpecificationOfSecurities, 0, "coupon_d",           "?", "coupon_d",                   SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  
  ODBCBIND(NULL, hField35T_NumberOfRights,            0, "ratio_right_q",      "?", "ratio_right_q",              SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 7)
  ODBCBIND(NULL, hField35T_CodeWord,                  0, "ratio_cdw35a_c",     "?", "ratio_cdw35a_c",             SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField35T_NumberOfSecurities,        0, "ratio_instr_q",      "?", "ratio_instr_q",              SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 7)
  
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c",     "?", "srinfo_cdw72_c",             SQL_C_CHAR,      SQL_VARCHAR,     8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",         "?", "{fn RTRIM(srinfo_txt)}",     SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)
  
  ODBCBIND(NULL, hField77R_Narrative,                 0, "legal_txt",          "?", "{fn RTRIM(legal_txt)}",      SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)
  ODBCBIND(NULL, hField79_Narrative,                  0, "narrative_txt",      "?", "narrative_txt",              SQL_C_CHAR,      SQL_LONGVARCHAR, 0,   0, 1850)
  
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount, 0, "safe_crdr_f",        "?", "safe_crdr_f",                SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,            0, "safe_acct_name",     "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,       0, "safe_bic",           "?", "safe_bic",                   SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",       "?", "{fn RTRIM(safe_namaddr)}",   SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT550_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT551_SERVER

BEGIN_ODBCBIND(MT551_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",        "?", "{fn RTRIM(tran_id)}",        SQL_C_CHAR, SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",    "?", "{fn RTRIM(rel_tran_id)}",    SQL_C_CHAR, SQL_VARCHAR,     16,  0, 16)

  ODBCBIND(NULL, hField35A_CodeWord,                  0, "instr_cdw35a_c", "?", "instr_cdw35a_c",             SQL_C_CHAR, SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField35A_Quantity,                  0, "instr_units_q",  "?", "instr_units_q",              SQL_C_CHAR, SQL_DECIMAL,     18,  3, 18)

  ODBCBIND(NULL, hField35B_ISIN,                      0, "instr_isin",     "?", "instr_isin",                 SQL_C_CHAR, SQL_CHAR,        12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",     "?", "{fn RTRIM(instr_desc)}",     SQL_C_CHAR, SQL_VARCHAR,     254, 0, 254)

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",             SQL_C_CHAR, SQL_VARCHAR,     8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",     SQL_C_CHAR, SQL_VARCHAR,     254, 0, 254)

  ODBCBIND(NULL, hField79_Narrative,                  0, "narrative_txt",  "?", "narrative_txt",              SQL_C_CHAR, SQL_LONGVARCHAR, 0,   0, 1850)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount, 0, "safe_crdr_f",    "?", "safe_crdr_f",                SQL_C_CHAR, SQL_CHAR,    1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,            0, "safe_acct_name", "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR, SQL_VARCHAR, 34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,       0, "safe_bic",       "?", "safe_bic",                   SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",   "?", "{fn RTRIM(safe_namaddr)}",   SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(MT551_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT552_SERVER

BEGIN_ODBCBIND(MT552_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",           "?", "{fn RTRIM(tran_id)}",       SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",       "?", "{fn RTRIM(rel_tran_id)}",   SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)

  ODBCBIND(srvrField23_FurtherIdentification, hField23_FurtherIdentification,       0, "further_txt",       "?", "further_txt", SQL_C_CHAR,      SQL_CHAR,      16, 0, 16)
  ODBCBIND(NULL, hField26H_ItemIdentification,        0, "fraction_f",        "?", "fraction_f",                SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(NULL, hField30_Date,                       0, "start_d",           "?", "start_d",                   SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31C_Date,                      0, "payable_d",         "?", "payable_d",                 SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31E_Date,                      0, "record_d",          "?", "record_d",                  SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField31H_DateAndTime,               0, "expiry_dt",         "?", "expiry_dt",                 SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31H_CodeWord,                  0, "expiry_w",          "?", "expiry_w",                  SQL_C_CHAR,      SQL_CHAR,        16,  0, 16)

  ODBCBIND(NULL, hField31J_DateAndTime,               0, "response_dt",       "?", "response_dt",               SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31J_CodeWord,                  0, "response_w",        "?", "response_w",                SQL_C_CHAR,      SQL_CHAR,        16,  0, 16)

  ODBCBIND(NULL, hField31L_Date,                      0, "effective_d",       "?", "effective_d",               SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31S_Date,                      0, "parri_d",           "?", "parri_d",                   SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField31X_DateAndTime,               0, "ex_dt",             "?", "ex_dt",                     SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31X_CodeWord,                  0, "ex_w",              "?", "ex_w",                      SQL_C_CHAR,      SQL_CHAR,        8,   0, 8)

  ODBCBIND(NULL, hField33B_PriceOrCurrencyCode,       0, "subpr_curr_iso",    "?", "subpr_curr_iso",            SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField33B_Amount,                    0, "subpr_a",           "?", "subpr_a",                   SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 15)

  ODBCBIND(NULL, hField33S_PriceOrCurrencyCode,       0, "indpright_curr_cw", "?", "indpright_curr_cw",         SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField33S_Amount,                    0, "indpright_a",       "?", "indpright_a",               SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 15)

  ODBCBIND(NULL, hField33T_PriceOrCurrencyCode,       0, "indpr_curr_cw",     "?", "indpr_curr_cw",             SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField33T_Amount,                    0, "indpr_a",           "?", "indpr_a",                   SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 15)

  ODBCBIND(NULL, hField35A_CodeWord,                  0, "instr_cdw35a_c",    "?", "instr_cdw35a_c",            SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField35A_Quantity,                  0, "instr_units_q",     "?", "instr_units_q",             SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 15)

  ODBCBIND(srvrField35B_IdentificationOfSecurities,        hField35B_ISIN,                     0, "instr_isin",        "?", "instr_isin",                SQL_C_CHAR,      SQL_CHAR,        12,  0, 12)
  ODBCBIND(srvrField35B_IdentificationOfSecurities,        hField35B_DescriptionOfTheSecurity, 0, "instr_desc",        "?", "{fn RTRIM(instr_desc)}",    SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)
  ODBCBIND(srvrField35B_IdentificationOfSecuritiesDerived, hField35B_ISIN,                     1, "sec_isin",          "?", "sec_isin",                  SQL_C_CHAR,      SQL_CHAR,        12,  0, 12)
  ODBCBIND(srvrField35B_IdentificationOfSecuritiesDerived, hField35B_DescriptionOfTheSecurity, 1, "sec_desc",          "?", "{fn RTRIM(sec_desc)}",      SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)

  ODBCBIND(NULL, hField35C_SpecificationOfSecurities, 0, "coupon_num",        "?", "coupon_num",                SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField35D_SpecificationOfSecurities, 0, "coupon_d",          "?", "coupon_d",                  SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField35S_CodeWord,                  0, "sec_cdw35a_c",      "?", "sec_cdw35a_c",              SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField35S_Quantity,                  0, "sec_units_q",       "?", "sec_units_q",               SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 15)

  ODBCBIND(NULL, hField35T_NumberOfRights,            0, "ratio_q",           "?", "ratio_q",                   SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 7)
  ODBCBIND(NULL, hField35T_CodeWord,                  0, "ratio_cdw35a_c",    "?", "ratio_cdw35a_c",            SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField35T_NumberOfSecurities,        0, "ratio_instr_q",     "?", "ratio_instr_q",             SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 7)

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c",    "?", "srinfo_cdw72_c",            SQL_C_CHAR,      SQL_VARCHAR,     8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",        "?", "{fn RTRIM(srinfo_txt)}",    SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)

  ODBCBIND(NULL, hField77B_Narrative,                 0, "proceeds_txt",      "?", "{fn RTRIM(proceeds_txt)}",  SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)
  ODBCBIND(NULL, hField77R_Narrative,                 0, "legal_txt",         "?", "{fn RTRIM(legal_txt)}",     SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)
  ODBCBIND(NULL, hField79_Narrative,                  0, "narrative_txt",     "?", "narrative_txt",             SQL_C_CHAR,      SQL_LONGVARCHAR, 0,   0, 1850)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount, 0, "safe_crdr_f",       "?", "safe_crdr_f",                SQL_C_CHAR, SQL_CHAR,    1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,            0, "safe_acct_name",    "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR, SQL_VARCHAR, 34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,       0, "safe_bic",          "?", "safe_bic",                   SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",      "?", "{fn RTRIM(safe_namaddr)}",   SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(MT552_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT553_SERVER

BEGIN_ODBCBIND(MT553_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",         "?", "{fn RTRIM(tran_id)}",        SQL_C_CHAR,       SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",     "?", "{fn RTRIM(rel_tran_id)}",    SQL_C_CHAR,       SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(srvrField23_FurtherIdentification, hField23_FurtherIdentification,     0, "further_txt",     "?", "further_txt",                SQL_C_CHAR,       SQL_CHAR,      16,  0, 16)
  ODBCBIND(NULL, hField30_Date,                       0, "execution_d",     "?", "execution_d",                SQL_C_TIMESTAMP,  SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField32B_CurrencyCode,              0, "settle_curr_iso", "?", "settle_curr_iso",            SQL_C_CHAR,       SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField32B_Amount,                    0, "settle_amount_a", "?", "settle_amount_a",            SQL_C_CHAR,       SQL_DECIMAL,     18,  3, 15)

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c",  "?", "srinfo_cdw72_c",             SQL_C_CHAR,       SQL_VARCHAR,     8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",      "?", "{fn RTRIM(srinfo_txt)}",     SQL_C_CHAR,       SQL_VARCHAR,     254, 0, 254)

  ODBCBIND(NULL, hField77D_Narrative,                 0, "reg_det_txt",     "?", "{fn RTRIM(reg_det_txt)}",    SQL_C_CHAR,       SQL_VARCHAR,     254, 0, 254)
  ODBCBIND(NULL, hField77R_Narrative,                 0, "dcl_det_txt",     "?", "{fn RTRIM(dcl_det_txt)}",    SQL_C_CHAR,       SQL_VARCHAR,     254, 0, 254)
  ODBCBIND(NULL, hField79_Narrative,                  0, "narrative_txt",   "?", "narrative_txt",              SQL_C_CHAR,       SQL_LONGVARCHAR, 0,   0, 1850)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,  0, "safe_crdr_f",     "?", "safe_crdr_f",                SQL_C_CHAR,       SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,             0, "safe_acct_name",  "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR,       SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,        0, "safe_bic",        "?", "safe_bic",                   SQL_C_CHAR,       SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",    "?", "{fn RTRIM(safe_namaddr)}",   SQL_C_CHAR,       SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT553_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT554_SERVER

BEGIN_ODBCBIND(MT554_SERVER)
  ODBCBIND(NULL, hField19_SumOfAmount,           0, "net_sum_a",       "?", "net_sum_a",                  SQL_C_CHAR, SQL_DECIMAL, 23,  3, 17)
  ODBCBIND(NULL, hField72_CodeWord,              0, "srinfo_cdw72_c",  "?", "srinfo_cdw72_c",             SQL_C_CHAR, SQL_VARCHAR, 8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation, 0, "srinfo_txt",      "?", "{fn RTRIM(srinfo_txt)}",     SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
  ODBCBIND(srvrField23_FurtherIdentification, hField23_FurtherIdentification,           0, "crdr_f",          "?", "crdr_f",                     SQL_C_CHAR, SQL_CHAR,    1,   0, 1)

  ODBCBIND(srvrField83a_SafekeepingAccount,   hFieldXXa_CreditedOrDebitedAccount,       0, "safe_crdr_f",     "?", "safe_crdr_f",                SQL_C_CHAR, SQL_CHAR,    1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount,   hFieldXXa_AccountNumber,                  0, "safe_acct_name",  "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR, SQL_VARCHAR, 34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount,   hFieldXXa_BankIdentifierCode,             0, "safe_bic",        "?", "safe_bic",                   SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount,   hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",    "?", "{fn RTRIM(safe_namaddr)}",   SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(MT554_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT554SUB_SERVER

BEGIN_ODBCBIND(MT554SUB_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",           "?", "{fn RTRIM(tran_id)}",           SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",       "?", "{fn RTRIM(rel_tran_id)}",       SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField31C_Date,                      0, "pay_d",             "?", "pay_d",                         SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31E_Date,                      0, "record_d",          "?", "record_d",                      SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31L_Date,                      0, "clip_d",            "?", "clip_d",                        SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField31X_DateAndTime,               0, "ex_d",              "?", "ex_d",                          SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31X_CodeWord,                  0, "ex_w",              "?", "ex_w",                          SQL_C_CHAR,      SQL_CHAR,      8,   0, 8)

  ODBCBIND(NULL, hField32G_CurrencyCode,              0, "gross_curr_iso",    "?", "gross_curr_iso",                SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32G_Amount,                    0, "gross_a",           "?", "gross_a",                       SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField34A_Date,                      0, "net_d",             "?", "net_d",                         SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField34A_CurrencyCode,              0, "net_curr_iso",      "?", "net_curr_iso",                  SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField34A_Amount,                    0, "net_a",             "?", "net_a",                         SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField35A_CodeWord,                  0, "instr_cdw35a_c",    "?", "instr_cdw35a_c",                SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35A_Quantity,                  0, "instr_units_q",     "?", "instr_units_q",                 SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField35B_ISIN,                      0, "instr_isin",        "?", "instr_isin",                    SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",        "?", "{fn RTRIM(instr_desc)}",        SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(NULL, hField35C_SpecificationOfSecurities, 0, "coupon_num",        "?", "coupon_num",                    SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35D_SpecificationOfSecurities, 0, "coupon_d",          "?", "coupon_d",                      SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField35U_PriceOrCurrencyCode,       0, "div_curr_cw",       "?", "div_curr_cw",                   SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35U_Amount,                    0, "div_amount_a",      "?", "div_amount_a",                  SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField35U_Code,                      0, "div_per_c",         "?", "div_per_c",                     SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)

  ODBCBIND(NULL, hField36_ExchangeRate,               0, "ex_rate",           "?", "ex_rate",                       SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 12)

  ODBCBIND(NULL, hField71E_CurrencyCode,              0, "tax_curr_iso",      "?", "tax_curr_iso",                  SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField71E_Amount,                    0, "tax_amount_a",      "?", "tax_amount_a",                  SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField71E_Rate,                      0, "tax_rate",          "?", "tax_rate",                      SQL_C_CHAR,      SQL_DECIMAL,   12,  0, 12)
  ODBCBIND(NULL, hField71E_AdditionalInformation,     0, "tax_info_txt",      "?", "tax_info_txt",                  SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c",    "?", "srinfo_cdw72_c",                SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",        "?", "{fn RTRIM(srinfo_txt)}",        SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(NULL, hField80C_Narrative,                 0, "component_txt",     "?", "{fn RTRIM(component_txt)}",     SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(srvrField87a_ReceiverOrDelivererOfSecurities, hFieldXXa_CreditedOrDebitedAccount,    0, "rdinstr_crdr_f",    "?", "rdinstr_crdr_f",                SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField87a_ReceiverOrDelivererOfSecurities, hFieldXXa_AccountNumber, 0, "rdinstr_acct_name", "?", "{fn RTRIM(rdinstr_acct_name)}", SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 1)
  ODBCBIND(srvrField87a_ReceiverOrDelivererOfSecurities, hFieldXXa_BankIdentifierCode,       0, "rdinstr_bic",       "?", "rdinstr_bic",                   SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField87a_ReceiverOrDelivererOfSecurities, hFieldXXa_BranchIdentificationOrNameAndAddress,    0, "rdinstr_namadd",    "?", "{fn RTRIM(rdinstr_namadd)}",    SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT554SUB_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT555_SERVER

BEGIN_ODBCBIND(MT555_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",        "?", "{fn RTRIM(tran_id)}",       SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",    "?", "{fn RTRIM(rel_tran_id)}",   SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)

  ODBCBIND(srvrField23_FurtherIdentification, hField23_Subfield1,         0, "crdr_f",         "?", "crdr_f", SQL_C_CHAR, SQL_CHAR, 1, 0, 1)
  ODBCBIND(srvrField23_FurtherIdentification, hField23_Subfield2,         0, "fur_ad",         "?", "fur_ad", SQL_C_CHAR, SQL_CHAR, 1, 0, 1)

  ODBCBIND(NULL, hField31C_Date,                      0, "pay_d",          "?", "pay_d",                     SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31E_Date,                      0, "record_d",       "?", "record_d",                  SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField31X_DateAndTime,               0, "ex_d",           "?", "ex_d",                      SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31X_CodeWord,                  0, "ex_w",           "?", "ex_w",                      SQL_C_CHAR,      SQL_CHAR,      8,   0, 8)

  ODBCBIND(NULL, hField33a_CreditOrDebit,             0, "fract_crdr_f",   "?", "fract_crdr_f",              SQL_C_CHAR,      SQL_CHAR,      1,  0, 1)
  ODBCBIND(NULL, hField33a_Date,                      0, "fract_d",        "?", "fract_d",                   SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,  0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField33a_CurrencyCode,              0, "fract_curr_iso", "?", "fract_curr_iso",            SQL_C_CHAR,      SQL_CHAR,      3,  0, 3)
  ODBCBIND(NULL, hField33a_Amount,                    0, "fract_a",        "?", "fract_a",                   SQL_C_CHAR,      SQL_DECIMAL,   18, 3, 18)

  ODBCBIND(NULL, hField34CD_CreditOrDebit,            0, "net_crdr_f",     "?", "net_crdr_f",                SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(NULL, hField34CD_Date,                     0, "net_d",          "?", "net_d",                     SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField34CD_CurrencyCode,             0, "net_curr_iso",   "?", "net_curr_iso",              SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField34CD_Amount,                   0, "net_a",          "?", "net_a",                     SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField35A_CodeWord,                  0, "instr_cdw35a_c", "?", "instr_cdw35a_c",            SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35A_Quantity,                  0, "instr_units_q",  "?", "instr_units_q",             SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(srvrField35B_IdentificationOfSecurities,       hField35B_ISIN,                     0, "instr_isin",     "?", "instr_isin",                 SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField35B_IdentificationOfSecurities,       hField35B_DescriptionOfTheSecurity, 0, "instr_desc",     "?", "{fn RTRIM(instr_desc)}",     SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(srvrField35B_IdentificationOfSecuritiesBooked, hField35B_ISIN,                     1, "book_isin",      "?", "book_isin",                  SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField35B_IdentificationOfSecuritiesBooked, hField35B_DescriptionOfTheSecurity, 1, "book_desc",      "?", "{fn RTRIM(book_desc)}",      SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  
  ODBCBIND(srvrField35L_Terms, hField35L_SpecificationOfSecurities,      0, "terms_txt",      "?", "{fn RTRIM(terms_txt)}",      SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)

  ODBCBIND(NULL, hField35N_CodeWord,                  0, "distr_cdw35a_c", "?", "distr_cdw35a_c",            SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35N_Quantity,                  0, "distr_units_q",  "?", "distr_units_q",             SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField35P_CodeWord,                  0, "book_cdw35a_c",  "?", "book_cdw35a_c",             SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35P_Quantity,                  0, "book_units_q",   "?", "book_units_q",              SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField36_ExchangeRate,               0, "ex_rate",        "?", "ex_rate",                   SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 12)

  ODBCBIND(NULL, hField71E_CurrencyCode,              0, "tax_curr_iso",   "?", "tax_curr_iso",              SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField71E_Amount,                    0, "tax_amount_a",   "?", "tax_amount_a",              SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField71E_Rate,                      0, "tax_rate",       "?", "tax_rate",                  SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField71E_AdditionalInformation,     0, "tax_info_txt",   "?", "{fn RTRIM(tax_info_txt)}",  SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",            SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",    SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(NULL, hField80C_Narrative,                 0, "component_txt",  "?", "{fn RTRIM(component_txt)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,    0, "safe_crdr_f",    "?", "safe_crdr_f",                SQL_C_CHAR, SQL_CHAR,    1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber, 0, "safe_acct_name", "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR, SQL_VARCHAR, 34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,       0, "safe_bic",       "?", "safe_bic",                   SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress,    0, "safe_namaddr",   "?", "{fn RTRIM(safe_namaddr)}",   SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(MT555_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT556_SERVER

BEGIN_ODBCBIND(MT556_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",            "?", "{fn RTRIM(tran_id)}",       SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",        "?", "{fn RTRIM(rel_tran_id)}",   SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(srvrField23_FurtherIdentification, hField23_FurtherIdentification, 0, "further_txt",        "?", "further_txt",             SQL_C_CHAR,      SQL_CHAR,      8, 0, 8)
  ODBCBIND(NULL, hField31S_Date,                      0, "call_d",             "?", "call_d",                    SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField32M_CurrencyCode,              0, "reda_curr_iso",      "?", "reda_curr_iso",             SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField32M_Amount,                    0, "reda_a",             "?", "reda_a",                    SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 15)

  ODBCBIND(NULL, hField33T_PriceOrCurrencyCode,       0, "red_curr_cw",        "?", "red_curr_cw",               SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField33T_Amount,                    0, "red_price_a",        "?", "red_price_a",               SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 15)

  ODBCBIND(NULL, hField34CD_CreditOrDebit,            0, "net_crdr_f",         "?", "net_crdr_f",                SQL_C_CHAR,      SQL_CHAR,        1,   0, 1)
  ODBCBIND(NULL, hField34CD_Date,                     0, "net_d",              "?", "net_d",                     SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField34CD_CurrencyCode,             0, "net_curr_iso",       "?", "net_curr_iso",              SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField34CD_Amount,                   0, "net_a",              "?", "net_a",                     SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 15)

  ODBCBIND(NULL, hField35A_CodeWord,                  0, "instr_cdw35a_c",     "?", "instr_cdw35a_c",            SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField35A_Quantity,                  0, "instr_units_q",      "?", "instr_units_q",             SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 15)

  ODBCBIND(NULL, hField35B_ISIN,                      0, "instr_isin",         "?", "instr_isin",                SQL_C_CHAR,      SQL_CHAR,        12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",         "?", "{fn RTRIM(instr_desc)}",    SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)

  ODBCBIND(NULL, hField35D_SpecificationOfSecurities, 0, "due_d",              "?", "due_d",                     SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField35E_SpecificationOfSecurities, 0, "instr_cert_num_txt", "?", "instr_cert_num_txt",        SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)
  ODBCBIND(srvrField35L_Terms,              hField35L_SpecificationOfSecurities, 0, "terms_txt",          "?", "{fn RTRIM(terms_txt)}",     SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
  ODBCBIND(NULL, hField36_ExchangeRate,               0, "ex_rate",            "?", "ex_rate",                   SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 12)

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c",     "?", "srinfo_cdw72_c",            SQL_C_CHAR,      SQL_VARCHAR,     8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",         "?", "{fn RTRIM(srinfo_txt)}",    SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)

  ODBCBIND(NULL, hField75_AdditionalInformation,      0, "query_txt",          "?", "{fn RTRIM(query_txt)}",     SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)
  ODBCBIND(NULL, hField80C_Narrative,                 0, "component_txt",      "?", "{fn RTRIM(component_txt)}", SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,        0, "safe_crdr_f",        "?", "safe_crdr_f",                 SQL_C_CHAR,      SQL_CHAR,        1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,                   0, "safe_acct_name",     "?", "{fn RTRIM(safe_acct_name)}",  SQL_C_CHAR,      SQL_VARCHAR,     34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,              0, "safe_bic",           "?", "safe_bic",                    SQL_C_CHAR,      SQL_CHAR,        12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress,        0, "safe_namaddr",       "?", "{fn RTRIM(safe_namaddr)}",    SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)
END_ODBCBIND(MT556_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT557_SERVER

BEGIN_ODBCBIND(MT557_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",        "?", "{fn RTRIM(tran_id)}",       SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",    "?", "{fn RTRIM(rel_tran_id)}",   SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(srvrField23_FurtherIdentification, hField23_FurtherIdentification, 0, "further_txt",    "?", "further_txt",           SQL_C_CHAR, SQL_CHAR,    8,  0, 8)
  ODBCBIND(NULL, hField32G_CurrencyCode,              0, "gross_curr_iso", "?", "gross_curr_iso",            SQL_C_CHAR,      SQL_CHAR,        3,   0, 8)
  ODBCBIND(NULL, hField32G_Amount,                    0, "gross_amount_a", "?", "gross_amount_a",            SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 18)
  ODBCBIND(NULL, hField32M_CurrencyCode,              0, "red_curr_iso",   "?", "red_curr_iso",              SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField32M_Amount,                    0, "red_amount_a",   "?", "red_amount_a",              SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 15)
  ODBCBIND(NULL, hField34A_Date,                      0, "net_d",          "?", "net_d",                     SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField34A_CurrencyCode,              0, "net_curr_iso",   "?", "net_curr_iso",              SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField34A_Amount,                    0, "net_a",          "?", "net_a",                     SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 18)
  ODBCBIND(NULL, hField36_ExchangeRate,               0, "ex_rate",        "?", "ex_rate",                   SQL_C_CHAR,      SQL_DECIMAL,     18,  3, 12)
  ODBCBIND(NULL, hField79_Narrative,                  0, "narrative_txt",  "?", "narrative_txt",             SQL_C_CHAR,      SQL_LONGVARCHAR, 0,   0, 1850)
  ODBCBIND(NULL, hField80C_Narrative,                 0, "component_txt",  "?", "{fn RTRIM(component_txt)}", SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)

  ODBCBIND(srvrField53a_AccountForPayment, hFieldXXa_CreditedOrDebitedAccount,     0, "pay_crdr_f",     "?", "pay_crdr_f",                 SQL_C_CHAR,      SQL_CHAR,        1,   0, 1)
  ODBCBIND(srvrField53a_AccountForPayment, hFieldXXa_AccountNumber,                0, "pay_acct_name",  "?", "{fn RTRIM(pay_acct_name)}",  SQL_C_CHAR,      SQL_VARCHAR,     34,  0, 34)
  ODBCBIND(srvrField53a_AccountForPayment, hFieldXXa_BankIdentifierCode,           0, "pay_bic",        "?", "pay_bic",                    SQL_C_CHAR,      SQL_CHAR,        12,  0, 12)
  ODBCBIND(srvrField53a_AccountForPayment, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "pay_namaddr",    "?", "{fn RTRIM(pay_namaddr)}",    SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)
END_ODBCBIND(MT557_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT559_SERVER

BEGIN_ODBCBIND(MT559_SERVER)
  ODBCBIND(NULL, hField19_SumOfAmount,           0, "net_sum_a",       "?", "net_sum_a",              SQL_C_CHAR, SQL_DECIMAL, 23, 3, 17)
  ODBCBIND(srvrField23_FurtherIdentification, hField23_FurtherIdentification, 0, "further_txt",     "?", "further_txt",            SQL_C_CHAR, SQL_CHAR,    8,  0, 8)

  ODBCBIND(NULL, hField72_CodeWord,              0, "srinfo_cdw72_c",  "?", "srinfo_cdw72_c",         SQL_C_CHAR, SQL_CHAR,    8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation, 0, "srinfo_txt",      "?", "{fn RTRIM(srinfo_txt)}", SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(MT559_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT559SUB_SERVER

BEGIN_ODBCBIND(MT559SUB_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",        "?", "{fn RTRIM(tran_id)}",       SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField31C_Date,                      0, "pay_d",          "?", "pay_d",                     SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31E_Date,                      0, "record_d",       "?", "record_d",                  SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31L_Date,                      0, "clip_d",         "?", "clip_d",                    SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31S_Date,                      0, "call_d",         "?", "call_d",                    SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField32G_CurrencyCode,              0, "gross_curr_iso", "?", "gross_curr_iso",            SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32G_Amount,                    0, "gross_a",        "?", "gross_a",                   SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField32M_CurrencyCode,              0, "reda_curr_iso",  "?", "reda_curr_iso",             SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32M_Amount,                    0, "reda_a",         "?", "reda_a",                    SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField33T_PriceOrCurrencyCode,       0, "red_curr_cw",    "?", "red_curr_cw",               SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33T_Amount,                    0, "red_price_a",    "?", "red_price_a",               SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 18)
  ODBCBIND(NULL, hField34A_Date,                      0, "net_d",          "?", "net_d",                     SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField34A_CurrencyCode,              0, "net_curr_iso",   "?", "net_curr_iso",              SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField34A_Amount,                    0, "net_a",          "?", "net_a",                     SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField35A_CodeWord,                  0, "instr_cdw35a_c", "?", "instr_cdw35a_c",            SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35A_Quantity,                  0, "instr_units_q",  "?", "instr_units_q",             SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField35B_ISIN,                      0, "instr_isin",     "?", "instr_isin",                SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",     "?", "{fn RTRIM(instr_desc)}",    SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField35C_SpecificationOfSecurities, 0, "coupon_num",     "?", "coupon_num",                SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35D_SpecificationOfSecurities, 0, "coupon_d",       "?", "coupon_d",                  SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField35E_SpecificationOfSecurities, 0, "cert_num_txt",   "?", "cert_num_txt",              SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField35L_SpecificationOfSecurities, 0, "terms_txt",      "?", "{fn RTRIM(terms_txt)}",     SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField35U_PriceOrCurrencyCode,       0, "div_curr_cw",    "?", "div_curr_cw",               SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35U_Amount,                    0, "div_amount_a",   "?", "div_amount_a",              SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField35U_Code,                      0, "div_per_c",      "?", "div_per_c",                 SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(NULL, hField36_ExchangeRate,               0, "ex_rate",        "?", "ex_rate",                   SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 12)

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",            SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",    SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(NULL, hField75_AdditionalInformation,      0, "query_txt",      "?", "{fn RTRIM(query_txt)}",     SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField80C_Narrative,                 0, "component_txt",  "?", "{fn RTRIM(component_txt)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT559SUB_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// AMOUNT_ADDED_SERVER

BEGIN_ODBCBIND(AMOUNT_ADDED_SERVER)
  ODBCBIND(NULL, hField73_CodeWord,              0, "cdw73_c",  "?", "cdw73_c",              SQL_C_CHAR, SQL_CHAR,    8,   0, 8)
  ODBCBIND(NULL, hField73_CurrencyCode,          0, "curr_iso", "?", "curr_iso",             SQL_C_CHAR, SQL_CHAR,    3,   0, 3)
  ODBCBIND(NULL, hField73_Amount,                0, "amount_a", "?", "amount_a",             SQL_C_CHAR, SQL_DECIMAL, 18,  3, 13)
  ODBCBIND(NULL, hField73_AdditionalInformation, 0, "add_info", "?", "{fn RTRIM(add_info)}", SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(AMOUNT_ADDED_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT560_SERVER

BEGIN_ODBCBIND(MT560_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",        "?", "{fn RTRIM(tran_id)}",       SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(NULL, hField30_Date,                       0, "proxy_dl",       "?", "proxy_dl",                  SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",            SQL_C_CHAR,      SQL_VARCHAR,     8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",    SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)

  ODBCBIND(NULL, hField79_Narrative,                  0, "narrative_txt",  "?", "narrative_txt",             SQL_C_CHAR,      SQL_LONGVARCHAR, 0,   0, 1850)
  ODBCBIND(NULL, hField80A_Narrative,                 0, "cmp_nam",        "?", "{fn RTRIM(cmp_nam)}",       SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)
END_ODBCBIND(MT560_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT561_SERVER

BEGIN_ODBCBIND(MT561_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",        "?", "{fn RTRIM(tran_id)}",       SQL_C_CHAR, SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",    "?", "{fn RTRIM(rel_tran_id)}",   SQL_C_CHAR, SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",            SQL_C_CHAR, SQL_CHAR,        8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",    SQL_C_CHAR, SQL_VARCHAR,     254, 0, 254)
  ODBCBIND(NULL, hField79_Narrative,                  0, "narrative_txt",  "?", "narrative_txt",             SQL_C_CHAR, SQL_LONGVARCHAR, 0,   0, 1850)
  ODBCBIND(NULL, hField80A_Narrative,                 0, "cmp_nam",        "?", "{fn RTRIM(cmp_nam)}",       SQL_C_CHAR, SQL_VARCHAR,     254, 0, 254)
  ODBCBIND(NULL, hField80B_Narrative,                 0, "proxy",          "?", "{fn RTRIM(proxy)}",         SQL_C_CHAR, SQL_VARCHAR,     254, 0, 254)
END_ODBCBIND(MT561_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT56INSTR_SERVER

BEGIN_ODBCBIND(MT56INSTR_SERVER)
  ODBCBIND(NULL, hField35B_ISIN,                     0, "instr_isin", "?", "instr_isin",             SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity, 0, "instr_desc", "?", "{fn RTRIM(instr_desc)}", SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(MT56INSTR_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT56INSTR_A_SERVER

BEGIN_ODBCBIND(MT56INSTR_A_SERVER)
  ODBCBIND(NULL, hField35A_CodeWord,  0, "instr_cdw35a_c", "?", "instr_cdw35a_c",             SQL_C_CHAR, SQL_CHAR,    3,   0, 3)
  ODBCBIND(NULL, hField35A_Quantity,  0, "instr_units_q",  "?", "instr_units_q",              SQL_C_CHAR, SQL_DECIMAL, 18,  3, 15)

  ODBCBIND(NULL, hFieldXXa_CreditedOrDebitedAccount,    0, "safe_crdr_f",    "?", "safe_crdr_f",                SQL_C_CHAR, SQL_CHAR,    1,   0, 1)
  ODBCBIND(NULL, hFieldXXa_AccountNumber,               0, "safe_acct_name", "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR, SQL_VARCHAR, 34,  0, 34)
  ODBCBIND(NULL, hFieldXXa_BankIdentifierCode,          0, "safe_bic",       "?", "safe_bic",                   SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(NULL, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namadd",    "?", "{fn RTRIM(safe_namadd)}",    SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(MT56INSTR_A_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT562_SERVER

BEGIN_ODBCBIND(MT562_SERVER)
  ODBCBIND(NULL, hField11a_ReceivedOrSent,            0, "orig_dir",       "?", "orig_dir",                 SQL_C_CHAR,      SQL_CHAR,        1, 0, 1)
  ODBCBIND(NULL, hField11a_MessageType,               0, "orig_mt",        "?", "orig_mt",                  SQL_C_CHAR,      SQL_CHAR,        3,   0, 3)
  ODBCBIND(NULL, hField11a_Date,                      0, "orig_d",         "?", "orig_d",                   SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField11a_SessionNumber,             0, "orig_sn",        "?", "orig_sn",                  SQL_C_SLONG,     SQL_CHAR,        4,   0, sizeof(SLONG))
  ODBCBIND(NULL, hField11a_SequenceNumber,            0, "orig_seq",       "?", "orig_seq",                 SQL_C_SLONG,     SQL_CHAR,        6,   0, sizeof(SLONG))

  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "trans_id",       "?", "{fn RTRIM(trans_id)}",     SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_trans_id",   "?", "{fn RTRIM(rel_trans_id)}", SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)

  ODBCBIND(srvrField23_FurtherIdentification, hField23_Subfield1,    0, "further_act",    "?", "further_act",  SQL_C_CHAR,      SQL_CHAR, 8, 0, 8)
  ODBCBIND(srvrField23_FurtherIdentification, hField23_Subfield2,    0, "further_stat",   "?", "further_stat", SQL_C_CHAR,      SQL_CHAR, 8, 0, 8)

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",           SQL_C_CHAR,      SQL_VARCHAR,     8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",   SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)

  ODBCBIND(NULL, hField79_Narrative,                  0, "narrative_txt",  "?", "narrative_txt",            SQL_C_CHAR,      SQL_LONGVARCHAR, 0,   0, 16*1024)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,    0, "safe_crdr_f",    "?", "safe_crdr_f",                SQL_C_CHAR, SQL_CHAR,    1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,               0, "safe_acct_name", "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR, SQL_VARCHAR, 34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,          0, "safe_bic",       "?", "safe_bic",                   SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",   "?", "{fn RTRIM(safe_namaddr)}",   SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(MT562_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT563_SERVER

BEGIN_ODBCBIND(MT563_SERVER)
  ODBCBIND(NULL, hField11a_ReceivedOrSent,            0, "orig_dir",       "?", "orig_dir", SQL_C_CHAR,      SQL_CHAR,      1, 0, 1)
  ODBCBIND(NULL, hField11a_MessageType,               0, "orig_mt",        "?", "orig_mt",  SQL_C_CHAR,      SQL_CHAR,      3, 0, 3)
  ODBCBIND(NULL, hField11a_Date,                      0, "orig_d",         "?", "orig_d",   SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0, 0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField11a_SessionNumber,             0, "orig_sn",        "?", "orig_sn",  SQL_C_SLONG,     SQL_CHAR,      4, 0, sizeof(SLONG))
  ODBCBIND(NULL, hField11a_SequenceNumber,            0, "orig_seq",       "?", "orig_seq", SQL_C_SLONG,     SQL_CHAR,      6, 0, sizeof(SLONG))

  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "trans_id",       "?", "{fn RTRIM(trans_id)}",      SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_trans_id",   "?", "{fn RTRIM(rel_trans_id)}",  SQL_C_CHAR,      SQL_VARCHAR,     16,  0, 16)

  ODBCBIND(srvrField23_FurtherIdentification, hField23_FurtherIdentification,        0, "further",        "?", "further",  SQL_C_CHAR,      SQL_CHAR,      8, 0, 8)
  ODBCBIND(NULL, hField30_Date,                       0, "exec_d",         "?", "exec_d",                    SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",            SQL_C_CHAR,      SQL_VARCHAR,     8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",    SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)

  ODBCBIND(NULL, hField77B_Narrative,                 0, "other_drv",      "?", "{fn RTRIM(other_drv)}",     SQL_C_CHAR,      SQL_VARCHAR,     254, 0, 254)
  ODBCBIND(NULL, hField79_Narrative,                  0, "narrative_txt",  "?", "narrative_txt",             SQL_C_CHAR,      SQL_LONGVARCHAR, 0,   0, 16*1024)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,    0, "safe_crdr_f",    "?", "safe_crdr_f",                SQL_C_CHAR, SQL_CHAR,    1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,               0, "safe_acct_name", "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR, SQL_VARCHAR, 34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,          0, "safe_bic",       "?", "safe_bic",                   SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",   "?", "{fn RTRIM(safe_namaddr)}",   SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(MT563_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT563SB_SERVER

BEGIN_ODBCBIND(MT563SB_SERVER)
  ODBCBIND(NULL, hField35A_CodeWord,                 0, "instr_cdw35a_c", "?", "instr_cdw35a_c",         SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35A_Quantity,                 0, "instr_units_q",  "?", "instr_units_q",          SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField35B_ISIN,                     0, "instr_isin",     "?", "instr_isin",             SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity, 0, "instr_desc",     "?", "{fn RTRIM(instr_desc)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT563SB_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT563SB1_SERVER

BEGIN_ODBCBIND(MT563SB1_SERVER)
  ODBCBIND(NULL, hField31L_Date,                      0, "instr_cr_d",        "?", "instr_cr_d",                SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField31S_Date,                      0, "parry",             "?", "parry",                     SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField32B_CurrencyCode,              0, "settle_curr_iso",   "?", "settle_curr_iso",           SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32B_Amount,                    0, "settle_amount_a",   "?", "settle_amount_a",           SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField33B_PriceOrCurrencyCode,       0, "subs_cur_iso",      "?", "subs_cur_iso",              SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33B_Amount,                    0, "subs_a",            "?", "subs_a",                    SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField33S_PriceOrCurrencyCode,       0, "conces_cur_iso",    "?", "conces_cur_iso",            SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33S_Amount,                    0, "conces_a",          "?", "conces_a",                  SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField34A_Date,                      0, "netproc_d",         "?", "netproc_d",                 SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField34A_CurrencyCode,              0, "netproc_cur_iso",   "?", "netproc_cur_iso",           SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField34A_Amount,                    0, "netproc_a",         "?", "netproc_a",                 SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField34GH_AddedOrDeducted,          0, "intrst_crdr_f",     "?", "intrst_crdr_f",             SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(NULL, hField34GH_NumberOfDays,             0, "intrst_days",       "?", "intrst_days",               SQL_C_SLONG,     SQL_INTEGER,   3,   0, sizeof(SLONG))
  ODBCBIND(NULL, hField34GH_CurrencyCode,             0, "intrst_curr_iso",   "?", "intrst_curr_iso",           SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField34GH_Amount,                   0, "intrst_a",          "?", "intrst_a",                  SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField35B_ISIN,                      0, "derinstr_isin",     "?", "derinstr_isin",             SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "derinstr_desc",     "?", "{fn RTRIM(derinstr_desc)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(NULL, hField35C_SpecificationOfSecurities, 0, "coupon_num",        "?", "coupon_num",                SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35D_SpecificationOfSecurities, 0, "coupon_d",          "?", "coupon_d",                  SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField35S_CodeWord,                  0, "derinstr_cdw35a_c", "?", "derinstr_cdw35a_c",         SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35S_Quantity,                  0, "derinstr_q",        "?", "derinstr_q",                SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField36_ExchangeRate,               0, "ex_rate",           "?", "ex_rate",                   SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 12)
  ODBCBIND(NULL, hField77D_Narrative,                 0, "reg_det_txt",       "?", "{fn RTRIM(reg_det_txt)}",   SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField77R_Narrative,                 0, "legal_txt",         "?", "{fn RTRIM(legal_txt)}",     SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT563SB1_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT570_SERVER

BEGIN_ODBCBIND(MT570_SERVER)
  ODBCBIND(srvrField12_MessageType,                 hField12_MessageType,                0, "msg_type",        "?", "msg_type",                       SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(srvrField20_TransactionReferenceNumber,  hField20_TransactionReferenceNumber, 0, "tran_id",         "?", "{fn RTRIM(tran_id)}",            SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)

  ODBCBIND(srvrField67A_StatementPeriod,            hField67A_FirstDateOfPeriod,         0, "stat_open_d",    "?", "stat_open_d",                       SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(srvrField67A_StatementPeriod,            hField67A_LastDateOfPeriod,          0, "stat_close_d",   "?", "stat_close_d",                      SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(srvrField72_SenderToReceiverInformation, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",                    SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(srvrField72_SenderToReceiverInformation, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",            SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(srvrField83a_SafekeepingAccount,         hFieldXXa_CreditedOrDebitedAccount,    0, "safe_crdr_f",    "?", "safe_crdr_f",                SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount,         hFieldXXa_AccountNumber,               0, "safe_acct_name", "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount,         hFieldXXa_BankIdentifierCode,          0, "safe_bic",       "?", "safe_bic",                   SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount,         hFieldXXa_BranchIdentificationOrNameAndAddress,    0, "safe_namaddr",   "?", "{fn RTRIM(safe_namaddr)}",   SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)
END_ODBCBIND(MT570_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT570SUBB_SERVER

BEGIN_ODBCBIND(MT570SUBB_SERVER)
  ODBCBIND(srvrField35B_IdentificationOfSecurities, hField35B_ISIN,                     0, "instr_isin",      "?", "instr_isin",             SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField35B_IdentificationOfSecurities, hField35B_DescriptionOfTheSecurity, 0, "instr_desc",      "?", "{fn RTRIM(instr_desc)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT570SUBB_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT570SUBB1_SERVER

BEGIN_ODBCBIND(MT570SUBB1_SERVER)
  ODBCBIND(srvrField23_FurtherIdentification, hField23_FurtherIdentification,       0, "further_c",       "?", "further_c",          SQL_C_CHAR,      SQL_VARCHAR,   16, 0, 16)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,     0, "safe_crdr_f",     "?", "safe_crdr_f",                 SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,                0, "safe_acct_name",  "?", "{fn RTRIM(safe_acct_name)}",  SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,           0, "safe_bic",        "?", "safe_bic",                    SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",    "?", "{fn RTRIM(safe_namaddr)}",    SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT570SUBB1_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT570SUBC_SERVER

BEGIN_ODBCBIND(MT570SUBC_SERVER)
  ODBCBIND(srvrField23_FurtherIdentification, hField23_FurtherIdentification, 0, "further_c",      "?", "further_c",      SQL_C_CHAR,      SQL_VARCHAR,   16, 0, 16)
END_ODBCBIND(MT570SUBC_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT570SUBC1_SERVER

BEGIN_ODBCBIND(MT570SUBC1_SERVER)
  ODBCBIND(srvrField35B_IdentificationOfSecurities, hField35B_ISIN,                      0, "instr_isin",      "?", "instr_isin",              SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField35B_IdentificationOfSecurities, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",      "?", "{fn RTRIM(instr_desc)}",  SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,     0, "safe_crdr_f",     "?", "safe_crdr_f",                 SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,                0, "safe_acct_name",  "?", "{fn RTRIM(safe_acct_name)}",  SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,           0, "safe_bic",        "?", "safe_bic",                    SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",    "?", "{fn RTRIM(safe_namaddr)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT570SUBC1_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT571_SERVER

BEGIN_ODBCBIND(MT571_SERVER)
  ODBCBIND(srvrField20_TransactionReferenceNumber, hField20_TransactionReferenceNumber, 0, "trans_id",       "?", "{fn RTRIM(trans_id)}",              SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(srvrField21_RelatedReference,           hField21_RelatedReference,           0, "rel_trans_id",   "?", "{fn RTRIM(rel_trans_id)}",          SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(srvrField26F_StatementBasis,            hField26F_ItemIdentification,        0, "basis",          "?", "basis",                             SQL_C_CHAR,      SQL_VARCHAR,   9,   0, 9)
  ODBCBIND(srvrField28_PageNumberAndContinuationIndicator, hField28_StatementNumber,            0, "page_num",       "?", "page_num",                          SQL_C_SLONG,     SQL_INTEGER,   5,   0, sizeof(SLONG))
  ODBCBIND(srvrField28_PageNumberAndContinuationIndicator, hField28_PageNumber,                 0, "cnt_ind",        "?", "{fn CONVERT(cnt_ind,SQL_INTEGER)}", SQL_C_SLONG,     SQL_CHAR,      2,   0, sizeof(SLONG))
  ODBCBIND(srvrField30_DatePrepared,     hField30_Date,                       0, "date_prep_d",    "?", "date_prep_d",                       SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(srvrField34E_FinalValue,      hField34E_CurrencyCode, 0, "fin_val_iso",    "?", "fin_val_iso",           SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(srvrField34E_FinalValue,      hField34E_Amount,       0, "fin_val_a",      "?", "fin_val_a",             SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15+1)
  ODBCBIND(srvrField67A_StatementPeriod, hField67A_FirstDateOfPeriod,              0, "period_d",       "?", "period_d",                          SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(srvrField72_SenderToReceiverInformation, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",                    SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(srvrField72_SenderToReceiverInformation, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",            SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,    0, "safe_crdr_f",    "?", "safe_crdr_f",           SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,               0, "safe_acct_name", "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,          0, "safe_bic",       "?", "safe_bic",                   SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",   "?", "{fn RTRIM(safe_namaddr)}",   SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT571_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT571SUB_SERVER

BEGIN_ODBCBIND(MT571SUB_SERVER)
  ODBCBIND(NULL, hField32H_CurrencyCode,             0, "value_iso",       "?", "value_iso",         SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32H_Amount,                   0, "value_a",         "?", "value_a",           SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField33B_PriceOrCurrencyCode,      0, "unit_price_iso",  "?", "unit_price_iso",         SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33B_Amount,                   0, "unit_price_a",    "?", "unit_price_a",           SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(srvrField34a_AccruedInterest, hField34GH_AddedOrDeducted,         0, "intrst_crdr_f",   "?", "intrst_crdr_f",          SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField34a_AccruedInterest, hField34GH_NumberOfDays,            0, "intrst_days",     "?", "intrst_days",            SQL_C_SLONG,     SQL_INTEGER,   3,   0, sizeof(SLONG))
  ODBCBIND(srvrField34a_AccruedInterest, hField34GH_CurrencyCode,            0, "intrst_curr_iso", "?", "intrst_curr_iso",        SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(srvrField34a_AccruedInterest, hField34GH_Amount,                  0, "intrst_a",        "?", "intrst_a",               SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField35B_ISIN,                     0, "instr_isin",      "?", "instr_isin",             SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity, 0, "instr_desc",      "?", "{fn RTRIM(instr_desc)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField35H_CodeWord,                 0, "instr_cdw35a_c",  "?", "instr_cdw35a_c",         SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35H_Quantity,                 0, "instr_q",         "?", "instr_q",                SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField36_ExchangeRate,              0, "ex_rate",         "?", "ex_rate",                SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 12)
  ODBCBIND(srvrField72_SenderToReceiverInformation, hField72_CodeWord,                  0, "srinfo_cdw72_c",  "?", "srinfo_cdw72_c",         SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(srvrField72_SenderToReceiverInformation, hField72_AdditionalInformation,     0, "srinfo_txt",      "?", "{fn RTRIM(srinfo_txt)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT571SUB_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT571SUB1_SERVER

BEGIN_ODBCBIND(MT571SUB1_SERVER)
  ODBCBIND(srvrField23_FurtherIdentification, hField23_Subfield1,     0, "futher_chg",     "?", "futher_chg",        SQL_C_CHAR,      SQL_VARCHAR,   2,   0, 2)
  ODBCBIND(srvrField23_FurtherIdentification, hField23_Subfield2,     0, "futher_rsn",     "?", "futher_rsn",        SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)

  ODBCBIND(srvrField60B_QuantityOfSecurities, hField60B_Amount,       0, "instr_q",        "?", "instr_q",           SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 18)

  ODBCBIND(srvrField72_SenderToReceiverInformation, hField72_CodeWord,              0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",         SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(srvrField72_SenderToReceiverInformation, hField72_AdditionalInformation, 0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT571SUB1_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT572_SERVER

BEGIN_ODBCBIND(MT572_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "trans_id",       "?", "{fn RTRIM(trans_id)}",              SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_trans_id",   "?", "{fn RTRIM(rel_trans_id)}",          SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)

  ODBCBIND(NULL, hField28_StatementNumber,            0, "page_num",       "?", "page_num",                          SQL_C_SLONG,     SQL_INTEGER,   0,   0, sizeof(SLONG))
  ODBCBIND(NULL, hField28_PageNumber,                 0, "cnt_ind",        "?", "{fn CONVERT(cnt_ind,SQL_INTEGER)}", SQL_C_SLONG,     SQL_CHAR,      2,   0, sizeof(SLONG))

  ODBCBIND(NULL, hField30_Date,                       0, "date_prep_d",    "?", "date_prep_d",                       SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField67A_FirstDateOfPeriod,         0, "stat_open_d",    "?", "stat_open_d",                       SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField67A_LastDateOfPeriod,          0, "stat_close_d",   "?", "stat_close_d",                      SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",                    SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",            SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,    0, "safe_crdr_f",    "?", "safe_crdr_f",                SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,               0, "safe_acct_name", "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,          0, "safe_bic",       "?", "safe_bic",                   SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",   "?", "{fn RTRIM(safe_namaddr)}",   SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)
END_ODBCBIND(MT572_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT572SUB_SERVER

BEGIN_ODBCBIND(MT572SUB_SERVER)
  ODBCBIND(NULL, hField35B_ISIN,                     0, "instr_isin",      "?", "instr_isin",             SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity, 0, "instr_desc",      "?", "{fn RTRIM(instr_desc)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(srvrField60A_OpeningBalance, hField60A_Amount,           0, "op_bal_a",        "?", "op_bal_a",               SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15+1)
  ODBCBIND(srvrField62A_ClosingBalance, hField62A_Amount,           0, "clo_bal_a",       "?", "clo_bal_a",              SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15+1)
END_ODBCBIND(MT572SUB_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT572SUB1_SERVER

BEGIN_ODBCBIND(MT572SUB1_SERVER)
  ODBCBIND(srvrField60B_OpeningBalance, hField60B_Amount,        0, "op_bal_a",        "?", "op_bal_a",                   SQL_C_CHAR,      SQL_DECIMAL,   18, 3, 15+1)
  ODBCBIND(srvrField62B_ClosingBalance, hField62B_Amount,        0, "clo_bal_a",       "?", "clo_bal_a",                  SQL_C_CHAR,      SQL_DECIMAL,   18, 3, 15+1)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,     0, "safe_crdr_f",     "?", "safe_crdr_f",                SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,                0, "safe_acct_name",  "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,           0, "safe_bic",        "?", "safe_bic",                   SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",    "?", "{fn RTRIM(safe_namaddr)}",   SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)
END_ODBCBIND(MT572SUB1_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT572SUB2_SERVER

BEGIN_ODBCBIND(MT572SUB2_SERVER)
  ODBCBIND(NULL, hField30_Date,                       0, "settle_d",         "?", "settle_d",               SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField33B_PriceOrCurrencyCode,       0, "unit_price_cw",    "?", "unit_price_cw",          SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField33B_Amount,                    0, "unit_price_a",     "?", "unit_price_a",           SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField34CD_CreditOrDebit,            0, "amount_crdr_f",    "?", "amount_crdr_f",          SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(NULL, hField34CD_Date,                     0, "amount_d",         "?", "amount_d",               SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField34CD_CurrencyCode,             0, "amount_iso",       "?", "amount_iso",             SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField34CD_Amount,                   0, "amount_a",         "?", "amount_a",               SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField34GH_AddedOrDeducted,          0, "intrst_crdr_f",    "?", "intrst_crdr_f",          SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(NULL, hField34GH_NumberOfDays,             0, "intrst_days",      "?", "intrst_days",            SQL_C_SLONG,     SQL_INTEGER,   3,   0, sizeof(SLONG))
  ODBCBIND(NULL, hField34GH_CurrencyCode,             0, "intrst_curr_iso",  "?", "intrst_curr_iso",        SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField34GH_Amount,                   0, "intrst_a",         "?", "intrst_a",               SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField35A_CodeWord,                  0, "instr_cdw35a_c",   "?", "instr_cdw35a_c",         SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35A_Quantity,                  0, "instr_q",          "?", "instr_q",                SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField66A_PostingDate,               0, "trans_d",          "?", "trans_d",           SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,  0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField66A_DirectionOfTheTransaction, 0, "trans_dir",        "?", "trans_dir",         SQL_C_CHAR,      SQL_CHAR,      1,  0, 1)
  ODBCBIND(NULL, hField66A_TransactionType,           0, "trans_cdw66A_c",   "?", "trans_cdw66A_c",    SQL_C_SLONG,     SQL_INTEGER,   2,  0, sizeof(SLONG))
  ODBCBIND(NULL, hField66A_ReceiversReference,        0, "trans_own_ref_id", "?", "trans_own_ref_id",  SQL_C_CHAR,      SQL_VARCHAR,   16, 0, 16)
  ODBCBIND(NULL, hField66A_SendersReference,          0, "trans_sndr_ref_id","?", "trans_sndr_ref_id", SQL_C_CHAR,      SQL_VARCHAR,   16, 0, 16)

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c",   "?", "srinfo_cdw72_c",         SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",       "?", "{fn RTRIM(srinfo_txt)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(srvrField87a_Counterparty, hFieldXXa_CreditedOrDebitedAccount,     0, "cntrp_crdr_f",     "?", "cntrp_crdr_f",                SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrField87a_Counterparty, hFieldXXa_AccountNumber,                0, "cntrp_acct_name",  "?", "{fn RTRIM(cntrp_acct_name)}", SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrField87a_Counterparty, hFieldXXa_BankIdentifierCode,           0, "cntrp_bic",        "?", "cntrp_bic",                   SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrField87a_Counterparty, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "cntrp_namaddr",    "?", "{fn RTRIM(cntrp_namaddr)}",   SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)
END_ODBCBIND(MT572SUB2_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT573_SERVER

BEGIN_ODBCBIND(MT573_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",        "?", "{fn RTRIM(tran_id)}",               SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",    "?", "{fn RTRIM(rel_tran_id)}",           SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)

  ODBCBIND(NULL, hField28_StatementNumber,            0, "page_num",       "?", "page_num",                          SQL_C_SLONG,     SQL_INTEGER,   5,   0, sizeof(SLONG))
  ODBCBIND(NULL, hField28_PageNumber,                 0, "cnt_ind",        "?", "{fn CONVERT(cnt_ind,SQL_INTEGER)}", SQL_C_SLONG,     SQL_CHAR,      2,   0, sizeof(SLONG))

  ODBCBIND(NULL, hField30_Date,                       0, "date_prep_d",    "?", "date_prep_d",                       SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField67A_FirstDateOfPeriod,         0, "stat_open_d",    "?", "stat_open_d",                       SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField67A_LastDateOfPeriod,          0, "stat_close_d",   "?", "stat_close_d",                      SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",                    SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",            SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,    0, "safe_crdr_f",    "?", "safe_crdr_f",                SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,               0, "safe_acct_name", "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,          0, "safe_bic",       "?", "safe_bic",                   SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress,    0, "safe_namaddr",   "?", "{fn RTRIM(safe_namaddr)}",   SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)
END_ODBCBIND(MT573_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT573SUBB_SERVER

BEGIN_ODBCBIND(MT573SUBB_SERVER)
  ODBCBIND(NULL, hField35B_ISIN,                     0, "instr_isin",      "?", "instr_isin",             SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity, 0, "instr_desc",      "?", "{fn RTRIM(instr_desc)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT573SUBB_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT573SUBB1_SERVER

BEGIN_ODBCBIND(MT573SUBB1_SERVER)
  ODBCBIND(NULL, hField11a_MessageType,               0, "orig_mt",         "?", "orig_mt",            SQL_C_CHAR,      SQL_CHAR,      3,  0, 3)
  ODBCBIND(NULL, hField11a_Date,                      0, "orig_d",          "?", "orig_d",             SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,  0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",         "?", "{fn RTRIM(tran_id)}",     SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",     "?", "{fn RTRIM(rel_tran_id)}", SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)

  ODBCBIND(srvrField23_FurtherIdentification, hField23_FurtherIdentification,       0, "further_c",       "?", "further_c",          SQL_C_CHAR,      SQL_VARCHAR,   16, 0, 16)
  ODBCBIND(NULL, hField30_Date,                       0, "settle_d",        "?", "settle_d",                SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField32B_CurrencyCode,              0, "settle_curr_iso", "?", "settle_curr_iso",         SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32B_Amount,                    0, "settle_amount_a", "?", "settle_amount_a",         SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField35A_CodeWord,                  0, "instr_cdw35a_c",  "?", "instr_cdw35a_c",          SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35A_Quantity,                  0, "instr_q",         "?", "instr_q",                 SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c",  "?", "srinfo_cdw72_c",          SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",      "?", "{fn RTRIM(srinfo_txt)}",  SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,     0, "safe_crdr_f",     "?", "safe_crdr_f",                 SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,                0, "safe_acct_name",  "?", "{fn RTRIM(safe_acct_name)}",  SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,           0, "safe_bic",        "?", "safe_bic",                    SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",    "?", "{fn RTRIM(safe_namaddr)}",    SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(srvrField87a_Counterparty,       hFieldXXa_CreditedOrDebitedAccount,     0, "cntrp_crdr_f",    "?", "cntrp_crdr_f",           SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField87a_Counterparty,       hFieldXXa_AccountNumber,                0, "cntrp_acct_name", "?", "{fn RTRIM(cntrp_acct_name)}", SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField87a_Counterparty,       hFieldXXa_BankIdentifierCode,           0, "cntrp_bic",       "?", "cntrp_bic",                   SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField87a_Counterparty,       hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "cntrp_namaddr",   "?", "{fn RTRIM(cntrp_namaddr)}",   SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT573SUBB1_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT573SUBC_SERVER

BEGIN_ODBCBIND(MT573SUBC_SERVER)
  ODBCBIND(srvrField23_FurtherIdentification, hField23_FurtherIdentification, 0, "further_c",      "?", "further_c",      SQL_C_CHAR,      SQL_VARCHAR,   16, 0, 16)
END_ODBCBIND(MT573SUBC_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT573SUBC1_SERVER

BEGIN_ODBCBIND(MT573SUBC1_SERVER)
  ODBCBIND(NULL, hField11a_MessageType,               0, "orig_mt",         "?", "orig_mt",            SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField11a_Date,                      0, "orig_d",          "?", "orig_d",             SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",         "?", "{fn RTRIM(tran_id)}",     SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",     "?", "{fn RTRIM(rel_tran_id)}", SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)

  ODBCBIND(NULL, hField30_Date,                       0, "settle_d",        "?", "settle_d",                SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(NULL, hField32B_CurrencyCode,              0, "settle_curr_iso", "?", "settle_curr_iso",         SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32B_Amount,                    0, "settle_amount_a", "?", "settle_amount_a",         SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(NULL, hField35A_CodeWord,                  0, "instr_cdw35a_c",  "?", "instr_cdw35a_c",          SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField35A_Quantity,                  0, "instr_q",         "?", "instr_q",                 SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(NULL, hField35B_ISIN,                      0, "instr_isin",      "?", "instr_isin",              SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(NULL, hField35B_DescriptionOfTheSecurity,  0, "instr_desc",      "?", "{fn RTRIM(instr_desc)}",  SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,     0, "safe_crdr_f",     "?", "safe_crdr_f",                 SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,                0, "safe_acct_name",  "?", "{fn RTRIM(safe_acct_name)}",  SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,           0, "safe_bic",        "?", "safe_bic",                    SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",    "?", "{fn RTRIM(safe_namaddr)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(srvrField87a_Counterparty,       hFieldXXa_CreditedOrDebitedAccount,     0, "cntrp_crdr_f",    "?", "cntrp_crdr_f",                     SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField87a_Counterparty,       hFieldXXa_AccountNumber,                0, "cntrp_acct_name", "?", "{fn RTRIM(cntrp_acct_name)}",      SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField87a_Counterparty,       hFieldXXa_BankIdentifierCode,           0, "cntrp_bic",       "?", "cntrp_bic",                        SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField87a_Counterparty,       hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "cntrp_namaddr",   "?", "{fn RTRIM(cntrp_namaddr)}",   SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72_c",  "?", "srinfo_cdw72_c",          SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",      "?", "{fn RTRIM(srinfo_txt)}",  SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT573SUBC1_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT574_SERVER

BEGIN_ODBCBIND(MT574_SERVER)
  ODBCBIND(srvrField20_TransactionReferenceNumber, hField20_TransactionReferenceNumber, 0, "tran_id",        "?", "{fn RTRIM(tran_id)}",               SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(srvrField21_RelatedReference,           hField21_RelatedReference,           0, "rel_tran_id",    "?", "{fn RTRIM(rel_tran_id)}",           SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)

  ODBCBIND(srvrField28_PageNumberAndContinuationIndicator, hField28_StatementNumber,    0, "page_num",       "?", "page_num",                          SQL_C_SLONG,     SQL_INTEGER,   5,   0, sizeof(SLONG))
  ODBCBIND(srvrField28_PageNumberAndContinuationIndicator, hField28_PageNumber,         0, "cnt_ind",        "?", "{fn CONVERT(cnt_ind,SQL_INTEGER)}", SQL_C_SLONG,     SQL_CHAR,      2,   0, sizeof(SLONG))

  ODBCBIND(srvrField30_DatePrepared,                       hField30_Date,               0, "date_prep_d",    "?", "date_prep_d",                       SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(srvrField67A_StatementPeriod,                   hField67A_FirstDateOfPeriod, 0, "stat_open_d",    "?", "stat_open_d",                       SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(srvrField67A_StatementPeriod,                   hField67A_LastDateOfPeriod,  0, "stat_close_d",   "?", "stat_close_d",                      SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(srvrField72_SenderToReceiverInformation, hField72_CodeWord,                   0, "srinfo_cdw72_c", "?", "srinfo_cdw72_c",                    SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(srvrField72_SenderToReceiverInformation, hField72_AdditionalInformation,      0, "srinfo_txt",     "?", "{fn RTRIM(srinfo_txt)}",            SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,    0, "safe_crdr_f",    "?", "safe_crdr_f",                SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,               0, "safe_acct_name", "?", "{fn RTRIM(safe_acct_name)}", SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,          0, "safe_bic",       "?", "safe_bic",                   SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress,    0, "safe_namaddr",   "?", "{fn RTRIM(safe_namaddr)}",   SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)
END_ODBCBIND(MT574_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT574SUB_SERVER

BEGIN_ODBCBIND(MT574SUB_SERVER)
  ODBCBIND(srvrField35B_IdentificationOfSecurities, hField35B_ISIN,                     0, "instr_isin",      "?", "instr_isin",             SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField35B_IdentificationOfSecurities, hField35B_DescriptionOfTheSecurity, 0, "instr_desc",      "?", "{fn RTRIM(instr_desc)}", SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT574SUB_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT574SUB1_SERVER

BEGIN_ODBCBIND(MT574SUB1_SERVER)
  ODBCBIND(NULL, hField11a_MessageType,    0, "orig_mt",  "?", "orig_mt",  SQL_C_CHAR,      SQL_CHAR,      3,  0, 3)
  ODBCBIND(NULL, hField11a_Date,           0, "orig_d",   "?", "orig_d",   SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,  0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField11a_SessionNumber,  0, "orig_sn",  "?", "orig_sn",  SQL_C_SLONG,     SQL_CHAR,      4,  0, sizeof(SLONG))
  ODBCBIND(NULL, hField11a_SequenceNumber, 0, "orig_seq", "?", "orig_seq", SQL_C_SLONG,     SQL_CHAR,      6,  0, sizeof(SLONG))

  ODBCBIND(srvrField20_TransactionReferenceNumber, hField20_TransactionReferenceNumber, 0, "tran_id",         "?", "{fn RTRIM(tran_id)}",     SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(srvrField21_RelatedReference,           hField21_RelatedReference,           0, "rel_tran_id",     "?", "{fn RTRIM(rel_tran_id)}", SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(srvrField23_FurtherIdentification, hField23_FurtherIdentification,       0, "further_txt",       "?", "{fn RTRIM(further_txt)}",          SQL_C_CHAR,      SQL_VARCHAR,   16, 0, 16)
  ODBCBIND(srvrField31C_ExpiryDate, hField31C_Date,                 0, "exp_d",           "?", "exp_d",                SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))

  ODBCBIND(srvrField32L_PriceLimit, hField32L_PriceOrCurrencyCode,  0, "price_lim_cur",   "?", "price_lim_cur",             SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(srvrField32L_PriceLimit, hField32L_Amount,               0, "price_lim_a",     "?", "price_lim_a",               SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(srvrField32L_PriceLimit, hField32L_FurtherQualification, 0, "price_lim_fur",   "?", "{fn RTRIM(price_lim_fur)}", SQL_C_CHAR,      SQL_VARCHAR,   35,  0, 35)

  ODBCBIND(srvrField35A_QuantityOfSecurities, hField35A_CodeWord,   0, "instr_cdw35a_c",  "?", "instr_cdw35a_c",        SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(srvrField35A_QuantityOfSecurities, hField35A_Quantity,   0, "instr_q",         "?", "instr_q",               SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)

  ODBCBIND(srvrField72_SenderToReceiverInformation, hField72_CodeWord,              0, "srinfo_cdw72_c",  "?", "srinfo_cdw72_c",          SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(srvrField72_SenderToReceiverInformation, hField72_AdditionalInformation, 0, "srinfo_txt",      "?", "{fn RTRIM(srinfo_txt)}",  SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)

  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_CreditedOrDebitedAccount,     0, "safe_crdr_f",     "?", "safe_crdr_f",                 SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_AccountNumber,                0, "safe_acct_name",  "?", "{fn RTRIM(safe_acct_name)}",  SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BankIdentifierCode,           0, "safe_bic",        "?", "safe_bic",                    SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField83a_SafekeepingAccount, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "safe_namaddr",    "?", "{fn RTRIM(safe_namaddr)}",    SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT574SUB1_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT202_SERVER

BEGIN_ODBCBIND(MT202_SERVER)
  ODBCBIND(srvrField20_TransactionReferenceNumber, hField20_TransactionReferenceNumber,  0, "tran_id",         "?", "{fn RTRIM(tran_id)}",     SQL_C_CHAR, SQL_VARCHAR, 16, 0, 16)
  ODBCBIND(srvrField21_RelatedReference,           hField21_RelatedReference,            0, "rel_tran_id",     "?", "{fn RTRIM(rel_tran_id)}", SQL_C_CHAR, SQL_VARCHAR, 16, 0, 16)

  ODBCBIND(srvrField32A_ValueDateCurrencyCodeAmount, hField32A_Date,                     0, "val_d",           "?", "val_d",           SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0, 0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(srvrField32A_ValueDateCurrencyCodeAmount, hField32A_PriceOrCurrencyCode,      0, "val_curr_iso",    "?", "val_curr_iso",    SQL_C_CHAR, SQL_CHAR,     3,   0, 3)
  ODBCBIND(srvrField32A_ValueDateCurrencyCodeAmount, hField32A_Amount,                   0, "val_a",           "?", "val_a",           SQL_C_CHAR, SQL_DECIMAL,  18,  3, 15)

  ODBCBIND(srvrField52a_OrderingInstitution,    hFieldXXa_CreditedOrDebitedAccount,      0, "ord_crdr_f",      "?", "ord_crdr_f",      SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrField52a_OrderingInstitution,    hFieldXXa_AccountNumber,                 0, "ord_acct_name",   "?", "ord_acct_name",   SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrField52a_OrderingInstitution,    hFieldXXa_BankIdentifierCode,            0, "ord_bic",         "?", "ord_bic",         SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrField52a_OrderingInstitution,    hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "ord_namaddr",     "?", "ord_namaddr",     SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)

  ODBCBIND(srvrField53a_SendersCorrespondent,   hFieldXXa_CreditedOrDebitedAccount,      0, "scor_crdr_f",     "?", "scor_crdr_f",     SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrField53a_SendersCorrespondent,   hFieldXXa_AccountNumber,                 0, "scor_acct_name",  "?", "scor_acct_name",  SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrField53a_SendersCorrespondent,   hFieldXXa_BankIdentifierCode,            0, "scor_bic",        "?", "scor_bic",        SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrField53a_SendersCorrespondent,   hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "scor_namaddr",    "?", "scor_namaddr",    SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)

  ODBCBIND(srvrField54a_ReceiversCorrespondent, hFieldXXa_CreditedOrDebitedAccount,      0, "rcor_crdr_f",     "?", "rcor_crdr_f",     SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrField54a_ReceiversCorrespondent, hFieldXXa_AccountNumber,                 0, "rcor_acct_name",  "?", "rcor_acct_name",  SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrField54a_ReceiversCorrespondent, hFieldXXa_BankIdentifierCode,            0, "rcor_bic",        "?", "rcor_bic",        SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrField54a_ReceiversCorrespondent, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "rcor_namaddr",    "?", "rcor_namaddr",    SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)

  ODBCBIND(srvrField56a_Intermediary,           hFieldXXa_CreditedOrDebitedAccount,      0, "inter_crdr_f",    "?", "inter_crdr_f",    SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrField56a_Intermediary,           hFieldXXa_AccountNumber,                 0, "inter_acct_name", "?", "inter_acct_name", SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrField56a_Intermediary,           hFieldXXa_BankIdentifierCode,            0, "inter_bic",       "?", "inter_bic",       SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrField56a_Intermediary,           hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "inter_namaddr",   "?", "inter_namaddr",   SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)

  ODBCBIND(srvrField57a_AccountWithInstitution, hFieldXXa_CreditedOrDebitedAccount,      0, "inst_crdr_f",     "?", "inst_crdr_f",     SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrField57a_AccountWithInstitution, hFieldXXa_AccountNumber,                 0, "inst_acct_name",  "?", "inst_acct_name",  SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrField57a_AccountWithInstitution, hFieldXXa_BankIdentifierCode,            0, "inst_bic",        "?", "inst_bic",        SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrField57a_AccountWithInstitution, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "inst_namadr",     "?", "inst_namadr",     SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)

  ODBCBIND(srvrField58a_BeneficiaryInstitution, hFieldXXa_CreditedOrDebitedAccount,      0, "ben_crdr_f",      "?", "ben_crdr_f",      SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrField58a_BeneficiaryInstitution, hFieldXXa_AccountNumber,                 0, "ben_acct_name",   "?", "ben_acct_name",   SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrField58a_BeneficiaryInstitution, hFieldXXa_BankIdentifierCode,            0, "ben_bic",         "?", "ben_bic",         SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrField58a_BeneficiaryInstitution, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "ben_namaddr",     "?", "ben_namaddr",     SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)

  ODBCBIND(srvrField72_SenderToReceiverInformation, hField72_CodeWord,                   0, "srinfo_cdw72_c",   "?", "srinfo_cdw72_c",           SQL_C_CHAR, SQL_VARCHAR, 8,   0, 8)
  ODBCBIND(srvrField72_SenderToReceiverInformation, hField72_AdditionalInformation,      0, "srinfo_txt",      "?", "{fn RTRIM(srinfo_txt)}",  SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(MT202_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// UMT202_SERVER

BEGIN_ODBCBIND(UMT202_SERVER)
  ODBCBIND(srvrUneiField20_SendersReference, hUneiField20_Reference, 0, "tran_id",         "?", "{fn RTRIM(tran_id)}",     SQL_C_CHAR, SQL_VARCHAR, 16, 0, 16)
  ODBCBIND(srvrUneiField21_RelatedReference, hUneiField21_Reference, 0, "rel_tran_id",     "?", "{fn RTRIM(rel_tran_id)}", SQL_C_CHAR, SQL_VARCHAR, 16, 0, 16)
  ODBCBIND(srvrUneiField32A_ValueDateCurrencyAmount, hUneiField32a_Date,         0, "val_d",           "?", "val_d",           SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0, 0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(srvrUneiField32A_ValueDateCurrencyAmount, hUneiField32a_CurrencyCode, 0, "val_curr_iso",    "?", "val_curr_iso",    SQL_C_CHAR, SQL_CHAR,     3,   0, 3)
  ODBCBIND(srvrUneiField32A_ValueDateCurrencyAmount, hUneiField32a_Amount,       0, "val_a",           "?", "val_a",           SQL_C_CHAR, SQL_DECIMAL,  18,  3, 17)

  ODBCBIND(srvrUneiField32C_TheBankingCommisionAmount, hUneiField32a_PayerOrBeneficiary,0, "'P'",           "?", "'P'",             SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrUneiField32C_TheBankingCommisionAmount, hUneiField32a_CurrencyCode,      0, "val_curr_iso",  "?", "val_curr_iso",    SQL_C_CHAR, SQL_CHAR,     3,   0, 3)
  ODBCBIND(srvrUneiField32C_TheBankingCommisionAmount, hUneiField32a_Amount,            0, "0",             "?", "0",               SQL_C_CHAR, SQL_DECIMAL,  18,  3, 17)

  ODBCBIND(srvrUneiField32T_TheAmountOfTheTransmissionExpenses, hUneiField32a_PayerOrBeneficiary,0, "'P'",           "?", "'P'",             SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrUneiField32T_TheAmountOfTheTransmissionExpenses, hUneiField32a_CurrencyCode,      0, "val_curr_iso",  "?", "val_curr_iso",    SQL_C_CHAR, SQL_CHAR,     3,   0, 3)
  ODBCBIND(srvrUneiField32T_TheAmountOfTheTransmissionExpenses, hUneiField32a_Amount,            0, "0",             "?", "0",               SQL_C_CHAR, SQL_DECIMAL,  18,  3, 17)

  ODBCBIND(srvrUneiField25a_InstructingParty, hUneiField25a_AccountNumber,  0, "inst_acct_name",  "?", "inst_acct_name",  SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrUneiField25a_Beneficiary,      hUneiField25a_AccountNumber,  0, "ben_acct_name",   "?", "ben_acct_name",   SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrUneiField5X_InstructingParty,  hUneiField5X_AccountNumber,   0, "inst_acct_name",  "?", "ben_acct_name",   SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrUneiField5X_InstructingParty,  hUneiField5X_NameAndAddress,  0, "inst_namadr",     "?", "inst_namadr",     SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)
  ODBCBIND(srvrUneiField5X_Beneficiary,       hUneiField5X_AccountNumber,   0, "ben_acct_name",   "?", "ben_acct_name",   SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrUneiField5X_Beneficiary,       hUneiField5X_NameAndAddress,  0, "ben_namaddr",     "?", "ben_namaddr",     SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)

  ODBCBIND(srvrUneiField52a_InstructingPartysBank, hUneiFieldXXa_CreditedOrDebitedAccount,      0, "inst_crdr_f",     "?", "inst_crdr_f",     SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrUneiField52a_InstructingPartysBank, hUneiFieldXXa_AccountNumber,                 0, "inst_acct_name",  "?", "inst_acct_name",  SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrUneiField52a_InstructingPartysBank, hUneiFieldXXa_BankIdentifierCode,            0, "inst_bic",        "?", "inst_bic",        SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrUneiField52a_InstructingPartysBank, hUneiFieldXXa_BranchIdentificationOrNameAndAddress, 0, "inst_namadr",     "?", "inst_namadr",     SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)

  ODBCBIND(srvrUneiField54a_ReceiversCorrespondentBank, hUneiFieldXXa_CreditedOrDebitedAccount,      0, "rcor_crdr_f",     "?", "rcor_crdr_f",     SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrUneiField54a_ReceiversCorrespondentBank, hUneiFieldXXa_AccountNumber,                 0, "rcor_acct_name",  "?", "rcor_acct_name",  SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrUneiField54a_ReceiversCorrespondentBank, hUneiFieldXXa_BankIdentifierCode,            0, "rcor_bic",        "?", "rcor_bic",        SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrUneiField54a_ReceiversCorrespondentBank, hUneiFieldXXa_BranchIdentificationOrNameAndAddress, 0, "rcor_namaddr",    "?", "rcor_namaddr",    SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)

  ODBCBIND(srvrUneiField56a_Intermediary, hUneiFieldXXa_CreditedOrDebitedAccount,      0, "inter_crdr_f",    "?", "inter_crdr_f",    SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrUneiField56a_Intermediary, hUneiFieldXXa_AccountNumber,                 0, "inter_acct_name", "?", "inter_acct_name", SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrUneiField56a_Intermediary, hUneiFieldXXa_BankIdentifierCode,            0, "inter_bic",       "?", "inter_bic",       SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrUneiField56a_Intermediary, hUneiFieldXXa_BranchIdentificationOrNameAndAddress, 0, "inter_namaddr",   "?", "inter_namaddr",   SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)

  ODBCBIND(srvrUneiField57a_BeneficiarysBank,   hUneiFieldXXa_CreditedOrDebitedAccount,      0, "scor_crdr_f",     "?", "scor_crdr_f",     SQL_C_CHAR, SQL_CHAR,     1,   0, 1)
  ODBCBIND(srvrUneiField57a_BeneficiarysBank,   hUneiFieldXXa_AccountNumber,                 0, "scor_acct_name",  "?", "scor_acct_name",  SQL_C_CHAR, SQL_VARCHAR,  34,  0, 34)
  ODBCBIND(srvrUneiField57a_BeneficiarysBank,   hUneiFieldXXa_BankIdentifierCode,            0, "scor_bic",        "?", "scor_bic",        SQL_C_CHAR, SQL_CHAR,     12,  0, 12)
  ODBCBIND(srvrUneiField57a_BeneficiarysBank,   hUneiFieldXXa_BranchIdentificationOrNameAndAddress, 0, "scor_namaddr",    "?", "scor_namaddr",    SQL_C_CHAR, SQL_VARCHAR,  254, 0, 254)
  ODBCBIND(NULL, hUneiField70_Narrative,      0, "srinfo_txt",      "?", "{fn RTRIM(srinfo_txt)}",  SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(UMT202_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT900_SERVER

BEGIN_ODBCBIND(MT900_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",       "?", "{fn RTRIM(tran_id)}",        SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",   "?", "{fn RTRIM(rel_tran_id)}",    SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField25_AccountIdentification,      0, "acct_name",     "?", "{fn RTRIM(acct_name)}",     SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(NULL, hField32A_Date,                      0, "val_d",         "?", "val_d",                      SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField32A_PriceOrCurrencyCode,       0, "val_curr_iso",  "?", "val_curr_iso",               SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32A_Amount,                    0, "val_a",         "?", "val_a",                      SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(srvrField52a_OrderingInstitution, hFieldXXa_CreditedOrDebitedAccount,    0, "ord_crdr_f",    "?", "ord_crdr_f",           SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField52a_OrderingInstitution, hFieldXXa_AccountNumber,               0, "ord_acct_name", "?", "{fn RTRIM(ord_acct_name)}", SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField52a_OrderingInstitution, hFieldXXa_BankIdentifierCode,          0, "ord_bic",       "?", "ord_bic",                   SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField52a_OrderingInstitution, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "ord_namaddr",   "?", "{fn RTRIM(ord_namaddr)}",   SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72c", "?", "srinfo_cdw72c",              SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",    "?", "{fn RTRIM(srinfo_txt)}",     SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT900_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT910_SERVER

BEGIN_ODBCBIND(MT910_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",         "?", "{fn RTRIM(tran_id)}",         SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",     "?", "{fn RTRIM(rel_tran_id)}",     SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField25_AccountIdentification,      0, "acct_name",       "?", "{fn RTRIM(acct_name)}",       SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(NULL, hField32A_Date,                      0, "val_d",           "?", "val_d",                       SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField32A_PriceOrCurrencyCode,       0, "val_curr_iso",    "?", "val_curr_iso",                SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32A_Amount,                    0, "val_a",           "?", "val_a",                       SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 15)
  ODBCBIND(srvrField52a_OrderingInstitution, hFieldXXa_CreditedOrDebitedAccount,      0, "ord_crdr_f",      "?", "ord_crdr_f",                  SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField52a_OrderingInstitution, hFieldXXa_AccountNumber,                 0, "ord_acct_name",   "?", "{fn RTRIM(ord_acct_name)}",   SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField52a_OrderingInstitution, hFieldXXa_BankIdentifierCode,            0, "ord_bic",         "?", "ord_bic",                     SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField52a_OrderingInstitution, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "ord_namaddr",     "?", "{fn RTRIM(ord_namaddr)}",     SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(srvrField56a_Intermediary,        hFieldXXa_CreditedOrDebitedAccount,      0, "inter_crdr_f",    "?", "inter_crdr_f",                SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField56a_Intermediary,        hFieldXXa_AccountNumber,                 0, "inter_acct_name", "?", "{fn RTRIM(inter_acct_name)}", SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField56a_Intermediary,        hFieldXXa_BankIdentifierCode,            0, "inter_bic",       "?", "inter_bic",                   SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField56a_Intermediary,        hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "inter_namaddr",   "?", "{fn RTRIM(inter_namaddr)}",   SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72c",   "?", "srinfo_cdw72c",               SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",      "?", "{fn RTRIM(srinfo_txt)}",      SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MT910_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MTn90_SERVER

BEGIN_ODBCBIND(MTn90_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",       "?", "{fn RTRIM(tran_id)}",       SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",   "?", "{fn RTRIM(rel_tran_id)}",   SQL_C_CHAR,      SQL_VARCHAR,   16,  0, 16)
  ODBCBIND(NULL, hField25_AccountIdentification,      0, "acct_name",     "?", "{fn RTRIM(acct_name)}",     SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(NULL, hField32a_CreditOrDebit,             0, "amnt_crdr_f",   "?", "amnt_crdr_f",               SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(NULL, hField32a_Date,                      0, "amnt_d",        "?", "amnt_d",                    SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0,   0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField32a_PriceOrCurrencyCode,       0, "amnt_curr_iso", "?", "amnt_curr_iso",             SQL_C_CHAR,      SQL_CHAR,      3,   0, 3)
  ODBCBIND(NULL, hField32a_Amount,                    0, "amnt_a",        "?", "amnt_a",                    SQL_C_CHAR,      SQL_DECIMAL,   18,  3, 18)
  ODBCBIND(srvrField52a_OrderingInstitution, hFieldXXa_CreditedOrDebitedAccount,    0, "ord_crdr_f",    "?", "ord_crdr_f",                SQL_C_CHAR,      SQL_CHAR,      1,   0, 1)
  ODBCBIND(srvrField52a_OrderingInstitution, hFieldXXa_AccountNumber,               0, "ord_acct_name", "?", "{fn RTRIM(ord_acct_name)}", SQL_C_CHAR,      SQL_VARCHAR,   34,  0, 34)
  ODBCBIND(srvrField52a_OrderingInstitution, hFieldXXa_BankIdentifierCode,          0, "ord_bic",       "?", "ord_bic",                   SQL_C_CHAR,      SQL_CHAR,      12,  0, 12)
  ODBCBIND(srvrField52a_OrderingInstitution, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "ord_namaddr",   "?", "{fn RTRIM(ord_namaddr)}",   SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72c", "?", "srinfo_cdw72c",             SQL_C_CHAR,      SQL_VARCHAR,   8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",    "?", "{fn RTRIM(srinfo_txt)}",    SQL_C_CHAR,      SQL_VARCHAR,   254, 0, 254)
END_ODBCBIND(MTn90_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MTn91_SERVER

BEGIN_ODBCBIND(MTn91_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",          "?", "{fn RTRIM(tran_id)}",     SQL_C_CHAR, SQL_VARCHAR, 16,  0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",      "?", "{fn RTRIM(rel_tran_id)}", SQL_C_CHAR, SQL_VARCHAR, 16,  0, 16)
  ODBCBIND(NULL, hField32B_CurrencyCode,              0, "amnt_curr_iso",    "?", "amnt_curr_iso",           SQL_C_CHAR, SQL_CHAR,    3,   0, 3)
  ODBCBIND(NULL, hField32B_Amount,                    0, "amnt_a",           "?", "amnt_a",                  SQL_C_CHAR, SQL_DECIMAL, 18,  3, 15)
  
  ODBCBIND(srvrField52a_OrderingInstitution,    hFieldXXa_CreditedOrDebitedAccount,        0, "ord_crdr_f",       "?", "ord_crdr_f",                   SQL_C_CHAR, SQL_CHAR,    1,   0, 1)
  ODBCBIND(srvrField52a_OrderingInstitution,    hFieldXXa_AccountNumber,                   0, "ord_acct_name",    "?", "{fn RTRIM(ord_acct_name)}",    SQL_C_CHAR, SQL_VARCHAR, 34,  0, 34)
  ODBCBIND(srvrField52a_OrderingInstitution,    hFieldXXa_BankIdentifierCode,              0, "ord_bic",          "?", "ord_bic",                      SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(srvrField52a_OrderingInstitution,    hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "ord_namaddr",      "?", "{fn RTRIM(ord_namaddr)}", SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
  
  ODBCBIND(srvrField57a_AccountWithInstitution, hFieldXXa_CreditedOrDebitedAccount,        0, "inacct_crdr_f",    "?", "inacct_crdr_f",                SQL_C_CHAR, SQL_CHAR,    1,   0, 1)
  ODBCBIND(srvrField57a_AccountWithInstitution, hFieldXXa_AccountNumber,                   0, "inacct_acct_name", "?", "{fn RTRIM(inacct_acct_name)}", SQL_C_CHAR, SQL_VARCHAR, 34,  0, 34)
  ODBCBIND(srvrField57a_AccountWithInstitution, hFieldXXa_BankIdentifierCode,              0, "inacct_bic",       "?", "inacct_bic",                   SQL_C_CHAR, SQL_CHAR,    12,  0, 12)
  ODBCBIND(srvrField57a_AccountWithInstitution, hFieldXXa_BranchIdentificationOrNameAndAddress, 0, "inacct_namaddr",   "?", "{fn RTRIM(inacct_namaddr)}", SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
  
  ODBCBIND(NULL, hField72_CodeWord,                   0, "srinfo_cdw72c",    "?", "srinfo_cdw72c",           SQL_C_CHAR, SQL_VARCHAR, 8,   0, 8)
  ODBCBIND(NULL, hField72_AdditionalInformation,      0, "srinfo_txt",       "?", "{fn RTRIM(srinfo_txt)}",  SQL_C_CHAR, SQL_VARCHAR, 254, 0, 254)
END_ODBCBIND(MTn91_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MTn92_SERVER

BEGIN_ODBCBIND(MTn92_SERVER)
  ODBCBIND(NULL, hField11a_ReceivedOrSent,            0, "orig_dir",      "?", "orig_dir", SQL_C_CHAR,      SQL_CHAR,      1, 0, 1)
  ODBCBIND(NULL, hField11a_MessageType,               0, "orig_mt",       "?", "orig_mt",  SQL_C_CHAR,      SQL_CHAR,      3, 0, 3)
  ODBCBIND(NULL, hField11a_Date,                      0, "orig_d",        "?", "orig_d",   SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0, 0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField11a_SessionNumber,             0, "orig_sn",       "?", "orig_sn",  SQL_C_SLONG,     SQL_CHAR,      4, 0, sizeof(SLONG))
  ODBCBIND(NULL, hField11a_SequenceNumber,            0, "orig_seq",      "?", "orig_seq", SQL_C_SLONG,     SQL_CHAR,      6, 0, sizeof(SLONG))
  
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",       "?", "{fn RTRIM(tran_id)}",     SQL_C_CHAR, SQL_VARCHAR, 16, 0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",   "?", "{fn RTRIM(rel_tran_id)}", SQL_C_CHAR, SQL_VARCHAR, 16, 0, 16)
  
  ODBCBIND(NULL, hField79_Narrative,                  0, "narrative_txt", "?", "narrative_txt",           SQL_C_CHAR, SQL_LONGVARCHAR, 0, 0, 16*1024)
  ODBCBIND(NULL, hCopyOfTheOriginalMessage,           0, "orig_copy",     "?", "orig_copy",               SQL_C_CHAR, SQL_LONGVARCHAR, 0, 0, 32*1024)
END_ODBCBIND(MTn92_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MTn95_SERVER

BEGIN_ODBCBIND(MTn95_SERVER)
  ODBCBIND(NULL, hField11a_ReceivedOrSent,            0, "orig_dir",      "?", "orig_dir", SQL_C_CHAR,      SQL_CHAR,      1, 0, 1)
  ODBCBIND(NULL, hField11a_MessageType,               0, "orig_mt",       "?", "orig_mt",  SQL_C_CHAR,      SQL_CHAR,      3, 0, 3)
  ODBCBIND(NULL, hField11a_Date,                      0, "orig_d",        "?", "orig_d",   SQL_C_TIMESTAMP, SQL_TIMESTAMP, 0, 0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField11a_SessionNumber,             0, "orig_sn",       "?", "orig_sn",  SQL_C_SLONG,     SQL_CHAR,      4, 0, sizeof(SLONG))
  ODBCBIND(NULL, hField11a_SequenceNumber,            0, "orig_seq",      "?", "orig_seq", SQL_C_SLONG,     SQL_CHAR,      6, 0, sizeof(SLONG))
  
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",       "?", "{fn RTRIM(tran_id)}",     SQL_C_CHAR, SQL_VARCHAR,     16, 0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",   "?", "{fn RTRIM(rel_tran_id)}", SQL_C_CHAR, SQL_VARCHAR,     16, 0, 16)
  
  ODBCBIND(NULL, hField77A_Narrative,                 0, "narrative_txt", "?", "narrative_txt",           SQL_C_CHAR, SQL_LONGVARCHAR, 0,  0, 16*1024)
  ODBCBIND(NULL, hField79_Narrative,                  0, "narr_desc",     "?", "narr_desc",               SQL_C_CHAR, SQL_LONGVARCHAR, 0,  0, 16*1024)
  ODBCBIND(NULL, hCopyOfTheOriginalMessage,           0, "orig_copy",     "?", "orig_copy",               SQL_C_CHAR, SQL_LONGVARCHAR, 0, 0, 32*1024)
END_ODBCBIND(MTn95_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MTn96_SERVER

BEGIN_ODBCBIND(MTn96_SERVER)
  ODBCBIND(NULL, hField11a_ReceivedOrSent,            0, "orig_dir",      "?", "orig_dir",                SQL_C_CHAR,      SQL_CHAR,        1,  0, 1)
  ODBCBIND(NULL, hField11a_MessageType,               0, "orig_mt",       "?", "orig_mt",                 SQL_C_CHAR,      SQL_CHAR,        3,  0, 3)
  ODBCBIND(NULL, hField11a_Date,                      0, "orig_d",        "?", "orig_d",                  SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0,  0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hField11a_SessionNumber,             0, "orig_sn",       "?", "orig_sn",                 SQL_C_SLONG,     SQL_CHAR,        4,  0, sizeof(SLONG))
  ODBCBIND(NULL, hField11a_SequenceNumber,            0, "orig_seq",      "?", "orig_seq",                SQL_C_SLONG,     SQL_CHAR,        6,  0, sizeof(SLONG))
  
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",       "?", "{fn RTRIM(tran_id)}",     SQL_C_CHAR,      SQL_VARCHAR,     16, 0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",   "?", "{fn RTRIM(rel_tran_id)}", SQL_C_CHAR,      SQL_VARCHAR,     16, 0, 16)
  
  ODBCBIND(NULL, hField77A_Narrative,                 0, "narrative_txt", "?", "narrative_txt",           SQL_C_CHAR,      SQL_LONGVARCHAR, 0,  0, 16*1024)
  ODBCBIND(NULL, hField79_Narrative,                  0, "narr_desc",     "?", "narr_desc",               SQL_C_CHAR,      SQL_LONGVARCHAR, 0,  0, 16*1024)
  ODBCBIND(NULL, hCopyOfTheOriginalMessage,           0, "orig_copy",     "?", "orig_copy",               SQL_C_CHAR,      SQL_LONGVARCHAR, 0, 0, 32*1024)
END_ODBCBIND(MTn96_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MTn98_SERVER

BEGIN_ODBCBIND(MTn98_SERVER)
  ODBCBIND(srvrField20_TransactionReferenceNumber, hField20_TransactionReferenceNumber, 0, "tran_id",       "?", "{fn RTRIM(tran_id)}",     SQL_C_CHAR, SQL_VARCHAR,     16, 0, 16)
  ODBCBIND(srvrField12_SubMessageType,             hField12_MessageType,                0, "msg_type",      "?", "msg_type", SQL_C_CHAR, SQL_CHAR,     3, 0, 3)
  ODBCBIND(srvrField77E_ProprietaryMessage,        hField77E_Narrative,                 0, "narrative_txt", "?", "narrative_txt",           SQL_C_CHAR, SQL_LONGVARCHAR, 0,  0, 32*1024)
END_ODBCBIND(MTn98_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MTn99_SERVER

BEGIN_ODBCBIND(MTn99_SERVER)
  ODBCBIND(NULL, hField20_TransactionReferenceNumber, 0, "tran_id",       "?", "{fn RTRIM(tran_id)}",     SQL_C_CHAR, SQL_VARCHAR,     16, 0, 16)
  ODBCBIND(NULL, hField21_RelatedReference,           0, "rel_tran_id",   "?", "{fn RTRIM(rel_tran_id)}", SQL_C_CHAR, SQL_VARCHAR,     16, 0, 16)
  ODBCBIND(NULL, hField79_Narrative,                  0, "narrative_txt", "?", "narrative_txt",           SQL_C_CHAR, SQL_LONGVARCHAR,  0, 0, 32*1024)
END_ODBCBIND(MTn99_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT592UM_SERVER

BEGIN_ODBCBIND(MT592UM_SERVER)
  ODBCBIND(NULL, hUneiField_MessageType,     0, "m70_type",    "?", "m70_type",    SQL_C_CHAR,      SQL_CHAR,        3, 0, 3)
  ODBCBIND(NULL, hUneiField_MT570TradeDate,  0, "m70_trade_d", "?", "m70_trade_d", SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0, 0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(srvrUneiField20_MT572TransactionReferenceNumber, hField20_TransactionReferenceNumber, 0, "m72_tran_id", "?", "{fn RTRIM(m72_tran_id)}", SQL_C_CHAR,      SQL_VARCHAR,    16, 0, 16)
  ODBCBIND(srvrUneiField67A_MT572StatementPeriod,           hField67A_FirstDateOfPeriod,         0, "m72_trade_d", "?", "m72_trade_d",             SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0, 0, sizeof(TIMESTAMP_STRUCT))
END_ODBCBIND(MT592UM_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
// MT598UM_SERVER

BEGIN_ODBCBIND(MT598UM_SERVER)
  ODBCBIND(NULL, hUneiField_TradeDate,                       0, "trade_d",      "?", "trade_d",                  SQL_C_TIMESTAMP, SQL_TIMESTAMP,   0, 0, sizeof(TIMESTAMP_STRUCT))
  ODBCBIND(NULL, hUneiField_MT570TransactionReferenceNumber, 0, "m70_tran_id", "?", "{fn RTRIM(m70_tran_id)}", SQL_C_CHAR,      SQL_VARCHAR,    16, 0, 16)
  ODBCBIND(NULL, hUneiField_MT572TransactionReferenceNumber, 0, "m72_tran_id", "?", "{fn RTRIM(m72_tran_id)}", SQL_C_CHAR,      SQL_VARCHAR,    16, 0, 16)
  ODBCBIND(NULL, hUneiField_MT574TransactionReferenceNumber, 0, "m74_tran_id", "?", "{fn RTRIM(m74_tran_id)}", SQL_C_CHAR,      SQL_VARCHAR,    16, 0, 16)
END_ODBCBIND(MT598UM_SERVER)

////////////////////////////////////////////////////////////////////////////////////////////////
