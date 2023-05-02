#include <bits/stdc++.h>
using namespace std;
int count1(vector<int> v, int low, int high)
{
  int n = v.size();
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (1 < v[mid])
    {
      high = mid - 1;
    }
    if (1 > v[mid])
    {
      low = mid + 1;
    }
    else
    {
      if (v[mid] != v[mid - 1] || mid == 0)
      {
        return (n - mid);
      }
      else
        high = mid - 1;
    }
  }
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
  int low = 0;
  int high = n - 1;
  cout << count1(v, low, high);
  return 0;
}