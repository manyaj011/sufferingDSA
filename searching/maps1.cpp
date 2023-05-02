/*
given n strings, print unique strings in lexiographical order with their frequency 
n<=10^5
|s|<=100
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
 map<string,int> m;
 int n;
 cin>>n;
 for(int i=0;i<n;i++)
 {
  string s;
  cin>>s;
  m[s]++;
 }
 for(auto &i:m)
 {
  cout<<i.first<<" "<<i.second<<endl;
 }

 int q;
 cin>>q;
 while(q--)
 {
  string s;
  cin>>s;
  cout<<m[s]<<endl;
 }

}