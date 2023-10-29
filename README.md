# build-your-own-lisp

Following https://www.buildyourownlisp.com/

## Compiling in terminal

### Windows

`cc -std=c99 -Wall main.c lib/mpc.c -o main`

### Linux

`cc -std=c99 -Wall main.c lib/mpc.c -ledit -lm -o main`

## Compiling using Build script

### Windows

`./build.sh`

### Linux

`bash build.sh`

## Run

### Windows

`./main.exe`

### Linux

./main

## Resources

* https://www.buildyourownlisp.com
* https://github.com/orangeduck/mpc
* https://linuxconfig.org/bash-scripting-cheat-sheet
* https://www.geeksforgeeks.org/how-to-detect-operating-system-through-a-c-program/
