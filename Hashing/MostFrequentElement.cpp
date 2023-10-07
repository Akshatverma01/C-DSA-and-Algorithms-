#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define rep(i,a,b) for(int i=a; i<b;i++)

using namespace std;

// ceate a map
// while travelling , keep track of elements and when we find (k+1)th without elements = break
// output the element

int main(){
    int n,k;
    cin>>n>>k;
    vi a(n);

    rep(i,0,n){
        cin>>a[i];
    }

    map<int,int> freq;
    rep(i,0,n){
        int presentSize = freq.size();
        if(freq[a[i]]==0 && presentSize == k)
        break;

        freq[a[i]]++;


    }
    vii ans;
    map<int,int>:: iterator it;
    for ( it= freq.begin(); it!=freq.end();it++)
    {
      if(it->second != 0){
        
        pair<int, int> p;
        p.first  = it->second;
        p.second = it->first;
        ans.push_back(p);

      }
    }
    sort(ans.begin(), ans.end(), greater<pair<int,int>>());

    vii :: iterator it1;

    for ( it1 = ans.begin(); it1 != ans.end(); it1++)
    {
        cout<< it1->second <<" "<< it1->first <<endl;
    }
    


}