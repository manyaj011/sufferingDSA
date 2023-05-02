#include <bits/stdc++.h>
using namespace std;
bool subarrwsumzero(int arr[], int n)
{
 for (int i = 0; i < n; i++)
 {
  /* code */
  int curr_sum = 0;
  for (int j = i; j < n; j++)
  {
   /* code */
   curr_sum+=arr[j];
   if (curr_sum  == 0)
    return true;
  }
 }
 return false;
}
//tc O(n^2)
// by hashing
bool myhash(int arr[] ,int n)
{
 unordered_set<int>h;
 int psum=0;
 for (int i = 0; i < n; i++)
 {
  /* code */
  psum+=arr[i];
  if(h.find(psum)!=h.end()) return true;
  if(psum==0) return true;
  else h.insert(psum);
 }
  return false;
}

int main()
{
 int arr[]={1,4,13,-3,-10,5};
 cout << subarrwsumzero(arr, 6)<<endl;
 cout << myhash(arr, 6);
 return 0;
}