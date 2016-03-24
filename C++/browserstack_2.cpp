#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>

using namespace std;
/**
.
+
*

*/
int main()
{

    char c_input[100];
    char c_needle[100];

    char p_needle[100]; //this is the needle which is parsed

    gets(c_input);
    gets(c_needle);
    int i; int j=0;
    for(i=0;i<strlen(c_needle);i++)
    {
        if(c_needle[i]=='.')
        {
            p_needle[j]=p_needle[i-1];
        }
        else if(c_needle[i]=='+')
        {
            int k=0;
            while(k++ < 3)
            {
                p_needle[j++]=c_needle[i-1];
            }
            continue;
        }
        else if(c_needle[i]=='*')
        {

        }
        else
        {
            p_needle[j]=c_needle[i];
        }
        j++;
    }
    p_needle[j]='\0';

    string input(c_input);
    string needle(p_needle);

    int found=input.find(needle);
    int track=0;
    int sew=found;

    while(found <input.length())
    {
        track++;
        found=input.find(needle,++sew);
    }

    cout<<track;

   return 0;
}
