#include<iostream>
#include<algorithm>
using namespace std;

// sum replacement: the value of each node repplace with the sum of all the subtree(left/right) nodes and itself i.e, left node + right node + root
// value of a node is change if its left and right subtree exists
// for leaf node their is no change
        //     1        1 replace with 11+3+1=15
        //    / \
        //   2   3      2 replace with 2+4+5=11 || 3 remain same
        //  / \
        // 4    5       no change

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

void in_order(struct node*root){
    if(root ==NULL){
        return;
    }
    else{  

        in_order(root->left);
        cout<<root->data<<" ";
        in_order(root->right);


    }

}
void post_order(struct node*root){
    if(root ==NULL){
        return;
    }
    else{  

        post_order(root->left);
        post_order(root->right);
        cout<<root->data<<" ";


    }

}

void sumReplace(node*root){
    if(root==NULL){
        return;
    }

    sumReplace(root->left);
    sumReplace(root->right);
    if(root->left!=NULL){
        root->data += root->left->data;
    } 

    if(root->right!=NULL){
        root->data+= root->right->data;
    }
// time complexity is O(1) becuse every node is calling once

}

// Alternative method GFG
int toSumTree(node *Node)
{
    // Base case
    if(Node == NULL)
    return 0;
 
    // Store the old value
    int old_val = Node->data;
 
    // Recursively call for left and
    // right subtrees and store the sum as
    // old value of this node
    Node->data = toSumTree(Node->left) + toSumTree(Node->right);
 
    // Return the sum of values of nodes
    // in left and right subtrees and
    // old_value of this node
    return Node->data + old_val;
}


int main(){

    struct node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right= new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    // root->left->left->right=new node(9);

    cout<<endl<<"pre-order";
    pre_order(root);
    
    cout<<endl<<"in-order";
    in_order(root);
    
    cout<<endl<<"post-order";
    post_order(root);

    sumReplace(root);
   
    cout<<"\nAfter sumreplace value is:" ;
    cout<<endl<<"Again pre-order";
    pre_order(root);
     toSumTree(root);
    cout<<"\nAlternative method of sumreplace value is:" ;
    cout<<endl<<"Again pre-order";
    pre_order(root);
    cout<<"inoreder";
    in_order(root);

    return 0;
}
    