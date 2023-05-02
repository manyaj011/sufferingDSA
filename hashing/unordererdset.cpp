#include<bits/stdc++.h>
using namespace std;
int main()
{
unordered_set<int>s;
s.insert(10);
s.insert(5);
s.insert(15);
s.insert(20);
for(int x : s)
 cout<<x<<" ";
cout<<endl;
//begin returns iterator to thr first element and end returns iterator beyond the last element
for(auto it=s.begin();it!=s.end();it++)
{
 cout<<*it<<" ";
}
//both for loops cout the permuatation of 10 5 15 20
cout<<endl;
cout<<s.size()<<" ";
// s.clear();
// cout<<s.size();
cout<<endl;
if(s.find(15)==s.end())
 cout<<"not found";
else
 cout<<"found"<<" "<<*(s.find(15))<<endl;
 //count fun can be used as a subsitiute of find fun 
 //find fun returns an iteraot if element is present
 //count fun returns 1 if ele present else 0
 //no duplicacy in unordered set  
 if(s.count(15)) cout<<"yes present"<<endl;
 else cout<<"no not present"<<endl;
 cout<<"the size is-"<<s.size()<<endl;
 s.erase(15);
 cout<<"the new size is-"<<s.size()<<endl;
 //another way of erasing any ele
 auto it=s.find(5);
 s.erase(it);
 cout<<s.size()<<endl;
 auto it1=s.find(20);
 auto it2=s.find(10);
 s.erase(it1,it2);
 cout<<s.size()<<endl;
 for (auto it = s.begin(); it != s.end(); it++)
 {
 cout << *it << " ";
 }
 return 0;
}