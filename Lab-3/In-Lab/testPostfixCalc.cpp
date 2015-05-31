//Annette Chun
//amc4sq
//02/03/2015
//testPostfixCalc.cpp

#include <stack>
#include <iostream>
#include <string>
#include <cstdlib>
#include "postfixCalculator.h"
using namespace std;

int main(){ //main method
  
  stack<int> a;
  postfixCalculator p;


  cout << "Enter a line of the postfix expression, hit Enter, and then hit Control-D: " << endl;

  while (true) {
    string s;
    cin >> s;
    if (s == "") {
      break;
    }
    if (s == "+"){ //addition
      p.add(a);
    }

    else if (s == "-"){ //subtraction
      p.subtract(a);
    }

    else if (s == "*"){ //multiplication
      p.multiply(a);
    }

    else if (s == "/"){ //division
      p.divide(a);
    }

    else if (s == "~"){ //negation
      p.negate(a);
    }

    else{ //digit
      int digit = atoi(s.c_str());
      a.push(digit);
    }
  }
  
  //IN-LAB TESTING
  
  //case 1 : result should be 32
  //a.push(5);
  //a.push(3);
  //p.add(a);
  //a.push(12);
  //p.multiply(a);
  //a.push(3);
  //p.divide(a);

  //case 2: result should be 198
  //a.push(3);
  //p.negate(a);
  //a.push(8);
  //a.push(2);
  //p.divide(a);
  //a.push(9);
  //p.multiply(a);
  //p.add(a);
  //a.push(6);
  //p.multiply(a);

  //case 3: result should be 42
  //a.push(42);
  
  //case 4: result should be -45
  //a.push(9);
  //a.push(8);
  //a.push(7);
  //p.multiply(a);
  //p.subtract(a);
  //a.push(6);
  //a.push(3);
  //p.divide(a);
  //p.add(a);

  //case 5: result should be -1836
  //a.push(4);
  //a.push(119);
  //a.push(47);
  //a.push(531);
  //p.add(a);
  //p.subtract(a);
  //p.multiply(a);

  //case 6: result should be -1
  //a.push(-5);
  //a.push(4);
  //p.add(a);

  //PRE-LAB TESTING

  //addition: result should be 15
  //a.push(1);
  //a.push(2);
  //a.push(3);
  //a.push(4);
  //a.push(5);
  //p.add(a);
  //p.add(a);
  //p.add(a);
  //p.add(a);


  //subtraction: result should be 21
  //a.push(20);
  //a.push(10);
  //p.subtract(a);
  //a.push(-3);
  //a.push(10);
  //p.subtract(a);
  //p.subtract(a);
  //a.push(2);
  //p.subtract(a);

  //multiplication: result should be 120
  //a.push(-1);
  //a.push(-2);
  //a.push(-5);
  //a.push(3);
  //p.multiply(a);
  //a.push(2);
  //a.push(-2);
  //p.multiply(a);
  //p.multiply(a);
  //p.multiply(a);
  //p.multiply(a);

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

  cout << "Result is: " << a.top() << endl;
  return 0;
}
