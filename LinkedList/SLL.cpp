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
void SLL::insertAtLast(int data){
    node *n = new node;
    node *t = start;
    n->item = data;
    n->next = NULL;
    if(start == NULL)
        start = n;
    else{
        while(n->next!=NULL)
            t=t->next;
        t->next = n;
    }
}
int main(){
    
    return 0;
}
