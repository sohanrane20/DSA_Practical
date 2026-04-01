// Part A: 5: Evaluate a postfix expression
#include <iostream>
#include <string.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void push(Node **head, int x);
int pop(Node **head);
bool isOperator(char chr);
int evaluatePostFix(Node **head, char *postfix);
int main()
{
    Node *head;
    head = NULL;
    char *postfix = (char *)"82/3-";
    int result = evaluatePostFix(&head, postfix);
    cout << result << endl;
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
bool isOperator(char chr)
{
    return chr == '+' || chr == '-' || chr == '*' || chr == '/';
}
int evaluatePostFix(Node **head, char *postfix)
{
    int i = 0, result;
    while (postfix[i] != '\0')
    {
        if (isOperator(postfix[i]))
        {
            int a = pop(head);
            int b = pop(head);
            switch (postfix[i])
            {
            case '+':
                result = b + a;
                break;
            case '-':
                result = b - a;
                break;
            case '*':
                result = b * a;
                break;
            case '/':
                result = b / a;
                break;
            }
            push(head, result);
        }
        else
        {
            push(head, postfix[i] - 48);
        }
        i++;
    }
    return (*head)->data;
}