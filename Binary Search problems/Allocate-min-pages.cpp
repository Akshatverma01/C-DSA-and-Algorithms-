#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

// n= no. of pages in different books[asc order]
// m= no. of students
 
// All the books have to be divided among m students,consecutively. Allocate the pages in such a way that maximum pages allocated to a student is minimun.


// Apply binary search for minimum and maximum value of "max " pages
// check the feasiblity of this chosen value

// check feas:
// Assign pages to each student in a sequential manner , while the current number of allocated pages don't exceed the value set(mid) by binary search
// if during the allocation the number of students dont exceed the limit of "m" the the solution is feasible .
// else , it is not

bool isPossible(int arr[], int n, int m, int minSum){
    int stdReq = 1, minPAgeSum=0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > minSum)
        {
            return false;
        }
        if(minPAgeSum + arr[i] > minSum){
            stdReq++;
            minPAgeSum = arr[i];
            

            if(stdReq > m){
                return false;
            }


        }
        else{
            minPAgeSum+= arr[i];
        }
        
    }
    return true;
    
}

int allocateMinPages(int arr[], int n, int m){
    int sum =0;
    sort(arr,arr+n);
    if(n<m){
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        sum +=arr[i];
    }

    // start= min all pages, end= max allocated pages
    int start =0, end = sum, ans = INT8_MAX;

    while (start <= end)
    {
     int mid= (start+end)/2;
     if(isPossible(arr, n, m, mid)){
        ans = min(ans, mid);
        end = mid-1;
     }   
     else{
        start = mid+1;
     }
    }
    return ans;   
}

int main(){
    int arr[] = {15,10,19,10,5,18,7};
    int n=7, m=5;
    cout<<"The min. number of pages"<<allocateMinPages(arr, n,m);

    return 0;
}