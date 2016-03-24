/*
Credits : Dushyant Sabharwal
          IIT Bombay
*/

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

using namespace std;
char *data[5470][16];
int main(int argc, char** argv)
{
	
	if(argc < 2)
	{
		fprintf(stderr,"Please enter the filepath\n");
		exit(0);
	}
	else
	{
		fstream file;
		file.open(argv[1],ios::in);
	
		
		if(!file.is_open())
		{
			fprintf(stderr,"Failed to open input file\n");
			exit(0);
		}
		else
		{
			
			char cell[16];
			int col=0,row=0;
			while(!file.eof())
			{
				string str;
				getline(file,str);
				int i=0,cellCount=0;
			  	
				while(i<=str.length())
				{
				 
				 if(str[i]==',')
				   {
					   //cout<<str[i]<<"->";
					   cell[cellCount]='\0';
					   cellCount=0;
					   i++;
					   
				   }	
		         else 
				   {
					cell[cellCount++]=str[i++];
				  	continue;
				   }
				   data[row][col++]=cell; 
				   cout<<cell<<endl;
				   										
				}
				row++;
				col=0;
			
		      }
		
	}
	
	cout<<"Displaying the data"<<endl;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<16;j++)
		{
		  	
			cout<<data[i][j]<<" ";
		}
		cout<<endl;
	}
  }
     return 1; 
}
