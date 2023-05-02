#include<bits/stdc++.h>
using namespace std;
int repeatingele(vector<int>v)
{
 int n=v.size();
 vector<bool>visited(n-1,false);//size is less because vo repeating ele km se km ek baar to repeat hoga
 for(int i=0;i<n;i++)
 {
  if(visited[v[i]]) return v[i];
  else visited[v[i]]=true;
 }
}//here TC os O(n) but AS is O(n-1) and we require AS O(1) so we need an optimal approach


int main()
{
int n;
cin>>n;
vector<int> v(n);
for (int i = 0; i < n; i++)
{
cin >> v[i];
}
cout<<repeatingele(v);
return 0;
}