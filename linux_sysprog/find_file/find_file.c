//
// Created by abondar on 2/16/17.
//
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include "find_file.h"

#define BUF_SIZE 8192

int main(void) {
    const char *path = "/home/abondar/";
    const char *file = "npm-debug.log";

    struct dirent *entry;
    char lines [BUF_SIZE];

    int ret = 1;
    DIR *dir;
    FILE *fl;
    int c;

    dir = opendir(path);

    errno = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, file)) {
            ret = 0;
            break;
        }
    }

    if (errno && !entry) {
        perror("readdir");
    }

    closedir(dir);

    if (ret == 0) {

     char *abs_path = concat(path,file);

        fl = fopen(abs_path, "r");
        if (!fl) {
            perror("fopen");
            return 1;
        }

        if (!fread(&lines, sizeof(lines),1,fl)){
            perror("fread");
            return 1;
        }

        printf("%s\n",lines);

        if (fclose(fl)) {
            perror("fclose");
            return 1;
        }
    }
}

char* concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the zero-terminator
    if (!result){
        return "";
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}