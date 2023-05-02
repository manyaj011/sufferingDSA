#include <bits/stdc++.h>
using namespace std;

// as is o(n)
vector<int> selectionsort(vector<int> &v)
{
  int n = v.size();
  int temp[n];
  for (int i = 0; i < n; i++)
  {
    int minind = 0;
    for (int j = 1; j < n; j++)
    {
      if (v[j] < v[minind])
      {
        minind = j;
      }
      temp[i] = v[minind];
      v[minind] = INT_MAX;
    }
  }
  for (int i = 0; i < n; i++)
  {
    v[i] = temp[i];
  }
  return v;
}

// when as is o(1)
void selectionsortopt(vector<int> v)
{
  int n = v.size();
  for (int i = 0; i < n; i++)
  {
    int minind = i;
    for (int j = i + 1; j < n; j++)
    {
      if (v[j] < v[minind])
        minind = j;
    }
    swap(v[i], v[minind]);
  }
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
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
  // selectionsort(v);
  //  for (int i = 0; i < n; i++)
  //  {
  //   cout << v[i] << " "; // how to print whole array
  //  }
  selectionsortopt(v);

  return 0;
}