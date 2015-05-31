//Annette Chun
//amc4sq
//02/10/15
//prelab4.cpp

#include <iostream>
using namespace std;

//methods

//sizeOfTest()
//int, unsigned int, float, double, char, bool, int*, char*, double*
//should print out all types and their respective sizes
void sizeOfTest(){ //should not take in any parameters
  cout << "Size of int = " << sizeof(int) << endl;
  cout << "Size of unsigned int = " << sizeof(unsigned int) << endl;
  cout << "Size of float = " << sizeof(float) << endl;
  cout << "Size of double = " << sizeof(double) << endl;
  cout << "Size of char = " << sizeof(char) << endl;
  cout << "Size of bool = " << sizeof(bool) << endl;
  cout << "Size of int* = " << sizeof(int*) << endl;
  cout << "Size of char* = " << sizeof(char*) << endl;
  cout << "Size of double* = " << sizeof(double*) << endl;
}

//outputBinary()
//take in one parameter, an unsigned int 
//should print out the 32-bit binary representation of the passed parameters in big Endian format
//cannot use the bitset class
void outputBinary(unsigned int x){
  int count = 0;
  cout << "outputBinary(" << x << ") // => ";
  for (int i = 31; i >= 0; i--){
    count++;
    if (count > 4){
      cout << " ";
      count = 1;
    }
    cout << ((x >> i) & 1);
  }
  cout << "" << endl;
}

//overflow()
void overflow(){ //no parameters
  unsigned int answer = sizeof(unsigned int);
  //cout << "Max value of unsigned int = " << answer << endl;
  cout << "Max value of unsigned int + 1 = " <<  answer+1 << endl;
  cout << "This happens because the function is adding one to the variable that is holding the value 4, it is not adding one to the actual max value of unsigned int. sizeof function is returning the size, in bytes, of a given variable or data type, not what the highest numerical value the unsigned int can hold, meaning an unsigned int can be declared and initialized at a value of 5, or in this case, become 5 by adding to its original value of 4." << endl; //answer "why does this happen?"
}


int main(){
  int x; //this program should only take in a single int value as input

  cout << "Please input a single integer value : ";
  cin >> x;

  sizeOfTest();
  outputBinary(x);
  overflow();
  return 0;
}
