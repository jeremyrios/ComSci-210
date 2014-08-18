#include "Checkbook.h"

//Constructor no parameters
DynamicCheckbook::DynamicCheckbook()
{
  numChecks = 2;
  checks = new Check[numChecks];
  numChecksWritten = 0;
}

//Constructor with parameters
DynamicCheckbook::DynamicCheckbook(float initBalance)
{
  numChecks = 2;
  checks = new Check[numChecks];
  balance = initBalance;
  numChecksWritten = 0;
}

//Write Check
bool DynamicCheckbook::writeCheck(float amt)
{
  if (amt > balance)
    return false;
  balance -= amt;
  if(numChecksWritten == numChecks)
    doubleArray();
  checks[numChecksWritten].amount = amt;
  checks[numChecksWritten].checkNumber = (numChecksWritten+1);
  numChecksWritten++;
  return true;
}

//Make a Deposit
bool DynamicCheckbook::deposit(float amt)
{
  if (amt <= 0) return false;
  balance += amt;
  lastDeposit = amt;
  return true;
}

//Get Checks
Check* DynamicCheckbook::getChecks() const
{
  Check* temp = new Check[numChecksWritten];
  for (int i=0; i<numChecksWritten; i++)
    temp[i] = checks[i];
  return temp;
}

//Double Dynamic Array
void DynamicCheckbook::doubleArray()
{
  Check* temp = new Check[numChecks*2];
  for (int i=0; i<numChecks; i++)
    temp[i] = checks[i];
  delete [] checks;
  checks = temp;
  numChecks *= 2;
}