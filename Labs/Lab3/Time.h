#ifndef Time_h
#define Time_h

class Time
{
  public:
  void setHours(double h){hours = h;}
  void setMinutes(double m){minutes = m;}
  void setSeconds(double s){seconds = s;}

  double getHours() const {return hours;}
  double getMinutes() const {return minutes;}
  double getSeconds() const {return seconds;}

  double timeInHours() const;
  double timeInMinutes() const;
  double timeInSeconds() const;

  Time(){}
  Time(double h, double m, double s);

  private:
  double hours;
  double minutes;
  double seconds;
};

#endif