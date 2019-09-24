@echo off
if %1. == . goto noparm
if exist %1.res del %1.res
echo Task: Expedition >%1.res
echo Program to test: %1 >>%1.res
echo ................ >>%1.res 
for %%i in (1,2,3,4,5,6,7,8,9,10) do call test.bat %%i %1
exit
:noparm
@echo Usage: test_all filename
@echo filename must be without extension!
