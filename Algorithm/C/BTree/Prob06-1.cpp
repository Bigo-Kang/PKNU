#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"bst.h"
#define BUFFER_SIZE 200

BST *theTree;
int n = 0;
void process();
void print(Node *p);
void compress(char ptr[]);
void read(char *text);
void inorder(Node * p);
void inorderFile(Node *p,FILE *fp);
void save(char *fileName,BST *tree);
void trace(BST* tree,Item item);
void f_cSearch(BST*tree, Item item);

int main() {
    theTree = create_bst(&compareTo);
    process();
    return 0;
}
void process() {
    char command[BUFFER_SIZE];
    while (1) {
        printf("$ ");
        scanf(" %s", command);
        if (strcmp("read", command) == 0) {
            char text[BUFFER_SIZE];
            scanf("%s", text);
            read(text);
        }
        else if (strcmp("list", command) == 0) {
            inorder(theTree->root);
        }
        else if (strcmp("find", command) == 0) {
            char tmp[BUFFER_SIZE];
            scanf("%s", tmp);
            Person* p = (Person*)malloc(sizeof(Person));
            p->name = tmp;
            Node *q = (Node*)malloc(sizeof(Node));
            q->data = search(theTree, p);
            if (q->data != NULL)
                print(q);
            else
                f_cSearch(theTree, p);
        }
        else if (strcmp("trace", command) == 0) {
            char tmp[BUFFER_SIZE];
            scanf("%s", tmp);
            Person* p = (Person*)malloc(sizeof(Person));
            p->name = tmp;
            trace(theTree, p);
        }
        else if (strcmp("delete", command) == 0) {
            char tmp[BUFFER_SIZE];
            scanf("%s", tmp);
            Person* p = (Person*)malloc(sizeof(Person));
            p->name = tmp;
            Node *q = (Node*)malloc(sizeof(Node));
            q->data = remov (theTree, p);
            print(q);
        }
        else if (strcmp("save", command) == 0) {
            char tmp[BUFFER_SIZE];
            scanf("%s", tmp);
            save(tmp, theTree);
        }
        else if (strcmp("exit", command) == 0)
            break;

    }
}

void read(char *text) {
    FILE*fp = fopen(text, "r");
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        Item tmp = (Person*)malloc(sizeof(Person));
        char *p = strtok(buffer, "|");
        compress(p);
        tmp->name = strdup(p);
        p = strtok(NULL, "|");
        compress(p);
        tmp->company = strdup(p);
        p = strtok(NULL, "|");
        compress(p);
        tmp->address = strdup(p);
        p = strtok(NULL, "|");
        compress(p);
        tmp->zipcode = strdup(p);
        p = strtok(NULL, "|");
        compress(p);
        tmp->phone = strdup(p);
        p = strtok(NULL, "|");
        compress(p);
        tmp->email = strdup(p);
        insert(theTree, tmp);
    }
    fclose(fp);
}
void compress(char ptr[]) {
    ptr[strlen(ptr) - 1] = ' ';
    int i = 0, j = 0;
    char compressed[BUFFER_SIZE];
    char prev = '\0';

    while (ptr[i] == ' ')
        i++;
    while (ptr[i] != '\0') {
        if (ptr[i] != ' ' || prev != ' ')
            compressed[j++] = ptr[i];

        prev = ptr[i];
        i++;
    }
    if (prev == ' ' || prev == '\n')
        compressed[--j] = '\0';
    else
        compressed[j] = '\0';
    strcpy(ptr, compressed);
}

void inorder(Node * p) {			//inorder로 순회하면서 print
    if (p == NULL) {
        return;
    }
    inorder(p->left);
    print(p);
    inorder(p->right);
}

void print(Node *p) {
    if (p->data == NULL)
        return;
    printf("%s\n", p->data->name);
    printf("\tCompany : %s\n", p->data->company);
    printf("\tAddress : %s\n", p->data->address);
    printf("\tZipcode : %s\n", p->data->zipcode);
    printf("\tPhone : %s\n", p->data->phone);
    printf("\tEmail : %s\n", p->data->email);
}

//-----------save
void save(char *fileName,BST *tree) {
    FILE *fp = fopen(fileName, "w");
    Node *p = tree->root;
    inorderFile(p, fp);
    fclose(fp);
}

void inorderFile(Node *p,FILE *fp) {
    if (p == NULL) {
        return;
    }
    inorderFile(p->left, fp);
    fprintf(fp,"%s  |", p->data->name);
    fprintf(fp,"%s  |", p->data->company);
    fprintf(fp,"%s  |", p->data->address);
    fprintf(fp,"%s  |", p->data->zipcode);
    fprintf(fp,"%s  |", p->data->phone);
    fprintf(fp,"%s  \n", p->data->email);
    inorderFile(p->right, fp);
}

void trace(BST* tree,Item item) {
    Node *p = tree->root;
    while (p != NULL) {
        printf("%s\n",p->data->name);
        int result = tree->compareT(p->data, item);
        if (result == 0)
            return;
        else if (result > 0)
            p = p->left;
        else
            p = p->right;
    }
    printf("Not Found\n");
    return;
}

//-------Prob 2
void f_cSearch(BST*tree, Item item) {
    Person* p = item;
    insert(tree, p);
    Node *q = search_node(tree, item);
    Node *f = tree_pre(q);
    Node *c = tree_suc(q);
    if(f!=NULL)
        printf("floor=%s\n", f->data->name);
    if (c != NULL)
        printf("ceiling=%s\n", c->data->name);
    remov (tree, p);
}