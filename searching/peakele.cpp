#include <bits/stdc++.h>
using namespace std;
int peakele(vector<int> v)
{
 int n = v.size();
 int low = 0;
 int high = n - 1;
 while (low <= high)
 {
  int mid = (low + high) / 2;
  if ((mid == 0 || v[mid] > v[mid - 1]) && (mid == n - 1 || v[mid] > v[mid + 1])) // sbse pehle mid check kia h ki khi vo peak element mid hi to nhi h
  {
   return v[mid];
  }
  if (mid > 0 && v[mid - 1] >= v[mid]) // yhaan ye dekha h ki agr mid-1 wala ele bdaa h to mtlb pkka ek peak ele left side m to hoga hi
   high = mid - 1;                     // left ab ek independent array bn gai h aur right side ka dhyaan rkhne ki zaroorat nhi h kunki vo to already dekh hi liya h
  else
   low = mid + 1; // agr mid-1 bda nhi h to mid+1 hoga kunki mid ki bhui ocnd pehle check krli to ab right ek independent array bn gai
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
 cout << peakele(v);
 return 0;
}
// TC=O(logn)
// AS=O(1)