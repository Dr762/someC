//
// Created by abondar on 08.03.16.
//
#include <stdio.h>
#include "encrypt.h"

int main() {

    unsigned char *plain;
    unsigned char *cipher;
    unsigned char *key;

    unsigned char a = 'abcde';
    plain = &a;

    unsigned char b = 'xxxffee';
    cipher = &b;

    unsigned char c = 'xxx';
    key = &c;

    //use either enc or dec at once
    des_encipher(plain, cipher, key);
    printf("Encrypted by DES\n");


    //  des_decipher(cipher,plain,key);
    //  printf("Decrypted by DES\n");

    Huge rsaPlain = 21321321;
    Huge rsaCyph = 2222222;
    Huge *rsp = &rsaCyph;

    RsaPubKey rsaPubKey;
    rsaPubKey.e = 4543543543;
    rsaPubKey.n= 32432432432432;

    rsa_encipher(rsaPlain, rsp,rsaPubKey);
    printf("Encrypted by RSA\n");

    RsaPriKey rsaPriKey;
    rsaPriKey.n=23324324324;
    rsaPriKey.d=213213213;
    rsa_decipher(rsaPlain, rsp,rsaPriKey);
    printf("Decrypted by RSA\n");

    return 0;
}