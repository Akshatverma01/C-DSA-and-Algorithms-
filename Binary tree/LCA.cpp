 #include<iostream>
 #include<vector>
 using namespace std;


struct node{
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

bool getPath(node*root, int key, vector<int>&path){
    if (root == NULL)
    {
        return false;
    }
    
    path.push_back(root->data);

    // check if the key exists
    if(root->data ==key){
        return true;
    }

    // return true if key exists in left or right subtree
    if(getPath(root->left,key,path) || getPath(root->right, key, path)){
        return true;
    }

    // if the key does not exists in tree and return false
     path.pop_back();
     return false;
}

int LCA(node*root, int n1, int n2){
    vector<int> path1 ,path2;
    
    // check if n1, n2 exists and find path size
    if(!getPath(root, n1, path1) || !getPath(root, n2,path2)){
        return -1;
    }
    int pc;//path change
    for(pc=0; pc<path1.size() && path2.size() ; pc++){
        if( path1[pc] != path2[pc] ){
            break; //point of path change
        }
    }
    return path1[pc-1];

}


// optimal method :: TC: O(1)
node*LCA2(node*root, int n1 , int n2){
    if (root==NULL)
    {
        return NULL;
    }
    // chec if any node match with n1 or n2
    if(root->data == n1 || root->data == n2){
        return root;
    }
    
    node*left = LCA2(root->left, n1, n2);
    node*right = LCA2(root->right, n1,n2);

    if(left!= NULL && right != NULL ){
        return root;
    }
    if(left == NULL && right == NULL){
        return NULL;
    }
    if(left!= NULL){
        return LCA2(root->left , n1,n2);
    }
    return LCA2(root->right, n1,n2);
}

int main(){
    node*root = new node(2);
    root->left = new node(3); 
    root->right = new node(5);
    root->left->left = new node(6);
    root->left->right = new node(4);
    root->right->left = new node(8);
    root->right->right = new node(7);
    root->right->right->right = new node(11);
    // root->right->right->right->right = new node(7);


    int n1= 4;
    int n2=8;
    int lca = LCA(root, n1, n2);

    if(lca == -1){
        cout<<"Lca doesn't exists\n";
    }
    else{
        cout<<"LCA::"<<lca<<endl;
        }
  
    node* Lca = LCA2(root, n1, n2);

    if(Lca == NULL){
        cout<<"Lca doesn't exists\n";
    }
    else{
        cout<<"LCA::"<<Lca->data<<endl;
        }

    return 0;
}