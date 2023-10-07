#include<iostream>
#include<algorithm>
using namespace std;

void reverse(int arr[], int n ,int s, int e){
    if(s==e){
        return;
    }
    swap(arr[s],arr[e]);
    reverse(arr,n,s+1,e-1);
}

int main(){
    int arr[]={12,22,45,98,43,67,22};

    // after 3rd index
    reverse(arr,7,2,6);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}