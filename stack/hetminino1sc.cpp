#include <bits/stdc++.h>
using namespace std;
class mystack
{
public:
 stack<int>ms;
 int min = -1;
 void push(int x)
 {
  if (ms.empty() == true)
  {
   ms.push(x);
   min = x;
   return;
  }
  if (x > min)
  {
   ms.push(x);
  }
  else
  {
   ms.push(2 * x - min);
   min = x;
  }
 }
 void pop(){
  if(ms.top() < 0){
   min =(2 * min) - ms.top();
   ms.pop();
  }
  else{
   ms.pop();
  }
 }
 int getmin(){
  return min;
 }
 int top(){
  if(ms.top() < 0){
   return min;
  }
  else return ms.top();
  }
};
using namespace std;
int main()
{
 mystack s;
 s.push(5);
 s.push(-6);
 s.push(7);
 s.push(1);
 s.pop();
 s.push(0);
 s.push(-8);
 s.pop();
 cout<<"the minimum elemnt is:"<<s.getmin();
 return 0;
}