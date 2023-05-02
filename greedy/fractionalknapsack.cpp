#include<bits/stdc++.h>
using namespace std;
bool mycmp(pair<int,int>a,pair<int,int>b)
{
 double r1=(double)a.first/a.second;
 double r2=(double)b.first/b.second;
 return r1>r2;
}
double fknaps(int w,pair<int,int>arr[],int n)
{
 sort(arr,arr+n,mycmp);
 double res=0;
 for(int i=0;i<n;i++)
 {
  if(arr[i].second<=w)
  {
   res+=arr[i].first;
   w-=arr[i].second;
  }
  else 
  {
   res+=arr[i].first*((double)w/arr[i].second);
   break;
  }
 }
 return res;
}
int main()
{
int n;
cin>>n;
int w;
cin>>w;
pair<int,int>arr[n]={{120,30},{100,20},{60,10}};
cout<<fknaps(w,arr,n);
return 0;
}