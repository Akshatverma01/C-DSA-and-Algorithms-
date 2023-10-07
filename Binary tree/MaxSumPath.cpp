#include<iostream>
#include<algorithm>
using namespace std;

// 1. node val
// 2. Max path sum thorugh left child +node val
// 3. Max path sum through right child + node val
// 4. Max path sum through left+ right +node val
struct node{
    int data;
    struct node*left;
    struct node*right; 

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};

int maxSumPathUtil(node*root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = maxSumPathUtil(root->left,ans);
    int right = maxSumPathUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left +right), max(root->data + left, root->data + right ));
    ans = max(ans,nodeMax);

    int singleSumPAth = max(root->data, max(root->data+ left, root->data + right));
    return singleSumPAth;
    
}

int maxSumPath(node*root){
    int ans = INT8_MIN;
    maxSumPathUtil(root,ans);
    return ans;
}


int main(){

    struct node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right= new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
   
    int a= maxSumPath(root);
    cout<<a;
   

    return 0;
}