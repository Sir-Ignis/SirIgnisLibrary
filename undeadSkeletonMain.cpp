#include "undeadSkeleton.h" 
#include <iostream>
using namespace std;

int main()
{
  //31 = red
  //32 = green
  cout << "\n\n\n";
  
  string blueO = "\033[1;34m";
  string blueC = "\033[0m";

  string redO  	   = "\033[3;31m"; //open italic bold red 
  string redC  	   = "\033[0m"; //close italic red
 
  string greenO  	   = "\033[5;32m"; //open flashing green
  string greenC  	   = "\033[0m"; //close flashing green

  skeleton Skeleton(100,5,"Jimmy");

  cout << "I have created " << blueO <<  Skeleton.getItsTypeOfMonster() << blueC <<  " he has " << 
    Skeleton.getItsHealthPoints() << redO <<  " health points, " << redC << Skeleton.getItsDefencePoints() << greenO << " defence points." << greenC << endl;

  cout << "\n\n\n";

  return 0;
}
