#include<iostream>
#include<algorithm>
using namespace std;
 
//  Given an array with n elements that represent n positions along a straight line.
// Find k elements such that the minimum distance b/w any 2 elements  is the maximum possible
// e.g. :: 1,2,3,4,5--->(1,5)


// Approach 1
// Find all possible subsets of size k & compare the min distance b/w all of them

// Approach2 Binary search 
// 1. sort array as a binary search 
// 2.pick middle as a result and check for feasibility.
// 3.If feasible, search the right half of the array with large minimum distance.
// 4.Else, search the left half of the array.


bool isFeasible(int mid,int arr[], int n, int k){
    int pos=arr[0] ,elements= 1;
     
     for(int i=1;i<n;i++){
        if(arr[i]-pos>=mid){
            pos=arr[i];
            elements++;
            if(elements==k){
                return true;
            }
           
        
        }
     }
     return false; 
}


int largestMinDistance(int arr[], int n, int k){

    sort(arr, arr+n);

    int result=-1;
    int left= 1 ,right = arr[n-1];

    while(left<right){
        int mid = (left+right)/2;

        if(isFeasible(mid, arr, n, k)){
            result = max(result, mid); 
            left= mid+1;
              
        }
        else{
            right=mid;
        }
    }
        return result;
}

int main(){
    int arr[]= {1,2,8,4,9};
    int n=5;
    int k=3;
    cout<<"Largest min distance is:"<<largestMinDistance(arr,n,k)<<endl;
    return 0;
}

