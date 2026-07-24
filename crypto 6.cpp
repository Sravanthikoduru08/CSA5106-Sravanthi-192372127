#include <stdio.h>

int main()
{
    printf("Most frequent ciphertext letter : B\n");
    printf("Second frequent ciphertext letter : U\n");

    printf("\nAssume:\n");
    printf("B -> E\n");
    printf("U -> T\n");

    printf("\nTry all valid values of a\n");
    printf("Compute b using:\n");
    printf("C = (aP+b) mod 26\n");
    printf("Then decrypt using modular inverse of a.\n");

    return 0;
}