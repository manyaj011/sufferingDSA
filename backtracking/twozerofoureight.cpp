#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> // For Windows

using namespace std;

const int SIZE = 4;
int board[SIZE][SIZE];

// Function to initialize the game board
void initializeBoard()
{
 for (int i = 0; i < SIZE; i++)
 {
  for (int j = 0; j < SIZE; j++)
  {
   board[i][j] = 0;
  }
 }
}

// Function to display the game board
void displayBoard()
{
 for (int i = 0; i < SIZE; i++)
 {
  for (int j = 0; j < SIZE; j++)
  {
   cout << board[i][j] << "\t";
  }
  cout << endl;
 }
 cout << endl;
}

// Function to generate a random number (2 or 4)
int generateRandomNumber()
{
 int randomNumber = (rand() % 2 + 1) * 2;
 return randomNumber;
}

// Function to add a new random tile to the board
void addRandomTile()
{
 int emptyCells = 0;
 for (int i = 0; i < SIZE; i++)
 {
  for (int j = 0; j < SIZE; j++)
  {
   if (board[i][j] == 0)
   {
    emptyCells++;
   }
  }
 }

 if (emptyCells == 0)
 {
  return;
 }

 int randomCell = rand() % emptyCells + 1;

 emptyCells = 0;
 for (int i = 0; i < SIZE; i++)
 {
  for (int j = 0; j < SIZE; j++)
  {
   if (board[i][j] == 0)
   {
    emptyCells++;
    if (emptyCells == randomCell)
    {
     board[i][j] = generateRandomNumber();
     return;
    }
   }
  }
 }
}

// Function to check if the game is over
bool isGameOver()
{
 // Check for any empty cells
 for (int i = 0; i < SIZE; i++)
 {
  for (int j = 0; j < SIZE; j++)
  {
   if (board[i][j] == 0)
   {
    return false;
   }
  }
 }

 // Check for any possible merges horizontally
 for (int i = 0; i < SIZE; i++)
 {
  for (int j = 0; j < SIZE - 1; j++)
  {
   if (board[i][j] == board[i][j + 1])
   {
    return false;
   }
  }
 }

 // Check for any possible merges vertically
 for (int j = 0; j < SIZE; j++)
 {
  for (int i = 0; i < SIZE - 1; i++)
  {
   if (board[i][j] == board[i + 1][j])
   {
    return false;
   }
  }
 }

 return true;
}

// Function to handle the player's move
void makeMove(char move)
{
 bool isMoved = false;
 bool canMerge[SIZE][SIZE] = {};

 // Initialize canMerge array
 for (int i = 0; i < SIZE; i++)
 {
  for (int j = 0; j < SIZE; j++)
  {
   canMerge[i][j] = true;
  }
 }

 // Move tiles left
 if (move == 'a')
 {
  for (int i = 0; i < SIZE; i++)
  {
   for (int j = 1; j < SIZE; j++)
   {
    if (board[i][j] != 0)
    {
     int k = j;
     while (k > 0 && board[i][k - 1] == 0)
     {
      board[i][k - 1] = board[i][k];
      board[i][k] = 0;
      k--;
      isMoved = true;
     }

     if (k > 0 && board[i][k - 1] == board[i][k] && canMerge[i][k - 1])
     {
      board[i][k - 1] *= 2;
      board[i][k] = 0;
      canMerge[i][k - 1] = false;
      isMoved = true;
     }
    }
   }
  }
 }

 // Move tiles right
 if (move == 'd')
 {
  for (int i = 0; i < SIZE; i++)
  {
   for (int j = SIZE - 2; j >= 0; j--)
   {
    if (board[i][j] != 0)
    {
     int k = j;
     while (k < SIZE - 1 && board[i][k + 1] == 0)
     {
      board[i][k + 1] = board[i][k];
      board[i][k] = 0;
      k++;
      isMoved = true;
     }

     if (k < SIZE - 1 && board[i][k + 1] == board[i][k] && canMerge[i][k + 1])
     {
      board[i][k + 1] *= 2;
      board[i][k] = 0;
      canMerge[i][k + 1] = false;
      isMoved = true;
     }
    }
   }
  }
 }

 // Move tiles up
 if (move == 'w')
 {
  for (int j = 0; j < SIZE; j++)
  {
   for (int i = 1; i < SIZE; i++)
   {
    if (board[i][j] != 0)
    {
     int k = i;
     while (k > 0 && board[k - 1][j] == 0)
     {
      board[k - 1][j] = board[k][j];
      board[k][j] = 0;
      k--;
      isMoved = true;
     }

     if (k > 0 && board[k - 1][j] == board[k][j] && canMerge[k - 1][j])
     {
      board[k - 1][j] *= 2;
      board[k][j] = 0;
      canMerge[k - 1][j] = false;
      isMoved = true;
     }
    }
   }
  }
 }

 // Move tiles down
 if (move == 's')
 {
  for (int j = 0; j < SIZE; j++)
  {
   for (int i = SIZE - 2; i >= 0; i--)
   {
    if (board[i][j] != 0)
    {
     int k = i;
     while (k < SIZE - 1 && board[k + 1][j] == 0)
     {
      board[k + 1][j] = board[k][j];
      board[k][j] = 0;
      k++;
      isMoved = true;
     }

     if (k < SIZE - 1 && board[k + 1][j] == board[k][j] && canMerge[k + 1][j])
     {
      board[k + 1][j] *= 2;
      board[k][j] = 0;
      canMerge[k + 1][j] = false;
      isMoved = true;
     }
    }
   }
  }
 }

 // Add a new random tile if any move is made
 if (isMoved)
 {
  addRandomTile();
 }
}

int main()
{
 srand(time(NULL));

 initializeBoard();
 addRandomTile();
 addRandomTile();
 displayBoard();

 while (!isGameOver())
 {
  char move;
  cout << "Enter your move (w/a/s/d): ";
  move = _getch(); // For Windows
  cout << endl;

  makeMove(move);
  displayBoard();
 }

 cout << "Game over!" << endl;

 return 0;
}