#include"red_black.h"
#include<stdio.h>
#include<stdlib.h>

void left_rotate(BST* tree, Node* x) {
    Node*y = x->right;
    if (y == NULL)
        return;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        tree->root = y;
    else {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void right_rotate(BST* tree, Node* x) {

    Node* y = x->left;
    if (y == NULL)
        return;
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL) {			//x가 루트
        tree->root = y;
    }
    else {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}
Node* tree_maximum(Node*tree) {
    Node* tmp = tree;
    while (tmp->right != NULL)
        tmp = tmp->right;
    return tmp;
}

Node* tree_pre(Node *node) {
    Node*tmp = node;
    if (tmp->right != NULL)
        return tree_maximum(tmp);
    Node*q = tmp->parent;
    while (q != NULL && tmp == q->left) {
        tmp = q;
        q = q->parent;
    }
    return q;
}

Node* tree_minimum(Node*tree) {
    Node*tmp = tree;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

Node* tree_successor(Node *node)
{
    Node*tmp = node;
    if (tmp->right != NULL)
        return tree_minimum(tmp->right);
    Node*q = tmp->parent;
    while (q != NULL && tmp == q->right) {
        tmp = q;
        q = q->parent;
    }
    return q;
}
BST *create_bst(CompareFtnType f) {
    BST* tmp = (BST*)malloc(sizeof(BST));
    tmp->root = NULL;
    tmp->compareFtn = f;
    return tmp;
}

Item search(BST *tree, Item item) {
    Node *p = tree->root;
    Node* floor = NULL, *ceiling = NULL;
    while (p != NULL) {
        int result = tree->compareFtn(p->data, item);
        if (result == 0)
            return p->data;
        else if (result > 0)
            p = p->left;
        else
            p = p->right;
    }
    return NULL;
}
void rb_insert_fixup(BST* tree, Node* z) {			//z는 삽입한 노드
    while (z->parent != NULL && z->parent->color == RED && z->parent->parent != NULL) {
        if (z->parent == z->parent->parent->left) {			//z부모노드가 할아버지 노드의 왼쪽 자식에 해당할 때	CASE 1,2,3
            Node*y = z->parent->parent->right;		//y는 삼촌노드에 해당
            if (y != NULL && y->color == RED) {					//FIXUP CASE 1		z삼촌이 RED일 때
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->right && (z->parent->left == NULL || z->parent->left->color == BLACK)) {			//삼촌노드가 블랙이거나 NIL일 때		CASE 2,3
                    z = z->parent;					//FIXUP CASE2			z가 부모의 오른쪽 자식일 때
                    left_rotate(tree, z);			//FIXUP CASE2
                }
                if (z->parent != NULL) {
                    z->parent->color = BLACK;			//FIXUP CASE3			z가 부모의 왼쪽 자식일 때
                    if (z->parent->parent == NULL)
                        break;
                    z->parent->parent->color = RED;
                    right_rotate(tree, z->parent->parent);
                }
            }
        }
        else {							//z부모노드가 할아버지 노드의 오른쪽 자식에 해당할 때 CASE 4,5,6
            Node*y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->left && (z->parent->left == NULL || z->parent->left->color == BLACK)) {
                    z = z->parent;
                    right_rotate(tree, z);
                }
                if (z->parent != NULL) {
                    z->parent->color = BLACK;
                    if (z->parent->parent == NULL)
                        break;
                    z->parent->parent->color = RED;
                    left_rotate(tree, z->parent->parent);
                }
            }
        }
    }
    tree->root->color = BLACK;
}
Node* search_node(BST *tree, Item item) {
    Node *p = tree->root;
    while (p != NULL) {
        int result = tree->compareFtn(p->data, item);
        if (result == 0)
            return p;
        else if (result > 0)
            p = p->left;
        else
            p = p->right;
    }
    return NULL;
}
void rb_insert(BST *tree, Item item) {
    Node *p = tree->root, *q = NULL;
    while (p != NULL) {
        int result = tree->compareFtn(p->data, item);
        q = p;
        if (result == 0)
            return;
        else if (result > 0)
            p = p->left;
        else
            p = p->right;
    }
    Node*tmp = (Node*)malloc(sizeof(Node));
    tmp->data = item;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->parent = NULL;
    tmp->color = RED;
    if (q == NULL) {
        tree->root = tmp;
        return;
    }
    int result = tree->compareFtn(q->data, item);
    if (result > 0) {
        q->left = tmp;
        tmp->parent = q;
    }
    else {
        q->right = tmp;
        tmp->parent = q;
    }

    rb_insert_fixup(tree, tmp);
}
void rb_delete_fixup(BST* tree, Node* x, Node*px, bool isLeftChild) {				//x는 삭제했던 y의 자식노드
    while (x != tree->root && (x == NULL || x->color == BLACK)) {
        if (isLeftChild) {					//DELETE_FIXUP CASE1,2,3,4
            Node *w = px->right;
            if (w->color == RED) {						//CASE 1
                w->color = BLACK;
                px->color = RED;
                left_rotate(tree, px);
                w = px->right;
            }
            if ((w->left == NULL || w->left->color == BLACK) && (w->right == NULL || w->right->color == BLACK)) {
                w->color = RED;
                x = px;
            }
            else {
                if ((w->right == NULL || w->right->color == BLACK) && (w->left != NULL && w->left->color == RED)) {
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(tree, w);
                    w = px->right;
                }
                if (w->right != NULL && w->right->color == RED) {
                    w->color = px->color;
                    px->color = BLACK;
                    w->right->color = BLACK;
                    left_rotate(tree, px);
                    x = tree->root;
                }
            }
        }
        else {
            Node *w = px->right;
            if (w->color == RED) {
                w->color = BLACK;
                px->color = RED;
                right_rotate(tree, px);
                w = px->right;
            }
            if ((w->left == NULL || w->left->color == BLACK) && (w->right == NULL || w->right->color == BLACK)) {
                w->color = RED;
                x = px;
            }
            else {
                if ((w->left == NULL || w->left->color == BLACK) && (w->right != NULL && w->right->color == RED)) {
                    w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(tree, w);
                    w = px->left;
                }
                if (w->left != NULL && w->left->color == RED) {
                    w->color = px->color;
                    px->color = BLACK;
                    w->left->color = BLACK;
                    right_rotate(tree, px);
                    x = tree->root;				//while을 빠져나가기위한 조건
                }
            }
        }
        if (x != tree->root) {
            px = x->parent;
            isLeftChild = (x == px->left);
        }
    }
    x->color = BLACK;
}
bool isLeftChild(Node* x) {
    if (x == x->parent->left)
        return true;
    return false;
}
Item rb_remov(BST *tree, Item item) {
    Item tmp = NULL;
    Node* p = search_node(tree, item);
    Node*q = NULL, *x = NULL;
    if (p == NULL)
        return NULL;

    if (p->left == NULL || p->right == NULL)
        q = p;
    else
        q = tree_successor(p);
    if (q->left != NULL)
        x = q->left;
    else
        x = q->right;
    if (x != NULL)
        x->parent = q->parent;
    if (q->parent == NULL)
        tree->root = x;
    else if (q == q->parent->left)
        q->parent->left = x;
    else
        q->parent->right = x;
    if (q != p) {
        tmp = p->data;
        p->data = q->data;
    }
    bool isLeft;
    if (q->left != x)
        isLeft = false;
    else
        isLeft = true;
    if (q->color == BLACK)
        rb_delete_fixup(tree, x, q->parent, isLeft);

//    deleteFixup(x, y->parent, isLeftChild);
//    x is possibly null, not root
//    y.parent is the parent of x
    return tmp;
}
