#include<iostream>
#include<climits>
using namespace std;

// The max sum of an subarray of size K and sum < X(given) 

// Calculate sum of first  K elements
// Initialize ans with this sum and chexk ifless than X
//  and sliding to new window as:
// iterarte over the rest of array . keep adding on element in sum & removing one from start
// Compare new sum with its ans in each iteration

// O(n);

void maxSubarrSum(int arr[], int n,int k, int X){
    int sum=0, ans=0;

    for(int i=0; i<k;i++){
        sum += arr[i];

    }

    if(sum<X){
        ans=sum;
    }

    for (int  i = k; i < n; i++)
    {
        sum -= arr[i-k];
        sum+= arr[i];

        if(sum< X){
            ans = max(ans, sum);
        }
    }
    
    cout<<ans<<" is the max sum possible for a "<< k<<" sized subarray\n";
}


int main(){
    int arr[] ={0,5,4,6,9,8 };
    int n=6;
    int k=3;
    int X= 10;

    maxSubarrSum(arr, n, k, X);
    return 0;


}