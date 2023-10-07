#include<iostream>
#define n 100
using namespace std;
int stack[n];
int top=-1;

void push(){
    int x;
    if(top==(n-1)){
        cout<<"OVERFLOW\n";
    }
    else{
        
        cout<<"Enter the data:\n";
        cin>>x;
        top=top+1;
        stack[top]=x;
    }
}

void pop(){
    int val;
    if(top==-1){
        cout<<"UNDERFLOW\n";
    }
    else{
        val=stack[top];
        top--;
        cout<<"The popped value is "<<val<<endl;
        
    }    
}

void display(){
    int i;
    if(top==-1){
        cout<<"Empty stack\n";
    }
    for(i=top;i>=0;i--){
        cout<<stack[top]<<endl;
    }
}
void peek(){
    if(top==-1){
        cout<<"UNDERFLOW\n";
    }
    else{
        cout<<stack[top];
    }
}
void empty_full(){
     if(top==-1){
        cout<<"UNDERFLOW\n";
    }
    else if(top==n-1){
        cout<<"OVERFLOW\n";
    }
}

int main(){
    int ch;
    do{
        cout<<"\n 1.Push\n 2.Pop\n 3.Display\n 4.Peek\n 5.Empty or full\n 6.Exit \n\nEnter choice\n";
        cin>>ch;

        switch(ch){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: peek();
                    break; 
            case 5: empty_full();
                    break;
            case 6: exit(0);

            default:
            cout<<"INVALID CHOICE!!\n";
        }

    }while(ch>0);
    return 0;

}