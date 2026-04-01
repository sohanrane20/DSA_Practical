// radix sort
#include <iostream>
using namespace std;
void count_sort(int arr[], int n, int factor);
int main()
{
    int arr[6] = {804, 26, 5, 64, 52, 1};
    int factor = 1;
    int max = arr[0];
    for (int i = 0; i < 6; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    for (int factor = 1; max / factor > 0; factor *= 10)
        count_sort(arr, 6, factor);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << "\t";
    cout << endl;
    return 0;
}
void count_sort(int arr[], int n, int factor)
{
    // find max;
    int max = (arr[0] / factor) % 10;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] / factor) % 10 > max)
            max = (arr[i] / factor) % 10;
    }
    // build count array
    int count[max + 1] = {};
    for (int i = 0; i < n; i++)
        count[(arr[i] / factor) % 10]++;
    // find prefix sum
    for (int i = 1; i < max + 1; i++)
        count[i] += count[i - 1];
    // build sorted array
    int ans[n] = {};
    for (int i = n - 1; i >= 0; i--)
    {
        ans[count[(arr[i] / factor) % 10] - 1] = arr[i];
        count[(arr[i] / factor) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = ans[i];
}