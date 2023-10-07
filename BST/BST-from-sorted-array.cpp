#include<iostream>
using namespace std;

// Balanced BST from sorted array

// MAke middle element as a root
// recursively , do same for subtress
            // 1. start to mid-1 for left subtrees
            // 2.mid+1 to end for right subtrees

struct Node{
    int data;
    struct Node*left,*right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node*sortedArrtoBST(int arr[], int start, int end)
{
    if(start>end){
        return NULL;
    }
    int mid =(start+end)/2;
    Node*root = new Node(arr[mid]);

    root->left = sortedArrtoBST(arr, start, mid-1);
    root->right = sortedArrtoBST(arr,mid+1, end);

    return root;

}

void preorder(Node*root){

    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void inorder(Node*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    int arr[] = {10, 20 ,30 ,40 ,50};
    Node*root=sortedArrtoBST(arr, 0, 4);
    
    // preorder(root);
    inorder(root);

    return 0;

}







