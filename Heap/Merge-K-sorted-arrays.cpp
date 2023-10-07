 #include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>

#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first 

using namespace std;
//1. Ccreate a min heap if pairs: pair->{value, array number}
//2. Insert {first array, element number} of all sorted array into minHeap
//3. Main idea:: We will pop element from the MinHeap and store into the answer array
// 4. Insert the next element of the sorted array into MInHeap 
// 5. we also need to keep track of the indices of the elements

int main(){
    int k; 
    cin>>k;

// constructing 2-D vector: vector of int type vector
    vector<vector<int>> a;

    for (int i = 0; i < k; i++)
    {
        // each index is set as a particular array
        int size;
        cin>>size;

        a[i]= vector<int>(size);
        for (int j = 0; j < k; i++)
        {
            cin>>a[i][j];
        }
         

    }
    // declaring pair-vector
    vector<int> idx(k,0);
    priority_queue<pii, vector<pii>,greater<pii>> pq;

    for (int i = 0; i < k; i++)
    {   
        pii p;
        p.ff = a[i][0];
        p.ss = i;
        pq.push(p);
    }
    
    // answer array
    vi ans;

    while (!pq.empty()){
        pii x = pq.top();
        pq.pop();

        ans.push_back(x.ff);

        if(idx[x.ss]+1 < a[x.ss].size()){
            pii p;
            p.ff = a[x.ss][idx[x.ss]+1];
            p.ss = x.ss;
            pq.push(p);
           
        }
        idx[x.ss]+=1;


    }
    for (int i = 0; i < k; i++)
    {
        cout<<ans[i];
    }
    cout<<endl;
    
    

    

}