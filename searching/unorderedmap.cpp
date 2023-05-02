#include<bits/stdc++.h>
using namespace std;
void print(unordered_map<int,string>&m)
{
 cout<<m.size()<<endl;
 for(auto &i : m)
 {
  cout<<i.first<<" "<<i.second<<endl;//TC:O(1)
 }
}
int main()
{
 unordered_map<int,string> m;
 m[1]="abc";//TC:O(1)
 m[5]="cdc";
 m[3]="acd";
 m[6]="a";
 m[5]="cde";
 auto it=m.find(3);//TC:O(1)
 if (it != m.end())
 {
  cout << (*it).first << " " << (*it).second << endl;
 }
 m.erase(3);//O(1)
 
 print(m);
 
}