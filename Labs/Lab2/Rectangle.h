#ifndef Rectangle_h
#define Rectangle_h

template <class DataType>
class Rectangle
{
  public:
  void setLength(DataType len){length = len;}
  void setWidth(DataType wid){width = wid;}

  DataType getLength(){return length;}
  DataType getWidth(){return width;}
  
  bool lenBiggerThanWid(){if(length>width){return true;} return false;}
  DataType perimeter(){return ((2*length)+(2*width));}
  DataType area(){return (length*width);}
 
  private:
  DataType length;
  DataType width;

};
#endif