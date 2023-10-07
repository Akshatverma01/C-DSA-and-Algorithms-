#include<iostream>
#include<vector>
using namespace std;

// given two arrays and find the sum of the digits of both array as in maths   2 3 4 5 6
// 1. array1 is large tan 2                                                    +     3 4  
// 2. array2 is large                                                        // 2 3 4 9 0
// 3. carry remain
vector<int> reverse(vector<int> v){
    int s=0, e=v.size()-1;

    while (s<=e)
    {
        swap(v[s++], v[e--]);
    }
    return v;
    
}

vector<int> sumOfTwoArray(vector<int>a1,int n ,vector<int>a2, int m){

    vector<int>ans;
    int i=n-1, j=m-1;
    int carry=0 , sum=0;
    
    while (i>=0 && j>=0  ){

        sum= a1[i] + a2[j];

        carry = sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--; j--;
    }

    while(i>=0){
        sum= a1[i] + carry ;

        carry = sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--; 
    }


    
    while(j>=0){
        sum= a2[j] + carry ;

        carry = sum/10;
        sum=sum%10;
        ans.push_back(sum);
        j--; 
    }

    while(carry !=0){
        sum = carry; 
        carry = sum/10;
        sum=sum%10;
        ans.push_back(sum);
    }

     return reverse(ans);


}

int main(){

int n,m,x;
vector<int>a1;
vector<int>a2;
cin>>n;
for(int i=0; i<n;i++){
    cin>>x;
    a1.push_back(x);
}

cin>>m;
for(int i=0; i<m;i++){
     cin>>x;
    a2.push_back(x);
}

vector<int> sum = sumOfTwoArray(a1,n,a2,m);

for(int i= 0; i<sum.size() ; i++){
    cout<<sum[i]<<" ";
}


    return 0;
}