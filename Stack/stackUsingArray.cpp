#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Stack{
    private:
        int capacity;
        int top;
        int *ptr;
    public:
        Stack(int);
        void push(int);
        int pop();
        int peek();
        void view();
};
Stack::Stack(int cap){
    capacity = cap;
    top = -1;
    ptr = new int[capacity];
}
int Stack::peek(){
    if(top==-1){
        cout<<"Stack is Empty\n";
        return -1;
    }
    return ptr[top];
}
void Stack::push(int data){
    if(top==capacity-1){
        cout<<"Stack is Full\n";
        return;
    }
    top++;
    ptr[top] = data;
}
int Stack::pop(){
    if(top==-1){
        cout<<"Stack is Empty\n";
        return -1;
    }
    else{
        top--;
        return ptr[top+1];
    }
}
void Stack::view(){
    if(top==-1){
        cout<<"Stack is Empty\n";
        return;
    }
    cout<<"TOP: "<<top<<"\n";
    for(int i=0;i<=top;i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
}
int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    
    
    
    return 0;
}
