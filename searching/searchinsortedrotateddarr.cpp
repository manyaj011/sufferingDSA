#include <bits/stdc++.h>
using namespace std;
int binarysearch(vector<int> v, int low, int high, int x)
{
 if (low > high)
  return -1;
 int mid = (low + high) / 2;
 if (v[mid] == x)
  return mid;
 else if (v[mid] > x)
  return binarysearch(v, mid + 1, high, x);
 else if (v[mid] < x)
  return binarysearch(v, low, mid - 1, x);
}
int rotatedarray(vector<int> v, int low, int high, int x)
{
 int n = v.size();
 while (low <= high)
 {
  int z = -1;
  int mid = (low + high) / 2;
  if (v[mid] == x)
   return mid;
  else if (v[mid] > v[low])
  {
   z = binarysearch(v, low, mid - 1, x);
   if (z != -1)
    return z;
  }
  else if (z == -1)
  {
   int w = rotatedarray(v, mid + 1, high, x);
   if (w != -1)
    return w;
  }
 }
 return -1;
}

int search(vector<int> v, int x)
{
 int n = v.size();
 int low = 0;
 int high = n - 1;
 while (low <= high)
 {
  int mid = (low + high) / 2;
  if (v[mid] == x)
   return mid;
  // left half is sorted
  else if (v[mid] > v[low])
  {
   if (x >= v[low] && x < v[mid]) // element present in sorted part
   {
    high = mid - 1;
   }
   else // element not present in left sorted part
   {
    low = mid + 1;
   }
  }
  // right half is sorted
  else
  {
   if (x > v[mid] && x <= v[high])
   {
    low = mid + 1; // ele present in right sorted part
   }
   else
   {
    high = mid - 1; // ele not present in right sorted part
   }
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
 int x;
 cin >> x;
 int high = n - 1;
 int low = 0;
 cout << rotatedarray(v, low, high, x);
 return 0;
}