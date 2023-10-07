#include<iostream>
#include<algorithm>
using namespace std;
// Given a binary tree, flatten it into linked list in-place.
// AFter flattening, left of each node hould point to null and right should contain next node in preorder sequence.

// 1.recursively, flatten left and right subtree
// 2.store the left and right tail(last elements of left and right)
// 3.store right subtree in temp and make left subtree as right subtree
// 4.join right subtree with left tail
// 5.return right tail

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

void flatten(node*root){
    if (root==NULL || (root->left== NULL && root->right == NULL))
    {
        return;
    }
    
    if (root->left !=NULL)
{


        flatten(root->left);
        // make left subtree as right
        node*temp = root->right;
        root->right = root->left;
        root->left= NULL;

        // check the last element in right that was left initially and traverse to last node to append the temp previous right
        node*t = root->right;
        while(t->right != NULL){
            t=t->right;
        }
        t->right= temp;
    }

    flatten(root->right);    
}
 
void inorder(node*root){
    if (root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right)  ;  
}


int main(){

    struct node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right= new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    cout<<"Inorder before flatten\n";
    inorder(root);

    flatten(root);
    
    cout<<"\nInorder after flatten\n";
    inorder(root);

    return 0;
}
