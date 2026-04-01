// Part B: Implement stack using linked list
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void push(Node **head, int x);
int pop(Node **head);
int peek(Node *head, int position);
bool isEmpty(Node *head);
bool isFull();
int main()
{
    Node *head = NULL;
    int choice, element, position;
    do
    {
        cout << "1: Push" << endl;
        cout << "2: Pop" << endl;
        cout << "3: Peek" << endl;
        cout << "4: Is empty" << endl;
        cout << "5: Is full" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element: ";
            cin >> element;
            push(&head, element);
            break;
        case 2:
            element = pop(&head);
            cout << "Popped element = " << element << endl;
            break;
        case 3:
            cout << "Enter position: ";
            cin >> position;
            cout << "Element = " << peek(head, position) << endl;
            break;
        case 4:
            if (isEmpty(head))
            {
                cout << "Empty" << endl;
            }
            else
            {
                cout << "Not empty" << endl;
            }
            break;
        case 5:
            if (isFull())
            {
                cout << "Full" << endl;
            }
            else
            {
                cout << "Not full" << endl;
            }
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice >= 1 && choice <= 5);
    return 0;
}
void push(Node **head, int x)
{
    Node *newNode = new Node;
    if (newNode == NULL)
    {
        cout << "Stack is full" << endl;
        return;
    }
    newNode->data = x;
    newNode->next = *head;
    *head = newNode;
}
int pop(Node **head)
{
    if (*head == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        Node *temp;
        temp = *head;
        *head = (*head)->next;
        int y = temp->data;
        delete temp;
        return y;
    }
}
int peek(Node *head, int position)
{
    Node *ptr;
    ptr = head;
    for (int i = 0; i < position; i++)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}
bool isEmpty(Node *head)
{
    return head == NULL;
}
bool isFull()
{
    Node *newNode;
    newNode = new Node;
    return newNode == NULL;
}