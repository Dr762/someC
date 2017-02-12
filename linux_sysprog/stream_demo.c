//
// Created by abondar on 2/12/17.
//

#include <stdio.h>

int main(void){
    FILE *in, *out;
    struct pirate{
        char name[100];
        unsigned long booty;
        unsigned int beard_len;
    } p, blackbeard={"Edward Tech",950,48};

    out = fopen("salo.txt","w");
    if (!out){
        perror("fopen");
        return 1;
    }

    if (!fwrite(&blackbeard,sizeof(struct pirate),1,out)){
        perror("fwrite");
        return 1;
    }


    if (fclose(out)){
        perror("fclose");
        return 1;
    }

    in = fopen("salo.txt","r");
    if (!in){
        perror("fopen");
        return 1;
    }

    if (!fread(&p, sizeof(struct pirate),1,in)){
        perror("fread");
        return 1;
    }



    if (fclose(in)){
        perror("fclose");
        return 1;
    }

    printf("name=\"%s\" booty=%lu beard_len=%u\n",
    p.name,p.booty,p.beard_len);

}
