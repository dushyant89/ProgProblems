#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *a,int key,int low,int high)
{
    int mid=(low+high)/2;
    if(low<=high)
    {
        if(a[mid]==key)
        {
           return a[mid];
        }
        else if(key>a[mid])
        {
           low=mid+1;
           binarySearch(a,key,low,high);
        }
        else
        {
            high=mid;
            binarySearch(a,key,low,high);
        }
    }
    else
    {
        return 0;
    }
}
int main()
{
    printf("Enter the no. of values to be prepared\n");
    int n;
    scanf("%d",&n);

    int *a= (int *)calloc(n,sizeof(int));
    printf("Enter the values for the array\n");
    int index=0;
    for(index;index<n;index++)
    {
       scanf("%d",&a[index]);
    }

    printf("Now enter the value you want to search\n");
    int search;
    scanf("%d",&search);
    printf("Found: %d",binarySearch(a,search,0,n-1));

    getch();

    return 1;
}
