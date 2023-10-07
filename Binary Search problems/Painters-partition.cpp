#include<iostream>
#include<climits>
using namespace std;

int findFeasible(int boards[], int n, int limit){
    int lenSum=0, painters =1;
    for (int  i = 0; i < n; i++)
    {
        lenSum += boards[i];
        if(lenSum >limit){
            lenSum = boards[i];
            painters++;
        }
    } 
    
    return painters;
}

int paintersPart(int boards[],int n, int m){
    int totalLen = 0, k=0;
    for (int i = 0; i < n; i++)
    {
        k = max(k,boards[i]);
        totalLen += boards[i];
    }
    int low =k, high = totalLen;
    while (low<high)
    {
        int mid = (low+high)/2;
        int painters = findFeasible(boards,n, mid);
        if(painters <= m){
            high = mid;
        }
        else{
            low= mid+1;
        }
    }
    return low;
    

}

int main(){
    int arr[] = {10,20,30,40};
    int n=4,m=2;

    cout<<"Min time to paint boardrs:"<<paintersPart(arr,n,m)<<endl;
    return 0;
}