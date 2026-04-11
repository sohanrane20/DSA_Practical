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