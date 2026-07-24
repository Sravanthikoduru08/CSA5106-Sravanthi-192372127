#include <stdio.h>
#include <string.h>

int modInverse(int a)
{
    int i;
    for(i=1;i<26;i++)
    {
        if((a*i)%26==1)
            return i;
    }
    return -1;
}

int main()
{
    char cipher[100];
    int a,b,i;

    printf("Enter Cipher Text (Uppercase): ");
    scanf("%s", cipher);

    printf("\nPossible Plaintexts:\n\n");

    for(a=1;a<26;a++)
    {
        int inv = modInverse(a);

        if(inv==-1)
            continue;

        for(b=0;b<26;b++)
        {
            printf("a=%2d  b=%2d : ",a,b);

            for(i=0; cipher[i]!='\0'; i++)
            {
                char ch=cipher[i];

                if(ch>='A' && ch<='Z')
                {
                    int c=ch-'A';
                    int p=inv*(c-b+26);
                    p%=26;
                    printf("%c",p+'A');
                }
            }
            printf("\n");
        }
    }

    return 0;
}