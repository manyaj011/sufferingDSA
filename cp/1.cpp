#include <iostream>
using namespace std;
int display(int n, string s)
{
 bool visited = true;
 ;
 for (int i = 0; i < n; i++)
 {
  if (s[i] != '0')
  {
   visited = false;
  }
 }
 if (visited = true)
  return n;
 else
 {
  int count = 0;
  for (int i = 0; i < n; i++)
  {
   if (i > 0 && i < n - 1)
   {
    if (s[i] == '0' && s[i - 1] == '+' && s[i + 1] == '-' || s[i] == '0' && s[i - 1] == '-' && s[i + 1] == '+')
    {
     count++;
    }
   }
  }
  return count;
 }
 return 0;
}
int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  int n;
  cin >> n;
  string s;
  cin >> s;
  cout << display(n, s) << endl;
 }
 return 0;
}
