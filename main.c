#include <stdio.h>
#include <stdlib.h>
#include "lib/mpc.h"

// if Windows
#ifdef _WIN32
#include <string.h>

// declare a buffer for user input of size 2048 */
static char buffer[2048];

// fake readline function
char* readline(char* prompt) {
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	char* cpy = malloc(strlen(buffer)+1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}

// fake add_history function
void add_history(char* unused) {}

#else
// Linux or MacOS
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char** argv) {
	
	puts("Lispy Version 0.0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while(1) {
		char* input = readline("lispy> ");

		add_history(input);

		printf("No you're a %s\n", input);

		free(input);
	}

	return 0;
}
