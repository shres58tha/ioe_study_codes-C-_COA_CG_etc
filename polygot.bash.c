#include <stdio.h>
#include <stdlib.h> /*
#  Copyright (c) 2011, Erik Nordstroem <contact[at]erikano[dot]net>
#
#   Permission to use, copy, modify, and/or distribute this software for any
#   purpose with or without fee is hereby granted, provided that the above
#   copyright notice and this permission notice appear in all copies.
#
#   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
#   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
#   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
#   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
#   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
#   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
#   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
EXIT_SUCCESS=0   #  */
#define F char *f

main ()
{
  F="UMAD?";
  printf /* | egrep -v ".*" #*/("");/*
  F=$( echo $F | egrep -o "[A-Za-z]*" | sed "s/ //g" )
  gcc $0 -o $F && ./$F || for i in 1 ; do echo lol; # */
  printf /*$F? | sed "s/\/\*U/U/g" ; echo #*/ ("lol\n%s\n", f);
  return 0; printf /* >/dev/null # */ (""); //\
  done;
}
//usr/bin/env false #\
main # PS joke was self made after reading about Polyglot_(computing) on WP

