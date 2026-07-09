#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100];
    int i, j = 0;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter key: ");
    scanf("%s", key);

    printf("Ciphertext: ");

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char p = toupper(text[i]);
            char k = toupper(key[j % strlen(key)]);
            char c = ((p - 'A') + (k - 'A')) % 26 + 'A';
            printf("%c", c);
            j++;
        } else {
            printf("%c", text[i]);
        }
    }

    return 0;
}
