#ifndef Stack_h
#define Stack_h

template <class DataType> 
class Stack
{
  public:
	Stack():capacity(2), data(new DataType[2]), top(-1){} // Constructor
	Stack(const Stack<DataType>& a); // Copy Constructor
	~Stack(){delete [] data;} // Destructor 
	Stack<DataType>& operator=(const Stack<DataType>& a); // Operator=  
	DataType& operator[](int index){return data[index];} // Operator[] 
	
	int size(){return (top+1);}
	bool isEmpty() const {return -1 == top;} // Funtion to check if stack is empty
	void push(DataType newObject); // Function to push object on to stack
	bool peek(DataType& getObject); // Function to peek at top object on stack
	bool pop(); // Function to pop object off top of stack
	void makeEmpty() {top = -1;} // Function to make stack empty

  private:
	DataType* data; 
    int capacity; 
    int top; // track newest value
    void changeSize(int newCapacity); // Resizing For Arrayed Stack

};

#include "Stack.cpp"

#endif