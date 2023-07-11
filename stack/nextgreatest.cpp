#include <bits/stdc++.h>
using namespace std;
// this is the naive approach
void nextgreatest(vector<int> v)
{
 for (int i = 0; i < v.size(); i++)
 {
  /* code */
  int j;
  for (j = i + 1; j < v.size(); j++)
  {
   /* code */
   if (v[j] > v[i])
   {
    cout << v[j] << " ";
    break;
   }
  }
  if (j == v.size())
  {
   cout << -1 << " ";
  }
 }
}
// tc o(n^2)
// sc o(1)

// this is the optimised code
vector<int> nextgrt(vector<int> v)
{
 vector<int> res;
 stack<int> s;
 s.push(v.size() - 1);
 res.push_back(-1);
 for (int i = v.size() - 2; i >= 0; i--)
 {
  while (s.empty() == false && v[s.top()] <= v[i])
  {
   s.pop();
  }
  int span = s.empty() ? -1 : v[s.top()];
  res.push_back(span);
  s.push(i);
 }
 reverse(res.begin(), res.end());
 return res;
}
//tc: o(n)
//sc: o(n)
int main()
{
 int n;
 cin >> n;
 vector<int> v(n);
 for (int i = 0; i < n; i++)
 {
  cin >> v[i];
 }
 // nextgreatest(v);
 vector<int> vec = nextgrt(v);
 for (auto x : vec)
 {
  cout << x << " ";
 }
 return 0;
}