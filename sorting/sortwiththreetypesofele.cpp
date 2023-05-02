#include<bits/stdc++.h>
using namespace std;
void sort_with_Three_type_of_elements(vector<int>v)
{
 int low=0;
 int mid=0;
 int high=v.size()-1;
 while(mid<=high)
 {
  if(v[mid]==0) 
  {
   swap(v[mid],v[low]);
    low++;
    mid++;
  }
   else if(v[mid]==1)
   {
    mid++;
   }
   else
   {
    swap(v[mid],v[high]);
    high--;
   }
  }
  for (int i = 0; i < v.size(); i++)
  {
   cout<<v[i]<<" ";
  }
  
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
sort_with_Three_type_of_elements(v);
return 0;
}