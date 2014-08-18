#include <iostream>
#include <iomanip>

#include "Rectangle.h"
#include "Rectangle.h"

#include "Fraction.h"
#include "Fraction.h"

using namespace std;

int main()
{
  cout << "\n\n/////////////////////  Testing  ////////////////////////\n\n";

  Rectangle<int> a1;
  a1.setLength(5); // 5
  a1.setWidth(4); // 4
  cout << "Rectangle A1 (int) declared and initialized with constructor 1(no parameters)" << endl 
	   << "length: " << a1.getLength() << " --> Expected Value = 5" << endl
	   << "width: " << a1.getWidth() << " --> Expected Value = 4" << endl
	   << "length>width? " << a1.isLengthBiggerThanWidth() << " --> Expected Value = 1 (true)" << endl
	   << "perimeter: " << a1.perimeter() << " --> Expected Value = 18" << endl 
	   << "area: " << a1.area() << " --> Expected Value = 20" << endl << endl;

  Rectangle<int> a2(4,5);
  cout << "Rectangle A (int) declared and initialized with constructor 2" << endl 
	   << "length: " << a2.getLength() << " --> Expected Value = 5" << endl
	   << "width: " << a2.getWidth() << " --> Expected Value = 4" << endl
	   << "length>width? " << a2.isLengthBiggerThanWidth() << " --> Expected Value = 1 (true)" << endl
	   << "perimeter: " << a2.perimeter() << " --> Expected Value = 18" << endl 
	   << "area: " << a2.area() << " --> Expected Value = 20" << endl << endl;

  cout <<  fixed;
  cout <<  setprecision (3);
  Rectangle<float> b1;
  b1.setLength(6.249);
  b1.setWidth(8.256); 
  cout << "Rectangle B1 (float) declared and initialized with constructor 1(no parameters)" << endl 
	   << "length: " << b1.getLength() <<  " --> Expected Value = 6.249" << endl
	   << "width: " << b1.getWidth() <<  " --> Expected Value = 8.256" << endl
	   << "length>width? " << b1.isLengthBiggerThanWidth() << " --> Expected Value = 0 (false)" << endl
	   << "perimeter: " << b1.perimeter() << " --> Expected Value = 29.010" << endl 
	   << "area: " << b1.area() << " --> Expected Value = 51.592" << endl << endl;

  Rectangle<float> b2(8.256,6.249);
  cout << "Rectangle B2 (float) declared and initialized with constructor 2" << endl 
	   << "length: " << b2.getLength() <<  " --> Expected Value = 6.249" << endl
	   << "width: " << b2.getWidth() <<  " --> Expected Value = 8.256" << endl
	   << "length>width? " << b2.isLengthBiggerThanWidth() << " --> Expected Value = 0 (false)" << endl
	   << "perimeter: " << b2.perimeter() << " --> Expected Value = 29.010" << endl 
	   << "area: " << b2.area() << " --> Expected Value = 51.592" << endl << endl;

  Fraction f1(5,6), f2(3,4), f3, f4;
  Rectangle<Fraction> c1(f2,f1);
  c1.setLength(f1); // (5/6)
  c1.setWidth(f2); // (3/4)

  cout << "Rectangle C1 (Fraction) declared and initialized with constructor 1" << endl;
  f3 = c1.getLength();
  cout << "length: " << f3.numerator << '/' << f3.denominator << " --> Expected Value = 5/6" << endl;
  f3 = c1.getWidth();
  cout << "width: " << f3.numerator << '/' << f3.denominator  << " --> Expected Value = 3/4" << endl;
  cout << "length>width? " << c1.isLengthBiggerThanWidth() << " --> Expected Value = 1 (true)" << endl;
  f3 = c1.perimeter();
  cout << "perimeter: " << f3.numerator << '/' << f3.denominator << " --> Expected Value = 76/24" << endl;
  f3 = c1.area();
  cout << "area: " << f3.numerator << '/' << f3.denominator << " --> Expected Value = 15/24" << endl << endl;


  Rectangle<Fraction> c2(f1, f2);
  cout << "Rectangle C2 (Fraction) declared and initialized with constructor 2" << endl;
  f4 = c2.getLength();
  cout << "length: " << f4.numerator << '/' << f4.denominator << " --> Expected Value = 3/4" << endl;
  f4 = c2.getWidth();
  cout << "width: " << f4.numerator << '/' << f4.denominator  << " --> Expected Value = 5/6" << endl;
  cout << "length>width? " << c2.isLengthBiggerThanWidth() << " --> Expected Value = 0 (false)" << endl;
  f4 = c2.perimeter();
  cout << "perimeter: " << f4.numerator << '/' << f4.denominator << " --> Expected Value = 76/24" << endl;
  f4 = c2.area();
  cout << "area: " << f4.numerator << '/' << f4.denominator << " --> Expected Value = 15/24" << endl << endl;

  cout << "/////////////////  End of Test   /////////////////////" << endl;

  return 0;
}