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
        while(t!=NULL){
            cout<<t->item<<" ";
            t=t->next;
        }
        cout<<endl;
    }
}
void DLL::insertAtLast(int data){
    node *n = new node;
    n->item = data;
    n->next = NULL;
    n->prev = NULL;
    if(start == NULL)
        start = n;
    else{
        node *t = start;
        while(t->next!=NULL)
            t=t->next;
        t->next = n;
    }
}
void DLL::insertAtFirst(int data){
    node *n = new node;
    n->item = data;
    n->next = start;
    n->prev = NULL;
    start = n;
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
    while(t!=NULL){
        if(t->item == data)
            return t;
        t = t->next;
    }
    cout<<"Node Not Found\n";
    return NULL;
}
void DLL :: deleteLastNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else if(start->next == NULL){
        delete start;
        start = NULL;
    }
    else{
        node *t = start;
        while(t->next!=NULL)
            t = t->next;
            t->prev->next = NULL;
            delete t;
    }
}
void DLL::deleteFirstNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        start = t->next;
        delete t;
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
        start = r->next;
    }
    else{
        while(r!=t->next)
            t=t->next;
        t->next = r->next;
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
    l.insertAtFirst(999);
    l.view();
    node *s = l.searchNode(40);
    l.insertAfter(s,555);
    l.view();
    l.deleteLastNode();
    l.view();
    node *s1 = l.searchNode(10);
    int deletedData = l.deleteNode(s1);
    cout<<"Deleted Node: "<<deletedData<<"\n";
    l.view();
    l.deleteFirstNode();
    l.view();
    return 0;
}
