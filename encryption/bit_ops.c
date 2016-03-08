//
// Created by abondar on 07.03.16.
//

#include <stdio.h>
#include "bit_ops.h"


int bit_get(const unsigned char *bits,int pos){

    unsigned char mask;

    int i;

    //set a mask for bit to get
    mask = 0x80;

    for (i=0;i<(pos % 8);i++){
        mask = mask>>1;
    }

    return (((mask & bits[(int)(pos/8)])==mask) ? 1: 0);
};

void bit_set(unsigned char *bits,int pos,int state){
    unsigned char mask;

    int i;

    //set a mask for bit to get
    mask = 0x80;

    for (i=0;i<(pos % 8);i++){
        mask = mask>>1;
    }
    //set a bit
    if (state)
        bits[pos/8]=bits[pos /8] | mask;
    else
        bits[pos/8]=bits[pos /8] & (~mask);
    return;
};

void bit_xor(const unsigned char *bits1, const unsigned char *bits2, unsigned char *bitsx, int size){

    int i;

    for (i=0;i<size;i++){
        if (bit_get(bits1,i)!=bit_get(bits2,i))
            bit_set(bitsx,i,1);
        else
            bit_set(bitsx,i,0);
    }


    return;
};

void bit_rot_left(unsigned char *bits, int size, int count){

    int fbit,lbit,i,j;

    //rotate to left
    if (size>0){
        for (i=0;i<=((size-1)/8);i++){
            //get a bit to be shiffted of the current byte
            lbit = bit_get(&bits[i],0);
            if (i==0){
                //save the bit shiffted of the first byte
                fbit=lbit;
            } else{
                //set rightmost bit of the previous byte to the leftmost bit
                // about to be shifted off the cur byte
                bit_set(&bits[i-1],7,lbit);
            }
            //shift curr byte to the left
            bits[i]=bits[i]<<1;
        }
        //set rightmost bit of the buffer to the bit
        // to be shifted of the first byte
        bit_set(bits,size-1,fbit);
    }
};