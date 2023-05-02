#include <bits/stdc++.h>
using namespace std;
void morethannbyk(vector<int> v, int k)
{
 int n = v.size();
 // int q = n / k;
 sort(v.begin(), v.end());
 int i = 1, count = 1;
 while (i < n)
 {
  while (i < n && v[i] == v[i - 1])
  {
   count++;
   i++;
  }
  if (count > n / k)
   cout << v[i - 1] << " ";
  count = 1;
  i++;
 }
}
// tc o(nlogn)
void optapp(vector<int> v, int k)
{
 int n = v.size();
 unordered_map<int, int> m;
 for (int i = 0; i < n; i++)
 {
  m[v[i]]++;
 }
 for (auto e : m)
 {
  if (e.second > n / k)
   cout << e.first << " ";
 }
}
//tc o(n)
//as o(n)
int main()
{
 vector<int> v = {10, 10, 20, 20, 20, 10, 10};
 morethannbyk(v, 3);
 optapp(v,3);
 return 0;
}