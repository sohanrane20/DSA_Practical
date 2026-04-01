// 6. Check whether a singly linked list is a palindrome.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *reverseList(struct Node *head);
int isPalindrome(struct Node *head);
int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct Node *head, *newNode, *temp;
    head = NULL;
    temp = NULL;
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
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    if (isPalindrome(head))
    {
        printf("\nPalindrome\n");
    }
    else
    {
        printf("\nNot palindrome\n");
    }
    return 0;
}
struct Node *reverseList(struct Node *head)
{
    struct Node *p, *q, *ptr;
    ptr = head;
    q = p = NULL;
    while (ptr != NULL)
    {
        p = ptr;
        ptr = ptr->next;
        p->next = q;
        q = p;
    }
    head = p;
    return head;
}
int isPalindrome(struct Node *head)
{
    struct Node *q, *p;
    q = p = head;
    while (p != NULL && p->next != NULL)
    {
        q = q->next;
        p = p->next->next;
    }
    q = reverseList(q);
    p = head;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            return 0;
        }
        p = p->next;
        q = q->next;
    }
    return 1;
}