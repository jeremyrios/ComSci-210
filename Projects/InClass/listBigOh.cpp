#include <iostream>
#include <string>
#include <list>
using namespace std;

#include <cmath>
#include <cassert>
#include <cstdlib> 
#include <ctime>

int main()
{
  // problem setup goes here
  srand(time(0));
  // programmer customizations go here
  int n = 500000; // THE STARTING PROBLEM SIZE
  string bigOh = "O(n log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)

  int elapsedTimeTicksNorm;
  double expectedTimeTicks;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    list<float> a;
	for (int i = 0; i<n; i++) a.push_front(rand());
    // initize the timer
    clock_t startTime = clock();

    // do something where n is the "size" of the problem
  a.sort();

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
	list<float>::iterator it = a.begin();
	float first = *it , second;
	  for(it++; it!=a.end(); it++) // how to traverse iterator list
	  {
		second = *it;
		assert(first<=second);
		first = second;
	  }


    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }

  return 0;
}
/*
Example output (for reading n lines from an input text file):
1436 (expected O(n)) for n=500
2742 (expected 2872) for n=1000
5442 (expected 5744) for n=2000
10828 (expected 11488) for n=4000
*/