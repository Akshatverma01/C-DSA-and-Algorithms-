#include<iostream>
#include<vector>
using namespace std;

void FormNumDivByThree(vector<int>arr, int k){

    pair<int,int> ans;
    int sum=0;

    for (int i = 0; i < k; i++)
    {
        sum+=arr[i];

    }
    if(sum %3 ==0){
       ans = make_pair(0,k-1);
               
    }
    bool found = false;

    for (int j = k; j < arr.size(); j++)
    {
        if(found){
            break;
        }
        sum = sum + arr[j] - arr[j-k];

        if(sum%3== 0){
            ans = make_pair(j-k, j);
            found = true;
        }
    }

    if(!found)
    { ans = make_pair(-1, 0);}
    if(ans.first == -1){
        cout<<"No such subarray exists"<<endl;
    }
    else{
        for (int  i = ans.first; i < ans.second; i++)
        {
            cout<<arr[i]<<" ";
        }
        
    }
    
    

}

int main(){
    vector<int> arr= {8,23,45,12,56,4};
    int n=6;
    int k=3;

    FormNumDivByThree(arr,k);
    return 0;
}