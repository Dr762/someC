//
// Created by abondar on 2/17/17.
//

#define PID 5186


#include <signal.h>


int main(void) {
    union   sigval value;
    int ret;

    value.sival_int = 404;

    ret = sigqueue(PID, SIGUSR2, value);
    if (ret) {
        perror("sigqueue");
    }

    return 0;
}