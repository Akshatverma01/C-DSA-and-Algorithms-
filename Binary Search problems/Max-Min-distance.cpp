#include<iostream>
#include<algorithm>
using namespace std;


// Given an array with n elements that represents n positions along a straight line.
// Find K elements such that the min distance between any 2 elements is max possible ( pair wise distance is atleast k)

// 1 sort array i binary search technique
// 2 Pick middle element as result & check for its feasibility
// 3 if feasible , search th right half of the array with larger minimun distance
// 4 else , search the left half of the is_array
// ex. arr= [11,2,7,5,1,12]   k=3
//  sorted arr=[1,2,5,7,11,12] 
//  left=1 , rigt = 12 , mid=6 (not feasible)
//  left =1 , right =6, mid=3 =>(1,5,11) (feasible)distance>min-dis i,e. mid=3
//  right half: left=3, right=6 , mid=4 => (1,5,11)
//  left=4, right=6, mid=5 =>(1,7,12)

bool isFeasible(int mid, int arr[], int n, int k){
    // Find that arr consists atleast k elements of mid distance

    int pos = arr[0], element =1;
    for(int i =1 ; i<n; i++){
        if (arr[i] - pos  >= mid)
        {
            pos = arr[i];
            element++;
            if(element == k){
                return true;
            }
        }        
    }
    return false;
}

int largestMinDis(int arr[], int n, int k){
    
    sort(arr, arr+n);
    int result = -1;
    int left =1;
    int right= arr[n-1];
    while (left < right)
    {
        int mid = (left + right)/2;
        if(isFeasible(mid, arr, n, k)){
            result = max(result, mid);
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return result;
}

int main(){
    int arr[] = {1,2,8,4,9};
    int n =5, k=3;

    cout<<"Largest min distance is :"<<largestMinDis(arr, n, k)<<endl;
    return 0;
}