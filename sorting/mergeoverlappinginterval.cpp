#include<bits/stdc++.h>
using namespace std;
class interval
{
public:
 int start;
 int end;
};
int mycmp(vector<interval>a,vector<interval>b)
{
 return a.start<b.start;
}
void merge_overlapping_interval(vector<interval>v)
{
 sort(v.begin(),v.end(),mycmp);
 int res=0;//ye res vector ke index ko represent krta h jisme hum overlap krane ke baad vector staore kr rhe h 
 //also hum koi nya vector array nhi bna rhe h usi vector m hi changes kr rhe h 
 for (int i = 1; i < v.size(); i++)
 {
  if(v[i].start<=v[res].end)
  {
   v[res].start=min(v[res].start,v[i].start);
   v[res].end=max(v[res].end,v[i].end);
  }
  else{
   res++;
   v[res]=v[i];
  }

 }
 for(int i=0;i<=res;i++)
 {
  cout<<v[i].start<<v[i].end<<" ";
 }
 
}

// TC :O(nlogn);
// SC: O(1)

int main()
{
int n;
cin>>n;
vector<interval>v(n);
vector<interval>:: iterator it;
for (it =v.begin() ; it < v.end(); it++)
{
cin >> v[it].start()>>it.end();
}

return 0;
}