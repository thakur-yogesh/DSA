#include<iostream>
#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

int linearSearch(int arr[],int size_,int target)
{
    int i;
    for(i=0;i<size_;i++)
        if(arr[i]==target)
            return i;
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
    cout<<"enter the element to be searched\n";
    cin>>target;
    int found;
    found = linearSearch(arr,size_,target);

    (found!=-1)?cout<<"\nelement found in the index "<<found:cout<<"\nelement is not in the array\n";
}
