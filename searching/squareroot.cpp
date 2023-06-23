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
double moreprecise(int n , int precision , int tempsol){
 double factor = 1;
 double ans = tempsol;
 for (int i = 0; i < precision; i++)
 {
  /* code */
  factor = factor/10;
  for (double j = ans; j*j < n; j+=factor)
  {
   /* code */
   ans = j;
  }
  
 }
 return ans;
}
int main()
{
int val;
cin>>val;
int tempsol = sqrroot(val);
cout<<moreprecise(val , 3 , tempsol);
return 0;
}