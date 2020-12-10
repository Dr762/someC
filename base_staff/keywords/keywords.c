//
// Created by abondar on 02.02.16.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keyTab/sizeof(struct key))
#define BUFSIZE 1000

char buf[BUFSIZE];
int bufp = 0;


struct key *binSearch(char *, struct key *, int);
int getWord(char *, int);
int getch(void);
void ungetch(int);

struct key {
    char *word;
    int count;

} keyTab[]={
    "auto",0,
    "break",0,
    "case",0,
    "char",0,
    "const",0,
    "continue",0,
    "static",0,
    "void",0



};

//keywords counter
int main() {
    char word[MAXWORD];
    struct key *p;


    while (getWord(word, MAXWORD) != EOF) {

        if (isalpha(word[0])) {
            if ((p = binSearch(word, keyTab, NKEYS)) != NULL) {
                p->count++;

            }
        }
    }

    for (p = keyTab; p < keyTab + NKEYS; p++) {
        if (p->count > 0) {
            printf("%4d %s\n", p->count, p->word);
        }
    }

    return 0;
}

//find word in tabs
struct key *binSearch(char *word, struct key *tab, int n) {
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high) {
        mid = low + (high - low) / 2;

        if ((cond = strcmp(word, mid->word)) < 0) {
            high = mid;

        } else if (cond > 0) {
            low = mid + 1;

        } else {

            return mid;
        }
    }
    return NULL;
}

int getWord(char *word, int lim) {
    int c;

    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF) {
        *w++ = c;
    }

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for ( ; --lim > 0;w++) {
        if (!isalnum(*w = getch())) {

            ungetch(*w);
            break;
        }

    }
    *w = '\0';

    return word[0];
}

int getch(void) {

    return (bufp > 0) ? buf[--bufp] : getchar();

}

void ungetch(int c) {

    if (bufp >= BUFSIZE)

        printf("ungetch: too many characters\n");

    else

        buf[bufp++] = c;

}
