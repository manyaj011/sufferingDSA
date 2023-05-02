#include <bits/stdc++.h>
using namespace std;
int longsubarrweqzao(int arr[], int n)
{
 for (int i = 0; i < n; i++)
 {
  /* code */
  if (arr[i] == 0)
   arr[i] = -1;
 }
}
int longestcommsub(int arr[], int n, int s)
{
 int psum = 0;
 int res = 0;
 unordered_map<int, int> m;
 for (int i = 0; i < n; i++)
 {
  /* code */
  psum += arr[i];
  if (psum == s)
   res = i + 1;
  if (m.find(psum) == m.end())
   m.insert({psum, i});
  if (m.find(psum - s) != m.end())
   res = max(res, i - m[psum - s]);
 }
 return res;
}
int main()
{
 int arr[] = {1, 1, 1, 0, 1, 0};
 cout << longsubarrweqzao(arr, 6);
 return 0;
}