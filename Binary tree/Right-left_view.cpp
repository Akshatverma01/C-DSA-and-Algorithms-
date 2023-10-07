#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

// balanced biinary tree: | height(left-subtree) - height(right-subtree) |<=1
    //          1                   20  
    //        /  \                 / 
    //       2     3              21  
    //     /  \   / \             /  
    //    4    5 6    7          22
    //  /
    // 9
    

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


//Time complexity is O(n)
void right_view(node*root){
        if (root==NULL)
        {
            return;
        }
        queue<node*>q;
        q.push(root);

        while (!q.empty())
        {
            int n=q.size();
            for (int  i = 0; i < n; i++)
            {   
                // making each element of queue as a node in order to acess
                node*curr=q.front();     
                q.pop();
                if(i== n-1)
                cout<<curr->data<<" ";

                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }

            }

        }
        
}


//Time complexity is O(n)
void left_view(node*root){
        if (root==NULL)
        {
            return;
        }
        queue<node*>q;
        q.push(root);

        while (!q.empty())
        {
            int n=q.size();
            for (int  i = 1; i <=n; i++)
            {   
                // making each element of queue as a node in order to acess
                node*curr=q.front();     
                q.pop();
                if(i== 1)
                cout<<curr->data<<" ";

                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }

            }

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
    //  root->left->left->right->left=new node(10);

    struct node*root2=new node(20);
    root2->left=new  node(21);
    root2->left->left=new node(22);

    // rigth view
    cout<<"Right view\n";
    cout<<"For tree 1\n";
    right_view(root1);
    cout<<"\nFor tree 2\n";
    right_view(root2);

     // left view
     cout<<"\nLeft view\n";
    cout<<"For tree 1\n";
    left_view(root1);
    cout<<"\nFor tree 2\n";
    left_view(root2);



    return 0;
}