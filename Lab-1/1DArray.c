/*
4: Program to store N integers in a 1D array.
5: Find the maximum and minimum elements.
6: Calculate the average of all elements.
*/
#include <stdio.h>
void readArray(int[], int);
void writeArray(int[], int);
int findMaximum(int[], int);
int findMinimum(int[], int);
float calculateAverage(int[], int);
int main()
{
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter elements: ");
	readArray(arr, n);
	printf("Elements are ");
	writeArray(arr, n);
	printf("\nMaximum element is %d\n", findMaximum(arr, n));
	printf("Minimum element is %d\n", findMinimum(arr, n));
	printf("Average is %f\n", calculateAverage(arr, n));
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
int findMaximum(int arr[], int n)
{
	int i, max = arr[0];
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
int findMinimum(int arr[], int n)
{
	int i, min = arr[0];
	for (i = 0; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}
float calculateAverage(int arr[], int n)
{
	int i, sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return ((float)sum) / n;
}
