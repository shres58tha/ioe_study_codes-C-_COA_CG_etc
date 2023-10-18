@echo off
rem Class Loader
title Class

set hhmm=%time:~0,5%
echo %hhmm%
set day=%date:~0,4%
goto %day%

:Sun
echo Sunday

rem 7:00 to 8:40
if %time% GTR 07:00 if %hhmm% LSS 08:40 goto MM
rem 8:40 to 10:20
if %hhmm% GTR 08:40 if %hhmm% LSS 10:20 goto GDC
rem 8:40 to 10:20
if %hhmm% GTR 10:20 if %hhmm% LSS 12:50 goto BreakTime
rem 12:00 to 1:40
if %hhmm% GTR 12:50 if %hhmm% LSS 14:30 goto LKC
rem 14:30 onwards
if %hhmm% GTR 14:30  goto NoClass

:Mon
echo Monday

rem 7:00 to 8:40
if %time% GTR 07:00 if %hhmm% LSS 08:40 goto SKR
rem 8:40 to 10:20
if %hhmm% GTR 08:40 if %hhmm% LSS 10:20 goto JG
rem 10:20 onwards
if %hhmm% GTR 10:20  goto NoClass

:Tue
echo Tuesday

rem 7:00 to 8:40
if %time% GTR 07:00 if %hhmm% LSS 08:40 goto MM
rem 8:40 to 10:20
if %hhmm% GTR 08:40 if %hhmm% LSS 10:20 goto NPA
rem 8:40 to 10:20
if %hhmm% GTR 10:20 if %hhmm% LSS 12:00 goto BreakTime
rem 12:00 to 1:40
if %hhmm% GTR 12:00 if %hhmm% LSS 13:40 goto PCR
rem 12:00 to 1:40
if %hhmm% GTR 13:40 if %hhmm% LSS 15:20 goto LKC
rem 15:20 onwards
if %hhmm% GTR 15:20  goto NoClass

:Wed
echo Wednesday

rem 7:00 to 8:40
if %time% GTR 07:00 if %hhmm% LSS 08:40 goto SA
rem 8:40 to 10:20
if %hhmm% GTR 08:40 if %hhmm% LSS 10:20 goto SKR
rem 8:40 to 10:20
if %hhmm% GTR 10:20 if %hhmm% LSS 12:00 goto BreakTime
rem 12:00 to 1:40
if %hhmm% GTR 12:00 if %hhmm% LSS 13:40 goto AKR
rem 13:40 onwards
if %hhmm% GTR 13:40  goto NoClass


:Thu
echo Thrusday


rem 7:00 to 8:40
if %time% GTR 07:00 if %hhmm% LSS 08:40 goto MM
rem 8:40 to 10:20
if %hhmm% GTR 08:40 if %hhmm% LSS 10:20 goto SS
rem 8:40 to 10:20
if %hhmm% GTR 10:20 if %hhmm% LSS 12:00 goto BreakTime
rem 12:00 to 1:40
if %hhmm% GTR 12:00 if %hhmm% LSS 13:40 goto AKR
rem 13:40 onwards
if %hhmm% GTR 13:40  goto NoClass


:Fri
echo Friday

rem 7:00 to 7:50
if %time% GTR 07:00 if %hhmm% LSS 07:50 goto GBJ
rem 7:50 to 8:40
if %time% GTR 07:50 if %hhmm% LSS 08:40 goto BreakTime
rem 8:40 to 10:20
if %hhmm% GTR 08:40 if %hhmm% LSS 10:20 goto SKR
rem 8:40 to 10:20
if %hhmm% GTR 10:20 if %hhmm% LSS 12:00 goto BreakTime
rem 12:00 to 1:40
if %hhmm% GTR 12:00 if %hhmm% LSS 13:40 goto RS
rem 1:40 onwards
if %hhmm% GTR 13:40  goto NoClass


:Sat
echo Saturday
goto NoClass


:MM
echo Current class is ElectroMagnetics-MM.
echo Redirecting...
start chrome "https://meet.google.com/lookup/ ?authuser=1"
pause

:NPA
echo Current class is Math-NPA
echo Redirecting...
start chrome "https://meet.google.com/lookup/ ?authuser=1"
pause 

:SG
echo Current class is Math-SG
echo Redirecting...
start chrome "https://meet.google.com/lookup/ ?authuser=1"
pause

:GDC
echo Current class is Math-GDC
echo Redirecting...
start chrome "https://meet.google.com/lookup/ ?authuser=1"
pause

:JG
echo Current class is Probability and Statics - JG
echo Redirecting...
start chrome "https://meet.google.com/lookup/ ?authuser=1"
pause

:SKR
echo Current class is Control System - SKR
echo Redirecting...
start chrome "https://meet.google.com/lookup/ ?authuser=1"
pause

:AKR
echo Current class is Electronic Device and Circuits - PCR
echo Redirecting...
start chrome "https://meet.google.com/lookup/ ?authuser=1"
pause

:PCR
echo Current class is Electronic Device and Circuits - PCR
echo Redirecting...
start chrome "https://meet.google.com/lookup/ ?authuser=1"
pause

:LKC
echo Current class is Instrumentation-LKC
echo Redirecting...
start chrome "https://meet.google.com/lookup/ ?authuser=1"
pause

:RS
echo Current class is Instrumentation-RS
echo Redirecting...
start chrome "https://meet.google.com/lookup/ ?authuser=1"
pause

:SS
echo Current class is Probability and Statics - SS
echo Redirecting...
start chrome "https://meet.google.com/lookup/ ?authuser=1"
pause

:GBJ
echo Current class is Math-GDC
echo Redirecting...
start chrome "https://meet.google.com/lookup/ ?authuser=1"
pause

:BreakTime
echo Break time now
echo.
pause

:NoClass
echo There is no class now
goto CLOSE



:CLOSE
pause


GOTO eof

where compare-op may be one of:

    EQU - equal
    NEQ - not equal
    LSS - less than
    LEQ - less than or equal
    GTR - greater than
    GEQ - greater than or equal
rem if "%VAR1%"=="VALUE" if "%VAR2%"=="VALUE" *do something*  and

rem if %age% geq 2 if %age% leq 12 set class=child   "and" example
rem if %age% geq 2 (                      "and"
rem     if %age% leq 12 (
rem         set class=child
rem     )
rem )
rem "or"
REM set res=F
REM if %hour% leq 6 set res=T
REM if %hour% geq 22 set res=T
REM if "%res%"=="T" (
    REM set state=asleep
REM )
