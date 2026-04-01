/*
3: Given a 3x3 matrix, print the elements and their memory
addresses. Demonstrate that in C, the address of A[0][1]
follows immediately after A[0][0], proving Row-Major storage.
*/
#include <stdio.h>
int main()
{
	int matrix[3][3], i, j;
	printf("Enter elements: ");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("Elements are \n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("Addresses of elements are \n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%u\t", &matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
