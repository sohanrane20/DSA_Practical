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
struct Node *findMax(struct Node *root)
{
    if (root != NULL)
    {
        if (root->right != NULL)
        {
            return findMax(root->right);
        }
        return root;
    }
}
struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            return root->right;
        }
        if (root->right == NULL)
        {
            return root->left;
        }
        struct Node *temp = findMax(root->left);
        root->data = temp->data;
        root->left = deleteNode(root->left, temp->data);
    }
    return root;
}
int main()
{
    int n, data;
    struct Node *root = NULL;
    cout << "Enter number of nodes : ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter data : ";
        cin >> data;
        root = insert(root, data);
    }
    inorder(root);
    cout << endl;
    cout << "Enter element to delete : ";
    cin >> data;
    root = deleteNode(root, data);
    inorder(root);
    cout << endl;
    return 0;
}