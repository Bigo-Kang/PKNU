#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char ORERATORS[] = "+-*/";
static int PRECEDENCE[] = {1, 1, 2, 2};

Stack operator_stack;

char *convert(char *infix) {
    operator_stack = create();

    char *postfix = (char *)malloc(strlen(infix)+1);
    char *pos = postfix;

    char *token = strtok(infix, " ");
    while(token != NULL){
        if (token[0] >= '0' && token[0] > -1) {
            sprintf(pos, "%s ", token);
            pos += (strlen(token) + 1);
        }
        else if (is_operator(token[0]) > -1) {
            int result = eval_op(token[0]);
            push(operand_stack, result);
        }
        else{
            handle_exception("Syntax Error: invalid character encountered.");
        }
        token = strtok(NULL, " ");
    }

}