#include <stdio.h>
#include <stdlib.h>

void merge(int *a,int low,int mid,int high)
{
    int i=0;
    int *aux= (int *)calloc((high-low)+1,sizeof(int));

    int k=low;
    int r=mid+1;
    while(k<=mid && r<=high)
    {
        if(a[k]<= a[r])
            aux[i++]=a[k++];
        else
            aux[i++]=a[r++];
    }
    if(k>mid)
    {
        while(r<=high)
            aux[i++]=a[r++];
    }
    else if(r>high)
    {
        while(k<=mid)
            aux[i++]=a[k++];
    }

    //now copying the values from aux array to a
    for(i=0;i<=(high-low);i++)
    {
        a[low+i]=aux[i];
        printf("%d ",aux[i]);
    }
    printf("\n");
    free(aux);
}

void mergeSort(int *a, int low,int high)
{
    int mid=(low+high)/2;
    if(low < high)
    {
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main()
{
    printf("Enter the no. of values\n");
    int n;
    scanf("%d",&n);
    int *a=(int *)calloc(n,sizeof(int));

    printf("Enter the values to be sorted\n");

    int index;

    for(index=0;index<n;index++)
    {
        scanf("%d",&a[index]);
    }
    mergeSort(a, 0,n-1);
    return 1;
}
