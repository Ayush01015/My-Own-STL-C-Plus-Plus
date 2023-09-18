#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class _Vector{
private:
    int capacity;
    int lastIndex;
    int *ptr;
public:
    _Vector(){}
    _Vector(int size){
        this->capacity = size;
        this->lastIndex = -1;
        this->ptr = new int[size];
    }
    ~_Vector(){
        delete this->ptr;
        delete this;
    }
    _Vector* Create_Vector(int size){
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
    bool _Vector::isFull()
    {
        return lastIndex==capacity-1;
    }
    void insert(int index,int data){
        if(index<0 || index>lastIndex+1)
            cout<<"Invalid Index\n";
        else{
            if(isFull())
                double_Vector();
            for(int i=lastIndex; i>=index; i--)
                this->ptr[i+1] = ptr[i];
            this->ptr[index] = data;
            lastIndex++;
        }
    }
    void remove(int index){
        if(this->lastIndex == -1)
            cout<<"_Vector is Empty\n";
        else if(index<0 || index>lastIndex+1)
            cout<<"Invalid Index\n";
        else if(lastIndex+1 >= capacity/2 && capacity>1)
            half_Vector();
        else{
            for(int i=index+1;i<=lastIndex;i++)
                ptr[i-1] = ptr[i];
            lastIndex--;
        }
    }
    int getElement(int index){
        if(this->lastIndex == -1)
            cout<<"_Vector is Empty\n";
        else if(index<0 || index>lastIndex+1)
            cout<<"Invalid Index\n";
        else
            return ptr[index];
    }
    int count(){
        return this->lastIndex+1;
    }
    int search(int item){
        for(int i=0;i<=this->lastIndex;i++)
            if(this->ptr[i]==item)
                return i;
            return -1;
    }
    void double_Vector(){
        capacity*=2;
        int *temp = new int[capacity];
        for(int i=0;i<=lastIndex;i++)
            temp[i] = ptr[i];
        delete []ptr;
        ptr = temp;
    }
    void half_Vector(){
        capacity/=2;
        int *temp = new int[capacity];
        for(int i=0;i<=lastIndex;i++)
            temp[i] = ptr[i];
        delete []ptr;
        ptr = temp;
    }
};
int main(){
    _Vector arr(5);
    arr.Create_Vector(5);
    arr.insert(0,10);
    arr.insert(1,20);
    arr.insert(2,30);
    arr.insert(3,40);
    arr.insert(4,50);
    arr.insert(5,60);
    arr.view();
    arr.remove(3); 
    // arr.view();
    return 0;
}
