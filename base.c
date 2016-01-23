//
// Created by abondar on 21.01.16.
//

#include <stdio.h>
#include "base.h"

#define LOWER 0
#define UPPER 300
#define STEP 20


int main() {

    printf("hello world\n");


    farCel();
    int a = bitCount(6);
    printf("Number of 1-bits in 6 is: %2d\n", a);

    int arr1[10];
    int n=0;

    for (int i = 0; i < 10; i++) {
        arr1[i] = n;
        n++;
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
};

