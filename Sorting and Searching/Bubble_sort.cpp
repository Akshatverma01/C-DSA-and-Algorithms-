#include<iostream>
using namespace std;

int main(){
    int m;
   cout<<"Enter the size of the array\n";
    cin>>m;
    int arr[m];
    cout<<"\nEnter the elements of the array\n";
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
  
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m-i; j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr[j+1],arr[j]);
        }
        
    }
    
    

    cout<<"\nSorted elements of the array are\n";
    for(int i=0;i<m;i++)
    {
       cout<<arr[i]<<endl;
    }
      
      return 0;
}