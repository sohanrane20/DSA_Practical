// A. 3. Rotate by k nodes
#include <iostream>
using namespace std;
struct Node
{
    Node *previous;
    int data;
    Node *next;
};
void displayList(Node *head);
Node *rotateList(Node *head, int k);
int main()
{
    Node *head, *newNode, *temp;
    int n, k;
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
    cout << "Elements of list before rotation are ";
    displayList(head);
    cout << endl;
    cout << "Enter k: ";
    cin >> k;
    head = rotateList(head, k);
    cout << "Elements of list after rotation are ";
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
Node *rotateList(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    Node *ptr, *p, *q;
    int i;
    q = head;
    ptr = head;
    for (i = 1; i < k && ptr->next != NULL; i++)
    {
        ptr = ptr->next;
    }
    if (i == k)
    {
        p = ptr->next;
        ptr->next = NULL;
        if (p != NULL)
        {
            p->previous = NULL;
            head = p;
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = q;
            q->previous = p;
        }
    }
    return head;
}