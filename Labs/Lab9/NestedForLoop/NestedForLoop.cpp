#include <iostream>
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

  // programmer customizations go here
  int n = 2000; // THE STARTING PROBLEM SIZE
  string bigOh = "O(n squared)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)

  int elapsedTimeTicksNorm;
  double expectedTimeTicks;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
	vector<double> randNum;
    srand (time(NULL));
	for(int i=0; i<n; i++)
      randNum.push_back(rand() % RAND_MAX);

    // initize the timer
    clock_t startTime = clock();

    // do something where n is the "size" of the problem
	for(int i=0; i<n; i++) // bouble sort
    {
      for(int j=n-1; j>i; j--)
      {
        if(randNum[j-1] > randNum[j])
        {
          double temp = randNum[j-1]; //swap 
          randNum[j-1] =  randNum[j];
          randNum[j] = temp;
        }
      }
    }

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

	for (int i = 1; i < n; i++) // code to verify that each number in the array is greater or equal to the number before it
	  assert (randNum[i - 1] <= randNum[i]);
  }
  
  return 0;
}


