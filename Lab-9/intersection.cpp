#include <iostream>
#include <vector>
using namespace std;
void sort_array(int arr[], int n);
int main()
{
    int m, n;
    cout << "Enter m ";
    cin >> m;
    cout << "Enter n ";
    cin >> n;
    int a[m], b[n];
    cout << "Enter 1st array elements ";
    for (int i = 0; i < m; i++)
        cin >> a[i];
    cout << "Enter 2nd array elements ";
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort_array(a, m);
    sort_array(b, n);
    int arr[(m > n) ? m : n], count = 0;
    for (int i = 0, j = 0; i < m && j < n;)
    {
        if (a[i] == b[j])
        {
            arr[count++] = a[i];
            i++;
            j++;
        }
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }
    for (int i = 0; i < count; i++)
        cout << arr[i] << "\t";
    return 0;
}
void sort_array(int arr[], int n)
{
    for (int pass = 1; pass <= n - 1; pass++)
    {
        for (int i = 0; i < pass - i; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}