#include <iostream>
#include <string>
using namespace std;

bool checkIfPrime(unsigned int number);

int main()
{
  cout << "\n\nPrime number hunter V0.1\n\n" << endl;

  unsigned int number;

  cout << "Enter a number." << endl;
  cout << "Number: ";
  cin >> number;

  bool isPrime;

  isPrime = checkIfPrime(number);

  if (isPrime == false) cout << "The number you entered is not a prime number." << endl;
  else cout << "The number you entered is a prime number!" << endl;

  return 0;
}

bool checkIfPrime(unsigned int number)
{
  unsigned int counter, numberOfFactors = 0;

  for (counter = 1; counter < (number+1); counter++)
    {
      if(number % counter == 0)
	{
	  numberOfFactors++;
	}  
    }
  if(numberOfFactors == 2) return 1;
  else return 0;
}
