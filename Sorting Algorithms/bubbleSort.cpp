#include<iostream>
#define MAX 10000
using namespace std;

void swap(int *a,int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int arr[MAX],size_,i,j,swapped;

    cout<<"enter the size of the array\n";
    cin>>size_;
    cout<<"enter the elements in the array\n";
    for(i=0;i<size_;i++)
        cin>>arr[i];
    for(i=0;i<size_;i++)
    {
        swapped = 0;
        for(j=0;j<size_-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swapped = 1;
            }
        }
        if(swapped==0)
            break;
    }
    cout<<"\nafter applying bubble sort : ";
    for(i=0;i<size_;i++)
        cout<<arr[i]<<" ";
}
