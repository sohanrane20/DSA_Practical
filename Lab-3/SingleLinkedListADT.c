// 1: Design a fully featured singly linked list ADT
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *insertAtHead(struct Node *head, int element);
struct Node *insertAtTail(struct Node *head, int element);
struct Node *deleteByValue(struct Node *head, int element);
struct Node *deleteByPosition(struct Node *head, int position);
struct Node *searchForValue(struct Node *head, int element);
struct Node *reverseList(struct Node *head);
void displayList(struct Node *head);
int detectCycle(struct Node *head);
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
		printf("1: Insert at head\n");
		printf("2: Insert at tail\n");
		printf("3: Delete by value\n");
		printf("4: Delete by position\n");
		printf("5: Search for value\n");
		printf("6: Reverse list\n");
		printf("7: Display list\n");
		printf("8: Detect cycle\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter element: ");
			scanf("%d", &element);
			head = insertAtHead(head, element);
			break;
		case 2:
			printf("Enter element: ");
			scanf("%d", &element);
			head = insertAtTail(head, element);
			break;
		case 3:
			printf("Enter element: ");
			scanf("%d", &element);
			head = deleteByValue(head, element);
			break;
		case 4:
			printf("Enter position: ");
			scanf("%d", &position);
			head = deleteByPosition(head, position);
			break;
		case 5:
			printf("Enter element: ");
			scanf("%d", &element);
			printf("Element found at %u\n", searchForValue(head, element));
			break;
		case 6:
			head = reverseList(head);
			break;
		case 7:
			printf("Elements of list are ");
			displayList(head);
			printf("\n");
			break;
		case 8:
			if (detectCycle(head))
			{
				printf("Linked list is cyclic\n");
			}
			else
			{
				printf("Linked list is not cyclic\n");
			}
			break;
		default:
			printf("Invalid choice\n");
		}
	} while (choice >= 1 && choice <= 8);
	return 0;
}
struct Node *insertAtHead(struct Node *head, int element)
{
	struct Node *newNode;
	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = element;
	newNode->next = head;
	head = newNode;
	return head;
}
struct Node *insertAtTail(struct Node *head, int element)
{
	struct Node *newNode, *ptr;
	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = element;
	newNode->next = NULL;
	ptr = head;
	if (head == NULL)
	{
		head = newNode;
		return head;
	}
	else
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newNode;
		return head;
	}
}
struct Node *deleteByValue(struct Node *head, int element)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct Node *fast, *slow;
	slow = fast = head;
	while (fast->data != element && fast->next != NULL)
	{
		slow = fast;
		fast = fast->next;
	}
	if (slow == fast)
	{
		head = fast->next;
		free(fast);
	}
	if (fast->data == element)
	{
		slow->next = fast->next;
		free(fast);
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
		return head;
	}
}
struct Node *searchForValue(struct Node *head, int element)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct Node *ptr;
	ptr = head;
	while (ptr->data != element && ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	if (ptr->data == element)
	{
		return ptr;
	}
}
struct Node *reverseList(struct Node *head)
{
	struct Node *ptr, *fast, *slow;
	ptr = head;
	slow = fast = NULL;
	while (ptr != NULL)
	{
		fast = ptr;
		ptr = ptr->next;
		fast->next = slow;
		slow = fast;
	}
	head = fast;
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
int detectCycle(struct Node *head)
{
	struct Node *fast, *slow;
	slow = fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = (fast->next)->next;
		if (slow == fast)
		{
			return 1;
		}
	}
	return 0;
}
