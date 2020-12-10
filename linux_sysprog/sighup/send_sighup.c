//
// Created by abondar on 2/16/17.
//

#define PID 5261

#include <sys/types.h>
#include <signal.h>


int main(void){

    int ret;

    /*check permission*/
    ret = kill(PID,0);
    if (ret){
        perror("kill");
    } else {
        ret = kill(PID,SIGHUP);
        if (ret){
            perror("kill");
        }
    }

    return 0;
}
