/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/** 
 * @file:   PushException.cpp
 * @author: cwood
 * @class:  PushException
 * 
 * Created on October 7, 2018, 3:42 PM
 */

#include <string>
#include "StackException.h"

StackException::StackException(const std::string& msg) : logic_error (msg) {
    
}



