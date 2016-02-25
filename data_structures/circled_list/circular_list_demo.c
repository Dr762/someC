//
// Created by abondar on 23.02.16.
//

#include <stdio.h>
#include "circular_list.h"


int main() {

    //linked list
    CList *l;

    int *data=0;
    int *data1=1;
    int *data2=2;

    clist_init(l, (void *) &data);
    printf("Circular list has been initalized\n");

    clist_ins_next(l, NULL, data);
    clist_ins_next(l,clist_head(l) ,data1);
    clist_ins_next(l,clist_next(clist_head(l)) ,data2);

    printf("Current linked list size %d\n", clist_size(l));
    printf("Head elem %d\n",clist_head(l)->data);

    printf("Next of head %d\n",clist_head(l)->next->data);
    printf("Next next of head %d\n",clist_head(l)->next->next->data);

    clist_rem_next(l, clist_head(l)->next, (void *) &data2);
    clist_rem_next(l, clist_head(l), (void *) &data1);
    clist_rem_next(l, clist_head(l), (void *) &data);

    printf("Linked list has been cleared\n");

    if (clist_size(l)==0) {
        clist_destroy(l);
        printf("Linked list has been destroyed\n");
    } else{
        printf("Can't delete list. It's not empty %d\n",clist_size(l));

    };
    return 0;
}



