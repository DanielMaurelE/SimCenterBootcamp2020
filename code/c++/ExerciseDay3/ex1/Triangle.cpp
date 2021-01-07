#include "Triangle.h"

int Triangle::numRect = 0;

Triangle::~Triangle() {
  numRect--;
  std::cout << "Triangle Destructor " << this->getColor() << "\n";
}

Triangle::Triangle(double b, double d, string color)
  :ColoredShape(color), base(b), height(d)
{
  numRect++;
}

double
Triangle::getArea(void) {
  return base*height/2.0;
}

void 
Triangle::printArea(std::ostream &s) {
  s << "Triangle: color: " << this->getColor() << ", area: "
    << base * height/2.0 << " numRect: " << numRect << "\n";
}

