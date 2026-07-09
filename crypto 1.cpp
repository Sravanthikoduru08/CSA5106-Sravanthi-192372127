#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    int k, i;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter shift value (1-25): ");
    scanf("%d", &k);

    if (k < 1 || k > 25) {
        printf("Invalid shift value! Enter a value between 1 and 25.\n");
        return 1;
    }

    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isupper(ch)) {
            text[i] = ((ch - 'A' + k) % 26) + 'A';
        }
        else if (islower(ch)) {
            text[i] = ((ch - 'a' + k) % 26) + 'a';
        }
    }

    printf("Encrypted message: %s\n", text);

    return 0;
}
