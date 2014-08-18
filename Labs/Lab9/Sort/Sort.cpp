#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

#include <cassert> 
#include <cmath>
#include <ctime> 

int main()
{
  // problem setup goes here
  bool test1=true, test2=true, test3=true, test 4=true;

  while(test1) // operator[] assignment at zeroth index, O(1)
  {
	cout << "\nTest 1 - operator[] assignment at zeroth index, O(1)\n\n";
    // programmer customizations go here
    int n = 100000; // THE STARTING PROBLEM SIZE
    string bigOh = "O(1)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)

    int elapsedTimeTicksNorm;
    double expectedTimeTicks;
    for (int cycle = 0; cycle < 4; cycle++, n*= 2)
    {
      // more problem setup goes here -- the stuff not timed
	  LinkedList<double> randNum;
      srand (time(NULL));
	  for(int i=0; i<n; i++)
        randNum.insert(rand() % RAND_MAX);

      // initize the timer
      clock_t startTime = clock();

      // do something where n is the "size" of the problem
	  randNum[0];

      // compute timing results
      clock_t endTime = clock(); 
      long elapsedTimeTicks = (long)(endTime - startTime);
      double factor = pow(2.0, cycle);
      if (cycle == 0)
        elapsedTimeTicksNorm = elapsedTimeTicks;
      else if (bigOh == "O(1)")
        expectedTimeTicks = elapsedTimeTicksNorm;
      else if (bigOh == "O(log n)")
        expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
      else if (bigOh == "O(n)")
        expectedTimeTicks = factor * elapsedTimeTicksNorm;
      else if (bigOh == "O(n log n)")
        expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
      else if (bigOh == "O(n squared)")
        expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

      // reporting block
      cout << elapsedTimeTicks;;
      if (cycle == 0) cout << " (expected " << bigOh << ')';
      else cout << " (expected " << expectedTimeTicks << ')';
      cout << " for n=" << n << endl;
    }
    test1=false;
  }
  while(test2) // operator[] assignment at 100th index, O(1)
  {
	cout << "\nTest 2 - operator[] assignment at 100th index, O(1)\n\n";
    // programmer customizations go here
    int n = 100000; // THE STARTING PROBLEM SIZE
    string bigOh = "O(1)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)

    int elapsedTimeTicksNorm;
    double expectedTimeTicks;
    for (int cycle = 0; cycle < 4; cycle++, n*= 2)
    {
      // more problem setup goes here -- the stuff not timed
	  LinkedList<double> randNum;
      srand (time(NULL));
	  for(int i=0; i<n; i++)
        randNum.insert(rand() % RAND_MAX);

      // initize the timer
      clock_t startTime = clock();

      // do something where n is the "size" of the problem
	  randNum[100];

      // compute timing results
      clock_t endTime = clock(); 
      long elapsedTimeTicks = (long)(endTime - startTime);
      double factor = pow(2.0, cycle);
      if (cycle == 0)
        elapsedTimeTicksNorm = elapsedTimeTicks;
      else if (bigOh == "O(1)")
        expectedTimeTicks = elapsedTimeTicksNorm;
      else if (bigOh == "O(log n)")
        expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
      else if (bigOh == "O(n)")
        expectedTimeTicks = factor * elapsedTimeTicksNorm;
      else if (bigOh == "O(n log n)")
        expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
      else if (bigOh == "O(n squared)")
        expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

      // reporting block
      cout << elapsedTimeTicks;;
      if (cycle == 0) cout << " (expected " << bigOh << ')';
      else cout << " (expected " << expectedTimeTicks << ')';
      cout << " for n=" << n << endl;
    }
    test2=false;
  }
  while(test3)
  {
	cout << "Test 3 - iteration from first to last using operator[], O(n)\n\n";
    // programmer customizations go here
    int n = 100000; // THE STARTING PROBLEM SIZE
    string bigOh = "O(n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)

    int elapsedTimeTicksNorm;
    double expectedTimeTicks;
    for (int cycle = 0; cycle < 4; cycle++, n*= 2)
    {
      // more problem setup goes here -- the stuff not timed
	  LinkedList<double> randNum;
      srand (time(NULL));
	  for(int i=0; i<n; i++)
        randNum.insert(rand() % RAND_MAX);

      // initize the timer
      clock_t startTime = clock();

      // do something where n is the "size" of the problem
	  for (int i = 0; i<randNum.length(); randNum[i], i++);

      // compute timing results
      clock_t endTime = clock(); 
      long elapsedTimeTicks = (long)(endTime - startTime);
      double factor = pow(2.0, cycle);
      if (cycle == 0)
        elapsedTimeTicksNorm = elapsedTimeTicks;
      else if (bigOh == "O(1)")
        expectedTimeTicks = elapsedTimeTicksNorm;
      else if (bigOh == "O(log n)")
        expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
      else if (bigOh == "O(n)")
        expectedTimeTicks = factor * elapsedTimeTicksNorm;
      else if (bigOh == "O(n log n)")
        expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
      else if (bigOh == "O(n squared)")
        expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

      // reporting block
      cout << elapsedTimeTicks;;
      if (cycle == 0) cout << " (expected " << bigOh << ')';
      else cout << " (expected " << expectedTimeTicks << ')';
      cout << " for n=" << n << endl;
    }
    test3=false;
  }
  while(test4)
  {
	cout << "Test 4 - length, O(1)\n\n";
    // programmer customizations go here
    int n = 100000; // THE STARTING PROBLEM SIZE
    string bigOh = "O(1)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)

    int elapsedTimeTicksNorm;
    double expectedTimeTicks;
    for (int cycle = 0; cycle < 4; cycle++, n*= 2)
    {
      // more problem setup goes here -- the stuff not timed
	  LinkedList<double> randNum;
      srand (time(NULL));
	  for(int i=0; i<n; i++)
        randNum.insert(rand() % RAND_MAX);

      // initize the timer
      clock_t startTime = clock();

      // do something where n is the "size" of the problem
	  randNum.length();

      // compute timing results
      clock_t endTime = clock(); 
      long elapsedTimeTicks = (long)(endTime - startTime);
      double factor = pow(2.0, cycle);
      if (cycle == 0)
        elapsedTimeTicksNorm = elapsedTimeTicks;
      else if (bigOh == "O(1)")
        expectedTimeTicks = elapsedTimeTicksNorm;
      else if (bigOh == "O(log n)")
        expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
      else if (bigOh == "O(n)")
        expectedTimeTicks = factor * elapsedTimeTicksNorm;
      else if (bigOh == "O(n log n)")
        expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
      else if (bigOh == "O(n squared)")
        expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

      // reporting block
      cout << elapsedTimeTicks;;
      if (cycle == 0) cout << " (expected " << bigOh << ')';
      else cout << " (expected " << expectedTimeTicks << ')';
      cout << " for n=" << n << endl;
    }
    test4=false;
  }
  return 0;
}


