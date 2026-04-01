#include <iostream>
#include <vector>
using namespace std;
int find_pairs(int arr[], int n, int target);
int main()
{
    int n, target;
    cout << "Enter number of elements ";
    cin >> n;
    int arr[n];
    cout << "Enter elements ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter target ";
    cin >> target;
    cout << "Number of pairs=" << find_pairs(arr, n, target) << endl;
    return 0;
}
int find_pairs(int arr[], int n, int target)
{
    int count = 0;
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[i] + arr[j] == target)
                count++;
        }
    }
    return count;
}