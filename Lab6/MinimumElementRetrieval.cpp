// Part A: 6: Design stack with minimum element retrieval
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *minimumBelow;
};
void push(Node **head, int x);
int pop(Node **head);
int findMinimum(Node *head);
int main()
{
    Node *head = NULL;
    push(&head, 6);
    push(&head, 2);
    push(&head, 9);
    cout << "Minimum = " << findMinimum(head) << endl;
    return 0;
}
void push(Node **head, int x)
{
    Node *newNode;
    newNode = new Node;
    if (newNode == NULL)
    {
        cout << "Stack is full" << endl;
        return;
    }
    newNode->data = x;
    newNode->next = *head;
    if (*head == NULL)
    {
        newNode->minimumBelow = newNode;
    }
    else
    {
        if (newNode->data < (*head)->minimumBelow->data)
        {
            newNode->minimumBelow = newNode;
        }
        else
        {
            newNode->minimumBelow = (*head)->minimumBelow;
        }
    }
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
        Node *temp = *head;
        *head = (*head)->next;
        int y = temp->data;
        delete temp;
        return y;
    }
}
int findMinimum(Node *head)
{
    return head->minimumBelow->data;
}