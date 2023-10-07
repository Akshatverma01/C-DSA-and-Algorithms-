#include<iostream>
using namespace std;
//#define n 50
int front=-1;
int rear=-1;
int queue[100];

void enque(int n){
int x;
if(rear=(n-1))
{
    cout<<"OVERFLOW\n";
 }
else
{
     if(front==-1 && rear==-1){
    
    front=rear=0;
    queue[rear]=x;
    }
    else{
    rear++;
    }
    cout<<"Enter the element to be inserted\n";
    cin>>x;
}
}

void deque(){
    if(front==-1||front>rear){
        cout<<"UNDERFLOW\n";
    }   
    else{
        if(front==rear){
            front=rear=-1;
        }
        else{
            cout<<queue[front]<<"deleted\n";
            front++;
        }
        
    }
}
void display(){
    if(front==-1||front>rear){
        cout<<"UNDERFLOW\n";
    }
    else{
        int x;
        while(front<=rear){
            cout<<queue[front];
            front++;
        }

    }
}


int main(){
    int m,i,ch;
    cout<<"Enter the size of queue\n";
    cin>>m;

while (1){
    cout<<"1.Enque\n 2.Deque\n 3.Display\n";
    cout<<"Enter your choice\n";
    cin>>ch;
    switch (ch)
    {
    case 1:
        enque(m);
        break;
    case 2:
        deque();
        break;
    case 3:
        display();
        break;
    default:
    cout<<"Enter valid choice\n";
        break;
    }
}

return 0;
}