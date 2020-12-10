//
// Created by abondar on 23.01.16.
//
#include <stdio.h>
int main() {

    int c, nw, nc, nl, i, nwhite;

    int ndigit[10];

    nl = nwhite = nc = nw = 0;

    for (i = 0; i < 10; i++) {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        nc++;
        switch (c) {
            case '\n':
                nl++;
                nwhite++;
                nw++;
                break;

            case '\t':
            case ' ':
                nwhite++;
                nw++;
                break;

            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                ndigit[c - '0']++;
                break;

            default:
                nc++;
                break;
        }


    }
    //quite wierd that in console it shows after ctrl-d but in cLion not
    //digits - shows the number of occurence of each digit
    printf("digits =");
    for (i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]);

    }

    printf(",white space = %d\n", nwhite);
    printf("Number of lines %d Number of words %d Number of chars %d\n", nl, nw, nc);

    return 0;
}
