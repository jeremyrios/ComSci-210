#include <iostream>

#include "Array.h"
#include "Array.h"

#include "Fraction.h"
#include "Fraction.h"

using namespace std;

#include <cassert>

int main()
{
	{
		cout << "\n//////////////TESTING/////////////////\n\n";

		Array<int> a(10);
		a[0] = 100;
		cout << a[0] << " expect 100\n";
		cout << a[10] << " expect garbage\n";
		cout << '[' << a.err() << ']' << " expect error" << endl;
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
		cout << a.length() << " expect 2\n\n";

		a[1] = 100; // now a[0] and a[1] are both 100

		Array<int> b = a;
		cout << b.lsearch(100) << " expect 0 because b[0] is first occurence \n";

		a[1] = 150;

		cout << b.lsearch(150) << " expect 1\n";
		cout << b.lsearch(250) << " expect -1\n";

		Array<int> c(10); c = a;
		cout << c.lsearch(150) << " expect 1\n";
		cout << c.lsearch(20) << " expect -1\n\n";

	}
	{
		Fraction f1(3,4), f2(1,2);
		Array<Fraction> a(10);
		a[5] = f1;
		cout << a[5] << " expect (3/4)\n";
		cout << a.length() << " expect 10\n";
		cout << a.lsearch(f1) << " expect 5\n";
		cout << a.lsearch(f2) << " expect -1\n";
	}

	cout << "\n////////////END OF TEST///////////////\n\n";
	return 0;
}