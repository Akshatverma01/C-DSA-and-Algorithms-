#include<iostream>
using namespace std;

/*
1.pick element from preorder and create a node
2.increment preorder index
3.search for picked elements's position in onorder
4.call to build left subtree from inorder's 0 to pos-1
5.call to build right subtree from inorer's  pos+1 to n
6.return the node
*/
struct Node{
    int data;
    struct Node*left;
    struct Node*right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }

};


int search(int inorder[],int start, int end, int curr)
{
    for(int i=start;i<=end;i++){
        if( inorder[i]==curr)
        {
            return i;
        }
    }
    return -1;
    
}


Node* build_tree(int preorder[], int inorder[], int start, int end){
    static int index=0;
    if(start>end){
        return NULL;
    }
    int curr=preorder[index];
    index++;
    Node *node=new Node(curr);
    if(start==end){
        return node;
    }
    int pos= search(inorder,start,end,curr);
    node->left=build_tree(preorder,inorder,start,pos-1);
    node->right=build_tree(preorder,inorder,pos+1,end);

  return node;
}

void inorderprint(Node*root){
    if(root==NULL){
        return;
 
   }
   inorderprint(root->left);
   cout<<root->data<<" ";
   inorderprint(root->right);
}


int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    Node*root=build_tree(preorder, inorder, 0,4);
    inorderprint(root);

    return 0;



}