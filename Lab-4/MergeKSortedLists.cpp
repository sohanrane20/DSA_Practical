// 11. Merge k sorted linked lists into one sorted linked list
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void displayList(Node *head);
Node *mergeKLists(Node *heads[], int k);
Node *mergeLists(Node *head1, Node *head2);
int main()
{
    int k, n;
    cout << "Enter k: ";
    cin >> k;
    Node *heads[k], *newNode, *temp, *head;
    for (int i = 0; i < k; i++)
    {
        heads[i] = NULL;
        cout << "Enter number of nodes: ";
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            newNode = new Node;
            cout << "Enter element " << j + 1 << ": ";
            cin >> newNode->data;
            newNode->next = NULL;
            if (heads[i] == NULL)
            {
                heads[i] = newNode;
                temp = newNode;
            }
            else
            {
                temp->next = newNode;
                temp = newNode;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        displayList(heads[i]);
        cout << endl;
    }
    head = mergeKLists(heads, k);
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
Node *mergeKLists(Node *heads[], int k)
{
    if (k == 0)
    {
        return NULL;
    }
    for (int i = 0; i <= k - 2; i++)
    {
        heads[i + 1] = mergeLists(heads[i], heads[i + 1]);
    }
    return heads[k - 1];
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
    ptr->next = NULL;
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