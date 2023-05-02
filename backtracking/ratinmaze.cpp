#include <bits/stdc++.h>
using namespace std;
#define n 4

bool solvemazerec(int maze[n][n], int i, int j, int sol[n][n]);

void printsol(int sol[n][n])
{
 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < n; j++)
  {
   cout << " " << sol[i][j] << " ";
  }
  cout << endl;
 }
}

bool issafe(int maze[n][n], int i, int j)
{
 return (i >= 0 && i < n && j >= 0 && j < n && maze[i][j] == 1);
}

bool solvemaze(int maze[n][n])
{
 int sol[n][n] = {{0, 0, 0, 0},
                  {0, 0, 0, 0},
                  {0, 0, 0, 0},
                  {0, 0, 0, 0}};

 if (solvemazerec(maze, 0, 0, sol) == false)
  return false;
 else
 {
  printsol(sol);
  return true;
 }
}

bool solvemazerec(int maze[n][n], int i, int j, int sol[n][n])
{
 if (i == n - 1 && j == n - 1 && maze[i][j] == 1)
 {
  sol[i][j] = 1;
  return true;
 }
 if (issafe(maze, i, j) == true)
 {
  if (sol[i][j] == 1)
   return false;

  sol[i][j] = 1;

  if (solvemazerec(maze, i + 1, j, sol) == true)
   return true;
  if (solvemazerec(maze, i - 1, j, sol) == true)
   return true;
  if (solvemazerec(maze, i, j + 1, sol) == true)
   return true;
  if (solvemazerec(maze, i, j - 1, sol) == true)
   return true;

  sol[i][j] = 0;
  return false;
 }
 return false;
}
int main()
{
 int maze[n][n] = {{1, 0, 0, 0},
                   {1, 1, 0, 1},
                   {0, 1, 0, 0},
                   {1, 1, 1, 1}};
 solvemaze(maze);
 return 0;
}