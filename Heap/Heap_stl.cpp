#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define vi vector<int>

using namespace std;


int main(){

    // MAX_HEAP:  are same as priority_queue
    priority_queue<int , vector<int>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);

    cout<<"MAX_HEAP";
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<"MAX_HEAP"<<pq.top()<<endl;

    // MIN_HEAP: priority_queue<int, vector<int>, greter<int> >
     priority_queue<int, vector<int>, greater<int> >pqm;
     pqm.push(2);
     pqm.push(1);
     pqm.push(3);
     cout<<"MIN-HEAP"<< pqm.top() << endl;
     pqm.pop();
     cout<<"MIN-HEAP"<< pqm.top() << endl;



    return 0;


}