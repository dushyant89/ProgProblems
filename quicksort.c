#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//implementing quick sort for characters
char str[100] = {'d','u','s','h','y','a','n','d','t','\0'};

int partition(int low,int high);

void quicksort(int low, int high)
{
    if(low < high)
    {
        int p= partition(low,high);
        quicksort(low,p-1);
        quicksort(p+1,high);
    }
}

int partition(int low,int high)
{
    int pivot = low;
    int left=low;
    int right=high;
    char temp;

    while(left < right)
    {
        while(str[pivot] >= str[left])
            left++;

        while(str[right] > str[pivot])
            right--;

        if(right > left)
        {
            temp= str[right];
            str[right]=str[left];
            str[left]=temp;
        }
    }

    temp=str[right];
    str[right]=str[pivot];
    str[pivot]=temp;

    printf("%s\n",str);

    return right;
}
int main()
{
    quicksort(0,(strlen(str)-1));

    int index=0;
    while(str[index]!='\0')
    {
        if(str[index]==str[index+1]) break;

        index++;
    }

    if(index == strlen(str)) printf("string is unique");
    else printf("contains duplicate");

    return 1;
}
