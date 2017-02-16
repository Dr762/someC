//
// Created by abondar on 2/16/17.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_LEN 1024

int main(void){
    char  cwd[BUF_LEN];

    if (!getcwd(cwd,BUF_LEN)){
        perror("getcwd");
        exit(EXIT_FAILURE);
    }

    printf("cwd= %s\n",cwd);
}