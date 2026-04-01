// A. 2. Find pair with given sum
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    Node *previous;
    int data;
    Node *next;
};
vector<vector<int>> findPair(Node *head, int target);
void displayList(Node *head);
int main()
{
    Node *head, *newNode, *temp;
    int n, target;
    head = NULL;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        newNode = new Node;
        cout << "Enter element " << i + 1 << ": ";
        cin >> newNode->data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
            temp->previous = NULL;
        }
        else
        {
            newNode->previous = temp;
            temp->next = newNode;
            temp = newNode;
        }
    }
    displayList(head);
    cout << endl;
    cout << "Enter target: ";
    cin >> target;
    vector<vector<int>> result = findPair(head, target);
    for (vector<int> pair : result)
    {
        cout << "(" << pair[0] << ", " << pair[1] << ")\t";
    }
    cout << endl;
    return 0;
}
void displayList(Node *head)
{
    Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
}
vector<vector<int>> findPair(Node *head, int target)
{
    vector<vector<int>> result;
    Node *p, *q;
    q = head;
    while (q->next != NULL)
    {
        q = q->next;
    }
    p = head;
    while (p != q && p->next != q)
    {
        if (p->data + q->data == target)
        {
            vector<int> pair{p->data, q->data};
            result.push_back(pair);
            p = p->next;
            q = q->previous;
        }
        else if (p->data + q->data > target)
        {
            q = q->previous;
        }
        else
        {
            p = p->next;
        }
    }
    return result;
}