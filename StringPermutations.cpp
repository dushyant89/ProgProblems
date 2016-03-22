#include <string>
#include <iostream>
#include <vector>
using namespace std;


vector<string> permute(vector<string> str_list,string input,int n)
{
    vector<string> new_list;
    for(int i=0;i<str_list.size();i++)
    {
        string sample=str_list[i];
        int x;
        cin>>x;
        //now the idea is to create permutations of a substring
        for(int j=0;j<=sample.length();j++)
        {
            cout<<sample.substr(0,j) + input.substr(n,1) + sample.substr(j,sample.length()-j)<<endl;
            new_list.push_back(sample.substr(0,j) + input.substr(n,1) + sample.substr(j,sample.length()-j));
        }
    }
    if(n>=input.length())
    {
        return new_list;
    }
    else
    {
        permute(new_list,input,++n);
    }
}

int main()
{
    string input="ABCD";

    vector <string> str_list,result;

    str_list.push_back(input.substr(0,1));

    result=permute(str_list,input,1);

    for(unsigned int i=0;i<result.size();i++)
        cout<<result[i]<<"\n";

    return 1;
}
