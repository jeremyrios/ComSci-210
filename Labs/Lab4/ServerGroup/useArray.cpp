#include <iostream>

#include "Array.h"
#include "Array.h"

using namespace std;

#include <cassert>

int main()
{
  cout << "\n//////////////TESTING/////////////////\n\n";
  Array<int> a(10); // create array of 10 ints 
  a[0] = 100; // allow assignment 
  cout << a[0]; // allow access 
  for (int i = 0; i < a.size(); i++) 
  a.changeSize(20); // make adjustable 
  cout << a.err(); // check status 
  or if (a.err().length()) ... // error 
  cout << "////////////END OF TEST///////////////\n\n";
  return 0;
}

