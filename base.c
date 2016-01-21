//
// Created by abondar on 21.01.16.
//

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

#define IN 1 //inside a word
#define OUT 0 //outside a word

void farCel();
void bigInputCounter();

int main() {

    printf("hello world\n");


    farCel();
    bigInputCounter();

    return 0;
}

//print farenheit-celc
void farCel() {
    float cels = 0;

    printf("Farenheit-Celsius table\n");
    for (float fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        cels = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, cels);

    }

}


void bigInputCounter() {

    int c, nw, nc, nl, state,i,nwhite;

    int ndigit[10];

    nwhite  = nc = nw = 0;
    state = OUT;
    nl=1;
    for (i=0;i<10;i++){
    ndigit[i] =0;
    }

    while ((c = getchar()) != EOF) {
        nc++;
        if (c == '\n') {
            nl++;
        }
        if (c>='0' && c<='9'){
            ndigit[c-'0']++;
        }

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            nwhite ++;

        } else if (state == OUT) {
            state = IN;
            nw++;

        }

    }
   //quite wierd that in console it shows after ctrl-d but in cLion not
    //digits - shows the number of occurence of each digit
    printf("digits =");
    for ( i = 0; i <10 ; ++i) {
        printf(" %d",ndigit[i]);

    }

    printf(",white space = %d\n",nwhite);
    printf("Number of lines %d Number of words %d Number of chars %d\n",nl,nw,nc);

}