#ifndef POSTFIXPAR_H
#define POSTFIXPAR_H

#include<stdbool.h>
#include "stackADT.h"
#include "postfixOPR.h"

char *convert(char *infix);
char *process_op(char op, char *pos);
int precedence(char op);

#endif