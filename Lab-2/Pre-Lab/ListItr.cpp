//Annette Chun
//amc4sq
//01/26/2015
//ListItr.cpp

#include "ListItr.h"
using namespace std;

//default constructor
ListItr::ListItr(){
  current = new ListNode; //holds the position in the list
}

//one parameter constructor
ListItr::ListItr(ListNode* theNode){
  current = theNode;
}

//Returns true if the iterator is currently pointing past the end
//position in the list(i.e., it's pointing to the dummy tail
bool ListItr::isPastEnd() const{
  return current -> next ==  NULL;
}

//Returns true if the iterator is currently pointing past(before) the first position in list (i.e., it's pointing to the dummy head)
bool ListItr::isPastBeginning() const{
  return current -> previous == NULL;
}

//Advances the current pointer to the next position in the list
//(unless already past the end of the list)
void ListItr::moveForward(){
  if (isPastEnd() == false){
    current = current -> next;
  }
}

//Moves current back to the previous position in the list (unless
//already past the beginning of the list)
void ListItr:: moveBackward(){
  if (isPastBeginning() == false){
    current = current -> previous;
  }
}

//Returns the value of the item in the current position of the
//list
int ListItr::retrieve() const{
  return current -> value ;
}
