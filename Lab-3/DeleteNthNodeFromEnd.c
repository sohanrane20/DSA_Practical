// 5: Delete nth node from end in one pass only
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *deleteNthNodeFromEnd(struct Node *head, int n);
void displayList(struct Node *head);
int main()
{
	int n, i, choice, k;
	struct Node *head, *newNode, *temp;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	if (n == 0)
	{
		head = NULL;
	}
	else
	{
		newNode = (struct Node *)malloc(sizeof(struct Node));
		printf("Enter element 1: ");
		scanf("%d", &newNode->data);
		newNode->next = NULL;
		head = newNode;
		temp = newNode;
		for (i = 2; i <= n; i++)
		{
			newNode = (struct Node *)malloc(sizeof(struct Node));
			printf("Enter element %d: ", i);
			scanf("%d", &newNode->data);
			newNode->next = NULL;
			temp->next = newNode;
			temp = temp->next;
		}
	}
	do
	{
		printf("1: Delete nth node from end\n");
		printf("2: Display list\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter position of node from end: ");
			scanf("%d", &k);
			head = deleteNthNodeFromEnd(head, k);
			break;
		case 2:
			printf("Elements of list are ");
			displayList(head);
			printf("\n");
			break;
		default:
			printf("Invalid choice\n");
		}
	} while (choice >= 1 && choice <= 2);
	return 0;
}
struct Node *deleteNthNodeFromEnd(struct Node *head, int n)
{
	struct Node *p, *q, *r;
	r = q = p = head;
	while (p->next != NULL && n != 0)
	{
		n--; // 3-1, 2-2, 1-3, 0-4
		p = p->next;
	}
	while (p->next != NULL && p != NULL)
	{
		r = q;
		q = q->next;
		p = p->next;
	}
	if (r == q)
	{
		head = q->next;
		free(q);
	}
	else
	{
		r->next = q->next;
		free(q);
	}
	return head;
}
void displayList(struct Node *head)
{
	struct Node *ptr;
	ptr = head;
	while (ptr != NULL)
	{
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
}
