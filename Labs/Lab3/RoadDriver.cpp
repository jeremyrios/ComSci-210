#include <iostream>
#include <iomanip>

#include "Road.h"
#include "Road.h"

using namespace std;

int main()
{
  Road I680(50, 200);
  cout <<  fixed;
  cout <<  setprecision (2);
  cout << "\n\n/////////////////////  Testing  ////////////////////////\n\n";

  cout << "I60 declared an initialized with a constructor" << endl
       << "Width = " << I680.getWidth() << " Feet --> Expected Value = 50" << endl
       << "Length = " << I680.getLength() << " Miles --> Expected Value = 200" << endl
       << "Cubic Feet of Asphalt Required = " << I680.asphalt(0.5) << " --> Expected Value = 26,400,000.00 \n\n";

  I680.setWidth(20.75);
  I680.setLength(168.8);
  cout << "I60 changed" << endl
       << "Width = " << I680.getWidth() << " Feet --> Expected Value = 20.75" << endl
       << "Length = " << I680.getLength() << " Miles --> Expected Value = 168.80" << endl
       << "Cubic Feet of Asphalt Required = " << I680.asphalt(0.3) << " --> Expected Value = 5,548,118.40 \n\n";

  Road I5(10.33, 500.26);
  cout << "I5 declared an initialized with a constructor" << endl
       << "Width = " << I5.getWidth() << " Feet --> Expected Value = 10.33" << endl
       << "Length = " << I5.getLength() << " Miles --> Expected Value = 500.26" << endl
       << "Cubic Feet of Asphalt Required = " << I5.asphalt(1.2) << " --> Expected Value = 32,742,457.23 \n\n";
  
  I5 = I680;
  cout << "I5 set = to I680" << endl
       << "Width = " << I5.getWidth() << " Feet --> Expected Value = 20.75" << endl
       << "Length = " << I5.getLength() << " Miles --> Expected Value = 168.80" << endl
       << "Cubic Feet of Asphalt Required = " << I5.asphalt(0.3) << " --> Expected Value = 5,548,118.40 \n\n";


  Road I10 = I680;
  cout << "I10 declared and set = to I680" << endl
       << "Width = " << I10.getWidth() << " Feet --> Expected Value = 20.75" << endl
       << "Length = " << I10.getLength() << " Miles --> Expected Value = 168.80" << endl
       << "Cubic Feet of Asphalt Required = " << I10.asphalt(0.3) << " --> Expected Value = 5,548,118.40 \n\n";

  I10.setWidth(5.78925);
  I10.setLength(66.64821);
  cout << "I10 changed" << endl
       << "Width = " << I10.getWidth() << " Feet --> Expected Value = 5.79" << endl
       << "Length = " << I10.getLength() << " Miles --> Expected Value = 66.65" << endl
       << "Cubic Feet of Asphalt Required = " << I10.asphalt(3.5274) << " --> Expected Value = 7,186,202.11 \n\n";
  cout << "/////////////////  End of Test   /////////////////////" << endl;
  return 0;
}