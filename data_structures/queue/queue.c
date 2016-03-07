//
// Created by abondar on 07.03.16.
//

#include "queue.h"


 #include "list.h"
 
 int queue_enqueue(Queue *queue,const void *data){
     
             
                         return  list_ins_next(queue,NULL,data);
     };
 
 
 int queue_dequeue(Queue *queue, void **data){
         return list_rem_next(queue,NULL,data);
     };
 