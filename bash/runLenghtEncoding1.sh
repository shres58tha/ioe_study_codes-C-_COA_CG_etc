#/* Run lenght encoder  
#!/bin/bash
while read s;do e=;while [[ $s ]];do c=${s:0:1};n=${s##+($c)};e+=$[${#s}-${#n}]$c;s=$n;done;echo $e;done
