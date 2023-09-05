#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class node{
    public:
        int item;
        node *next;
};
class Stack{
    private:
        node *start;
        void deleteFirstNode();
    public:
        Stack();
        ~Stack();
        void view();
        void push(int);
        int pop();
        int peek();
};
Stack::Stack(){
    start=NULL;
}
Stack::~Stack(){
    while(start)
        deleteFirstNode();
}
void Stack::view(){
    if(start==NULL)
        cout<<"Stack is Empty\n";
    else{
        node *t = start;
        while(t!=NULL){
            cout<<t->item<<" ";
            t=t->next;
        }
        cout<<endl;
    }
}
void Stack::deleteFirstNode(){
    if(start == NULL){
        cout<<"Stack is Empty\n";
        return;
    }else{
        node *t = start;
        start = t->next;
        delete t;
    }
}
void Stack::push(int data){
    node *n = new node();
    n->item = data;
    n->next = NULL;
    if(start == NULL){
        start = n;
    }else{
        node *t = start;
        while(t->next!=NULL)
            t=t->next;
        t->next = n;
    }
}
int Stack::pop(){
    if(start == NULL){
        cout<<"Stack is Empty\n";
        return -1;
    }else{
        node *t = start;
        node *t1 = NULL;
        while(t->next!=NULL){
            t1=t;
            t=t->next;
        }
        if(t1!=NULL)
            t1->next = NULL;
        else
            start = NULL;
        int deletedItem = t->item;
        delete t;
        return deletedItem;
    }
}
int Stack::peek(){
    if(start == NULL){
        cout<<"Stack is Empty\n";
        return -1;
    }else{
        node *t = start;
        while(t->next!=NULL)
            t=t->next;
        return t->item;
    }
}
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<"Peek: "<<s.peek()<<endl;
    s.view();
    s.pop();
    s.view();
    cout<<"Peek: "<<s.peek()<<endl;

    return 0;
}
