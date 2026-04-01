// Implementation of hash table (Division method)
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
int main()
{
    int m, n;
    cout << "Enter m ";
    cin >> m;
    Node *table[m];
    for (int i = 0; i < m; i++)
        table[i] = NULL;
    cout << "Enter number of keys ";
    cin >> n;
    int keys[n];
    cout << "Enter keys ";
    for (int i = 0; i < n; i++)
        cin >> keys[i];
    for (int i = 0; i < n; i++)
    {
        int j = keys[i] % m;
        Node *new_node;
        new_node = new Node;
        new_node->data = keys[i];
        new_node->next = NULL;
        if (table[j] == NULL)
            table[j] = new_node;
        else
        {
            new_node->next = table[j];
            table[j] = new_node;
        }
    }
    for (int i = 0; i < m; i++)
    {
        Node *p;
        p = table[i];
        cout << "Cell=" << i << "\t";
        while (p != NULL)
        {
            cout << p->data << "->";
            p = p->next;
        }
        cout << endl;
    }
    return 0;
}