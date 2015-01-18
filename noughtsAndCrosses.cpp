#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector <vector <int> > & boardPosition);
void checkMove(vector <vector <int> > & boardPosition, unsigned int row, unsigned int column);

bool getPlayerMove(vector <vector <int> > & boardPosition);
bool getComputerMove(vector <vector <int> > & boardPosition);

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
  unsigned short int move;

  do
    {
      printBoard(boardPosition);
      getPlayerMove(boardPosition);

      checkBoardColumnOne(boardPosition,gameOver, player);
      checkBoardColumnTwo(boardPosition,gameOver, player);
      checkBoardColumnThree(boardPosition,gameOver, player);

      checkBoardRowOne(boardPosition,gameOver, player);
      checkBoardRowTwo(boardPosition,gameOver, player);
      checkBoardRowThree(boardPosition,gameOver, player);

      checkBoardDiagonalLeft(boardPosition,gameOver, player);
      checkBoardDiagonalRight(boardPosition,gameOver, player);
     
      getComputerMove(boardPosition);

      checkBoardColumnOne(boardPosition,gameOver, player);
      checkBoardColumnTwo(boardPosition,gameOver, player);
      checkBoardColumnThree(boardPosition,gameOver, player);

      checkBoardRowOne(boardPosition,gameOver, player);
      checkBoardRowTwo(boardPosition,gameOver, player);
      checkBoardRowThree(boardPosition,gameOver, player);

      checkBoardDiagonalLeft(boardPosition,gameOver, player);
      checkBoardDiagonalRight(boardPosition,gameOver, player);
    }
  while(gameOver == false);

  if ((gameOver == true) && (player == 1)) 
    {
      cout << "Game over! You won!" << endl;
    }
  else if ((gameOver == true) && (player == 0))
    {
      cout << "Hahaha! I won!" << endl;
    }
  return 0;    
}

void printBoard(vector <vector <int> > & boardPosition)
{
  cout << "\n";
  cout << boardPosition[0][0];
  cout << boardPosition[0][1];
  cout << boardPosition[0][2];
  cout << "\n";
  cout << boardPosition[1][0];
  cout << boardPosition[1][1];
  cout << boardPosition[1][2];
  cout <<"\n";
  cout << boardPosition[2][0];
  cout << boardPosition[2][1];
  cout << boardPosition[2][2];
  cout << "\n";
}

void checkMove(vector <vector <int> > & boardPosition, unsigned int row, unsigned int column)
{
  if(boardPosition[row][column] == 2)
    {
      cout << "There is already an opponents piece here!" << endl;
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

  boardPosition[row][column] = 1;
  checkMove(boardPosition, row, column);
}

bool getComputerMove(vector <vector <int> > & boardPosition)
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

bool checkBoardColumnOne(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
  if((boardPosition[0][0] == 1) && (boardPosition[1][0] == 1) && (boardPosition[2][0] == 1 ))
    {
      return gameOver = true;
      player = 1;
    }     
  else if((boardPosition[0][0] == 2) && (boardPosition[1][0] == 2) && (boardPosition[2][0] == 2 ))
    {
      return gameOver = true;
      player = 0;
    } 	 
}


bool checkBoardColumnTwo(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
  if((boardPosition[0][1] == 1) && (boardPosition[1][1] == 1) && (boardPosition[2][1] == 1))
    {
      return gameOver = true;
      player = 1;
    }
  else if((boardPosition[0][1] == 2) && (boardPosition[1][1] == 2) && (boardPosition[2][1] == 2))
    {
      return gameOver = true;
      player = 0;
    }
}

bool checkBoardColumnThree(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
  if((boardPosition[0][2] == 1) && (boardPosition[1][2] == 1) && (boardPosition[2][2] == 1))
    {
      return gameOver = true;
      player = 1;
    }
  else if((boardPosition[0][2] == 2) && (boardPosition[1][2] == 2) && (boardPosition[2][2] == 2))
    {
      return gameOver = true;
      player = 0;
    }
}

bool checkBoardRowOne(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
  if((boardPosition[0][0] == 1) && (boardPosition[0][1] == 1) && (boardPosition[0][2] == 1))
    {
      return gameOver = true;
      player = 1;
    } 
     else if((boardPosition[0][0] == 2) && (boardPosition[0][1] == 2) && (boardPosition[0][2] == 2))
    {
      return gameOver = true;
      player = 0;
    }
}

bool checkBoardRowTwo(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
   if((boardPosition[1][0] == 1) && (boardPosition[1][1] == 1) && (boardPosition[1][2] == 1))
    {
      return gameOver = true;
      player = 1;
    } 
   if((boardPosition[1][0] == 2) && (boardPosition[1][1] == 2) && (boardPosition[1][2] == 2))
    {
      return gameOver = true;
      player = 0;
    }
}

bool checkBoardRowThree(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
   if((boardPosition[2][0] == 1) && (boardPosition[2][1] == 1) && (boardPosition[2][2] == 1))
    {
      return gameOver = true;
      player = 1;
    }
   else if((boardPosition[2][0] == 2) && (boardPosition[2][1] == 2) && (boardPosition[2][2] == 2))
    {
      return gameOver = true;
      player = 0;
    }
}

bool checkBoardDiagonalLeft(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
   if((boardPosition[0][0] == 1) && (boardPosition[1][1] == 1) && (boardPosition[2][2] == 1))
    {
      return gameOver = true;
      player = 1;
    } 
   else if((boardPosition[0][0] == 2) && (boardPosition[1][1] == 2) && (boardPosition[2][2] == 2))
    {
      return gameOver = true;
      player = 0;
    }
}

bool checkBoardDiagonalRight(vector <vector <int> > & boardPosition, bool & gameOver, bool & player)
{
   if((boardPosition[0][2] == 1) && (boardPosition[1][1] == 1) && (boardPosition[2][0] == 1))
    {
      return gameOver = true;
      player = 1;
    } 
   else if((boardPosition[0][2] == 2) && (boardPosition[1][1] == 2) && (boardPosition[2][0] == 2))
    {
      return gameOver = true;
      player = 0;
    } 
}


