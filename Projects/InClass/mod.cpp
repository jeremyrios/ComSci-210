#include<iostream>
#include<list>
using namespace std;

int main()
{
  int a, b;
  bool loop = true;
  while(loop)
  {
	cout << endl << "Enter first number: ";
	cin >> a;
	cout << endl << "Enter mod number: ";
	cin >> b;
	cout << endl << "Answer: " << a%b << endl; 
  }
  return 0;
}