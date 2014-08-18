#include <cassert>

template <class DataType> // Copy Constructor For Arrayed Stack
Stack<DataType>::Stack(const Stack<DataType>& a) 
: capacity(a.capacity), data(0), top(a.top)
{
  if (capacity > 0)
    data = new DataType[capacity];
  for (int i = 0; i < capacity; i++)
    data[i] = a.data[i];
}

template <class DataType> // Operator= For Arrayed Stack
Stack<DataType>& Stack<DataType>::operator=(const Stack<DataType>& a) 
{
  if (this != &a)
  {
    delete [] data;
    data = 0;
    capacity = a.capacity;
    if (capacity > 0)
      data = new DataType[capacity];
    for (int i = 0; i < capacity; i++)
      data[i] = a.data[i];
    top = a.top;
  }
  return *this;
}

template <class DataType>  // Resizing For Arrayed Stack (private function)
void Stack<DataType>::changeSize(int newCapacity) 
{
  assert(newCapacity > 0);
  DataType* newData = new DataType[newCapacity];
  int limit = newCapacity > capacity ? capacity : newCapacity;
  for (int i = 0; i < limit; i++) newData[i] = data[i];
  delete [] data;
  data = newData;
  capacity = newCapacity;
}

template <class DataType> // Function to push object on to stack
void Stack<DataType>::push(DataType newObject) 
{
  if (++top == capacity) // double the capacity as in Array
    changeSize(capacity*2);
  data[top] = newObject;
}

template <class DataType> // Function to peek at top object on stack
bool Stack<DataType>::peek(DataType& getObject) 
{
  if (-1 == top) return false; // failed
  getObject = data[top];
  return true; // success
}

template <class DataType> // Function to pop object off top of stack
bool Stack<DataType>::pop() 
{
  if (-1 == top) return false; // failed
  --top;
  if (top>2 && top<(capacity/4)) // halve the capacity
    changeSize(capacity/2);
  return true; // success
}
