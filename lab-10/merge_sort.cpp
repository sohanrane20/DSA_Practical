// merge sort
#include <iostream>
using namespace std;
void merge(int arr[], int beg, int mid, int end);
void merge_sort(int arr[], int beg, int end);
int main()
{
    int arr[6] = {9, 6, 5, 0, 8, 2};
    merge_sort(arr, 0, 5);
    for (int i = 0; i <= 5; i++)
        cout << arr[i] << "\t";
    cout << endl;
    return 0;
}
void merge(int arr[], int beg, int mid, int end)
{
    int n1 = mid - beg + 1, n2 = end - mid, l[n1], r[n2];
    for (int i = beg; i <= mid; i++)
        l[i - beg] = arr[i];
    for (int j = mid + 1; j <= end; j++)
        r[j - (mid + 1)] = arr[j];
    int i = 0, j = 0, k = beg;
    while (i < n1 && j < n2)
    {
        if (l[i] < r[j])
        {
            arr[k++] = l[i];
            i++;
        }
        else if (l[i] > r[j])
        {
            arr[k++] = r[j];
            j++;
        }
        else
        {
            arr[k++] = l[i];
            i++;
            j++;
        }
    }
    for (; i < n1; i++)
        arr[k++] = l[i];
    for (; j < n2; j++)
        arr[k++] = r[j];

    for (int k = 0; k < end - beg; k++)
        cout << arr[k] << "\t";
    cout << endl;
}
void merge_sort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int mid = beg + (end - beg) / 2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}