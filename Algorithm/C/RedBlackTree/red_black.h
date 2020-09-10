#ifndef REDBLACK_H
#define REDBLACK_H
#define RED 1
#define BLACK 2
#include"person.h"
typedef Person * Item;
typedef int(*CompareFtnType)(Item, Item);
struct node {
    Item data;
    int color;
    struct node *left, *right, *parent;
};

typedef struct node Node;

typedef struct tree {
    Node *root;
    CompareFtnType compareFtn;
}BST;

BST *create_bst(CompareFtnType f);
Item search(BST *tree, Item item);
void rb_insert(BST *tree, Item item);
Item rb_remov(BST *tree, Item item);
Node* tree_successor(Node *node);
Node* tree_pre(Node *node);
Node* search_node(BST *tree, Item item);
#endif

