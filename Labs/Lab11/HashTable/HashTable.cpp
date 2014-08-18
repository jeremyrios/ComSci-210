template <class DataType> // Function to 
bool HashTable<DataType>::retrieve(DataType& a) 
{
  int i = a.hashCode() % HASHTABLE_CAPACITY;
  if (i<0) i+=HASHTABLE_CAPACITY;
  if(!data[i].empty())
  {
    typename list<DataType>::iterator it; 
    it = find(data[i].begin(), data[i].end(), a); 
    if (it != data[i].end()) 
	{
	  a = *it; // replace 
	  return true;
	}
  }
  return false;
}

template <class DataType> // Function to 
bool HashTable<DataType>::replace(const DataType& a)
{
  int i = a.hashCode() % HASHTABLE_CAPACITY;
  if (i<0) i+=HASHTABLE_CAPACITY;
  if(!data[i].empty())
  {
    typename list<DataType>::iterator it; 
    it = find(data[i].begin(), data[i].end(), a); 
    if (it != data[i].end()) 
	{
	  *it = a; // replace 
	  return true;
	}
  }
  return false;
}

template <class DataType> // Function to 
bool HashTable<DataType>::remove(DataType& a)
{
  int i = a.hashCode() % HASHTABLE_CAPACITY;
  if (i<0) i+=HASHTABLE_CAPACITY;
  if(!data[i].empty()) 
  {
    typename list<DataType>::iterator it; 
    it = find(data[i].begin(), data[i].end(), a); 
    if (it != data[i].end())
	{
	  a = *it; // replace 
	  it = data[i].erase(it);
	  elements--;
	  return true;
	}
  }
  return false;
}

template <class DataType> // Function to 
bool HashTable<DataType>::insert(const DataType& a)
{
  int i = a.hashCode() % HASHTABLE_CAPACITY;
  if (i<0) i+=HASHTABLE_CAPACITY;
  if(data[i].empty())
  {
    data[i].push_back(a);
	elements++;
	return true;
  }
  else 
  {
    typename list<DataType>::iterator it; 
    it = find(data[i].begin(), data[i].end(), a); 
    if (it != data[i].end()) 
	  *it = a; // replace 
    else 
	{
	  data[i].push_back(a);
	  elements++;
	}
	return true;
  }
}

template <class DataType> // Function to 
void HashTable<DataType>::clear()
{
  for(int i=0; i<HASHTABLE_CAPACITY; i++)
	data[i].clear();
  elements=0;
}
