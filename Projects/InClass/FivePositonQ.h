#ifndef FivePositonQ_h
#define FivePositonQ_h

#include <cassert> 

template <class DataType>
struct Node
{
  DataType data;
  Node<DataType>* next;
};

template <class DataType>
class FivePositonQ
{
  
  public:
  FivePositonQ();
  ~FivePositonQ();
  bool addNewItem(const DataType &);
  DataType FivePositonQ<DataType>::removeOldestItem();

  private:
  int size;
  Node<DataType>* start;
  Node<DataType>* end;
};  

template <class DataType>
FivePositonQ<DataType>::FivePositonQ()
{
  
}

template <class DataType>
FivePositonQ<DataType>::FivePositonQ(const FivePositonQ &q)
{
  size = q.size;
  start = end = 0;
  Node<DataType>* p;

  Node<DataType>* node = new Node<DataType>;
    node->data = t;
    node->next = 0;
    if (end) end->next = node; else start = node;
    end = node;
}

template <class DataType>
FivePositonQ<DataType>::~FivePositonQ()
{
  while(start)
  {
    p = start->next;
    delete start;
    start = p;
  }
}

template <class DataType>
bool FivePositonQ<DataType>::addNewItem(const DataType &t)
{
  bool result = false;
  if(size<5)
  {
    for (p = q.start; p; p = p->next)
    {
    Node<DataType>* node = new Node<DataType>;
    node->data = t;
    node->next = 0;
    if (end) end->next = node; else start = node;
    end = node;
    ++size;
    result = true;
  }
  assert((start == 0 && end ==0 && size == 0) || 
         (start != 0 && end !=0 && size != 0));
  return result;
}  

template <class DataType>
DataType FivePositonQ<DataType>::removeOldestItem()
{
  DataType result
    if(start)
    {
      Node<DataType>* p =start->next;
      result = start->data;
      delet start;
      start = p;
      if(start == 0) end = 0;
      --size;
    }
    assert((start == 0 && end ==0 && size == 0) || 
         (start != 0 && end !=0 && size != 0));
    return result;
}  
 
#endif