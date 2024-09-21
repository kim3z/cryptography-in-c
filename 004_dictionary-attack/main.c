#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Author: Kim Lehtinen <kim@kimlehtinen.com>
 * 
 * Program description: 
 * This program performs caesar cipher decryption and tries to crack given ciphertext (plaintext that is encrypted).
 * This works by shifting keys 1-26, it will print all candidate solutions.
 * For each candidate solution we check if any word from our dictionary exists,
 * and print what we guess they've written.
 * 
 * Example:
 * Give as input cipher text IDSPN and it should print out TODAY even if we don't know which key they used.
 */

int main()
{
    const char *dictionary[] = {"HELLO","TODAY", "SCHOOL", "SUMMER", "SUN", "HOUSE"}; // our dictionary database
    char plaintext[100];
    char crackedText[100] = "";

    printf("ENTER CIPHERTEXT:\n");
    scanf("%[^\t\n]", plaintext);
    printf("\nCIPHER TEXT GIVEN: %s\n\n", plaintext);

    int i;

    // try every possible key
    for (i = 1; i < 26; i++) {
        int key = i;
        int j;
        int temp;

        char pTextCopy[strlen(plaintext)];
        strncpy(pTextCopy, plaintext, strlen(plaintext));

        // decrypt characters for candidate solution
        for (j = 0; j < strlen(pTextCopy); j++) {
            if (pTextCopy[j] != ' ') {
                temp = (int) (pTextCopy[j] - (int)'A') - abs(key);

                if (temp < 0) {
                    pTextCopy[j] = (char) (temp + 26 + (int)'A');
                } else {
                    pTextCopy[j] = (char) ( ( (temp) % 26 ) + (int)'A');
                }
            }
        }

        printf("CANDIDATE: %s\n", pTextCopy);

        // check if any word in our dictionary database exists in this candidate solution
        int d;
        for (d = 0; d < sizeof(dictionary) / sizeof(dictionary[0]); d++) {
            char *s;
            s = strstr(pTextCopy, dictionary[d]);
            if (s != NULL) {
                // store found word for displaying it in the end
                strcat(crackedText, (char *) dictionary[d]);
                strcat(crackedText, " ");
            }
        }

    }

    printf("\nCRACKED TEXT: %s\n", crackedText);
    getchar();
    return 0;
}
