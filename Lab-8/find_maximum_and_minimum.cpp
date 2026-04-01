// 3. Find maximum and minimum element in queue
#include <iostream>
#include <climits>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Queue
{
    Node *front;
    Node *rear;
};
void enqueue(Queue *queue, int item);
int dequeue(Queue *queue);
int maximum(Queue *queue);
int minimum(Queue *queue);
int main()
{
    Queue *queue = new Queue;
    queue->front = NULL;
    queue->rear = NULL;
    int choice, item;
    Node *p;
    do
    {
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display elements\n";
        cout << "4. Maximum element\n";
        cout << "5. Minimum element\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element: ";
            cin >> item;
            enqueue(queue, item);
            break;
        case 2:
            item = dequeue(queue);
            if (item != -1)
                cout << "Dequeued element=" << item << endl;
            else
                cout << "Queue full\n";
            break;
        case 3:
            p = queue->front;
            while (p != NULL)
            {
                cout << p->data << "\t";
                p = p->next;
            }
            cout << endl;
            break;
        case 4:
            cout << "Maximum element=" << maximum(queue) << endl;
            break;
        case 5:
            cout << "Minimum element=" << minimum(queue) << endl;
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice >= 1 && choice <= 5);
    return 0;
}
void enqueue(Queue *queue, int item)
{
    Node *new_node;
    new_node = new Node;
    if (new_node == NULL)
        return;
    new_node->data = item;
    new_node->next = NULL;
    if (queue->front == NULL && queue->rear == NULL)
    {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else
    {
        (queue->rear)->next = new_node;
        queue->rear = new_node;
    }
}
int dequeue(Queue *queue)
{
    if (queue->front == NULL)
        return -1;
    int item = (queue->front)->data;
    Node *temp = queue->front;
    if (queue->front == queue->rear)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else
        queue->front = (queue->front)->next;
    delete temp;
    return item;
}
int maximum(Queue *queue)
{
    Node *p = queue->front;
    int max = INT_MIN;
    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
int minimum(Queue *queue)
{
    Node *p = queue->front;
    int min = INT_MAX;
    while (p != NULL)
    {
        if (p->data < min)
            min = p->data;
        p = p->next;
    }
    return min;
}