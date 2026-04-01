// Part A: 4: Convert infix expression to postfix
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
char *convertInfixToPostfix(Node **head, char *infix);
bool hasHigherPriority(char operator1, char operator2);
int main()
{
    Node *head;
    head = NULL;
    char *infix = (char *)"(A+B)*(C-D)";
    char *postfix = convertInfixToPostfix(&head, infix);
    cout << postfix << endl;
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
bool hasHigherPriority(char operator1, char operator2)
{
    if (operator1 == operator2)
    {
        return false;
    }
    else
    {
        if (operator1 == '*' || operator1 == '/')
        {
            return true;
        }
        else if (operator1 == '+' || operator2 == '-')
        {
            return false;
        }
    }
}
char *convertInfixToPostfix(Node **head, char *infix)
{
    push(head, '(');
    int i = 0, loc = 0;
    char *postfix = new char[strlen(infix)];
    while (infix[i] != '\0')
    {
        if (infix[i] == '(')
        {
            push(head, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((*head)->data != '(')
            {
                postfix[loc++] = (*head)->data;
                pop(head);
            }
            pop(head);
        }
        else if (isOperator(infix[i]))
        {
            if (isOperator((*head)->data))
            {
                if (hasHigherPriority(infix[i], (*head)->data))
                {
                    push(head, infix[i]);
                }
                else
                {
                    while (isOperator((*head)->data) && hasHigherPriority((*head)->data, infix[i]))
                    {
                        postfix[loc++] = (*head)->data;
                        pop(head);
                    }
                    push(head, infix[i]);
                }
            }
            else
            {
                push(head, infix[i]);
            }
        }
        else
        {
            postfix[loc++] = infix[i];
        }
        i++;
    }
    while ((*head)->data != '(')
    {
        postfix[loc++] = (*head)->data;
        pop(head);
    }
    postfix[loc] = '\0';
    return postfix;
}