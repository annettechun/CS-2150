//Annette Chun
//amc4sq
//02/05/15
//stacknode.h

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

using namespace std;

class stacknode{

 public:
  stacknode(); //constructor
  stacknode(int element); //one parameter constructor
  int getData();

 private:
  int data;
  stacknode *next;
  friend class stack; //NEED SO STACK CAN USE NEXT
};

#endif
