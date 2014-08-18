#ifndef Node_h
#define Node_h

template <class DataType>
struct Node
{
  DataType data;
  Node<DataType>* next;
};

#endif

#ifndef LinkedList_h
#define LinkedList_h

template <class DataType> 
class LinkedList
{
  public:
	LinkedList():start(0),current(0),size(0),currentIndex(-1){} // Constructor
	LinkedList(const LinkedList<DataType>& a); // Copy Constructor
	~LinkedList(); // Destructor 
	LinkedList<DataType>& operator=(const LinkedList<DataType>& a); // Operator=  
	DataType& operator[](double i);

	bool isEmpty() const {return start==0;} // Funtion to check if Linked List is empty
	void insert(const DataType& data); // Function to insert object into Linked List
	bool first(DataType& data); // Function to get first value and set "current" to its node
	bool getNext(DataType& data); // Function used with Get First for "iteration"
	bool find(const DataType& data); // Function to find matching element
	bool retrieve(DataType& data); // Function to find and retrieve matching element
	bool replace(const DataType& data); // Function to replace last-found element 
	bool remove(DataType& data); // Function to find, retrieve, and delete matching element
	void makeEmpty(); // Function to empty Linked List
	double length() const {return size;}
	double getCurentIndex() const {return currentIndex;}

  private:
	Node<DataType>* start; 
	Node<DataType>* current;
	DataType dummy;
	double size;
	double currentIndex;
};

#include "LinkedList.cpp"

#endif