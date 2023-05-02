#include<bits/stdc++.h>
using namespace std;
void print(map<int,string>&m)
{
 cout<<m.size()<<endl;
 for (auto &i : m) //& taki maps ki copy na create ho 
 {
  cout << i.first << " " << i.second << endl;
 }
 //excess krne ki TC yani jese i.first likha h uski TC logn h
}
int main()
{
 map<int,string> m;
 m[1] = "abc"; //O(logn) basically kisi bhi value kko insert krne ka TC logn h
 m[5] = "cdc";
 m[3] = "acd";
 m.insert({4,"afg"});
 //output m sorted order m display hi hoga 
 // map<int,string> :: iterator it;
 // for(it=m.begin();it!=m.end();++it)
 // {
 //  cout<<(*it).first<<" "<<(*it).second<<endl;
 // }
 auto it=m.find(3); //O(logn) 
 if(it!=m.end())
  m.erase(3); //erase krne se to map m se 3 ki value chli gyi na phr print kese hora h ??
 if(it==m.end())
 {
  cout<<"NO VALUE";//agr value ho hi na to map m.end() ki value return krta h 
 }
 else
 {
  cout<<(*it).first<<" "<<(*it).second<<endl;
 }
 print(m);
}