#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char plaintext[1000];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // Substitution key
    int i;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        if (isupper(ch)) {
            plaintext[i] = key[ch - 'A'];
        }
        else if (islower(ch)) {
            plaintext[i] = tolower(key[ch - 'a']);
        }
    }

    printf("Ciphertext: %s", plaintext);

    return 0;
}
