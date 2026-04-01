// Part A: 3: Check for balanced paranthesis
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void push(Node **head, int x);
int pop(Node **head);
bool isOpeningBracket(char chr);
bool isClosingBracket(char chr);
bool hasBalancedParanthesis(Node **head, char *expression);
int main()
{
    Node *head;
    head = NULL;
    char *expression = (char *)"[(a+b)*{c+d}]";
    if (hasBalancedParanthesis(&head, expression))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not balanced" << endl;
    }
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
bool isOpeningBracket(char chr)
{
    return chr == '(' || chr == '{' || chr == '[';
}
bool isClosingBracket(char chr)
{
    return chr == ')' || chr == '}' || chr == ']';
}
bool hasBalancedParanthesis(Node **head, char *expression)
{
    int i = 0;
    while (expression[i] != '\0')
    {
        if (isOpeningBracket(expression[i]))
        {
            push(head, expression[i]);
        }
        else if (isClosingBracket(expression[i]))
        {
            if (*head != NULL && (*head)->data == '(' && expression[i] == ')')
            {
                pop(head);
            }
            else if (*head != NULL && (*head)->data == '{' && expression[i] == '}')
            {
                pop(head);
            }
            else if (*head != NULL && (*head)->data == '[' && expression[i] == ']')
            {
                pop(head);
            }
            else
            {
                return false;
            }
        }
        i++;
    }
    return *head == NULL;
}