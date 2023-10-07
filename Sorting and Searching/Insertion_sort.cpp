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
  
    for (int i = 1; i < m; i++) 
    {
        int temp= arr[i];
        int j= i-1;
        while (j>=0 && arr[j] > temp){
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1]= temp; 
    }
    

    cout<<"\nSorted elements of the array are\n";
    for(int i=0;i<m;i++)
    {
       cout<<arr[i]<<endl;
    }
      
      return 0;
}