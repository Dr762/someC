//
// Created by abondar on 23.02.16.
//

#include <stdio.h>
#include "double_list.h"


int main() {

    DList *l;

    int *data=0;
    int *data1=1;
    int *data2=2;
    int *data3 =3;

    dlist_init(l, (void *) &data);
    printf("Linked list has been initalized\n");

    dlist_ins_next(l, NULL, data1);
    dlist_ins_prev(l, l->head, data);
    dlist_ins_next(l, l->tail, data2);


    printf("Current double linked list size %d\n", dlist_size(l));

    printf("Head elem %d\n",dlist_head(l)->data);
    printf("Tail elem %d\n",dlist_tail(l)->data);

    dlist_ins_prev(l,l->tail,data3);

    printf("New head elem %d\n",dlist_head(l)->data);
    printf("Current linked list size %d\n", dlist_size(l));

    dlist_remove(l, dlist_tail(l)->prev->prev, (void *) &data1);
    dlist_remove(l, dlist_tail(l), (void *) &data2);
    dlist_remove(l, dlist_head(l), (void *) &data3);
    dlist_remove(l, l->head, (void *) &data);


    printf("Linked list has been cleared\n");

    if (dlist_size(l)==0) {
        dlist_destroy(l);
        printf("Linked list has been destroyed\n");
    } else{
        printf("Can't delete list. It's not empty %d\n",dlist_size(l));

    };

    return 0;
}



