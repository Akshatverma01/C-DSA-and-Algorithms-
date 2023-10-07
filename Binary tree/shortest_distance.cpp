 #include<iostream>
 using namespace std;

// Find the LCA(least common ancestor)
// Find distance n1(d1) & n2(d2) from LCA
// return (d1+d2)

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


// TC::O(1)
node*LCA(node*root, int n1 , int n2){
    if (root==NULL)
    {
        return NULL;
    }
    // chec if any node match with n1 or n2
    if(root->data == n1 || root->data == n2){
        return root;
    }
    
    node*left = LCA(root->left, n1, n2);
    node*right = LCA(root->right, n1,n2);

    if(left!= NULL && right != NULL ){
        return root;
    }
    if(left == NULL && right == NULL){
        return NULL;
    }
    if(left!= NULL){
        return LCA(root->left , n1,n2);
    }
    return LCA(root->right, n1,n2);
}

int findDis(node*root, int k, int dist){
    if (root == NULL) 
    {
        return -1;
    }
    if (root->data == k){
        return dist;
    }
    int left = findDis(root->left,k,dist+1);
    if(left != -1){
        return left;
    }
    else return findDis(root->right, k, dist+1);
    
    
}
int distancebtwNode(node*root, int n1, int n2){
    node*lca = LCA(root,n1, n2);
    int d1 = findDis(lca,n1,0);
    int d2 = findDis(lca, n2,0);
    return d1+d2;
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



 cout<<distancebtwNode(root, 6,11);
  

    return 0;
}