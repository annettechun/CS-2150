//Annette Chun
//amc4sq
//01/29/2015
//List.cpp

#include <iostream>
#include "List.h"
using namespace std;

//default constructor
List::List() {
  this -> head = new ListNode;
  this -> tail = new ListNode;
  head-> next = tail;
  tail-> previous = head;
  count= 0;
}

//copy constructor
List::List(const List& source) {
  head=new ListNode;
  tail=new ListNode;
  head->next=tail;
  tail->previous=head;
  count=0;
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()){ //deep copy of the list
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

//Destructor
List::~List(){
  makeEmpty();
  delete head;
  delete tail;
}

//Equals operator
List& List::operator=(const List& source) {
  if (this == &source)
    return *this;
  else{
    makeEmpty();
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

//returns true if empty; else false
bool List::isEmpty() const{
  if (head->next==NULL){
    return true;
  }
    return false;
}

//removes all times except blank head and tail
void List::makeEmpty(){
  ListItr a = head -> next;
  while (a.isPastEnd() == false){
    delete a.current;
    a.moveForward();
  }
  count = 0;
}

//returns an iterator that points to
//the ListNode in the first position
ListItr List::first(){
  return ListItr(head->next);
}

//returns an iterator that points to
//the ListNode in the last position
ListItr List::last(){
  return ListItr(tail->previous);
}

//inserts x after current iterator position p
void List::insertAfter(int x, ListItr position){
  ListNode *newNode = new ListNode;
  newNode -> value = x;
  newNode -> previous = position.current;
  newNode -> next = position.current -> next;
  position.current ->  next = newNode;
  newNode -> next -> previous = newNode; // reset pointers
  count++;
}

//inserts x before current iterator position p
void List::insertBefore(int x, ListItr position){
  ListNode *newNode = new ListNode;
  newNode -> value = x;
  newNode -> next = position.current;
  newNode -> previous = position.current -> previous;
  position.current -> previous = newNode;
  newNode -> previous -> next = newNode; //reset pointers
  count++;
}

//insert x at tail of list
void List::insertAtTail(int x){
  ListItr a = tail;
  insertBefore(x,a);
}

//removes the first occurence of x
void List::remove(int x){ 
  ListNode *a = head;
  bool b = false;
  while (b == false){
    if (a->value == x){
      delete a;
      ListNode *c = a -> previous;
      ListNode *d = a -> next;
      c -> next = d;
      d -> previous = c;
      b = true;
    }
    a = a -> next;
  }  
  count--;
}

//returns an iterator that points to
//the first occurence of x, else return
//a iterator to the dummy tail node
ListItr List::find(int x){
  ListNode *a = head;
  bool b = false;
  while (b == false){
    if (a -> value == x){
      return ListItr(a);
      b = true;
    }
    a = a -> next;
  }
  return NULL;
}

//returns the number of elements in the list
int List::size() const{
  return count; 
}

//prints a list either forwards (by default -- from
//head to tail) when forward is true, or backwards
//(from tail to head) when forward is false.
//YOU MUST USE YOUR LISTITR CLASS TO IMPLEMENT THIS
//FUNCTION

void printList(List& theList, bool forward){
  if (forward == true){
    ListItr a = ListItr(theList.first());
    while (!a.isPastEnd()){
      cout << a.retrieve() << " ";
      a.moveForward();
    }
  }

  if (forward != true){
    ListItr a = ListItr(theList.last());
    while (!a.isPastBeginning()){
      cout << a.retrieve() << " ";
      a.moveBackward();
    }
  }
}
