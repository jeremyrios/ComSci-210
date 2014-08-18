#ifndef Array_h
#define Array_h

#include <string>
using namespace std;

template <class DataType>
class Array
{
  public:
  Array(int initialCapacity);
  Array(const Array<DataType>& a);
  ~Array();
  Array<DataType>& operator=(const Array<DataType>& a);
  DataType& operator[](int index);
  int length() const;
  void changeSize(int newCapacity);
  string err() const;

  private:
  int capacity;
  int errorCode;
  DataType* data;
  DataType dummy; // requires default constructor
};

#include "Array.cpp"

#endif