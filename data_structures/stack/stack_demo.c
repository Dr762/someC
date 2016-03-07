//
// Created by abondar on 07.03.16.
//

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main() {

    Stack *stack;
    int *data = 0;
    int *data1 = 1;
    int *data2 = 2;

    stack_init(stack, (void *) &data);

    printf("Stack has been created\n");
    stack_push(stack, &data);
    stack_push(stack, &data1);
    stack_push(stack, &data2);

    printf("Stack head %d\n", stack_peek(stack));
    printf("Stack size %d\n", stack_size(stack));

    stack_pop(stack, &data2);
    stack_pop(stack, &data1);
    stack_pop(stack, &data);

    printf("Stack has been cleared\n");

    stack_destroy(stack);
    printf("Stack has been destroyed\n");


    return 0;
}