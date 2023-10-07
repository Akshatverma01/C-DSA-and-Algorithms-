#include<iostream>
using namespace std;

void merge(int a1[], int n, int a2[], int m, int a3[]){
    int k=0,i=0,j=0;
    while(i<n && j<m){

            if(a1[i]<=a2[j]){
                a3[k++]= a1[i++];
            
            }
            else {
                a3[k++]= a2[j++];
               
            }
    }
    
    if(i<n ){
        while(i<n){    a3[k++]=a1[i++];    }
    }

   if(j<m ){
    while(j<m){
        a3[k++]= a2[j++];
    }
   }
//    return k;
}

int main(){
    int arr1[]= {1,3,5,7,9};
    int arr2[]= {2,4,6};
    int arr3[]={0};
    
    merge(arr1, 5, arr2, 3, arr3);

        for(int i=0; i< 8;i++){
            cout<<arr3[i]<<" ";
        }

    return 0;
}