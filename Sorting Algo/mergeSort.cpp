#include<iostream>
#define MAX 100000
using namespace std;

void merger(int arr[],int start,int mid,int end_)
{
    int n1,n2,i,j,k;
    n1 = mid - start +1;
    n2 = end_ - mid;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i] = arr[start+i];
    for(j=0;j<n2;j++)
        R[j] = arr[mid+1+j];

    L[n1] = 63551;
    R[n2] = 63552;
    i=0;
    j=0;
    k = start;
    while(k<=end_)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
}

void mergeSort(int arr[],int start,int end_)
{
    if(start<end_)
    {
        int mid = (start+end_) / 2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end_);
        merger(arr,start,mid,end_);
    }
}

int main()
{
    int n,arr[MAX],i;
    cout<<"enter the size of the array\n";
    cin>>n;
    cout<<"enter the elements in the array\n";
    for(i=0;i<n;i++)
        cin>>arr[i];
    int start = 0;
    int end_ = n-1;
    mergeSort(arr,start,end_);
    cout<<"sorted array :";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
