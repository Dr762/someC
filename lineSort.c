//
// Created by abondar on 27.01.16.
//

#include <stdio.h>
#include <string.h>

#include "lineSort.h"

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000

char *lineptr[MAXLINES];
//pointers to lines
static char allocBuf[ALLOCSIZE]; //alloc storage
static char *allocp = allocBuf; //next free pos to alloc


int main() {

    int nLines = 0; //number of input lines

    if ((nLines = readLines(lineptr, MAXLINES)) >= 0) {

        qSort(lineptr, 0, nLines - 1);
        printf("After sort\n");
        writeLines(lineptr, nLines);
        return 0;
    } else {
        printf("error: input too big\n");
        return 1;
    }
}

int readLines(char *lineptr[], int maxlines) {
    int len, nLines = 0;
    char *p, line[MAXLEN];

    while ((len = getLine(line, MAXLEN)) > 0) {
        if (nLines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0'; //delete new line
            strcpy(p, line);
            lineptr[nLines++] = p;
        }

    }
    return nLines;
}

void writeLines(char *lineptr[], int nLines) {

    while (nLines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}

int getLine(char *s, int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i;

}

void qSort(char *v[], int left, int right) {
    int i, last;


    if (left >= right) { //do nothing if arrays has<2 elems
        return;
    }

    int subdiv = (left + right) / 2;
    swap(v, left, subdiv);
    last = left;// move partition to v[0]

    for (i = left + 1; i <= right; i++) { //partition
        if (strcmp(v[i], v[left]) < 0) {

            swap(v, ++last, i);
        }
    }
    swap(v, left, last); //restore partition
    qSort(v, left, last - 1);
    qSort(v, last + 1, right);


}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;

}

char *alloc(int n) {
    if (allocBuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}