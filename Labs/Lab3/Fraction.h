#ifndef Fraction_h
#define Fraction_h

struct Fraction
{
  Fraction(){}
  Fraction(const int &n, const int &d){numerator=n;denominator=d;}

  int numerator;
  int denominator;
};

ostream& operator<<(ostream& output, const Fraction& f) 
{
    output << "(" <<  f.numerator << "/" << f.denominator <<")";
    return output;  // for multiple << operators.
}

Fraction operator+(const Fraction &a, const Fraction &b)
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

Fraction operator*(const Fraction &a, const Fraction &b)
{
  Fraction c;
  c.numerator = a.numerator * b.numerator;
  c.denominator = a.denominator * b.denominator;
  return c;
}

bool operator>(const Fraction &a, const Fraction &b)
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

Fraction operator*(const Fraction &a, const int &i)
{
  Fraction c;
  c.numerator = a.numerator * i;
  c.denominator = a.denominator;
  return c;
}

Fraction operator*(const int &i, const Fraction &a)
{
  Fraction c;
  c.numerator = a.numerator * i;
  c.denominator = a.denominator;
  return c;
}

#endif