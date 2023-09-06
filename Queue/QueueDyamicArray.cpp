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
        void doubleArraySize();
};
Queue::Queue(){}
Queue::Queue(int cap){
    capacity = cap;
    rear = -1;
    front = -1;
    ptr = new int[capacity];
}
void Queue::doubleArraySize(){
    this->capacity *=2;
    int *temp = new int[capacity];
    for(int i=0;i<this->capacity/2;i++)
        temp[i] = ptr[i];
    ptr = temp;
}
void Queue::enQueue(int data){
    if(isQueueEmpty()){
        front=0;
        rear=0;
        ptr[rear] = data;
    }else if(isQueueFull()){
        this->doubleArraySize();
        rear++;
        ptr[rear] = data;
    }else if(front>0 && rear == capacity-1){
        rear = 0;
        ptr[rear]=data;
    }
    else{
        rear++;
        ptr[rear] = data;
    }   
}
bool Queue::isQueueFull(){
    if((rear == capacity-1 && front==0)||(rear<front && front-rear==1))
        return true;
    return false;
}
bool Queue::isQueueEmpty(){
    if(rear==-1 && front==-1)
        return true;
    return false;
}
void Queue::view(){
    if(isQueueEmpty()){
        cout<<"Queue is Empty\n";
    }else if(rear==front){
            cout<<ptr[rear]<<" ";
    }else if(isQueueFull()){
        for(int i=0;i<=capacity-1;i++)
            cout<<ptr[i]<<" ";
        cout<<endl;
    }else if(rear<front){
        for(int i=0;i<=rear;i++)
            cout<<ptr[i]<<" ";
        for(int i=front;i<=capacity-1;i++)
            cout<<ptr[i]<<" ";
    }else if(front<rear){
        for(int i = front;i<=rear;i++)
            cout<<ptr[i]<<" ";
    }
}
int Queue::deQueue(){
    int deletedData = ptr[front];
    if(isQueueEmpty()){
        cout<<"Queue is Empty\n";
        return -1;
    }else if(rear==front){
        this->front = -1;
        rear=-1;
    }else if(front == capacity-1){
        front=0;
    }else{
        front++;
    }
    return deletedData;
}
int Queue::count(){
    int count = 0;
    if(isQueueEmpty()){
        count = 0;
        cout<<"Queue is Empty\n";
    }else if(rear==front){
        count = 1;
    }else if(isQueueFull()){
        count = capacity;
    }else if(rear<front){
        for(int i=0;i<=rear;i++)
            count++;
        for(int i=front;i<=capacity-1;i++)
            count++;
    }else if(front<rear){
        for(int i = front;i<=rear;i++)
            count++;
    }
    return count;
}
int main(){
    Queue q(5);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);
    cout<<q.count()<<endl;
    q.view();
    return 0;
}
