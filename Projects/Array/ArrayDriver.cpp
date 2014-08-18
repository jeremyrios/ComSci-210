#include <iostream>
using namespace std;

#include "Array.h"
#include "Array.h"

struct Fraction
{
};

int main()
{
  {
    Array<int> a(10);
    a[0] = 100;
    cout << a[0] << " expect 100\n";
    cout << a.length() << " expect 10\n";
    a.changeSize(100);
    cout << a.length() << " expect 100\n";
    cout << a[0] << " expect 100\n";
    a.changeSize(2);
    cout << a.length() << " expect 2\n";
    cout << a[0] << " expect 100\n";
    cout << '[' << a.err() << ']' << " expect blank" << endl;
    a.changeSize(-2);
    cout << '[' << a.err() << ']' << " expect error" << endl;
    cout << a.length() << " expect 2\n";

    Array<int> b = a;
    Array<int> c(10); c = a;
  }
  {
    Fraction f;
    Array<Fraction> a(10);
    a[0] = f;
    cout << a.length() << " expect 10\n";
  }

  return 0;
}