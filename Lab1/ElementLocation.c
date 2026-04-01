/*
8: Write a C program to calculate the physical memory address of
an element A[i][j] using both Row-Major and Column-Major
formulas and verify it against the actual address in memory
*/
#include <stdio.h>
void readArray(int[], int);
void writeArray(int[], int);
int rowMajorOrderFormula(int baseAddress, int row, int col, int i, int j);
int columnMajorOrderFormula(int baseAddress, int row, int col, int m, int n);
int main()
{
	int row, col, i, j, m, n;
	printf("Enter number of rows: ");
	scanf("%d", &row);
	printf("Enter number of columns: ");
	scanf("%d", &col);
	int arr[row][col];
	printf("Enter elements: ");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	printf("Elements are \n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter row number of element: ");
	scanf("%d", &m);
	printf("Enter column number of element: ");
	scanf("%d", &n);
	printf("Memory address is %u\n", &arr[m][n]);
	printf("Address calculated by row major order formula is %u\n", rowMajorOrderFormula((int)arr, row, col, m, n));
	printf("Address calculated by column major order formula is %u\n", columnMajorOrderFormula((int)arr, row, col, m, n));
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
int rowMajorOrderFormula(int baseAddress, int row, int col, int m, int n)
{
	return baseAddress + ((m * col + n) * sizeof(int));
}
int columnMajorOrderFormula(int baseAddress, int row, int col, int m, int n)
{
	return baseAddress + ((n * row + m) * sizeof(int));
}
