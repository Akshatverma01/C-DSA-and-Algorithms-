#include<iostream>
#include<climits>
using namespace std;

// 1. Given sorted array,rotated from a pivot point(unknown) and X
// 2.Search X in sorted array with complexity less than that of linear search
// Orignal array= [10,20,30,40,50]
// Roatated array = [30,40,50,10,20]
// X=10 ans=3(index)

// 1Find pivot element
// 2 apply BS in left half
// 3 Apply BS in right half
// 4 pivot logic :: arr[i]>arr[i+1]

int searchInRotatedArray(int arr[], int key, int left, int right){

    if(left>right){
        return -1;
    }
    int mid = (left+right)/2;
    if(arr[mid] == key){
        return mid+1;
    }

// Pivot condition:: If left < mid/right element
    if(arr[left] <= arr[mid]){
        if( key >= arr[left ]&& key <=arr[mid]){
            return searchInRotatedArray(arr, key, left, mid-1);
        }
        return searchInRotatedArray(arr, key, mid+1,right);
    }
    // If it obey the ascending order
    if (key>= arr[mid] && key <= arr[right])
    {
        return searchInRotatedArray(arr,key , mid+1, right);
    }
    return searchInRotatedArray(arr, key,left, mid-1);
    
}

int main(){

    int arr[]= {6,7,8,9,10,11,15,20,35,1,2,5};
    int n=8;
    int key=15;

    int i = searchInRotatedArray(arr, key, 0,n-1);
    if(i==-1){
        cout<<"Key doesn't exits\n";
    }
    else{
        cout<<"KEy exsts at:\n"<<i;
    }
    return 0;
}