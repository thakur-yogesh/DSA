#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

int binarySearch(int a[],int left_index,int right_index,int target)
{
    int middle_index;
    while(left_index<=right_index)
    {
        middle_index = (right_index+left_index)/2;

        if(a[middle_index]<target)
            left_index = middle_index +1;
        if(a[middle_index]==target)
            return middle_index;
        else
            right_index = middle_index -1;
    }
    return -1;
}

int main()
{
    system("COLOR 0A");
    int arr[MAX],size_,i,target;
    cout<<"enter the size of the array\n";
    cin>>size_;
    cout<<"enter the elements in the array\n";
    for(i=0;i<size_;i++)
        cin>>arr[i];
    sort(arr,arr+size_);
    cout<<"sorted array\n";
    for(i=0;i<size_;i++)
        cout<<arr[i]<<" ";
    cout<<"enter the value to be searched\n";
    cin>>target;
    int found;
    found = binarySearch(arr,0,size_-1,target);

    (found!=-1)?cout<<"\nelement is found in the index "<<found:cout<<"\nelement is not in the array\n";
}
