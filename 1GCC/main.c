#include <stdio.h>
#include <string.h>
#include <math.h>
#include "md5.h"

int main() {
    unsigned char check[16] = {0};
    scanf("%x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x", &check[0], &check[1], &check[2], &check[3], &check[4], &check[5], &check[6], &check[7], &check[8], &check[9], &check[10], &check[11], &check[12], &check[13], &check[14], &check[15]);
    fflush(stdin);

    char* alphabet = "abcdefghijklmnopqrstuvwxyz";

    unsigned int pSize = 3;
    int pIndex[3] = {0};
    char pText[3] = {0};

    while (pIndex[0] != 26) {

        //creer le brutforce
        for (int i = 0; i < pSize; i++) {
            pText[i] = alphabet[pIndex[i]];
        }
        printf("%s\n", pText);

        //hash le brutforce
        unsigned char digest[16] = {0};
        md5((unsigned char *)pText, pSize, digest);


        //compare les hashes
        if (!strncmp((const char *) digest, (const char *) check, 16)) {
            printf("%s ==> password found\n", pText);
            break;
        }

        //increment la derniere lettre
        pIndex[pSize - 1] = pIndex[pSize - 1] + 1;
        for (int j = pSize - 1; j > 0; j--) {
            if (pIndex[j] == 26) {
                pIndex[j] = 0;
                pIndex[j - 1] = pIndex[j - 1] + 1;
            }
        }
    }

    return 0;
}
//60 57 f1 3c 49 6e cf 7f d7 77 ce b9 e7 9a e2 85
//de 9c 3c ba c5 e2 2a 64 b3 74 67 08 83 7d dd 16