//
// Created by abondar on 23.02.16.
//

#ifndef SOMEC_LIST_H
#define SOMEC_LIST_H

#include <stdlib.h>
//elem
typedef struct DListElem_ {
    void *data;
    struct DListElem_ *prev;
    struct DListElem_ *next;
}DListElem;


//list itself
typedef struct DList_{

    int size;
    int (*match)(const void *key1,const void *key2);
    void (*destroy)(void *data);

    DListElem *head;
    DListElem *tail;
}DList;

void dlist_init(DList *list,void (*destroy)(void *data));
void dlist_destroy(DList *list);
int  dlist_ins_next(DList *list,DListElem *elem, const void *data);
int  dlist_ins_prev(DList *list,DListElem *elem,  void **data);
int  dlist_remove(DList *list,DListElem *elem, void** data);

#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)
#define dlist_is_head(element) ((element)->prev==NULL ? 1:0)
#define dlist_is_tail(element) ((element)->next==NULL ? 1:0)
#define dlist_data(element) ((element)->data)
#define dlist_next(element) ((element)->next)
#define dlist_prev(element) ((element)->next)


#endif //SOMEC_LIST_H
