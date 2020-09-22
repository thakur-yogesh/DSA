#include<iostream>
using namespace std;
int main()
{
    cout<<"enter the range of the numbers for finding the primes of among them\n";
    int n;
    cin>>n;
    bool isprime[n+1];
    int i;

    for(i=2;i<=n;i++)
        isprime[i] = true;

    for(i=2;i*i<=n;i++)
    {
        if(isprime[i]==true)
        {
            for(int j=2*i;j<=n;j=j+i)
                isprime[j] = false;
        }
    }
    for(i=2;i<=n;i++){
        if(isprime[i])
            cout<<i<<" ";
    }
}
