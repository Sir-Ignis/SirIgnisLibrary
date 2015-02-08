#include <iostream>
using namespace std;
enum CHOICE { DrawRect = 1, GetArea, GetPerim, ChangeDimensions, Quit};

//Rectangle class declaration
class Rectangle
{
public:
  // constructors
  Rectangle(int width, int height);
  ~Rectangle();

  // accessors
  int GetHeight() const { return itsHeight; }
  int GetWidth() const { return itsWidth; }
  int GetArea() const { return itsHeight * itsWidth; }
  int GetPerim() const { return 2*itsHeight + 2*itsWidth; }
  void SetSize(int newWidth, int newHeight);

  // Misc. methods


private:
  int itsWidth;
  int itsHeight;
};


// Class method implementations
void Rectangle::SetSize(int newWidth, int newHeight)
{
  itsWidth = newWidth;
  itsHeight = newHeight;
}

Rectangle::Rectangle(int width, int height)
{
  itsWidth = width;
  itsHeight = height;
}

 Rectangle::~Rectangle() {}

 int DoMenu();
 void DoDrawRect(Rectangle);
 void DoGetArea(Rectangle);
 void DoGetPerim(Rectangle);

 int main()
 {
  // initialize a rectangle to 30,5
  Rectangle theRect(30,5);

  int choice = DrawRect;
  int fQuit = false;

  while (!fQuit)
    {
  choice = DoMenu();
  if (choice < DrawRect || choice  > Quit)
    {
  cout << "\nInvalid Choice, please try again.\n\n";
  continue;
}
  switch (choice)
    {
 case DrawRect:
 DoDrawRect(theRect);
 break;
 case GetArea:
   DoGetArea(theRect);
   break;
 case GetPerim:
   DoGetPerim(theRect);
   break;
 case ChangeDimensions:
   int newLength, newWidth;
   cout << "\nNew width: ";
   cin >> newWidth;
   cout << "New height: ";
   cin >> newLength;
   theRect.SetSize(newWidth, newLength);
   DoDrawRect(theRect);
   break;
 case Quit:
   fQuit = true;
   cout << "\nExiting...\n\n";
   break;
 default:
   cout << "Error in choice!\n";
   fQuit = true;
   break;
  }  // end switch
} // end while
  return 0;
} // end main

 int DoMenu()
 {
  int choice;
  cout << "\n\n *** Menu *** \n";
  cout << "(1) Draw rectangle\n";
  cout << "(2) Area\n";
  cout << "(3) Perimeter\n";
  cout << "(4) Resize\n";
  cout << "(5) Quit\n";

  cin >> choice;
  return choice;
}

 void DoDrawRect(Rectangle theRect)
 {
  int height = theRect.GetHeight();
  int width = theRect.GetWidth();

  for (int i = 0; i< height; i++)
    {
  for (int j = 0; j< width; j++)
    cout << "*";
  cout << "\n";
}
}

 void DoGetArea(Rectangle theRect)
 {
  cout << "Area: " << theRect.GetArea() << endl;
}

 void DoGetPerim(Rectangle theRect)
 {
  cout << "Perimeter: " << theRect.GetPerim() << endl;
}
