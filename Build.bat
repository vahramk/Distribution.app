
set CURRENT_PATH=%cd%


rem set up build environment
call BuildSetEnv.bat

qmake "CONFIG+=%BuildConfig%" distribution.pro
nmake


rem -----------------------------------------------------------------------------------------
