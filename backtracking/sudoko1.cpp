#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's safe to place a number in a particular cell
bool isSafe(vector<vector<int>> &board, int row, int col, int num)
{
 // Check row and column constraints
 for (int i = 0; i < 9; ++i)
 {
  if (board[row][i] == num || board[i][col] == num)
  {
   return false;
  }
 }

 // Check 3x3 grid constraints
 int startRow = row - row % 3;
 int startCol = col - col % 3;
 for (int i = 0; i < 3; ++i)
 {
  for (int j = 0; j < 3; ++j)
  {
   if (board[startRow + i][startCol + j] == num)
   {
    return false;
   }
  }
 }

 return true; // Number can be placed in the cell
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(vector<vector<int>> &board)
{
 int row, col;

 // Find an empty cell
 bool isEmptyCell = false;
 for (row = 0; row < 9; ++row)
 {
  for (col = 0; col < 9; ++col)
  {
   if (board[row][col] == 0)
   {
    isEmptyCell = true;
    break;
   }
  }
  if (isEmptyCell)
  {
   break;
  }
 }

 // If no empty cell is found, the puzzle is solved
 if (!isEmptyCell)
 {
  return true;
 }

 // Try placing numbers from 1 to 9 in the empty cell
 for (int num = 1; num <= 9; ++num)
 {
  if (isSafe(board, row, col, num))
  {
   board[row][col] = num; // Place the number in the cell

   if (solveSudoku(board))
   {
    return true; // Puzzle is solved
   }

   board[row][col] = 0; // Undo the placement if it doesn't lead to a solution
  }
 }

 return false; // No solution exists
}

// Function to print the Sudoku board
void printSudoku(vector<vector<int>> &board)
{
 for (int i = 0; i < 9; ++i)
 {
  for (int j = 0; j < 9; ++j)
  {
   cout << board[i][j] << " ";
  }
  cout << endl;
 }
}

int main()
{
 // Create a Sudoku board
 vector<vector<int>> board = {
     {5, 3, 0, 0, 7, 0, 0, 0, 0},
     {6, 0, 0, 1, 9, 5, 0, 0, 0},
     {0, 9, 8, 0, 0, 0, 0, 6, 0},
     {8, 0, 0, 0, 6, 0, 0, 0, 3},
     {4, 0, 0, 8, 0, 3, 0, 0, 1},
     {7, 0, 0, 0, 2, 0, 0, 0, 6},
     {0, 6, 0, 0, 0, 0, 2, 8, 0},
     {0, 0, 0, 4, 1, 9, 0, 0, 5},
     {0, 0, 0, 0, 8, 0, 0, 7, 9}};

 if (solveSudoku(board))
 {
  cout << "Sudoku puzzle solved:\n";
  printSudoku(board);
 }
 else
 {
  cout << "No solution exists for the Sudoku puzzle.\n";
 }

 return 0;
}
