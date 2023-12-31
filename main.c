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

	// create parsers
	mpc_parser_t* Number   = mpc_new("number");
	mpc_parser_t* Operator = mpc_new("operator");
	mpc_parser_t* Expr     = mpc_new("expr");
	mpc_parser_t* Lispy    = mpc_new("lispy");

	// define language/grammar
	mpca_lang(MPCA_LANG_DEFAULT, 
		"                                                    \
			number   : /-?[0-9]+/ ;                            \
			operator : '+' | '-' | '*' | '/' ;                 \
			expr     : <number> | '(' <operator> <expr>+ ')' ; \
			lispy    : /^/ <operator> <expr>+ /$/ ;            \
		",
		Number,
		Operator,
		Expr,
		Lispy
	);
	
	puts("Lispy Version 0.0.0.1");
	puts("Press Ctrl+c to Exit\n");

	while(1) {
		char* input = readline("lispy> ");

		add_history(input);

		// attempt to parse user input
		mpc_result_t r;
		if (mpc_parse("<stdin>", input, Lispy, &r)) {
			// print AST
			mpc_ast_print(r.output);
			mpc_ast_delete(r.output);
		} else {
			// print err
			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}

		free(input);
	}

	// undefine and delete parsers
	mpc_cleanup(4, Number, Operator, Expr, Lispy);

	return 0;
}
