#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << ",";
        inorder(root->right);
    }
}
int main()
{
    int n, data;
    cout << "Enter number of nodes : ";
    cin >> n;
    struct Node *root = NULL;
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter data : ";
        cin >> data;
        root = insert(root, data);
    }
    inorder(root);
    return 0;
}