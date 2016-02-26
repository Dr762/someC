//
// Created by abondar on 27.02.16.
//

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main() {

    Queue *queue;
    int *data = 0;
    int *data1 = 1;
    int *data2 = 2;

    queue_init(queue, (void *) &data);

    printf("Queue has been created\n");
    queue_enqueue(queue, &data);
    queue_enqueue(queue, &data1);
    queue_enqueue(queue, &data2);


    printf("Queue size %d\n",queue_size(queue));

    queue_dequeue(queue,&data);
    queue_dequeue(queue,&data1);
    queue_dequeue(queue,&data2);

    printf("Queue has been cleared\n");

    queue_destroy(queue);
    printf("Queue has been destroyed\n");


    return 0;
}