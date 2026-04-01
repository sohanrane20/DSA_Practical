// 5. Reverse a singly linked list in groups of size k
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
	head = NULL;
	for (i = 1; i <= n; i++)
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
	displayList(head);
	printf("\n");
	printf("Enter number of nodes in group: ");
	scanf("%d", &k);
	head = reverseListInGroups(head, k);
	displayList(head);
	printf("\n");
	return 0;
}
struct Node *reverseListInGroups(struct Node *head, int k)
{
	int count;
	struct Node *ptr, *fast, *slow, *rev, *p, *q;
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
		p = rev;
		while (p->next != NULL)
		{
			p = p->next;
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
		q = fast;
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
			q = fast;
		}
		p->next = q;
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