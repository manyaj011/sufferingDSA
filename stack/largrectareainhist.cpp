#include <bits/stdc++.h>
using namespace std;
int areahist(vector<int> v)
{
 int res = 0;
 for (int i = 0; i < v.size(); i++)
 {
  /* code */
  int curr = v[i];

  for (int j = i - 1; j >= 0; j--)
  {
   /* code */
   if (v[j] >= v[i])
    curr += v[i];
   else
    break;
  }
  for (int j = i + 1; j < v.size(); j++)
  {
   /* code */
   if (v[j] >= v[i])
    curr += v[i];
   else
    break;
  }
  res = max(res, curr);
 }
 return res;
}
// tc o(n^2)
// sc o(1)

// this is the optimal approach
// this app includes finding the next and prev smallest in the array
vector<int> psm(vector<int> v)
{
 stack<int> s;
 s.push(0);
 vector<int> res;
 res.push_back(-1);
 for (int i = 0; i < v.size(); i++)
 {
  /* code */
  while (s.empty() == false && v[i] <= v[s.top()])
  {
   s.pop();
  }
  int span = s.empty() ? -1 : s.top();
  res.push_back(span);
  s.push(i);
 }
 return res;
}

vector<int> nsm(vector<int> v)
{
 stack<int> s;
 s.push(v.size() - 1);
 vector<int> res;
 res.push_back(-1);
 for (int i = v.size() - 2; i >= 0; i--)
 {
  /* code */
  while (s.empty() == false && v[i] <= v[s.top()])
  {
   s.pop();
  }
  int span = s.empty() ? -1 : i - s.top();
  res.push_back(span);
  s.push(i);
 }
 reverse(res.begin(), res.end());
 return res;
}
int betterapp(vector<int> v)
{
 vector<int> ps = psm(v);
 vector<int> ns = nsm(v);
 int res = 0;
 for (int i = 0; i < v.size(); i++)
 {
  /* code */
  int curr = v[i];
  curr += (i - ps[i] - 1) * v[i];
  curr += (ns[i] - i - 1) * v[i];
  res = max(res, curr);
 }
 return res;
}

// this is the best solution
int getmax(vector<int> v)
{
 stack<int> s;
 int res;
 int n = v.size();
 for (int i = 0; i < v.size(); i++)
 {
  /* code */
  while (s.empty() == false && v[s.top()] >= v[i])
  {
   int tp = s.pop();
   int curr = v[tp] * (s.empty() ? i : i - s.top() - 1);
   res = max(res, curr);
  }
  s.push(i);
 }
 while (!s.empty())
 {
  int tp = s.pop();
  int curr = v[tp] * (s.empty() ? n : n - s.top() - 1);
  res = max(res, curr);
 }
 return res;
}
int main()
{
 int n;
 cin >> n;
 vector<int> v(n);
 for (int i = 0; i < n; i++)
 {
  cin >> v[i];
 }
 cout << areahist(v);
 return 0;
}