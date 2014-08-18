template <class DataType> // Copy Constructor
LinkedList<DataType>::LinkedList(const LinkedList<DataType>& a)
: start(0), current(0), size(a.length()), currentIndex(a.currentIndex) 
{
  Node<DataType>* p;
  Node<DataType>* end = 0;
  for (p = a.start; p; p = p->next)
  {
    Node<DataType>* node = new Node<DataType>;
    node->data = p->data;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
	end=node;
    if (p == a.current) current = node; 
  }
}
 
template <class DataType> // Destructor For Any Linked List
LinkedList<DataType>::~LinkedList()
{
  Node<DataType>* p;
  while (start) 
  { 
    p = start->next; 
    delete start; 
    start = p;
  } 
}

template <class DataType> //Operator= For Singly-Linked List
LinkedList<DataType>& LinkedList<DataType>::operator=(const LinkedList<DataType>& a)
{
  size = a.length();
  if (this != &a)
  {
    current = 0;
	currentIndex=a.currentIndex;
    Node<DataType>* p;
    Node<DataType>* end = 0;
    while (start) // if "this" is something make it empty
    { 
      p = start->next; 
      delete start; 
      start = p;
    }
    for (p=a.start; p; p=p->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      if (end) end->next = node;
      else start = node;
	  end=node;
      if (p == a.current) current = node; 
    }
  }
  return *this;
}

template <class DataType> //Operator[] For Singly-Linked List
DataType& LinkedList<DataType>::operator[](double i)
{
  if(i<0||i>=length()) return dummy;
  double j=0;
  if(i>=currentIndex && currentIndex!=0)
  {
	for(j=(i-currentIndex); j>0; j--)
	{ 
      currentIndex++;
	  current=current->next;
	}

	return current->data;
  }
  else
  {
	for(j=0,current=start,currentIndex=0; j<i; j++)
	{ 
      currentIndex++;
	  current=current->next;
	}
	return current->data;
  }
}

template <class DataType> // Function to insert object into Linked List
void LinkedList<DataType>::insert(const DataType& data) // O(1)
{
  current = 0;
  Node<DataType>* node = new Node<DataType>;
  node->data = data;
  node->next = start;
  start = node;
  size++;
  currentIndex=0;
}

template <class DataType> // Function to get first value and set "current" to its node
bool LinkedList<DataType>::first(DataType& data) // O(1)
{
  if (!start) 
    return false;
  data = start->data;
  current = start;
  currentIndex=0;
  return true;
}

template <class DataType> // Function used with Get First for "iteration"
bool LinkedList<DataType>::getNext(DataType& data) // O(1)
{
  if (!current) 
    return false;
  current = current->next;
  currentIndex++;
  if (!current) 
	return false;
  data = current->data;
  return true;
}

template <class DataType> // Function to find matching element
bool LinkedList<DataType>::find(const DataType& data) // O(n)
{
  DataType temp;
  if (first(temp)) do
  {
    if (data == temp) return true; // found it
  } 
  while (getNext(temp));
  return false; // no match
}

template <class DataType> // Function to find and retrieve matching element
bool LinkedList<DataType>::retrieve(DataType& data) // O(n)
{
  if (!find(data)) return false;
  data = current->data; // set in find
  return true;
}

template <class DataType> // Function to replace last-found element 
bool LinkedList<DataType>::replace(const DataType& data) // O(1)
{
  if (!current) return false;
  current->data = data;
  return true;
}

template <class DataType> // Function to find, retrieve, and delete matching element
bool LinkedList<DataType>::remove(DataType& data) // O(n)
{
  // find node to remove
  Node<DataType>* p;
  Node<DataType>* prev;
  for (prev = 0, p = start; p; prev = p, p = p->next)
    if (p->data == data)
      break;

  // delete node here
  if (!p) return false; // no match
  if (prev)
    prev->next = p->next; 
  else 
    start = p->next;
  if (p == current)
	current = current->next;
  data = p->data;
  delete p;
  size--;
  return true;
}

template <class DataType> // Function to empty Linked List
void LinkedList<DataType>::makeEmpty() // O(n)
{
  while (start) 
  { 
    current = start->next; 
    delete start; 
    start = current;
  }
  size=0;
  currentIndex=-1;
}

