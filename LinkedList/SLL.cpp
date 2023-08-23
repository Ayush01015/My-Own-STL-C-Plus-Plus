#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class node{
    public:
        int item;
        node *next;
};
class SLL{
    private:
        node *start;
    public:
        SLL();
        void view();
        void insertAtFirst(int);
        void insertAtLast(int);
        void insertAfter(node*,int);
        node* searchNode(int);
        void deleteLastNode();
        void deleteFirstNode();
        node* deleteNode(node*);
};
SLL::SLL(){
    start = NULL;
}
void SLL::view(){
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

void SLL::insertAtLast(int data){
    node *n = new node;
    n->item = data;
    n->next = NULL;
    if(start == NULL)
        start = n;
    else{
        node *t = start;
        while(t->next!=NULL)
            t=t->next;
        t->next = n;
    }
}
void SLL::insertAtFirst(int data){
    node *n = new node;
    n->item = data;
    n->next = start;
    start = n;
}
void SLL::insertAfter(node *r,int data){
    node *n = new node;
    n->item = data; 
    n->next = r->next;
    r->next = n;
}
node* SLL :: searchNode(int data){
    node *t = start;
    while(t!=NULL){
        if(t->item == data)
            return t;
        t = t->next;
    }
    cout<<"Node Not Found\n";
    return NULL;
}
void SLL :: deleteLastNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
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
        delete t;
    }
}
void SLL::deleteFirstNode(){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        start = t->next;
        delete t;
    }
}
node* SLL::deleteNode(node *r){
    if(start == NULL)
        cout<<"List is Empty\n";
    else{
        node *t = start;
        while(r!=t->next)
            t=t->next;
        t->next = r->next;
        delete r;
    }
}
int main(){
    SLL l;
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
    l.deleteLastNode();
    l.deleteLastNode();
    l.deleteLastNode();
    l.deleteLastNode();
    l.deleteLastNode();
    l.deleteLastNode();
    l.deleteLastNode();
    l.view();
    return 0;
}
