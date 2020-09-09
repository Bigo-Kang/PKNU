#include "postfixCAL.h"

char OPERATORS[] = "+-*/()";
int PRECEDENCE[] = { 1, 1, 2, 2, -1, -1 };

Stack operator_stack;
Stack operand_stack;

int convert(char *infix) {

    operator_stack = create();
    operand_stack = create();

    char *postfix = (char *)malloc(strlen(infix) + 1);
    char *pos = postfix;
    long num;
    char *ptr, *prev;
    int tmp;

    num = strtol(infix,&ptr,0);
    while(ptr != NULL){
        if(num != 0)
            push(operand_stack, num);
        else{
            if (is_empty(operator_stack) || *ptr == '(')
                push(operator_stack, *ptr);
            else {
                char top_op = peek(operator_stack);
                if (precedence(*ptr) > precedence(top_op))
                    push(operator_stack, *ptr);
                else {
                    while (!is_empty(operator_stack) && precedence(*ptr) <= precedence(top_op)) {
                        pop(operator_stack);
                        if (top_op == '(')
                            break;
                        tmp = eval_op (top_op);
                        push(operand_stack,tmp);

                        if (!is_empty(operator_stack))
                            top_op = (char)peek(operator_stack);
                    }
                    if (*ptr != ')')
                        push(operator_stack, *ptr);
                }
            }
        }

        prev = ptr + 1;
        num = strtol(prev, &ptr, 10);

    }
    while (!is_empty(operator_stack)) {
        char op = (char) pop (operator_stack);
        if (op == '(')
            handle_exception ("Unmatched parenthesis.\n");
        tmp = eval_op (op);
        return tmp;
    }
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

int read_line(char str[], int n){
    int ch, i=0;
    while((ch=getchar()) != '\n')
        if(i<n)
            str[i++] = ch;
    str[i]='\0';

    return i;
}

int is_operator(char ch) {
    for (int i = 0; i < strlen(OPERATORS); i++)
        if (OPERATORS[i] == ch)
            return i;
    return -1;
}

int eval(char *expr) {
    operand_stack = create();
    char *token = strtok(expr, " ");
    while (token != NULL) {
        if (token[0] >= '0'&& token[0] <= '9') {
            int value = atoi(token);
            push(operand_stack, value);
        }
        else if (is_operator(token[0]) > -1) {
            int result = eval_op(token[0]);
            push(operand_stack, result);
        }
        else {
            handle_exception("Syntax Error: invalid character encountered.\n");
        }
        token = strtok(NULL, " ");
    }
    if (is_empty(operand_stack))
        handle_exception("Syntax Error: Stack empty in eval_op.\n");
    int answer = pop(operand_stack);
    if (is_empty(operand_stack))
        return answer;
    else {
        handle_exception("Syntax Error: Stack should be empty.\n");
        return -1;
    }
}

void handle_exception(const char *err_msg) {
    printf("%s\n", err_msg);
    exit(1);
}

int eval_op(char op) {
    if(is_empty(operand_stack))
        handle_exception("Syntax Error: Stack empty in eval_op.\n");
    int rhs = pop(operand_stack);

    if(is_empty(operand_stack))
        handle_exception("Syntax Error: Stack empty in eval_op.\n");
    int lhs = pop(operand_stack);

    int result = 0;
    switch (op) {
        case '+': result = lhs + rhs; break;
        case '-': result = lhs - rhs; break;
        case '*': result = lhs * rhs; break;
        case '/': result = lhs / rhs; break;
    }
    return result;
}