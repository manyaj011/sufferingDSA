#include <bits/stdc++.h>
using namespace std;
bool issafe(string s, int l, int i, int r)
{
 if ((s[l - 1] == 'a' || s[l - 1] == 'A') && (s[i] == 'b' || s[i] == 'B'))
  return false;
 if (r = l + 1 && (s[i] == 'a' || s[i] == 'A') && (s[l] == 'b' || s[l] == 'B'))
  return false;
 return true;
}
void permute(string s, int l, int r)
{
 if (l == r)
 {
  cout << s << " ";
  return;
 }
 for (int i = l; i <= r; l++)
 {
  if (issafe(s, l, i, r))
  {
   swap(s[l], s[i]);
   permute(s, l+1, r);
   swap(s[l], s[i]);
  }
 }
}
int main()
{
 string s;
 cin >> s;
 permute(s,0,s.length()-1);
}