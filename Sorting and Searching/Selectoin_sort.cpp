#include<iostream>
#include<algorithm>
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
    {   int min=i;
        
        for (int j = i+1; j < m ; j++)
        {
            if(arr[min]>arr[j]){
                min= j;
            }
            
        }
        swap(arr[min],arr[i]);       


        
    }
    
    

    cout<<"\nSorted elements of the array are\n";
    for(int i=0;i<m;i++)
    {
       cout<<arr[i]<<endl;
    }
      
      return 0;
}