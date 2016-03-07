//
// Created by abondar on 07.03.16.
//

#include <stddef.h>
#include <stdio.h>
#include "chtbl.h"

int main() {

    CHTbl *chTbl;
    int *data = 0;

    chtbl_init(chTbl, 4, chTbl->match, chTbl->h, chTbl->destroy);
    printf("hash table inited\n");

    chtbl_insert(chTbl, &data);

    printf("size %d\n", chtbl_size(chTbl));
    chtbl_remove(chTbl, (void **) &data);
    printf("hash table removed\n");

    chtbl_destroy(chTbl);
    printf("hash table destroyed\n");


    return 0;
}