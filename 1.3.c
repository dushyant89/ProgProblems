#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int keys[128];

int main()
{
    printf("Enter both the strings\n");

    char string_1[100];
    char string_2[100];

    scanf("%s\n",string_1);
    scanf("%s",string_2);
    int i;
    if(strlen(string_1)==strlen(string_2))
    {
        for(i=0;i<strlen(string_1);i++)
        {
            keys[string_1[i]]++;
            keys[string_2[i]]--;
        }

        for(i=0;i<128;i++)
        {
            if(keys[i] >0)
            {
                printf("string 2 is not a permutation of string 1");
                break;
            }
        }

        if(i==128)
        {
            printf("string 2 is a permutation of string 1");
        }
    }
    else
    {
        printf("string 2 is not a permutation of string 1");
    }

    return 1;
}
