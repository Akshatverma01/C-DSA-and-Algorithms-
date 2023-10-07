#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
// Number equal to the sum of its divisors

// Convert array into binary array
// Replace index i with 1 if it is a perfect nmbr else 0
// 1.variable to store sum of divisors
// 2. Traverse every nmbr less than arr[i] and add it to sum if it is a divisor of arr[i]
// 3. if the sum of all divisore is equal to arr[i] then it is a perfect nmbr

int MaxSum(int arr[], int n , int k){
    if(n<k){
        cout<<"Invalid Values"<<endl;
        return -1;
    }
    int res =0;
    for(int i=0;i<k;i++){
            res+= arr[i];
    }

    int sum= res;
    for(int i=k; i<n;i++){
        sum += arr[i]- arr[i-k];
        res = max(sum, res);
    }

    return res;


}
bool isNmbrPerfect(int n){
    int sum=1;
    for(int i=2; i< sqrt(n); i++){
        if(n%i == 0){
            if(i==n/i){
                sum+=i;
            }
            else{
                sum += i+ n/i;
            }
        }
    }

    if(sum == n && n!=1){
        return true;
    }
    return false;
}

int maxPerfectNumber(int arr[], int n ,int k){
    for (int i = 0; i < n; i++)
    {
        if(isNmbrPerfect(arr[i])){
            arr[i]  = 1;
        }
        else{
            arr[i]=0;
        } 
    }
    return MaxSum(arr, n ,k);
}

int main(){
    int arr[]= {28,3,4,6,496,99,8128,24};
    int k=4;
    int n=8;

    cout<<"Max-Number of Perfect Number"<<maxPerfectNumber(arr, n, k);
    return 0;
}