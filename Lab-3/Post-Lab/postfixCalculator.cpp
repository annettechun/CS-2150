//Annette Chun
//amc4sq
//02/05/15
//postfixCalculator.cpp

#include <cstdlib>
#include <iostream>
#include "postfixCalculator.h"

using namespace std;

//default constructor
postfixCalculator::postfixCalculator(){
  count = 0;
  one = 0;
  two = 0;
}

//methods
void postfixCalculator::add(stack& p){
  if (p.empty() == true){
    cout << "An error has occurred. The stack is empty." << endl;
    exit(-1);
  }
  else{
    one = p.top();
    p.pop();
    count--;
     if (p.empty() == true){
      cout << "An error has occurred. The stack is empty." << endl;
      exit(-1);
     }
    else{
      two = p.top();
      p.pop();
    }
  }

  p.push(two+one);
}

void postfixCalculator::subtract(stack& p){
  if (p.empty() == true){
    cout << "An error has occurred. The stack is empty." << endl;
    exit(-1);
  }
  else{
    one = p.top();
    p.pop();
    count--;
    if (p.empty() == true){
      cout << "An error has occurred. The stack is empty." << endl;
      exit(-1);
    }
    else{
      two = p.top();
      p.pop();
    }
  }

  p.push(two - one);
}   

void postfixCalculator::multiply(stack& p){
  if (p.empty() == true){
    cout << "An error has occurred. The stack is empty." << endl;
    exit(-1);
  }
  else{
    one = p.top();
    p.pop();
    count--;
    if (p.empty() == true){
      cout << "An error has occurred. The stack is empty." << endl;
      exit(-1);
    }
    else{
      two = p.top();
      p.pop();
    }
  }

  p.push(two*one);
} 

void postfixCalculator::divide(stack& p){
  if (p.empty() == true){
    cout << "An error has occurred. The stack is empty." << endl;
    exit(-1);
  }
  else{
    one = p.top();
    p.pop();
    count--;
    if (p.empty() == true){
      cout << "An error has occurred. The stack is empty." << endl;
      exit(-1);
    }
    else{
      two = p.top();
      p.pop();
    }
  }

  p.push(two/one);
}

void postfixCalculator::negate(stack& p){
  if (p.empty() == true){
    cout << "An error has occurred. The stack is empty." << endl;
    exit(-1);
  }
  else{
    one = p.top();
    p.pop();
  }

  p.push(-one);
}
