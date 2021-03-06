# Microsoft Developer Studio Project File - Name="CompassML" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=CompassML - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CompassML.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CompassML.mak" CFG="CompassML - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CompassML - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CompassML - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CompassML - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "$(XERCESCROOT)/include" /I ".\\" /I "C:/Program Files/GME/sdk/BON/" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "BUILDER_OBJECT_NETWORK_V2" /FR /FD /Zm200 /Zm200 /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib xerces-c_2D.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept /libpath:"$(XERCESCROOT)/lib"
# Begin Custom Build - Performing registration
OutDir=.\Debug
TargetPath=.\Debug\CompassML.dll
InputPath=.\Debug\CompassML.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "CompassML - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /Zi /O1 /I "$(XERCESCROOT)/include" /I ".\\" /I "C:/Program Files/GME/sdk/BON/" /D "NDEBUG" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "BUILDER_OBJECT_NETWORK_V2" /FD /Zm200 /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib xerces-c_2.lib /nologo /subsystem:windows /dll /debug /machine:I386 /libpath:"C:\Tools\xercesc\lib" /libpath:"$(XERCESCROOT)/lib"
# Begin Custom Build - Performing registration
OutDir=.\Release
TargetPath=.\Release\CompassML.dll
InputPath=.\Release\CompassML.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "CompassML - Win32 Debug"
# Name "CompassML - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/BON.cpp"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\BON2Component.cpp
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/BONImpl.cpp"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComHelp.cpp"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/Common.cpp"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\Component.def
# End Source File
# Begin Source File

SOURCE=.\Component.rc
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComponentDll.cpp"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComponentLib.idl"

!IF  "$(CFG)" == "CompassML - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - MIDL $(InputPath))
InputPath="C:/Program Files/GME/sdk/BON/ComponentLib.idl"

BuildCmds= \
	midl /I.\ /server none /client none "C:/Program Files/GME/sdk/BON/ComponentLib.idl"

"ComponentLib.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "CompassML - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - MIDL $(InputPath))
InputPath="C:/Program Files/GME/sdk/BON/ComponentLib.idl"

BuildCmds= \
	midl /I.\ /server none /client none "C:/Program Files/GME/sdk/BON/ComponentLib.idl"

"ComponentLib.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComponentObj.cpp"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/Exceptions.cpp"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/Extensions.cpp"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/MON.cpp"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/MONImpl.cpp"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/Utils.cpp"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\XercesString.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/BON.h"
# End Source File
# Begin Source File

SOURCE=.\BON2Component.h
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/BONImpl.h"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComHelp.h"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/Common.h"
# End Source File
# Begin Source File

SOURCE=.\ComponentConfig.h
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComponentDll.h"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComponentObj.h"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/Exceptions.h"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/Extensions.h"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/GMECOM.h"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/MON.h"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/MONImpl.h"
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/Utils.h"
# End Source File
# Begin Source File

SOURCE=.\XercesString.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\CompIcon.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\ConfigureComponent.exe
# End Source File
# End Target
# End Project
