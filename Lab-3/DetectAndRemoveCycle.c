// 6: Detect and remove cycle
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
int detectCycle(struct Node *head);
struct Node *detectCycleStart(struct Node *head);
void removeCycle(struct Node *head);
void displayList(struct Node *head);
int main()
{
	int n, i, choice;
	struct Node *head, *node1, *node2, *node3, *node4, *node5;
	node1 = (struct Node *)malloc(sizeof(struct Node));
	node2 = (struct Node *)malloc(sizeof(struct Node));
	node3 = (struct Node *)malloc(sizeof(struct Node));
	node4 = (struct Node *)malloc(sizeof(struct Node));
	node5 = (struct Node *)malloc(sizeof(struct Node));
	node1->data = 1;
	node1->next = node2;
	head = node1;
	node2->data = 2;
	node2->next = node3;
	node3->data = 3;
	node3->next = node4;
	node4->data = 4;
	node4->next = node5;
	node5->data = 5;
	node5->next = node3;
	do
	{
		printf("1: Detect cycle\n");
		printf("2: Remove cycle\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			if (detectCycle(head))
			{
				printf("Linked list is cyclic\n");
			}
			else
			{
				printf("Linked list is not cyclic\n");
			}
			break;
		case 2:
			removeCycle(head);
			break;
		default:
			printf("Invalid choice\n");
		}
	} while (choice >= 1 && choice <= 2);
	return 0;
}
int detectCycle(struct Node *head)
{
	struct Node *slow, *fast;
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
struct Node *detectCycleStart(struct Node *head)
{
	struct Node *slow, *fast;
	slow = fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = (fast->next)->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}
	return NULL;
}
void removeCycle(struct Node *head)
{
	struct Node *ptr, *start;
	ptr = head;
	start = detectCycleStart(head);
	if (start == NULL)
	{
		return;
	}
	while (ptr->next != start)
	{
		ptr = ptr->next;
	}
	ptr->next = NULL;
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
