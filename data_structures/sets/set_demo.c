//
// Created by abondar on 27.02.16.
//

#include <stdlib.h>
#include <stdio.h>
#include "set.h"

int main() {

    Set *set;


    set_init(set, set->match, NULL);
    printf("Set size %d\n", set_size(set));


    set_destroy(set);
    printf("Set has been destroyed\n");
    return 0;
}