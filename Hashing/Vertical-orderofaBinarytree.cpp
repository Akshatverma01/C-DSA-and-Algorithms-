#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#define vi vector<int>

using namespace std;
struct Node{
    int key;
    Node*left,*right;

};

Node* newnode(int key){
    Node*node = new Node;
    node->key = key;
    node->left=NULL;
    node->right= NULL;
    return node;

}

void getVerticalorder(Node*root, int hDis, map<int,vi>&m){
    if(root==NULL){
        return;
    }

    m[hDis].push_back(root->key);
    getVerticalorder(root->left,hDis-1,m);
    getVerticalorder(root->right,hDis+1,m);

}

int main(){
        //     10
        //    /   \
        //   7     4
        //  / \   / \
        // 3  11 14  6 
    Node*root= newnode(10);
    root->left = newnode(7);
    root->right = newnode(4);
    root->left->left = newnode(3);
    root->left->right = newnode(11);
    root->right->left = newnode(14);
    root->right->right = newnode(6);

    map<int, vector<int>> m;
    int hDis =0;

    getVerticalorder(root,hDis,m);

    map<int ,vi>:: iterator it;
     for (it=m.begin(); it != m.end() ;it++){

        for (int i = 0; i < (it->second).size() ; i++)
        {
            cout<<(it->second)[i]<<" ";
        }
        cout<<endl;
     }


return 0;

}