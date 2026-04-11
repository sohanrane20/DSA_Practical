// Insertion sort
#include <iostream>
using namespace std;
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
    for (int j = 1; j <= 8; j++)
    {
        int min = arr[j], i;
        for (i = j - 1; i > 0 && arr[i] > min; i--)
            arr[i + 1] = arr[i];
        arr[i] = min;
    }
    for (int i = 0; i <= 8; i++)
        cout << arr[i] << "\t";
    cout << endl;
    return 0;
}