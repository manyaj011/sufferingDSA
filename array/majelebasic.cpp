#include <bits/stdc++.h>
using namespace std;
int majele(int arr[], int n)
{
  int res = 0, max_count = 1;
  for (int i = 0; i < n; i++)
  {
    int count = 1;
    for (int j = i+1; j < n; j++)
    {
      if (arr[i] == arr[j] && arr[i]!=INT_MIN && arr[j]!=INT_MIN)
      {
        count++;
        arr[j] = INT_MIN;
        if (count > max_count)
        {
          res=i;
        }
        max_count = max(count, max_count);
      }
    }
  }
  return res;
}
int main()
{
  int n;
  cout << "enter size of array:";
  cin >> n;
  int arr[n];
  cout << "enter elements of array:";

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << majele(arr, n);
}