#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace std;

bool GetWorld(char* string, char* word, int& wordOffset);
// driver program

int main()
{
  const int bufferSize = 255;
  char buffer[bufferSize+1]; // hold the entire string
   char word[bufferSize+1]; // hold the word
   int wordOffset = 0;

   cout << "Enter a string: ";
   cin.getline(buffer,bufferSize);

   while (GetWorld(buffer,word,wordOffset))
     {
       cout << "Got this word: " << word << endl;
     }

   return 0;
}

// function to parse words from a string.
bool GetWorld(char* string, char* word, int& wordOffset)
{

  if (!string[wordOffset]) // end of string?
    return false;

  char *p1, *p2;
  p1 = p2 = string+wordOffset; // point to the next word

    // eat leading spaces
    for (int i = 0; i<(int)strlen(p1) && !isalnum(p1[0]); i++)
      p1++;

  // see if you have a wor
  if (!isalnum(p1[0]))
    return false;

  // p1 now points to start of next word
  // point p2 there as well
  p2 = p1;

  // march p2 to end of word
  while (isalnum(p2[0]))
    p2++;

  // p2 is now at end of word
  // p1 is at biginning of word
  // length of word is the difference
  int len = int (p2 -p1);

  //copy the word into the buffer
  strncpy (word,p1,len);

  // null terminate it
  word[len]='\0';

  // now find the beginning of th next word
  for (int i = int(p2-string); i<(int)strlen (string) && !isalnum(p2[0]); i++)
    p2++;

  wordOffset = int(p2-string);

  return true;

}
