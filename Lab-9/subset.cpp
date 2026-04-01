#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cout << "Enter m ";
    cin >> m;
    cout << "Enter n ";
    cin >> n;
    int a[m], b[n];
    cout << "Enter A elements ";
    for (int i = 0; i < m; i++)
        cin >> a[i];
    cout << "Enter B elements ";
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int j;
    for (j = 0; j < n; j++)
    {
        bool flag = false;
        for (int i = 0; i < m && !flag; i++)
        {
            if (a[i] == b[j])
                flag = true;
        }
        if (!flag)
            break;
    }
    if (j == n)
        cout << "B subset of A\n";
    else
        cout << "B not subset of A\n";
    return 0;
}