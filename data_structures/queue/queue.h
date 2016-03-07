//
// Created by abondar on 07.03.16.
//

#ifndef SOMEC_QUEUE_H
#define SOMEC_QUEUE_H
#include "list.h"
#include <stdlib.h>

typedef List Queue;

#define queue_init list_init
#define queue_destroy list_destroy

int queue_enqueue(Queue *queue,const void *data);
int queue_dequeue(Queue *queue, void **data);

#define queue_peek(queue) ((queue)->head == NULL ? NULL:(queue)->head->data)
#define queue_size list_size

#endif //SOMEC_QUEUE_H
