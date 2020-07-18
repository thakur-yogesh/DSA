#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node *link;
};

struct node *getNewNode(int data)
{
    node *newnode;
    newnode = new node;
    newnode->data = data;
    newnode->link = 0;
    return newnode;
};

struct node *push(node *head,int data)
{
    if(head==0)
    {
        head = getNewNode(data);
    }
    else
    {
        head->link = push(head->link,data);
    }
    return head;
};

void printList(node *head)
{
    int first = 1;
    while(head)
    {
        if(first == 1)
        {
            first = 0;
        }
        else
        {
            cout<<"->";
        }
        cout<<head->data;

        head = head->link;
    }
}

int main()
{
    system("COLOR 0A");
    node *head = 0;
    cout<<"enter the size of the linked list\n";
    int _size;
    cin>>_size;
    while(_size--)
    {
        cout<<"enter the element\n";
        int element;
        cin>>element;
        head = push(head,element);
    }

    printList(head);
}
