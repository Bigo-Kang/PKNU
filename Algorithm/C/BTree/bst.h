#ifndef BTREE_BTL_H
#define BTREE_BTL_H

#include "person.h"
#include <stdio.h>
#include <stdlib.h>

typedef  Person *Item;
typedef int(*CompareType)(Item, Item);

typedef struct node {
    Item data;
    struct node *left, *right, *parent;
}Node;

typedef  struct tree {
    Node *root;
    CompareType compareT;
}BST;

BST *create_bst(CompareType f);
Item search(BST *tree, Item item);
bool insert(BST *tree, Item item);
Item remov (BST *tree, Item item);
Node* tree_suc(Node *node);
Node* tree_pre(Node *node);
Node* search_node(BST *tree, Item item);

#endif //BTREE_BTL_H
