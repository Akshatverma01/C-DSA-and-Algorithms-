#include<iostream>
#include<vector>
using namespace std;


// Iterate from i = 0 to i < n
// Base condition for the recursive approach, when n <= 1, return 1
// Return the res.
// Make a recursive call catalan(i) and catalan(n – i – 1) and keep adding the product of both into res.

// Applications
// 1.possible bst's
// 2.parentheisis / brackets combinations
// 3.possible forests
// 4.ways of triangulations
// 5.possible paths in matrix
// 6.dividing a circle usinh N chords
// 7.Dyck wors of given length & much more'

struct Node{
    int data;
    struct Node*left,*right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int catalan(int n){
    if(n<=1){
        return 1;
    }
    int res=0;
    for(int i=0; i<=n-1;i++){
        res+=catalan(i) * catalan(n-i-1);
    }

    return res;
}


// valid BST using CAtalan numbers
vector<Node*> constructTrees(int start, int end)
{
    vector<Node*> trees;
    for(int i=start; i<=end ; i++){
        vector<Node*> leftSubtrees = constructTrees( start, i-1);
        vector<Node*> rightSubtrees = constructTrees( i+1, end);
        


    }
}












int main(){

    for(int i=0; i<10 ;i++){
        cout<<catalan(i)<<" ";

    }
    cout<<endl;
    return 0;
}