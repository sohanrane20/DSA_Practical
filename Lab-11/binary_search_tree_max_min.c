#include <stdio.h>
#include <stdlib.h>
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
        root = (struct Node *)malloc(sizeof(struct Node));
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
        printf("%d, ", root->data);
        inorder(root->right);
    }
}
int findMax(struct Node *root)
{
    if (root != NULL)
    {
        if (root->right != NULL)
        {
            return findMax(root->right);
        }
        return root->data;
    }
}
int findMin(struct Node *root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            return findMin(root->left);
        }
        return root->data;
    }
}
int main()
{
    int n, data;
    struct Node *root = NULL;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter data : ");
        scanf("%d", &data);
        root = insert(root, data);
    }
    inorder(root);
    printf("\n");
    int max = findMax(root), min = findMin(root);
    printf("Maximum element : %d\n", max);
    printf("Minimum element : %d\n", min);
    return 0;
}