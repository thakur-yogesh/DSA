#include<iostream>
#define MAX 100000
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
   int a[MAX],n,i,j;
   cout<<"enter the size of the array\n";
   cin>>n;
   cout<<"enter the elements in the array\n";
   for(i=0;i<n;i++)
      cin>>a[i];
   for(i=1;i<n;i++)
   {
       while(i>0&&a[i]<a[i-1])
       {
           swap(&a[i],&a[i-1]);
           i--;
       }
   }
   cout<<"sorted array\n";
   for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
