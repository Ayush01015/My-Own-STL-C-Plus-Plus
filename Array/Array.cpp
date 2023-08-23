
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
};
int main(){
    Array arr(5);
    return 0;
}
