#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int>& nums){

    int count=0;
    int n=nums.size();
    for (int i = 1; i < n; i++)
    {
        if(nums[i-1]>nums[i]) count++;
    }
    
    if(nums[n-1] >nums[0])
    count++;

    return count<=1;
}

int main(){

    vector<int> arr;
    
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    // arr.push_back(18);
    // arr.push_back(9);
    // arr.push_back(11);
    int n=6;

    if(check(arr)){
        cout<<"The array is sorted and rotated "<<endl;
    }
    else{
        cout<<"Neither sorted nor rotated"<<endl;
    }

    return 0; 
}