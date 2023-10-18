@echo off
rem Class Loader
title Class

set hhmm=%time:~0,5%
echo %hhmm%
set day=%date:~0,4%
echo %day%
goto %day%

:Sun
if %hhmm% GTR 07:00 if %hhmm% LSS 08:40 goto MM        
if %hhmm% GTR 08:40 if %hhmm% LSS 10:20 goto GDC        
if %hhmm% GTR 10:20 if %hhmm% LSS 12:50 goto BreakTime  
if %hhmm% GTR 12:50 if %hhmm% LSS 14:30 goto LKC        
if %hhmm% GTR 14:30  goto NoClass    
                   
:Mon
if %time% GTR 07:00 if %hhmm% LSS 08:40 goto SKR
if %hhmm% GTR 08:40 if %hhmm% LSS 10:20 goto JG
if %hhmm% GTR 10:20  goto NoClass

:Tue
if %time% GTR 07:00 if %hhmm% LSS 08:40 goto MM
if %hhmm% GTR 08:40 if %hhmm% LSS 10:20 goto NPA
if %hhmm% GTR 10:20 if %hhmm% LSS 12:00 goto BreakTime
if %hhmm% GTR 12:00 if %hhmm% LSS 13:40 goto PCR
if %hhmm% GTR 13:40 if %hhmm% LSS 15:20 goto LKC
if %hhmm% GTR 15:20  goto NoClass

:Wed
if %time% GTR 07:00 if %hhmm% LSS 08:40 goto SA
if %hhmm% GTR 08:40 if %hhmm% LSS 10:20 goto SKR
if %hhmm% GTR 10:20 if %hhmm% LSS 12:00 goto BreakTime
if %hhmm% GTR 12:00 if %hhmm% LSS 13:40 goto AKR
if %hhmm% GTR 13:40  goto NoClass


:Thu
if %time% GTR 07:00 if %hhmm% LSS 08:40 goto MM
if %hhmm% GTR 08:40 if %hhmm% LSS 10:20 goto SS
if %hhmm% GTR 10:20 if %hhmm% LSS 12:00 goto BreakTime
if %hhmm% GTR 12:00 if %hhmm% LSS 13:40 goto AKR
if %hhmm% GTR 13:40  goto NoClass

:Fri
if %time% GTR 07:00 if %hhmm% LSS 07:50 goto GBJ
if %time% GTR 07:50 if %hhmm% LSS 08:40 goto BreakTime
if %hhmm% GTR 08:40 if %hhmm% LSS 10:20 goto SKR
if %hhmm% GTR 10:20 if %hhmm% LSS 12:00 goto BreakTime
if %hhmm% GTR 12:00 if %hhmm% LSS 13:40 goto RS
if %hhmm% GTR 13:40  goto NoClass


:Sat
echo Saturday
goto NoClass


:MM
echo Current class is ElectroMagnetics-MM.
start chrome "https://meet.google.com/lookup/###?authuser=1"
pause

:NPA
echo Current class is Math-NPA
start chrome "https://meet.google.com/lookup/###?authuser=1"
pause 

:SG
echo Current class is Math-SG
start chrome "https://meet.google.com/lookup/###?authuser=1"
pause

:GDC
echo Current class is Math-GDC
start chrome "https://meet.google.com/lookup/###?authuser=1"
pause

:JG
echo Current class is Probability and Statics - JG
start chrome "https://meet.google.com/lookup/###?authuser=1"
pause

:SKR
echo Current class is Control System - SKR
start chrome "https://meet.google.com/lookup/###?authuser=1"
pause

:AKR
echo Current class is Electronic Device and Circuits - PCR
start chrome "https://meet.google.com/lookup/###?authuser=1"
pause

:PCR
echo Current class is Electronic Device and Circuits - PCR
start chrome "https://meet.google.com/lookup/###?authuser=1"
pause

:LKC
echo Current class is Instrumentation-LKC
start chrome "https://meet.google.com/lookup/###?authuser=1"
pause

:RS
echo Current class is Instrumentation-RS
start chrome "https://meet.google.com/lookup/###?authuser=1"
pause

:SS
echo Current class is Probability and Statics - SS
start chrome "https://meet.google.com/lookup/###?authuser=1"
pause

:GBJ
echo Current class is Math-GDC
start chrome "https://meet.google.com/lookup/###?authuser=1"
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

examples----------
where compare-op may be one of:
    EQU - equal
    NEQ - not equal
    LSS - less than
    LEQ - less than or equal
    GTR - greater than
    GEQ - greater than or equal

rem  and
if "%VAR1%"=="VALUE" if "%VAR2%"=="VALUE" *do something*  

rem and" example
 if %age% geq 2 if %age% leq 12 set class=child   "
 if %age% geq 2 (                      "and"
     if %age% leq 12 (
         set class=child
     )
 )
rem "or"
set res=F
if %hour% leq 6 set res=T
if %hour% geq 22 set res=T
 if "%res%"=="T" (
     set state=asleep
)
