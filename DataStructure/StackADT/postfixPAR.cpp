#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "postfixPAR.h"

char OPERATORS[] = "+-*/()";
int PRECEDENCE[] = { 1, 1, 2, 2, -1, -1 };

Stack operator_stack;

char *convert(char *infix) {
	operator_stack = create();
	char *postfix = (char *)malloc(strlen(infix) + 1);
	char *pos = postfix;

	char *token = strtok(infix, " ");
	while (token != NULL) {
		if (token[0] >= '0' && token[0] <= '9') {
			sprintf(pos, "%s ", token);
			pos += (strlen(token) + 1);
		}
		else if (is_operator(token[0]) > -1) {
			pos = process_op(token[0], pos);
		}
		else {
			handle_exception("Syntax Error: invalid character encountered.\n");
		}
		token = strtok(NULL, " ");
	}

	while (!is_empty(operator_stack)) {
		char op = (char)pop(operator_stack);
		if (op == '(')
			handle_exception("Unmatched parenthesis.\n");
		sprintf(pos, "%c ", op);
		pos += 2;
	}
	*pos = '\0';
	return postfix;
}

char *process_op(char op, char *pos) {
	if (is_empty(operator_stack) || op == '(')
		push(operator_stack, op);
	else {
		char top_op = peek(operator_stack);
		if (precedence(op) > precedence(top_op))
			push(operator_stack, op);
		else {
			while (!is_empty(operator_stack) && precedence(op) <= precedence(top_op)) {
				pop(operator_stack);
				if (top_op == '(')
					break;
				sprintf(pos, "%c ", top_op);
				pos += 2;
				if (!is_empty(operator_stack))
					top_op = (char)peek(operator_stack);
			}
			if (op != ')')
				push(operator_stack, op);
		}
	}
	return pos;
}

int precedence(char op) {
	return PRECEDENCE[is_operator(op)];
}