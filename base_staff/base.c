//
// Created by abondar on 21.01.16.
//

#include <stdio.h>
#include "base.h"


#define LOWER 0
#define UPPER 300
#define STEP 20


int main(int argc, char *argv[]) {

    printf("hello world\n");


    farCel();
    int a = bitCount(6);
    printf("Number of 1-bits in 6 is: %2d\n", a);


    int day_of_year = dayOfYear(2016, 02, 01);
    printf("Febraury 1 is %2d day of year\n", day_of_year);


    char *month = month_name(11);
    printf("%s\n", month);

    echo(argc, argv);

    for (int i=0;i< 10;i++){
        printf("Factorial of %d is %2d\n",i,fact(i));

    }

    for (int i=11;i< 20;i++){
        printf("Factorial of %d is %2d\n",i,factTail(i,1));

    }

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

int bitCount(unsigned x) {
    int b;
    for (b = 0; x != 0; x >>= 1) {
        if (x & 01) {
            b++;
        }
    }
    return b;

}




//set day of year from month and da
int dayOfYear(int year, int month, int day) {
    int i, leap;
    static char dayTab[2][13] = {
            {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    //non-leap number of days
            {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},    //leap number of days

    };
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++) {
        day += dayTab[leap][i];
    }
    return day;

}

char *month_name(int n) {

    static char *name[] = {
            "Bad month", "January", "February", "March",
            "April", "May", "June", "July", "August", "September",
            "October", "November", "December"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}

void echo(int argc, char *argv[]) {

    printf("arguments ");
    while (--argc > 0) {
        printf("%s%s", *++argv,(argc>1)? " ":"");
    }
    printf("\n");


}

int fact(int n){
    if (n<0){
        return 0;
    } else if(n==0){
        return 1;
    } else if(n==1){
        return 1;
    } else {
        return n*fact(n-1);
    }

}

int factTail(int n,int a){
    if (n<0){
        return 0;
    } else if(n==0){
        return 1;
    } else if(n==1){
        return a;
    } else {
        return factTail(n-1,n*a);
    }
}