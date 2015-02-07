#ifndef SQUARE_H
#define SQUARE_H
using namespace std;

class Sides
{
  public:
         Sides(unsigned int side);
         ~Sides();
         unsigned int getSide() const { return itsSide;}
  private:
         void setItsSide(unsigned int side) { itsSide = side;}
         unsigned int itsSide;
};

class Square
{
  public:
         Square(Sides);
         ~Square();
};

#endif
