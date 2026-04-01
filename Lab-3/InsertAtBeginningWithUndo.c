// 2: Insert at beginning with undo capability
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *insertAtBeginning(struct Node *head, int element);
struct Node *undo(const struct Node *originalHead, struct Node *head);
void displayList(struct Node *head);
int main()
{
	int n, i, choice, element;
	const struct Node *originalHead;
	struct Node *head, *newNode, *temp;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	if (n == 0)
	{
		originalHead = head = NULL;
	}
	else
	{
		newNode = (struct Node *)malloc(sizeof(struct Node));
		printf("Enter element 1: ");
		scanf("%d", &newNode->data);
		newNode->next = NULL;
		originalHead = head = newNode;
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
		printf("1. Insert at beginning\n");
		printf("2. Undo\n");
		printf("3. Display list\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter element: ");
			scanf("%d", &element);
			head = insertAtBeginning(head, element);
			break;
		case 2:
			head = undo(originalHead, head);
			break;
		case 3:
			printf("Elements of list are ");
			displayList(head);
			printf("\n");
			break;
		default:
			printf("Invalid choice\n");
		}
	} while (choice >= 1 && choice <= 3);
	return 0;
}
struct Node *insertAtBeginning(struct Node *head, int element)
{
	struct Node *newNode;
	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = element;
	newNode->next = head;
	head = newNode;
	return head;
}
struct Node *undo(const struct Node *originalHead, struct Node *head)
{
	if (originalHead == head)
	{
		return head;
	}
	else
	{
		struct Node *temp;
		temp = head;
		head = temp->next;
		free(temp);
		return head;
	}
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
