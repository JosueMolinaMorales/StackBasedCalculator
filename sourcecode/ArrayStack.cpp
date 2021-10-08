/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/** 
 * @file:   ArrayStack.cpp
 * @author: cwood
 * @class:  ArrayStack
 * 
 * Created on March 3, 2019, 10:22 AM
 */

#include <cassert>
#include "ArrayStack.h"
#include "StackException.h"

template <class T>
ArrayStack<T>::ArrayStack() : top(-1) {
//    top = -1;
}

//ArrayStack::ArrayStack(const ArrayStack& orig) {
//}
//
//ArrayStack::~ArrayStack() {
//}

template <class T>
bool ArrayStack<T>::isEmpty() const {
    return (top < 0);
}
template <class T>
T ArrayStack<T>::peek() const {
    //If isEmpty(), what do I return?
    //use precondition, if it fails program halts
    assert(!isEmpty());
    return items[top];
}
template <class T>
bool ArrayStack<T>::pop() {
    bool result = false;
//    if (!isEmpty()) {
//        top--;
//        result = true;
//    }
//    return result;
    if (!isEmpty())
        top--;
    else
        throw StackException("Pop called on an empty stack");
    return result;
}
template <class T>
bool ArrayStack<T>::push(const T& newItem) {
    bool result = false;
    if (top < SIZE -1) {
        top++;
        items[top] = newItem;
        result = true;
    } else {
        throw StackException("Push called on a full stack");
    }
    return result;
}

