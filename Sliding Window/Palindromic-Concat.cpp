#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Check if the subarray of size K such that concatination of elements form a palindrome

// Store concat of initial K elements
// Iterate over array & start del elements from strat and add from end
// Check if concat is palindrome

bool isPalindrome(int n){
    int temp=n, number=0;
    while (temp>0)
    {
        number = number*10 + temp%10;
        temp = temp/10;
    }

    if(number == n){
        return true;
    }
    return false;
    
}

int findPalindrome(vector<int>arr, int k){
    int num=0;

    for(int i=0; i<k;i++){
        num = num*10+ arr[i];
    }

    if(isPalindrome(num)){
        return 0;
    }

    for(int j=k; j<arr.size(); j++){
        num = (num % (int)pow(10,k-1))*10 + arr[j];

        if(isPalindrome(num)){
        return j-k+1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {1,2,35,6,2,2,6};
    int k=4;
    int ans = findPalindrome(arr,k);

    if(ans==-1){
        cout<<"Palindrome subarray dosnot exists"<<endl;

    }
    else{
        for(int i=ans; i < ans+k ;i++){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}