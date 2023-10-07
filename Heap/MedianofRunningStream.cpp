#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define vi vector<int>

using namespace std;

// Numebers are coming and tell the median after each input

priority_queue<int, vi,greater<int> > pqmin;
priority_queue<int, vi> pqmax;

void insert(int x){
    if(pqmin.size() == pqmax.size()){
        // chaeck for first element i.e, empty heap
        if(pqmax.size() == 0){
            pqmax.push(x);
            return;
        }

        if(x < pqmax.top()){
            pqmax.push(x);
        }
        else{
            pqmin.push(x);
        }  
    }
    else{
        // two cases 
        // 1: Size of max-heap > min-heap
        // 2. Size of min-heap < max-heap

        if(pqmax.size()> pqmin.size()){
            if( x > pqmax.top()){
                pqmin.push(x);
            }
            else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);

            }
        }
        else{
            if(x< pqmin.top()){
                pqmax.push(x);
            }
            else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);

            }
        }

    }
}

double findMedian(){
    if(pqmax.size() == pqmin.size()){
        return (pqmin.top() + pqmax.top()) / 2.0;
    }
    else if(pqmax.size() > pqmin.size()){
        return pqmax.top();
        
    }
    else{
        return pqmin.top();
    }
}

 int main(){

    insert(10);
    insert(15);
    insert(20);
    insert(25);
    cout<<findMedian()<<endl;

    return 0;
 }