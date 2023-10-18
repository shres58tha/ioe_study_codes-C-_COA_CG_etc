#!/bin/bash

# BAT / CMD goto function
function goto
{
    label=$1
    cmd=$(sed -n "/^:[[:blank:]][[:blank:]]*${label}/{:a;n;p;ba};" $0 | 
          grep -v ':$')
    eval "$cmd"
    exit
}

echo update

# Just for the heck of it: how to create a variable where to jump to:
y="ll"
start=${1:-$y}
echo $start
start=${1:-"start"}
echo $start
goto "$start"

: start
goto_msg="Starting..."
echo $goto_msg
# Just jump to the label:
goto "continue"

: skipped
goto_msg="This is skipped!"
echo $goto_msg

: continue
goto_msg="Ended..."
echo "$goto_msg"

# following doesn't jump to apt update whereas original does
goto update
