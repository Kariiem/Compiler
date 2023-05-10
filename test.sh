#!/bin/sh

make clean
make
./comp test.txt
make clean