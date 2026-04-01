#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of elements ";
    cin >> n;
    int arr[n];
    cout << "Enter elements ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int max = 0;
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[i] == arr[j] && j - i > max)
                max = j - i;
        }
    }
    cout << "Maximum difference between two occurences of elements=" << max << endl;
    return 0;
}