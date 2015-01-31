#include <iostream>
#include <vector>
#include <string>
using namespace std;


char convertStringToChar(vector<char> & encryptedText, signed int position)
{
  return encryptedText[position];
}

char convertReverseStringToChar(vector<char> & encryptedText, string reverseString, signed int position)
{
  return reverseString[position];
}

void Print (vector<char>& encryptedText)
{
  //vector<char> encryptedText;
  for (int i=0; i<encryptedText.size();i++){
    cout << encryptedText[i] << endl;
  }
}

vector<char> encryptText(string text)
{
  vector<char> encryptedText;
  string reverseString ;

  char encryptedTextCharacter;

  unsigned int hardPrime = 2147483647;
  signed int position = 0;

  for(position = text.length(); position != -1; position--)
    {
      reverseString = reverseString + (text[position]);
      cout << reverseString << endl;
    }

  for(;position < reverseString.length(); position++)
    {
      encryptedText.push_back (convertReverseStringToChar(encryptedText,reverseString, position));
    }

  for(;position < encryptedText.size(); position++)
    {
      encryptedTextCharacter = convertStringToChar(encryptedText, position);
      encryptedText.push_back (encryptedTextCharacter*hardPrime);
    }

  Print(encryptedText);
  return encryptedText;
}

int main()
{
  string text;

  cout << "Enter a string." << endl;
  cout << "String: " << endl;
  cin >> text;

  encryptText(text);
  
  return 0;
}



