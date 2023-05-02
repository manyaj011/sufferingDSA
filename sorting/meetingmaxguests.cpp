#include<bits/stdc++.h>
using namespace std;
int maxguests(vector<int>arrival,vector<int>departure)
{
 int res=1;
 int curr=1;
 int i=1;
 int j=0;
 int n=arrival.size();
 sort(arrival.begin(),arrival.end());
 sort(departure.begin(),departure.end());
 while(i<n && j<n)
 {
  if(arrival[i]<=departure[j])
  {
   curr++;
   i++;
  }
  else{
   curr--;
   j++;
  }
  res=max(res,curr);
 }
 return res;
}
int main()
{
int n;
cin>>n;
vector<int> arrival(n);
for (int i = 0; i < n; i++)
{
cin >> arrival[i];
}
vector<int>departure(n);
for(int i=0;i<n;i++)
{
 cin>> departure[i];
}
cout<<maxguests(arrival,departure);
return 0;
}