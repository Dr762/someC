//
// Created by abondar on 07.03.16.
//

#include<stdlib.h>
#include <string.h>
#include <stdio.h>
#include "circular_list.h"


void clist_init(CList *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;

    return;
};


void clist_destroy(CList *list) {
    void *data;

    //remove each elem
    while (clist_size(list) > 0) {
        if (clist_rem_next(list, list->head, (void **) &data) == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }
    memset(list, 0, sizeof(CList));
    return;
};


int clist_ins_next(CList *list, CListElem *elem, const void *data) {
    CListElem *new_elem;

    //Allocate strorage for elem
    if ((new_elem = (CListElem *) malloc(sizeof(CListElem))) == NULL) {
        return -1;
    }

    new_elem->data = (void *) data;

    //insert to head

    if (clist_size(list) == 0) {
        new_elem->next = new_elem;
        list->head = new_elem;
    } else {
        //insert not to head

        new_elem->next = elem->next;
        elem->next = new_elem;
    }

    list->size;
    return 0;
};

int clist_rem_next(CList *list, CListElem *elem, void **data) {
    CListElem *old_elem;

    //no remove from empty
    if (clist_size(list) == 0) {
        return -1;
    }

    *data = elem->next->data;
    //remove last
    if (elem->next == elem) {
        old_elem = elem->next;
        list->head = NULL;
    } else {
        //remove not last
        old_elem = elem->next;
        elem->next = elem->next->next;
        if (old_elem == clist_head(list)) {
            list->head = old_elem->next;
        }
    }

    free(old_elem);
    list->size--;
    return 0;

};