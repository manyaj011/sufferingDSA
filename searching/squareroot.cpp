#include<bits/stdc++.h>
using namespace std;
int sqrroot(int value)
{
 int low=1; int high=value;int ans=-1;
 while(low<=high)
 {
  int mid=(low+high)/2;
  int msq=mid*mid;
  if(msq==value)
   return mid;
  else if(msq>value)
   high=mid-1;
  else
  {
   low = mid + 1;
   ans = mid;
  }
 }
 return ans;
}
int main()
{
int val;
cin>>val;
cout<<sqrroot(val);
return 0;
}