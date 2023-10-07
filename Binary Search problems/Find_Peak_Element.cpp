// Peak element is greater than its neighbours.
// cases::1=>Ascending order array= last element is peak
        //2=>Des orded array= first elemt is peak
        //3=>mix array

// Use binary search from 0 to n-1
// Compute mid & for each mid check if it is peak  and return
// case1: if arr[mid-1] > arr[mid] check left for peak
// case2: if arr[mid] < arr[mid+1] check right for peak

#include<iostream>
#include<climits>
using namespace std;

int findPeak(int arr[], int start, int end, int n){
     
     int mid= start + (end-start)/2;
    if(( mid==0 || arr[mid-1] <= arr[mid] )&& (mid== n-1 || arr[mid+1] <= arr[mid]))
    {   return mid;}

    else if(mid>0 && arr[mid-1] > arr[mid]){
        return findPeak(arr, start, mid-1, n);
    }
    else{
    return findPeak( arr, mid+1, end,n);
    }

}

int main(){
    int arr[]= {0,6,8,5,7,9};
    int n=6;
    
    cout<<"Peak element index : "<< findPeak(arr, 0, n-1,n);
    return 0;
}