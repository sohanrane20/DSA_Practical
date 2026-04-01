// Linear probing
#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cout << "Enter m ";
    cin >> m;
    int table[m];
    for (int i = 0; i < m; i++)
        table[i] = -1;
    cout << "Enter number of keys ";
    cin >> n;
    int keys[n];
    cout << "Enter keys ";
    for (int i = 0; i < n; i++)
        cin >> keys[i];
    for (int j = 0; j < n; j++)
    {
        int i = 0, k;
        do
        {
            k = (keys[j] + i) % m;
            if (table[k] != -1)
                i++;
        } while (table[k] != -1 && i <= 5);
        if (table[k] == -1)
            table[k] = keys[j];
    }
    for (int i = 0; i < m; i++)
        cout << "Cell=" << i << "\t" << table[i] << endl;
    return 0;
}