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

    int arr1[10];
    int n = 10;

    printf("Unsorted array ");
    for (int i = 0; i < 10; i++) {
        arr1[i] = n;
        n--;
        printf("%2d", arr1[i]);
    }
    printf("\n");

    shellSort(arr1, 10);
    n = 10;
    for (int i = 0; i < 10; i++) {
        arr1[i] = n;
        n--;
    }

    qSort(arr1, 0, 9);

    int day_of_year = dayOfYear(2016, 02, 01);
    printf("Febraury 1 is %2d day of year\n", day_of_year);


    char *month = month_name(11);
    printf("%s\n", month);

    echo(argc, argv);


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

void shellSort(int v[], int n) {
    int gap, i, j;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
                swap(v, j, j + gap);

            }
        }
    }
    printf("Shell sorted array ");
    for (i = 0; i < 10; i++) {
        printf("%3d", v[i]);
    }
    printf("\n");

}

void qSort(int v[], int left, int right) {
    int i, last;


    if (left >= right) { //do nothing if arrays has<2 elems
        return;
    }

    int subdiv = (left + right) / 2;
    swap(v, left, subdiv);
    last = left;// move partition to v[0]

    for (i = left + 1; i <= right; i++) { //partition
        if (v[i] < v[left]) {

            swap(v, ++last, i);
        }
    }
    swap(v, left, last); //restore partition
    qSort(v, left, last - 1);
    qSort(v, last + 1, right);


    printf("Q sorted array ");
    for (i = 0; i < 10; i++) {
        printf("%3d", v[i]);
    }
    printf("\n");

}

void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;

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