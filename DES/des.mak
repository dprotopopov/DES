# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

!IF "$(CFG)" == ""
CFG=des - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to des - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "des - Win32 Release" && "$(CFG)" != "des - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "des.mak" CFG="des - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "des - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "des - Win32 Debug" (based on "Win32 (x86) Console Application")
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
# PROP Target_Last_Scanned "des - Win32 Debug"
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "des - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
OUTDIR=.
INTDIR=.

ALL : "$(OUTDIR)\des.exe"

CLEAN : 
	-@erase ".\des.exe"
	-@erase ".\des.obj"
	-@erase ".\DesMem.obj"
	-@erase ".\DesFile.obj"
	-@erase ".\DesAnsi.obj"
	-@erase ".\Desx.obj"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE"\
 /Fp"des.pch" /YX /c 
# ADD BASE RSC /l 0x419 /d "NDEBUG"
# ADD RSC /l 0x419 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/des.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386
LINK32_FLAGS=/nologo /subsystem:console /incremental:no\
 /pdb:"$(OUTDIR)/des.pdb" /machine:I386 /out:"$(OUTDIR)/des.exe" 
LINK32_OBJS= \
	"$(INTDIR)/des.obj" \
	"$(INTDIR)/DesMem.obj" \
	"$(INTDIR)/DesFile.obj" \
	"$(INTDIR)/DesAnsi.obj" \
	"$(INTDIR)/Desx.obj"

"$(OUTDIR)\des.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "des - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
OUTDIR=.
INTDIR=.

ALL : "$(OUTDIR)\des.exe"

CLEAN : 
	-@erase ".\vc40.pdb"
	-@erase ".\vc40.idb"
	-@erase ".\des.exe"
	-@erase ".\des.obj"
	-@erase ".\DesMem.obj"
	-@erase ".\DesFile.obj"
	-@erase ".\DesAnsi.obj"
	-@erase ".\Desx.obj"
	-@erase ".\des.ilk"
	-@erase ".\des.pdb"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE"\
 /Fp"des.pch" /YX /c 
# ADD BASE RSC /l 0x419 /d "_DEBUG"
# ADD RSC /l 0x419 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/des.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:console /incremental:yes\
 /pdb:"$(OUTDIR)/des.pdb" /debug /machine:I386 /out:"$(OUTDIR)/des.exe" 
LINK32_OBJS= \
	"$(INTDIR)/des.obj" \
	"$(INTDIR)/DesMem.obj" \
	"$(INTDIR)/DesFile.obj" \
	"$(INTDIR)/DesAnsi.obj" \
	"$(INTDIR)/Desx.obj"

"$(OUTDIR)\des.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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

# Name "des - Win32 Release"
# Name "des - Win32 Debug"

!IF  "$(CFG)" == "des - Win32 Release"

!ELSEIF  "$(CFG)" == "des - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\des.c
DEP_CPP_DES_C=\
	".\des.h"\
	".\desx.h"\
	".\desmem.h"\
	".\desfile.h"\
	

"$(INTDIR)\des.obj" : $(SOURCE) $(DEP_CPP_DES_C) "$(INTDIR)"


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

SOURCE=.\DesFile.c
DEP_CPP_DESFI=\
	".\des.h"\
	".\desx.h"\
	".\desfile.h"\
	

"$(INTDIR)\DesFile.obj" : $(SOURCE) $(DEP_CPP_DESFI) "$(INTDIR)"


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
