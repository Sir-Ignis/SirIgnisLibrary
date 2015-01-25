#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector <vector <int> > & boardPosition);
void checkMove(vector <vector <int> > & boardPosition, unsigned int row, unsigned int column);
bool checkIfBoardFull(vector <vector <int> > & boardPosition, bool & gameOver, bool & tie);

bool getPlayerMove(vector <vector <int> > & boardPosition);
bool getComputerMove(vector <vector <int> > & boardPosition, bool & placed);
void computerAI(vector <vector <int> > & boardPosition, bool & placed);

bool checkBoardColumnOne(vector <vector <int> > & boardPosition, bool & gameOver, bool & player);
bool checkBoardColumnTwo(vector <vector <int> > & boardPosition, bool & gameOver, bool & player);
bool checkBoardColumnThree(vector <vector <int> > & boardPosition, bool & gameOver, bool & player);

bool checkBoardRowOne(vector <vector <int> > & boardPosition, bool & gameOver, bool & player);
bool checkBoardRowTwo(vector <vector <int> > & boardPosition, bool & gameOver, bool & player);
bool checkBoardRowThree(vector <vector <int> > & boardPosition, bool & gameOver, bool & player);

bool checkBoardDiagonalLeft(vector <vector <int> > & boardPosition, bool & gameOver, bool & player);
bool checkBoardDiagonalRight(vector <vector <int> > & boardPosition, bool & gameOver, bool & player);


