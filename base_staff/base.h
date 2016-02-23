//
// Created by abondar on 23.01.16.
//

#ifndef SOMEC_BASE_H
#define SOMEC_BASE_H

void farCel();

int bitCount(unsigned x);

void shellSort(int v[], int n);

void qSort(int v[], int left, int right);

void swap(int v[], int i, int j);

int dayOfYear(int year, int month, int day);

char *month_name(int n);

void echo(int argc, char *argv[]);

int fact(int n);

int factTail(int n,int a);

#endif //SOMEC_BASE_H
