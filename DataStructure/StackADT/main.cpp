#include <stdio.h>
#include "postfixCAL.h"
#define MAX_LENGTH 100

int main()
{
	char infix[MAX_LENGTH];
//    char *ptr;
//    long num;
//    int ch;
    read_line(infix, MAX_LENGTH);
	printf(" %s := ", infix);

    int postfix = convert(infix);
	printf("%d\n", postfix);


//    char *str = "-123-4*5)+6";
//    char *ptr;
//    long num=0;
//    bool bl = true;
//    //scanf ("%s",str);
//    num = strtol (str,&ptr,0);
//    printf("%ld\n", num);
//    num = strtol (ptr, &ptr, 0);
//    printf("%ld\n", num);
}