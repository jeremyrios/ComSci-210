#define HASHTABLE_CAPACITY 1009

#ifndef HashTable_h
#define HashTable_h

#include <string>
#include <list>
#include <algorithm>

template <class DataType>
class HashTable
{
  public:
	HashTable():elements(0){}

	int size() const {return elements;}
    bool empty() const {return (elements==0)?true:false;}
	bool retrieve(DataType&) ;
	bool replace(const DataType&);
	bool remove(DataType&);
	bool insert(const DataType&);
	void clear();

  private:
	list<DataType> data[HASHTABLE_CAPACITY];
	int elements; // # of elements in hash table
};

#include "HashTable.cpp"

#endif