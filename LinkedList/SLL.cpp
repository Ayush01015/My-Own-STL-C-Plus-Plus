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
};
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
        while(n->next!=NULL)
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
int main(){
    
    return 0;
}
