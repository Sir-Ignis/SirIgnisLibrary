#include "square.h"
#include <iostream>

Square::Square(Sides)
{ 
}

Square::~Square()
{
}

Sides::Sides(unsigned int side)
{
  itsSide = side;
}

Sides::~Sides()
{
}

int main()
{
  unsigned int area;

  Sides mySides(8);
  //Square mySquare(sides);

  area = mySides.getSide()*mySides.getSide();

  cout << "Area of mySquare : " << area << endl;

  return 0;   
}
