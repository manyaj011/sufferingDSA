// #include <iostream>
// #include <chrono>
// #include <thread>

// void bouncing_ball_animation()
// {
//  const int screen_width = 80;
//  const int ball_radius = 5;
//  int ball_pos = 0;
//  bool ball_moving_right = true;

//  while (true)
//  {
//   // Update the ball position
//   if (ball_moving_right)
//   {
//    ball_pos++;
//    if (ball_pos + ball_radius >= screen_width)
//    {
//     ball_moving_right = false;
//    }
//   }
//   else
//   {
//    ball_pos--;
//    if (ball_pos - ball_radius <= 0)
//    {
//     ball_moving_right = true;
//    }
//   }

//   // Clear the screen
//   std::cout << "\033[2J";

//   // Draw the ball
//   for (int i = 0; i < screen_width; i++)
//   {
//    if (i == ball_pos)
//    {
//     std::cout << "O";
//    }
//    else
//    {
//     std::cout << " ";
//    }
//   }
//   std::cout << "\r" << std::flush;

//   // Wait for a short period of time
//   std::chrono::milliseconds timespan(50);
//   std::this_thread::sleep_for(timespan);
//  }
// }

// int main()
// {
//  bouncing_ball_animation();
//  return 0;
// }

// User function Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
 // Function to find list of all words possible by pressing given numbers.
 void solve(int digit[], int n, string output, int index, vector<string> &ans, string mapping[])
 {
  if (index >= n)
  {
   ans.push_back(output);
   return;
  }

  int number = digit[index];
  string value = mapping[number];

  for (int i = 0; i < value.length(); i++)
  {
   output.push_back(value[i]);
   solve(digit, n, output, index + 1, ans, mapping);
   output.pop_back();
  }
 }
 vector<string> possibleWords(int a[], int N)
 {
  vector<string> ans;
  if (N == 0)
   return ans;

  string output = "";
  int index = 0;

  string mapping[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  solve(a, N, output, index, ans, mapping);
  return ans;
 }
};
int main()
{
 int a[] = {2, 3};
 Solution obj;
 vector<string>res=obj.possibleWords(a, 2);
 for (int i = 0; i < res.size(); i++)
 {
  /* code */
  cout<<res[i]<<" ";
 }
 
 return 0;
}