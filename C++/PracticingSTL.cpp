#include<vector>
#include<conio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int i_size;
    cout<<"Enter the size of array you want to play with\n";
    cin>>i_size;
    vector<int> key(i_size);
    vector<int> value(i_size);
    cout<<"Now enter values for the array\n";
    for(int i=0;i<i_size;i++)
    {
        cin>>key[i];
        value[i]=0;
        cout<<" ";
    }
    //Done initializing and now sorting the array O(nlogn) time
    sort(key.begin(),key.end());

    for(int i=0;i<i_size;i++)
    {
        int j=i;
        int i_count=0;
        for(j;key[j]<2*key[i];j++)
        {
            i_count++;
        }
        value[i]=i_count;
    }

    int i_max=value[0];
    //finding the maximum range now
    for(int i=0;i<i_size;i++)
    {
        if(value[i] >i_max) i_max=value[i];
    }

    cout<<"Minimum no. of removals are\n"<<i_size-i_max;

    return 1;
}
