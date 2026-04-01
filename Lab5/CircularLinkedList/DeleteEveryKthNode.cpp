// B. 5. Delete every kth node
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void displayList(Node *head);
Node *deleteEveryKthNode(Node *head, int k);
int main()
{
    int n;
    Node *head, *newNode, *temp;

    head = NULL;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        newNode = new Node;

        cout << "Enter element " << i + 1 << ": ";
        cin >> newNode->data;

        newNode->next = head;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    displayList(head);
    cout << endl;

    head = deleteEveryKthNode(head, 2);

    displayList(head);
    cout << endl;

    return 0;
}
void displayList(Node *head)
{
    Node *ptr;

    ptr = head;

    do
    {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    } while (ptr != head);
}
Node *deleteNode(Node *head, Node *ptr)
{
    Node *p;
    if (ptr == head)
    {
        p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = ptr->next;
        head = ptr->next;
        delete ptr;
        return head;
    }

    p = head;
    while (p->next != ptr)
    {
        p = p->next;
    }
    p->next = ptr->next;
    delete ptr;
    return head;
}
Node *deleteEveryKthNode(Node *head, int k)
{
    Node *ptr, *temp;
    ptr = head;
    while (ptr->next != ptr)
    {
        for (int i = 1; i < k; i++)
        {
            ptr = ptr->next;
        }
        temp = ptr->next;
        head = deleteNode(head, ptr);
        ptr = temp;

        displayList(head);
        cout << endl;
    }
    return head;
}