#include<iostream>
#include<vector>
#include<algorithm>
#define vi vector<int>

using namespace std;

void heapify(vi &a, int n, int i){
    int maxIdx = i;
     int l= 2*i+1;
     int r= 2*i+2;
     
     if(l<n && a[l] > a[maxIdx]){
        maxIdx= l;
     }

     if(r<n && a[r] > a[maxIdx]){
        maxIdx=r;
     }

     if(maxIdx != i){
        swap(a[i], a[maxIdx]);
        heapify(a,n,maxIdx);


     }
}

void heapSort(vi &a){
    int n=a.size();

// Max heap
    for(int i=(n/2)-1; i>=0;i--){
       heapify(a,n,i);
    }

// Heap sort
    for(int i=n-1; i>=0 ;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);

    }
}



int main(){
    int n;
    cin>>n;

    vi a(n);
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    heapSort(a);
    for(int i=0; i<n;i++){
        cout << a[i]<<" ";
    }
    
    return 0;
}