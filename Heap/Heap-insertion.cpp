#include<iostream>
using namespace std;

// Heap using array

class heap{
    public:
    int arr[100];
    int size =0;

    void insertion(int val){
        size ++;
        int index = size;

        arr[index]= val;

        while(index>1){
            int parent = index/2;
// max heap
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;        
    }

    void delete(){
        if (size == 0)
        {
            cout<<"Empty heap\n";
            return;
        }
        

        
    }
};

int main(){
    heap h;
    h.insertion(50);
    h.insertion(34);
    h.insertion(299);
    h.insertion(392);
    h.insertion(5);
    h.insertion(234);
    h.insertion(10);
    h.print();
    return 0;
}
