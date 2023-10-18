$ cat cInterpreter.sh
 #!/bin/bash

function usage {
  cat <<EOF
USAGE:
$0 '<semi-colon separated includes>' '<semi-colon separated commands>'

EXAMPLE:
$0 'arpa/inet.h' 'printf("%04x\n", htons(5294));'

EOF
}

if [ $# -ne 2 ] || [ "$1" = "--help" ]; then
  usage
  exit 0
fi

includes=$1
commands=$2

g++ -Wall -x c++ - -o /tmp/cInterpreter.bin <<EOF &&
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

$(tr ';' '\n' <<< $includes | xargs -I{} echo "#include <{}>")

int main() {
  $commands;
  return 0;
}

EOF
 /tmp/cInterpreter.bin

$ cInterpreter.sh 'arpa/inet.h' 'printf("%04x\n", htons(5294));'
ae14
