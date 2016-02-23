//
// Created by abondar on 23.02.16.
//

#include <stdio.h>
#include "list.h"


int main() {

    //linked list
    List *l;

    int *data=0;
    int *data1=1;
    int *data2=2;
    int *data3 =3;

    list_init(l, (void *) &data);
    printf("Linked list has been initalized\n");

    list_ins_next(l, NULL, data);
    list_ins_next(l,NULL ,data1);
    list_ins_next(l,NULL ,data2);


    printf("Current linked list size %d\n", list_size(l));

    printf("Head elem %d\n",l->head->data);
    printf("Next of head elem %d\n",l->head->next->data);
    printf("Next of the next %d\n",l->head->next->next->data);
    printf("Tail elem %d\n",l->tail->data);

    list_ins_next(l,l->head,data3);

    printf("Current linked list size %d\n", list_size(l));
    printf("New next of head %d\n",l->head->next->data);

    list_rem_next(l, NULL, (void *) &data);
    list_rem_next(l, NULL, (void *) &data1);
    list_rem_next(l, NULL, (void *) &data2);
    list_rem_next(l, NULL, (void *) &data3);

    printf("Linked list has been cleared\n");

    list_destroy(l);
    printf("Linked list has been destroyed\n");

    return 0;
}



