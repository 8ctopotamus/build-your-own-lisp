#!/bin/bash

echo "Compiling..."

cc -std=c99 -Wall $1.c -o $1
