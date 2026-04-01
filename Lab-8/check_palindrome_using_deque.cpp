// 4. Check palindrome using deque
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void insert_front(Node **front, Node **rear, int item);
void insert_rear(Node **front, Node **rear, int item);
int delete_front(Node **front, Node **rear);
int delete_rear(Node **front, Node **rear);
bool is_palindrome(Node **front, Node **rear, char *str);
int main()
{
    Node *front = NULL, *rear = NULL;
    char str[30];
    cout << "Enter string: ";
    cin >> str;
    if (is_palindrome(&front, &rear, str))
        cout << "Palindrome\n";
    else
        cout << "Not palindrome\n";
    return 0;
}
void insert_front(Node **front, Node **rear, int item)
{
    Node *new_node = new Node;
    if (new_node == NULL)
        return;
    new_node->data = item;
    new_node->next = *front;
    *front = new_node;
}
void insert_rear(Node **front, Node **rear, int item)
{
    Node *new_node = new Node;
    if (new_node == NULL)
        return;
    new_node->data = item;
    new_node->next = NULL;
    if (*front == NULL && *rear == NULL)
    {
        *front = new_node;
        *rear = new_node;
    }
    else
    {
        (*rear)->next = new_node;
        *rear = new_node;
    }
}
int delete_front(Node **front, Node **rear)
{
    if (*front == NULL)
        return -1;
    int item = (*front)->data;
    if (*front == *rear)
    {
        delete *front;
        *front = NULL;
        *rear = NULL;
    }
    else
    {
        Node *temp = *front;
        *front = (*front)->next;
        delete temp;
    }
    return item;
}
int delete_rear(Node **front, Node **rear)
{
    if (*front == NULL)
        return -1;
    int item = (*rear)->data;
    if (*front == *rear)
    {
        *front = NULL;
        delete *rear;
        *rear = NULL;
    }
    else
    {
        Node *p = *front, *q = *front;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        *rear = q;
        delete p;
    }
    return item;
}
bool is_palindrome(Node **front, Node **rear, char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        insert_rear(front, rear, str[i]);
        i++;
    }
    while (*front != NULL && *rear != NULL)
    {
        if (*front == *rear || (*front)->next == *rear)
            break;
        int f = delete_front(front, rear), r = delete_rear(front, rear);
        if (f != r)
            return false;
    }
    return true;
}