// B. 2. Check is circular list is sorted
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void displayList(Node *head);
bool checkSortedList(Node *head);
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

    if (checkSortedList(head))
    {
        cout << "Sorted in ascending order\n";
    }
    else
    {
        cout << "Not sorted in ascending order\n";
    }
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
bool checkSortedList(Node *head)
{
    Node *ptr;
    ptr = head;
    do
    {
        if (ptr->data > ptr->next->data)
        {
            return false;
        }
        ptr = ptr->next;
    } while (ptr->next != head);
    return true;
}