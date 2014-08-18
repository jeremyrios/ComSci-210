#ifndef PriorityQueue_h
#define PriorityQueue_h

#include "Array.h"

template<class DataType>
class PriorityQueue
{
  public:
	PriorityQueue():elements(2), heapsize(0){}
	PriorityQueue(const Array<DataType>& arr);
	void enqueue(const DataType& newElement);
	bool dequeue(DataType& remElement); // return false if heap is empty
	bool isEmpty() const {return (heapsize==0)?true:false;}
	void makeEmpty();
	int size() const {return heapsize;}

  private:
	Array<DataType> elements;
	int heapsize;
	inline void heapify(int i);
};

#include "PriorityQueue.cpp"

#endif
