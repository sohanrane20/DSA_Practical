// A. 8. Swap nodes at given positions
#include <iostream>
using namespace std;
struct Node
{
    Node *previous;
    int data;
    Node *next;
};
void displayList(Node *head);
Node *swapNodes(Node *head, int a, int b);
int main()
{
    Node *head, *newNode, *temp;
    int n, a, b;
    head = NULL;
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
    displayList(head);
    cout << endl;
    cout << "Enter positions: ";
    cin >> a >> b;
    head = swapNodes(head, a, b);
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
Node *swapNodes(Node *head, int a, int b)
{
    Node *p, *q, *pPrevious, *qPrevious, *pNext, *qNext;
    p = head;
    for (int i = 1; i < a && p != NULL; i++)
    {
        p = p->next;
    }
    q = head;
    for (int i = 1; i < b && q != NULL; i++)
    {
        q = q->next;
    }

    pPrevious = p->previous;
    pNext = p->next;
    qPrevious = q->previous;
    qNext = q->next;

    if (p->next == q)
    {
        if (p == head)
        {
            head = q;
        }
        if (p->previous != NULL)
        {
            p->previous->next = q;
        }

        if (q->next != NULL)
        {
            q->next->previous = p;
        }

        q->previous = pPrevious;
        q->next = p;

        p->previous = q;
        p->next = qNext;
    }
    else
    {
        if (p == head)
        {
            head = q;
        }

        if (p->previous != NULL)
        {
            p->previous->next = q;
        }

        if (p->next != NULL)
        {
            p->next->previous = q;
        }

        if (q->previous != NULL)
        {
            q->previous->next = p;
        }

        if (q->next != NULL)
        {
            q->next->previous = p;
        }

        p->previous = qPrevious;
        p->next = qNext;

        q->previous = pPrevious;
        q->next = pNext;
    }
    return head;
}