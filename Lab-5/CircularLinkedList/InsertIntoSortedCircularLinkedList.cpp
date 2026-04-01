// B. 3. Insert into sorted circular linked list
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void displayList(Node *head);
Node *insertIntoSortedList(Node *head, int item);
int main()
{
    int n, item;
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

    cout << "Enter item: ";
    cin >> item;

    head = insertIntoSortedList(head, item);

    displayList(head);
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
Node *insertIntoSortedList(Node *head, int item)
{
    Node *ptr, *newNode;
    newNode = new Node;
    newNode->data = item;

    if (head->data > item)
    {
        newNode->next = head;

        ptr = head;

        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;

        head = newNode;
        return head;
    }

    ptr = head;

    do
    {
        if (ptr->next->data > item)
        {

            newNode->next = ptr->next;
            ptr->next = newNode;

            break;
        }
        ptr = ptr->next;
    } while (ptr->next != head);

    if (ptr->next == head)
    {
        newNode->next = head;
        ptr->next = newNode;
    }
    return head;
}