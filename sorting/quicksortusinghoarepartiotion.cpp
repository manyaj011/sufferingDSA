#include <bits/stdc++.h>
using namespace std;
int hoare_partition(vector<int> v, int l, int h)
{

 int pivot = v[l];
 int i = l - 1;
 int j = h + 1;
 while (true)
 {
  do
  {
   i++;
  } while (v[i] < pivot);

  do
  {
   j++;
  } while (v[j] > pivot);

  if (i >= j)
   return j; // ye return krta h pivot ke pehle wala index

  swap(v[i], v[j]);
 }
}
void quicksortusinghoarepartition(vector<int> v, int l, int h)
{
 while (l < h)
 {
  int p = hoare_partition(v, l, h);
  quicksortusinghoarepartition(v, l, p);
  quicksortusinghoarepartition(v, p + 1, h);
 }
}

void print(vector<int> v)
{
 for (int i = 0; i < v.size(); i++)
 {
  cout << v[i] << " ";
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

 quicksortusinghoarepartition(v, 0, n - 1);
 print(v);
 return 0;
}