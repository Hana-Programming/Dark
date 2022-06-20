@echo off
set path=%~dp0%
%CD:~0,2%\Masm32\bin\ml.exe /coff %path%\Files\AsmFiles\%1%.asm
%CD:~0,2%\Masm32\bin\link.exe /SUBSYSTEM:CONSOLE %1%.obj
%1%
