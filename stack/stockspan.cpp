#include <bits/stdc++.h>
using namespace std;
vector<int> stocks(vector<int> v)
{
 int n = v.size();
 vector<int> s;
 for (int i = 0; i < n; i++)
 {
  int res = 1;
  for (int j = i - 1; j >= 0 && v[j] <= v[i]; j--)
  {
   // if (j > 0 && v[j - 1] < v[i])
   // {
   res++;
   // }
   // else
   // {
   //  break;
   // }
  }
  s.push_back(res);
 }
 return s;
} // what is wrong
// TC : O(n^2)

// this is the optimal approach

void printstock(vector<int> v)
{
 stack<int> s;
 s.push(0);
 cout << 1 << " ";
 for (int i = 1; i < v.size(); i++)
 {
  /* code */
  while (s.empty() == false && v[s.top()] <= v[i])
  {
   s.pop();
  }
  int span = s.empty() ? i + 1 : s.top() - i;
  cout << span << " ";
  s.push(i);
 }
}
//TC: O(n)
//AS: O(n)
int main()
{
 int n;
 cin >> n;
 vector<int> v(n);

 for (int i = 0; i < n; i++)
 {
  cin >> v[i];
 }
 vector<int> st = stocks(v);
 for (auto x : st)
 {
  cout << st[x] << " ";
 }
}
