#include<stdio.h>
#include<stdlib.h>

void reverse(char *str)
{
    int length=0;
    while(str[length]!='\0')
    {
        length++;
    }
    int low=0;
    int high=length-1;
    while(low < high)
    {
        char temp= str[low];
        str[low]=str[high];
        str[high]=temp;

        low++;
        high--;
    }
}

int main()
{
    char input[100];
    printf("Enter a string to be reversed\n");

    scanf("%s",input);
    reverse(input);

    printf("reversed string is : %s",input);

    return 1;
}
