// A. 1. Reverse a doubly linked list
#include <iostream>
using namespace std;
struct Node
{
    Node *previous;
    int data;
    Node *next;
};
void displayList(Node *head);
Node *reverseList(Node *head);
int main()
{
    Node *head, *newNode, *temp;
    head = NULL;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        newNode = new Node;
        cout << "Enter element " << i + 1 << ": ";
        cin >> newNode->data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
            temp->previous = NULL;
        }
        else
        {
            newNode->previous = temp;
            temp->next = newNode;
            temp = newNode;
        }
    }
    cout << "Elements of list before reversal are ";
    displayList(head);
    cout << endl;
    head = reverseList(head);
    cout << "Elements of list after reversal are ";
    displayList(head);
    cout << endl;
    return 0;
}
void displayList(Node *head)
{
    Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
}
Node *reverseList(Node *head)
{
    Node *ptr, *q, *p;
    ptr = head;
    q = p = NULL;
    while (ptr != NULL)
    {
        p = ptr;
        ptr = ptr->next;
        p->next = q;
        p->previous = ptr;
        q = p;
    }
    head = p;
    return head;
}