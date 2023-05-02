#include <bits/stdc++.h>
using namespace std;
int subarrwgivsum(int arr[], int n, int given_sum)
{
 unordered_set<int> h;
 int psum = 0;
 for (int i = 0; i < n; i++)
 {
  /* code */
  psum += arr[i];
  if (h.find(psum - given_sum) != h.end())
   return true;
  else
  {
   h.insert(psum);
  }
 }
 return false;
}
int main()
{
 int arr[] = {5, 8, 6, 13, 3, -1};
 cout << subarrwgivsum(arr, 6, 20);
 return 0;
}
// TC: O(n)
// AS: O(n)