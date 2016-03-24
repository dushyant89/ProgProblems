#include<stdio.h>
#include <conio.h>

int k[12],l[12],m[12];


void merge(int *a,int low,int mid,int high)
{
	int i;

	
	for(i=low;i<=mid;i++)
	{
		l[i]=a[i];
				
	}
	
	int n=0;
	
	for(i=mid+1;i<=high;i++)
	{
		m[n]=a[i];
		//printf("%d",m[n]);		
		n++;
	}
	//printf("\n");
	
	int j=0;
	n=0;
	
	for(i=low;j<=mid&&n<=(high-mid);i++)
	{
		if(l[j] <= m[n])
		{
		
			
			k[i]=l[j];
			j++;
		}
		else
		{
			k[i]=m[n];
			n++;
		}
	}
	
    if(j < mid || (j==0 && j==mid))
    {
    	while(j<=mid)
    	{
    		k[i]=l[j];
			i++;
    		j++;
			
    		
    	}
    }

    if(n < (high-mid) || (n==0 && n==(high-mid)))
    {
    	
		while(n<=(high-mid))
    	{
    		
			k[i]=m[n];
			i++;
    		n++;
			
    		
    	}
    }
	
	
}

void mergesort(int *a,int low,int high)
{
	int mid;
	if(low < high)
	{
		
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
		
	}
	
}

int main()
{
	
  int a[]={4,3,2,1};	
  mergesort(a,0,3);
  
  printf("\nPrinting numbers: ");
  for(int i=0;i<=3;i++)
  {
  	printf("%d ",k[i]);
  }
  return 1;
}
