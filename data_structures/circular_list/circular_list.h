//
// Created by abondar on 07.03.16.
//

#ifndef SOMEC_CIRCULAR_LIST_H
#define SOMEC_CIRCULAR_LIST_H
//elem

typedef struct CListElem_ {
    void *data;
    struct CListElem_ *next;

} CListElem;


//list itself

typedef struct CList_ {


    int size;


    int (*match)(const void *key1, const void *key2);


    void (*destroy)(void *data);


    CListElem *head;


} CList;


void clist_init(CList *list, void (*destroy)(void *data));


void clist_destroy(CList *list);

// elem- after which to insert
//NULL as elem to avoid confusion


int clist_ins_next(CList *list, CListElem *elem, const void *data);


int clist_rem_next(CList *list, CListElem *elem, void **data);


#define clist_size(list)((list)->size)
#define clist_head(list)((list)->head)
#define clist_data(element)((element)->data)
#define clist_next(element)((element)->next)


#endif //SOMEC_CIRCULAR_LIST_H
