/** Requests an arithmetic expression from the end user and passes
 *     the string to the eval function.  The eval function evaluates
 *     the arithmetic expression, returning the result to the main.
 *     Input expressions are expected to be in proper inorder form.
 *
 * @file Arithmetic.cpp
 * @author YOUR NAME           
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
#include "ArrayStack.h"

using namespace std;

/**
 * Evaluates the string expression using two stacks.
 * @param expr A simple mathematical expression containing numbers 1-9 and =-*^/ operators
 * @return The value of the expression
 */
float eval(string expr);

/**
 * Helper function that calculates and pushes into valStack the sum/difference/product/quotient 
 * of the first two numbers in the valStack using the operator from the top of the operatorStack
 * after each number is peeked, it will be popped. Along with the operator in the operatorStack
 * @param operatorStack Stack that contains the operators
 * @param valStack Stack that contains the Values
 */
void calcResultStoreInStack(ArrayStack<string>& operatorStack, ArrayStack<float>& valStack);

/**
 * Helper function that determines the level of precedence for an operator. 1 -> + & -
 * 2 -> * & / . 3-> ^
 * Note that '(' will be sent in if the expression contains parenthesis, but returns -1. eval() handles
 * the parenthesis.
 * @param anOperator an Operator to be evaluated
 * @return the precedence level of an operator
 */
int findPrecedenceLevel(string anOperator);

/**
 * Helper function that accepts two operators, and sends those operators to 
 * findPrecedenceLevel() 
 * @param operatorInString Operator that is currently being tested
 * @param opOnTopOfStack Operator that is on top of the stack
 * @return True if the operatorInString is greater than or equal to the operatorOnTopOfStack
 */
bool isHigherOrEqualTo(string operatorInString, string opOnTopOfStack);

// The following main function should not be modified
int main(void) {
    string expression = "Continue";

    do {
        std::cout << "Enter an arithmetic expression on a single line ('q' to end): ";
        getline(cin, expression);
        if (expression[0] != 'q') {
            float result = eval(expression);
            cout << expression << " = " << result << endl;
        }
    } while (expression[0] != 'q');

    return 0;
}

float eval(string expr) 
{ 
    //Stacks
    ArrayStack<std::string> operatorStack;
    ArrayStack<float> valStack;
    
    //variables to use
    string expressionChar = "";
    
    //read the string character by character
    for(int i = 0; i < expr.size(); i++){
        expressionChar = expr[i]; //holds each character
        if(isdigit(expr[i])){ //used expr[i] since isdigit accepts char not string
            valStack.push(stoi(expressionChar)); //used expressionChar since stoi uses string not char
        }else{
            //if stack is empty, add the operator to stack
            if(operatorStack.isEmpty()){
                operatorStack.push(expressionChar);
                
            //This handles if the parenthesis were the first thing in the stack or not
            //Also handles nested parenthesis
            }else if(expressionChar == "(" or expressionChar == ")"){ 
                //when a closed parenthesis is encountered, evaluate all the expressions until you reach
                //the first open parenthesis then push that value onto the stack, and pop the open parenthesis
                if(expressionChar == ")"){
                    while(operatorStack.peek() != "("){
                        calcResultStoreInStack(operatorStack, valStack);
                    }
                    operatorStack.pop(); //pop the open parenthesis
                }else{//if the expChar == "(" then just push it onto the stack
                    operatorStack.push(expressionChar);
                }
            }else{
                //while the stack is not empty and the precedentLevel of the char is less than the precedent level of
                //the operator at the top of the stack
                while(!operatorStack.isEmpty() && isHigherOrEqualTo(expressionChar, operatorStack.peek())){
                    
                    //calc the result from the op and two numbers, stores the number in valStack
                    calcResultStoreInStack(operatorStack, valStack);
                    
                }//repeat until the operator at the top of the stack is the same precedent or less than
                
                //push the operator onto the stack
                operatorStack.push(expressionChar);
            } 
        }//end if
       
    }//end for
    
    //after every character has been read, evaluate the remaining operators and numbers
    while(!operatorStack.isEmpty()){
        calcResultStoreInStack(operatorStack, valStack);
    }
    
    return valStack.peek();
}

void calcResultStoreInStack(ArrayStack<string>& operatorStack, ArrayStack<float>& valStack){
    //peek and pop the first two values on the top of the stack
    float number1 = valStack.peek();
    valStack.pop();
    float number2 = valStack.peek();
    valStack.pop();
    
    //get the operator to use, then remove it from stack
    string operatorToUse = operatorStack.peek();
    operatorStack.pop();
    
    float result = 0;
    
    if(operatorToUse == "+"){
        result = number2 + number1;
        //cout << number2 << " + " << number1 << " = " << result << endl;
    }else if(operatorToUse == "-"){ 
        result = number2 - number1;
        //cout << number2 << " - " << number1 << " = " << result << endl;
    }else if(operatorToUse == "*"){
        result = number2 * number1;
        //cout << number2 << " * " << number1 << " = " << result << endl;
    }else if(operatorToUse == "/"){
        result = number2 / number1;
        //cout << number2 << " / " << number1 << " = " << result << endl;
    }else if(operatorToUse == "^"){
        result = pow(number2, number1);
    }
    //cout << "pushing " << result << " onto stack"<< endl;
    
    //push result
    valStack.push(result);
        
}

int findPrecedenceLevel(string anOperator){
    int precedenceLevel = -1;
    
    if(anOperator == "+" or anOperator == "-"){
        precedenceLevel = 1;
    }else if(anOperator == "*" or anOperator == "/"){
        precedenceLevel = 2; 
    }else if(anOperator == "^"){
        precedenceLevel = 3;
    }
    
    return precedenceLevel;
}

bool isHigherOrEqualTo(string operatorInString, string opOnTopOfStack){
    if(findPrecedenceLevel(operatorInString) <= findPrecedenceLevel(opOnTopOfStack)){
        return true;
    }else{
        return false;
    }
}


/*
     for(int i = 0; i < expr.size(); i++){
        expressionChar = expr[i];
        if(isdigit(expr[i])){
            valStack.push(stoi(expressionChar, 0));
        }else{
            //if stack is empty, add the operator to stack
            if(operatorStack.isEmpty()){
                operatorStack.push(expressionChar);
            }else{
                
                //while the stack is not empty and the precedentLevel of the char is less than the precedent level of
                //the operator at the top of the stack
                while(!operatorStack.isEmpty() && isHigherOrEqualTo(expressionChar, operatorStack.peek())){
                    
                    //calc the result from the op and two numbers, stores the number in valStack
                    calcResultStoreInStack(operatorStack, valStack);
                    
                }//repeat until the operator at the top of the stack is the same precedent or less than
                
                //push the operator onto the stack
                operatorStack.push(expressionChar);
            } 
        }//end if
        
        //printStacks(operatorStack, valStack);
    }//end for
 */
/* extra credit
 else if(expressionChar == "("){
            counter = i+1;
            while(expressionChar != ")"){
                currentString += expr[counter];
                cout << currentString << endl;
                counter++;
                expressionChar = expr[counter];
            }
            valStack.push(eval(currentString));
            i = counter; 
 
 */
