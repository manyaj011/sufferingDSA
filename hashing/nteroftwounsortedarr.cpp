#include<bits/stdc++.h>
using namespace std;
void intersection(int *a,int *b,int n1,int n2)
{
 for (int i = 0; i < n1; i++)
 {
  /* code */
  bool flag=false;
  for (int j = 0; j < n2; j++)
  {
   /* code */
   if(a[i]==b[j])
   {
    flag=true;
    break;
   }
  }
  if(flag==true)
  {
   cout<<a[i]<<" ";
  }  
 }
 //tc O(n1*n2)
}
void interusinghashmap(int *a,int *b,int n1,int n2)
{
  unordered_set<int>s(b,b+n2);//theta(n2)
  //hmko a aaray ke order m answer chaiye isliye hmne b ko set m daala h tbhi hm a ke ele ko check krate jaenge aur print krate jaenge
  for (int i = 0; i < n1; i++)//theta(n1)
  {
   /* code */
   if(s.find(a[i])!=s.end()) //constant time
    cout<<a[i]<<" ";
  }
  //overall TC theta(n1+n2)
  //as theta(n2)
}
int main()
{
 int a[]={10,15,20,25,30,50};
 int b[]={30,5,15,80};
 // intersection(a,b,6,4);
 interusinghashmap(a,b,6,4);
}