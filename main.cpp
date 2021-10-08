/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * @file:   Arithmetic.cpp
 * @author: cwood
 *
 * Created on March 3, 2019, 11:02 AM
 */

#include <cstdlib>
#include <iostream>
#include "ArrayStack.h"
#include "StackException.h"
#include <stdexcept>
using namespace std;

/*
 * 
 */
int main() {

    ArrayStack<int> intStack;
    cout << "Beginning " << boolalpha << intStack.isEmpty() << endl;
    
    for (int i=1; i<=5; i++) {
//        try {
            intStack.push(i);
//        } catch (StackException e) {
//            cout << e.what() << endl;
//        }
    }
    cout << "After push " << boolalpha << intStack.isEmpty() << endl;
   
    //check copy constructor
    ArrayStack<int> numStack(intStack);
    cout << "Copied item: " << numStack.peek() << endl;
    intStack.pop();
    cout << "Copied item: " << intStack.peek() << endl;
    cout << "Copied item: " << numStack.peek() << endl;
    
    cout << "Contents: ";
    int sum = 0;
    while (!intStack.isEmpty()) {
        cout << intStack.peek() << " ";
        sum += intStack.peek();
        try {
            intStack.pop();
        } catch (StackException e) {
            cout << e.what() << endl;
        }
    }
    cout << endl << "Sum: " << sum << endl;
    
    ArrayStack<string> strStack;
    strStack.pop();
    cout << "Did a problem occur with pop? " << endl;
//    intStack.peek();
//    cout << "Did a problem occur with peek? " << endl;
    

    return 0;
}

