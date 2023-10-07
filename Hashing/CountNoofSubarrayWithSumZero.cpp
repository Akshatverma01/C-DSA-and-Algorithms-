#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#define vi vector<int>
#define rep(i,a,b) for(int i=a; i<b;i++)

using namespace std;

// Map prefix sum to a map
//  For every key, choose 2 values from all the occurences of particular prefSum("MC2")
// Special case: for prefSum 0, we have to also include them.

int main(){
    int n;
    cin>>n;
    vi a(n);


    rep(i,0,n){
        cin>>a[i];     
    }

    map<int,int>cnt;

    int prefSum=0;
     
     rep(i,0,n){
        prefSum+=a[i];
        cnt[prefSum]++;
     }
    int ans=0;
     map<int,int>::iterator it;

     for (it=cnt.begin(); it!=cnt.end(); it++)
     {
        int c= it->second;

        ans += (c*(c-1)/2);

        if(it->first == 0)
        ans+= it->second;
     }
     
     cout<<ans<<endl;


}