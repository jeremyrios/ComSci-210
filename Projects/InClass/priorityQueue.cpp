#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Car
{
  string make;
  int year;
  bool operator<(const Car& c) const {return year < c.year;}
};

int main()
{
  priority_queue<int> pq;
  pq.push(100);
  pq.push(400);
  pq.push(500);
  pq.push(200);
  cout << pq.top() << endl;
  priority_queue<Car> pq;
  Car c; c.year =2000;
  pq.push(c);
  c.year = 2011;
  pq.push(c);
  cout << pq.top().year << endl;
  return 0;
}