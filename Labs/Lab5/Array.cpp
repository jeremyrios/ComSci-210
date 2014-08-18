template <class DataType> // Constructor
Array<DataType>::Array(int initialCapacity)
: capacity(initialCapacity), errorCode(0), data(0)
{
  if (capacity <= 0)
    errorCode |= 1;
  else
    data = new DataType[capacity];    
}

template <class DataType> // Destructor
Array<DataType>::~Array()
{
  delete [] data;
}

template <class DataType> // Copy constructor
Array<DataType>::Array(const Array<DataType>& a)
: capacity(a.capacity), errorCode(a.errorCode), data(0)
{
  if (capacity > 0)
    data = new DataType[capacity];
  for (int i = 0; i < capacity; i++)
    data[i] = a.data[i];
}

template <class DataType> // Overloaded [] Operator
DataType& Array<DataType>::operator[](int index)
{
  if (index < 0 || index >= capacity)
  {
    errorCode |= 2;
    return dummy;
  }
  errorCode &= (7 - 2); // unset
  return data[index];
}

template <class DataType> // Overloaded = (asignment) Operator
Array<DataType>& Array<DataType>::operator=(const Array<DataType>& a)
{
  if (this != &a)
  {
    delete [] data;
    data = 0;
    capacity = a.capacity;
    errorCode = a.errorCode;
    if (capacity > 0)
      data = new DataType[capacity];
    for (int i = 0; i < capacity; i++)
      data[i] = a.data[i];
  }
  return *this;
}

template <class DataType> // Function to find length of Array
int Array<DataType>::length() const
{
  return capacity;
}

template <class DataType> // Function to change size of Array
void Array<DataType>::changeSize(int newCapacity)
{
  errorCode &= (7 - 4); // unset
  if (newCapacity <= 0)
    errorCode |= 4;
  else
  {
    DataType* newData = new DataType[newCapacity];
    int limit = newCapacity > capacity ? capacity : newCapacity;
    for (int i = 0; i < limit; i++)
      newData[i] = data[i];
    delete [] data;
    data = newData;
    capacity = newCapacity;
  } 
}

template <class DataType> // Function that returns error message
string Array<DataType>::err() const
{
  string result;
  if (errorCode & 1)
    result += string(result.length() ? " | " : "") + "invalid size parameter in constructor";
  if (errorCode & 2)
    result += string(result.length() ? " | " : "") + "invalid index used in []";
  if (errorCode & 4)
    result += string(result.length() ? " | " : "") + "invalid resize parameter in changeSize";
  return result;
}

 template <class DataType> // Linear search function (searches the array for a matching data 
int Array<DataType>::lsearch(const DataType& T) const // item and returns -1 if not found, 
{                                                  // or the index if found)
  for(int i=0; i<capacity; i++)
  {
	if(T == data[i]) return i;
  }
  return -1;
}