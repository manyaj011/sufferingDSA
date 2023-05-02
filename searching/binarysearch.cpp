#include<bits/stdc++.h>
using namespace std;
int binarysearch(vector<int>v,int target)
{
 int n=v.size();
 int low=0;
 int high=n-1;
 while(low<=high)
 {
  int mid = (high + low) / 2;
  if(v[mid]==target)
   return mid;
  
  else if(target<v[mid])
   high=mid-1;
 
  else if(target>v[mid])
   low=mid+1;

 }
// cout<<mid;
 return -1;
}
int main()
{
int n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++)
{
 cin>>v[i];
} 
cout<<"enter the target element:";
int target;
cin>>target;
cout<<binarysearch(v,target);
}