//
// Created by abondar on 2/15/17.
//

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fs.h>


#define NR_OPEN 1
int main(void) {

    pid_t pid;
    int i;

    /*create new process*/
    pid = fork();
    if (pid == -1) {
        return -1;
    } else if (pid != 0) {
        exit(EXIT_SUCCESS);
    }

    /*create new  session and process group*/
    if (setsid() == -1) {
        return -1;
    }

    /*set working directrory to the roor dir*/
    if (chdir("/") == -1) {
        return -1;
    }

    /*close all open files*/
    for (i = 0; i < NR_OPEN; i++) {
        close(i);
    }

    /*redirect fd's to /dev/null */
    open("/dev/null/",O_RDWR);
    dup(0);
    dup(0);

    return 0;

}
