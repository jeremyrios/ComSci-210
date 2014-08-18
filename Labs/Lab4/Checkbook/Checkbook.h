#ifndef Checkbook_h
#define Checkbook_h

const int CAPACITY = 50;

template<class DataType>
struct CheckInfo{
  int numChecks;
  DataType checks[CAPACITY];
};

template <class DataType>
class Checkbook
{
  public:
  Checkbook();
  Checkbook(float initBalance);

  void setBalance(const float &amt){balance = amt;}
  bool writeCheck(const DataType &amt); //returns false if amount is greater than balence 
  void deposit(float amt);

  float getBalance() const {return balance;}
  DataType getLastCheck() const {return lastChecks[lastIndex];}
  //getLastChecks returns up to CAPACITY checks in a CheckInfo strucy
  //checks in the checks array are stored in order, with the latest check first 
  CheckInfo<DataType> getLastChecks() const;
  float getLastDeposit()const {return lastDeposit;}

  private:
  float balance;
  int numChecks; // the number of checks stored in the array
  int lastIndex; // the index of the last check that was written
  DataType lastChecks[CAPACITY]; //saves up to CAPACITY checks
  float lastDeposit;
};

#include "Checkbook.cpp"

#endif