#include <bits/stdc++.h>
using namespace std;
int count_occur(vector<int> v, int low, int high, int target, int count)
{
 int n = v.size();
 // int count=0;
 while (low <= high)
 {
  int mid = (low + high) / 2;
  if (target > v[mid])
   return count_occur(v, mid + 1, high, target,  count);
  else if (target < v[mid])
   return count_occur(v, low, mid - 1, target, count);
  else
  {
   if(v[mid]!=v[mid-1] || mid==0)
    return count_occur(v, mid+1, high, target, count++);
   else if(v[mid])
   return count_occur(v, mid + 1, high, target, count++);
  }
 }
 return count;
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
 cout << "enter the target element:";
 int target;
 cin >> target;
 cout << count_occur(v, 0, n - 1, target, 0);

 return 0;
}