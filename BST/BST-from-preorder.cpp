#include<iostream>
using namespace std;

// INsertion in a Bst

struct Node{
    int data;
    struct Node*left,*right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node*BSTrfromPre(int preorder[], int* preorderIdx, int key, int min, int max, int n){
        if(*preorderIdx >= n){
            return NULL;
        }
        Node* root=NULL;
        if(key > min && key <max){
            root= new Node(key);
            *preorderIdx =*preorderIdx+1;

            if( *preorderIdx < n){
                root->left = BSTrfromPre( preorder,preorderIdx, preorder[*preorderIdx], min, key,n);
            }
            if(*preorderIdx < n){
                root->right =  BSTrfromPre( preorder,preorderIdx, preorder[*preorderIdx], key, max,n);
            }
        } 
        return root;

}



void pre_order( Node*root){
    if(root ==NULL){
        return;
    }
    else{  

        cout<<root->data<<" ";
        pre_order(root->left);
        pre_order(root->right);


    }

}


int main(){

    int preorder[]= {10,2,1,13,11};
    int n=5;
    int preorderIdx = 0;
    Node* root = BSTrfromPre(preorder, &preorderIdx, preorder[0], INT8_MIN, INT8_MAX, n);
    pre_order(root);
    return 0;

            //     10
            //    /  \
            //   2    13
            //  /     /
            // 1     11    

}