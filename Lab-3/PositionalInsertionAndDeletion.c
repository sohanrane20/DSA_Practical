// 4: Position based insertion and deletion
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *insertAtPosition(struct Node *head, int element, int position);
struct Node *deleteByPosition(struct Node *head, int position);
void displayList(struct Node *head);
int main()
{
	int n, i, choice, element, position;
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
		printf("1: Insert at position\n");
		printf("2: Delete by position\n");
		printf("3: Display list\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter element: ");
			scanf("%d", &element);
			printf("Enter position: ");
			scanf("%d", &position);
			head = insertAtPosition(head, element, position);
			break;
		case 2:
			printf("Enter position: ");
			scanf("%d", &position);
			head = deleteByPosition(head, position);
			break;
		case 3:
			printf("Elements of linked list are ");
			displayList(head);
			printf("\n");
			break;
		default:
			printf("Invalid choice\n");
		}
	} while (choice >= 1 && choice <= 8);
	return 0;
}
struct Node *insertAtPosition(struct Node *head, int element, int position)
{
	struct Node *newNode;
	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = element;
	int i;
	struct Node *fast, *slow;
	slow = fast = head;
	for (i = 0; i < position && fast != NULL; i++)
	{
		slow = fast;
		fast = fast->next;
	}
	if (slow == fast)
	{
		newNode->next = head;
		head = newNode;
		return head;
	}
	if (i == position)
	{
		slow->next = newNode;
		newNode->next = fast;
	}
	return head;
}
struct Node *deleteByPosition(struct Node *head, int position)
{
	if (head == NULL)
	{
		return NULL;
	}
	int i;
	struct Node *fast, *slow;
	slow = fast = head;
	for (i = 0; i < position && fast->next != NULL; i++)
	{
		slow = fast;
		fast = fast->next;
	}
	if (slow == fast)
	{
		head = fast->next;
		free(fast);
		return head;
	}
	if (i == position)
	{
		slow->next = fast->next;
		free(fast);
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
