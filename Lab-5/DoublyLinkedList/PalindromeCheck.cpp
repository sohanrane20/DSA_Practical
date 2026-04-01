// A. 6. Palindrome check
#include <iostream>
using namespace std;
struct Node
{
    Node *previous;
    int data;
    Node *next;
};
void displayList(Node *head);
bool checkPalindrome(Node *head);
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
    displayList(head);
    cout << endl;
    if (checkPalindrome(head))
    {
        cout << "Palindrome\n";
    }
    else
    {
        cout << "Not palindrome\n";
    }
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
bool checkPalindrome(Node *head)
{
    Node *p, *q;
    q = head;
    while (q->next != NULL)
    {
        q = q->next;
    }
    p = head;
    while (p->next != q && p != q)
    {
        if (p->data != q->data)
        {
            return false;
        }
        p = p->next;
        q = q->previous;
    }
    return true;
}