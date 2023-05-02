#include<bits/stdc++.h>
using namespace std;
int mindiff(vector<int>v)
{
 int res=INT_MAX;
 sort(v.begin(), v.end()); // sort takes nlogn
 for(int i=0;i<v.size()-1;i++)
 {
  res=min(res,abs(v[i+1]-v[i]));
 }//this loop takes theta(n)
 //overall TC:O(nlogn)
 return res;
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
cout<<mindiff(v);
return 0;
}