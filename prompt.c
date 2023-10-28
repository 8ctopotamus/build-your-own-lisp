#include <stdio.h>

// declare a buffer for user input of size 2048 */
static char input[2048];

int main(int argc, char** argv) {
	
	puts("Lispy Version 0.0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while(1) {
		printf("looping");
		fputs("lispy> ", stdout);
		
		fgets(input, 2048, stdin);

		fgets(input, 2048, stdin);

		printf("No you're a %s", input);	
	}

	return 0;
}
