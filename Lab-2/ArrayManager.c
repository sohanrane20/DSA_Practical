// 1: b: Array operations in C
#include <stdio.h>
#include <stdlib.h>
void readArray(int mainArray[], int size);
void printArray(int mainArray[], int size);
void copySubArray(int mainArray[], int subArray[]);
void mergeArrays(int mainArray[], int subArray1[], int subArray2[]);
void separateEvenAndOdd(int mainArray[], int size, int subArray1[], int subArray2[]);
void separatePositiveAndNegative(int mainArray[], int size, int subArray1[], int subArray2[]);
int main()
{
    int choice;
    int mainArray[20], subArray1[10], subArray2[10];
    int size;
    do
    {
        printf("\n1: Copy sub array\n");
        printf("2: Merge two arrays\n");
        printf("3: Separate even and odd numbers\n");
        printf("4: Separate positive and negative numbers\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter elements of sub array: ");
            readArray(subArray1, 10);
            printf("Elements of sub array are ");
            printArray(subArray1, 10);
            copySubArray(mainArray, subArray1);
            printf("\nElements of main array are ");
            printArray(mainArray, 10);
            break;
        case 2:
            printf("Enter elements of sub array 1: ");
            readArray(subArray1, 10);
            printf("Elements of sub array 1 are ");
            printArray(subArray1, 10);
            printf("\nEnter elements of sub array 2: ");
            readArray(subArray2, 10);
            printf("Elements of sub array 2 are ");
            printArray(subArray2, 10);
            mergeArrays(mainArray, subArray1, subArray2);
            printf("\nElements of main array are ");
            printArray(mainArray, 20);
            break;
        case 3:
            printf("Enter number of elements: ");
            scanf("%d", &size);
            printf("Enter elements of main array: ");
            readArray(mainArray, size);
            printf("Elements of main array are ");
            printArray(mainArray, size);
            separateEvenAndOdd(mainArray, size, subArray1, subArray2);
            break;
        case 4:
            printf("Enter number of elements in main array: ");
            scanf("%d", &size);
            readArray(mainArray, size);
            printArray(mainArray, size);
            separatePositiveAndNegative(mainArray, size, subArray1, subArray2);
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice >= 1 && choice <= 4);
    return 0;
}
void readArray(int mainArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &mainArray[i]);
    }
}
void printArray(int mainArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", mainArray[i]);
    }
}
void copySubArray(int mainArray[], int subArray[])
{
    for (int i = 0; i < 10; i++)
    {
        mainArray[i] = subArray[i];
    }
}
void mergeArrays(int mainArray[], int subArray1[], int subArray2[])
{
    int temp, j, i = 0;
    for (j = 0; j < 10; j++)
    {
        mainArray[i] = subArray1[j];
        i++;
    }
    for (j = 0; j < 10; j++)
    {
        mainArray[i] = subArray2[j];
        i++;
    }
    for (i = 0; i < 20; i++)
    {
        for (j = i + 1; j < 20; j++)
        {
            if (mainArray[i] < mainArray[j])
            {
                temp = mainArray[i];
                mainArray[i] = mainArray[j];
                mainArray[j] = temp;
            }
        }
    }
}
void separateEvenAndOdd(int mainArray[], int size, int subArray1[], int subArray2[])
{
    int j = 0, k = 0;
    for (int i = 0; i < size; i++)
    {
        if (mainArray[i] % 2 == 0)
        {
            subArray1[j] = mainArray[i];
            j++;
        }
        else
        {
            subArray2[k] = mainArray[i];
            k++;
        }
    }
    printf("\nEven numbers in sub array 1 are ");
    for (int i = 0; i < j; i++)
    {
        printf("%d\t", subArray1[i]);
    }
    printf("\nOdd numbers in sub array 2 are ");
    for (int i = 0; i < k; i++)
    {
        printf("%d\t", subArray2[i]);
    }
}
void separatePositiveAndNegative(int mainArray[], int size, int subArray1[], int subArray2[])
{
    int j = 0, k = 0;
    for (int i = 0; i < size; i++)
    {
        if (mainArray[i] > 0)
        {
            subArray1[j] = mainArray[i];
            j++;
        }
        else if (mainArray[i] < 0)
        {
            subArray2[k] = mainArray[i];
            k++;
        }
    }
    printf("\nPositive numbers in sub array 1 are ");
    for (int i = 0; i < j; i++)
    {
        printf("%d\t", subArray1[i]);
    }
    printf("\nNegative numbers in sub array 2 are ");
    for (int i = 0; i < k; i++)
    {
        printf("%d\t", subArray2[i]);
    }
}