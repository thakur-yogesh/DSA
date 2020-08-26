#include <iostream>

using namespace std;

int main()
{
   long int n,a[1000000],i;
   cout<<"enter the size of the array\n";
    cin>>n;
    cout<<"enter the elements in the range 0 - 100 otherwise the algorithm will not work :)"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];
    int counter[100];
    for(i=0;i<100;i++)
        counter[i] = 0;
    for(i=0;i<n;i++)
        counter[a[i]] = counter[a[i]] + 1;
    cout<<"sorted array : ";
    for(i=0;i<100;i++)
    {
        if(counter[i]==0)
            continue;
        else
        {
            for(int j=0;j<counter[i];j++)
                cout<<i<<" ";
        }
    }
}
