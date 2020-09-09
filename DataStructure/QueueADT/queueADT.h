//
// Created by 강대원 on 2017. 11. 20..
//
#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef  int Item;
typedef struct queue_type *Queue;

Queue create();
void destroy(Queue q);
void make_empty(Queue q);
bool is_empty(Queue q);
void enqueue(Queue q, Item i);
Itme dequeue(Queue q);
Itme peek(Queue q);
int get_size(Queue q);

#endif //QUEUE_QUEUEADT_H
