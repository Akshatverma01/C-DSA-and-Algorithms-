#include<iostream>

using namespace std;

struct stack{
    int data;
    struct stack*next;
};
struct stack*top=NULL;

struct stack*push(){
    struct stack*newstack=(struct stack*)malloc(sizeof(struct stack*));
    cout<<"Enter the data of stack at top\n";
    cin>>newstack->data;
    
    if(top==NULL){
        top=newstack;
        newstack->next=NULL;
    }
    else{
        
        newstack->next=top;
        top=newstack;
    }
    return top;
}

struct stack*pop(){
    int val;
    struct stack*temp=top;
    if(top==NULL){
        cout<<"\nSTACK underflow\n";
    }
    else{
        val=top->data;
        cout<<"Popped element is" <<val<<endl;
        top=top->next;
        free(temp);
    }
     return top;
}

void display(){
    struct stack*ptr=top;
    if(ptr==NULL){
        cout<<"empty stack\n";
    }
    else{
        while(ptr!=NULL){
            cout<<ptr->data<<endl;
            ptr=ptr->next;
        }
    }

}
int main(){
    int ch;
    do{
        cout<<"\n 1.Push\n 2.Pop\n 3.Display\n 6.Exit \n\nEnter choice\n";
        cin>>ch;

        switch(ch){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            // case 4: peek();
            //         break; 
            // case 5: empty_full();
            //         break;
            case 6: exit(0);

            default:
            cout<<"INVALID CHOICE!!\n";
        }

    }while(ch>0);
    return 0;

}