// Bubble sort
#include <iostream>
using namespace std;
int main()
{
    int n = 6, arr[n] = {12, 90, 23, 89, 34, 78};
    for (int pass = 1; pass < n; pass++)
    {
        for (int i = 0; i <= n - pass - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    return 0;
}