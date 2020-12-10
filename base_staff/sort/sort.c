//
// Created by abondar on 06.03.16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

#include "sort.h"


int main(int argc,char *argv[]){

    int arr1[10];

    if (strcmp(argv[1],"ss")==0){
        refillArray(arr1,10);
        shellSort(arr1, 10);
    }

    if (strcmp(argv[1],"qs")==0){
        refillArray(arr1,10);
        qSort(arr1, 0, 9);
    }

    if (strcmp(argv[1],"cs")==0){
        refillArray(arr1,10);
        countSort(arr1,10,11);
    }

    return 0;
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


void refillArray(int v[],int n){
    printf("Unsorted array ");
    for (int i = 0; i < 10; i++) {
        v[i] = n;
        n--;
        printf("%3d",v[i]);
    }
    printf("\n");
}

//k=maxint +1
int countSort(int *data, int size, int k){
    int *counts,*temp;
    int i,j;

    if ((counts=(int *)malloc(k * sizeof(int)))==NULL)
        return -1;

    //temp - sorted elems
    if ((temp=(int *)malloc(size * sizeof(int)))==NULL){
        free(counts);
        return -1;
    }

    //init counts
    for (i=0;i<k;i++)
        counts[i]=0;

    //count occurence of each element
    for (j=0;j<size;j++)
        counts[data[j]]=counts[data[j]]+1;

    //adjust count to reflect counts before it
    for (i=1;i<k;i++)
        counts[i]=counts[i]+counts[i-1];

    //use counts to pos each elem where it belongs
    for (j=size-1;j>=0;j--){
        temp[counts[data[j]]-1]=data[j];
        counts[data[j]]=counts[data[j]]-1;
    }

    memcpy(data,temp,size *sizeof(int));

    free(counts);
    free(temp);

    printf("Count sort ");
    for (i=0;i<size;i++){
        printf("%3d",data[i]);
    }
    printf("\n");
}

