//Annette Chun
//amc4sq
//01/26/2015
//List.cpp

#include "List.h"
using namespace std;

//default constructor
List::List() {
  head = new ListNode;
  tail = new ListNode;
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
  if (head->next == NULL){
    return true;
  }
    return false;
}

//removes all times except blank head and tail
void List::makeEmpty(){
  while (!isEmpty()){
    remove(first().retrieve());
  }
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
  ListNode *a = head;
  bool b = false;
  while (b == false){
    if (a  == position.current){
      a -> value = x;
      b = true;
    }
    a = a -> next;    
  }
}

//inserts x before current iterator position p
void List::insertBefore(int x, ListItr position){
  ListNode *a = head;
  bool b = false;
  while (b == false){
   if (a == position.current){
     a->value  = x;
     b = true;
   }
   a = a -> next; 
  }
}

//insert x at tail of list
void List::insertAtTail(int x){
  ListNode *a = tail;
  a -> value = x;
  tail = a;
}

//removes the first occurence of x
void List::remove(int x){ 
  ListNode *a = head;
  bool b = false;
  while (b == false){
    if (a->value == x){
      delete a;
      b = true;
    }
    a = a -> next;
  }  
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
    while (a.isPastEnd()==false){
      cout << a.retrieve() << endl;
      a.moveForward();
    }
  }

  if (forward != true){
    ListItr a = ListItr(theList.last());
    while (a.isPastBeginning()==false){
      cout << a.retrieve() << endl;
      a.moveBackward();
    }
  }
}
