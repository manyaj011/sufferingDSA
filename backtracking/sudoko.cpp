#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define n 9

void print(int board[n][n])
{
 for (int i = 0; i < 9; i++)
 {
  for (int j = 0; j < 9; j++)
  {
   cout << board[i][j] << " ";
  }
  cout << endl;
 }
}

bool isvalid(int k, int i, int j, int board[n][n])
{
 for (int m = 0; m < 9; m++)
 {
  if (board[m][j] == k)
  {
   return false;
  }
 }
 for (int z = 0; z < 9; z++)
 {
  if (board[i][z] == k)
  {
   return false;
  }
 }
 for (int z = 0; z < 9; z++)
 {
  if (board[3 * (i / 3) + z / 3][3 * (j / 3) + z % 3] == k)
  {
   return false;
  }
 }
 return true;
}

bool isSudokuSolved(int board[n][n])
{
 for (int i = 0; i < 9; i++)
 {
  for (int j = 0; j < 9; j++)
  {
   if (board[i][j] == 0)
   {
    return false;
   }
  }
 }
 return true;
}

void sudoku(int board[n][n])
{
 if (isSudokuSolved(board))
 {
  print(board);
  return;
 }

 for (int i = 0; i < 9; i++)
 {
  for (int j = 0; j < 9; j++)
  {
   if (board[i][j] == 0)
   {
    for (int k = 1; k <= 9; k++)
    {
     if (isvalid(k, i, j, board))
     {
      board[i][j] = k;
      sudoku(board);
      board[i][j] = 0;
     }
    }
    return;
   }
  }
 }
}

int main()
{
 int board[9][9] = {
     {3, 0, 6, 5, 0, 8, 4, 0, 0},
     {5, 2, 0, 0, 0, 0, 0, 0, 0},
     {0, 8, 7, 0, 0, 0, 0, 3, 1},
     {0, 0, 3, 0, 1, 0, 0, 8, 0},
     {9, 0, 0, 8, 6, 3, 0, 0, 5},
     {0, 5, 0, 0, 9, 0, 6, 0, 0},
     {1, 3, 0, 0, 0, 0, 2, 5, 0},
     {0, 0, 0, 0, 0, 0, 0, 7, 4},
     {0, 0, 5, 2, 0, 6, 3, 0, 0}};

 sudoku(board);

 return 0;
}
