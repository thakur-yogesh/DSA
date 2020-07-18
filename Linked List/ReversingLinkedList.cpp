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
    cout<<"List:\n";
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

node *reverseList(node *head)
{
    node *current, *next,*prev;
    current = head;
    while(current)
    {
        if(current==head){
            next = current->link;
            current->link = 0;
            prev = current;
            current = next;
        }
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    return prev;

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

    head = reverseList(head);
    cout<<"\nlist after reversing\n";
    printList(head);



}
