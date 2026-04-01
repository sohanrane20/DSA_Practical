// Part A: 1. Implement stack using array
#include <iostream>
#define SIZE 10
using namespace std;
void push(int *stack, int *top, int x);
int pop(int *stack, int *top);
int peek(int *stack, int i);
bool isEmpty(int top);
bool isFull(int top);
int main()
{
    int *stack = new int[SIZE], top = -1, choice, element, position;
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
            push(stack, &top, element);
            break;
        case 2:
            element = pop(stack, &top);
            cout << "Popped element = " << element << endl;
            break;
        case 3:
            cout << "Enter position: ";
            cin >> position;
            cout << "Element = " << peek(stack, position) << endl;
            break;
        case 4:
            if (isEmpty(top))
            {
                cout << "Empty" << endl;
            }
            else
            {
                cout << "Not empty" << endl;
            }
            break;
        case 5:
            if (isFull(top))
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
    delete[] stack;
    return 0;
}
void push(int *stack, int *top, int x)
{
    if (*top == SIZE - 1)
    {
        cout << "Stack is full" << endl;
        return;
    }
    stack[++(*top)] = x;
}
int pop(int *stack, int *top)
{
    if (*top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        return stack[(*top)--];
    }
}
int peek(int *stack, int i)
{
    return stack[i];
}
bool isEmpty(int top)
{
    return top == -1;
}
bool isFull(int top)
{
    return top == SIZE - 1;
}