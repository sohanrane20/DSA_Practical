#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void enqueue(Node **front, Node **rear, int element);
int dequeue(Node **front, Node **rear);
bool isEmpty(Node *front, Node *rear);
int frontElement(Node *front);
int main()
{
    int choice, element;
    Node *front, *rear;
    front = NULL;
    rear = NULL;
    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Is empty" << endl;
        cout << "4. Front element" << endl;
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
            if (isEmpty(front, rear))
            {
                cout << "Empty" << endl;
            }
            else
            {
                cout << "Not empty" << endl;
            }
            break;
        case 4:
            cout << "Front element = " << frontElement(front) << endl;
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
    newNode->next = NULL;
    if (*front == NULL && *rear == NULL)
    {
        *front = newNode;
        *rear = newNode;
    }
    else
    {
        (*rear)->next = newNode;
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
    Node *temp = *front;
    if (*front == *rear)
    {
        *front = NULL;
        *rear = NULL;
    }
    else
    {
        *front = (*front)->next;
    }
    delete temp;
    return element;
}
bool isEmpty(Node *front, Node *rear)
{
    return front == NULL && rear == NULL;
}
int frontElement(Node *front)
{
    return front->data;
}