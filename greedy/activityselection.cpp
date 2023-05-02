#include <bits/stdc++.h>
using namespace std;
int mycmp(pair<int,int>a, pair<int,int>b)
{
 return(a.second<b.second);
}
int maxActivity(pair<int, int> arr[], int n)
{
 sort(arr,arr+n,mycmp);
 int prev = 0;
 int res = 1;
 for (int curr = 1; curr < n; curr++)
 {
  if(arr[prev].second<=arr[curr].first)
  {
   res++;
   prev=curr;
  }
 }
 return res;
}
int main()
{
 int n;
 cin >> n;
 pair<int,int>arr[n];
 for(int i=0;i<n;i++)
 {
  cin>>arr[i].first>>arr[i].second;
  cout<<endl;
 }
 cout<<maxActivity(arr,n);
 return 0;
}