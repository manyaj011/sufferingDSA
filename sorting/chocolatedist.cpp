#include <bits/stdc++.h>
using namespace std;
int chocolatedist(vector<int> v, int m)
{
 sort(v.begin(), v.end()); // o(nlogn)
 int res = v[m - 1] - v[0];
 for (int i = 0; i + m - 1 < v.size(); i++)
 {
  res = min(res, v[m + i - 1] - v[i]);
 } // o(n)
 return res;
}
// so overall tc is o(nlogn)
int main()
{
 int n;
 cin >> n;
 vector<int> v(n);
 for (int i = 0; i < n; i++)
 {
  cin >> v[i];
 }
 int m;
 cout << "enter no of packets to be chosen:";
 cin >> m;
 cout << chocolatedist(v, m);
 return 0;
}