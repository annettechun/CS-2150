//Annette Chun
//amc4sq
//02/05/2015
//testPostfixCalc.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include "postfixCalculator.h"

using namespace std;

int main(){ //main method
  
  stack p;
  postfixCalculator c;

  cout<< "Enter a line of the postfix expression, hit Enter, and then hit Control-D: " << endl;
  
  while (true){
    string s;
    cin >> s;
    if (s == ""){
      break;
    }
    else if (s=="+"){ //addition
      c.add(p);
    }
    else if(s=="-"){ //subtraction
      c.subtract(p);
    }
    else if(s=="*"){ //multiplication
      c.multiply(p);
    }
    else if(s=="/"){ //division
      c.divide(p);
    }
    else if(s=="~"){ //negation
      c.negate(p);
    }
    else{ //digit
      int digit = atoi(s.c_str());
      p.push(digit);
    }
  }
  
  // IN-LAB TESTING
  
  //case 1: result should be 32
  //p.push(5);
  //p.push(3);
  //c.add(p);
  //p.push(12);
  //c.multiply(p);
  //p.push(3);
  //c.divide(p);

  //case 2: result should be 198
  //p.push(3);
  //a.negate(c);
  //p.push(8);
  //p.push(2);
  //a.divide(c);
  //p.push(9);
  //a.multiply(c);
  //a.add(p);
  //p.push(6);
  //c.multiply(a);

  //case 3: result should be 42
  //p.push(42);

  //case 4: result should be -45
  //p.push(9);
  //p.push(8);
  //p.push(7);
  //c.multiply(p);
  //c.subtract(p);
  //p.push(6);
  //p.push(3);
  //c.divide(p);
  //c.add(p);

  //case 5: result should be -1836
  //p.push(4);
  //p.push(119);
  //p.push(47);
  //p.push(531);
  //c.add(p);
  //c.subtract(p);
  //c.multiply(p);

  //case 6: result should be -1
  //p.push(-5);
  //p.push(4);
  //c.add(p);
  
  // PRE-LAB TESTING

  //addition: result should be 15
  //p.push(1);
  //p.push(2);
  //p.push(3);
  //p.push(4);
  //p.push(5);
  //c.add(p);
  //c.add(p);
  //c.add(p);
  //c.add(p);


  //subtraction: result should be 21
  //p.push(20);
  //p.push(10);
  //c.subtract(p);
  //p.push(-3);
  //p.push(10);
  //c.subtract(p);
  //c.subtract(p);
  //p.push(2);
  //c.subtract(p);

  //multiplication: result should be 120
  //p.push(-1);
  //p.push(-2);
  //p.push(-5);
  //p.push(3);
  //c.multiply(p);
  //p.push(2);
  //p.push(-2);
  //c.multiply(p);
  //c.multiply(p);
  //c.multiply(p);
  //c.multiply(p);

  //division: result should be 42
  //a.push(-1512);
  //a.push(-12);
  //a.push(-2);
  //p.divide(a);
  //p.divide(a);
  //a.push(-2);
  //p.divide(a);
  //a.push(3);
  //p.divide(a);

  //negation: result should be 1
  //a.push(-1);
  //p.negate(a);
  //p.negate(a);
  //p.negate(a);

  cout << "Result is: " <<p.top() << endl;
  return 0;
}
