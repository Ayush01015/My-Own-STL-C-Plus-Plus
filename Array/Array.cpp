
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Array{
private:
    int capacity;
    int lastIndex;
    int *ptr;
public:
    Array(){}
    Array(int size){
        this->capacity = size;
        this->lastIndex = -1;
        this->ptr = new int[size];
    }
    Array* CreateArray(int size){
        this->capacity = size;
        this->lastIndex = -1;
        this->ptr = new int[size];
    }
    void view(){
        cout<<"LastIndex: "<<lastIndex<<"\n";
        for(int i=0;i<=this->lastIndex;i++){
            cout<<this->ptr[i]<<" ";
        }
        cout<<endl;
    }
    void insert(int index,int data){
        if(index<0 || index>lastIndex+1)
            cout<<"Invalid Index\n";
        else if(lastIndex == capacity-1)
            cout<<"Array is Full\n";
        else{
            for(int i=lastIndex; i>=index; i--)
                this->ptr[i+1] = ptr[i];
            this->ptr[index] = data;
            lastIndex++;
        }
    }
    void remove(int index){
        if(this->lastIndex == -1)
            cout<<"Array is Empty\n";
        else if(index<0 || index>lastIndex+1)
            cout<<"Invalid Index\n";
        else{
            for(int i=index+1;i<=lastIndex;i++)
                ptr[i-1] = ptr[i];
            lastIndex--;
        }
    }
};
int main(){
    Array arr(5);
    return 0;
}
