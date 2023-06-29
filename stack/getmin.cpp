#include <bits/stdc++.h>
using namespace std;
class mystack
{
public:
 stack<int> ms;
 stack<int> as;

 void push(int x)
 {
  if (ms.empty() == true) // this is the base case where the first value is always push into because we need sthn gto compare to
  {
   ms.push(x);
   as.push(x);
   return;
  }
  ms.push(x);
  if (as.top() >= ms.top())
  {
   as.push(x);
  }
 }
 void pop()
 {
  if (ms.top() == as.top())
  {
   as.pop();
  }
  ms.pop();
 }
 int top()
 {
  return ms.top();
 }
 int getmin()
 {
  return as.top();
 }
};
int main()
{
 mystack s;
 s.push(4);
 s.push(5);
 s.push(8);
 s.push(1);
 s.pop();

 cout << " Minimum Element from Stack: " << s.getmin();

 return 0;
}