#include <bits/stdc++.h>
using namespace std;
int binarysearch(vector<int> v, int x, int n)
{
 int low = 0;
 int high = 1;
 while (high < n)
 {
  int mid = (low + high) / 2;
  if (v[mid] == x)
   return mid;
  else if(x>v[mid])
   high = high * 2;
 }
}
int main()
{
 int n1;
 cin >> n1;
 vector<int> v(n1);
 for (int i = 0; i < n1; i++)
 {
  cin >> v[i];
 }
 cout << "enter n:";
 int n;
 cin >> n;
 cout << "enter searching element";
 int x;
 cin >> x;
 cout << binarysearch(v, x, n);
 return 0;
}