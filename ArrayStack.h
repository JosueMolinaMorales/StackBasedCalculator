/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayStack.h
 * Author: josue m
 *
 * Created on March 3, 2019, 10:22 AM
 */

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "StackADT.h"

const int SIZE = 50;

template <class T>
class ArrayStack : StackADT<T> {
public:
    ArrayStack();
//    ArrayStack(const ArrayStack& orig);
//    virtual ~ArrayStack();
    
    //interface methods
    bool isEmpty() const;
    bool push(const T& newItem);
    bool pop();
    T peek() const;
    
private:
//    static const int SIZE = 50;
    T items[SIZE];
    int top;
};

#include "ArrayStack.cpp"
#endif /* ARRAYSTACK_H */

