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
int countLeaves(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}
int main()
{
    struct Node *root = buildBinaryTree();
    int leaves = countLeaves(root);
    printf("Total number of leaves : %d", leaves);
    return 0;
}