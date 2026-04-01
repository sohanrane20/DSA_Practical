// 9. Find the intersection point of two singly linked lists.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *findIntersectionPoint(struct Node *head1, struct Node *head2);
int main()
{
    struct Node *head1, *head2, *node1, *node2, *node3, *node4, *node5, *node6, *node7;
    node1 = (struct Node *)malloc(sizeof(struct Node));
    node2 = (struct Node *)malloc(sizeof(struct Node));
    node3 = (struct Node *)malloc(sizeof(struct Node));
    node4 = (struct Node *)malloc(sizeof(struct Node));
    node5 = (struct Node *)malloc(sizeof(struct Node));
    node6 = (struct Node *)malloc(sizeof(struct Node));
    node7 = (struct Node *)malloc(sizeof(struct Node));
    head1 = node1;
    node1->data = 4;
    node1->next = node2;
    node2->data = 1;
    node2->next = node3;
    node3->data = 8;
    node3->next = node4;
    node4->data = 5;
    node4->next = NULL;
    head2 = node5;
    node5->data = 5;
    node5->next = node6;
    node6->data = 6;
    node6->next = node7;
    node7->data = 1;
    node7->next = node3;
    printf("The intersection point is the node whose data is %d\n", findIntersectionPoint(head1, head2)->data);
    return 0;
}
struct Node *findIntersectionPoint(struct Node *head1, struct Node *head2)
{
    struct Node *p, *q;
    p = head1;
    while (p != NULL)
    {
        q = head2;
        while (q != NULL)
        {
            if (q == p)
            {
                return q;
            }
            q = q->next;
        }
        p = p->next;
    }
    return NULL;
}