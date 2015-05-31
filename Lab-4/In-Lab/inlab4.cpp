//Annette Chun
//amc4sq
//02/11/15
//inlab4.cpp

#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

union{
  unsigned int ui;
  float f;
  int i;
  unsigned int uiTwo;
} x;

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
 
int main(){

//UNION

// float
x.f = 0;
outputBinary(x.ui);
x.f = 1;
outputBinary(x.ui);

//int
x.i = 0;
outputBinary(x.ui);
x.i = 1;
outputBinary(x.ui);

//unsigned int
x.uiTwo = 0;
outputBinary(x.ui);
x.uiTwo = 1;
outputBinary(x.ui);

//MAXIMUM VALUES FOR DATA TYPES

//int
cout << "The maximum value for an int is : " << INT_MAX << endl;
//unsigned int
cout << "The maximum value for an unsigned int is : " << UINT_MAX << endl;
//float
cout << "The maximum value for a float is : " << FLT_MAX << endl;  
//double
cout << "The maximum value for a double is : " << DBL_MAX << endl;
//char
cout << "The maximum value for char is : " << CHAR_MAX << endl;
//pointers
cout << "The maximum value for a pointer is 2^(64 bits) : 1.84467440e+19" << endl;

//DEBUGGER

//double

//double dblZero = 0.0;
//double dblOne = 1.0;

//char

//char charZero = '0';
//char charOne = '1';

//bool

//bool boolZero = false;
//bool boolOne = true;

//int*

//int* intNull = NULL;

//char*

//char* charNull = NULL;

//double*

//double* dblNull = NULL;

//cout << "Zero in double : " << dblZero << endl;
//cout << "One in double : " << dblOne << endl;
//cout << "Zero in char : " << charZero << endl;
//cout << "One in char : " << charOne << endl;
//cout << "Zero in bool : " << boolZero << endl;
//cout << "one in bool : " << boolOne << endl;
//cout << "NULL in int* : " << intNull << endl;
//cout << "NULL in char* : " << charNull << endl;
//cout << "NULL in double* : " << dblNull << endl;

//REPRESENTATION IN MEMORY

bool x = true;
char y = 'a';
int z = 0;
double a = 0.0;
int* b = NULL;

cout << "The value stored in the bool is : " << x << endl;
cout << "The value stored in the char is : " << y << endl;
cout << "The value stored in the int is : " << z << endl;
cout << "The value stored in the double is : " << a << endl;
cout << "The value stored in the int* is : " << b << endl;

//PRIMITIVE ARRAYS IN C++

int IntArray[10] = {0,1,2,3,4,5,6,7,8,9};
char CharArray[10] = {'a','b','c','d','e','f','g','h','i','j'};
int IntArray2D[6][5] = {{10,11,12,13,14}, {15,16,17,18,19},{20,21,22,23,24},{25,26,27,28,29},{30,31,32,33,34},{35,36,37,38,39}};
char CharArray2D[6][5] = {{'k','l','m','n','o'},{'p','q','r','s','t'},{'u','v','w','x','y'},{'z','A','B','C','D'},{'E','F','G','H','I'},{'J','K','L','M','N'}};

cout << "IntArray : " << IntArray << endl;
cout << "CharArray : " << CharArray << endl;
cout << "IntArray2D : " << IntArray2D << endl;
cout << "CharArray2D : " << CharArray2D << endl;

return 0;

}
