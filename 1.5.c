#include<string.h>
#include<stdio.h>
#include<stdlib.h>

// runs in O(n) time
int main()
{
    char input[100];

    printf("Please enter the string to be compressed\n");
    scanf("%s",input);

    char *compressed = (char *)calloc(strlen(input),sizeof(char));

    int i;
    int j=0;
    for(i=0;i<strlen(input);i++)
    {
        compressed[j]=input[i];
        int count=1;
        while(input[i]==input[++i])
        {
            count++;
        }

        while(count > 0)
        {
            compressed[++j]=(char)(48 + count%10);
            count=count/10;
        }
        j=j+1;
        compressed[j]='\0';
        if(strlen(compressed) >= strlen(input)) break;
        i=i-1;
    }

    if(i==strlen(input))
    {
        printf("compressed string is : %s\n",compressed);
    }
    else
    {
        printf("compressed string is : %s\n",input);
    }

    return 1;
}
