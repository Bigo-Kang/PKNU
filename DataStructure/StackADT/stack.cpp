#include "stack.h"
//1. �迭�� stack�� ����
static void terminate(const char *message)		//���� ��Ȳ�� �߻��������� �Լ�
{
    printf("%s\n", message);
    exit(1);
}


Stack create()
{
    Stack s = (Stack)malloc(sizeof(struct stackType));

    if (s == NULL)
        terminate("Error in create : stack could not be created.\n");
    s->contents = (Item*)malloc(sizeof(Item)*INIT_CAPACITY);

    if (s->contents == NULL)
    {
        free(s);
        terminate("Error in create : stack could not be created.\n");
    }

    s->top = -1;
    s->size = INIT_CAPACITY;
    return s;

}

void destroy(Stack s)		//���� ��ü�� ���ִ°�
{
    free(s->contents);
    free(s);
}

void makeEmpty(Stack s)		//������ ���븸 ������ ��, �ʱ����·� ������
{
    s->top = -1;
}

bool isEmpty(Stack s)
{
    return s->top == -1;
}

void push(Stack s, Item i)
{
    if (isFull(s))
        reallocate(s);
    s->top++;
    s->contents[s->top] = i;
}

Item pop(Stack s)
{
    if (isEmpty(s))
        terminate("Error in pop : stack is empty.\n");
    s->top--;
    return s->contents[s->top + 1];
}

Item peek(Stack s)
{
    if(isEmpty(s))
        terminate("Error in peek : stack is empty.\n");
    return s->contents[s->top];
}

void reallocate(Stack s)
{
    Item *tmp = (Item*)malloc(sizeof(Item)*s->size * 2);
    if (tmp == NULL)
    {
        terminate("Error in create : stack could not be created.\n");
    }

    for (int i = 0;i < s->size;i++)
        tmp[i] = s->contents[i];

    free(s->contents);
    s->contents = tmp;
    s->size *= 2;
}


Item isFull(Stack s)
{
    return s->top == s->size;
}

Item howMany(Stack s)
{
    return s->top + 1;
}




//2. linked-list�� ������ ����

//
//typedef struct node
//{
//	Item data;
//	struct node *next;
//}Node;
//
//struct stackType
//{
//	struct node *top;
//};
//
//
//static void terminate(const char *message)
//{
//	printf("%s\n", message);
//	exit(EXIT_FAILURE);
//}
//
//void destroy(Stack s)
//{
//	makeEmpty(s);
//	free(s);
//}
//
//void makeEmpty(Stack s)
//{
//	while (!isEmpty(s))
//		pop(s);
//}
//
//bool isEmpty(Stack s)
//{
//	return s->top == NULL;
//}
//
//void push(Stack s, Item i)
//{
//	Node *newNode = (Node*)malloc(sizeof(Node));
//	if (newNode == NULL)
//		terminate("Error in push : stack is full");
//
//	newNode->data = i;
//	newNode->next = s->top;
//	s->top = newNode;
//}
//
//Item pop(Stack s)
//{
//	Node *oldTop;
//	Item i;
//
//	if (isEmpty(s))
//		terminate("Error in pop : stack is empty\n");
//
//	oldTop = s->top;
//	i = oldTop->data;
//	s->top = oldTop->next;
//	free(oldTop);
//	return i;
//
//}
//
//Item peek(Stack s)
//{
//	if (isEmpty(s))
//		terminate("Error in peek : stack is empty\n");
//	return s->top->data;
//}//
// Created by 강대원 on 2017. 11. 15..
//

