#include<iostream>
using namespace std;

// Searchng and deletion in a Bst

struct Node{
    int data;
    struct Node*left,*right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

//time comlexity : O(logn)
Node*search(Node*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    //data>key
    if(root->data > key){
        return search(root->left, key);
    }
    //data<key
        return search(root->right, key);
        
}

//Inorder successor
Node* inordersucc(Node*root){
    Node*curr = root;
    while (curr && curr->left != NULL){
        curr= curr->left;
    }
    return curr;   


}

//Inorder predecessor
// Node*inorderpred(Node*root){
//     Node*curr = root;
//     while(curr && curr->right !=NULL){
//         curr=curr->right;
//     }
//     return curr;
// }

//Delete in bst
Node*deleteinBST(Node*root, int key){
    //case 1&2 , if root has single or no child
        if(key < root->data){
        root->left = deleteinBST(root->left, key);

    }
    else if(key> root->data){
        root->right = deleteinBST(root->right, key);

    }
    else{
            if(root->left == NULL){
                Node*temp = root->right;
                free(root);
                return temp;
            }
            
            if(root->right == NULL){
                Node*temp = root->left;
                free(root);
                return temp;
            } 

            //case 3
            Node*temp=inordersucc(root->right);
            // Node*temp=inorderpred(root->left);
            root->data= temp->data;
            root->right= deleteinBST(root->right, temp->data);


    }
    return root;
}


void inorder(Node*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){
    Node*root= new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right= new Node(3);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<"Inorder traverse\n";
    inorder(root);

    // if(search(root,5) ==NULL){
    //     cout<<"\nKey does not exist\n";
    // }
    // else{
    //     cout<<"\nKey exists";
    // }


    root=deleteinBST(root, 5);

    cout<<"\nAgain Inorder\n";
    inorder(root);


    return 0;
   

}
