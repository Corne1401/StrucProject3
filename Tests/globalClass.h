#ifndef GLOBALCLASS_H
#define GLOBALCLASS_H

#include <iostream>

class testClass{
public:
    explicit testClass(int data){
        this->data1 = data;
    }
    int getData1(){
        return data1;
    }
private:
    int data1;
};

#endif // GLOBALCLASS_H
