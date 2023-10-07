#include<iostream>
#include<algorithm>
using namespace std;

// balanced biinary tree: | height(left-subtree) - height(right-subtree) |<=1
    //          1
    //        /  \
    //       2     3
    //     /  \   / \
    //    4    5 6    7
    

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

void pre_order(struct node*root){
    if(root ==NULL){
        return;
    }
    else{  

        cout<<root->data<<" ";
        pre_order(root->left);
        pre_order(root->right);


    }

}

int height(node*root){ 
     if(root == NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh =height(root->right);
    return max( lh,rh)+1;
    
}
// Time complexity is: O(n*n)

bool isBalanced(node *root)
{
    if(root == NULL){
        return true ;
    }
    if(isBalanced(root->left)==false){          /*calling for each node left and  right : O(n)*/
        return false;
    }
    if(isBalanced(root->right)==false)
    {
        return false;
    }
    int lh=height(root->left);                  /*calling for each node left and right :O(n)*/                
    int rh= height(root->right);
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}


// Alternate mathod for O(n)
 bool isBalanced2(node*root, int*height){
    if(root == NULL){
        return true ;
    }

    int lh=0, rh=0;

    if(isBalanced2(root->left,&lh)==false){
        return false;
    }
    if ( isBalanced2(root->right, &rh)==false)
    {
        return false;
    }
    *height=max(lh,rh)+1;

    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
 }


int main(){

    struct node*root1=new node(1);
    root1->left=new node(2);
    root1->right=new node(3);
    root1->left->left=new node(4);
    root1->left->right= new node(5);
    root1->right->left=new node(6);
    root1->right->right=new node(7);
    root1->left->left->right=new node(9);
    // root1->left->left->right->left=new node(10);                                                                                       
    struct node*root2=new node(20);
    root2->left=new  node(21);
    root2->left->left=new node(22);

    // cout<<endl<<"pre-order";
    // pre_order(root);

    if(isBalanced(root1)){
        cout<<"Balanced binary tree\n";
    }
    else{
        cout<<"\nNot a balanced binary tree";
    }
    if(isBalanced(root2)){
        cout<<"Balanced binary tree";
    }
    else{
        cout<<"\nNot a balanced binary tree";
    }

    cout<<"\nAlternate results";
    if(isBalanced(root1)){
        cout<<"\nBalanced binary tree\n";
    }
    else{
        cout<<"\nNot a balanced binary tree";
    }
    if(isBalanced(root2)){
        cout<<"Balanced binary tree";
    }
    else{
        cout<<"Not a balanced binary tree";
    }

    return 0;
}