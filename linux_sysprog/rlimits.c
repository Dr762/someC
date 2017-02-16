//
// Created by abondar on 2/16/17.
//

#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main(void) {
    struct rlimit rlim;
    int rlm;

    rlm = getrlimit(RLIMIT_CORE, &rlim);
    if (rlm == -1) {
        perror("getrlimit");
        return 1;
    }

    printf("RLIMIT_CORE limits: soft=%ld hard=%ld\n", rlim.rlim_cur, rlim.rlim_max);

    rlim.rlim_cur = 32 * 1024 * 1024; /*32 mb*/
    rlim.rlim_max = RLIM_INFINITY; /*actually we do not change it*/

    rlm = setrlimit(RLIMIT_CORE,&rlim);
    if (rlm == -1){
        perror("setrlimit");
        return 1;
    }

    printf("New RLIMIT_CORE limits: soft=%ld hard=%ld\n", rlim.rlim_cur, rlim.rlim_max);
}