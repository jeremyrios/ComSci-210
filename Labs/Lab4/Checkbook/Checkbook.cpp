
template <class DataType>
Checkbook<DataType>::Checkbook()
{
  lastIndex =-1;
  numChecks = 0;
}

template <class DataType>
Checkbook<DataType>::Checkbook(float initBalance)
{
  balance = initBalance;
  lastIndex =-1;
  numChecks = 0;
}

template <class DataType>
bool Checkbook<DataType>::writeCheck(const DataType &amt)
{
  if (amt > balance)
    return false;
  balance -= amt;
  if(lastIndex == CAPACITY)
    lastIndex = 0;
  lastChecks[lastIndex] = amt;
  if(numChecks != CAPACITY)
    numChecks++;
  return true;
}

template <class DataType>
void Checkbook<DataType>::deposit(float amt)
{
  if (amt <= 0) return;
  balance += amt;
  lastDeposit = amt;
}

template <class DataType>
CheckInfo<DataType> Checkbook<DataType>::getLastChecks() const
{
  CheckInfo<DataType> info;
  info.numChecks = numChecks;
  for(int i=0, j=lastIndex; i<numChecks; i++, j--)
  {
	if(j==-1)
	  j = CAPACITY-1;
    info.checks[i] = lastChecks[j];
  }
  return info;
}