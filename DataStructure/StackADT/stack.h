//���� ���� ����

#ifndef STACKT_H
#define STACK_H

#pragma warning(disable:4996)

#define INIT_CAPACITY 100
#define MAX_LEN 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

typedef int Item;


typedef struct stackType
{
    Item *contents;
    int top;
    int size;		//������ ������ �ϴ� �迭�� ũ��
}*Stack;



static void terminate(const char *message);		//���� ��Ȳ�� �߻��������� �Լ�
Stack create();
void destroy(Stack s);		//���� ��ü�� ���ִ°�
void makeEmpty(Stack s);		//������ ���븸 ������ ��, �ʱ����·� ������
bool isEmpty(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);
void reallocate(Stack s);
Item isFull(Stack s);
Item howMany(Stack s);




#endif