//
// Created by abondar on 2/16/17.
//

#include "multi_signal_handler.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(void){

    /*register handler*/
    if (signal(SIGINT,signal_handler)==SIG_ERR){
        fprintf(stderr, "Cannot handle SIGINT\n");
        exit(EXIT_FAILURE);
    }

    /*register handler*/
    if (signal(SIGTERM,signal_handler)==SIG_ERR){
        fprintf(stderr, "Cannot handle SIGTERM\n");
        exit(EXIT_FAILURE);
    }


    /*reset SIGPROF's behavior to default */
    if (signal(SIGPROF,SIG_DFL)==SIG_ERR){
        fprintf(stderr,"Cannot reset SIGPROF!");
    }


    /*ignore SIGHUP*/
    if (signal(SIGHUP,SIG_IGN)==SIG_ERR){
        fprintf(stderr,"Cannot ignore SIGHUP!");
    }

    for(;;){
        pause();
    }

    return 0;


}

static void signal_handler(int signo) {
    if (signo == SIGINT) {
        printf("Caught SIGINT\n");
    } else if (signo == SIGTERM) {
        printf("Caught SIGTERM\n");
    } else {
        fprintf(stderr,"Unexpected signal");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}