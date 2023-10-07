#include<iostream>
#include<queue>
using namespace std;

// Level order traversal is done by queue data structure.
// insert root first into the queue and put NULL into queue and check for its left or right child and dequeue the root and insert its left or right child.
// check each level and add a NULL after traversing all the elements of a level.
// NULL represents that a level has been traversed.
// encountering NULL will dequeue the queue element
// the element dequeued from the queue first check if its childs exists.
// if exists the push into the queue and the dequeued the parent node.

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


void printLevelOrder(Node*root){
    if(root==NULL){

        return;
    }
  
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        // assigning queue front as a node and pop
        Node*node=q.front();
        q.pop();
        // analysing if node childs exists
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left)
               q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty()){
            q.push(NULL);

        }

    }

}

// FIND THE SUM OF NODES AT Kth LEVEL
int sum_at_K(Node*root, int k){
    if(root==NULL){
        return -1;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;

    while(!q.empty()){
        Node*node=q.front();
        q.pop();
        if(node!=NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
 
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int main(){

    struct Node*root= new Node(4);
    root->left=new Node(2);
    root->right=new Node(6);
    root->left->left=new Node(1);
    root->left->right= new Node(3);
    root->right->left=new Node(5);
    root->right->right=new Node(7);
// printing level-order traversal
    printLevelOrder(root);
    // Sum at Kth Level
    cout<<endl<<sum_at_K(root,2);
   
    return 0;

    //         1
    //        /  \
    //       2     3
    //     /  \   / \
    //    4    5 6    7
}