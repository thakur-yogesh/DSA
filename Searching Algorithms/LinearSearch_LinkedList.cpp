#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *link;
};

node *getnewNode(int data)
{
    node *newnode;
    newnode = new node;
    newnode->data = data;
    newnode->link = 0;
    return newnode;
}

node *push(node *head, int data)
{
    if(head==0)
        head = getnewNode(data);
    else
        head->link = push(head->link,data);
    return head;
}

int linear_search(node *head,int target)
{
    if(head){
        while(head){
          if(head->data==target)
            return 1;
        head = head->link;
        }
       }
    return -1;
}


int main()
{
    system("COLOR 0A");
    int n;
    cout<<"enter the size of the linked list\n";
    cin>>n;
    node *head;
    head = 0;

    while(n--)
    {
        int element;
        cout<<"enter the elements in the linked list\n";
        cin>>element;
        head = push(head,element);
    }
    node *temp;
    temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    int number;
    cout<<"enter the number to be searched\n";
    cin>>number;

    int found;

    found = linear_search(head,number);

    (found!=-1)?cout<<"element is present in the linked list\n":cout<<"element is not in the list\n";

}
