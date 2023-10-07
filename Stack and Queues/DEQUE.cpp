#include<iostream>
using namespace std;
#define max 10
int deque[max];
int front=-1;
int rear=-1;


void insert_rear(){
    int val;
    if(( front==0&&rear==max-1)||(front>rear)){
        cout<<"Overflow"<<endl;
    }
    else {
        cout<<"Enter value"<<endl;
        cin>>val;
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
        }
        else {
            if(rear==max-1){
            rear=0;
            }
            else{
                rear++;
            }
        }
        deque[rear]=val;
    }
    
}


void insert_front(){
    int val;
    if((front==0&&rear==max-1)||(front>rear)){
        cout<<"Overflow"<<endl;
    }
    else {
        cout<<"Enter value"<<endl;
        cin>>val;
        if(front==-1&&rear==-1){
            front=0;
            rear=0;
        }
        else {
            if(front==0){
            front=max-1;
            }
            else{
                front--;
            }
        }
        deque[front]=val;
    }
    
}

void delete_front(){
    if(front==-1){
        cout<<"Queue is empty\n";
    }
    else{
        if(front==rear){
            rear=front=-1;
        }
        else if(front==max-1){
            front=0;
        }
        else{
            front++;
        }
    }

}

void delete_rear(){
    if(rear==-1){
        cout<<"Queue is empty\n";
    }
    else{
        if(front==rear){
            rear=front=-1;
        }
        else if(rear=0){
            rear=max-1;
        }
        else{
            rear--;
        }
    }

}

void display(){
    if(front==-1&&rear==-1){
        cout<<"Queue is empty\n";
    }
    else{
        while (front<=rear)
        {
            cout<<deque[front]<<endl;
            front++;
        }

        
    }
}


int main(){
    int i,ch;

    cout<<" 1.Insert_rear\n 2.Insert_front\n 3.Delete_rear\n 4.Delete_front\n 5.Display\n 6.Exit\n";
   
   while (1){
    cout<<"Enter your choice!!\n";
    cin>>ch;
    switch (ch)
    {
    case 1:
        insert_rear();
        break;
    case 2:
        insert_front();
        break;
    case 3:
        delete_rear();
        break;
    case 4:
        delete_front();
        break;
    case 5:
        display();
    case 6:
        exit(0);
    default:
    cout<<"Enter valid choice!!\n";
        break;
    }
   }
   return 0;

}