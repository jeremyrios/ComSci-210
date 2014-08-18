#include <iostream>
using namespace std;

#include "PriorityQueue.h"
#include "PriorityQueue.h"

int main()
{
  int j,k;
  int i[20] = {20,33,12,54,28,27,39,2,99,67,32,90,41,6,45,38,66,19,7,109};
  PriorityQueue<int> pq1;
  cout << "PQ 1's size is: " << pq1.size() << " - expect 0\n\n";
  for(j=0; j<20; j++)
	 pq1.enqueue(i[j]);
  PriorityQueue<int> pq2 = pq1;
  cout << "PQ 1's size is now: " << pq1.size() << " - expect 20\n\n"
	   << "The contents of the PQ 1 is are:\n";
  while(!pq1.isEmpty())
  {
	pq1.dequeue(k);
	cout << " " << k;
  }
  cout << "\n\nPQ 1's size is now: " << pq1.size() << " - expect 0\n\n";

  cout << "PQ 2's size is: " << pq2.size() << " - expect 20\n\n";
  cout << "The fist 10 items in PQ 2 are:\n";
  while(pq2.size()>10)
  {
	pq2.dequeue(k);
	cout << " " << k;
  }
  PriorityQueue<int> pq3; pq3 = pq2;
  cout << "\n\nPQ 3's size is: " << pq3.size() << " - expect 10\n\n";
  pq2.makeEmpty();
  pq3.makeEmpty();
  cout << "\nPQ 2's size is now: " << pq1.size() << " - expect 0\n\n";
  cout << "\nPQ 3's size is now: " << pq1.size() << " - expect 0\n\n";
  return 0;
}