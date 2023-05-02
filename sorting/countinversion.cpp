#include <bits/stdc++.h>
using namespace std;
int count_and_merge(vector<int> v, int l, int m, int r)
{
 int n1 = m - l + 1;
 int n2 = r - m;
 vector<int> left(n1);
 vector<int> right(n2);
 for (int i = 0; i < n1; i++)
 {
  left[i] = v[l + i];
 }
 for (int i = 0; i < n2; i++)
 {
  right[i] = v[m + i + 1];
 } // ye left array and right array m daala to vo already sorted tha left aur right???
 int res = 0;
 int i = 0, j = 0, k = l;
 while (i < n1 && j < n2)
 {
  if (left[i] < right[j])
  {
   v[k] = left[i];
   i++;
   k++;
  }
  else
  {
   v[k] = right[j];
   res += n1 - i;
   j++;
   k++;
  }
 }
 while(i<n1) {v[k]=left[i];i++;k++;}
 while(j<n2) {v[k]=right[j];j++;k++;}
 return res;
}
int count_inversion(vector<int> v, int l, int r)
{
 int res = 0;
 if (l < r)
 {
  int m = (l + (r - l)) / 2;
  res += count_inversion(v, l, m);
  res += count_inversion(v, m + 1, r);
  res += count_and_merge(v, l, m, r);
 }
 return res;
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
 cout<<count_inversion(v,0,n-1);
 return 0;
}