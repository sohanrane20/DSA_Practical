// count sort
#include <iostream>
using namespace std;
int main()
{
    int arr[6] = {9, 6, 5, 0, 8, 2};
    int max = arr[0];
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    int count[max + 1] = {};
    for (int i = 0; i <= 5; i++)
        count[arr[i]]++;
    // prefix sum
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    int ans[6];
    for (int i = 5; i >= 0; i--)
    {
        ans[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < 6; i++)
        cout << ans[i] << "\t";
    cout << endl;
    return 0;
}