#include <bits/stdc++.h>
using namespace std;
void fun(string u, int n)
{
 for (int i = 0; i < u.length(); i++)
 {
  if (u[i] == u[i + 1] && u[i + 1] == u[i + 2])
  {
   u.erase(u.begin() + i);
   u.erase(u.begin() + i + 1);
   
  }
  else
   continue;
 }
 for (int i = 0; i < u.length(); i++)
 {
  if (u[i] == u[i + 1] && u[i + 1] == u[i + 2])
   fun(u, u.length());
  else
   i++;
 }
 cout << u << endl;
}
int main()
{
 //your code goes here
 // int t;
 // cin >> t;
 // while (t--)
 // {
  int n;
  cin >> n;
  string u;
  cin >> u;
  fun(u, n);
 // }
 return 0;
}