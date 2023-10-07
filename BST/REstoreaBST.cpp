#include<iostream>
#include<math.h>
using namespace std;

// case1: Swapped elements are not adjacent to each other in inorder
//     Maintain 3 pointers first, last and mid.
//     First-->(8): hold a node if any number(3) < previous node(8)-->(8,>3)
//     Mid:       node at which number (3)< previous(8)
//     LAst:      2nd node where any number < previous node(7,2)
// -->>SWAp FIRST WITH LAST


// case2: Swapped elements are adjacent to each other in inorder
//     Maintain 3 pointers first, last and mid.
// -->>SWAP FIRST WITH MID

 
struct node{
    int data;
    struct node*left , *right;

    node(int val){
        data=val;
        left= NULL;
        right=NULL;
    }

 };
 void swap(int*a, int*b){
        int temp = *a;
        *a= *b;
        *b= temp;
 }

void calcPointers(node*root, node**first, node**mid, node**last, node**prev){
   if(root==NULL){
       return;
   }

calcPointers(root->left,first,mid,last,prev);{
    if(*prev && root->data < (*prev)->data){
        if(!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last =  root;
        }
    }
             
        *prev = root;
        calcPointers(root->right,first,mid,last,prev);

}
}


void restoreBST(node*root){
    node*first,*mid,*last,*prev;
    first=NULL;
    mid=NULL;
    last=NULL;
    prev = NULL;

    calcPointers(root,&first,&mid,&last,&prev);
    
            // case1
        if(first&&last){
            swap(&(first->data),&(last->data));
        }
        else if(first&&mid){
            swap(&(first->data),&(mid->data));
        }
    
}

void inorder(node*root){
    if(root==NULL){
        return;;
     }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

    }

int main(){

        //     6
        //    / \
        //   9   3
        //  /\   \
        // 1  4    13

node*root= new node(6);
root->left= new node(9);
root->right= new node(3);
root->left->left = new node(1);
root->left->right = new node(4);
root->right->right = new node(13);

restoreBST(root);

inorder(root);

    return 0;
}