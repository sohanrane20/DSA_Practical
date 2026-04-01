// A. 5. Maximum sum sublist
#include <iostream>
using namespace std;
struct Node
{
    Node *previous;
    int data;
    Node *next;
};
void displayList(Node *head);
void displayList(Node *beg, Node *end);
int maximumSumSublist(Node *head);
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
    cout << maximumSumSublist(head);
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
void displayList(Node *beg, Node *end)
{
    Node *ptr;
    ptr = beg;
    while (ptr != NULL && ptr != end->next)
    {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
}
int maximumSumSublist(Node *head)
{
    Node *ptr, *beg, *end, *temp;
    int result = 0, sum = 0;

    ptr = head;

    beg = head;
    end = head;
    temp = head;

    while (ptr != NULL)
    {
        sum += ptr->data;

        if (sum > result)
        {
            result = sum;
            beg = temp;
            end = ptr;
        }

        if (sum < 0)
        {
            sum = 0;
            temp = ptr->next;
        }

        ptr = ptr->next;
    }

    displayList(beg, end);
    cout << endl;

    return result;
}