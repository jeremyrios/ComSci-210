template <class DataType> // Copy Constructor
Queue<DataType>::Queue(const Queue<DataType>& a)
: front(0), end(0)
{
  Node<DataType>* p;
  for (p = a.front; p; p = p->next)
  {
    Node<DataType>* node = new Node<DataType>;
    node->data = p->data;
    node->next = 0;
    if (end) end->next = node;
    else front = node;
    end = node;
} }

template <class DataType> // Destructor 
Queue<DataType>::~Queue()
{
  Node<DataType>* p;
  while (front) 
  { 
    p = front->next; 
    delete front; 
    front = p;
} }

template <class DataType> // Operator=  
Queue<DataType>& Queue<DataType>::operator=(const Queue<DataType>& a)
{
  if (this != &a)
  {
    Node<DataType>* p;
    end = 0;
    while (front) 
    { 
      p = front->next; 
      delete front; 
      front = p;
    }
    for (p = a.front; p; p = p->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      if (end) end->next = node;
      else front = node;
      end = node;
  } }
  return *this;
}

template <class DataType> // Function to push object on to Queue
void Queue<DataType>::push(DataType data)
{
  Node<DataType>* node = new Node<DataType>;
  node->data = data;
  node->next = 0;
  if (end) end->next = node;
  else front = node;
  end = node;
}

template <class DataType> // Function to peek at top object on Queue
bool Queue<DataType>::peek(DataType& data)
{
  if (0 == front) return false; // failed
  data = front->data;
  return true; // success
}

template <class DataType> // Function to pop object off top of Queue
bool Queue<DataType>::pop(DataType& data)
{
  if (0 == front) return false; // failed
  data = front->data;
  Node<DataType>* p = front->next;
  delete front;
  front = p;
  if (front == 0) end = 0;
  return true; // success
}

template <class DataType> // Function to make stack Queue
void Queue<DataType>::makeEmpty()
{
  end = 0;
  Node<DataType>* p;
  while (front) 
  { 
    p = front->next; 
    delete front; 
    front = p;
} }