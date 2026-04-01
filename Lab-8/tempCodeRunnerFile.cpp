//1. Reverse queue
#include<iostream>
#include<stack>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
void enqueue(Node **front,Node **rear,int item);
int dequeue(Node **front,Node **rear);
void reverse(Node **front,Node **rear);
int main()
{
    Node *front=NULL,*rear=NULL;
    int choice,item;
    Node *p;
    do
    {
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Display elements\n";
        cout<<"4. Reverse\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter element: ";
                cin>>item;
                enqueue(&front,&rear,item);
                break;
            case 2:
                item=dequeue(&front,&rear);
                if(item!=-1) cout<<"Dequeued element="<<item<<endl;
                else cout<<"Queue full\n";
                break;
            case 3:
                p=front;
                while(p!=NULL) 
                {
                    cout<<p->data<<"\t";
                    p=p->next;
                }
                cout<<endl;
                break;
            case 4:
                reverse(&front,&rear);
                break;
            default:
                cout<<"Invalid choice\n";
        }
    } while(choice>=1 && choice<=4);
    return 0;
}
void enqueue(Node **front,Node **rear,int item) 
{
    Node *new_node;
    new_node=new Node;
    if(new_node==NULL) return;
    new_node->data=item;
    new_node->next=NULL;
    if(*front==NULL && *rear==NULL) 
    {
        *front=new_node;
        *rear=new_node;
    } 
    else 
    {
        (*rear)->next=new_node;
        *rear=new_node;
    }
}
int dequeue(Node **front,Node **rear) 
{
    if(*front==NULL) return -1;
    int item=(*front)->data;
    Node *temp=*front;
    if(*front==*rear) 
    {
        *front=NULL;
        *rear=NULL;
    } 
    else *front=(*front)->next;
    delete temp;
    return item;
}
void reverse(Node **front,Node **rear)
{
    stack<int> s1;
    int item;
    while(true)
    {
        item=dequeue(front,rear);
        if(item==-1) break;
        s1.push(item);
    }
    while(!s1.empty())
    {
        item=s1.top();
        s1.pop();
        enqueue(front,rear,item);
    }
}