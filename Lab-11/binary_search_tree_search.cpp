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
bool search(struct Node *root,int data){
    if(root==NULL){
        return false;
    }
    if(root->data==data){
        return true;
    }else if(data<root->data){
        return search(root->left,data);
    }else{
        return search(root->right,data);
    }
}
int main(){
    int n,data;
    struct Node *root=NULL;
    cout<<"Enter number of nodes : ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Enter data : ";
        cin>>data;
        root=insert(root,data);
    }
    inorder(root);
    cout<<endl;
    cout<<"Enter data to search : ";
    cin>>data;
    if(search(root,data)){
        cout<<data<<" was found\n";
    }else{
        cout<<data<<" was not found\n";
    }
    return 0;
}