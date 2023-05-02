#include<bits/stdc++.h>
using namespace std;
void unionn(vector<int>v1,vector<int>v2,int n1,int n2)
{
 int i=0,j=0;
 while(i<n1 && j<n2)
 {
  if(v1[i]==v1[i-1] && i>0) {i++;continue;}
  if(v2[j]==v2[j-1] && j>0) {j++;continue;}
  if(v1[i]<v2[j]) 
  {
   cout<<v1[i]<<" ";
   i++;
  }
  else if(v1[i]>v2[j])
  {
   cout<<v2[j]<<" ";
   j++;
  }
  else 
  {
   cout<<v1[i]<<" ";
   i++;
   j++;
  }

 }
 while(i<n1)
 {
  if(i>0 && v1[i]!=v1[i-1])
  {cout<<v1[i]<<" ";
  i++;}
 }
 while(j<n2)
 {
  if(j>0 && v2[j]!=v2[j-1])
  {cout<<v2[j]<<" ";
  j++;}
 }
}
int main()
{
int n1,n2;
cout<<"enter size of first array";
cin>>n1;
cout<<"enter size of second array";
cin>>n2;
vector<int> v1(n1);
vector<int> v2(n2);
for (int i = 0; i < n1; i++)
{
cin >> v1[i];
}
for (int i = 0; i < n2; i++)
{
cin >> v2[i];
}
unionn(v1,v2,n1,n2);
return 0;
}