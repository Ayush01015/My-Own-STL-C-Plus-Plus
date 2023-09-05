#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Queue{
    private:
        int capacity;
        int rear,front;
        int *ptr;
    public:
        Queue();
        Queue(int);
        void view();
        void enQueue(int);
        bool isQueueFull();
        bool isQueueEmpty();
        int deQueue();
        int getRear();
        int getFront();
        int count();
};
Queue::Queue(){}
Queue::Queue(int cap){
    capacity = cap;
    rear = -1;
    front = -1;
    ptr = new int[capacity];
}
void Queue::enQueue(int data){
    if(isQueueEmpty()){
        front=0;
        rear=0;
        ptr[rear] = data;
    }else if(isQueueFull()){
        cout<<"Queue is Full\n";
    }else if(front>0 && rear == capacity-1){
        rear = 0;
        ptr[rear]=data;
    }
    else{
        rear++;
        ptr[rear] = data;
    }   
}

int main(){
    
    return 0;
}
