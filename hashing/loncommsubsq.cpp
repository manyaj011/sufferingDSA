#include <bits/stdc++.h>
using namespace std;
int loncommsubsq(vector<int> v)
{
 int n = v.size();
 sort(v.begin(), v.end());
 int curr = 1, res = 1;
 for (int i = 1; i < n; i++)
 {
  /* code */
  if (v[i] - v[i - 1] == 1)
   curr++;
  else if (v[i] != v[i - 1])
  {
   res = max(res, curr);
   curr = 1;
  }
 }
 return max(res, curr);
}
int optapp(vector<int> v)
{
 int n = v.size();
 unordered_set<int> h(v.begin(), v.end());
 int res = 0;
 for (auto x : h) // x value h jo hash set m unki
 {
  if (h.find(x - 1) == h.end())
  {
   int curr = 1;
   while (h.find(x + curr) != h.end())
    curr++;
   res = max(res, curr);
  }
 }
 return res;
}
//TC:o(n) 2N LOOKUPS it may seem n^2 cse of while loop inside the foe loop but actualy is linear see concept in nb
int main()
{
 vector<int> v = {0, 1, 5, 5, 6, 7, 8};
 // cout << loncommsubsq(v);
 cout<<optapp(v);
 return 0;
}