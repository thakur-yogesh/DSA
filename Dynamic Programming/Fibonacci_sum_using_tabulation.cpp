#include<iostream>
using namespace std;

int fib(int n)
{
    int tab[n+1];

    tab[0] = 0;
    tab[1] = 1;

    for(int i=2;i<=n;i++)
    {
        tab[i] = tab[i-1] + tab[i-2];
    }

    return tab[n];

}

int main()
{
    int n;
    cout<<"enter the number\n";
    cin>>n;
    cout<<"fibonacci sum=="<<fib(n);
}
