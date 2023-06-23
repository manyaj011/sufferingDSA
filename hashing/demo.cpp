#include <bits/stdc++.h>
using namespace std;

int main()
{
  // your code goes here
  
    int n, b;
    cin >> n >> b;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
      s.insert(a[i]);
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
      int z = ~(b ^ a[i]);
      cout<<z;
      if (s.find(z) != s.end())
      {
        c++;
        break;
      }
    }
    if (c > 0)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  return 0;
}