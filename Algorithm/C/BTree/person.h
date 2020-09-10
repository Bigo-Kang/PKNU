#ifndef BTREE_PERSON_H
#define BTREE_PERSON_H

typedef  struct person {
    char *name;
    char *address;
    char *company;
    char *zipcode;
    char *phone;
    char *email;
}Person;

int compareTo(Person *p, Person *q);

#endif //BTREE_PERSON_H
