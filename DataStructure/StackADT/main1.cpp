#include "stack.h"

static char OPERATORS[] = "+-*/()";
static int PRECEDENCE[] = { 1,1,2,2,-1,-1 };		//���ϱ��� ������ �켱������ 1�̰� ���ϱ��� �������� �켱������ 2�̴�(���⼭�� ���ڰ� ū ���� �� ū �켱�����̴�.)

Stack operandStack, operatorStack;

int readLine(FILE *fp, char str[], int limit);
int precedence(char op);			//op�� �������̴�
int isOperator(char ch);
void handleException(const char *errMsg);
int integrate(char *infix, int *final);
int calculate(int lhs, int rhs, char oper);

int main()
{
    char expr[MAX_LEN];
    if (readLine(stdin, expr, MAX_LEN) <= 0)
        return 1;			//����������
    int final = 0;
    printf("%d\n", integrate(expr,&final));
}


int readLine(FILE *fp, char str[], int limit)
{
    int ch, i = 0;
    while ((ch = fgetc(fp)) != '\n'&&ch != EOF)
        if (i < limit - 1)
            str[i++] = ch;

    str[i] = '\0';
    return i;
}




int precedence(char op)			//op�� �������̴�
{
    return PRECEDENCE[isOperator(op)];
}


int isOperator(char ch)
{
    for (int i = 0;i < strlen(OPERATORS);i++)
        if (OPERATORS[i] == ch)
            return i;
    return -1;
}


void handleException(const char *errMsg)
{
    printf("%s\n", errMsg);
    exit(1);
}




int integrate(char *infix, int *final)
{
    operatorStack = create();
    operandStack = create();
    char *postfix = (char*)malloc(strlen(infix) + 1);
    char *pos = postfix;
    char *errorPtr,*prevErrPtr;
    long num=0;
    bool first = true;
    int result;



    num = strtol(infix, &errorPtr, 10);
    while (1)
    {
        if (num != NULL)
            push(operandStack, num);

        if (*errorPtr != NULL)
        {
            if (isEmpty(operatorStack)||*errorPtr=='(')
                push(operatorStack, *errorPtr);

            else							//��� ���� ��ȣ�� �ƴ�
            {
                char topOp = (char)peek(operatorStack);

                if (precedence(topOp) < precedence(*errorPtr))
                    push(operatorStack, *errorPtr);

                else
                {
                    while (!isEmpty(operatorStack) && precedence(topOp) >= precedence(*errorPtr))
                    {
                        pop(operatorStack);
                        if (topOp == '(')
                            break;
                        int rhs = pop(operandStack);
                        int lhs = pop(operandStack);
                        result = calculate(lhs, rhs, topOp);
                        push(operandStack, result);
                        if (!isEmpty(operatorStack))
                            topOp = (char)peek(operatorStack);
                    }
                    if (*errorPtr != ')')
                        push(operatorStack, *errorPtr);
                }

            }
        }

        else if (*errorPtr == NULL)
            break;

        prevErrPtr = errorPtr + 1;
        num = strtol(prevErrPtr, &errorPtr, 10);

    }


    while (!isEmpty(operatorStack))
    {
        int rhs, lhs, result;
        if (!isEmpty(operandStack))
            rhs = pop(operandStack);
        if (!isEmpty(operandStack))
            lhs = pop(operandStack);
        char op = (char)pop(operatorStack);
        if (op == '(')
            handleException("Unmatched parenthesis.\n");
        result = calculate(lhs, rhs, op);
        return result;
    }

}

int calculate(int lhs, int rhs, char oper)
{
    int result = 0;
    switch (oper)
    {
        case '+':result = lhs+rhs;break;
        case '-':result = lhs-rhs;break;
        case '*':result = lhs*rhs;break;
        case '/':result = lhs/rhs;break;
        case '^':result = pow((double)lhs, (double)rhs);
    }
    return result;
}


