 #include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<algorithm>

#define vi vector<int>
#define rep(i,a,b) for (int i = a; i < b; i++)

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vi a(n);

    rep(i,0,n)
    cin>> a[i];

// max-Heap
    priority_queue<int, vi>pq;

    rep(i,0,n){
        pq.push(a[i]);
    }

    int sum = 0;
    int cnt = 0;

    while (!pq.empty())
    {
        if(pq.top() > k){
            pq.pop();
        }
        else{
        sum += pq.top();
        pq.pop();

        cnt++;
        if(sum>=k)
        break;
        }
       
    }

    if(sum<k){
        cout<<"-1"<<endl;
    }
    else if(sum>k){
        cout<<"0"<<endl;
    }
    else{
        cout<<cnt;
    }
    
return 0;

}
