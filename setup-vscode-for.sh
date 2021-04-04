#!/bin/bash

make clean
mkdir .build
make $1 -n > .build/make-output.txt
python generate-compile-commands.py
