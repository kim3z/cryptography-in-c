#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Author: Kim Lehtinen <kim@kimlehtinen.com>
 * 
 * Program description: 
 * This program performs caesar cipher decryption and tries to crack given ciphertext (plaintext that is encrypted).
 * This works by shifting keys 1-26, it will print all candidate solutions.
 */

int main()
{
    char plaintext[100];

    printf("ENTER CIPHERTEXT:\n");
    scanf("%s", plaintext);
    printf("Ciphertext given: %s\n", plaintext);

    int i;

    for (i = 1; i < 26; i++) {
        int key = i;
        int j;
        int temp;

        char pTextCopy[strlen(plaintext)];
        strncpy(pTextCopy, plaintext, strlen(plaintext));

        for (j = 0; j < strlen(pTextCopy); j++) {
            temp = (int) (pTextCopy[j] - (int)'A') - abs(key);

            if (temp < 0) {
                pTextCopy[j] = (char) (temp + 26 + (int)'A');
            } else {
                pTextCopy[j] = (char) ( ( (temp) % 26 ) + (int)'A');
            }
        }

        printf("CANDIDATE: %s\n", pTextCopy);
    }
    getchar();
    return 0;
}
