// A. 9. Clone doubly linked list with random pointers
#include <iostream>
using namespace std;
struct Node
{
    Node *previous;
    int data;
    Node *next;
    Node *random;
};
void displayList(Node *head);
Node *cloneList(Node *head);
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
    node1->previous = NULL;
    node1->random = node3;

    node2->data = 3;
    node2->next = node3;
    node2->previous = node1;
    node2->random = node3;

    node3->data = 5;
    node3->next = node4;
    node3->previous = node2;
    node3->random = NULL;

    node4->data = 9;
    node4->next = NULL;
    node4->previous = node3;
    node4->random = node3;

    Node *clone = cloneList(head);
    cout << "List cloned";
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
    Node *clone, *newNode, *temp, *originalNext, *duplicateNext, *duplicate, *original;

    clone = NULL;
    original = head;

    while (original != NULL)
    {
        newNode = new Node;
        newNode->data = original->data;
        newNode->next = NULL;
        newNode->previous = NULL;
        if (clone == NULL)
        {
            clone = newNode;
            temp = newNode;
        }
        else
        {
            newNode->previous = temp;
            temp->next = newNode;
            temp = newNode;
        }
        original = original->next;
    }

    duplicate = clone;
    original = head;

    while (duplicate != NULL)
    {
        originalNext = original->next;

        original->next = duplicate;
        duplicate->previous = original;

        duplicateNext = duplicate->next;

        duplicate->next = originalNext;

        if (originalNext != NULL)
        {
            originalNext->previous = duplicate;
        }

        original = originalNext;
        duplicate = duplicateNext;
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

    original = head;
    duplicate = head->next;

    while (original != NULL)
    {
        originalNext = original->next;
        original->next = originalNext->next;

        if (original->next != NULL)
        {
            original->next->previous = original;
        }

        if (duplicate->next != NULL)
        {
            duplicate->next = duplicate->next->next;

            if (duplicate->next != NULL)
            {
                duplicate->next->previous = duplicate;
            }
        }

        original = original->next;
        duplicate = duplicate->next;
    }
    return clone;
}