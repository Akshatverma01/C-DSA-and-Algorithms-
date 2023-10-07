#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#define vi vector<int>
#define rep(i,a,b) for(int i=a; i<b;i++)

using namespace std;

// Ques: Given an array with n elements, calculate the minimum sum of k, consecutiv elements::O(n*k)
// 1. Iterate from i=0; i=n-k-1 in outer loop
// 2. Starting form every j=i compute sum of k elements and maintain the minimum

// OPtimal ::O(m)
// 1.Compute sum of the first k elements (i=0 to k)
// 2.while increasing i, subtract a[i-1] and add a[i+k-1] in the previous sum, which will become current sum

int main(){
    int n,k;
    cin>>n>>k;

    vi a(n);

    rep(i,0,n){
        cin>>a[i];
    }

    int s=0;

    int ans=  INT8_MAX;

    rep(i,0,k){
        s+= a[i];
    }
    ans= min(ans,s);
    cout<<s<<" ";

    // sliding
    rep(i,1,n-k+1){
        s -= a[i-1];
        s+= a[i+k-1];
        ans = min(ans, s);
        cout<<s<<" ";



    }
    cout<<endl;

    cout<<ans<<endl;


}




