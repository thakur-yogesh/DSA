#include<iostream>
#define MAX 100
using namespace std;

void swap(int *a,int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(int arr[],int parent,int size__)
{
    int left_child = 2*parent + 1;
    int right_child = 2*parent + 2;
    int smallest = parent;

    if(left_child<size__&&arr[left_child]<arr[parent])
        smallest = left_child;
    if(right_child<size__&&arr[right_child]<arr[smallest])
        smallest = right_child;
    if(smallest!=parent)
    {
        swap(&arr[parent],&arr[smallest]);
        minHeapify(arr,smallest,size__);
    }
}

void buildHeap(int arr[],int size_)
{
    int parent_of_last_leaf = (size_-2)/2;
    for(int i = parent_of_last_leaf;i>=0;i--)
        minHeapify(arr,i,size_);
}

int main()
{
    int a[MAX],i,j,n;
    cout<<"enter the size of the array\n";
    cin>>n;
    cout<<"enter the elements in the array\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"after building the min heap\n";
    buildHeap(a,n);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
