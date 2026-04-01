// 1: a: Array operations in C
#include <stdio.h>
#include <stdlib.h>
void readArray(int mainArray[], int size);
void printArray(int mainArray[], int size);
int insertElement(int mainArray[], int size, int element, int position);
int deleteElement(int mainArray[], int size, int position);
void reverseArray(int mainArray[], int size);
void reverseArrayInPlace(int mainArray[], int size);
int addElements(int mainArray[], int size);
int addElementsRecursively(int mainArray[], int size);
void searchElement(int mainArray[], int size, int element);
int main()
{
    int choice;
    int mainArray[20], subArray1[10], subArray2[10];
    int size;
    int element, position;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    readArray(mainArray, size);
    printArray(mainArray, size);
    do
    {
        printf("\n1: Insert element at end\n");
        printf("2: Insert element at beginning\n");
        printf("3: Insert element at given position\n");
        printf("4: Delete last element\n");
        printf("5: Delete first element\n");
        printf("6: Delete element at given position\n");
        printf("7: Reverse array using temporary array\n");
        printf("8: Reverse array without using temporary array\n");
        printf("9: Display sum of all elements using recursion\n");
        printf("10: Display sum of all elements without using recursion\n");
        printf("11: Search element\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &element);
            size = insertElement(mainArray, size, element, size);
            printArray(mainArray, size);
            break;
        case 2:
            printf("Enter element: ");
            scanf("%d", &element);
            size = insertElement(mainArray, size, element, 0);
            printArray(mainArray, size);
            break;
        case 3:
            printf("Enter element: ");
            scanf("%d", &element);
            printf("Enter position: ");
            scanf("%d", &position);
            size = insertElement(mainArray, size, element, position);
            printArray(mainArray, size);
            break;
        case 4:
            size = deleteElement(mainArray, size, size - 1);
            printArray(mainArray, size);
            break;
        case 5:
            size = deleteElement(mainArray, size, 0);
            printArray(mainArray, size);
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &position);
            size = deleteElement(mainArray, size, position);
            printArray(mainArray, size);
            break;
        case 7:
            reverseArray(mainArray, size);
            printArray(mainArray, size);
            break;
        case 8:
            reverseArrayInPlace(mainArray, size);
            printArray(mainArray, size);
            break;
        case 9:
            printf("Sum of all elements is %d", addElements(mainArray, size));
            break;
        case 10:
            printf("Sum of all elements is %d", addElementsRecursively(mainArray, size));
            break;
        case 11:
            printf("Enter element to search: ");
            scanf("%d", &element);
            searchElement(mainArray, size, element);
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice >= 1 && choice <= 11);
    return 0;
}
void readArray(int mainArray[], int size)
{
    printf("Enter elements of array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &mainArray[i]);
    }
}
void printArray(int mainArray[], int size)
{
    printf("Elements of array are ");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", mainArray[i]);
    }
}
int insertElement(int mainArray[], int size, int element, int position)
{
    for (int i = size - 1; i >= position; i--)
    {
        mainArray[i + 1] = mainArray[i];
    }
    mainArray[position] = element;
    return size + 1;
}
int deleteElement(int mainArray[], int size, int position)
{
    for (int i = position; i < 20; i++)
    {
        mainArray[i] = mainArray[i + 1];
    }
    return size - 1;
}
void reverseArray(int mainArray[], int size)
{
    int temp[size];
    for (int i = 0; i < size; i++)
    {
        temp[size - i - 1] = mainArray[i];
    }
    for (int i = 0; i < size; i++)
    {
        mainArray[i] = temp[i];
    }
}
void reverseArrayInPlace(int mainArray[], int size)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int temp = mainArray[left];
        mainArray[left] = mainArray[right];
        mainArray[right] = temp;
        left++;
        right--;
    }
}
int addElements(int mainArray[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += mainArray[i];
    }
    return sum;
}
int addElementsRecursively(int mainArray[], int size)
{
    if (size == 0)
        return 0;
    return mainArray[size - 1] + addElementsRecursively(mainArray, size - 1);
}
void searchElement(int mainArray[], int size, int element)
{
    int position, flag = 0;
    for (int i = 0; i < size && flag == 0; i++)
    {
        if (mainArray[i] == element)
        {
            position = i;
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("Element was found at %d\n", position);
    }
    else
    {
        printf("Element was not found\n");
    }
}