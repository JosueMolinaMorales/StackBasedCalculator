/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PushException.h
 * Author: cwood
 *
 * Created on October 7, 2018, 3:42 PM
 */

#ifndef PUSHEXCEPTION_H
#define PUSHEXCEPTION_H

#include <stdexcept>
#include <string>

class StackException : public std::logic_error {
public:
    StackException(const std::string& msg = "");
    
private:

};

#endif /* PUSHEXCEPTION_H */

