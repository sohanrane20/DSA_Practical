// 2. Count number of elements in queue
#include <iostream>
#define N 10
using namespace std;
void enqueue(int *queue, int *front, int *rear, int item);
int dequeue(int *queue, int *front, int *rear);
int main()
{
    int *queue = new int[N];
    int front = -1, rear = -1;
    int choice, item;
    do
    {
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display elements\n";
        cout << "4. Count number of elements\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element: ";
            cin >> item;
            enqueue(queue, &front, &rear, item);
            break;
        case 2:
            item = dequeue(queue, &front, &rear);
            if (item != -1)
                cout << "Dequeued element=" << item << endl;
            else
                cout << "Queue full\n";
            break;
        case 3:
            for (int i = front; i <= rear && i != -1; i++)
                cout << queue[i] << "\t";
            cout << endl;
            break;
        case 4:
            cout << "Number of elements=" << rear - front + 1 << endl;
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice >= 1 && choice <= 4);
    cout << "Number of elements=" << rear - front + 1 << endl;
    return 0;
}
void enqueue(int *queue, int *front, int *rear, int item)
{
    if (*rear == N - 1)
        return;
    if (*front == -1 && *rear == -1)
        (*front)++;
    queue[++*rear] = item;
}
int dequeue(int *queue, int *front, int *rear)
{
    if (*front == -1)
        return -1;
    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    return queue[(*front)++];
}