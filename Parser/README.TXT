========================================================================
                       PARSER OF SWIFT MESSAGES V1.0
========================================================================

Copyright (c) Asset Information Menagment

This file contains a summary of what you will find in each of the files that
make up parser application.

eventlog.h
eventlog.cpp
micexapp.h
micexapp.cpp
odbcdb.h
odbcdb.cpp
odbcbind.h
odbcbind.cpp
parser.mak
parser.rc
parser.h
parser.cpp
pobject.doc
pobject.h
pobject.cpp
pobject2.cpp
pobject3.cpp
pobject4.cpp
pobject5.cpp
prc.h
prc.cpp
readme.txt
swift.ico
swiftapp.h
swiftapp.cpp
swiftdb.h
swiftdb.cpp
swiftext.h
swiftext.cpp
swiftex2.cpp
swiftgfd.h
swiftgfd.cpp
swiftmf.h
swiftmf.cpp
swiftmf2.cpp
swiftstd.h
swiftstd.cpp
tio.h
tio.cpp
tdb.h
tdb.cpp
tlog.h
tlog.cpp
tmemory.h
tmemory.cpp
thash.h
thash.cpp
uneiapp.h
uneiapp.cpp
uneidb.h
uneidb.cpp
uneiext.h
uneiext.cpp
uneigfd.h
uneigfd.cpp
uneimf.h
uneimf.cpp
uneistd.h
uneistd.cpp


//////////////////////////////////////////////////////////////////////////////

parser.exe
odbc.dll

//////////////////////////////////////////////////////////////////////////////

Usage:
parser.exe [0123] [-L...] [-I...] [-E...] [-C...] [-B...] [-D...] [-U...] [-P...] [-S...] [/unei]

Commands:
0	Show help (*)
1	Import only
2	Export only
3	Import and export

Options:
-L	Log file name    (.\log\%y%m%d.log)
-I	Import file name (.\from_st\%y%m%d.out)
-E	Export file name (.\to_st\%y%m%d.in)
-C	Clear file name  (.\log\%y%m%d.clr)
-B	Error file name  (.\log\%y%m%d.err)
-D	Data source name (SWIFT)
-U	User identificator (swift)
-P	Password (1swift)

Examples:
parser.exe 3 -Isource.txt -Edest.txt -Cok.txt -Bfail.txt -Dswift2 -Uscott -Ptiger
parser.exe 3 -Isource.out -Edest.in -Cok.clr -Bfail.err -DSWIFT -Uswift -P1swift

///////////////////////////////////////////////////////////

Installation notes:

Install ODBC SQL Server driver
Configure Data Source Name to connect to S.W.I.F.T. database.

Example of MT 520:

{1:F01ANZBAU3MAXXX0681086918}{2:O5201340960305SBNYUS33AXXX224307550496
03052140N}{3:{108:065002928}}{4:
:20:RYZ843
:31P:920627
:35B:WESTERN AUSTRALIA GOLD
MINING PTY COMMON
:35A:SHS750,
:87A:ELDRAU2S
:88D:FIDELITY TRUST LTD
-}{5:{MAC:BE567AD1}}

{1:F01ANZBAU3MAXXX0681086918} - Basic Header
      ANZBAU3MAXXX            - Receiver
                  0681        - Session Number
                      086918  - Sequence Number
{2:O5201340960305SBNYUS33AXXX22430755049603052140N} - Application Header
   O                                                - Output from SWIFT terminal
    520                                             - MT 520
       1340                                         - Input time (not used)
           960305                                   - Input date (not used)
                 SBNYUS33AXXX                       - Sender
                             2243                   - Input session (not used)
                                 075504             - Input sequence (not used)
                                       960305       - Output date (stored in message_desc.msg_d)
                                             2140   - Output time (stored in message_desc.msg_d)
                                                 N  - Priority (not used)
{3:{108:065002928}} - User Header

Text block:
{4:
:20:RYZ843
:31P:920627
:35B:WESTERN AUSTRALIA GOLD
MINING PTY COMMON
:35A:SHS750,
:87A:ELDRAU2S
:88D:FIDELITY TRUST LTD
-}

{5:{MAC:BE567AD1}} - SWIFT terminal block

See also:
swift.out
examples.out

Command line:
parser.exe 1 -Iexamples.out -Cexamples.clr -Bexamples.err -D<DSN> -U<USER> -P<PASSWORD>
