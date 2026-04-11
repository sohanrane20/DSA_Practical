#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int height(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}
int getBalance(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}
struct Node *rotateClockwise(struct Node *y)
{
    struct Node *x=y->left;
    struct Node *T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=1+max(height(y->left), height(y->right));
    x->height=1+max(height(x->left), height(x->right));
    return x;
}
struct Node* rotateAnticlockwise(struct Node *x){
    struct Node *y=x->right;
    struct Node *T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=1+max(height(x->left), height(x->right));
    y->height=1+max(height(y->left), height(y->right));
    return y;
}
struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = (struct Node *)malloc(sizeof(struct Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->height = 1;
        return root;
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    else
    {
        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1)
    {
        if (data < root->left->data)
        {
            return rotateClockwise(root);
        }
        if(data>root->left->data){
            root->left=rotateAnticlockwise(root->left);
            return rotateClockwise(root);
        }
    }
    if(balance<-1){
        if(data>root->right->data){
            return rotateAnticlockwise(root);
        }
        if(data<root->right->data){
            root->right=rotateClockwise(root->right);
            return rotateAnticlockwise(root);
        }
    }
    return root;
}
struct Node *findMax(struct Node *root){
    if(root!=NULL){
        if(root->right!=NULL){
            return findMax(root->right);
        }
        return root;
    }
}
struct Node* deleteNode(struct Node *root, int data){
    if(root==NULL){
        return NULL;
    }
    if(data<root->data){
        root->left=deleteNode(root->left, data);
    }else if(data>root->data){
        root->right=deleteNode(root->right, data);
    }else{
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }
        struct Node *temp=findMax(root);
        root->data=temp->data;
        root->right=deleteNode(root->right, temp->data);
    }
    root->height=1+max(height(root->left), height(root->right));
    int balance=getBalance(root);
    if(balance>1){
        //LL imbalance
        if(data<root->left->data){
            return rotateClockwise(root);
        }
        //LR imbalance
        if(data>root->right->data){
            root->right=rotateAnticlockwise(root->right);
            return rotateClockwise(root);
        }
    }
    if(balance<-1){
        //RR imbalance
        if(data>root->right->data){
            return rotateAnticlockwise(root);
        }
        //RL imbalance
        if(data<root->right->data){
            root->right=rotateClockwise(root->right);
            return rotateAnticlockwise(root);
        }
    }
    return root;
}
void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main()
{
    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct Node *root=NULL;
    for(int i=1; i<=n; i++){
        printf("Enter data: ");
        scanf("%d", &data);
        root=insertNode(root, data);
    }
    inorder(root);
    printf("\n");
    printf("Enter element to delete: ");
    scanf("%d", &data);
    root=deleteNode(root, data);
    inorder(root);
    printf("\n");
    return 0;
}