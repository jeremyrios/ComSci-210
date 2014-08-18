#ifndef TwoDArray_H
#define TwoDArray_H

const int INIT_ROWS = 2;
const int INIT_COLS = 2;

template <class DataType>
struct Row
{
  DataType& operator[](int);

  private:
    DataType* data;
    int size; // #of columns in the row
};

template <class DataType>
class TwoDArray
{
  public:
    Row<DataType>& operator[](int);

  private:
    Row<DataType>* data;
    
};

template <class DataType>
DataType& Row<DataType>::operator[](int col)
{
  // if col < 0 fail
  // if col.= size, resize... maybe
  return data[col];
}

template <class DataType>
Row<DataType>& TwoDArray<DataType>::operator[](int row)


template <class DataType>
TwoDArray<DataType>::TwoDArray()
:size(INIT_ROWS),data(new DataType[size]){}

#endif

//return # rows & # columns