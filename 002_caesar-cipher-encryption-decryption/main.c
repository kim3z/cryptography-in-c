
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Author: Kim Lehtinen <kim@kimlehtinen.com>
 * 
 * Program description: 
 * This program performs caesar cipher encryption and decryption.
 * User enters plaintext and a key (1-26) that will be used for shifting.
 */

int main()
{
    char plaintext[100];
    int key;

    printf("ENTER PLAINTEXT:\n");
    scanf("%s", plaintext);
    printf("Plain text given: %s\n", plaintext);

    printf("ENTER KEY:\n");
    scanf("%d", &key);
    printf("Key: %d\n", key);

    int i = 0;
    for (i = 0; i < strlen(plaintext); i++) {
        plaintext[i] = (char) ( ( ( (int) plaintext[i] - (int)'A' + abs(key) ) % 26) + (int)'A' );
    }

    printf("ENCRYPTED: %s\n", plaintext);

    int j = 0;
    int temp;

    for (j = 0; j < strlen(plaintext); j++) {
        temp = (int) (plaintext[j] - (int)'A') - abs(key);

        if (temp < 0) {
            plaintext[j] = (char) (temp + 26 + (int)'A');
        } else {
            plaintext[j] = (char) ( ( (temp) % 26 ) + (int)'A');
        }
    }

    printf("DECRYPTED: %s\n", plaintext);
    getchar();
    return 0;
}
