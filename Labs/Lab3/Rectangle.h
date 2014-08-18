#ifndef Rectangle_h
#define Rectangle_h

template <class DataType>
class Rectangle
{
  public:
  void setLength(DataType l){length = l;}
  void setWidth(DataType w){width = w;}

  DataType getLength() const {return length;}
  DataType getWidth() const {return width;}
  
  bool isLengthBiggerThanWidth() const {return (length>width? true:false);}
  DataType perimeter(){return ((2*length)+(2*width));}
  DataType area(){return (length*width);}

  Rectangle(){}   // Constructor 1
  Rectangle(const DataType &w, const DataType &l); // Constructor 2
 
  private:
  DataType length;
  DataType width;

};

template <class DataType> // Constructor 2
Rectangle<DataType>::Rectangle(const DataType &w, const DataType &l)
{
  length = l;
  width = w;
}

#endif