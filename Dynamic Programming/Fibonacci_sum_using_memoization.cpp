#include<iostream>
using namespace std;
#define MAX 10000

int memo[MAX];

int fibo(int n)
{
    if(memo[n]==-1)
    {
        int result;
        if(n==0||n==1)
           result = n;
        else
           result = fibo(n-1) + fibo(n-2);
        memo[n] = result;
    }
    return memo[n];
}

int main()
{
    cout<<"enter the number for finding the fibonacci sum\n";
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        memo[i] = -1;
    }
    cout<<fibo(n);
}
