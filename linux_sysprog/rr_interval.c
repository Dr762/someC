//
// Created by abondar on 2/16/17.
//

#include <sched.h>
#include <stdio.h>

int main(void){
    struct  timespec tp;
    int interval;

    interval = sched_rr_get_interval(0,&tp);
    if (interval ==-1){
        perror("sched_rr_get_interval");
        return 1;
    }

    printf("Our time quantum is %.2lf milliseconds\n",
           (tp.tv_sec * 1000.0f) + (tp.tv_nsec / 1000000.0f));

}