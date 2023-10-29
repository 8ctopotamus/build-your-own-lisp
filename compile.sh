#!/bin/bash

filename = $1

echo "Compiling..."

echo "cc -std=c99 -Wall ${filename}.c -o ${filename}"
