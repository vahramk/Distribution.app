
set CURRENT_PATH=%cd%

call BuildSetEnv.bat

nmake clean

rem Clean the build output
rd %CURRENT_PATH%\debug /S /Q
rd %CURRENT_PATH%\release /S /Q
del %CURRENT_PATH%\Makefile
del %CURRENT_PATH%\Makefile.Debug
del %CURRENT_PATH%\Makefile.Release