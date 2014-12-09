@echo off

if (%QTDIR%)==() set QTDIR=C:\Qt\4.7.2
if (%BuildConfig%)==() set BuildConfig=release

rem Set Qt paths
set PATH=%QTDIR%\bin;%PATH%
set QMAKESPEC=win32-msvc2010

rem Set VS2010 paths
call "%VS100COMNTOOLS%\..\..\VC\vcvarsall.bat" amd64

rem echo environment variables
echo -- QTDIR set to %QTDIR%
echo -- QMAKESPEC set to %QMAKESPEC%
echo -- build Configuration set to %BuildConfig%

rem -----------------------------------------------------------------------------------------
