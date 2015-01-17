#include <iostream>
using namespace std;

int fib(unsigned long int position);

int main()
{
  unsigned long int answer, position;

  cout << "\n\n"; 

  cout << "Which position? ";
  cin >> position;
  cout << "\n";

  answer = fib(position);
  cout << answer << " is the ";
  cout << position << "th Fibonacci number.\n";

  cout << "\n\n";

  return 0;
}

int fib(unsigned long int n)
{
  unsigned long int minusTwo = 1, minusOne = 1, answer = 2;

  if (n < 3)
    return 1;

  for (n -= 3; n; n--)
    {
      minusTwo = minusOne;
      minusOne = answer;
      answer = minusOne + minusTwo;
    }

  return answer;
}
