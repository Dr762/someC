//
// Created by abondar on 2/16/17.
//

#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
#include <stdio.h>
#include <sys/stat.h>

int main(void){
    struct  group *gr;
    int ret;

    gr = getgrnam("ss1");
    if (!gr){
        perror("getgrnam");
        return 1;
    }

    ret = chmod("salo.txt",gr->gr_gid);
    if (ret){
        perror("chmod");
    }



}