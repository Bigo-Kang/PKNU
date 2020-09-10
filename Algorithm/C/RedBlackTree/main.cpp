#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"red_black.h"
#define BUFFER_SIZE 200

BST *theTree;
int n = 0;

void process();
int isRedBlackTree(Node* x);
bool isRedBlackTree_recur();
void read_text(char *text);
void compress(char ptr[]);
void print(Node *p);
void inorder(Node * p);
void inorderFile(Node *p, FILE *fp);
void save(char *fileName, BST *tree);
void trace(BST* tree, Item item);
void f_cSearch(BST*tree, Item item);

int main() {
    theTree = create_bst(&compareTo);
    process();
    if (isRedBlackTree_recur())
        printf("True");
    else
        printf("False");
    return 0;
}
void process() {
    char command[BUFFER_SIZE];
    while (1) {
        printf("$");
        scanf(" %s", command);
        if (strcmp("read", command) == 0) {
            char text[BUFFER_SIZE];
            scanf("%s", text);
            read_text(text);
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
            q->data = rb_remov(theTree, p);
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


int isRedBlackTree(Node* x) {
    if (x == NULL)
        return 1;
    if (x->color == RED && (x->left != NULL && x->left->color == RED || x->right != NULL && x->right->color == RED))
        return -1;
    int result1 = isRedBlackTree(x->left);
    if (result1 == -1)
        return -1;
    int result2 = isRedBlackTree(x->right);
    if (result2 == -1 || result1 != result2)
        return -1;
    return result1 + (x->color == BLACK ? 1 : 0);
}

bool isRedBlackTree_recur() {
    if (theTree->root == NULL)
        return true;
    if (theTree->root->color == RED)
        return false;
    return isRedBlackTree(theTree->root) != -1;
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
    if (p->color == BLACK)
        printf("\tColor : BLACK\n");
    else
        printf("\tColor : RED\n");
}

void compress(char ptr[]) {		//문자열 사이에 많은 공백이 있으면 하나의 공백문자로
    ptr[strlen(ptr) - 1] = ' ';
    int i = 0, j = 0;
    char compressed[BUFFER_SIZE];
    char prev = '\0';

    while (ptr[i] == ' ')
        i++;//skip the leading blanks
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


void read_text(char *text) {
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
        rb_insert(theTree, tmp);
    }
    fclose(fp);
}

void inorder(Node * p) {			//inorder로 순회하면서 print
    if (p == NULL) {
        return;
    }
    inorder(p->left);
    print(p);
    inorder(p->right);
}
void inorderFile(Node *p, FILE *fp) {
    if (p == NULL) {
        return;
    }
    inorderFile(p->left, fp);
    fprintf(fp, "%s  |", p->data->name);
    fprintf(fp, "%s  |", p->data->company);
    fprintf(fp, "%s  |", p->data->address);
    fprintf(fp, "%s  |", p->data->zipcode);
    fprintf(fp, "%s  |", p->data->phone);
    fprintf(fp, "%s  \n", p->data->email);
    inorderFile(p->right, fp);
}
void save(char *fileName, BST *tree) {
    FILE *fp = fopen(fileName, "w");
    Node *p = tree->root;
    inorderFile(p, fp);
    fclose(fp);
}
void trace(BST* tree, Item item) {
    Node *p = tree->root;
    while (p != NULL) {
        printf("%s\n", p->data->name);
        int result = tree->compareFtn(p->data, item);
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

void f_cSearch(BST*tree, Item item) {
    Person* p = item;
    rb_insert(tree, p);
    Node * q = search_node(tree, item);
    Node*c = tree_successor(q);
    Node*f = tree_pre(q);
    if (f != NULL)
        printf("floor=%s\n", f->data->name);
    if (c != NULL)
        printf("ceiling=%s\n", c->data->name);
    rb_remov(tree, p);
}
