#include<string>
#include<iostream>
using namespace std;

void subsets(string input,string output,int length)
{
    if(length==0)
    {
        cout<<"\""<<output<<"\""<<" ";
        return;
    }
    subsets(input,output,length-1);
    subsets(input,output+input[length-1],length-1);
}

int main()
{
    string str;
    cout<<"enter the string\n";
    cin>>str;
    subsets(str,"",str.length());
}

