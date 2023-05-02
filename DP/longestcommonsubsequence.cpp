#include <bits/stdc++.h>
using namespace std;
int memo[4][3] = {-1};
int lcs(string s1, string s2, int m, int n)
{
 if (memo[m][n] != -1)
  return memo[m][n];
 if (m == 0 || n == 0)
  return 0;
 else
 {
  if (s1[m - 1] == s2[n - 1])
  {
   memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1);
   cout << s1[m - 1]<<"->";
  }
  else
   memo[m][n] = max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
 }
 return memo[m][n];
}
int main()
{
 int m, n;
 cout << "enter size of m and n:";
 cin >> m >> n;
 string s1, s2;
 cout << "enter string s1 and s2:";
 cin >> s1 >> s2;
 cout << "the longest common subsequence is:" << lcs(s1, s2, m, n);
}