//Annette Chun
//amc4sq
//01/29/2015
//ListNode.cpp

#include <iostream>
#include "ListNode.h"
using namespace std;

//default constructor
ListNode::ListNode(){
  value = 0;
  this -> next = NULL; //for doubly linked lists
  this -> previous = NULL; //for doubly linked lists
}
