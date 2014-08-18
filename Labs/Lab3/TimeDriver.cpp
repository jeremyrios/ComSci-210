#include <iostream>
#include <iomanip>

#include "Time.h"
#include "Time.h"

using namespace std;

int main()
{
  cout <<  fixed;
  cout <<  setprecision (2);
  cout << "\n\n/////////////////////  Testing  ////////////////////////\n\n";

  Time London(1,40,30);
  cout << endl << "London - declared & intialized with constuctor" << endl
       << "Hours = " << London.getHours() << "   -->   Expected Value = 1 \n"
       << "Minutes = " << London.getMinutes() << "   -->   Expected Value = 40 \n"
       << "Seconds = " << London.getSeconds() << "   -->   Expected Value = 30 \n"
       << "Time In Hours = " << London.timeInHours() << "   -->   Expected Value = 1.68 \n"
       << "Time In Minutes = " << London.timeInMinutes() << "   -->   Expected Value = 100.50 \n"
       << "Time In Seconds = " << London.timeInSeconds() << "   -->   Expected Value = 6030.00 \n";

  London.setHours(5);
  London.setMinutes(36);
  London.setSeconds(45);
  cout << endl << "London changed" << endl
       << "Hours = " << London.getHours() << "   -->   Expected Value = 5 \n"
       << "Minutes = " << London.getMinutes() << "   -->   Expected Value = 36 \n"
       << "Seconds = " << London.getSeconds() << "   -->   Expected Value = 45 \n"
       << "Time In Hours = " << London.timeInHours() << "   -->   Expected Value = 5.61 \n"
       << "Time In Minutes = " << London.timeInMinutes() << "   -->   Expected Value = 336.75 \n"
       << "Time In Seconds = " << London.timeInSeconds() << "   -->   Expected Value = 20205.00 \n";

  /* If un-commented Expected all Garbage 
    cout << endl << "NewYork predeclared & ititalized with default constructor" << endl
       << "Hours = " << NewYork.getHours() << "   -->   Expected Value = Garbage \n"
       << "Minutes = " << NewYork.getMinutes() << "   -->   Expected Value = Garbage \n"
       << "Seconds = " << NewYork.getSeconds() << "   -->   Expected Value = Garbage \n"
       << "Time In Hours = " << NewYork.timeInHours() << "   -->   Expected Value = Garbage \n"
       << "Time In Minutes = " << NewYork.timeInMinutes() << "   -->   Expected Value = Garbage \n"
       << "Time In Seconds = " << NewYork.timeInSeconds() << "   -->   Expected Value = Garbage \n";
  */

  Time NewYork = London;
  cout << endl << "NewYork declared set = London" << endl
       << "Hours = " << NewYork.getHours() << "   -->   Expected Value = 5 \n"
       << "Minutes = " << NewYork.getMinutes() << "   -->   Expected Value = 36 \n"
       << "Seconds = " << NewYork.getSeconds() << "   -->   Expected Value = 45 \n"
       << "Time In Hours = " << NewYork.timeInHours() << "   -->   Expected Value = 5.61 \n"
       << "Time In Minutes = " << NewYork.timeInMinutes() << "   -->   Expected Value = 336.75 \n"
       << "Time In Seconds = " << NewYork.timeInSeconds() << "   -->   Expected Value = 20205.00 \n";

  NewYork.setHours(11);
  NewYork.setMinutes(12);
  NewYork.setSeconds(59);
  cout << endl << "NewYork changed" << endl 
       << "Hours = " << NewYork.getHours() << "   -->   Expected Value = 11 \n"
       << "Minutes = " << NewYork.getMinutes() << "   -->   Expected Value = 12 \n"
       << "Seconds = " << NewYork.getSeconds() << "   -->   Expected Value = 59 \n"
       << "Time In Hours = " << NewYork.timeInHours() << "   -->   Expected Value = 11.22 \n"
       << "Time In Minutes = " << NewYork.timeInMinutes() << "   -->   Expected Value = 672.98 \n"
       << "Time In Seconds = " << NewYork.timeInSeconds() << "   -->   Expected Value = 40379.00 \n";

  Time California(11,59,59);
  cout << endl << "California - declared & intialized with constuctor" << endl
       << "Hours = " << California.getHours() << "   -->   Expected Value = 11 \n"
       << "Minutes = " << California.getMinutes() << "   -->   Expected Value = 59 \n"
       << "Seconds = " << California.getSeconds() << "   -->   Expected Value = 59 \n"
       << "Time In Hours = " << California.timeInHours() << "   -->   Expected Value = 12.00 \n"
       << "Time In Minutes = " << California.timeInMinutes() << "   -->   Expected Value = 719.98 \n"
       << "Time In Seconds = " << California.timeInSeconds() << "   -->   Expected Value = 43199.00 \n";
  
  California = London;
  cout << endl << "California = London " << endl
       << "Hours = " << California.getHours() << "   -->   Expected Value = 5 \n"
       << "Minutes = " << California.getMinutes() << "   -->   Expected Value = 36 \n"
       << "Seconds = " << California.getSeconds() << "   -->   Expected Value = 45 \n"
       << "Time In Hours = " << California.timeInHours() << "   -->   Expected Value = 5.61 \n"
       << "Time In Minutes = " << California.timeInMinutes() << "   -->   Expected Value = 336.75 \n"
       << "Time In Seconds = " << California.timeInSeconds() << "   -->   Expected Value = 20205.00 \n";

  cout << "\n\n/////////////////  End of Test   /////////////////////\n\n";
  return 0;
}