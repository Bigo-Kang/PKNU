#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

struct node{
    int value;
    struct node *next;
};
typedef struct node Node;
Node *head = NULL;

void handle_create();
Node *insert_tail(int val, Node *tail);
void handle_add();
void handle_remove();
void handle_print();
int size();
void handle_size();
void handle_reverse();
void handle_swap();


int main()
{
    char buffer[MAX_LENGTH];

    while(1){
        printf("$ ");
        scanf("%s", buffer);
        if(strcmp(buffer, "create") == 0){
            handle_create();
        }
        else if(strcmp(buffer, "add") == 0){
            handle_add();
        }
        else if(strcmp(buffer, "remove") == 0){
            handle_remove();
        }
        else if(strcmp(buffer, "print") == 0){
            handle_print();
        }
        else if(strcmp(buffer, "size") == 0){
            handle_size();
        }
        else if(strcmp(buffer, "reverse") == 0){
            handle_reverse();
        }
        else if(strcmp(buffer, "swap") == 0){
            handle_swap();
        }
        else if(strcmp(buffer, "exit") == 0){
            break;
        }
    }

}

void handle_create(){
    char buffer[MAX_LENGTH];
    fgets(buffer,MAX_LENGTH,stdin);
    char *p = strtok(buffer," ");
    Node *tail = NULL;
    while(p!=NULL){
        int val = atoi(p);

        tail = insert_tail(val, tail);


        p= strtok(NULL," ");
    }
}

Node * insert_tail(int val, Node *tail) {
    Node *ptr = (Node *) malloc(sizeof(Node));
    ptr->value = val;
//add at the end of the list

    if (head == NULL) {
        ptr->next = NULL;
        head = tail = ptr;
// tail is head and node
    } else {
        tail->next = ptr;
        tail = ptr;
    }
    return tail;
}

void handle_add(){

}

void handle_remove(){

}

void handle_print(){
    Node *p=head;
    while(p!=NULL){
        printf("%d ",p->value);
        p = p->next;
    }
    printf("\n");
}

void handle_size(){
    printf("%d ", size());
}

int size(){
    Node *p=head;
    int size = 0;
    while(p!=NULL){
        printf("%d ",p->value);
        size++;
        p = p->next;
    }
    return size;
}

void handle_reverse(){
    if(size() <= 1)
        return;

    Node *p = head->next, *q = head, *r = NULL;
    while(q!=NULL){
        q->next = r;
        r = q;
        q = p;
        if(p != NULL)
            p = p->next;
    }
    head = r;
}

void handle_swap(){
    int x, y;
    scanf("%d %d", &x,&y);
    int length = size();
    if(x < 0 || x >= length || y <= x || y >= length)
        return;

    Node *xptr = get_node(x-1);
    Node *yptr = get_node(y-1);

    Node *xptr = get_node(x);
    Node *yptr = get_node(y);


    if(x==0){
        if (y==x+1) {
            xptr->next = yptr->next;
            yptr->next = xptr;
            head = yptr;

        }
        else {

        }
    }
    else {
        if (y==x+1) {

        }
        else {

        }
    }
}