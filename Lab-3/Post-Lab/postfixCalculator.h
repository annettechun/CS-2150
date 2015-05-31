//Annette Chun
//amc4sq
//02/05/2015
//postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include "stack.h"

using namespace std;

class postfixCalculator{
 public:
  postfixCalculator(); //constructor
  void add(stack& p); //adds the first two popped elements
  void subtract(stack& p); //subracts the first two popped elements
  void multiply(stack& p); //multiplies the first two popped elements
  void divide(stack& p); //divides the first two popped elements
  void negate(stack& p); //negates the first two popped elements

 private:
    int count; //#of elements in the stack
    int one; //first popped element
    int two; //second popped element
};

#endif
