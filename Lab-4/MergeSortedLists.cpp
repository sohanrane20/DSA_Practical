// 8. Merge two sorted linked lists into one sorted list
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void displayList(Node *head);
Node *mergeLists(Node *head1, Node *head2);
int main()
{
    Node *head, *head1, *head2, *newNode, *temp;
    int n;
    head1 = NULL;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        newNode = new Node;
        cout << "Enter element " << i + 1 << ": ";
        cin >> newNode->data;
        newNode->next = NULL;
        if (head1 == NULL)
        {
            head1 = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    head2 = NULL;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        newNode = new Node;
        cout << "Enter element " << i + 1 << ": ";
        cin >> newNode->data;
        newNode->next = NULL;

        if (head2 == NULL)
        {
            head2 = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    displayList(head1);
    cout << endl;
    displayList(head2);
    cout << endl;
    head = mergeLists(head1, head2);
    displayList(head);
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
Node *mergeLists(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    Node *head, *ptr, *p, *q;
    p = head1;
    q = head2;
    if (p->data <= q->data)
    {
        ptr = p;
        p = p->next;
    }
    else
    {
        ptr = q;
        q = q->next;
    }
    head = ptr;
    while (p != NULL && q != NULL)
    {
        if (p->data <= q->data)
        {
            ptr->next = p;
            p = p->next;
        }
        else
        {
            ptr->next = q;
            q = q->next;
        }
        ptr = ptr->next;
    }
    if (p != NULL)
    {
        ptr->next = p;
    }
    else if (q != NULL)
    {
        ptr->next = q;
    }
    return head;
}