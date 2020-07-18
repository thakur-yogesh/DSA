#include<iostream>
using namespace std;
class minheap{
public:
    int  *arr;
    int siz;
    int capacity;

    minheap(int c)
    {
        arr=new int[c];
        siz=0;
        capacity=c;
    }
    int leftchile(int i)
    {
        return ((2*i+1)/2);
    }
    int rightchile(int i)
    {
        return ((2*i+2)/2);
    }
    int parent(int i)
    {
        return ((i-1)/2);
    }
    void swap(int *a,int *b)
    {
        int t;
        t=*a;
        *a=*b;
        *b=t;
    }
    void push(int i)
    {
        if(siz==capacity)
        {
            cout<<"hpgya bhai\n";
            return;
        }
        siz++;
        arr[siz-1]=i;
        for(int x=siz-1;x!=0&&arr[parent(x)]>arr[x];)
        {
            swap(&arr[x],&arr[parent(x)]);
            x=parent(x);
        }
    }
    void print()
    {
        for(int i=0;i<siz;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};
int main()
{
    int n;
    cout<<"enter the max size of the minheap\n";
    cin>>n;

    minheap heap(n);

    bool run = true;

    while(run){
        cout<<"\nenter 1 to insert a item in the heap, 2 to print, and 3 to terminate the program\n";
        int choice;
        cin>>choice;
        switch(choice){

     case 1:
        cout<<"enter the element to be inserted:\n";
        int element;
        cin>>element;
        heap.push(element);
        break;
     case 2:
         cout<<"here is your heap:\n";
         heap.print();
         break;
     case 3:
        cout<<"terminating the program:\n";
        run = false;
        break;
        }

    }

}
