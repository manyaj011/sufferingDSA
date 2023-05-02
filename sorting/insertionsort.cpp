#include <bits/stdc++.h>
using namespace std;
void insertionsort(vector<int> v)
{
 int n = v.size();
 for (int i = 1; i < n; i++)
 {
  int j = i - 1;
  int key = v[i];
  while (j >= 0 && key < v[j])
  {
   // swap(key,v[j]);why swapping is wrong
   v[j + 1] = v[j];
   j--;
  }
  v[j + 1] = key;
 }
 for (int i = 0; i < n; i++)
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
 insertionsort(v);
 return 0;
}