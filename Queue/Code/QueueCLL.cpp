#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class node{
    public:
        int item;
        node *next;
};
class CLL{
    private:
        node *start;
    public:
        CLL();
        ~CLL();
        void view();
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        node* searchNode(int);
        void deleteLastNode();
        void deleteFirstNode();
        int deleteNode(node*);
        bool isEmpty();
        int count();
};
CLL::CLL(){
    start = NULL;
}
CLL::~CLL(){
    while(start)
        deleteFirstNode();
}
bool CLL::isEmpty(){
    if(start == NULL)
        return true;
    return false;
}
int CLL::count(){
    int count = 0;
    if(isEmpty()){
        cout<<"List is Empty\n";
        return -1;
    }else{
        node *t = start;
        do{
            count++;
            t=t->next;
        }while(t!=start);
        return count;
    }
}
void CLL::view(){
    if(start==NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        do{
            cout<<t->item<<" ";
            t=t->next;
        }while(t!=start);
        cout<<endl;
    }
}
void CLL::insertAtLast(int data){
    node *n = new node;
    n->item = data;
    if(start == NULL){
        start = n;
        n->next = n;
    }else{
        n->next = start;
        node *t = start;
        while(t->next!=start)
            t=t->next;
        t->next = n;
    }
}
node* CLL :: searchNode(int data){
    node *t = start;
    do{
        if(t->item == data)
            return t;
        t = t->next;
    }while(t!=start);
    cout<<"Node Not Found\n";
    return NULL;
}
void CLL::deleteFirstNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        node *r = start;
        while(t->next!=start)
            t=t->next;
        t->next = start->next;
        start = start->next;
        delete r;
    }
}
class Queue:public CLL {
    public:
        Queue();
        ~Queue();
        void viewQueue();
        void enQueue(int);
        void deQueue();
};
Queue::Queue():CLL(){
}
Queue::~Queue(){
}
void Queue::enQueue(int data){ 
    this->insertAtLast(data);
}
void Queue::deQueue(){
    if(isEmpty()){
        cout<<"Queue is Empty\n";
        return;
    }
    this->deleteFirstNode();
}
void Queue::viewQueue(){
    if(isEmpty()){
        cout<<"Queue is Empty\n";
        return;
    }
    else
        view();
}
int main(){
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.view();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.view();
    return 0;
}
