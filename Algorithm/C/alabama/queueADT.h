#ifndef ALABAMA_QUEUEADT_H
#define ALABAMA_QUEUEADT_H
#include<stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;
Queue create();
void destyoy(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek(Queue q);
int get_size(Queue q);
#endif //ALABAMA_QUEUEADT_H
