//
// Created by abondar on 2/16/17.
//

#include <unistd.h>
#include <stdio.h>
#include <sched.h>
#include <memory.h>

int main(void) {

    pid_t pid;
    struct sched_param sp;
    int policy, max, pr;

    pid = getpid();
    if (pid == -1) {
        perror("getpid");
    }


    policy = sched_getscheduler(pid);
    if (policy==-1){
        return -1;
    }

    max = sched_get_priority_max(policy);
    if (max == -1){
        return 1;
    }

    memset(&sp,0, sizeof(struct sched_param));
    sp.sched_priority = max;
    pr= sched_setparam(pid,&sp);

    printf("New priority %d\n",pr);

    return 0;
}