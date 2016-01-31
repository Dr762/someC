//
// Created by abondar on 28.01.16.
//

#ifndef SOMEC_LINESORT_H
#define SOMEC_LINESORT_H
int readLines(char *lineptr[],int nLines);
void writeLines(char *lineptr[],int nLines);
void qSort(char *lineptr[],int left,int right);
int getLine(char *,int);
void swap(char* v[],int i,int j);
char *alloc(int );
#endif //SOMEC_LINESORT_H
