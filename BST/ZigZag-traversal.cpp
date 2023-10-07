#include<iostream>
#include<stack>
using namespace std;

// use 2 stacks---current level & next level
// variable left-to-right
// if LefttoRIght, push left child then right , else  push right child to the left

 struct node{
    int data;
    struct node*left , *right;

    node(int val){
        data=val; 
        left=NULL;
        right=NULL;
    }

 };


// time complexity::o(2n)=O(n)
 void ZigZag(node*root){
    if(root==NULL){
        return;
    }
    stack<node*> currLevel;
    stack<node*> nextLevel;
    bool leftToRight = true;
    currLevel.push(root);

    while (!currLevel.empty()){
        node*temp = currLevel.top();
        currLevel.pop();

        if(temp){
        cout<<temp->data<<" ";
        

        // check if leftToRight is true
        if(leftToRight){
            if(temp->left){
                nextLevel.push(temp->left);
            }
            if(temp->right){
                nextLevel.push(temp->right);
            }
        }

        // check if leftToRight is not true
            else{
                if(temp->right){
                    nextLevel.push(temp->right);
                }
                if(temp->left){
                    nextLevel.push(temp->left);
                }
            }
        
        } 
        if(currLevel.empty()){
            leftToRight=!leftToRight;
            swap(currLevel, nextLevel);
        }
    }
 
    
 }

 int main(){
    node*root = new node(12);
    root->left =new node(9);
    root->right=new node(15);
    root->left ->left= new node(5);
    root->left->right = new node(10);

    ZigZag(root);
    return 0;

 }