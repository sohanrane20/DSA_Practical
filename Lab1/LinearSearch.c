/*
7: ​Perform a Linear Search for a specific key entered by the
user.
*/
#include <stdio.h>
void readArray(int[], int);
void writeArray(int[], int);
void searchElement(int[], int, int);
int main()
{
	int n, num;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter elements: ");
	readArray(arr, n);
	printf("Elements: \n");
	writeArray(arr, n);
	printf("\nEnter element to search: ");
	scanf("%d", &num);
	searchElement(arr, n, num);
	return 0;
}
void readArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
}
void writeArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
}
void searchElement(int arr[], int n, int num)
{
	int i, flag = 0, loc;
	for (i = 0; i < n && flag == 0; i++)
	{
		if (arr[i] == num)
		{
			loc = i;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		printf("Element was not found\n");
	}
	else
	{
		printf("Element was found at location %d\n", loc);
	}
}
