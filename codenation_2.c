#include<stdio.h>
#include<string.h>

char* swap(char *input,int i,int j){
    char c=input[i];
    input[i]=input[j];
    input[j]=c;

    return input;
}

int findCost(char *input_1,char *input_2,int j) {

    int cost=10000;
    printf("%s %s\n",input_1,input_2);
    int len=strlen(input_1);

    if(strcmp(input_1,input_2)==0){
        return 0;
    }
    if(strcmp(swap(input_1,0,len-1),input_2)==0){
               input_1=swap(input_1,0,len-1);
            return 1;
    }
    else {
        input_1=swap(input_1,0,len-1);
    }
    if(j==len-1) {
        return 0;
    }

    int i;
    int temp=0;
    for(i=j;i<len-1;i++) {
        temp=1+findCost(swap(input_1,i,i+1),input_2,j+1);
         cost=(temp <cost) ? temp :cost;
         temp=0;
         input_1=swap(input_1,i,i+1); //this is the backtracking step
    }

    return cost;
}

int main()
{
   char input_1[10];
   char input_2[10];
   printf("Enter the two input strings\n");
   while(1) {
        scanf("%s",input_1);
        scanf("%s",input_2);

        printf("Minimum no. of movements are: %d\n",findCost(input_1,input_2,0));
   }
   return 0;
}
