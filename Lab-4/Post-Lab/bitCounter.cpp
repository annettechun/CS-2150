//Annette Chun
//amc4sq
//02/13/15
//bitCounter.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

int BitCounter(int n){
  if(n == 0){
    return 0;
  }
  else if (n == 1){
    return 1;
  }
  else{
    return (BitCounter(n/2) + BitCounter(n%2));
  }
}

int main(int argc, char **argv){
  if (argc == 2){
    string x(argv[1]);
    int y = atoi(x.c_str());
    cout << BitCounter(y) << endl;
  }
}
