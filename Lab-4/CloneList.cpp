// 4. Clone a linked list with next and random pointers.
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *random;
    Node *next;
};
Node *cloneList(Node *head);
void displayList(Node *head);
int main()
{
    Node *head, *node1, *node2, *node3, *node4;
    node1 = new Node;
    node2 = new Node;
    node3 = new Node;
    node4 = new Node;
    head = node1;
    node1->data = 1;
    node1->next = node2;
    node1->random = node3;
    node2->data = 3;
    node2->next = node3;
    node2->random = node3;
    node3->data = 5;
    node3->next = node4;
    node4->random = NULL;
    node4->data = 9;
    node4->next = NULL;
    node4->random = node3;
    Node *clone = cloneList(head);
    cout << "List cloned" << endl;
    return 0;
}
void displayList(Node *head)
{
    Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
}
Node *cloneList(Node *head)
{
    Node *clone, *newNode, *temp, *temp1, *temp2, *duplicate, *original;
    clone = NULL;
    original = head;
    while (original != NULL)
    {
        newNode = new Node;
        newNode->data = original->data;
        newNode->next = NULL;
        if (clone == NULL)
        {
            clone = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        original = original->next;
    }
    duplicate = clone;
    original = head;
    while (duplicate != NULL)
    {
        temp1 = original->next;
        original->next = duplicate;
        temp2 = duplicate->next;
        duplicate->next = temp1;
        original = temp1;
        duplicate = temp2;
    }
    original = head;
    while (original != NULL && original->next != NULL)
    {
        if (original->random != NULL)
        {
            original->next->random = original->random->next;
        }
        original = original->next->next;
    }
    original = head, duplicate = head->next;
    while (original != NULL)
    {
        temp = original->next;
        original->next = temp->next;
        if (duplicate->next != NULL)
        {
            duplicate->next = duplicate->next->next;
        }
        original = original->next;
        duplicate = duplicate->next;
    }
    return clone;
}