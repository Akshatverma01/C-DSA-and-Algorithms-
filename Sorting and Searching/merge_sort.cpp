#include<iostream>
#define n 20

using namespace std;
int arr[n];
int temp[n];
void merge(int arr[], int beg, int mid, int end);

void merge_sort(int arr[], int beg, int end){
    int mid;
    if(beg<=end){
        mid=(beg+end)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,beg ,mid,end);
    }
}

  
void merge(int arr[], int beg, int mid, int end){
    int i=beg;
    int j=mid+1;
    int index=0;
    while((i<=mid)&&(j<=end)){
        if(arr[i]<arr[j])
        {   
            temp[index]=arr[i];
            index++;
            i++;
        }
        else{
            temp[index]=arr[j];
            index++;
            j++;
        }
    }
    if(i>mid){
        while(j<=end){
            temp[index]=arr[j];
            index++;
            j++;
        }
    }
    else{
        while(i<=mid){
            temp[index]=arr[i];
            index++;
            i++;
        }
    }
    // int k=0;
    // while(k<=index)
    // {
    // arr[k]=temp[k];
    // k++;
    // }
}

int main(){
    int m;
   cout<<"Enter the size of the array\n";
    cin>>m;
    cout<<"\nEnter the elements of the array\n";
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr,0,m-1);

    cout<<"\nSorted elements of the array are\n";
    for(int i=0;i<m;i++)
    {
       cout<<temp[i]<<endl;
    }
      
      return 0;
}
