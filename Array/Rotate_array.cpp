#include<iostream>
#include<vector>
using namespace std;

int main(){

    int arr[]= {12,45,67,11,20,0,01};
    int n=7;
    int k=3;

    vector<int>ans(n);

    for (int i = 0; i < n; i++)
    {
       ans[(i+k)%n]= arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
    return 0;
}