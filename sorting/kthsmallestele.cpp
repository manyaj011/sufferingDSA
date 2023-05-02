#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> v, int l, int h)
{
 int pivot=v[h];
 int i = l - 1;

 for (int j = l; j <= h -1; j++)
 {
  if (v[j] < pivot)
  {
   i++;
   swap(v[i], v[j]);
  }
 }
 swap(v[i + 1], v[h]);
 return i + 1;
}

int kthsmallest(vector<int> v, int k, int l, int h)
{
 while (l <= h)
 {
  int p = partition(v, l, h);
  if (p == k - 1)
   return p;
  else if (p > k - 1)
   return h = p - 1;
  else if (p < k - 1)
   return l = p + 1;
 }
 return -1;
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
 cout<<"enter the index of k:";
 int k;
 cin>>k;
 cout<<kthsmallest(v,k,0,n-1);
 return 0;
}