echo off

set TYP_MCU=%2
set TYP_OS=%3
set BUILD_COMMAND=%CD%\..\tools\util\make\make.exe -f %CD%\..\Make\make_000.gmk all
echo Build command is: %BUILD_COMMAND%
%BUILD_COMMAND%
