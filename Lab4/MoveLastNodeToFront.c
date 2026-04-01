// 7. Move the last node of a linked list to the front
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *moveLastNodeToFront(struct Node *head);
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
    head = moveLastNodeToFront(head);
    printf("\nElements of linked list after moving last node to front are ");
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}
struct Node *moveLastNodeToFront(struct Node *head)
{
    struct Node *fast, *slow;
    slow = fast = head;
    while (fast->next != NULL)
    {
        slow = fast;
        fast = fast->next;
    }
    slow->next = NULL;
    fast->next = head;
    head = fast;
    return head;
}