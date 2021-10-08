/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/** 
 * @file:   StackADT.h
 * @author: cwood
 * @class:  StackADT
 *
 * Created on March 3, 2019, 10:20 AM
 */

#ifndef STACKADT_H
#define STACKADT_H

template <class T>
class StackADT {
    public:
        virtual bool isEmpty() const = 0;
        virtual bool push(const T& newItem) = 0;
        virtual bool pop() = 0;
        virtual T peek() const = 0;
};

#endif /* STACKADT_H */

