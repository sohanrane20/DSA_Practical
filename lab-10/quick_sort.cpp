#include <iostream>
using namespace std;
int partition(int arr[], int beg, int end);
void quick_sort(int arr[], int beg, int end);
int main()
{
    int arr[8] = {9, 6, 5, 0, 8, 2, 4, 7};
    quick_sort(arr, 0, 7);
    for (int i = 0; i < 8; i++)
        cout << arr[i] << "\t";
    cout << endl;
    return 0;
}
int partition(int arr[], int beg, int end)
{
    int pivot = arr[end];
    int i = beg - 1;
    for (int j = beg; j <= end - 1; j++)
    {
        if (arr[j] <= pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}
void quick_sort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int pivot = partition(arr, beg, end);
        quick_sort(arr, beg, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}