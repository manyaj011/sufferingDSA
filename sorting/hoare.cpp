// when pivot is first element and prtioning acc to pivot

#include <bits/stdc++.h>
using namespace std;
int hoare(vector<int> v, int l, int h)
{
 int i = l - 1;
 int j = h + 1;
 int pivot = v[l];
 while (true)
 {
  do
  {
   i++;
  } while (v[i] < pivot); // for left window to be smaller this loop runs till elemnts are smaleer than pivot

  do
  {
   j--;
  } while (v[j] > pivot); // for right eindow to be graeter thid loo pruns tillvright elemnts are greater than pivot

  if (i >= j)
  {
   for (int i = 0; i < v.size(); i++)
   {
    cout << v[i] << " ";
   }
   cout << endl;
   return j;
  }
  swap(v[i], v[j]); // when we get a greater element than pivot in the and a smaller elemnt in the right window we swap both of them
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
 cout << "the final pos of j is-" << hoare(v, 0, n - 1);
 return 0;
}

#include <iostream>
using namespace std;
int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  int x, y;
  cin >> x >> y;
  if (x * y <= 500 && x <= 8)
   cout << "yes" << endl;
  else
   cout << "no" << endl;
 }
}

#include <iostream>
using namespace std;

int main()
{
 int t;
 cin >> t;
 while (t--)
 {
  int temp;
  cin >> temp;
  if (temp > 24)
   cout << "yes" << endl;
  else
   cout << "no" << endl;
 }
 return 0;
}
