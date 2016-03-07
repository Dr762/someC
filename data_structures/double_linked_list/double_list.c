//
// Created by abondar on 07.03.16.
//

 #include<stdlib.h>
 #include <string.h>
 #include <stdio.h>
 
 #include "double_list.h"
 
 void dlist_init(DList *list, void (*destroy)(void *data)) {
         list->size = 0;
         list->destroy = destroy;
         list->head = NULL;
         list->tail = NULL;
     
                 return;
     };
 
 void dlist_destroy(DList *list) {
         void *data;
     
                 //remove each elem
                         while (dlist_size(list)>0){
         
                         if (dlist_remove(list,dlist_tail(list),&data) ==0 && list->destroy !=NULL){
                         list->destroy(data);
                     }
             }
         memset(list,0, sizeof(DList));
         return;
     };
 
 int dlist_ins_next(DList *list, DListElem *elem, const void *data) {
         DListElem *new_elem;
     
                 if (elem == NULL && dlist_size(list) != 0) {
                 return -1;
             }
         //Allocate strorage for elem
                 if ((new_elem = (DListElem *) malloc(sizeof(DListElem))) == NULL) {
                 return -1;
             }
     
                 new_elem->data = (void *) data;
     
                 //insert when empty
                         if (dlist_size(list) == 0) {
         
                         list->head = new_elem;
                 list->head->prev = NULL;
                 list->head->next = NULL;
                 list->tail = new_elem;
         
                     } else {
                 //insert to non-empty
                         new_elem->next = elem->next;
                 new_elem->prev = elem;
         
                         if (elem->next == NULL) {
                         list->tail = new_elem;
                     } else {
                         elem->next->prev = new_elem;
                     }
         
                         elem->next = new_elem;
         
                     }
     
                 list->size  ;
         return 0;
     };
 
 int dlist_ins_prev(DList *list, DListElem *elem, void **data){
         DListElem *new_elem;
     
                 if (elem == NULL && dlist_size(list) != 0) {
                 return -1;
             }
     
                 //Allocate strorage for elem
                         if ((new_elem = (DListElem *) malloc(sizeof(DListElem))) == NULL) {
                 return -1;
             }
     
                 new_elem->data = (void *) data;
     
                 //insert when empty
                         if (dlist_size(list) == 0) {
         
                         list->head = new_elem;
                 list->head->prev = NULL;
                 list->head->next = NULL;
                 list->tail = new_elem;
         
                     } else {
                 //insert to non-empty
                         new_elem->next = elem;
                 new_elem->prev = elem->prev;
         
                         if (elem->next == NULL) {
                         list->head = new_elem;
                     } else {
                         elem->prev->next = new_elem;
                     }
         
                         elem->prev = new_elem;
         
                     }
     
                 list->size  ;
         return 0;
     };
 
 int dlist_remove(DList *list, DListElem *elem, void **data){
     
                 //no remove from empty
                         if (elem==NULL || dlist_size(list)==0){
                 return -1;
             }
     
                 *data = elem->data;
         if (elem == list->head){
                 //remove from head
                 
                                 list->head = elem->next;
                 if (list->head==NULL){
                         list->tail=NULL;
                     } else{
                         elem->next->prev=NULL;
                     }
             } else{
                 //remove not from head
                 
                                 elem->prev->next = elem->next;
         
                         if (elem->next==NULL){
                         list->tail =elem->prev;
             
                             } else{
                         elem->next->prev=elem->prev;
                     }
             }
     
                 free(elem);
         list->size--;
         return 0;
     
             }; 