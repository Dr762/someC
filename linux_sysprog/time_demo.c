//
// Created by abondar on 2/17/17.
//


#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

#include "time_demo.h"


//compile with lrt to run timer
int main(void) {

    time_resoulutions();
    get_cur_time();
    sleep_demo();
    sleep_advanced();
    interval_timer();
    create_cpu_timer();
    create_realtime_timer();


    return 0;
}

void time_resoulutions(void) {
    clockid_t clocks[] = {
            CLOCK_REALTIME,
            CLOCK_MONOTONIC,
            CLOCK_PROCESS_CPUTIME_ID,
            CLOCK_THREAD_CPUTIME_ID,
            (clockid_t) -1};

    int i;

    for (i = 0; clocks[i] != (clockid_t) -1; i++) {
        struct timespec ts;
        int ret;

        ret = clock_gettime(clocks[i], &ts);
        if (ret) {
            perror("clock_getres");
        } else {
            printf("clock=%d sec=%ld nsec=%ld\n",
                   clocks[i], ts.tv_sec, ts.tv_nsec);
        }
    }

}

void get_cur_time(void) {
    struct timeval tv;
    int ret;

    ret = gettimeofday(&tv, NULL);
    if (ret) {
        perror("gettimeofday");
    } else {
        printf("seconds=%ld useconds=%ld\n",
               (long) tv.tv_sec, (long) tv.tv_usec);
    }
}

void sleep_demo(void) {
    struct timespec req = {.tv_sec =0,
            .tv_nsec =200};

    struct timespec rem, *a = &req, *b = &rem;

    while (nanosleep(a, b) && errno == EINTR) {
        struct timespec *tmp = a;
        a = b;
        b = tmp;
    }

}

void sleep_advanced(void) {
    int ret;

    struct timespec req = {.tv_sec =0,
            .tv_nsec =200};

    struct timespec rem;

    ret = clock_nanosleep(CLOCK_REALTIME, 0, &req, &rem);
    if (ret) {
        perror("clock_nanosleep");
    }
}


void alarm_handler(int signum) {
    printf("Timer hit!\n");
}


void interval_timer(void) {
    struct itimerval delay;
    int ret;

    signal(SIGALRM, alarm_handler);

    delay.it_value.tv_sec = 5;
    delay.it_value.tv_usec = 0;
    delay.it_interval.tv_sec = 1;
    delay.it_interval.tv_usec = 0;

    ret = setitimer(ITIMER_REAL, &delay, NULL);
    if (ret) {
        perror("settimer");
        return;
    }

    pause();

}

void create_cpu_timer(void) {
    timer_t timer;
    int ret;

    ret = timer_create(CLOCK_PROCESS_CPUTIME_ID, NULL, &timer);
    if (ret) {
        perror("timer_create");
    }

    ret = timer_delete(timer);
    if (ret){
        perror("timer_delete");
    }
}

//sends SIGUSR1 on expire
void create_realtime_timer(void) {
    struct sigevent evp;
    timer_t timer;
    int ret;

    evp.sigev_value.sival_ptr = &timer;
    evp.sigev_notify = SIGEV_SIGNAL;
    evp.sigev_signo = SIGUSR1;

    ret = timer_create(CLOCK_REALTIME, &evp, &timer);
    if (ret) {
        perror("timer_create");
    }


}
