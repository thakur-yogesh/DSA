#include<iostream>
#include <bits/stdc++.h>
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

void minHeapify(int arr[],int parent)
{
    int left_child = parent*2 +1;
    int right_child = parent*2 +2;
    int smallest = parent;

    if(left_child<heap_size&&arr[left_child]<arr[parent])
        smallest = left_child;
    if(right_child<heap_size&&arr[right_child]<arr[smallest])
        smallest = right_child;
    if(smallest!=parent)
    {
        swap(&arr[smallest],&arr[parent]);
        minHeapify(arr,smallest);
    }
}

void buildHeap(int arr[])
{
    int parent_of_the_last_leaf = (heap_size-2)/2;
    for(int i = parent_of_the_last_leaf;i>=0;i--)
        minHeapify(arr,i);
}

int extractMin(int arr[])
{
    if(heap_size<0)
       {
           cout<<"heap under flow returning code 0:\n";
           return 0;
       }
    else{
        int minimum = arr[0];
        arr[0] = arr[heap_size--];
        minHeapify(arr,0);
        return minimum;
    }
}

int main()
{
    system("COLOR 0A");
    int a[MAX],i;
    cout<<"enter the size of the heap\n";
    cin>>heap_size;
    cout<<"enter the elements in the heap\n";
    for(i=0;i<heap_size;i++)
        cin>>a[i];
    buildHeap(a);
    cout<<"heap : ";
    for(i=0;i<heap_size;i++)
        cout<<a[i]<<" ";
    cout<<"\nafter calling extract min function:\n";
    cout<<extractMin(a);
}
