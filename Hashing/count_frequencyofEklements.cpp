#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#define vi vector<int>

using namespace std;
int main(){
     
     int n;
     cin>>n;
     vi a(n);

     for (int i = 0; i < n; i++)
     {
        cin>>a[i];
     }

// map<int,int> freq;
unordered_map<int,int> freq;
     for (int i = 0; i < n; i++)
     {
        freq[a[i]]++;

     }
     
// map<int ,int>::iterator it;     
unordered_map<int ,int>::iterator it;
     for (it=freq.begin(); it != freq.end() ;it++){

        cout<<it->first<<" "<<it->second<<endl;
     }
        
     return 0;
  
 
}