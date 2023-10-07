// FInd minimum subarray size for which sum>X

// USe ans,sum,start
//1 Iterate over array & start adding elements to sum
//2 Iterarte over array and start adding elements to the sum
//3 If sum>X , remove elemets from start
#include<iostream>
using namespace std;

int smallestSubarraySum(int arr[], int n, int X){
    int sum=0, minLen = n+1, start=0, end=0;

    while (end<n)
    {
        while (sum <= X && end <n )
        {
            sum+= arr[end++];
        }

        while (sum>X && start<n)
        {
            if(end-start < minLen){
                // updating the size of smallest subarray
                minLen= end-start;
            }

            sum-= arr[start++];
            
        }
        
        
    }
    
return minLen;
}

int main(){
    int arr[]= {1,4,45,6,10,19};
    int X=51;
    int n=6;

    int minLength= smallestSubarraySum(arr, n, X);

    if(minLength==n+1){
        cout<<"No such subarray exists\n";
    }
    else{
        cout<<"Smallest subarray is :"<<minLength;
    }

    return 0;

}