# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

!IF "$(CFG)" == ""
CFG=Parser - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Parser - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Parser - Win32 Release" && "$(CFG)" != "Parser - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "PARSER.MAK" CFG="Parser - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Parser - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Parser - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "Parser - Win32 Debug"
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Parser - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\PARSER.exe"

CLEAN : 
	-@erase "$(INTDIR)\eventlog.obj"
	-@erase "$(INTDIR)\micexapp.obj"
	-@erase "$(INTDIR)\odbcbind.obj"
	-@erase "$(INTDIR)\odbcdb.obj"
	-@erase "$(INTDIR)\parser.obj"
	-@erase "$(INTDIR)\parser.res"
	-@erase "$(INTDIR)\pobject.obj"
	-@erase "$(INTDIR)\pobject2.obj"
	-@erase "$(INTDIR)\pobject3.obj"
	-@erase "$(INTDIR)\pobject4.obj"
	-@erase "$(INTDIR)\pobject5.obj"
	-@erase "$(INTDIR)\prc.obj"
	-@erase "$(INTDIR)\swiftapp.obj"
	-@erase "$(INTDIR)\swiftdb.obj"
	-@erase "$(INTDIR)\swiftex2.obj"
	-@erase "$(INTDIR)\swiftext.obj"
	-@erase "$(INTDIR)\swiftgfd.obj"
	-@erase "$(INTDIR)\swiftmf.obj"
	-@erase "$(INTDIR)\swiftmf2.obj"
	-@erase "$(INTDIR)\swiftrep.obj"
	-@erase "$(INTDIR)\swiftsrv.obj"
	-@erase "$(INTDIR)\swiftst2.obj"
	-@erase "$(INTDIR)\swiftstd.obj"
	-@erase "$(INTDIR)\tdb.obj"
	-@erase "$(INTDIR)\thash.obj"
	-@erase "$(INTDIR)\tio.obj"
	-@erase "$(INTDIR)\tlog.obj"
	-@erase "$(INTDIR)\tmemory.obj"
	-@erase "$(INTDIR)\uneiapp.obj"
	-@erase "$(INTDIR)\uneidb.obj"
	-@erase "$(INTDIR)\uneiext.obj"
	-@erase "$(INTDIR)\uneigfd.obj"
	-@erase "$(INTDIR)\uneimf.obj"
	-@erase "$(INTDIR)\uneisrv.obj"
	-@erase "$(INTDIR)\uneist2.obj"
	-@erase "$(INTDIR)\uneistd.obj"
	-@erase "$(OUTDIR)\PARSER.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /W3 /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /ML /W3 /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS"\
 /Fp"$(INTDIR)/PARSER.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/parser.res" /d "NDEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/PARSER.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 libcmt.lib msvcrt.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386 /nodefaultlib
LINK32_FLAGS=libcmt.lib msvcrt.lib kernel32.lib user32.lib gdi32.lib\
 winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib\
 uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no\
 /pdb:"$(OUTDIR)/PARSER.pdb" /machine:I386 /nodefaultlib\
 /out:"$(OUTDIR)/PARSER.exe" 
LINK32_OBJS= \
	"$(INTDIR)\eventlog.obj" \
	"$(INTDIR)\micexapp.obj" \
	"$(INTDIR)\odbcbind.obj" \
	"$(INTDIR)\odbcdb.obj" \
	"$(INTDIR)\parser.obj" \
	"$(INTDIR)\parser.res" \
	"$(INTDIR)\pobject.obj" \
	"$(INTDIR)\pobject2.obj" \
	"$(INTDIR)\pobject3.obj" \
	"$(INTDIR)\pobject4.obj" \
	"$(INTDIR)\pobject5.obj" \
	"$(INTDIR)\prc.obj" \
	"$(INTDIR)\swiftapp.obj" \
	"$(INTDIR)\swiftdb.obj" \
	"$(INTDIR)\swiftex2.obj" \
	"$(INTDIR)\swiftext.obj" \
	"$(INTDIR)\swiftgfd.obj" \
	"$(INTDIR)\swiftmf.obj" \
	"$(INTDIR)\swiftmf2.obj" \
	"$(INTDIR)\swiftrep.obj" \
	"$(INTDIR)\swiftsrv.obj" \
	"$(INTDIR)\swiftst2.obj" \
	"$(INTDIR)\swiftstd.obj" \
	"$(INTDIR)\tdb.obj" \
	"$(INTDIR)\thash.obj" \
	"$(INTDIR)\tio.obj" \
	"$(INTDIR)\tlog.obj" \
	"$(INTDIR)\tmemory.obj" \
	"$(INTDIR)\uneiapp.obj" \
	"$(INTDIR)\uneidb.obj" \
	"$(INTDIR)\uneiext.obj" \
	"$(INTDIR)\uneigfd.obj" \
	"$(INTDIR)\uneimf.obj" \
	"$(INTDIR)\uneisrv.obj" \
	"$(INTDIR)\uneist2.obj" \
	"$(INTDIR)\uneistd.obj" \
	".\ODBC32.LIB"

