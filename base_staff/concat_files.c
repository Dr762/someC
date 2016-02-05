//
// Created by abondar on 05.02.16.
//

#include <stdio.h>
#include <stdlib.h>

//file contaer
int main(int argc,char *argv[]){

    FILE *fp;
    void fileCopy(FILE*,FILE*);
    char *prog=argv[0]; //name for errors
    if (argc==1){
        fileCopy(stdin,stdout);
    } else {
        while (--argc>0){
            if ((fp=fopen(*++argv,"r"))==NULL){
                fprintf(stderr,"%s: cat:can't open %s\n",prog,*argv);
                exit(1);
            } else{
               fileCopy(fp,stdout);
                fclose(fp);
            }
        }

    }
    if(ferror(stdout)){
        fprintf(stderr,"%s: error writing stdout\n",prog);
        exit(2);
    }
}


void fileCopy(FILE *ifp,FILE *ofp){
    int c;
    while ((c=getc(ifp))!=EOF){
        putc(c,ofp);
    }
}
