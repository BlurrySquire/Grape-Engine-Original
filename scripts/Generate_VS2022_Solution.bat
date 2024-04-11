@ECHO OFF
pushd %~dp0\..\
call 3rd-party\!Premake\Windows\premake5.exe --file=premake5.lua vs2022
popd
PAUSE
