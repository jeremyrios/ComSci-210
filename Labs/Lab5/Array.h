#ifndef Array_h
#define Array_h

#include <string>
using namespace std;

template <class DataType>
class Array
{
  public:
  Array(int initialCapacity); // Constructor
  Array(const Array<DataType>& a); // Copy constructor
  ~Array(); // Destructor
  Array<DataType>& operator=(const Array<DataType>& a); // Overloaded = (asignment) Operator
  DataType& operator[](int index); // Overloaded [] Operator
  int length() const; // Function to find length of Array
  void changeSize(int newCapacity); // Function to change size of Array
  string err() const; // Function that returns error message
  int lsearch(const DataType& T) const; // Linear search function (searches the array for a 
                                  // matching data item and returns -1 if not found, 
                                  // or the index if found)
  private:
  int capacity;
  int errorCode;
  DataType* data; 
  DataType dummy; // requires default constructor
};

#include "Array.cpp"

#endif