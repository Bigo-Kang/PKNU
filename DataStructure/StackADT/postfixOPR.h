#ifndef POSTFIXOPR_H
#define POSTFIXOPR_H

#include <stdbool.h>
#include <string.h>
#include "stackADT.h"
//#include "postfixCAL.h"


int is_operator(char ch);
int eval(char *expr);
char *convert(char *infix);
void handle_exception(const char *err_msg);
int eval_op(char op);


#endif