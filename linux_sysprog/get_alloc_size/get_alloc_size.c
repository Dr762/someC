//
// Created by abondar on 2/16/17.
//

#include <malloc.h>

int main(void){
    size_t len =21;
    size_t size;
    char *buf;

    buf = malloc(len);
    if (!buf){
        perror("malloc");
        return -1;
    }

    size = malloc_usable_size(buf);

    printf("size %zu\n",size);


}