"$(OUTDIR)\PARSER.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Parser - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Parser__"
# PROP BASE Intermediate_Dir "Parser__"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\PARSER.exe"

CLEAN : 
	-@erase "$(INTDIR)\eventlog.obj"
	-@erase "$(INTDIR)\micexapp.obj"
	-@erase "$(INTDIR)\odbcbind.obj"
	-@erase "$(INTDIR)\odbcdb.obj"
	-@erase "$(INTDIR)\parser.obj"
	-@erase "$(INTDIR)\parser.res"
	-@erase "$(INTDIR)\pobject.obj"
	-@erase "$(INTDIR)\pobject2.obj"
	-@erase "$(INTDIR)\pobject3.obj"
	-@erase "$(INTDIR)\pobject4.obj"
	-@erase "$(INTDIR)\pobject5.obj"
	-@erase "$(INTDIR)\prc.obj"
	-@erase "$(INTDIR)\swiftapp.obj"
	-@erase "$(INTDIR)\swiftdb.obj"
	-@erase "$(INTDIR)\swiftex2.obj"
	-@erase "$(INTDIR)\swiftext.obj"
	-@erase "$(INTDIR)\swiftgfd.obj"
	-@erase "$(INTDIR)\swiftmf.obj"
	-@erase "$(INTDIR)\swiftmf2.obj"
	-@erase "$(INTDIR)\swiftrep.obj"
	-@erase "$(INTDIR)\swiftsrv.obj"
	-@erase "$(INTDIR)\swiftst2.obj"
	-@erase "$(INTDIR)\swiftstd.obj"
	-@erase "$(INTDIR)\tdb.obj"
	-@erase "$(INTDIR)\thash.obj"
	-@erase "$(INTDIR)\tio.obj"
	-@erase "$(INTDIR)\tlog.obj"
	-@erase "$(INTDIR)\tmemory.obj"
	-@erase "$(INTDIR)\uneiapp.obj"
	-@erase "$(INTDIR)\uneidb.obj"
	-@erase "$(INTDIR)\uneiext.obj"
	-@erase "$(INTDIR)\uneigfd.obj"
	-@erase "$(INTDIR)\uneimf.obj"
	-@erase "$(INTDIR)\uneisrv.obj"
	-@erase "$(INTDIR)\uneist2.obj"
	-@erase "$(INTDIR)\uneistd.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(OUTDIR)\PARSER.exe"
	-@erase "$(OUTDIR)\PARSER.ilk"
	-@erase "$(OUTDIR)\PARSER.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /W3 /Gm /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS"\
 /Fp"$(INTDIR)/PARSER.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/parser.res" /d "_DEBUG" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/PARSER.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 libcmt.lib msvcrt.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /nodefaultlib
LINK32_FLAGS=libcmt.lib msvcrt.lib kernel32.lib user32.lib gdi32.lib\
 winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib\
 uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)/PARSER.pdb" /debug /machine:I386 /nodefaultlib\
 /out:"$(OUTDIR)/PARSER.exe" 
