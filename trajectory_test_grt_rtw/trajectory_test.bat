set MATLAB=C:\MATLAB\R2006a
set MSVCDir=c:\program files\microsoft visual studio .net 2003\common7\..\vc7
"C:\MATLAB\R2006a\rtw\bin\win32\envcheck" INCLUDE "c:\program files\microsoft visual studio .net 2003\common7\..\vc7\platformsdk\include"
if errorlevel 1 goto vcvars32
"C:\MATLAB\R2006a\rtw\bin\win32\envcheck" INCLUDE "c:\program files\microsoft visual studio .net 2003\common7\..\vc7\include"
if errorlevel 1 goto vcvars32
"C:\MATLAB\R2006a\rtw\bin\win32\envcheck" PATH "c:\program files\microsoft visual studio .net 2003\common7\..\vc7\bin"
if errorlevel 1 goto vcvars32
goto make

:vcvars32
set VSINSTALLDIR=c:\program files\microsoft visual studio .net 2003\common7\..\common7\ide
set VCINSTALLDIR=c:\program files\microsoft visual studio .net 2003\common7\..
set FrameworkSDKDir=c:\program files\microsoft visual studio .net 2003\common7\..\FrameworkSDK
set FrameworkDir=c:\program files\microsoft visual studio .net 2003\common7\..\Framework
call "C:\MATLAB\R2006a\toolbox\rtw\rtw\private\vcvars32_710.bat"

:make
cd .
nmake -f trajectory_test.mk  ADD_MDL_NAME_TO_GLOBALS=1 VISUAL_VER=7.1
@if errorlevel 1 goto error_exit
exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
