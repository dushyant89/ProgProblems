#include<stdio.h>
#include<conio.h>
#include<math.h>

//Globals
int listsize=0;



int returnCyclic(int n)
{
	int r,nCopy,newNum;
	int exp=0;
	int tenthPower=1;
	nCopy=n;
	
	while((nCopy/10)>=1)
	{
		nCopy=nCopy/10;
		exp++;
	}
	
	/*while(exp >0)
	{
		tenthPower=tenthPower*10;
		exp--;
	}*/
	
	
	
	newNum=((n%10)*tenthPower)+n/10;
	
	return newNum;
	
}

bool checkPrime(int n)
{
	int check=2;
	
	while(check <=n/2)
	{
		if(n%check==0)
		{
			
		  break;
		}
		check++;
		
	}
	if(check > (n/2))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

int main ()

{
	
int limit=1000000;
int cyclicN=0;

int nCopy=0;
	
 for(int n=3;n<=limit;n++)
 {	
	
	if(n%2==0)continue;

	
	if(checkPrime(n))
	{
	 int rotationalLimit=0;
	 
	 nCopy=n;
	 
	 while((nCopy/10)>=1)
  	  {
		nCopy=nCopy/10;
		rotationalLimit++;
	  }
	  
	  nCopy=n;	
	  
	  while(rotationalLimit>0)
	  {
	  	cyclicN=returnCyclic(nCopy);
	  	
		if(checkPrime(cyclicN))
	  	{
	  		rotationalLimit--;
	  	}
	  	else
	  	{
	  		break;
	  	}
	  	nCopy=cyclicN;
	  }
	  
	  if(rotationalLimit==0)
	  {
	  	listsize++;
	  	printf("%d.%d\n",listsize,n);
	  }
		
	} 
 }

	
return listsize;
		
}
