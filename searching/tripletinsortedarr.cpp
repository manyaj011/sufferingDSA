#include<bits/stdc++.h>
using namespace std;
bool triplet(vector<int>v , int x)
{
 int n=v.size();
 int i=0;
 int j=n-1;
 while(i<j)
 { 
  int s=v[i]+v[j];
  if(s==x) j--;
  else if(s>x) j--;
  else
  {
   for (int z = i + 1; z < j; z++)
   {
    if (s + v[z] == x)
     return true;
   }
   i++;
  } 
 }
 return false;
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
int x;
cout<<"enter the sum number:";
cin>>x;
cout<<triplet(v,x);
return 0;
}