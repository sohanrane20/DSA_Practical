// B. 1. Split circular linked list
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void displayList(Node *head);
void splitList(Node *head);
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

    splitList(head);
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

void splitList(Node *head)
{
    Node *slow, *fast, *another, *ptr;

    slow = head;
    fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != head && fast->next != head);

    ptr = head;

    while (ptr->next != slow)
    {
        ptr = ptr->next;
    }

    ptr->next = head;

    another = slow;

    ptr = another;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    ptr->next = another;

    displayList(head);
    cout << endl;
    displayList(another);
    cout << endl;
}