#include<iostream>
using namespace std;

int main(){
    int arr[]= {1,0,2,0,3,0,4,0};
    int n=8, k=0,j=0;
    for(int  i=0; i<n; i++){
       if(arr[i] != 0){
        swap(arr[i], arr[j]);
        j++;
       }
    }
    for (int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
    
}