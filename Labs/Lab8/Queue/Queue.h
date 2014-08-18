#ifndef Node_h
#define Node_h

template <class DataType>
struct Node
{
  DataType data;
  Node<DataType>* next;
};

#endif

#ifndef Queue_h
#define Queue_h

template <class DataType> 
class Queue
{
  public:
	Queue():front(0), end(0){} // Constructor
	Queue(const Queue<DataType>& a); // Copy Constructor
	~Queue(); // Destructor 
	Queue<DataType>& operator=(const Queue<DataType>& a); // Operator=  

	bool isEmpty() const {return 0==front;} // Funtion to check if Queue is empty
	void push(DataType data); // Function to push object on to Queue
	bool peek(DataType& data); // Function to peek at top object on Queue
	bool pop(DataType& data); // Function to pop object off top of Queue
	void makeEmpty(); // Function to empty Queue

  private:
	Node<DataType>* front; 
    Node<DataType>* end;
};

#include "Queue.cpp"

#endif