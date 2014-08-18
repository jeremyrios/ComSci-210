#include <iostream>
#include <string>
using namespace std;

#include "LinkedList.h"

#include <cassert> 
#include <cmath>
#include <ctime> 

int main()
{
  // problem setup goes here
  srand (time(NULL));
  int i, REPS = 10000000;
  bool test1=true, test2=true, test3=true, test4=true;
  while(test1) // operator[] assignment at zeroth index, O(1)
  {
	cout << "\n  Test 1 - operator[] assignment at zeroth index, O(1)\n\n";
    // programmer customizations go here
    int n = 1000000; // THE STARTING PROBLEM SIZE

    string bigOh = "O(1)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)

    int elapsedTimeTicksNorm;
    double expectedTimeTicks;
    for (int cycle=0; cycle<4; cycle++, n*=2)
    {
      // more problem setup goes here -- the stuff not timed
	  LinkedList<double> randNums1;
	  for(i=0; i<n; i++)
        randNums1.insert(rand() % RAND_MAX);

	  long elapsedTimeTicks = 0;
	  for (i=0; i<REPS; i++) 
      { 
        // initize the timer
        clock_t startTime = clock();

        // do something where n is the "size" of the problem
	    randNums1[0]=222;

        // compute timing results
        clock_t endTime = clock(); 
        elapsedTimeTicks += (long)(endTime - startTime);
	  }
	  randNums1.makeEmpty();
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
      cout << elapsedTimeTicks;
      if (cycle == 0) cout << " (expected " << bigOh << ')';
      else cout << " (expected " << expectedTimeTicks << ')';
      cout << " for n=" << n << endl;
    }
    test1=false;
  }

  while(test2) // operator[] assignment at 100th index, O(1)
  {
	cout << "\n\n  Test 2 - operator[] assignment at 100th index, O(1)\n\n";
    // programmer customizations go here
    int n = 1000000; // THE STARTING PROBLEM SIZE
    string bigOh = "O(1)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)

    int elapsedTimeTicksNorm;
    double expectedTimeTicks;
    for (int cycle=0; cycle<4; cycle++, n*=2)
	{
      LinkedList<double> randNums2;
	  for(i=0; i<n; i++)
        randNums2.insert(rand() % RAND_MAX);
      // more problem setup goes here -- the stuff not timed
 	  long elapsedTimeTicks = 0;
	  for (i=0; i<REPS; i++) 
      { 
        // initize the timer
        clock_t startTime = clock();

        // do something where n is the "size" of the problem
	    randNums2[100]=555;

        // compute timing results
        clock_t endTime = clock(); 
		elapsedTimeTicks += (long)(endTime - startTime);
	  }
	  randNums2.makeEmpty();
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
      cout << elapsedTimeTicks;
      if (cycle == 0) cout << " (expected " << bigOh << ')';
      else cout << " (expected " << expectedTimeTicks << ')';
      cout << " for n=" << n << endl;
    }
    test2=false;
  }

  while(test3) // iteration from first to last using operator[], O(n)
  {
	cout << "\n\n  Test 3 - iteration from first to last using operator[], O(n)\n\n";
    // programmer customizations go here
	int n = 2000000; // THE STARTING PROBLEM SIZE
    
    string bigOh = "O(n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)

    int elapsedTimeTicksNorm;
    double expectedTimeTicks;
    for (int cycle = 0; cycle < 4; cycle++, n*= 2)
    {
      // more problem setup goes here -- the stuff not timed
	  LinkedList<double> randNums3;
	  for(i=0; i<n; i++)
        randNums3.insert(rand() % RAND_MAX);

      // initize the timer
      clock_t startTime = clock();

      // do something where n is the "size" of the problem
	  for (i=0; i<randNums3.length(); randNums3[i], i++);

      // compute timing results
      clock_t endTime = clock(); 
      long elapsedTimeTicks = (long)(endTime - startTime);

	  randNums3.makeEmpty();

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

  while(test4) // length, O(1)
  {
	cout << "\n\n  Test 4 - length, O(1)\n\n";
    // programmer customizations go here
	int n = 1000000; // THE STARTING PROBLEM SIZE

    
    string bigOh = "O(1)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)

    int elapsedTimeTicksNorm;
    double expectedTimeTicks;
    for (int cycle = 0; cycle < 4; cycle++, n*= 2)
    {
      // more problem setup goes here -- the stuff not timed
      LinkedList<double> randNums4;
	  for(i=0; i<n; i++)
        randNums4.insert(rand() % RAND_MAX);

	  long elapsedTimeTicks = 0;
	  for (i=0; i<REPS; i++) 
      { 
        // initize the timer
        clock_t startTime = clock();

        // do something where n is the "size" of the problem
	    randNums4.length();

        // compute timing results
        clock_t endTime = clock(); 
		elapsedTimeTicks += (long)(endTime - startTime);
	  }
	  randNums4.makeEmpty();
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
  cout << endl;
  return 0;
}


