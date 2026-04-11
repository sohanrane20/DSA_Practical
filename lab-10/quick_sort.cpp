// Quick sort
#include <iostream>
using namespace std;
int partition(int arr[], int beg, int end);
void quick_sort(int arr[], int beg, int end);
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element: ";
        cin >> arr[i];
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
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