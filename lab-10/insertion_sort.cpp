// insertion sort
#include <iostream>
using namespace std;
int main()
{
    int arr[9] = {9, 6, 5, 0, 8, 2, 7, 1, 3};
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