#include <bits/stdc++.h>
using namespace std;
int longsubarrwgivsum(int arr[], int n, int given_sum)
{
  unordered_map<int, int> m;
  int psum = 0;
  int res = 0;
  for (int i = 0; i < n; i++)
  {
    /* code */ 
    psum += arr[i];
    if (psum == given_sum)
      res = i + 1;
    if (m.find(psum) == m.end())
      m.insert({psum, i});
    if (m.find(psum - given_sum) != m.end())
      res = max(res, i - m[psum - given_sum]);
  }
  return res;
}
int main()
{
  int arr[] = {8, 3, 1, 5, -6, 6, 2, 2};
  cout << longsubarrwgivsum(arr, 8, 4);
  return 0;
}