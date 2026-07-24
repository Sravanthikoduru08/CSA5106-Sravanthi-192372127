#include <stdio.h>
#include <ctype.h>

char plain[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char cipher[]="CIPHERABDFGJKLMNOQSTUVWXYZ";

int main()
{
    char text[100];
    int i,j;

    printf("Enter plaintext: ");
    scanf("%s",text);

    printf("Ciphertext: ");

    for(i=0;text[i]!='\0';i++)
    {
        char ch=toupper(text[i]);

        for(j=0;j<26;j++)
        {
            if(ch==plain[j])
            {
                printf("%c",cipher[j]);
                break;
            }
        }
    }

    return 0;
}