#!/bin/bash

filename = $1

echo "Compiling..."

cc -std=c99 -Wall main.c lib/mpc.c -ledit -lm -o main

echo "Done"
