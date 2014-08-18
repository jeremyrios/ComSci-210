
#include <iostream>

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
  Fraction a = {5,6}, b = {3,4}, c, f;
  cout << "\n/////////////////////  Testing  ////////////////////////\n\n";
  cout << "Fraction a: " << a.numerator << '/' << a.denominator << " (assignment upon declaration)" << endl
       << "Fraction b: " <<  b.numerator << '/' << b.denominator << " (assignment upon declaration)" << endl;
  f = a + b;
  cout << " a + b = " << f.numerator << '/' << f.denominator << " -- Expected answer: 38/24" << endl;
  f = a * b;
  cout << "a * b = " << f.numerator << '/' << f.denominator << " -- Expected answer: 15/24" << endl;
  cout << "Is a > b ?  answer: " << (a>b) << " -- Expected answer: 1 = (true)" << endl;
  f = a * 2;
  cout << "a * 2 = " << f.numerator << '/' << f.denominator << " -- Expected answer: 10/6" << endl;
  f = 2 * b;
  cout << "2 * b = " << f.numerator << '/' << f.denominator << " -- Expected answer: 6/4" << endl;
  c.numerator = 3;
  c.denominator = 8;
  Fraction d = b;
  cout << endl << "Fraction c: " << c.numerator << '/' << c.denominator << " (assignment after declaration)" << endl
               << "Fraction d = b: " << d.numerator << '/' << d.denominator << " (assignment upon declaration)" << endl;
  f = c + d;
  cout << "c + d = " << f.numerator << '/' << f.denominator << " -- Expected answer: 36/32" << endl;
  f = c * d;
  cout << "c * d = " << f.numerator << '/' << f.denominator << " -- Expected answer: 9/32" << endl;
  cout << "Is c > d ?  answer: " << (c>d) << " -- Expected answer: 0 = (false)" << endl;
  f = 2 * c;
  cout << "2 * c = " << f.numerator << '/' << f.denominator << " -- Expected answer: 6/8" << endl;
  f = d * 2;
  cout << "d * 2 = " << f.numerator << '/' << f.denominator << " -- Expected answer: 6/4" << endl;
  cout << endl << "/////////////////  End of Test   /////////////////////" << endl;
  return 0;
}