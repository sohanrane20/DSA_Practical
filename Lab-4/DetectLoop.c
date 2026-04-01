// 2. Detect a loop in a singly linked list.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int detectLoop(struct Node *head);
struct Node *detectLoopStart(struct Node *head);
int main()
{
    struct Node *head, *node1, *node2, *node3;
    node1 = (struct Node *)malloc(sizeof(struct Node));
    node2 = (struct Node *)malloc(sizeof(struct Node));
    node3 = (struct Node *)malloc(sizeof(struct Node));
    node1->data = 1;
    node1->next = node2;
    node2->data = 3;
    node2->next = node3;
    node3->data = 4;
    node3->next = node2;
    head = node1;
    if (detectLoop(head))
    {
        printf("Loop start detected at the node whose data is %d\n", detectLoopStart(head)->data);
    }
    else
    {
        printf("Loop not detected\n");
    }
    return 0;
}
int detectLoop(struct Node *head)
{
    struct Node *slow, *fast;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}
struct Node *detectLoopStart(struct Node *head)
{
    struct Node *slow, *fast;
    slow = fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}