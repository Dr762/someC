//
// Created by abondar on 07.03.16.
//

#ifndef SOMEC_LIST_H
#define SOMEC_LIST_H
//elem
typedef struct ListElem_ {
    void *data;
        struct ListElem_ *next;
    }ListElem;


//list itself
typedef struct List_{

        int size;
        int (*match)(const void *key,const void *key2);
        void (*destroy)(void *data);

        ListElem *head;
        ListElem *tail;
    }List;

void list_init(List *list,void (*destroy)(void *data));
void list_destroy(List *list);
int  list_ins_next(List *list,ListElem *elem, const void *data);
int  list_rem_next(List *list,ListElem *elem,  void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list,element) ((element)==(list)->head ? 1:0)
#define list_is_tail(list,element) ((element)->next==NULL ? 1:0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)


#endif //SOMEC_LIST_H
