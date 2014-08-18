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
  int length() const {return capacity;} // returns length of Array
  void changeSize(int newCapacity); 
  string err() const; // returns error message
  int lsearch(const DataType& T) const; // returns -1 if not found, or index if found)
  void sort(){quickSort(0,capacity-1);}  
  void sort(const int s, const int e){quickSort(s,e);}
  int bsearch(DataType& T){sort();return bsearch2(T, 0, capacity-1);} 



  private:
  int capacity;
  int errorCode;
  DataType* data; 
  DataType dummy; // requires default constructor

  void quickSort(const int s, const int e);
  int bsearch2(DataType& T, int s, int e) const;
};

#include "SortableArray.cpp"

#endif