//suppose perfect input
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef struct node {
    int data;
    struct node *next;
}Node;
Node *head = NULL;
int readLine(char str[], int limit);
void create(char *cmd);
Node* createAdd(Node *prev, char *ptr);
void add(char *commandLine);
void fadd(char *ptr);
void iadd(char *cmd);
void remove(char *commandLine);
Node* iremove(char *index);
Node* vremove(char *data);
Node* rremove(char *data);
Node* removeFirst();
Node* removeAfter(Node *prev);
Node* search(int num);
void size();
void reverse();
void swap(char *commandLine);
void realSwap(int x, int y);
Node *getNode(int index);
void print();
int n = 0;
int main()
{
    char commandLine[MAX];
    char *command, *argument, *argument1;
    while (1) {
        printf("$ ");
        if (readLine(commandLine, MAX) <= 0)
            continue;
        command = strtok(commandLine, " ");
        if (strcmp(command, "create") == 0) {
            create(commandLine);
        }
        else if (strcmp(command, "add") == 0) {
            add(commandLine);
        }
        else if (strcmp(command, "remove") == 0) {
            remove(commandLine);
        }
        else if (strcmp(command, "size") == 0) {
            size();
        }
        else if (strcmp(command, "reverse") == 0) {
            reverse();
        }
        else if (strcmp(command, "swap") == 0) {
            swap(commandLine);
        }
        else if (strcmp(command, "print") == 0) {
            print();
        }
        else if (strcmp(command, "exit") == 0)
            break;
    }
    return 0;
}
int readLine(char str[], int limit) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < limit - 1) str[i++] = ch;
    str[i] = '\0';
    return i;
}
void create(char *cmd) {
    char *ptr;
    ptr = strtok(NULL, " ");
    fadd(ptr);
    /*
    head = (Node*)malloc(sizeof(Node));
    head->data = atoi(ptr);
    head->next = NULL;
    */
    n++;
    Node *pre = head;
    ptr = strtok(NULL, " ");
    while (ptr != NULL) {
        pre = createAdd(pre, ptr);
        ptr = strtok(NULL, " ");
    }
}
Node* createAdd(Node *prev, char *ptr) {
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->data = atoi(ptr);
    tmp->next = NULL;
    prev->next = tmp;
    n++;
    return tmp;
}
void add(char *commandLine) {
    char *ptr = strtok(NULL, " ");
    if (strcmp(ptr, "-f") == 0) {
        ptr = strtok(NULL, " ");
        fadd(ptr);
    }
    else
    {
        iadd(ptr);
    }
}
void fadd(char *ptr) {
    Node * tmp = (Node *)malloc(sizeof(Node));
    tmp->data = atoi(ptr);
    tmp->next = head;
    head = tmp;
    n++;
}
void iadd(char *cmd) {
    char*arg1 = strtok(NULL, " ");
    char*arg2 = strtok(NULL, " ");
    if (atoi(arg1) == 0) {
        fadd(arg2);
        return;
    }
    Node *ptr = head;
    for (int i = 0; i < atoi(arg1) - 1; i++) //ptr이 head를 가리키고 있기에 -1을 해줌
        ptr = ptr->next;
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->data = atoi(arg2);
    tmp->next = ptr->next;
    ptr->next = tmp;
    n++;
}
void remove(char *commandLine) {
    char *ptr = strtok(NULL, " ");
    if (strcmp(ptr, "-i") == 0) {
        ptr = strtok(NULL, " ");
        iremove(ptr);
    }
    else if (strcmp(ptr, "-v") == 0) {
        ptr = strtok(NULL, " ");
        vremove(ptr);
    }
    else {
        ptr = strtok(NULL, " ");
        rremove(ptr);
    }
}
Node* iremove(char *index) {
    int num = atoi(index);
    if (num == 0) {
        removeFirst();
        //return head or new node odject;
    }
    else {
        Node *p = head;
        for (int i = 0; i < num - 1; i++)
            p = p->next;
        p = removeAfter(p);
    }
    return 0;
}
Node* removeFirst() {
    if (head == NULL) {
        return NULL;
    }
    else {
        head = head->next;
        n--;
        return NULL;
    }
}
Node* removeAfter(Node *prev) {
    Node*tmp = prev->next;
    if (head == NULL) {
        return NULL;
    }
    else {
        prev->next = tmp->next;
        n--;
        return tmp;
    }
}
Node* vremove(char *data) {
    int num = atoi(data);
    Node *p = search(num);
    if (p->data == num && p == head) removeFirst();
    else {
        p = removeAfter(p);
    }
    return NULL;
}
Node* search(int num) {
    Node *p = head;
    if (p->data == num) return p;
    //p = p->next;
    while (p != NULL) {
        if (p->next->data == num) return p;
        p = p->next;
    }
    return NULL;
}
Node* rremove(char *data) {
    int num = atoi(data);
    Node *p = head;
    Node *q = NULL;
    while (p != NULL) {
        if (p->data%num == 0 && q == NULL) removeFirst();
        if (p->data%num == 0 && q != NULL) removeAfter(q);
        q = p;
        p = p->next;
    }
    return NULL;
}
void size() {
    if (n == 0) {
        printf("%d\n", n);
        return;
    }
    printf("%d\n", n - 1);
}
void reverse() {
    node *p, *q, *r;
    p = head;
    q = NULL;
    r = NULL;
    while (p->next != NULL) {
        if (q != NULL)
            q->next = r;
        r = q;
        q = p;
        p = p->next;
    }
    if (q != NULL)
        q->next = r;
    p->next = q;
    head = p;
}
void swap(char *commandLine) {
    char *ptr1 = strtok(NULL, " ");
    char *ptr2 = strtok(NULL, " ");
    int arg1 = atoi(ptr1), arg2 = atoi(ptr2);
    realSwap(arg1, arg2);
    /*
    Node *p;
    Node *q;
    Node *r;
    Node *s;
    if (arg1 == 0 || arg2 == 0) {
     int arg3 = (arg1 > arg2 ? arg1 : arg2) - 1;
     int arg4 = (arg1 > arg2 ? arg2 : arg1) + 1;
     if (arg1 - arg2 == 1 || arg2 - arg1 == 1) {
      if (arg1 == 0) p = getNode(arg2);
      else
       p = getNode(arg1);
      q = head;
      head = p;
      q->next = p->next;
      p->next = q;
     }
     else {
      r = getNode(arg3);
      s = getNode(arg4);
      if (arg1 == 0) p = getNode(arg2);
      else
       p = getNode(arg1);
      q = head;
      head = p;
      r->next = q;
      q->next = p->next;
      p->next = s;

     }
    }
    else {
     int arg3 = (arg1 < arg2 ? arg1 : arg2) - 1;
     if (arg1 - arg2 == 1 || arg2 - arg1 == 1) {
      r = getNode(arg3);
      if (arg1 < arg2) {
       p = getNode(arg2);
       q = getNode(arg1);
      }
      else {
       p = getNode(arg1);
       q = getNode(arg2);
      }
      r->next = p;
      q->next = p->next;
      p->next = q;
      // p->next = q;
     }
     else {
      int arg3 = (arg1 > arg2 ? arg1 : arg2) - 1;
      int arg4 = (arg1 > arg2 ? arg2 : arg1) - 1;
      r = getNode(arg3); s = getNode(arg4);
      if (arg1 < arg2) {
       p = getNode(arg2);
       q = getNode(arg1);
      }
      else {
       p = getNode(arg1);
       q = getNode(arg2);
      }
      //s->next = p;
      //r->next = q;
      //q->next = p->next;
      //p->next = r;
      s->next = p;
      r->next = p->next;
      p->next = q->next;
      q->next = r->next;
      r->next = q;
     }
    }
    */
}
void realSwap(int x, int y) {
    node *p, *q, *r, *s;
    p = head;
    q = NULL;
    r = head;
    s = NULL;
    for (int i = 0; i < y; i++) {
        q = p;
        p = p->next;
    }
    for (int i = 0; i < x; i++) {
        s = r;
        r = r->next;
    }
    if (s != NULL)
        s->next = p;
    else
        head = p;
    if (q != NULL)
        q->next = r;
    else
        head = r;
    node* tmp;
    tmp = r->next;
    r->next = p->next;
    p->next = tmp;
}
Node *getNode(int index) {
    if (index < 0) return NULL;
    Node *p = head;
    for (int i = 0; i < index && p != NULL; i++)
        p = p->next;
    return p;
}

void print() {
    Node *p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
} 