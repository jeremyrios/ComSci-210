#include <iostream>
using namespace std;

void countdown(int n)
{
  if(n>0)
  { 
	cout << n << endl;
	countdown(n-1);
  }
  else 
   cout << n << endl;
}

int main()
{
  countdown(10);
  return 0;
}