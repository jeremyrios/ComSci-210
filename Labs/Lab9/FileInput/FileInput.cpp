#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cmath>
#include <ctime> 
#include <cstring>

const char* inputFile ("dvc-schedule.txt"); 

int main()
{
  // problem setup goes here

  // programmer customizations go here
  int n = 500; // THE STARTING PROBLEM SIZE
  string bigOh = "O(n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)

  int elapsedTimeTicksNorm;
  double expectedTimeTicks;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    ifstream fin(inputFile);

    // initize the timer
    clock_t startTime = clock();

    // do something where n is the "size" of the problem
    if(fin.is_open())
    {
      for(int lines=0; lines<n && fin.good(); lines++) // read the input file
      {
        string line;
        getline(fin, line); // read the line
      }
      fin.close();
    }
    else 
      cout << "Unable to open input file\n";

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
  
  return 0;
}


