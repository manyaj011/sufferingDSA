#include <bits/stdc++.h>
using namespace std;
int firstoccur(vector<int> &arr, int n, int k)
{
 int l = 0;
 int h = n - 1;
 int first = -1; // intitaise with -1
 while (l <= h)
 {
  int mid = (l + h) / 2;
  if (arr[mid] == k)
  {
   // if(mid == 0 || arr[mid] != arr[mid-1])
   first = mid;
   h = mid - 1; // this is the optimal way
   // else
   //     h = mid -1;
  }
  else if (arr[mid] > k)
   h = mid - 1;
  else
   l = mid + 1;
 }
 return first;
}
int lastoccur(vector<int> &arr, int n, int k)
{
 int last = -1;
 int l = 0;
 int h = n - 1;
 while (l <= h)
 {
  int mid = (l + h) / 2;
  if (arr[mid] == k)
  {
   // if(arr[mid] != arr[mid+1] || mid == n-1)
   last = mid;
   l = mid + 1;
   // else
   //     l = mid + 1;
  }
  else if (arr[mid] < k)
  {
   l = mid + 1;
  }
  else
  {
   h = mid - 1;
  }
 }
 return last;
}
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
 // Write your code here
 pair<int, int> p;
 p.first = firstoccur(arr, n, k);
 p.second = lastoccur(arr, n, k);
 return p;
}
int main()
{

 vector<int> arr = {
     0,
     0,
     1,
     1,
     2,
     2,
     2,
     2,
 };
 pair<int, int> k = firstAndLastPosition(arr, 8, 2);
 cout << k.first << " " << k.second;
}