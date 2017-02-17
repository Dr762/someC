//
// Created by abondar on 2/16/17.
//


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "sigint_handler.h"


int main(void){
    if (signal(SIGINT,sigint_handler)==SIG_ERR){
        fprintf(stderr, "Cannot handle SIGINT\n");
        exit(EXIT_FAILURE);
    }

    for (;;){
        pause();
    }

    return 0;
}



static void sigint_handler(int signo){
    printf("Caught SIGINT!\n");
    exit(EXIT_SUCCESS);
}