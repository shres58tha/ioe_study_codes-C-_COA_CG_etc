@echo off
rem Class Loader
title Class

type routine.txt
setlocal
set currentTime=%TIME%


for /f "tokens=1 delims= " %%a in ("%date%") do (
if %%a==Sun goto Sunday
if %%a==Mon goto Monday
if %%a==Tue goto Tuesday
if %%a==Wed goto Wednesday
if %%a==Thu goto Thursday
if %%a==Fri goto Friday
if %%a==Sat goto Saturday
)

:Sunday
echo Sunday
echo %time:~0,5%

rem 7:00 to 8:40
if %currentTime% geq 07:00 if %currentTime% leq 08:40 CALL :callSubjects MM

rem 8:40 to 10:20
if %currentTime% geq 08:40 if %currentTime% leq 10:20 CALL :callSubjects GDC

rem 12:50 to 2:30
if %currentTime% geq 12:50 if %currentTime% leq 14:30 CALL :callSubjects LKC

else goto NoClass

:Monday
echo Monday
echo %time:~0,5%

rem 7:00 to 8:40
if %currentTime% geq 07:00 if %currentTime% leq 08:40 CALL :callSubjects SKR

rem 8:40 to 10:20
if %currentTime% geq 08:40 if %currentTime% leq 10:20 CALL :callSubjects JG

else goto NoClass

:Tuesday
echo Tuesday
echo %time:~0,5%

rem 7:00 to 8:40
if %currentTime% geq 07:00 if %currentTime% leq 08:40 CALL :callSubjects MM

rem 8:40 to 10:20
if %currentTime% geq 08:40 if %currentTime% leq 10:20 CALL :callSubjects NPA

rem 12:00 to 1:40
if %currentTime% geq 12:00 if %currentTime% leq 13:40 CALL :callSubjects PCR

rem 1:40 to 3:20
if %currentTime% geq 13:00 if %currentTime% leq 15:20 CALL :callSubjects LKC

goto NoClass

:Wednesday
echo Wednesday
echo %time:~0,5%

rem 7:00 to 8:40
if %currentTime% geq 07:00 if %currentTime% leq 08:40 CALL :callSubjects SG

rem 8:40 to 10:20
if %currentTime% geq 08:40 if %currentTime% leq 10:20 CALL :callSubjects SKR


rem 12:00 to 1:40
if %currentTime% geq 12:00 if %currentTime% leq 13:40 CALL :callSubjects AKR

else goto NoClass

:Thursday
echo Thrusday
echo %time:~0,5%

rem 7:00 to 8:40
if %currentTime% geq 07:00 if %currentTime% leq 08:40 CALL :callSubjects MM

rem 8:40 to 10:20
if %currentTime% geq 08:40 if %currentTime% leq 10:20 CALL :callSubjects SS

rem 12:00 to 1:40
if %currentTime% geq 12:00 if %currentTime% leq 13:40 CALL :callSubjects MM

else goto NoClass


:Friday
echo Friday
echo %time:~0,5%

rem 7:00 to 7:50
if %currentTime% geq 07:00 if %currentTime% leq 05:50 CALL :callSubjects GBJ

rem 8:40 to 10:20
if %currentTime% geq 08:40 if %currentTime% leq 10:20 CALL :callSubjects SKR


rem 12:00 to 1:40
if %currentTime% geq 12:00 if %currentTime% leq 01:40 CALL :callSubjects RS

else goto NoClass


:Saturday
echo Saturday
echo %time:~0,5%
goto NoClass

:NoClass
echo There is no class now.
goto CLOSE

:callSubjects 
for /f "tokens=1,2 delims=	" %%a in (subjects.txt) do (
if %%a==%~1 (
echo today's class is %~1
start opera %%b
)
)
EXIT /B 0

:CLOSE
pause
exit
