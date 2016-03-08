//
// Created by abondar on 07.03.16.
//

#ifndef SOMEC_BIT_OPS_H
#define SOMEC_BIT_OPS_H

//get state of bit in pos
int bit_get(const unsigned char *bits,int pos);

void bit_set(unsigned char *bits,int pos,int state);

void bit_xor(const unsigned char *bits1, const unsigned char *bits2, unsigned char *bitsx, int size);

//rotates bits from buffer to the left count bits.
// res -left count bits are right count bits. other bits are shifted accordingly
void bit_rot_left(unsigned char *bits, int size, int count);
#endif //SOMEC_BIT_OPS_H
