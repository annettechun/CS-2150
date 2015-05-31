//Annette Chun
//amc4sq
//02/05/15
//stack.cpp

#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;

//default constructor
stack::stack(){
  head = NULL;
}

//adds the passed element to the top
void stack::push(int e){
  stacknode *pointer;
  stacknode *temp=head;
  pointer = new stacknode(e);
  if (head==NULL){
    head=pointer;
    pointer->next = NULL;
  }
  else{
    while(temp->next != NULL){
      temp=temp->next;
    }
    temp->next = pointer;
    pointer->next = NULL;
  }
}

//returns element on top of stack
//if empty, error must be indicated
int stack::top(){
  if (empty()){
  cout << "An error has occurred. The stack is empty." << endl;
  exit(-1);
  }

 stacknode *temp = head;
 int count = 1;
 while (temp -> next != NULL){
   temp = temp-> next;
   count++;
 }
 return temp->getData();
 //return count;
}

//removes element on top
//if empty, error must be indicated
void stack::pop(){
  if (empty()){
     cout << "An error has occurred. The stack is empty." << endl;
      exit(-1);
  }
  stacknode *temp = head;
  stacknode *top = head;
   while(temp->next != NULL){
    temp=temp->next;
   }
  temp->next = NULL;
  
  if(top != temp){
    while(top->next != temp){
      top=top->next;
    }
    top->next=NULL;
    delete(temp);
  }
  
  else{
    delete(temp);
  }
}

//any elements left in the stack?
bool stack::empty(){
  if (head == NULL){
    return true;
 }
  return false;
}
