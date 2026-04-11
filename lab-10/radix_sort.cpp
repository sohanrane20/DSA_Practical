// Radix sort
#include <iostream>
using namespace std;
void count_sort(int arr[], int n, int factor);
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
    int factor = 1;
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    for (int factor = 1; max / factor > 0; factor *= 10)
        count_sort(arr, n, factor);
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << endl;
    return 0;
}
void count_sort(int arr[], int n, int factor)
{
    // Find max;
    int max = (arr[0] / factor) % 10;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] / factor) % 10 > max)
            max = (arr[i] / factor) % 10;
    }
    // Build count array
    int count[max + 1] = {};
    for (int i = 0; i < n; i++)
        count[(arr[i] / factor) % 10]++;
    // Find prefix sum
    for (int i = 1; i < max + 1; i++)
        count[i] += count[i - 1];
    // Build sorted array
    int ans[n] = {};
    for (int i = n - 1; i >= 0; i--)
    {
        ans[count[(arr[i] / factor) % 10] - 1] = arr[i];
        count[(arr[i] / factor) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = ans[i];
}