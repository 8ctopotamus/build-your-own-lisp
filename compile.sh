#!/bin/bash

filename = $1

echo "Compiling..."

echo cc -std=c99 -Wall prompt.c -ledit -o prompt
# echo "cc -std=c99 -Wall ${filename}.c -o ${filename}"

echo "Done"
