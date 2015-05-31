//Annette Chun
//amc4sq
//02/03/2015
//postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

using namespace std;

class postfixCalculator{
 public:
  postfixCalculator(); //constructor
  void add(stack<int>& s); //adds the first two popped elements
  void subtract(stack<int>&  s); //subracts the first two popped elements
  void multiply(stack<int>& s); //multiplies the first two popped elements
  void divide(stack<int>& s); //divides the first two popped elements
  void negate(stack<int>& s); //negates the first two popped elements

  //void push(int e); //this adds the passed element to the top of the stack
  //int top(); //this returns the element on the top of the stack. 
  //It does not remove that element from the top. if the stack is empty, 
  //then somehow an error must be indicated -- printing an error message
  // and exiting is fine for reporting errors for this lab.
  //void pop(); //this removes the element on the top of the stack, but does
  // not return it. If the stack is empty, then somehow an error must be
  // indicated -- for this lab, you can just print out an error message and
  // then exit.
  //bool empty(); //this tells whether there are any elements left in the stack 
  //(false) or not (true).

 private:
    int count; //#of elements in the stack
    int one; //first popped element
    int two; //second popped element
};

#endif
