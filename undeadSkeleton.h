#ifndef UNDEADSKELTON_H
#define UNDEADSKELETON_H
#include <string>

using namespace std;

class monster
{
  public:
  unsigned int healthPoints, defencePoints;
  string typeOfMonster;

  monster(unsigned int healthPoints, unsigned int defencePoints, string typeOfMonster);
  ~monster();

  unsigned int getItsHealthPoints() {return itsHealthPoints;};
  unsigned int getItsDefencePoints() {return itsDefencePoints;};
  string getItsTypeOfMonster() {return itsTypeOfMonster;};

  private:
  
  unsigned int itsHealthPoints, itsDefencePoints;
  string itsTypeOfMonster;  

  void setItsHealthPoints(unsigned int itsHealthPoints) {itsHealthPoints = healthPoints;};
  void setItsDefencePoints(unsigned int itsDefencePoints) {itsDefencePoints = defencePoints;};
  void setItsTypeOfMonster(string setItsTypeOfMonster) {itsTypeOfMonster = typeOfMonster;};
};

monster::monster(unsigned int healthPoints, unsigned int defencePoints, string typeOfMonster)
{
  itsHealthPoints = healthPoints;
  itsDefencePoints = defencePoints;
  itsTypeOfMonster = typeOfMonster;
}

monster::~monster()
{
}

class skeleton : public monster
{
  public:
 skeleton(unsigned int healthPoints, unsigned int defencePoints, string typeOfMonster) : monster(healthPoints,defencePoints,typeOfMonster) {}; 
};

#endif
