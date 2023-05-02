#include <bits/stdc++.h>
using namespace std;
int binsubarrwsamesize(vector<int> v1, vector<int> v2)
{
 int n = v1.size();
 int res = 0;
 for (int i = 0; i < n; i++)
 {
  /* code */
  int sum1 = 0, sum2 = 0;
  for (int j = i; j < n; j++)
  {
   /* code */
   sum1 += v1[j];
   sum2 += v2[j];
   if (sum1 == sum2)
   {
    res = max(res, j - i + 1);
   }
  }
 }
 return res;
}
int lonsubarrwsumzero(vector<int> temp, int s)
{
 int n = temp.size();
 unordered_map<int, int> m;
 int res = 0, psum = 0;
 for (int i = 0; i < n; i++)
 {
  /* code */
  psum += temp[i];
  if (psum == s)
   res = i + 1;
  if (m.find(psum) == m.end())
   m.insert({psum, i});
  if (m.find(psum - s) != m.end())
   res = max(res, i - m[psum - s]);
 }
 return res;
}
int optapp(vector<int> v1, vector<int> v2)
{
 int n = v1.size();
 vector<int> temp(n);
 for (int i = 0; i < n; i++)
 {
  /* code */
  temp.push_back(v1[i] - v2[i]);
 }
 int ans = lonsubarrwsumzero(temp, 0);
 return ans;
}

int main()
{
 vector<int> v1 = {0, 1, 0, 1, 1, 1, 1};
 vector<int> v2 = {1, 1, 1, 1, 1, 0, 1};
 // cout << binsubarrwsamesize(v1, v2);
 cout << optapp(v1, v2);
}