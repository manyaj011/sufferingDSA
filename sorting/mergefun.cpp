#include <bits/stdc++.h>
using namespace std;
void mergearr(vector<int> v, vector<int> left, vector<int> right)
{
 int m = left.size();
 int n = right.size();
 int i = 0, j = 0;
 while (i < m && j < n)
 {
  if (left[i] <= right[j])
  {
   v[i] = left[i];
   i++;
  }
  else
  {
   v[i] = right[i];
   j++;
  }
 }
 while (i < m)
 {
  v[i] = left[i];
  i++;
 }
 while (j < n)
 {
  v[i] = right[j];
  j++;
  i++;
 }
 for (int i = 0; i < n; i++)
 {
  cout << v[i] << " ";
 }
}
void mergefun(vector<int> v, int low, int mid, int high)
{
 int n = v.size();
 int n1 = mid - low + 1, n2 = high - mid;
 vector<int> left(n1);
 vector<int> right(n2);
 for (int i = 0; i < n1; i++)
 {
  left.push_back(v[i]);
 }
 for (int j = 0; j < n2; j++)
 {
  right.push_back(v[mid + j + 1]);
 }
 mergearr(v,left, right);
 
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
 int low, mid, high;
 cin >> low >> mid >> high;
 mergefun(v, low, mid, high);
 return 0;
}