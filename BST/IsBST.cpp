#include<iostream>
using namespace std;

// Is it a Bst?

struct Node{
    int data;
    struct Node*left,*right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

bool isBST(Node*root,Node*min=NULL, Node*max=NULL){
    if(root==NULL){
        return true;
    }
    
    if(min!= NULL && root->data <= min->data){
        return false;
    }
      if(max!= NULL && root->data >= max->data){
        return false;
    }

    bool leftValid = isBST(root->left, min, root);
    bool rightVAlid = isBST(root->right, root, max);
    return leftValid and rightVAlid;
}


// Alternative method

int maxValue(struct Node* root)
{
    if (root == NULL) {
        return INT16_MIN;
    }
    int value = root->data;
    int leftMax = maxValue(root->left);
    int rightMax = maxValue(root->right);
 
    return max(value, max(leftMax, rightMax));
}
 
int minValue(struct Node* root)
{
    if (root == NULL) {
        return INT16_MAX;
    }
    int value = root->data;
    int leftMax = minValue(root->left);
    int rightMax = minValue(root->right);
 
    return min(value, min(leftMax, rightMax));
}
 
/* Returns true if it is a binary search tree */
int isBST2(struct Node* root)
{
    if (root == NULL)
        return 1;
 
    /* false if the max of the left is > than us */
    if (root->left != NULL
        && maxValue(root->left) > root->data)
        return 0;
 
    /* false if the min of the right is <= than us */
    if (root->right != NULL
        && minValue(root->right) < root->data)
        return 0;
 
    /* false if, recursively, the left or right is not a BST
     */
    if (!isBST2(root->left) || !isBST2(root->right))
        return 0;
  
    /* passing all that, it's a BST */
    return 1;
}
 

int main(){
     Node*root= new Node(5);
    root->left=new Node(2);
    root->right=new Node(8);
    // root->left->left=new Node(1);
    // root->left->right= new Node(3);
    // root->right->left=new Node(6);
    // root->right->right=new Node(7);

    if(isBST(root,NULL,NULL) )
    {
        cout<<"VAlid BST"<<endl;
    }
    else{
        cout<<"Invalid BST";
    }

    
    if(isBST2(root) )
    {
        cout<<"VAlid BST"<<endl;
    }
    else{
        cout<<"Invalid BST";
    }

    return 0;
}