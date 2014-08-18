#include <iostream>
#include <string>
using namespace std;

#include "PriorityQueue.h"

#include <cassert> 
#include <cmath>
#include <ctime> 

int main()
{
  // problem setup goes here
  bool test1=true, test2=true;
  PriorityQueue<double> pq;
  int i, REPS = 1000000;
  srand (time(NULL));


  while(test1) // operator[] assignment at zeroth index, O(1)
  {
	cout << "\n  Test 1 - enqueue, O(log n)\n\n";
    // programmer customizations go here
    double n = 500000; // THE STARTING PROBLEM SIZE
    string bigOh = "O(log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
	
    int elapsedTimeTicksNorm;
    double expectedTimeTicks, m;
    for (int cycle=0; cycle<4; cycle++, n*=2)
    {
      // more problem setup goes here -- the stuff not timed
	  for(i=0; i<n; i++)
	    pq.enqueue(rand() % RAND_MAX);
	  long elapsedTimeTicks = 0;
	  for (i=0; i<REPS; i++) 
      { 
		m = rand() % RAND_MAX;
	    assert(pq.size()==n);

	    // initize the timer
        clock_t startTime = clock();

        // do something where n is the "size" of the problem
	    pq.enqueue(m);

        // compute timing results
        clock_t endTime = clock(); 
        elapsedTimeTicks += (long)(endTime - startTime);
		pq.dequeue(m);
	  }

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
	  pq.makeEmpty();
      assert(pq.isEmpty());
    }
    test1=false;
  }


  REPS = 500000;

  while(test2) // operator[] assignment at 100th index, O(1)
  {
	cout << "\n\n  Test 2 - dequeue, O(log n)\n\n";
    // programmer customizations go here
    double n = 500000; // THE STARTING PROBLEM SIZE
    string bigOh = "O(log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)


    int elapsedTimeTicksNorm;
    double expectedTimeTicks;
    for (int cycle=0; cycle<4; cycle++, n*=2)
	{
      // more problem setup goes here -- the stuff not timed
      for(i=0; i<n; i++)
	    pq.enqueue(rand() % RAND_MAX); // fill pq 
	  long elapsedTimeTicks = 0;
	  clock_t startTime, endTime;
	  double j;
	  for (i=0; i<REPS; i++) 
	  {
	    assert(pq.size()==n);
        // initize the timer
        startTime = clock();

        // do something where n is the "size" of the problem
	    pq.dequeue(j);

        // compute timing results
        endTime = clock(); 
	    elapsedTimeTicks += (long)(endTime - startTime);
		pq.enqueue(j);
	  }
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
	  pq.makeEmpty();
      assert(pq.isEmpty());
    }
    test2=false;
  }
	 
  cout << endl;
  return 0;
}


