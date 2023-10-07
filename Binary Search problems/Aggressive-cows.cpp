// Given an array of size N and stall K aggressive cows such that min dis is max possible
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isPossible(vector<int>&stalls, int k, int mid){

    int cowCount=1;
    int lastPos = stalls[0];
 for (int i = 1; i < stalls.size(); i++)
 {
    if( stalls[i]-lastPos >= mid ){
        cowCount++;
        lastPos=stalls[i];
        if(cowCount == k){
            return true;
        }

    }
}
    return false;
}

int aggressiveCows( vector<int>&stalls, int k){
    sort(stalls.begin(), stalls.end());
    int s=0;
    int e = stalls[stalls.size()-1];

    int ans=-1;
    int mid= s+ (e-s)/2;

    while(s<=e){
        if(isPossible(stalls, k, mid)){
            ans = max(mid, ans);
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid= s+(e-s)/2;

    }
    return ans;

}

int main(){
    vector<int> stalls = {4,2,1,9,8};
    int k=3;
    int ans = aggressiveCows(stalls, k);
    cout<<"Largest minimum possible distance between cows is :"<<ans;
    return 0;

    
}