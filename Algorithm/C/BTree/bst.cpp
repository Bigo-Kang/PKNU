#include "bst.h"
Node *tree_mini (Node *node);
Node *tree_maxi (Node *node);

BST *create_bst(CompareType f) {
    BST* tmp = (BST*)malloc(sizeof(BST));
    tmp->root = NULL;
    tmp->compareT = f;
    return tmp;
}

Item search(BST *tree, Item item) {
    Node *p = tree->root;
    Node* floor=NULL , *ceiling=NULL ;
    while (p != NULL) {
        int result = tree->compareT(p->data, item);
        if (result == 0)
            return p->data;
        else if (result > 0)
            p = p->left;
        else
            p = p->right;
    }
    return NULL;
}

Node* search_node(BST *tree, Item item) {
    Node *p = tree->root;

    while ( p != NULL ) {
        int result = tree->compareT(p->data, item);
        if (result == 0)
            return p;
        else if (result > 0)
            p = p->left;
        else
            p = p->right;
    }
    return NULL;
}

bool insert(BST *tree, Item item) {
    Node *p = tree->root, *q=NULL;
    while (p != NULL) {
        int result = tree->compareT(p->data, item);
        q = p;
        if (result == 0)
            return false;
        else if (result > 0)
            p = p->left;
        else
            p = p->right;
    }
    Node *tmp = (Node*)malloc(sizeof (Node));
    tmp->data = item;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->parent = NULL;
    if (q == NULL) {
        tree->root = tmp;
        return true;
    }
    int result = tree->compareT(q->data, item);
    if (result > 0) {
        q->left = tmp;
        tmp->parent = q;
    }
    else {
        q->right = tmp;
        tmp->parent = q;
    }
    return true;
}

Item remov (BST *tree, Item item) {
    Node* tmp = tree->root;
    Node* p = search_node(tree, item);
    Node* q = NULL;
    if(p == NULL)
        return NULL;

    if (p->left == NULL || p->right == NULL)
        q=p;
    else
        q = tree_suc (p);
    if ( q->left != NULL)
        tmp = q->left;
    else
        tmp = q->right;
    if (tmp != NULL)
        tmp->parent = q->parent;
    if (q->parent == NULL)
        tree->root = tmp;
    else if (q==q->parent->left)
        q->parent->left = tmp;
    else
        q->parent->right = tmp;
    if(q != p)
        p->data = q->data;
    return q->data;
}

Node* tree_suc(Node *node) {
    Node *tmp = node;
    if (tmp->right != NULL)
        return tree_mini(tmp);
    Node*q = tmp->parent;
    while( q != NULL && tmp == q->right) {
        tmp = q;
        q = q->parent;
    }
    return q;
}

Node *tree_mini (Node *node) {
    Node *tmp = node;
    while(tmp->left != NULL)
        tmp = tmp->left;
    return tmp;
}

Node* tree_pre(Node *node) {
    Node *tmp = node;
    if ( tmp->right != NULL)
        return tree_maxi(tmp);
    Node *q = tmp->parent;
    while (q != NULL && tmp == q->left) {
        tmp = q;
        q = q->parent;
    }
    return q;
}

Node *tree_maxi (Node *node) {
    Node *tmp = node;
    while(tmp->right != NULL)
        tmp = tmp->right;
    return tmp;
}