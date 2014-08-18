

//Constructor no parameters
template <class DataType>
DynamicCheckbook<DataType>::DynamicCheckbook()
{
  numChecks = 2;
  checks = new DataType[numChecks];
  numChecksWritten = 0;
}

//Constructor with parameters
template <class DataType>
DynamicCheckbook<DataType>::DynamicCheckbook(float initBalance)
{
  numChecks = 2;
  checks = new DataType[numChecks];
  balance = initBalance;
  numChecksWritten = 0;
}

//Write Check
template <class DataType>
bool DynamicCheckbook<DataType>::writeCheck(float amt)
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
template <class DataType>
bool DynamicCheckbook<DataType>::deposit(float amt)
{
  if (amt <= 0) return false;
  balance += amt;
  lastDeposit = amt;
  return true;
}

//Get Checks
template <class DataType>
DataType* DynamicCheckbook<DataType>::getChecks() const
{
  DataType* temp = new DataType[numChecksWritten];
  for (int i=0; i<numChecksWritten; i++)
    temp[i] = checks[i];
  return temp;
}

//Double Dynamic Array
template <class DataType>
void DynamicCheckbook<DataType>::doubleArray()
{
  DataType* temp = new DataType[numChecks*2];
  for (int i=0; i<numChecks; i++)
    temp[i] = checks[i];
  delete [] checks;
  checks = temp;
  numChecks *= 2;
}