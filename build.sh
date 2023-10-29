#!/bin/bash

echo "Compiling on $OSTYPE..."

if [ "$OSTYPE" == "win32" ] || [ "$OSTYPE" == "msys" ]; then
  cc -std=c99 -Wall main.c lib/mpc.c -o main
else
  cc -std=c99 -Wall main.c lib/mpc.c -ledit -lm -o main
fi


echo "Done"
