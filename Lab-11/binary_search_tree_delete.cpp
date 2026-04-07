#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* insert(struct Node *root,int data){
    if(root==NULL){
        root=new Node();
        root->data=data;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}
void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<",";
        inorder(root->right);
    }
}
struct Node* find_max(struct Node *root){
    if(root!=NULL&&root->right!=NULL){
        return find_max(root->right);
    }
    return root;
}
struct Node* delete_node(struct Node *root,int data){
    if(root==NULL){
        return NULL;
    }
    if(data<root->data){
        return delete_node(root->left,data);
    }else if(data>root->data){
        return delete_node(root->right,data);
    }else{
        
    }
}
int main(){

    return 0;
}