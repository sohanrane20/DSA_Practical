// B. 5. Reverse circular linked list
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void displayList(Node *head);
Node *reverseList(Node *head);
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

    head = reverseList(head);

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
Node *reverseList(Node *head)
{
    Node *ptr, *slow, *fast;

    ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = NULL;

    ptr = head;
    slow = NULL;
    fast = NULL;

    while (ptr != NULL)
    {
        fast = ptr;
        ptr = ptr->next;
        fast->next = slow;
        slow = fast;
    }

    ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = fast;

    head = fast;

    return head;
}