#!/bin/sh

make clean
make
./comp test.txt "$1"
