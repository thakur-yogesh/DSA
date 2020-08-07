#include<iostream>
#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

void swap(float *a,float *b)
{
    float t;
    t = *a;
    *a = *b;
    *b = t;
}

void swap_int(int *a,int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    float num_obj,profits[MAX],weights[MAX],net_profit[MAX],capacity;
    int i;
    cout<<"enter the number of objects\n";
    cin>>num_obj;
    int objects[MAX];
    for(i=0;i<num_obj;i++)
        objects[i]=i;
    cout<<"enter the profits and weights for each objects\n";
    for(i=0;i<num_obj;i++)
    {
        cin>>profits[i];
        cin>>weights[i];
    }
    cout<<"enter maximum capacity of the bag\n";
    cin>>capacity;

    for(i=0;i<num_obj;i++)
    {
        net_profit[i] = profits[i] / weights[i];
    }
    for(i=1;i<num_obj;i++)
    {
        while(i>0&&net_profit[i-1]<=net_profit[i])
        {
            swap(&net_profit[i-1],&net_profit[i]);
            swap_int(&objects[i-1],&objects[i]);
            i--;
        }
    }
    cout<<"sorted netprofit::";
    for(i=0;i<num_obj;i++)
        cout<<net_profit[i]<<" ";
    cout<<endl<<"sorted objects::";
    for(i=0;i<num_obj;i++)
        cout<<objects[i]<<" ";
    float max_profit = 0;
    for(i=0;i<num_obj;i++)
    {
        if(capacity>0&&weights[i]<=capacity)
        {
            capacity = capacity - weights[i];
            max_profit = max_profit + profits[objects[i]];
        }
        else
            break;
    }
    if(capacity>0)
        max_profit = max_profit + profits[objects[i]]*(capacity/(weights[i]));
   cout<<"max profit\n";
   cout<<max_profit;
}
