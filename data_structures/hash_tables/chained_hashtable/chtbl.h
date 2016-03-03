//
// Created by abondar on 03.03.16.
//

#ifndef SOMEC_CHTBL_H
#define SOMEC_CHTBL_H


#include "list.h"

typedef struct CHTbl_ {
    int buckets;

    int (*h)(const void *key);

    int (*match) (const void *key1,const void *key2);

    void (*destroy)(void *data);

    int size;

    List *table;

} CHTbl;


int chtbl_init(CHTbl *html,int buckets, int (*h)(const void *key),
               int (*match)(const void *key1,const void *key2),
               void (*destroy)(void *data));

void chtbl_destroy(CHTbl *htbl);

int chtbl_insert(CHTbl *htbl,const void *data);

int chtbl_remove(CHTbl *htbl, void **data);

int chtbl_lookup(const CHTbl *htbl, void **data);

#define chtbl_size(htbl) ((htbl)->size)


#endif //SOMEC_CHTBL_H
