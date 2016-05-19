# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

!IF "$(CFG)" == ""
CFG=DESTEST - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to DESTEST - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "DESTEST - Win32 Release" && "$(CFG)" !=\
 "DESTEST - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "DESTEST.MAK" CFG="DESTEST - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DESTEST - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "DESTEST - Win32 Debug" (based on "Win32 (x86) Console Application")
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
# PROP Target_Last_Scanned "DESTEST - Win32 Debug"
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DESTEST - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
OUTDIR=.
INTDIR=.

ALL : "$(OUTDIR)\DESTEST.exe"

CLEAN : 
	-@erase ".\DESTEST.exe"
	-@erase ".\DesFile.obj"
	-@erase ".\DesAnsi.obj"
	-@erase ".\DESTEST.OBJ"
	-@erase ".\DesMem.obj"
	-@erase ".\Desx.obj"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_CONSOLE"\
 /Fp"DESTEST.pch" /YX /c 
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/DESTEST.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386
# SUBTRACT LINK32 /nodefaultlib
LINK32_FLAGS=/nologo /subsystem:console /incremental:no\
 /pdb:"$(OUTDIR)/DESTEST.pdb" /machine:I386 /out:"$(OUTDIR)/DESTEST.exe" 
LINK32_OBJS= \
	"$(INTDIR)/DesFile.obj" \
	"$(INTDIR)/DesAnsi.obj" \
	"$(INTDIR)/DESTEST.OBJ" \
	"$(INTDIR)/DesMem.obj" \
	"$(INTDIR)/Desx.obj"

"$(OUTDIR)\DESTEST.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "DESTEST - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
OUTDIR=.
INTDIR=.

ALL : "$(OUTDIR)\DESTEST.exe"

CLEAN : 
	-@erase ".\vc40.pdb"
	-@erase ".\vc40.idb"
	-@erase ".\DESTEST.exe"
	-@erase ".\DesFile.obj"
	-@erase ".\DesAnsi.obj"
	-@erase ".\DESTEST.OBJ"
	-@erase ".\DesMem.obj"
	-@erase ".\Desx.obj"
	-@erase ".\DESTEST.ilk"
	-@erase ".\DESTEST.pdb"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_CONSOLE"\
 /Fp"DESTEST.pch" /YX /c 
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/DESTEST.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386
# SUBTRACT LINK32 /nodefaultlib
LINK32_FLAGS=/nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)/DESTEST.pdb" /debug /machine:I386 /out:"$(OUTDIR)/DESTEST.exe" 
LINK32_OBJS= \
	"$(INTDIR)/DesFile.obj" \
	"$(INTDIR)/DesAnsi.obj" \
	"$(INTDIR)/DESTEST.OBJ" \
	"$(INTDIR)/DesMem.obj" \
	"$(INTDIR)/Desx.obj"

"$(OUTDIR)\DESTEST.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx.obj:
   $(CPP) $(CPP_PROJ) $<  

.c.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "DESTEST - Win32 Release"
# Name "DESTEST - Win32 Debug"

!IF  "$(CFG)" == "DESTEST - Win32 Release"

!ELSEIF  "$(CFG)" == "DESTEST - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\DESTEST.C
DEP_CPP_DESTE=\
	".\des.h"\
	".\desx.h"\
	".\desmem.h"\
	".\desfile.h"\
	

"$(INTDIR)\DESTEST.OBJ" : $(SOURCE) $(DEP_CPP_DESTE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DesFile.c
DEP_CPP_DESFI=\
	".\des.h"\
	".\desx.h"\
	".\desfile.h"\
	

"$(INTDIR)\DesFile.obj" : $(SOURCE) $(DEP_CPP_DESFI) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DesAnsi.c
DEP_CPP_DESAN=\
	".\des.h"\
	

"$(INTDIR)\DesAnsi.obj" : $(SOURCE) $(DEP_CPP_DESAN) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DesMem.c
DEP_CPP_DESME=\
	".\des.h"\
	".\desx.h"\
	".\desmem.h"\
	

"$(INTDIR)\DesMem.obj" : $(SOURCE) $(DEP_CPP_DESME) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Desx.c
DEP_CPP_DESX_=\
	".\des.h"\
	".\desx.h"\
	

"$(INTDIR)\Desx.obj" : $(SOURCE) $(DEP_CPP_DESX_) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################
