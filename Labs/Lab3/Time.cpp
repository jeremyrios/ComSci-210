#include "Time.h"

double Time::timeInHours() const
{
  double hrs = hours + ((minutes +(seconds/60))/60);
  return hrs;
}

double Time::timeInMinutes() const
{
  double mins = (hours*60)+ minutes + (seconds/60);
  return mins;
}

double Time::timeInSeconds() const
{
  double secs = (((hours*60)+ minutes)*60) + seconds;
  return secs;
}

Time::Time(double h, double m, double s)
{
  hours = h;
  minutes = m;
  seconds = s;
}