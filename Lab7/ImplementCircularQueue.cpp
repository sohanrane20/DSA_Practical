#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void enqueue(Node **front, Node **rear, int element);
int dequeue(Node **front, Node **rear);
int frontElement(Node *front);
int rearElement(Node *rear);
int main()
{
    Node *front, *rear;
    front = NULL;
    rear = NULL;
    int choice, element;
    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front element" << endl;
        cout << "4. Rear element" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element: ";
            cin >> element;
            enqueue(&front, &rear, element);
            break;
        case 2:
            cout << "Dequeued " << dequeue(&front, &rear) << endl;
            break;
        case 3:
            cout << "Front element = " << frontElement(front) << endl;
            break;
        case 4:
            cout << "Rear element = " << rearElement(rear) << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice >= 1 && choice <= 4);
    return 0;
}
void enqueue(Node **front, Node **rear, int element)
{
    Node *newNode;
    newNode = new Node;
    if (newNode == NULL)
    {
        cout << "Queue overflow" << endl;
        return;
    }
    newNode->data = element;
    if (*front == NULL && *rear == NULL)
    {
        *front = newNode;
        *rear = newNode;
        newNode->next = *front;
    }
    else
    {
        (*rear)->next = newNode;
        newNode->next = *front;
        *rear = newNode;
    }
}
int dequeue(Node **front, Node **rear)
{
    if (*front == NULL)
    {
        cout << "Queue underflow" << endl;
        return -1;
    }
    int element = (*front)->data;
    Node *temp;
    temp = *front;
    if (*front == *rear)
    {
        *front = NULL;
        *rear = NULL;
    }
    else
    {
        *front = (*front)->next;
        (*rear)->next = *front;
    }
    delete temp;
    return element;
}
int frontElement(Node *front)
{
    return front->data;
}
int rearElement(Node *rear)
{
    return rear->data;
}