#include<iostream>
#include<algorithm>
using namespace std;

// find and print all nodes from a node at a distance k
//case1::visit Node's subtree till k==0
//case2::find distance d of all the ancestors 
//       for all ancestors search other subtree at (k-d)
//        
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

// case 1  : Nodes subtree

void printSubtreeNodes(node*root, int k){
    if (root == NULL || k<0)
    {
        return;
    }
    if (k==0)
    {
        cout<<root->data<<" ";
    }

    printSubtreeNodes(root->left, k-1);
    printSubtreeNodes(root->right, k-1);    
    
}

// case 2 : Ancestors

int printNodsAtK(node*root, node*target, int k){
    if (root == NULL)
    {
        return -1;
    }
    if (root==target)
    {
        printSubtreeNodes(root, k);
        return 0; 
    }


// check if target is in left subtree
    int dl = printNodsAtK(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
         cout<<root->data<<" ";   
        }else{
            printSubtreeNodes(root->right, k-dl-2);
        }
        return 1+dl;
    }
    


// check if target is in right subtree
    int dr = printNodsAtK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
         cout<<root->data<<" ";   
        }else{
            printSubtreeNodes(root->left, k-dr-2);
        }
        return 1+dr ;
    }
    
    
    return -1;
    
}


int main(){

    struct node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right= new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
   
   printNodsAtK(root, root->left,3);
 
  

    return 0;
}
