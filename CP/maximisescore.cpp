#include <bits/stdc++.h>
using namespace std;

int main()
{
 // your code goes here
 int t;
 cin >> t;
 while (t--)
 {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
   cin >> arr[i];
  }
  int res = INT_MAX;
  int hig = INT_MAX;
  for (int i = 0; i < n - 1; i++)
  {
   hig = max(abs(arr[i] - arr[i - 1]), abs(arr[i] - arr[i + 1]));
   if (res > hig)
   {
    res = hig;
   }
  }
  res = min(res, min(abs(arr[0] - arr[1]), abs(arr[n - 1] - arr[n - 2])));
  cout << res << endl;
 }
 return 0;
}
