#include <iostream>
#include<iomanip>

#include "Rectangle.h"
#include "Rectangle.h"

using namespace std;

struct Fraction
{
  int numerator;
  int denominator;
};

Fraction operator+(Fraction a, Fraction b)
{
  Fraction c, d;
  if (a.denominator != b.denominator)
  {
    c.numerator = a.numerator * b.denominator;
    d.numerator = b.numerator * a.denominator;
    c.denominator = a.denominator * b.denominator;
    c.numerator = c.numerator + d.numerator;
  }
  else
  {
    c.numerator = a.numerator + b.numerator;
    c.denominator = a.denominator;
  }
  return c;
}

Fraction operator*(Fraction a, Fraction b)
{
  Fraction c;
  c.numerator = a.numerator * b.numerator;
  c.denominator = a.denominator * b.denominator;
  return c;
}

bool operator>(Fraction a, Fraction b)
{
  int c, d;
  if (a.denominator != b.denominator)
  {
    c = a.numerator * b.denominator;
    d = b.numerator * a.denominator;
  }
  else
  {
    c = a.numerator;
    d = b.numerator;
  }
  if(c>d)
  {
    return true;
  }
  else 
  {
    return false;
  }
}

Fraction operator*(Fraction a, int i)
{
  Fraction c;
  c.numerator = a.numerator * i;
  c.denominator = a.denominator;
  return c;
}

Fraction operator*(int i, Fraction a)
{
  Fraction c;
  c.numerator = a.numerator * i;
  c.denominator = a.denominator;
  return c;
}

int main()
{
  Rectangle<int> a1;
  a1.setLength(5);
  a1.setWidth(4);
  cout << "\n/////////////////////  Testing  ////////////////////////\n\n";
  cout << "Rectangle A1 (int)" << endl 
	   << "length: " << a1.getLength() << endl
	   << "width: " << a1.getWidth() << endl
	   << "length>width? " << a1.lenBiggerThanWid() << " -- Expected Value = 1 (true)" << endl
	   << "perimeter: " << a1.perimeter() << " -- Expected Value = 18" << endl 
	   << "area: " << a1.area() << " -- Expected Value = 20" << endl << endl;

  Rectangle<int> a2 = a1;
  cout << "Rectangle A2 (int)" << endl 
	   << "length: " << a2.getLength() << endl
	   << "width: " << a2.getWidth() << endl
	   << "length>width? " << a2.lenBiggerThanWid() << " -- Expected Value = 1 (true)" << endl
	   << "perimeter: " << a2.perimeter() << " -- Expected Value = 18" << endl 
	   << "area: " << a2.area() << " -- Expected Value = 20" << endl << endl;

  Rectangle<float> b1, b2;
  b1.setLength(6.249);
  b1.setWidth(8.256);
  cout <<  fixed <<  setprecision (3);
  cout << "Rectangle B1 (float)" << endl 
	   << "length: " << b1.getLength() << endl
	   << "width: " << b1.getWidth() << endl
	   << "length>width? " << b1.lenBiggerThanWid() << " -- Expected Value = 0 (false)" << endl
	   << "perimeter: " << b1.perimeter() << " -- Expected Value = 29.010" << endl 
	   << "area: " << b1.area() << " -- Expected Value = 51.592" << endl << endl;
  b2 = b1;
  cout << "Rectangle B2 (float)" << endl 
	   << "length: " << b2.getLength() << endl
	   << "width: " << b2.getWidth() << endl
	   << "length>width? " << b2.lenBiggerThanWid() << " -- Expected Value = 0 (false)" << endl
	   << "perimeter: " << b2.perimeter() << " -- Expected Value = 29.010" << endl 
	   << "area: " << b2.area() << " -- Expected Value = 51.592" << endl << endl;

  Fraction f1 = {5,6}, f2 = {3,4}, f3;
  
  Rectangle<Fraction> c1, c2;
  c1.setLength(f1);
  c1.setWidth(f2);

  cout << "Rectangle C1 (Fraction)" << endl;
  f3 = c1.getLength();
  cout << "length: " << f3.numerator << '/' << f3.denominator  << endl;
  f3 = c1.getWidth();
  cout << "width: " << f3.numerator << '/' << f3.denominator  << endl;
  cout << "length>width? " << c1.lenBiggerThanWid() << " -- Expected Value = 1 (true)" << endl;
  f3 = c1.perimeter();
  cout << "perimeter: " << f3.numerator << '/' << f3.denominator << " -- Expected Value = 76/24" << endl;
  f3 = c1.area();
  cout << "area: " << f3.numerator << '/' << f3.denominator << " -- Expected Value = 15/24" << endl << endl;

  c2 = c1;
  cout << "Rectangle C2 (Fraction)" << endl;
  f3 = c2.getLength();
  cout << "length: " << f3.numerator << '/' << f3.denominator  << endl;
  f3 = c2.getWidth();
  cout << "width: " << f3.numerator << '/' << f3.denominator  << endl;
  cout << "length>width? " << c2.lenBiggerThanWid() << " -- Expected Value = 1 (true)" << endl;
  f3 = c2.perimeter();
  cout << "perimeter: " << f3.numerator << '/' << f3.denominator << " -- Expected Value = 76/24" << endl;
  f3 = c2.area();
  cout << "area: " << f3.numerator << '/' << f3.denominator << " -- Expected Value = 15/24" << endl << endl;

  Rectangle<Fraction> c3 = c2;
  cout << "Rectangle C3 (Fraction)" << endl;
  f3 = c3.getLength();
  cout << "length: " << f3.numerator << '/' << f3.denominator  << endl;
  f3 = c3.getWidth();
  cout << "width: " << f3.numerator << '/' << f3.denominator  << endl;
  cout << "length>width? " << c3.lenBiggerThanWid() << " -- Expected Value = 1 (true)" << endl;
  f3 = c3.perimeter();
  cout << "perimeter: " << f3.numerator << '/' << f3.denominator << " -- Expected Value = 76/24" << endl;
  f3 = c3.area();
  cout << "area: " << f3.numerator << '/' << f3.denominator << " -- Expected Value = 15/24" << endl << endl;

  cout << "/////////////////  End of Test   /////////////////////" << endl;
  return 0;
}