LINK32_OBJS= \
	"$(INTDIR)\eventlog.obj" \
	"$(INTDIR)\micexapp.obj" \
	"$(INTDIR)\odbcbind.obj" \
	"$(INTDIR)\odbcdb.obj" \
	"$(INTDIR)\parser.obj" \
	"$(INTDIR)\parser.res" \
	"$(INTDIR)\pobject.obj" \
	"$(INTDIR)\pobject2.obj" \
	"$(INTDIR)\pobject3.obj" \
	"$(INTDIR)\pobject4.obj" \
	"$(INTDIR)\pobject5.obj" \
	"$(INTDIR)\prc.obj" \
	"$(INTDIR)\swiftapp.obj" \
	"$(INTDIR)\swiftdb.obj" \
	"$(INTDIR)\swiftex2.obj" \
	"$(INTDIR)\swiftext.obj" \
	"$(INTDIR)\swiftgfd.obj" \
	"$(INTDIR)\swiftmf.obj" \
	"$(INTDIR)\swiftmf2.obj" \
	"$(INTDIR)\swiftrep.obj" \
	"$(INTDIR)\swiftsrv.obj" \
	"$(INTDIR)\swiftst2.obj" \
	"$(INTDIR)\swiftstd.obj" \
	"$(INTDIR)\tdb.obj" \
	"$(INTDIR)\thash.obj" \
	"$(INTDIR)\tio.obj" \
	"$(INTDIR)\tlog.obj" \
	"$(INTDIR)\tmemory.obj" \
	"$(INTDIR)\uneiapp.obj" \
	"$(INTDIR)\uneidb.obj" \
	"$(INTDIR)\uneiext.obj" \
	"$(INTDIR)\uneigfd.obj" \
	"$(INTDIR)\uneimf.obj" \
	"$(INTDIR)\uneisrv.obj" \
	"$(INTDIR)\uneist2.obj" \
	"$(INTDIR)\uneistd.obj" \
	".\ODBC32.LIB"

"$(OUTDIR)\PARSER.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "Parser - Win32 Release"
# Name "Parser - Win32 Debug"

!IF  "$(CFG)" == "Parser - Win32 Release"

