#include "Road.h"

void Road::setWidth(double w)
{
  width = w;
}

void Road::setLength(double l)
{
  length = l;
}

Road::Road(double w, double l)
{
  width = w;
  length = l;
}

double Road::asphalt(double thickness) const
{
  const double FtPerMile = 5280;
  double cubicFeet = width * (length*FtPerMile) * thickness;
  return cubicFeet;
}