int main()
{
  vector <vector<int> > boardPosition(3, vector<int>(3, 0) );
  bool gameOver = false;
  bool player = 1;
  bool placed = false;
  bool tie = false;

  unsigned short int move;

  do
    {
      printBoard(boardPosition);
      getPlayerMove(boardPosition);

      checkBoardColumnOne(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkBoardColumnTwo(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkBoardColumnThree(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkBoardRowOne(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkBoardRowTwo(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkBoardRowThree(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkBoardDiagonalLeft(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkBoardDiagonalRight(boardPosition,gameOver, player);
      if(gameOver == true) break;
     
      getComputerMove(boardPosition, placed);

      checkBoardColumnOne(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkBoardColumnTwo(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkBoardColumnThree(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkBoardRowOne(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkBoardRowTwo(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkBoardRowThree(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkBoardDiagonalLeft(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkBoardDiagonalRight(boardPosition,gameOver, player);
      if(gameOver == true) break;

      checkIfBoardFull(boardPosition, gameOver, tie);
      if(tie == true) break;
    }
  while(gameOver == false);

  printBoard(boardPosition);

  if ((gameOver == true) && (player == 1)) 
    {
      cout << "Game over! You won!" << endl;
    }
  else if ((gameOver == true) && (player == 0))
    {
      cout << "Hahaha! I won!" << endl;
    }
  else if (tie == true)
    {
      cout << "It's a tie!" << endl;
    }
  return 0;    
}

// sexy print board functions are property of nnemesis
char getCharacter(int boardPosition)
{
  if (boardPosition == 0)
  {
    return '=';
  }
  else if (boardPosition == 1)
  {
    return 'X';
  }
  else if (boardPosition == 2)
  {
    return '0';
  }
}

void printBoard(vector <vector <int> > & boardPosition)
{
  cout << "\n";
  cout << " " << getCharacter(boardPosition[0][0]);
  cout << " " << getCharacter(boardPosition[0][1]);
  cout << " " << getCharacter(boardPosition[0][2]);
  cout << "\n\n";
  cout << " " << getCharacter(boardPosition[1][0]);
  cout << " " << getCharacter(boardPosition[1][1]);
  cout << " " << getCharacter(boardPosition[1][2]);
  cout <<"\n\n";
  cout << " " << getCharacter(boardPosition[2][0]);
  cout << " " << getCharacter(boardPosition[2][1]);
  cout << " " << getCharacter(boardPosition[2][2]);
  cout << "\n\n";
}

bool checkIfBoardFull(vector <vector <int> > & boardPosition, bool & gameOver, bool & tie)
{
  unsigned short int row, column, filled = 0;

  for (row = 0, column = 0; row < 3; row++)
    {
      for (column = 0;column < 3; column++)
	{
          if(boardPosition[row][column] != 0)
	  {
            filled++;
	  }
	}
    }
  if(filled == 9)
    {
      return tie = true;
    }
  else
    {
      return gameOver = false;
    }
}

void checkMove(vector <vector <int> > & boardPosition, unsigned int row, unsigned int column)
{
  if(boardPosition[row][column] == 2)
    {
      cout << "There is already an opponents piece here!" << endl;
      getPlayerMove(boardPosition);
    }
  else if(boardPosition[row][column] == 1)
    {
      cout << "You have already placed a piece here!" << endl;
      getPlayerMove(boardPosition);
    }
}

bool getPlayerMove(vector <vector <int> > & boardPosition)
{
  unsigned int row, column;

  do
    {
  cout << "Enter your move." << endl;
  cout << "Row (0-2): ";
  cin >> row;
  cout << "\n";
  cout << "Column (0-2): ";
  cin >> column;
  cout << "\n";
  if( (row < 0 || row > 2) || (column < 0 || column > 2) ) cout << "Error!" << endl;
    }
  while( (row < 0 || row > 2) || (column < 0 || column > 2) );
  checkMove(boardPosition, row, column);
  boardPosition[row][column] = 1;
}

bool getComputerMove(vector <vector <int> > & boardPosition, bool & placed)
{
  placed = false;

  computerAI(boardPosition, placed);

  if (placed == false)
    {
  if(boardPosition[1][1] == 0) boardPosition[1][1] = 2;

  else if (boardPosition[1][0] == 0) boardPosition[1][0] = 2;
  
  else if (boardPosition[0][1] == 0) boardPosition[0][1] = 2;

  else if (boardPosition[1][2] == 0) boardPosition[1][2] = 2;
    
  else if (boardPosition[2][1] == 0) boardPosition[2][1] = 2;

  else if (boardPosition[0][0] == 0) boardPosition[0][0] = 2;

  else if (boardPosition[0][2] == 0) boardPosition[0][2] = 2;

  else if (boardPosition[2][0] == 0) boardPosition[2][0] = 2;

  else if (boardPosition[2][2] == 0) boardPosition[2][2] = 2;
    }
}


//a|d|g//
//b|e|h//
//c|f|i//

void computerAI(vector <vector <int> > & boardPosition, bool & placed)
{
  placed = false;

  if((boardPosition[0][0] == 1) && (boardPosition[1][0] == 1))  // a+d = g
    {
      if(boardPosition[2][0] == 0)
        {
	  boardPosition[2][0] = 2;
         placed = true;
        } 
    }  
  else if((boardPosition[0][0] == 1) && (boardPosition[0][2] == 1)) //a+g = d
    {
       if(boardPosition[0][1] == 0) 
       {
         boardPosition[0][1] = 2;
         placed = true;
       } 
    }
  else if((boardPosition[0][1] == 1) && (boardPosition[2][1] == 1)) //d+f = e
    {
       if(boardPosition[1][1] == 0)
       {
         boardPosition[1][1] = 2;
         placed = true;
       } 
    }
  else  if((boardPosition[0][1] == 1) && (boardPosition[1][1] == 1)) //d+e = f
    {
       if (boardPosition[2][1] == 0) 
       {
         boardPosition[2][1] = 2;
         placed = true;
       }
    }
  else if((boardPosition[0][2] == 1) && (boardPosition[1][2] == 1))  //g+h = i 
    {
       if (boardPosition[2][2] == 0)   
       {
         boardPosition[2][2] = 2;
         placed = true;
       }
    } 
  else if((boardPosition[0][0] == 1) && (boardPosition[0][1] == 1)) //a+d = g
    {
       if (boardPosition[0][2] == 0) 
       {
         boardPosition[0][2] = 2;
         placed = true;
       }
    }
  else if((boardPosition[0][0] == 1) && (boardPosition[1][0] == 1)) //a+b = c
    {
       if (boardPosition[2][0] == 0) 
       {
         boardPosition[2][0] = 2;
         placed = true;
       }
    }
  else if((boardPosition[0][0] == 1) && (boardPosition[2][0] == 1)) //a+c = b
    {
       if (boardPosition[0][1] == 0) 
       {
         boardPosition[0][1] = 2;
         placed = true;
       }
    }
  else if((boardPosition[1][0] == 1) && (boardPosition[1][1] == 1)) //b+e = h
    {
       if (boardPosition[1][2] == 0) 
       {
         boardPosition[1][2] = 2;
         placed = true;
       }
    }
  else if((boardPosition[1][0] == 1) && (boardPosition[2][0] == 1)) //b+c = a
    {
       if (boardPosition[0][0] == 0) 
       {
         boardPosition[0][0] = 2;
         placed = true;
       }
    }
  else if((boardPosition[1][0] == 1) && (boardPosition[1][2] == 1)) //b+h = e
    {
       if (boardPosition[1][1] == 0) 
       {
         boardPosition[1][1] = 2;
         placed = true;
       }
    }
  else if((boardPosition[2][0] == 1) && (boardPosition[2][1] == 1)) //c+f = i
    {
       if (boardPosition[2][2] == 0) 
       {
         boardPosition[2][2] = 2;
         placed = true;
       } 
    }
  else if((boardPosition[2][0] == 1) && (boardPosition[2][2] == 1)) //c+i = f
    {
       if (boardPosition[2][1] == 0) 
       {
         boardPosition[2][1] = 2;
         placed = true;
       } 
    }
  else if((boardPosition[2][0] == 1) && (boardPosition[1][1] == 1)) //c+e = g
    {
       if (boardPosition[0][2] == 0) 
       {
         boardPosition[0][2] = 2;
         placed = true;
       } 
    }
  else if((boardPosition[2][1] == 1) && (boardPosition[1][1] == 1)) //f+e = d
    {
       if (boardPosition[0][1] == 0) 
       {
         boardPosition[0][1] = 2;
         placed = true;
       }
    }
  else if((boardPosition[0][0] == 1) && (boardPosition[1][1] == 1)) //a+e = i
    {
       if (boardPosition[2][2] == 0) 
       {
         boardPosition[2][2] = 2;
         placed = true;
       } 
    }
  else if((boardPosition[0][2] == 1) && (boardPosition[1][1] == 1)) //g+e = c
    {
       if (boardPosition[2][0] == 0) 
       {
         boardPosition[2][0] = 2;
         placed = true;
       } 
    }
  else if((boardPosition[0][2] == 1) && (boardPosition[2][0] == 1)) //g+c = e
    {
       if (boardPosition[1][1] == 0) 
       {
         boardPosition[1][1] = 2;
         placed = true;
       }
    }
  else if((boardPosition[1][2] == 1) && (boardPosition[1][1] == 1)) //h+e = b
    {
       if (boardPosition[1][0] == 0) 
       {
         boardPosition[1][0] = 2;
         placed = true;
       } 
    }
  else if((boardPosition[1][2] == 1) && (boardPosition[2][2] == 1)) //h+i = g
    {
       if (boardPosition[2][0] == 0) 
       {
         boardPosition[2][0] = 2;
         placed = true;
       }
    }
  else if((boardPosition[0][2] == 1) && (boardPosition[0][1] == 1)) //g+d = a
    {
       if (boardPosition[0][0] == 0) 
       {
         boardPosition[0][0] = 2;
         placed = true;
       }
    }
  else if((boardPosition[2][2] == 1) && (boardPosition[2][1] == 1)) //i+f = c
    {
       if (boardPosition[2][0] == 0) 
       {
         boardPosition[2][0] = 2;
         placed = true;
       }
    }
  else if((boardPosition[2][2] == 1) && (boardPosition[1][1] == 1)) //i+e = a
    {
       if (boardPosition[0][0] == 0) 
       {
         boardPosition[0][0] = 2;
         placed = true;
       }
    }
}

bool checkBoardColumnOne(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
  if((boardPosition[0][0] == 1) && (boardPosition[1][0] == 1) && (boardPosition[2][0] == 1 ))
    {
      player = 1;
      return gameOver = true;
    }     
  else if((boardPosition[0][0] == 2) && (boardPosition[1][0] == 2) && (boardPosition[2][0] == 2 ))
    {
      player = 0;
      return gameOver = true;
    } 	 
}


bool checkBoardColumnTwo(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
  if((boardPosition[0][1] == 1) && (boardPosition[1][1] == 1) && (boardPosition[2][1] == 1))
    {
      player = 1;
      return gameOver = true;
    }
  else if((boardPosition[0][1] == 2) && (boardPosition[1][1] == 2) && (boardPosition[2][1] == 2))
    {
      player = 0;
      return gameOver = true;
    }
}

bool checkBoardColumnThree(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
  if((boardPosition[0][2] == 1) && (boardPosition[1][2] == 1) && (boardPosition[2][2] == 1))
    {
      player = 1;
      return gameOver = true;
    }
  else if((boardPosition[0][2] == 2) && (boardPosition[1][2] == 2) && (boardPosition[2][2] == 2))
    {
      player = 0;
      return gameOver = true;
    }
}

bool checkBoardRowOne(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
  if((boardPosition[0][0] == 1) && (boardPosition[0][1] == 1) && (boardPosition[0][2] == 1))
    {
      player = 1;
      return gameOver = true;
    } 
     else if((boardPosition[0][0] == 2) && (boardPosition[0][1] == 2) && (boardPosition[0][2] == 2))
    {
      player = 0;
      return gameOver = true;
    }
}

bool checkBoardRowTwo(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
   if((boardPosition[1][0] == 1) && (boardPosition[1][1] == 1) && (boardPosition[1][2] == 1))
    {
      player = 1;
      return gameOver = true;
    } 
   if((boardPosition[1][0] == 2) && (boardPosition[1][1] == 2) && (boardPosition[1][2] == 2))
    {
      player = 0;
      return gameOver = true;
    }
}

bool checkBoardRowThree(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
   if((boardPosition[2][0] == 1) && (boardPosition[2][1] == 1) && (boardPosition[2][2] == 1))
    {
      player = 1;
      return gameOver = true;
    }
   else if((boardPosition[2][0] == 2) && (boardPosition[2][1] == 2) && (boardPosition[2][2] == 2))
    {
      player = 0;
      return gameOver = true;
    }
}

bool checkBoardDiagonalLeft(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
   if((boardPosition[0][0] == 1) && (boardPosition[1][1] == 1) && (boardPosition[2][2] == 1))
    {
      player = 1;
      return gameOver = true;
    } 
   else if((boardPosition[0][0] == 2) && (boardPosition[1][1] == 2) && (boardPosition[2][2] == 2))
    {
      player = 0;
      return gameOver = true;
    }
}

bool checkBoardDiagonalRight(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
   if((boardPosition[0][2] == 1) && (boardPosition[1][1] == 1) && (boardPosition[2][0] == 1))
    {
      player = 1;
      return gameOver = true;
    } 
   else if((boardPosition[0][2] == 2) && (boardPosition[1][1] == 2) && (boardPosition[2][0] == 2))
    {
      player = 0;
      return gameOver = true;
    } 
}







