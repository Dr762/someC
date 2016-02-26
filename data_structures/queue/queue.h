//
// Created by abondar on 27.02.16.
//

#ifndef SOMEC_STACK_H
#define SOMEC_STACK_H

#include "../linked_list/list.h"
#include <stdlib.h>

typedef List Queue;

#define queue_init list_init
#define queue_destroy list_destroy

int queue_enqueue(Queue *queue,const void *data);
int queue_dequeue(Queue *queue, void **data);

#define queue_peek(queue) ((queue)->head == NULL ? NULL:(queue)->head->data)
#define queue_size list_size

#endif //SOMEC_STACK_H
