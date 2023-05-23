#! /bin/bash

# Check if the user has provided an input file.
if [ $# -eq 0 ]
then
    echo "No input file provided."
    echo "Usage: ./run.sh <input_file>"
    exit 1
fi

# Take an input file and compile it.
./comp < $1 > functions.txt
