@ECHO OFF
pushd %~dp0\..\
call 3rd-Party\!Premake\Windows\premake5.exe --file=premake5.lua vs2022
popd
PAUSE
