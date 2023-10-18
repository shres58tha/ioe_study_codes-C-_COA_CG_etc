@echo off
for %%x in (
        a.js
        storage.js
        logic.js
        main.js
        z.js
       ) do (
         echo your file name is %%x
         echo "%%x" is a cool name
         echo.
         echo =-=-=-=-=-=
         echo.
       )
the reason it looks like a vertical list is so it will be easier to add or remove more items. (and 'echo' with 'dot' is for one empty line).

the output will look like this:

C:\example>yourBatchName.cmd
your file name is a.js
"a.js" is a cool name

=-=-=-=-=-=

your file name is storage.js
"storage.js" is a cool name

=-=-=-=-=-=

your file name is logic.js
"logic.js" is a cool name

=-=-=-=-=-=

your file name is main.js
"main.js" is a cool name

=-=-=-=-=-=

your file name is z.js
"z.js" is a cool name

=-=-=-=-=-=
** p.s. for file name listing one should prefer using something like this:

for %%e in (*.dll) do (....

------------------------------------------------
In this case the values may be stored in an arbitrarily long file, one per line. Call it my-values.list, with a content similar to:

1.1
1.2
2.4
3.9
3.9.1
3.9.2
3.91
3.91.1
...
Now you could read the variables from this text file, line by line:

for /f "tokens=*" %a in (c:\path\to\my-values.list) do echo.  Version%~nxa.txt


------------------------------------------------------
Need goto :eof at end of subroutines and at end of main routine so you don't fall into subroutines.
tokens=1* (%%f is first token; %%g is rest of the line)
~ in set list=%~1 to remove quotes so quotes don't accumulate

@echo off
set themes=Sun,Granite,Twilight

call :parse "%themes%"
pause
goto :eof

:parse
setlocal
set list=%~1
echo list = %list%
for /F "tokens=1* delims=," %%f in ("%list%") do (
    rem if the item exist
    if not "%%f" == "" call :getLineNumber %%f
    rem if next item exist
    if not "%%g" == "" call :parse "%%g"
)
endlocal
goto :eof

:getLineNumber
setlocal
echo file name is %1
set filename=%1
goto :eof
-----------------------------------------------------------------------

::===============================================================
:: The below example is used to find computer and logged on users
::
::===============================================================
ECHO OFF 
:: Windows version check 
IF NOT "%OS%"=="Windows_NT" GOTO Syntax 
ECHO.%* | FIND "?" >NUL 
:: Command line parameter check 
IF NOT ERRORLEVEL 1 GOTO Syntax
IF NOT [%2]==[] GOTO Syntax 
:: Keep variable local 
SETLOCAL 
:: Initialize variable 
SET WSS= 
:: Parse command line parameter 
IF NOT [%1]==[] FOR /F "tokens = 1 delims = \ " %%A IN ('ECHO.%~1') DO SET WSS = %%A 
:: Use NET VIEW and NBTSTAT to find computers and logged on users 
FOR /F "tokens = 1 delims = \ " %%a IN ('NET VIEW ^| FIND /I "\\%WSS%"') DO FOR /F 
"tokens = 1 delims = " %%A IN ('NBTSTAT -a %%a ^| FIND /I /V "%%a" ^| FIND 
"<03>"') DO ECHO.%%a %%A 
:: Done 
ENDLOCAL
GOTO:EOF 
:Syntax 
ECHO Display logged on users and their workstations. 
ECHO Usage: ACTUSR [ filter ] 
IF "%OS%"=="Windows_NT" ECHO Where: filter is the first part of the 
computer name^(s^) to be displayed
----------------------------------------------------------
I think I understand what you want, and if so the answers below misinterpret it: if I'm right, you want var2 to hold a value such as A, so you want newvar to be set to the contents of varA. The only way I have found to make CMD double-parse is to use echo set newvar=%%var%var2%>temp.cmd, then .\temp.cmd. A bit unwieldy, but it does work. – AFH Jun 30 '14 at 21:21


I agree with AFH; you need to get CMD to “double-parse” the set statement.  But I’ve found a kludge for doing it that doesn’t involve a temporary batch file (or looking at every variable to find the one you want).  It uses a subroutine and a trick called delayed variable expansion.  Enable delayed expansion by adding

setlocal enabledelayedexpansion
somewhere near the beginning of your batch file.  The purpose of delayed variable expansion is somewhat complicated – see SET /? and SETLOCAL /? for more information – but the important thing to know is that it lets you reference variables with !variable_name! in addition to %variable_name%.

So here we go:

@echo off
setlocal enabledelayedexpansion
set var1=red
set var2=orange
set var3=yellow
set A=2
call :kludge var%A%
echo Newvar is %newvar%.
goto :eof

:kludge
set newvar=!%1!
exit /b
When we jump to :kludge, the statement is first transformed into set newvar=!var2! (because %1, the first argument to the subroutine, is var2) and then set newvar=orange (just as if the statement had been set newvar=%var2%).  So newvar gets set to orange.

BTW, goto :eof and exit /b are interchangeable.  If called from within a subroutine (i.e., someplace you got to with a call statement), they cause a return to the caller.  Otherwise, they act like a jump to the end of the batch file, causing the batch job to terminate without blowing away the parent, interactive, Command Prompt.


A relatively slow method. The CALL command provides an extra level of variable expansion. The percents around the outer variable name are doubled to delay the expansion until after the inner variable has been expanded.

@echo off
setlocal
set "var1=value"
set "var2=1"
call set "newvar=%%var%var2%%%"
A much better method is to use delayed expansion. It must be first enabled with SETLOCAL ENABLEDELAYEDEXPANSION. The variable within percents is expanded when the line is parsed. The variable within exclamation points is expanded after parsing, just before the line is executed.

@echo off
setlocal enableDelayedExpansion
set "var1=value"
set "var2=1"
set "newvar=!var%var2%!"


Generally, I'd try to avoid scenarios like this. While it is possible, it is far from performant and not very easy to read either - basically you'd have to parse the output of the set command.

set index=9
set var9=Goal

echo %var9%
for /F "usebackq tokens=1* delims==" %I in (`set`) do if "%I" == "var%index%" set result=%J
echo %result%





----------------------------------------------------------------






