#include <bits/stdc++.h>
using namespace std;
void bubblesort(vector<int> v)
{
 int n = v.size();
 bool swapped=false;
 for (int i = 0; i < n - 1; i++)
 {
  for (int j = 0; j < n - i - 1; j++)
  {
   if (v[j] > v[j + 1])
   {
    swap(v[j], v[j + 1]);
    swapped=true;
   }
  }
  if(swapped==false) break;
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
 // vector<int>z=bubblesort(v);
 // for(auto i: z)
 // {
 //  cout<<z[i]<<" ";
 // }
 bubblesort(v);
 return 0;
}