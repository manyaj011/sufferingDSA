#include<bits/stdc++.h>
using namespace std;
//this is the iterative method
queue<int> revere(queue<int>q){
 stack<int>s;
 while(q.empty() == false){
  s.push(q.front());
  q.pop();
 }
 while(s.empty() == false){
  q.push(s.top());
  s.pop();
 }
 return q;
} 

//this is the recursive method
void rev(queue<int>&q){
 if(q.empty() == true) return;
 int x = q.front();
 q.pop();
 rev(q);
 q.push(x);
 }
int main()
{
queue<int>q;
q.push(10);
q.push(20);
q.push(30);
q.push(40);
// for(int x : q)
// {queues do not support direct iteration in C++ using range-based for loops. 
 // cout<<x<<" ";
// }
queue<int>res=revere(q);
while(res.empty() == false){
 cout<<res.front()<<endl;
 res.pop();
}
cout<<endl;
rev(q);
while (q.empty() == false)
{
 cout << q.front() << endl;
 q.pop();
}
return 0;
}