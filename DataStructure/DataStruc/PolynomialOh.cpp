#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_POLYS 100
//자료구조를 먼저 생각해야한다. 이런것이 먼저 이루어져야 한다.
struct term{
    int coef;
    int expo;
    struct term *next;
};
typedef  struct term Term;

typedef struct polynomial{
    char name;
    Term*first;
    int size;
} Polynomial;

Term *create_term_instance(int c, int e);
void print_poly(Polynomial *ptr_poly;

Polynomial *polys[MAX_POLYS];
int n = 0; //전역변수에서 한 글자짜리의 변수이름은 좋은 생각이 아니다.

int main() {

    Polynomial *p = create_polynomial_instance ('f');
    add_term (4, 3, p);
    add_term (-4, 4, p);
    add_term (1, 0, p);
    add_term (-4, 3, p);
    add_term (5, 2, p);
    print_poly(p);

}

void print_poly(Polynomial *ptr_poly) {
    Term *p = ptr_poly->first;
    printf("%c=",ptr_poly->name);
    while(p!=NULL){
        printf("%dx^%d+", p->coef,p->expo);
        p=p->next;
    }
    printf("\n");
}

void add_term(int c, int e, Polynomial *ptr_poly, Term t)
{
    if(c==0)
        return;
    Term *p = ptr_poly->first, *q=NULL;
    while(p!=NULL && p->expo != e){
        //프로그래밍 조건문에서 &&연산의 순서는 교환법칙이 성립하지 않는다
        q = p;
        p = p->next;
    }
    if(p!=NULL && p->expo == e){    // exist
        p->coef += c;
        // zero after add
        if(p->coef == 0) {   // remove p
            if (q == NULL) //first node
                ptr_poly->first = p->next;


            else
                q->next = p->next;
            ptr_poly->size--;
            free (p);
        }
    }
    else{   // not exist
        Term *t = create_term_instance(c,e);
        if(q==NULL){
            t->next = ptr_poly->first;
            ptr_poly->first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
        ptr_poly->size++;
    }
}

Term *create_term_instance(int c, int e) {
    Term *t = (Term*)malloc(sizeof(Term));
    t->coef = c;
    t->expo = e;
    t->next = NULL;
    return t;
}

Polynomial *create_polynomial_instance(char name) {
    Polynomial*p=(Polynomial *)malloc(sizeof(Polynomial));
    p->name = name;
    p->first = NULL;
    p->size = 0;
    return p;
}