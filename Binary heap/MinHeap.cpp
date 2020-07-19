#include<iostream>
using namespace std;
class minheap{
public:
    int  *arr;
    int _size;
    int capacity;

    minheap(int c)
    {
        arr=new int[c];
        _size=0;
        capacity=c;
    }
    int leftchild(int i)
    {
        return ((2*i+1)/2);
    }
    int rightchild(int i)
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
        if(_size==capacity)
        {
            cout<<"hogya bhai\n";
            return;
        }
        _size++;
        arr[_size-1]=i;
        for(int x=_size-1;x!=0&&arr[parent(x)]>arr[x];)
        {
            swap(&arr[x],&arr[parent(x)]);
            x=parent(x);
        }
    }
    void print()
    {
        for(int i=0;i<_size;i++)
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
