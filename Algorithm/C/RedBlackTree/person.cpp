#include "person.h"
#include <string.h>

int compareTo(Person *p, Person *q) {
	return strcmp(p->name, q->name);
}