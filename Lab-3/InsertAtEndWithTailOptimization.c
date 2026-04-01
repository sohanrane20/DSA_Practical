// 3: Insert at end with tail optimisation
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *insertAtEnd(struct Node *tail, int element);
void displayList(struct Node *head);
int main()
{
	int n, i, choice, element;
	struct Node *head, *tail, *newNode, *temp;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	if (n == 0)
	{
		head = tail = NULL;
	}
	else
	{
		newNode = (struct Node *)malloc(sizeof(struct Node));
		printf("Enter element 1: ");
		scanf("%d", &newNode->data);
		newNode->next = NULL;
		head = tail = newNode;
		temp = newNode;
		for (i = 2; i <= n; i++)
		{
			newNode = (struct Node *)malloc(sizeof(struct Node));
			printf("Enter element %d: ", i);
			scanf("%d", &newNode->data);
			newNode->next = NULL;
			tail = newNode;
			temp->next = newNode;
			temp = temp->next;
		}
	}
	do
	{
		printf("1: Insert at end\n");
		printf("2: Display list\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter element: ");
			scanf("%d", &element);
			tail = insertAtEnd(tail, element);
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
struct Node *insertAtEnd(struct Node *tail, int element)
{
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = element;
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
	return tail;
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
