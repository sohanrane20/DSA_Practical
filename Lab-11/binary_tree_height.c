#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *buildBinaryTree()
{
    int data;
    printf("Enter data : ");
    scanf("%d", &data);
    if (data == -1)
    {
        return NULL;
    }
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    printf("Enter data for left child of %d : ", data);
    root->left = buildBinaryTree();
    printf("Enter data for right child of %d : ", data);
    root->right = buildBinaryTree();
    return root;
}
int findHeight(struct Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    int l = findHeight(root->left), r = findHeight(root->right);
    return 1 + ((l >= r) ? l : r);
}
int main()
{
    struct Node *root = buildBinaryTree(root);
    int height = findHeight(root);
    printf("Height of binary tree : %d", height);
    return 0;
}