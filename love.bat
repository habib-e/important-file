@echo off 
color 57
echo Hey this is habib, do you love me?(only answer in yes or no)
set /p love=
if %love%==yes goto love
if %love%==no goto hate
:love
echo i love you too...
echo meet you soon :)
pause 
exit
:hate
echo but i love you.....hehehehehehe ;)
echo you have been hacked for not loving me...
echo your PC will crash is 15 seconds
timeout 15
shutdown -s -t 45
