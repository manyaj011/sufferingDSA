#include<bits/stdc++.h>
using namespace std;
int countOccurence(vector<int>v, int k)
{
 int n=v.size();
 sort(v.begin(), v.end());
 int finalcount = 0;
 for (int i = 0; i < n; i++)
 {
  int count = 1;

  while (i + 1 < n && v[i] == v[i + 1])
  {
   count++;
   i++;
  }
  if (count > n / k)
  {
   finalcount++;
  }
 }
 return finalcount;
}
int main()
{
int n;
cin>>n;
vector<int> v(n);
for (int i = 0; i < n; i++)
{
cin >> v[i];
}
int k;
cin>>k;
cout<<countOccurence(v,k);
return 0;
}
