//Annette Chun
//amc4sq
//02/05/15
//stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "stacknode.h"

using namespace std;

class stack{

 public:

  stack(); //constructor

  void push(int e); //this adds the passed element to the top of the stack
  int top(); //this returns the element on the top of the stack. 
  //It does not remove that element from the top. if the stack is empty, 
  //then somehow an error must be indicated -- printing an error message
  // and exiting is fine for reporting errors for this lab.
  void pop(); //this removes the element on the top of the stack, but does
  // not return it. If the stack is empty, then somehow an error must be
  // indicated -- for this lab, you can just print out an error message and
  // then exit.
  bool empty(); //this tells whether there are any elements left in the stack 
  //(false) or not (true).

 private:
  stacknode *head;
  friend class postfixCalculator; //provides access to stack methods

};

#endif
