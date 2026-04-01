//Mid-square method
#include<iostream>
#include<math.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
int count_digits(int num);
int main()
{
    int n;
    Node *table[100];
    for(int i=0; i<100; i++)
        table[i]=NULL;
    cout<<"Enter n ";
    cin>>n;
    int keys[n];
    cout<<"Enter keys ";
    for(int i=0; i<n; i++)
        cin>>keys[i];
    for(int i=0; i<n; i++)
    {
        int square=keys[i]*keys[i], count=count_digits(square);
        float remove=(count-2)/2;
        int middle=((int)(square/pow(10, remove)))%(int)pow(10, 2);
        int j=middle%100;
        Node *new_node;
        new_node=new Node;
        new_node->data=keys[i];
        new_node->next=NULL;
        if(table[j]==NULL)
            table[j]=new_node;
        else
        {
            new_node->next=table[j];
            table[j]=new_node;
        }
    }
    for(int i=0; i<100; i++)
    {
        Node *p;
        p=table[i];
        cout<<"Cell="<<i<<"\t";
        while(p!=NULL)
        {
            cout<<p->data<<"->";
            p=p->next;
        }
        cout<<endl;
    }
    return 0;
}
int count_digits(int num)
{
    int count=0;
    while(num>0)
    {
        count++;
        num/=10;
    }
    return count;
}