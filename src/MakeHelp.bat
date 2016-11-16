@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by MUSIC.HPJ. >"hlp\Music.hm"
echo. >>"hlp\Music.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Music.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Music.hm"
echo. >>"hlp\Music.hm"
echo // Prompts (IDP_*) >>"hlp\Music.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Music.hm"
echo. >>"hlp\Music.hm"
echo // Resources (IDR_*) >>"hlp\Music.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Music.hm"
echo. >>"hlp\Music.hm"
echo // Dialogs (IDD_*) >>"hlp\Music.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Music.hm"
echo. >>"hlp\Music.hm"
echo // Frame Controls (IDW_*) >>"hlp\Music.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Music.hm"
REM -- Make help for Project MUSIC


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\Music.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\Music.hlp" goto :Error
if not exist "hlp\Music.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\Music.hlp" Debug
if exist Debug\nul copy "hlp\Music.cnt" Debug
if exist Release\nul copy "hlp\Music.hlp" Release
if exist Release\nul copy "hlp\Music.cnt" Release
echo.
goto :done

:Error
echo hlp\Music.hpj(1) : error: Problem encountered creating help file

:done
echo.
