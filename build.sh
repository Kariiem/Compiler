#! /bin/bash

FILE=$1

rm -f comp.lex.c comp.lex.h comp.tab.c comp.tab.h comp

flex comp.l
bison -d comp.y

gcc -o comp lex.yy.c comp.tab.c
# ./comp < test_cases/$FILE