//Annette Chun
//amc4sq
//02/03/15
//postfixCalculator.cpp

#include <stack>
#include <cstdlib>
#include <iostream>
#include "postfixCalculator.h"
using namespace std;

//default constructor
postfixCalculator::postfixCalculator(){
}

//methods
void postfixCalculator::add(stack<int>& s){
    if (s.empty() == true){
      exit(-1);
  }
  else{
    one = s.top();
    s.pop();
    count--;
    if (s.empty() == true){
      exit(-1);
    }
    else{
      two = s.top();
      s.pop();
    }
  }

  s.push(two+one);
}

void postfixCalculator::subtract(stack<int>& s){
  if (s.empty() == true){
    exit(-1);
  }
  else{
    one = s.top();
    s.pop();
    count--;
    if (s.empty() == true){
      exit(-1);
    }
    else{
      two = s.top();
      s.pop();
    }
  }

  s.push(two - one);
}   

void postfixCalculator::multiply(stack<int>& s){
  if (s.empty() == true){
    exit(-1);
  }
  else{
    one = s.top();
    s.pop();
    count--;
    if (s.empty() == true){
      exit(-1);
    }
    else{
      two = s.top();
      s.pop();
    }
  }

  s.push(two*one);
} 

void postfixCalculator::divide(stack<int>& s){
  if (s.empty() == true){
    exit(-1);
  }
  else{
    one = s.top();
    s.pop();
    count--;
    if (s.empty() == true){
       exit(-1);
    }
    else{
      two = s.top();
      s.pop();
    }
  }

  s.push(two/one);
}

void postfixCalculator::negate(stack<int>& s){
  if (s.empty() == true){
    exit(-1);
  }
  else{
    one = s.top();
    s.pop();
  }

  s.push(-one);
}
