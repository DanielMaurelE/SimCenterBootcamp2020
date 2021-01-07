#ifndef _TRIANGLE
#define _TRIANGLE

#include "ColoredShape.h"

class Triangle: public ColoredShape {
 public:
  Triangle(double b, double h, string color);
  ~Triangle();
  double getArea(void);
  void printArea(std::ostream &s);  

 protected:

 private:
  double base, height;
  static int numRect;
};

#endif // _RECTANGLE

  
