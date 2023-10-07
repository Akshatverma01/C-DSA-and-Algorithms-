#include<iostream>
#include<algorithm>
using namespace std;

//Implementation 
//Traversals 
//Count number of nodes in a BT
//HEIGHT OF A BT


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

// COUNT NUMBER OF NODES IN A BINARY TREE
int countnodes(node*root){
if(root==NULL){
   return 0;
 }

    return countnodes(root->left)+ countnodes(root->right)+1;
}

/*
//Alternate method
int TotalNodes(node* root)
{
    // Base Case
    if (root == NULL)
        return 0;
        
    // Find the left height and the
    // right heights
    int lh = left_height(root);
    int rh = right_height(root);
    // If left and right heights are
    // equal return 2^height(1<<height) -1
    if (lh == rh)
        return (1 << lh) - 1;
    // Otherwise, recursive call
    return 1 + TotalNodes(root->left)
           + TotalNodes(root->right);
}*/

// SUM AF ALL NODES VALUE
int sumNode(node*root){
        if(root==NULL){
            return 0;
        }
        return sumNode(root->left)+sumNode(root->right)+root->data;
}

// CALCULATE HEIGHT OF A BINARY TREE
int calHeight(node*root){
    if(root==NULL){
        return 0;
    }
    int lheight=calHeight(root->left);
    int rheight=calHeight(root->right);
    return  (max( lheight, rheight) +1);
    // or return( max(calHeight(root->left), calHeight(root->right))+1);
}


// CALCULATE DIAMETER OF A BINARY TREE and time complexity is O(n^2)
int calDiameter(node*root){
    if(root==NULL){
        return 0;
    }
    int lheight=calHeight(root->left);
    int rheight=calHeight(root->right);
    int currDiameter=lheight+rheight+1;

    int lDiameter=calDiameter(root->left);
    int rDiameter=calDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));


}

// optimised version
// time comp. is O(n) as no other function is calling
int caldiameter(node*root,  int*height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0;
    int rh=0;
    int ldiameter=caldiameter(root->left, &lh);
    int rdiameter=caldiameter(root->right,&rh);
    int currDiameter=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(currDiameter, max(ldiameter,rdiameter));
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
    
    // Count nodes
    cout<<"\nNumber of nodes"<<countnodes(root)<<endl;

    // SUM OF NODES
    cout<<"sum of nodes value:"<<sumNode(root)<<endl;

    // HEIGHT OF A BINARY TREE
    cout<<"Height of a binary tree is :"<<calHeight(root);

    // DIAMETER OF A BINARY TREE
    cout<<"\nDiameter of a binary tree:"<<calDiameter(root);
    
    // Alternative method of calculating DIAMETER OF A BINARY TREE
    int height=0;
    cout<<"\nAlternative Diameter of a binary tree:"<<caldiameter(root,&height);

    return 0;
    //         1
    //        /  \
    //       2     3
    //     /  \   / \
    //    4    5 6    7
}