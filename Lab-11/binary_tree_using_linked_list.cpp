#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *buildBinaryTree()
{
    int data;
    cout << "Enter data : ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    struct Node *root = new Node();
    root->data = data;
    cout << "Enter left child of " << data << " : \n";
    root->left = buildBinaryTree();
    cout << "Enter right child of " << data << " : \n";
    root->right = buildBinaryTree();
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
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        cout << root->data << ",";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << ",";
    }
}
int main()
{
    struct Node *root = buildBinaryTree();
    cout << "Inorder : ";
    inorder(root);
    cout << endl;
    cout << "Preorder : ";
    preorder(root);
    cout << endl;
    cout << "Postorder : ";
    postorder(root);
    cout << endl;
    return 0;
}