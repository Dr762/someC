//
// Created by abondar on 07.03.16.
//

#include "chtbl.h"
 #include "list.h"
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
 
 
 int chtbl_init(CHTbl *htbl, int buckets, int (*h)(const void *key),
                int (*match)(const void *key1, const void *key2),
                void (*destroy)(void *data)) {
 
     int i;
     if ((htbl->table = (List *) malloc(buckets * sizeof(List))) == NULL)
         return -1;
 
     //init buckets
     htbl->buckets = buckets;
     for(i=0;i< htbl->buckets;i  ){
         list_init(&htbl->table[i],destroy);
     }
 
     //encapsulate funcs
     htbl->h =h;
     htbl->match=match;
     htbl->destroy=destroy;
 
     //init number of elems
     htbl->size=0;
     return 0;
 };
 
 void chtbl_destroy(CHTbl *htbl){
         int i;
         for(i=0;i< htbl->buckets;i  ){
                 list_destroy(&htbl->table[i]);
             }
     
                 free(htbl->table);
     
                 memset(htbl,0, sizeof(CHTbl));
     
                 return;
     };
 
 int chtbl_insert(CHTbl *htbl, const void *data){
     
                 void *temp;
         int bucket,retval;
     
                 temp = (void *)data;
     
                 //already exists
                         if (chtbl_lookup(htbl,&temp)==0)
                 return 1;
     
                 //hash the key
                         bucket = htbl->h(data) % htbl->buckets;
     
                 if ((retval == list_ins_next(&htbl->table[bucket],NULL,data))==0)
                 htbl->size  ;
     
                 return retval;
     };
 
 int chtbl_remove(CHTbl *htbl, void **data){
         ListElem *elem,*prev;
     
                 int bucket;
     
                 bucket = htbl->h(*data) % htbl->buckets;
     
                 prev =NULL;
     
                 for (elem=list_head(&htbl->table[bucket]);elem !=NULL;elem=list_next(elem)){
                 if (htbl->match(*data,list_data(elem))){
                         if (list_rem_next(&htbl->table[bucket],prev,data)==0){
                 
                                         htbl->size--;
                                 return 0;
                             } else{
                                 return -1;
                             }
                     }
         
                         prev = elem;
             }
     
                 //data not found
                         return -1;
     
             };
 
 
 int chtbl_lookup(const CHTbl *htbl, void **data){
     
                 ListElem *elem;
         int bucket;
     
                 bucket = htbl->h(*data) % htbl->buckets;
     
                 for (elem=list_head(&htbl->table[bucket]);elem !=NULL;elem=list_next(elem)) {
                 if (htbl->match(*data, list_data(elem))) {
                         *data = list_data(elem);
                         return 0;
                     }
             }
     
                     return -1;
     };