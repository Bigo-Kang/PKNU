#pragma once
#ifndef PERSON_H
#define PERSON_H

typedef struct person {
	char *name;
	char *address;
	char *company;
	char *zipcode;
	char *phone;
	char *email;
}Person;

int compareTo(Person *p, Person *q);
#endif // !PERSON_H
