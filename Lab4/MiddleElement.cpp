// 1. Find the middle element of a singly linked list.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *findMiddleElement(struct Node *head);
int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct Node *head, *newNode, *temp;
    head = NULL;
    for (int i = 1; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter element %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    printf("Elements of linked list are ");
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    ptr = findMiddleElement(head);
    printf("Middle element is %d", ptr->data);
    return 0;
}
struct Node *findMiddleElement(struct Node *head)
{
    struct Node *p, *q;
    q = p = head;
    while (p != NULL && p->next != NULL)
    {
        q = q->next;
        p = p->next->next;
    }
    return q;
}