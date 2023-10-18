#!/bin/sh


factorial()
{
  if [ "$1" -gt "1" ]; then
    i=`expr $1 - 1`
    j=`factorial $i`
    k=`expr $1 \* $j`
    echo $k
  else
    echo 1
  fi
}


while :
do
  echo "Enter a number (max value 20):"
  echo "enter any other to exit"
  read x
  
  #if [$x]
  if [ $x -gt 20 ]; then
    echo error: out of range: max value to 20
  else
    factorial $x
  fi  
done    
