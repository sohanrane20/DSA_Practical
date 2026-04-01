// 10. Flatten a linked list having next and bottom pointers into a single sorted list.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;
};
struct Node *flattenList(struct Node *head);
struct Node *mergeLists(struct Node *head1, struct Node *head2);
int main()
{
    int i;
    struct Node *result, *head, *nodes[10];
    for (int i = 0; i < 10; i++)
    {
        nodes[i] = (struct Node*)malloc(sizeof(struct Node));
    }

    head = nodes[0];

    nodes[0]->data = 5;
    nodes[0]->next = nodes[1];
    nodes[0]->bottom = nodes[4];

    nodes[1]->data = 10;
    nodes[1]->next = nodes[2];
    nodes[1]->bottom = nodes[6];

    nodes[2]->data = 19;
    nodes[2]->next = nodes[3];
    nodes[2]->bottom = nodes[7];

    nodes[3]->data = 28;
    nodes[3]->next = NULL;
    nodes[3]->bottom = nodes[8];

    nodes[4]->data = 7;
    nodes[4]->next = NULL;
    nodes[4]->bottom = nodes[5];

    nodes[5]->data = 8;
    nodes[5]->next = NULL;
    nodes[5]->bottom = NULL;

    nodes[6]->data = 20;
    nodes[6]->next = NULL;
    nodes[6]->bottom = NULL;

    nodes[7]->data = 22;
    nodes[7]->next = NULL;
    nodes[7]->bottom = NULL;

    nodes[8]->data = 40;
    nodes[8]->next = NULL;
    nodes[8]->bottom = nodes[9];

    nodes[9]->data = 45;
    nodes[9]->next = NULL;
    nodes[9]->bottom = NULL;

    result = flattenList(head);
    struct Node *ptr;
    ptr = result;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->bottom;
    }
    return 0;
}
struct Node *flattenList(struct Node *head)
{
    struct Node *ptr, *result;
    result = head;
    ptr = head->next;
    result->next = NULL;
    while (ptr != NULL) 
    {
        struct Node *temp = ptr->next;
        ptr->next = NULL;
        result = mergeLists(result, ptr);
        ptr = temp;
    }
    return result;
}
struct Node *mergeLists(struct Node *head1, struct Node *head2) 
{
    struct Node *head, *ptr, *p, *q;
    p = head1;
    q = head2;
    if (p->data <= q->data) {
        ptr = p;
        p = p->bottom;
    } else {
        ptr = q;
        q = q->bottom;
    }
    ptr->bottom = NULL;
    head = ptr;
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            ptr->bottom = p;
            p = p->bottom;
        } else {
            ptr->bottom = q;
            q = q->bottom;
        }
        ptr = ptr->bottom;
    }
    if (p != NULL) {
        ptr->bottom = p;
    } else if (q != NULL) {
        ptr->bottom = q;
    }
    return head;
}