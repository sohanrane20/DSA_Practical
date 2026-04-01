// 3. Remove duplicates from a sorted singly linked list.
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void remove_element(Node *head, Node *ptr);
Node *remove_duplicates(Node *head);
int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node *head, *newNode, *temp;
    head = NULL;
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
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
    cout << endl;
    head = remove_duplicates(head);
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
    return 0;
}
void remove_element(Node *head, Node *ptr)
{
    Node *p;
    p = head;
    while (p->next != ptr && p->next != NULL)
    {
        p = p->next;
    }
    if (p->next == ptr)
    {
        p->next = ptr->next;
        delete ptr;
    }
}
Node *remove_duplicates(Node *head)
{
    Node *ptr;
    ptr = head;
    while (ptr != NULL && ptr->next != NULL)
    {
        while (ptr->next != NULL && ptr->data == ptr->next->data)
        {
            remove_element(head, ptr->next);
        }
        ptr = ptr->next;
    }
    return head;
}