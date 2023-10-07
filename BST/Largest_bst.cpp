#include<iostream>
using namespace std;

// Each node will store the following info
// 1.min in subtree
// 2.max in subtree
// 3.subtree size
// 4.size of largest Bst
// 5.isBST

// bottom-up recursive approach  

struct node{
    int data;
    struct node*left , *right;

    node(int val){
        data=val;
        left= NULL;
        right=NULL; 
    }

 };
  

struct InfoofBST{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;

};

InfoofBST largestBstinBT(node*root){
    if(root==NULL){
        return{0,INT8_MIN,INT8_MAX, 0,true};
    }

    // leaf node
    if(root->left == NULL && root->right ==NULL){
        return{1, root->data, root->data,1,true};
    }

    InfoofBST leftInfo = largestBstinBT(root->left);
    InfoofBST rightInfo = largestBstinBT(root->right);

    InfoofBST curr;
    curr.size = (1+leftInfo.size + rightInfo.size);

// check the bst condition
    if(leftInfo.isBST &&rightInfo.isBST && leftInfo.max<root->data && rightInfo.min > root->data){

        curr.min= min(leftInfo.min, min(rightInfo.min,root->data));
        curr.max = max(leftInfo.max, max(rightInfo.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;
        return curr;

    }

// else condition
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;

}

int main(){

    //     15
    //     /\
    //    20  30 
    //    /
    //    5
    //   / \
    //  4   10
    node*root =new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);
    root->left->left->right= new node(10);
    root->left->left->left = new node(4);


    cout<<"Largest BST in BT::" << largestBstinBT(root).ans <<endl;
    return 0;

}