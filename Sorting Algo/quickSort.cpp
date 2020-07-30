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

int Partition(int arr[],int start,int end_)
{
    int pivot = arr[end_];
    int i = start-1;
    int j;
    for(j=start;j<end_;j++)
    {
        if(arr[j]<=pivot)
        {
            i = i+1;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[end_]);
    return i+1;
}

void quickSort(int arr[],int start,int end_)
{
    if(start<end_)
    {
        int sorted_index = Partition(arr,start,end_);
        quickSort(arr,start,sorted_index-1);
        quickSort(arr,sorted_index+1,end_);
    }
}

int main()
{
    int a[MAX],n,i;
    cout<<"enter the size of the array\n";
    cin>>n;
    cout<<"enter the elements in the array\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    int start = 0;
    int end_ = n-1;
    quickSort(a,start,end_);
    cout<<"array after sort: ";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
