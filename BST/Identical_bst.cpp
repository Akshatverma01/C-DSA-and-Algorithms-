#include<iostream>
using namespace std;

// if both same node empty, return true
// if both non-empty,
         //a.check that data at nodes is equal
        // b.check if left subtrees are is_same
        // c.check if right subtree is same
// if (a,b,c) are true, return true , else return false

struct node{
    int data;
    struct node*left , *right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

 };

//  isIdentical
bool isIdentical(node*root1, node*root2){
    if(root1==NULL&& root2 == NULL){
        return true;
    }
    else if(root1 == NULL || root2 ==NULL){
        return false;

    }
    else{
        bool cond1 = root1->data== root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);

        if(cond1 && cond2 && cond3){
            return true;
        }
        else{
            return false;
        }
    }
    }


 int main(){

    //     5                   
    //    / \
    //   3   8
    //  / \
    // 2    4
    
    //     5
    //    / \
    //   3   8
    //  / \    \
    // 2   4    9
    
    node*root1= new node(5);
    root1->left=new node(3);
    root1->right=new node(8);
    root1->left->left = new node(2);
    root1->left->right = new node(4);

     node*root2= new node(5);
    root2->left=new node(3);
    root2->right=new node(8);
    root2->left->left = new node(2);
    root2->left->right = new node(4);
    root2->right->right = new node(9);

    if(isIdentical(root1,root2))
    {
    cout<<"BST is Identical\n";
    }   
    else{
        cout<<"Bst is not Identical\n";
    }
 return 0;

 }

 
