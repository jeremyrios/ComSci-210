#ifndef Road_h
#define Road_h

class Road
{
  public:
    Road(double, double); // a constructor
    void setWidth(double);
    void setLength(double);
    double getWidth() const {return width;}
    double getLength() const {return length;}
    double asphalt(double) const;


  private:
    double width;
    double length;
};


#endif