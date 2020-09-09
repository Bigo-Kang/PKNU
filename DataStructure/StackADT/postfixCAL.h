#ifndef POSTFIXCAL_H
#define POSTFIXCAL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "stackADT.h"

int read_line(char str[], int n);
int convert(char *infix);
char *process_op(char op, char *pos);
int precedence(char op);

int is_operator(char ch);
int eval(char *expr);
void handle_exception(const char *err_msg);
int eval_op(char op);


#endif