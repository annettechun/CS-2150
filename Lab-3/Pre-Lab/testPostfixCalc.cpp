//Annette Chun
//amc4sq
//02/03/2015
//testPostfixCalc.cpp

#include <stack>
#include <iostream>
#include "postfixCalculator.h"
using namespace std;

//main method
int main(){
  
  stack<int> a;
  postfixCalculator p;
  //add
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);
  a.push(5);
  p.add(a);
  p.add(a);
  p.add(a);
  p.add(a);


  //minus
  a.push(20);
  a.push(10);
  p.subtract(a);
  a.push(-3);
  a.push(10);
  p.subtract(a);
  p.subtract(a);
  a.push(2);
  p.subtract(a);

  //multiplication
  a.push(-1);
  a.push(-2);
  a.push(-5);
  a.push(3);
  p.multiply(a);
  a.push(2);
  a.push(-2);
  p.multiply(a);
  p.multiply(a);
  p.multiply(a);
  p.multiply(a);

  //divide
  a.push(-1512);
  a.push(-12);
  a.push(-2);
  p.divide(a);
  p.divide(a);
  a.push(-2);
  p.divide(a);
  a.push(3);
  p.divide(a);

  //negate
  a.push(-1);
  p.negate(a);
  p.negate(a);
  p.negate(a);

  cout << "Result is: " << a.top() << endl;
  return 0;
}
