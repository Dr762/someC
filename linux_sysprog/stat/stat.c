//
// Created by abondar on 2/16/17.
//

#include <malloc.h>

int main(void){
    struct  mallinfo m;
     m = mallinfo();

    printf("free chunks: %d\n",m.ordblks);

    malloc_stats();
}