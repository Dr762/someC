//
// Created by abondar on 2/12/17.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/poll.h>

#define TIMEOUT 5

// run: ./poll_demo - stdin ready
// ./poll_demo < file - stdin and stdout will be ready
int main(void){
    struct pollfd fds[2];
    int ret;

    /*watch stdin for input*/
    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;

    /*watch stdout for write*/
    fds[1].fd = STDOUT_FILENO;
    fds[1].events = POLLOUT;

    /*BLOCK*/
    ret = poll(fds,2,TIMEOUT * 1000);
    if (ret ==-1){
        perror("poll");
        return 1;
    }

    if(!ret){
        printf("%d seconds elapsed.\n",TIMEOUT);
        return 0;
    }

    if (fds[0].revents & POLLIN){
        printf("stdin is readable\n");
    }

    if (fds[1].revents & POLLOUT){
        printf("stdout is readable\n");
    }

    return 0;
}