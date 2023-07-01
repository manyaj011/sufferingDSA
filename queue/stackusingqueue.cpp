#include<bits/stdc++.h>
using namespace std;
class Stack{
 public:
 queue<int>q1,q2; //implementing stack using queue
 int top(){ 
  return q1.front();
  }
 int pop(){
  int x = q1.front();
  q1.pop();
  return x;
 }
 int size(){
  return q1.size();
 }
 //here the push function is costly
 void push(int x){
  while(q1.empty() == false){
   int y = q1.front();
   q2.push(y);
   q1.pop();
  }
  q1.push(x);
  while(q2.empty() == false){
   int y = q2.front();
   q1.push(y);
   q2.pop();
  }
 }
};
int main()
{
Stack s;
s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.push(50);
cout<<s.pop()<<endl;
cout<<s.top()<<endl;
cout<<s.size()<<endl;
return 0;
}