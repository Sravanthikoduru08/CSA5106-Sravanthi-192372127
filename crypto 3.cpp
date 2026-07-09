#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void generateMatrix(char key[]) {
    int used[26] = {0};
    int i, j, k = 0;

    used['J' - 'A'] = 1; 

    for (i = 0; key[i] != '\0'; i++) {
        char ch = toupper(key[i]);
        if (ch == 'J')
            ch = 'I';
        if (!used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (!used[i]) {
            matrix[k / 5][k % 5] = i + 'A';
            k++;
        }
    }
}

void findPosition(char ch, int *row, int *col) {
    int i, j;
    if (ch == 'J')
        ch = 'I';

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encrypt(char text[]) {
    int i;
    for (i = 0; text[i] != '\0'; i += 2) {
        int r1, c1, r2, c2;

        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);

        if (r1 == r2) {
            printf("%c%c",
                   matrix[r1][(c1 + 1) % 5],
                   matrix[r2][(c2 + 1) % 5]);
        }
        else if (c1 == c2) {
            printf("%c%c",
                   matrix[(r1 + 1) % 5][c1],
                   matrix[(r2 + 1) % 5][c2]);
        }
        else {
            printf("%c%c",
                   matrix[r1][c2],
                   matrix[r2][c1]);
        }
    }
}

int main() {
    char key[100], text[100];
    int i, len;

    printf("Enter keyword: ");
    scanf("%s", key);

    generateMatrix(key);

    printf("\nPlayfair Matrix:\n");
    for (i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }

    printf("\nEnter plaintext (even number of letters): ");
    scanf("%s", text);

    for (i = 0; text[i]; i++)
        text[i] = toupper(text[i]);

    len = strlen(text);
    if (len % 2 != 0) {
        text[len] = 'X';
        text[len + 1] = '\0';
    }

    printf("Ciphertext: ");
    encrypt(text);

    return 0;
}
