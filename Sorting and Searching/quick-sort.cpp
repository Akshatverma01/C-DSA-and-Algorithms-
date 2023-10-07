#include<iostream>
using namespace std;

int partition(int arr[],int beg, int end);

void quick_sort(int arr[],int beg, int end){
    int loc;
    if(beg<=end){
        loc=partition(arr,beg,end);
        quick_sort(arr,beg,loc-1);
        quick_sort(arr,loc+1,end);
        
    }
}

int partition(int arr[], int beg, int end)
{
    int loc,left,right,flag;
    left=loc=beg;
    right=end;
    flag=0;
    int temp;

    while(flag!=1){
        
        while ((arr[loc]<=arr[right])&&(loc!=right))
        {right--;        }
        if(loc==right)
       { flag=1;}
        else if(arr[loc]>arr[right]){
            temp=arr[loc];
            arr[loc]=arr[right];
            arr[right]=temp;
            loc=right;
        }
        if(flag!=1){
         while ((arr[left]<=arr[loc])&&(loc!=left))
        {left++;        }
        if(loc==left)
        {flag=1;}
        else if(arr[left]>arr[loc]){
            temp=arr[loc];
            arr[loc]=arr[left];
            arr[left]=temp;
            loc=left;
            }
        }

    }
    return loc;

}

int main(){
    int m,temp,i;
    int arr[m];
    cout<<"Enter the size of the array\n";
    cin>>m;
    cout<<"\nEnter the elements of the array\n";
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    quick_sort(arr,0,m-1);

    cout<<"\nSorted elements of the array are\n";
    for(int i=0;i<m;i++)
    {
       cout<<arr[i]<<endl;
    }
      
      return 0;
}
