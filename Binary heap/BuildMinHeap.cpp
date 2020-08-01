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

void minHeapify(int arr[],int root,int heap_size)
{
    int left_child = 2 * root + 1;
    int right_chile = 2 * root + 2;
    int smallest;
    if(left_child<=heap_size&&arr[left_child]<arr[root])
        smallest = left_child;
    else
        smallest = root;
    if(right_chile<=heap_size&&arr[right_chile]<arr[root])
        smallest = right_chile;
    if(smallest!=root){
        swap(&arr[root],&arr[smallest]);
        minHeapify(arr,smallest,heap_size);
    }
}

void buildHeap(int arr[],int heap_size)
{
    for(int i = ((heap_size-2)/2);i>=0;i--)
        {
            minHeapify(arr,i,heap_size);
        }
}

int main()
{
    int arr[MAX],i,n;
    cout<<"enter the size of the array\n";
    cin>>n;
    cout<<"enter the elements in the array\n";
    for(i=0;i<n;i++)
        cin>>arr[i];
    buildHeap(arr,n-1);
    cout<<"after heapifying the array: \n";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
