#include<iostream>
using namespace std;

int binary_search(int a[], int beg,int end, int x){
    int mid =(beg+end)/2;

    if(x<a[mid]){
        binary_search(a,beg,mid,x);
    }
    else if(x > a[mid]){
        binary_search(a, mid+1, end,x);
    }
    else{
        return mid;
    }
       return;

}

int main(){
    
    int n,x;
    int a[n];
    cout<<"Enter size of array\n";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    cout<<"\nEnter the element you want to search:\n";
    cin>>x;
    cout<<"Element found at"<<binary_search(a,0,n,x);
    return 0;
        
} 