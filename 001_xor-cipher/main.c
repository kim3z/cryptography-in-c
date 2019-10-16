
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Author: Kim Lehtinen <kimlehtinenwork@gmail.com>
 * 
 * Program description: XOR cipher encryption and decryption
 */

int main()
{
    char * message = "CIPHER";
    char key = 'A';

    printf("%s", "MESSAGE: ");
    printf("%s\n", message);

    printf("%s", "KEY: ");
    printf("%c\n", key);

    int messageLen = strlen(message);
    int i;

    printf("%s", "ENCRYPTED REPRESENTED IN DECIMALS: ");
    char encrypted[messageLen];

    for (i = 0; i < messageLen; i++) {
        encrypted[i] = message[i]^key;

        printf("%d\t", (int)encrypted[i]);
    }
    printf("\n");
    
    encrypted[messageLen] = '\0';

    char decrypted[messageLen];

    for (i = 0; i < messageLen; i++) {
        decrypted[i] = encrypted[i]^key;
    }

    decrypted[messageLen] = '\0';

    printf("%s", "DECRYPTED: ");
    printf("%s\n", decrypted);

    return 0;
}
