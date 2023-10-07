#include<iostream>
using namespace std;

//Binary tree from inorder and postorder
/*
1.pick element from end of postorder and create a node
2.decrement postorder index
3.search for picked elements's position in inorder
4.call to build right subtree from inorer's  pos+1 to n
5.call to build left subtree from inorder's 0 to pos-1
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

int search(int inorder[], int start, int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

Node*buildtree(int postorder[], int inorder[], int start, int end){
    static int index=end;

    if(start>end){
        return NULL;
    }
    int curr=postorder[index];
    index--;
    Node *node=new Node(curr);
    
    if(start == end){
        return node;
    }
    int pos=search(inorder,start,end,curr);
    node->right=buildtree(postorder,inorder,pos+1,end);
    node->left=buildtree(postorder,inorder,start,pos-1);

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
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};
    Node*root= buildtree(postorder,inorder,0,4);
    inorderprint(root);
    return 0;
}