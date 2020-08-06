#include<iostream>
#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

int heap_size;

void swap(int *a,int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int parent(int index)
{
    return (index-1)/2;
}

void minHeapify(int arr[],int parent)
{
    int left_child = 2*parent + 1;
    int right_child = 2*parent + 2;
    int smallest = parent;

    if(left_child<heap_size&&arr[left_child]<arr[parent])
        smallest = left_child;
    if(right_child<heap_size&&arr[right_child]<arr[smallest])
        smallest = right_child;
    if(smallest!=parent)
    {
        swap(&arr[parent],&arr[smallest]);
        minHeapify(arr,smallest);
    }
}

void buildHeap(int arr[],int size_)
{
    int parent_of_last_leaf = (size_-2)/2;
    for(int i = parent_of_last_leaf;i>=0;i--)
        minHeapify(arr,i);
}

void heapSort(int a[],int size_)
{
    int i;
    buildHeap(a,size_);
    for(i=size_-1;i>=0;i--)
        {
            swap(&a[0],&a[i]);
            heap_size--;
            minHeapify(a,0);
        }
}

int main()
{
    system("COLOR 0A");
    int a[MAX],i,j,n;
    cout<<"enter the size of the array\n";
    cin>>n;
    heap_size = n;
    cout<<"enter the elements in the array\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    heapSort(a,n);
    cout<<"after applying heapsort : ";
    for(i=n-1;i>=0;i--)
        cout<<a[i]<<" ";

}
