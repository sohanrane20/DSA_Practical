// Part A: 2: Reverse a string using stack
#include <iostream>
#include <string.h>
using namespace std;
void push(char *stack, int *top, char x);
char pop(char *stack, int *top);
char peek(char *stack, int i);
bool isEmpty(int top);
bool isFull(int top);
void reverseString(char *str, int *top, char *stack);
int main()
{
    int top = -1;
    char *stack = new char[10];
    char str[30];
    cout << "Enter string: ";
    cin.getline(str, sizeof(str));
    reverseString(str, &top, stack);
    cout << str << endl;
    delete[] stack;
    return 0;
}
void push(char *stack, int *top, char x)
{
    if (*top == 9)
    {
        cout << "Stack is full" << endl;
        return;
    }
    stack[++(*top)] = x;
}
char pop(char *stack, int *top)
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
char peek(char *stack, int i)
{
    return stack[i];
}
bool isEmpty(int top)
{
    return top == -1;
}
bool isFull(int top)
{
    return top == 9;
}
void reverseString(char *str, int *top, char *stack)
{
    int i = 0;
    while (str[i] != '\0')
    {
        push(stack, top, str[i]);
        i++;
    }

    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = pop(stack, top);
    }
    str[i] = '\0';
}