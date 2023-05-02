#include<bits/stdc++.h>
using namespace std;
int twopointerapproach(vector<int>v, int x)
{
 int n=v.size();
 int i=0;
 int j=n-1;
 while(i<j)
 {
  if(v[i]+v[j]==x) return 1;
  else if(v[i]+v[j]>x) j--;//agr v[i]+v[j] bdaa h x se to mtlb jo v[j] hoga vo baki sbhi bche hue i e saath bdi value hi dega to v[j] ko ignore kr skte h baki sbhi i ke liye
  else i++;
 }
 return -1;
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
cout<<"enter sum of which pair is to be find:";
int x;
cin>>x;
int z=twopointerapproach(v,x);
if(z==1) cout<<"yes sum can be found";
else
cout<<"no such elements are present whose sum is "<<x;
return 0;

}
//TC=O(n)
//AS:O(1)