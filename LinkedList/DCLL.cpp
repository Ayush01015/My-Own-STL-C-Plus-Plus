#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class node{
    public:
        node* prev;
        int item;
        node *next;
};
class DLL{
    private:
        node *start;
    public:
        DLL();
        ~DLL();
        void view();
        void viewRev();
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        node* searchNode(int);
        void deleteLastNode();
        void deleteFirstNode();
        int deleteNode(node*);
};
DLL::DLL(){
    start = NULL;
}
DLL::~DLL(){
    while(start)
        deleteFirstNode();
}
void DLL::view(){
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
void DLL:: viewRev(){
    if(start==NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        while(t->next!=NULL)
            t=t->next;
            // int x =0;
        do{
            cout<<t->item<<" ";
            t=t->prev;
            // cout<<++x<<endl;
        }while(t!=NULL);
        cout<<endl;
    }
}
void DLL::insertAtFirst(int data){
    node *n = new node;
    n->item = data;
    if(start == NULL){
        n->prev = n; 
        n->next = n;
    }else{
        n->prev = start->prev;
        start->prev->next = n;
        n->next = start;
    }
        start = n;
}
void DLL::insertAtLast(int data){
    node *n = new node;
    n->item = data;
    if(start == NULL){
        n->next = n;
        n->prev = n;
        start = n;
    }else{
        n->next = start;
        n->prev = start->prev;
        start->prev->next = n;
        start->prev = n;
    }
}
void DLL::insertAfter(node *r,int data){
    node *n = new node;
    n->item = data;
    n->prev = r;
    n->next = r->next;
    r->next->prev = n;
    r->next = n;
}
node* DLL :: searchNode(int data){
    node *t = start;
    do{
        if(t->item == data)
            return t;
        t = t->next;
    }while(t!=NULL);
    cout<<"Node Not Found\n";
    return NULL;
}
void DLL::deleteLastNode(){
    node *lastNode = start->prev;
    if(start == NULL){
        cout<<"List is Empty\n";
    }
    else if(start->next == start){
        delete start;
        start = NULL;
    }
    else{
        start->prev = lastNode->prev;
        lastNode->prev->next = start;
        delete lastNode;
    }
}
void DLL::deleteFirstNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else if(start->next == start){
        delete start;
        start = NULL;
    }
    else{
        node *firstNode = start;
        firstNode->next->prev = start->prev;
        start->prev->next = start->next;
        start = start->next;
        delete firstNode;
    }
}
int DLL::deleteNode(node *r){ 
    //function to delete node and it also return deleted value
    node *t = start;
    if(start == NULL){
        cout<<"List is Empty\n";
        return -1;
    }
    else if(start == r){
        r->next->prev = NULL;
        start = r->next;
    }else if(r->next == NULL){
        r->prev->next = NULL;
    }
    else{
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    int deletedValue = r->item;
    delete r;
    return deletedValue;
}
int main(){
    DLL l;
    l.insertAtLast(10);
    l.insertAtLast(20);
    l.insertAtLast(30);
    l.insertAtLast(40);
    l.insertAtLast(50);
    l.insertAtLast(60);
    l.insertAtLast(70);
    // l.deleteLastNode();
    l.insertAtFirst(999);
    l.insertAtFirst(998);
    // l.view();
    // node *t = l.searchNode(20);
    // l.insertAfter(t,6969);
    l.view();
    l.viewRev();
    // cout<<"::"<<l.start->next->item<<" ";
    // l.insertAtFirst(90);
    // l.insertAtLast(80);
    // l.view();
    // l.deleteFirstNode();
    // l.deleteFirstNode();
    // l.deleteLastNode();
    // l.view();
    // int data = l.deleteNode(t);
    // l.view();
    // cout<<data;
    return 0;
}

