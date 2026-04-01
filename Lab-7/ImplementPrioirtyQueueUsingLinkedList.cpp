#include <iostream>
using namespace std;
struct Node
{
    int data;
    int priority;
    Node *next;
};
void push(Node **head, int data, int priority);
int pop(Node **head);
int peek(Node *head);
int main()
{
    Node *head;
    head = NULL;
    int choice, data, priority;
    do
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter priority: ";
            cin >> priority;
            push(&head, data, priority);
            break;
        case 2:
            cout << "Popped " << pop(&head) << endl;
            break;
        case 3:
            cout << "Highest priority data = " << peek(head) << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice >= 1 && choice <= 3);
    return 0;
}
void push(Node **head, int data, int priority)
{
    Node *newNode = new Node;
    if (newNode == NULL)
    {
        cout << "Queue overflow" << endl;
        return;
    }
    newNode->data = data;
    newNode->priority = priority;
    if (*head == NULL)
    {
        newNode->next = NULL;
        *head = newNode;
    }
    else if (priority < (*head)->priority)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node *ptr;
        ptr = *head;
        while (ptr->next != NULL && ptr->next->priority <= priority)
        {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}
int pop(Node **head)
{
    if (*head == NULL)
    {
        cout << "Queue underflow" << endl;
        return -1;
    }
    int element = (*head)->data;
    Node *temp;
    temp = *head;
    *head = (*head)->next;
    delete temp;
    return element;
}
int peek(Node *head)
{
    return head->data;
}