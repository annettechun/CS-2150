//Annette Chun
//amc4sq
//02/24/15
//TreeCalc.cpp
//TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <stack>
#include <cstdlib>
#include <iostream>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
  stack<TreeNode*> mystack;
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
  if (!mystack.empty()){
    cleanTree(mystack.top());
  }
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
  if (ptr != NULL){
    cleanTree(ptr->left);
    cleanTree(ptr->right);
  }
  delete ptr;
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
  // insert a value into the tree
  if (val==("+")){
    TreeNode* x = new TreeNode();
    x -> right = mystack.top();
    mystack.pop();
    x -> left = mystack.top();
    mystack.pop();
    x -> value = "+";
    mystack.push(x);
    
  }
  else if (val==("-")){
    TreeNode* x = new TreeNode();
    x -> right = mystack.top();
    mystack.pop();
    x -> left = mystack.top();
    mystack.pop();
    x -> value = "-";
    mystack.push(x);
    
  }
  else if (val==("*")){
    TreeNode* x = new TreeNode();
    x -> right = mystack.top();
    mystack.pop();
    x -> left = mystack.top();
    mystack.pop();
    x -> value = "*";
    mystack.push(x);
  }
  else if (val==("/")){
    TreeNode* x = new TreeNode();
    x -> right = mystack.top();
    mystack.pop();
    x -> left = mystack.top();
    mystack.pop();
    x -> value = "/";
    mystack.push(x);
  }
  else{
    TreeNode* x = new TreeNode();
    x -> value = val;
    mystack.push(x);
  }
    
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
   // print the tree in prefix format
  if (ptr != NULL){
    cout << ptr -> value << " ";
    printPrefix(ptr -> left);
    printPrefix(ptr -> right);
  }
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
   // print tree in infix format with appropriate parentheses
  if (ptr != NULL){
    if(ptr -> value == "+" || ptr -> value == "-" || ptr -> value == "*" || ptr -> value == "/"){
      cout << "(";
      printInfix(ptr -> left);
      cout << " " << ptr -> value << " ";
      printInfix(ptr -> right);
      cout << ")";
    }
    else{
      cout << ptr -> value;
    }
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
   // print the tree in postfix form
  if (ptr != NULL){
    printPostfix(ptr -> left);
    printPostfix(ptr -> right);
    cout << ptr -> value << " ";
  }
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        // call your implementation of printPostfix()
    printPostfix(mystack.top());
        cout << endl;

        cout << "Expression tree in infix expression: ";
        // call your implementation of printInfix()
    printInfix(mystack.top());
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        // call your implementation of printPrefix()
    printPrefix(mystack.top());
        cout << endl;

    } else
      cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
//private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
  // Traverse the tree and calculates the result
  int x = 0;
  if (ptr -> right != NULL || ptr -> left != NULL){
    if (ptr -> value == "+"){
      x = calculate(ptr -> left) + calculate (ptr -> right);
    }
    if (ptr -> value == "-"){
      x = calculate(ptr -> left) - calculate (ptr -> right);
    }
    if (ptr -> value == "*"){
      x = calculate(ptr -> left) * calculate (ptr -> right);
    }
    if (ptr -> value == "/"){
      x = calculate(ptr -> left) / calculate (ptr -> right);
    }
  }
  else {
    x = atoi((ptr -> value).c_str());
  }
  return x;
    
}

//Calls calculate, sets the stack back to a blank stack
//public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    // call private calculate method here
    while (!mystack.empty()){
      i = calculate(mystack.top());
      mystack.pop();
    }
    return i;
}
