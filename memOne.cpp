#include <iostream>
using namespace std;

//--NOTE--
//You must enter all the text without any enters in between, i.e. no gaps as big or bigger than a line.

int main()
{
  string text; 

  cout << "\n\n";
  cout << "Enter string: ";
  getline(cin,text);

  cout << "\n";

  unsigned int i;

  cout << text[0] << " ";  

  for (i = 0; i < text.length(); i++)
    {
      if (text[i] == char(32))
	{
          cout << text[i+1] << " ";
	}
    }

  cout << "\n\n";

  return 0;
}
