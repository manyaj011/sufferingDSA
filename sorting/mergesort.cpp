#include <bits/stdc++.h>
using namespace std;
void mergesort(vector<int> v1, vector<int> v2)
{
 int n = v1.size();
 int m = v2.size();
 int i = 0, j = 0;
 while (i < n && j < m)
 {
  if (v1[i] <= v2[j])
  {
   cout << v1[i] << " ";
   i++;
  }
  else
  {
   cout << v2[j] << " ";
   j++;
  }
 }
 while (i < n)
 {
  cout << v1[i] << " ";
  i++;
 }
 while (j < m)
 {
  cout << v2[j] << " ";
  j++;
 }
}
int main()
{
 int n;
 cin >> n;
 vector<int> v1(n);
 for (int i = 0; i < n; i++)
 {
  cin >> v1[i];
 }
 int m;
 cin >> m;
 vector<int> v2;
 for (int i = 0; i < m; i++)
 {
  cin >> v2[i];
 }
 mergesort(v1,v2);
 return 0;
}