!ELSEIF  "$(CFG)" == "Parser - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\pobject.cpp
DEP_CPP_POBJE=\
	".\pobject.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\pobject.obj" : $(SOURCE) $(DEP_CPP_POBJE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\prc.cpp
DEP_CPP_PRC_C=\
	".\pobject.h"\
	".\prc.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\prc.obj" : $(SOURCE) $(DEP_CPP_PRC_C) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\tdb.cpp
DEP_CPP_TDB_C=\
	".\tdb.h"\
	".\tlog.h"\
	

"$(INTDIR)\tdb.obj" : $(SOURCE) $(DEP_CPP_TDB_C) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\tio.cpp
DEP_CPP_TIO_C=\
	".\tio.h"\
	".\tlog.h"\
	

"$(INTDIR)\tio.obj" : $(SOURCE) $(DEP_CPP_TIO_C) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\swiftext.cpp
DEP_CPP_SWIFT=\
	".\pobject.h"\
	".\prc.h"\
	".\swiftext.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\swiftext.obj" : $(SOURCE) $(DEP_CPP_SWIFT) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\swiftgfd.cpp
DEP_CPP_SWIFTG=\
	".\pobject.h"\
	".\prc.h"\
	".\srv.h"\
	".\swiftext.h"\
	".\swiftgfd.h"\
	".\swiftsrv.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\swiftgfd.obj" : $(SOURCE) $(DEP_CPP_SWIFTG) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\swiftmf.cpp
DEP_CPP_SWIFTM=\
	".\pobject.h"\
	".\prc.h"\
	".\srv.h"\
	".\swiftext.h"\
	".\swiftmf.h"\
	".\swiftsrv.h"\
	".\swiftstd.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\swiftmf.obj" : $(SOURCE) $(DEP_CPP_SWIFTM) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\swiftstd.cpp
DEP_CPP_SWIFTS=\
	".\pobject.h"\
	".\prc.h"\
	".\srv.h"\
	".\swiftext.h"\
	".\swiftgfd.h"\
	".\swiftsrv.h"\
	".\swiftstd.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\swiftstd.obj" : $(SOURCE) $(DEP_CPP_SWIFTS) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\pobject.doc

!IF  "$(CFG)" == "Parser - Win32 Release"

!ELSEIF  "$(CFG)" == "Parser - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\SWIFT.OUT

!IF  "$(CFG)" == "Parser - Win32 Release"

!ELSEIF  "$(CFG)" == "Parser - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\odbcbind.cpp
DEP_CPP_ODBCB=\
	".\odbcbind.h"\
	".\srv.h"\
	".\swiftsrv.h"\
	".\uneisrv.h"\
	

"$(INTDIR)\odbcbind.obj" : $(SOURCE) $(DEP_CPP_ODBCB) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\swiftapp.cpp
DEP_CPP_SWIFTA=\
	".\eventlog.h"\
	".\odbcbind.h"\
	".\odbcdb.h"\
	".\parser.h"\
	".\pobject.h"\
	".\prc.h"\
	".\swiftapp.h"\
	".\swiftdb.h"\
	".\swiftext.h"\
	".\swiftmf.h"\
	".\swiftrep.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\swiftapp.obj" : $(SOURCE) $(DEP_CPP_SWIFTA) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\thash.cpp
DEP_CPP_THASH=\
	".\thash.h"\
	

"$(INTDIR)\thash.obj" : $(SOURCE) $(DEP_CPP_THASH) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\tlog.cpp
DEP_CPP_TLOG_=\
	".\tlog.h"\
	

"$(INTDIR)\tlog.obj" : $(SOURCE) $(DEP_CPP_TLOG_) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\odbcdb.cpp
DEP_CPP_ODBCD=\
	".\odbcbind.h"\
	".\odbcdb.h"\
	".\pobject.h"\
	".\tdb.h"\
	".\thash.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\odbcdb.obj" : $(SOURCE) $(DEP_CPP_ODBCD) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\eventlog.cpp
DEP_CPP_EVENT=\
	".\eventlog.h"\
	".\tlog.h"\
	

"$(INTDIR)\eventlog.obj" : $(SOURCE) $(DEP_CPP_EVENT) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\tmemory.cpp
DEP_CPP_TMEMO=\
	".\tmemory.h"\
	

"$(INTDIR)\tmemory.obj" : $(SOURCE) $(DEP_CPP_TMEMO) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\parser.rc
DEP_RSC_PARSE=\
	".\swift.ico"\
	

"$(INTDIR)\parser.res" : $(SOURCE) $(DEP_RSC_PARSE) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\swiftrep.cpp
DEP_CPP_SWIFTR=\
	".\srv.h"\
	".\swiftrep.h"\
	".\swiftsrv.h"\
	".\tdb.h"\
	".\thash.h"\
	".\tlog.h"\
	

"$(INTDIR)\swiftrep.obj" : $(SOURCE) $(DEP_CPP_SWIFTR) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\swiftsrv.cpp
DEP_CPP_SWIFTSR=\
	".\srv.h"\
	".\swiftsrv.h"\
	

"$(INTDIR)\swiftsrv.obj" : $(SOURCE) $(DEP_CPP_SWIFTSR) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\swiftdb.cpp
DEP_CPP_SWIFTD=\
	".\odbcbind.h"\
	".\odbcdb.h"\
	".\pobject.h"\
	".\swiftdb.h"\
	".\tdb.h"\
	".\thash.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\swiftdb.obj" : $(SOURCE) $(DEP_CPP_SWIFTD) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\uneisrv.cpp
DEP_CPP_UNEIS=\
	".\srv.h"\
	".\uneisrv.h"\
	

"$(INTDIR)\uneisrv.obj" : $(SOURCE) $(DEP_CPP_UNEIS) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\uneidb.cpp
DEP_CPP_UNEID=\
	".\odbcbind.h"\
	".\odbcdb.h"\
	".\pobject.h"\
	".\tdb.h"\
	".\thash.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	".\uneidb.h"\
	

"$(INTDIR)\uneidb.obj" : $(SOURCE) $(DEP_CPP_UNEID) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\uneiapp.cpp
DEP_CPP_UNEIA=\
	".\eventlog.h"\
	".\odbcbind.h"\
	".\odbcdb.h"\
	".\parser.h"\
	".\pobject.h"\
	".\prc.h"\
	".\swiftapp.h"\
	".\swiftdb.h"\
	".\swiftext.h"\
	".\swiftmf.h"\
	".\swiftrep.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	".\uneiapp.h"\
	".\uneidb.h"\
	".\uneiext.h"\
	".\uneimf.h"\
	

"$(INTDIR)\uneiapp.obj" : $(SOURCE) $(DEP_CPP_UNEIA) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\parser.cpp
DEP_CPP_PARSER=\
	".\eventlog.h"\
	".\micexapp.h"\
	".\odbcbind.h"\
	".\odbcdb.h"\
	".\parser.h"\
	".\pobject.h"\
	".\swiftapp.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	".\uneiapp.h"\
	

"$(INTDIR)\parser.obj" : $(SOURCE) $(DEP_CPP_PARSER) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\uneistd.cpp
DEP_CPP_UNEIST=\
	".\pobject.h"\
	".\prc.h"\
	".\srv.h"\
	".\swiftext.h"\
	".\swiftgfd.h"\
	".\swiftsrv.h"\
	".\swiftstd.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	".\uneiext.h"\
	".\uneigfd.h"\
	".\uneisrv.h"\
	".\uneistd.h"\
	

"$(INTDIR)\uneistd.obj" : $(SOURCE) $(DEP_CPP_UNEIST) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\uneimf.cpp
DEP_CPP_UNEIM=\
	".\pobject.h"\
	".\prc.h"\
	".\srv.h"\
	".\swiftext.h"\
	".\swiftmf.h"\
	".\swiftsrv.h"\
	".\swiftstd.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	".\uneiext.h"\
	".\uneigfd.h"\
	".\uneimf.h"\
	".\uneisrv.h"\
	".\uneistd.h"\
	

"$(INTDIR)\uneimf.obj" : $(SOURCE) $(DEP_CPP_UNEIM) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\uneigfd.cpp
DEP_CPP_UNEIG=\
	".\pobject.h"\
	".\prc.h"\
	".\srv.h"\
	".\swiftext.h"\
	".\swiftsrv.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	".\uneiext.h"\
	".\uneigfd.h"\
	".\uneisrv.h"\
	

"$(INTDIR)\uneigfd.obj" : $(SOURCE) $(DEP_CPP_UNEIG) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\uneiext.cpp
DEP_CPP_UNEIE=\
	".\pobject.h"\
	".\prc.h"\
	".\swiftext.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	".\uneiext.h"\
	

"$(INTDIR)\uneiext.obj" : $(SOURCE) $(DEP_CPP_UNEIE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\pobject2.cpp
DEP_CPP_POBJEC=\
	".\pobject.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\pobject2.obj" : $(SOURCE) $(DEP_CPP_POBJEC) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\swiftex2.cpp
DEP_CPP_SWIFTE=\
	".\pobject.h"\
	".\prc.h"\
	".\swiftext.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\swiftex2.obj" : $(SOURCE) $(DEP_CPP_SWIFTE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\pobject3.cpp
DEP_CPP_POBJECT=\
	".\pobject.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\pobject3.obj" : $(SOURCE) $(DEP_CPP_POBJECT) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\pobject4.cpp
DEP_CPP_POBJECT4=\
	".\pobject.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\pobject4.obj" : $(SOURCE) $(DEP_CPP_POBJECT4) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\pobject5.cpp
DEP_CPP_POBJECT5=\
	".\pobject.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\pobject5.obj" : $(SOURCE) $(DEP_CPP_POBJECT5) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\swiftmf2.cpp
DEP_CPP_SWIFTMF=\
	".\pobject.h"\
	".\prc.h"\
	".\srv.h"\
	".\swiftext.h"\
	".\swiftmf.h"\
	".\swiftsrv.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\swiftmf2.obj" : $(SOURCE) $(DEP_CPP_SWIFTMF) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\pmodel.doc

!IF  "$(CFG)" == "Parser - Win32 Release"

!ELSEIF  "$(CFG)" == "Parser - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ODBC32.LIB

!IF  "$(CFG)" == "Parser - Win32 Release"

!ELSEIF  "$(CFG)" == "Parser - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\swiftst2.cpp
DEP_CPP_SWIFTST=\
	".\pobject.h"\
	".\prc.h"\
	".\srv.h"\
	".\swiftext.h"\
	".\swiftgfd.h"\
	".\swiftsrv.h"\
	".\swiftstd.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	

"$(INTDIR)\swiftst2.obj" : $(SOURCE) $(DEP_CPP_SWIFTST) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\uneist2.cpp
DEP_CPP_UNEIST2=\
	".\pobject.h"\
	".\prc.h"\
	".\srv.h"\
	".\swiftext.h"\
	".\swiftgfd.h"\
	".\swiftsrv.h"\
	".\swiftstd.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	".\uneiext.h"\
	".\uneigfd.h"\
	".\uneisrv.h"\
	".\uneistd.h"\
	

"$(INTDIR)\uneist2.obj" : $(SOURCE) $(DEP_CPP_UNEIST2) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\micexapp.cpp
DEP_CPP_MICEX=\
	".\eventlog.h"\
	".\micexapp.h"\
	".\odbcbind.h"\
	".\odbcdb.h"\
	".\parser.h"\
	".\pobject.h"\
	".\prc.h"\
	".\swiftapp.h"\
	".\swiftdb.h"\
	".\swiftext.h"\
	".\swiftmf.h"\
	".\swiftrep.h"\
	".\tdb.h"\
	".\tio.h"\
	".\tlog.h"\
	".\tmemory.h"\
	".\uneiapp.h"\
	".\uneidb.h"\
	".\uneiext.h"\
	".\uneimf.h"\
	

"$(INTDIR)\micexapp.obj" : $(SOURCE) $(DEP_CPP_MICEX) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################
