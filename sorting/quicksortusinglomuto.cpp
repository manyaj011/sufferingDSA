#include <bits/stdc++.h>
using namespace std;
int lomutopartition(vector<int> v, int l, int h)
{
 int i = l - 1;
 int pivot = v[h];
 for (int j = l; j < h; j++)
 {
  if (v[j] < pivot)
  {
   i++;
   swap(v[j], v[i]);
  }
 }
 swap(v[i + 1], v[h]);

 return (i + 1);
}
void quicksortusinglomuto(vector<int> v, int l, int h)
{

 if (l < h) // to check if there is only one element or if low crosses high index
 {
  int p = lomutopartition(v, l, h);
  quicksortusinglomuto(v, l, p - 1);
  quicksortusinglomuto(v, p + 1, h);
 }
}
void print(vector<int>v)
{
 for(int i=0;i<v.size();i++)
 {
  cout<<v[i]<<" ";
 }
}
int main()
{
 int n;
 cin >> n;
 vector<int> v(n);
 for (int i = 0; i < n; i++)
 {
  cin>> v[i];
 }
 quicksortusinglomuto(v, 0, n - 1);
 print(v);
 
 return 0;
}