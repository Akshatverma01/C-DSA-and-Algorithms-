#include<iostream>
using namespace std;

void linear_search(int a[], int n, int x){
    
        cout<<"Element found at\n";
        for (int i = 0; i < n; i++){
        if(a[i]==x){
             cout<<i<<" ";          
           
        }
    }

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
    linear_search(a,n,x);
    return 0;
        
}