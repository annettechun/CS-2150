//Annette Chun
//amc4sq
//02/05/15
//stacknode.cpp

#include <iostream>
#include "stacknode.h"

using namespace std;

//default constructor
stacknode::stacknode(){
  data = 0;
  next = NULL;
}

//one parameter constructor
stacknode::stacknode(int element){
  data=element;
  next = NULL;
}

//getData()
int stacknode::getData(){
  return data;
}
