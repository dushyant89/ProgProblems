#include<stdio.h>
#include<conio.h>
#include<math.h>

int main(int argc,char* argv)
{
	
	//code for user input will come here
	
	float inputVector[10]={1,2,3,4,5,3,4,1,9,7};
	
	float weights_1[10]={0.4,0.005,0.025,0.005,0.0025,0.20,0.3,0.01,0.03};
	float weights_2[10]={0.3,0.001,0.035,0.05,0.025,0.28,0.32,0.1,0.003};
	float weight_3[1]  ={0.03};
	
	float x_1=0.0;
	
	int i;float target=1.0;
	
 while(1)
 {	
	//for first level
	for(i=0;i<10;i++)
	{		
		x_1+=inputVector[i]*weights_1[i];		
	}
	
	float f_1=1/(1+pow(2.71828,-x1));

	
	float x_2=0.0;
	
	//for first level second node
	for(i=0;i<10;i++)
	{		
		x_2+=inputVector[i]*weights_2[i];		
	}
	
	float f_2=1/(1+pow(2.71828,-x_2));
	
	//for second level	
    float f_3= o_1*weight_3[0] + o_2*weight_3[0];	
    float e_3= target-f_3;
    
    
    float e_1=weight_3[0]*e_3;
    float e_2=e_1;
    
    for(i=0;i<10;i++)
    {
    	weights_1[i]=e_1*f_1 + weights_1[i];
    }
    
    for(i=0;i<10;i++)
    {
    	weights_2[i]=e_2*f_2 + weights_2[i];
    }
    
	
 } 
	
	return 1;
}
