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
int countNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main()
{
    struct Node *root = buildBinaryTree();
    int nodes = countNodes(root);
    printf("Total number of nodes : %d", nodes);
    return 0;
}