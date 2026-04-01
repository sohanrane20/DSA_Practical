// 7: Reverse linked list in groups of k
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *reverseListInGroups(struct Node *head, int k);
void displayList(struct Node *head);
int main()
{
	int n, i, k;
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
	printf("Elements of linked list are ");
	displayList(head);
	printf("\n");
	printf("Enter number of nodes in group: ");
	scanf("%d", &k);
	head = reverseListInGroups(head, k);
	printf("Elements of linked list are ");
	displayList(head);
	printf("\n");
	return 0;
}
struct Node *reverseListInGroups(struct Node *head, int k)
{
	int count;
	struct Node *ptr, *fast, *slow, *rev, *end, *temp;
	ptr = head;
	slow = fast = NULL;
	count = k;
	while (ptr != NULL && count != 0)
	{
		count--;
		fast = ptr;
		ptr = ptr->next;
		fast->next = slow;
		slow = fast;
	}
	rev = fast;
	while (ptr != NULL)
	{
		end = rev;
		while (end->next != NULL)
		{
			end = end->next;
		}
		slow = fast = NULL;
		count = k;
		while (ptr != NULL && count != 0)
		{
			count--;
			fast = ptr;
			ptr = ptr->next;
			fast->next = slow;
			slow = fast;
		}
		temp = fast;
		if (count != 0)
		{
			ptr = fast;
			slow = fast = NULL;
			while (ptr != NULL)
			{
				fast = ptr;
				ptr = ptr->next;
				fast->next = slow;
				slow = fast;
			}
			temp = fast;
		}
		end->next = temp;
	}
	return rev;
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
