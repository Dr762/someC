//
// Created by abondar on 2/11/17.
//

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <zconf.h>
#include <memory.h>
#include <asm/errno.h>
#include "file_ops.h"

int main(void) {

    openFile("../../LICENSE");
    createFile("salo.txt");
    readFile("../../LICENSE");
    writeFile("salo.txt");
    fileSync("salo.txt");
    fileSeek("../../LICENSE");
    truncateFile("salo.txt",3);

    return 0;
}


void openFile(char *fname) {
    int fd;

    fd = open(fname, O_RDONLY);
    if (fd == -1) {
        printf("Error reading file\n");
    } else {
        printf("File descriptor %p\n", fd);
    }

    if (close(fd)==-1){
        printf("Error closing file\n");
    }
};


void createFile(char *fname){
    int fd;

    fd = creat(fname, 0644);
    if (fd == -1) {
        printf("Error creating file\n");
    } else {
        printf("File descriptor %p\n", fd);
    }
};

void readFile(char *fname){
    unsigned long word;
    ssize_t nr;

    int fd;

    fd = open(fname, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file\n");
        return;
    }


    nr = read(fd,&word,sizeof(unsigned long));

    if (nr == -1) {
        printf("Error reading file\n");
    } else {
        printf("Some bytes %zu\n", nr);
    }

    if (close(fd)==-1){
        printf("Error closing file\n");
    }
};

void writeFile(char *fname){
    const char *buf = "SAAAALOO";
    ssize_t  nr;
    int fd;

    fd = open(fname, O_WRONLY);
    if (fd == -1) {
        printf("Error opening file\n");
        return;
    }


    nr = write(fd,buf,strlen(buf));

    if (nr == -1) {
        printf("Error writing to file\n");
    } else {
        printf("Wrote to file %zu\n", nr);
    }

    if (close(fd)==-1){
        printf("Error closing file\n");
    }
};

void fileSync(char *fname){
    int fd;

    fd = open(fname, O_FSYNC);
    if (fd == -1) {
        printf("Error opening file\n");
    }

    int ret;

    ret = fsync(fd);
    if (ret==-1){
        if (ret==EINVAL){
            if (fdatasync(fd)==-1){
                perror("fdatasyncfailed");
            }
        } else {
            printf("Error synchronizing file\n");
        }
    } else{
        printf("Synced %p\n",ret);
    }
};


void fileSeek(char *fname){
    int fd;
    off_t ret;
    int pos = 217;

    fd = open(fname, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file\n");
        return;
    }

    ret = lseek(fd,(off_t) pos,SEEK_SET);
    if (ret == (off_t) -1){
        printf("Error setting file pos\n");
    } else {
        printf("Set position  %zu\n", ret);
    }



    if (close(fd)==-1){
        printf("Error closing file\n");
    }
};


void truncateFile(char *fname,int newLen){
    int ret;

    ret = truncate(fname,newLen);
    if (ret==-1){
        printf("Error truncating file \n");
    }
};
